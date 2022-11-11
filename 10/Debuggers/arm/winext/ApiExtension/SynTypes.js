﻿"use strict";

//**************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
// 
// SynTypes.js:
//
// Script which aids in code analysis & reverse engineering via the definition
// of synthetic types.
//
// This contains a *VERY BASIC* C header parser that is able to take simple *C*
// struct definitions and map them to synthetic types that are created by
// this script.  In other words, we will create a duck typed JavaScript object
// with the fields of the C structures and unions mapped to the memory layout
// that we read from the header.
//

delete Object.prototype.toString;
delete Array.prototype.toString;

function __getAPI()
{
    return host.namespace.Debugger.Utility;
}

//*************************************************
// Private:
//

function __getModuleComparisonName(mod)
{
    var name = mod.Name;
    var compName = name.substring(name.lastIndexOf("\\") + 1);
    return compName;

}

//*************************************************
// Type System Utilities:
//

// __UnknownPointerTypeClass:
//
// If we cannot find a synthetic type for something (undefined) that is a pointer, return an empty
// type that represents the pointer so that the value can be displayed.
//
class __UnknownPointerTypeClass
{
    constructor(ptrVal, ptrLevel)
    {
        this.__ptrVal = ptrVal;
        this.__ptrLevel = ptrLevel;
    }

    toString()
    {
        var str = "";
        for (var i = 0; i < this.__ptrLevel; ++i)
        {
            str += "*";
        }
        str += " 0x";
        str += this.__ptrVal.toString(16);
        return str;
    }
}

//
// Unfortunately, numerous publicly documented structures do not have type information in the public 
// symbols for their module despite being publicly documented on MSDN.  Include a 'type creator' utility.  
// At some point in the future when JsProvider supports modules, this should be extracted into such.
//

var __diag = false;
var __syntheticTypes = {};

var __forceUsePublicSymbols = false;
var __usePrivateSymbols = !__forceUsePublicSymbols;
var __checkedPrivateSymbols = false;

// __getSyntheticTypeAlign:
//
// Gets the alignment of a synthetic type.
//
function __getSyntheticTypeAlign(typeName, contextInheritorModule)
{
    var typeInfo = __syntheticTypes[typeName];
    if (typeInfo === undefined)
    {
        var enumDesc = __enumTypes[typeName];
        if (enumDesc === undefined)
        {
            throw new Error("Could not find type " + typeName);
        }

        var nativeType = host.getModuleType(contextInheritorModule, enumDesc.definition.BaseType);
        return __getNativeTypeAlign(nativeType);
    }

    var align = typeInfo.align;
    if (align === undefined)
    {
        var pointerSize = host.getModuleType(contextInheritorModule, "void *").size;
        align = 1;

        for (var field of typeInfo.descriptor)
        {
            if (align >= pointerSize)
            {
                break;
            }

            var fieldAlign = __getSyntheticFieldAlign(field, contextInheritorModule);
            if (fieldAlign > align)
            {
                align = fieldAlign;
            }
        }

        if (align > pointerSize)
        {
            align = pointerSize;
        }

        typeInfo.align = align;
    }
    return align;
}

// __getSyntheticTypeSize:
//
// Gets the size of a synthetic type.
//
function __getSyntheticTypeSize(typeName, contextInheritorModule)
{
    var typeInfo = __syntheticTypes[typeName];
    if (typeInfo === undefined)
    {
        var enumDesc = __enumTypes[typeName];
        if (enumDesc === undefined)
        {
            throw new Error("Could not find type " + typeName);
        }

        return __getTypeSize(enumDesc.containingTable, enumDesc.definition.BaseType);
    }
    var size = typeInfo.size;
    if (size === undefined)
    {
        size = 0;
        var curBit = 0;
        var addBit = true;
        for (var field of typeInfo.descriptor)
        {
            var fieldSize = __getSyntheticFieldSize(field, contextInheritorModule);
            var isBitField = !(field.bitLength === undefined);
            if (isBitField)
            {
                var originalFieldSize = fieldSize;
                if (!addBit)
                {
                    //
                    // Do not count subsequent portions of the bit field in the overall type size.
                    //
                    fieldSize = 0;
                }
                curBit += field.bitLength;
                if (curBit >= originalFieldSize * 8)
                {
                    curBit = 0;
                    addBit = true;
                }
                else
                {
                    addBit = false;
                }
            }
            else
            {
                curBit = 0;
                addBit = true;
            }

            if (typeInfo.isUnion)
            {
                if (fieldSize > size)
                {
                    size = fieldSize;
                }
            }
            else
            {
                size += fieldSize;
            }
        }

        var typeAlign = __getSyntheticTypeAlign(typeName, contextInheritorModule);
        var alignMask = (typeAlign - 1);
        size += alignMask;
        size &= ~alignMask;
        typeInfo.size = size;
    }
    return size;
}

// __getTypeSize:
//
// Returns the size of a type.
//
function __getTypeSize(typeTable, typeName)
{
    var nativeType = host.getModuleType(typeTable.__boundModule, typeName);
    if (nativeType != null && nativeType !== undefined)
    {
        return nativeType.size;
    }
    else
    {
        return __getSyntheticTypeSize(typeName, typeTable.Module);
    }
}

// __getSyntheticFieldSize:
//
// Returns the size of a field (whether synthetic or native) of a synthetic type.
//
function __getSyntheticFieldSize(field, contextInheritorModule)
{
    if (field.fieldType === undefined)
    {
        if (field.syntheticPointerLevel === undefined || field.syntheticPointerLevel == 0)
        {
            return __getSyntheticTypeSize(field.fieldSyntheticType, contextInheritorModule);
        }
        else
        {
            return host.evaluateExpression("sizeof(void*)", contextInheritorModule);
        } 
    }
    else
    {
        return host.evaluateExpression("sizeof(" + field.fieldType + ")", contextInheritorModule);
    }
}

// __getNativeTypeAlign:
//
// Returns the alignment requirements of a native type
//
function __getNativeTypeAlign(nativeType)
{
    //
    // There is no __alignof() or the like (even at host.getModuleType's level).  Assume the
    // alignment of most things is its natural size.
    //
    if (nativeType.typeKind == "pointer")
    {
        var pointerSize = host.getModuleType(nativeType.containingModule, "void *").size;
        return pointerSize;
    }
    else if (nativeType.typeKind == "array")
    {
        return __getNativeTypeAlign(nativeType.baseType);
    }
    else if (nativeType.typeKind == "udt")
    {
        var align = 1;
        var nativeFields = nativeType.fields;
        var nativeFieldNames = Object.getOwnPropertyNames(nativeFields);
        for (var fieldName of nativeFieldNames)
        {
            var field = nativeFields[fieldName];
            if (align >= pointerSize)
            {
                return align;
            }

            var fldAlign = __getNativeTypeAlign(field.type);
            if (fldAlign > align)
            {
                align = fldAlign;
            }
        }

        return align;
    }
    else
    {
        var typeSize = nativeType.size;
        var pointerSize = host.getModuleType(nativeType.containingModule, "void *").size;
        if (typeSize > pointerSize)
        {
            return pointerSize;
        }
        else
        {
            return typeSize;
        }
    }
}

// __getSyntheticFieldAlign:
//
// Returns the alignment requirements of a synthetic field
//
function __getSyntheticFieldAlign(field, contextInheritorModule)
{
    if (field.fieldType == undefined)
    {
        //
        // The natural alignment of a pointer is the size of a pointer on the architecture.  If the type is
        // a synthetic pointer, we do not need to compute any sort of alignment on the underlying type.
        //
        var pointerLevel = field.syntheticPointerLevel;
        if (pointerLevel === undefined || pointerLevel == 0)
        {
            return __getSyntheticTypeAlign(field.fieldSyntheticType, contextInheritorModule);
        }
        else
        {
            var pointerSize = host.getModuleType(contextInheritorModule, "void *").size;
            return pointerSize;
        }
    }
    else
    {
        var nativeType = host.getModuleType(contextInheritorModule, field.fieldType);
        if (nativeType != null && nativeType !== undefined)
        {
            return __getNativeTypeAlign(nativeType, contextInheritorModule);
        }
        else
        {
            //
            // We have nothing by which we can determine this.
            //
            return 1;
        }
    }
}

// __EnumSynthetic:
//
// A class which represents a synthetic "enum".  It has a field named value which contains the value
// of the enumerant.  Its string conversion is the name.
//
class __EnumSynthetic
{
    constructor(enumDef, enumVal)
    {
        this.__enumDef = enumDef;
        this.__enumVal = enumVal;
    }

    get value()
    {
        return this.__enumVal;
    }

    toString()
    {
        var enumerant = this.__enumDef.findEnumerant(this.value);
        if (enumerant)
        {
            return enumerant.Name + " (" + this.value.toString() + ")";
        }
        else
        {
            return this.value.toString();
        }
    }
}

// __createEnumValue:
//
// Creates a value for a defined enum at a given address.
//
function __createEnumValue(enumDef, addr, contextInheritorModule, enumsAsObjects)
{
    var moduleName = __getModuleComparisonName(contextInheritorModule);
    var typeObject = host.getModuleType(moduleName, enumDef.BaseType, contextInheritorModule);
    var baseValue = host.createTypedObject(addr, typeObject);

    if (enumsAsObjects)
    {
        return new __EnumSynthetic(enumDef, baseValue);
    }
    else
    {
        return baseValue;
    }
}

// __getFieldValue:
//
// Returns the value of a field (whether synthetic or native) of a synthetic type.
//
function __getSyntheticFieldValue(field, addr, contextInheritorModule)
{
    if (field.fieldType === undefined)
    {
        var arraySize = field.syntheticArraySize;
        var pointerLevel = field.syntheticPointerLevel;

        var typeClass;
        var ptrTypeClass;

        //
        // For pointers, we can deal with an unknown base type.  This will just be a string convertible
        // blank object -- the string conversion for which will just be the pointer value.
        //
        var synTypeDesc = __syntheticTypes[field.fieldSyntheticType];
        if (synTypeDesc === undefined)
        {
            if (pointerLevel !== undefined && pointerLevel > 0)
            {
                ptrTypeClass = __UnknownPointerTypeClass;
            }
            else 
            {
                //
                // Is it a defined enum type.  We have a set of options for how we want to present
                // such (either just *AS* the base type or as a "pseudo-enum" (really a struct with a field
                // called value and a string conversion of the enumerant)
                //
                var enumDesc = __enumTypes[field.fieldSyntheticType];
                if (enumDesc !== undefined)
                {
                    var enumsAsObjects = enumDesc.containingTable.ReturnEnumsAsObjects;
                    return __createEnumValue(enumDesc.definition, addr, contextInheritorModule, enumsAsObjects);
                }
            }
        }
        else
        {
            typeClass = synTypeDesc.classObject;
            ptrTypeClass = synTypeDesc.pointerClassObject;
        }

        if (arraySize === undefined && pointerLevel === undefined)
        {
            return new typeClass(addr, contextInheritorModule);
        }
        else if (arraySize !== undefined)
        {
            var typeSize = __getSyntheticTypeSize(field.fieldSyntheticType, contextInheritorModule);
            var result = [];
            for (var i = 0; i < arraySize; ++i)
            {
                var entry = new typeClass(addr, contextInheritorModule);
                result.push(entry);
                addr = addr.add(typeSize);
            }
            return result;
        }
        else if (pointerLevel !== undefined)
        {
            var pointerSize = host.getModuleType(contextInheritorModule, "void *").size;
            var ptrAddr = addr;
            while (pointerLevel > 0)
            {
                var ptrRead = host.memory.readMemoryValues(ptrAddr, 1, pointerSize, false, contextInheritorModule);
                ptrAddr = ptrRead[0];
                --pointerLevel;
            }
            return new ptrTypeClass(ptrAddr, field.syntheticPointerLevel, ptrAddr, contextInheritorModule);
        }
    }
    else
    {
        //
        // fieldType references basic types that should be present in **ANY** symbolic information.
        // Just grab the first module as the "reference module" for this purpose.  We cannot grab
        // "ntdll" generically as we want to avoid a situation in which the debugger opens a module (-z ...)
        // from failing.
        //
        var moduleName = __getModuleComparisonName(contextInheritorModule);
        var typeObject = host.getModuleType(moduleName, field.fieldType, contextInheritorModule);
        var result = host.createTypedObject(addr, typeObject);

        //
        // If this is a synthetic bit field, do the appropriate mask and shift.
        //
        if (field.bitLength)
        {
            var size = host.evaluateExpression("sizeof(" + field.fieldType + ")");
            var one = 1;
            var allBits = 0xFFFFFFFF;
            if (size > 4)
            {
                one = host.Int64(1);
                allBits = host.Int64(0xFFFFFFFF, 0xFFFFFFFF);
            }

            var topBit = field.startingBit + field.bitLength;
            var topMask = one.bitwiseShiftLeft(topBit).subtract(1);

            result = result.bitwiseAnd(topMask);
            if (field.startingBit > 0)
            {
                var bottomMask = one.bitwiseShiftLeft(field.startingBit).subtract(1).bitwiseXor(allBits);
                result = result.bitwiseAnd(bottomMask);
                result = result.bitwiseShiftRight(field.startingBit);
            }
        }

        return result;
    }
}

// __preprocessTypeDescriptor:
//
// Preprocess the type descriptor and make certain things easier.
//
function __preprocessTypeDescriptor(typeDescriptor)
{
    for (var field of typeDescriptor)
    {
        var synType = field.fieldSyntheticType;
        if (!(synType === undefined))
        {
            //
            // If the synthetic type is an "array", we need to get the base type and actually tag it as an array
            //
            synType = synType.trim();
            if (synType.endsWith("]"))
            {
                //
                // Extract the array portion.
                //
                var extractor = /(.*)\[(\d+)\]$/;
                var results = extractor.exec(synType);
                field.fieldSyntheticType = results[1].trim();
                field.syntheticArraySize = parseInt(results[2]);
            }
            else if (synType.endsWith("*"))
            {
                //
                // Extract the pointer portion
                //
                var baseType = synType;
                var pointerLevel = 0;
                while (baseType.endsWith("*"))
                {
                    ++pointerLevel;
                    baseType = baseType.slice(0, -1).trim();
                }
                field.fieldSyntheticType = baseType;
                field.syntheticPointerLevel = pointerLevel;
            }
        }
    }
}

function __addEmbeddedAccessor(outerObject, fieldValue, name)
{
    Object.defineProperty(outerObject,
                          name,
                          {
                              configurable: false,
                              enumerable: true,
                              get: function()
                              {
                                  return fieldValue[name];
                              }
                          });
}

// __embedType:
//
// Takes a field (for what might be an unnamed struct/union) and embeds it in the outer structure.
//
function __embedType(outerObject, fieldValue, contextInheritorModule)
{
    var names = Object.getOwnPropertyNames(fieldValue);
    for (var name of names)
    {
        //
        // Do *NOT* overwrite the projected things we place on the objects.
        //
        if (name != "targetLocation" && name != "targetSize")
        {
            __addEmbeddedAccessor(outerObject, fieldValue, name);
            // outerObject[name] = fieldValue[name];
        }
    }
}

// __addAccessor():
//
// Creates a property which fetches the value of a synthetic field.  Any exceptions from the fetch
// will be bounded at the key level and returned accurately.
//
function __addAccessor(obj, field, addr64, contextInheritorModule)
{
    Object.defineProperty(obj, 
                          field.fieldName, 
                          {
                              configurable: false,
                              enumerable: true,
                              get: function()
                              {
                                  return __getSyntheticFieldValue(field, addr64, contextInheritorModule);
                              }
                          });
}

// __defineSyntheticType:
//
// Defines a "synthetic" type based on a descriptor (list of fields).  For a structure, FOO, this would
// allow syntax like this:
//
//     var myFoo = new __FOO(location);
//
// and then use of any synthetic field much as if it were an actual native object created with createTypedObject.
//
function __defineSyntheticType(typeTable, typeDefinition)
{
    var typeDescriptor = typeDefinition.__typeEntry;
    var typeName = typeDefinition.Name;
    __preprocessTypeDescriptor(typeDescriptor);

    class typeClass
    {
        constructor(addr, contextInheritorModule)
        {
            var curBit = 0;
            var fieldSize = 0;
            var addr64 = host.Int64(addr);
            this.targetLocation = addr64;
            this.targetSize = __getSyntheticTypeSize(typeName, contextInheritorModule);
            for (var field of typeDescriptor)
            {
                var fldSize = __getSyntheticFieldSize(field, contextInheritorModule);
                var fldAlign = __getSyntheticFieldAlign(field, contextInheritorModule);
                //
                // Align the field if it has alignment requirements.
                //
                if (fldAlign > 1)
                {
                    //
                    // Int64 is missing bitwiseNot in many releases of JsProvider.  The field alignment is never
                    // going to be over 32 bits.  Adjust using that.
                    //
                    // When the support for .bitwiseNot is in enough releases, remove this workaround.
                    //
                    var low32AlignMask = 0xFFFFFFFF - (fldAlign - 1);
                    var alignMask = host.Int64(low32AlignMask, 0xFFFFFFFF);
                    addr64 = addr64.add(fldAlign - 1).bitwiseAnd(alignMask);
                }

                var isBitField = !(field.bitLength === undefined);
                if (isBitField)
                {
                    if (fieldSize == 0)
                    {
                        curBit = 0;
                        fieldSize = fldSize;
                    }
                    field.startingBit = curBit;
                }

                var fldName = field.fieldName;
                if (fldName === undefined)
                {
                    try
                    {
                        var fldValue = __getSyntheticFieldValue(field, addr64, contextInheritorModule);
                        __embedType(this, fldValue, contextInheritorModule);
                    }
                    catch(e)
                    {
                    }
                }
                else
                {
                    __addAccessor(this, field, addr64, contextInheritorModule);
                    // this[field.fieldName] = fldValue;
                }

                if (isBitField)
                {
                    curBit += field.bitLength;
                    if (curBit >= fieldSize * 8)
                    {
                        curBit = 0;
                        fieldSize = 0;
                        addr64 = addr64.add(fldSize);
                    }
                }
                else
                {
                    addr64 = addr64.add(fldSize);
                }
            }
        }
    };

    class pointerTypeClass extends typeClass
    {
        constructor(ptrVal, ptrLevel, addr, contextInheritorModule)
        {
            super(addr, contextInheritorModule);
            this.__ptrVal = ptrVal;
            this.__ptrLevel = ptrLevel;
        }

        toString()
        {
            var str = "";
            for (var i = 0; i < this.__ptrLevel; ++i)
            {
                str += "*";
            }
            str += " 0x";
            str += this.__ptrVal.toString(16);
            return str;
        }
    }

    var headerName = typeTable.Header;
    if (headerName === undefined)
    {
        headerName = "ApiDefined";
    }
    else
    {
        var dotIdx = headerName.indexOf(".");
        if (dotIdx != -1)
        {
            headerName = headerName.substring(0, dotIdx);
        }
    }

    var modelName = "DataModel.SyntheticTypes." + headerName + "." + typeName;

    __syntheticTypes[typeName] =
    {
        classObject: typeClass,
        pointerClassObject: pointerTypeClass,
        descriptor: typeDescriptor,
        isUnion: false,
        containingTable: typeTable,
        modelName: modelName
    }

    typeDefinition.__make = function(addrObj)
    {
        return new typeClass(addrObj, typeTable.Module);
    };

    typeTable.__addType(typeDefinition);

    if (typeTable.RegisterSyntheticTypeModels)
    {
        host.registerNamedModel(typeClass, modelName);
    }
}

// __defineSyntheticUnion:
//
// Defines a "synthetic" union based on a descriptor (list of all fields in the union).  For a union, FOO, this would
// allow syntax like this:
//
//     var myUnionFoo = new __FOO(location);
//
// and then use of any synthetic field much as if it were an actual native object created with createTypedObject.
//
function __defineSyntheticUnion(typeTable, typeDefinition)
{
    var typeDescriptor = typeDefinition.__typeEntry;
    var typeName = typeDefinition.Name;
    __preprocessTypeDescriptor(typeDescriptor);

    class typeClass
    {
        constructor(addr, contextInheritorModule)
        {
            var largestSize = 0;
            var curBit = 0;
            var fieldSize = 0;
            var addr64 = host.Int64(addr);
            this.targetLocation = addr64;
            this.targetSize = __getSyntheticTypeSize(typeName, contextInheritorModule);
            for (var field of typeDescriptor)
            {
                var fldSize = __getSyntheticFieldSize(field, contextInheritorModule);
                var isBitField = !(field.bitLength === undefined);
                if (isBitField)
                {
                    if (fieldSize == 0)
                    {
                        curBit = 0;
                        fieldSize = fldSize;
                    }
                    field.startingBit = curBit;
                }

                var fldValue = __getSyntheticFieldValue(field, addr64, contextInheritorModule);

                var fldName = field.fieldName;
                if (fldName === undefined)
                {
                    __embedType(this, fldValue, contextInheritorModule);
                }
                else
                {
                    this[field.fieldName] = fldValue;
                }

                if (isBitField)
                {
                    curBit += field.bitLength;
                    if (curBit >= fieldSize * 8)
                    {
                        curBit = 0;
                        fieldSize = 0;
                    }
                }
            }
        }
    };

    __syntheticTypes[typeName] =
    {
        classObject: typeClass,
        descriptor: typeDescriptor,
        isUnion: true,
        containingTable: typeTable
    }

    typeDefinition.__make = function(addrObj)
    {
        return new typeClass(addrObj, typeTable.Module);
    };

    typeTable.__addType(typeDefinition);
}

//*************************************************
// Type Tables:
//

var __typeTables = [];

function __getModuleFor(modQ)
{
    if (typeof(modQ) === "string")
    {
        return host.currentProcess.Modules.getValueAt(modQ);
    }
    else
    {
        return modQ;
    }
}

// __TypeTable:
//
// Represents a set of synthetic type definitions bound to a single module.
//
class __TypeTable
{
    constructor(boundModule, headerPath, attributes)
    {
        this.__boundModule = boundModule;
        this.__headerPath = headerPath;
        this.__module = __getModuleFor(boundModule);
        this.__attributes = attributes;
        this.__types = [];
    }

    toString()
    {
        var desc = this.Module.Name;
        if (this.__headerPath !== undefined)
        {
            desc += "(" + this.Header + ")";
        }
        return desc;
    }

    __isSymbolType(typeName)
    {
        var boundType = host.getModuleType(this.__boundModule, typeName);
        if (boundType == null || boundType === undefined)
        {
            return false;
        }
        return true;
    }

    __addType(typeDefinition)
    {
        this.__types.push(typeDefinition);
    }

    get ReturnEnumsAsObjects()
    {
        if (this.__attributes && this.__attributes.ReturnEnumsAsObjects)
        {
            return this.__attributes.ReturnEnumsAsObjects;
        }
        return false;
    }

    get RegisterSyntheticTypeModels()
    {
        if (this.__attributes && this.__attributes.RegisterSyntheticTypeModels)
        {
            return this.__attributes.RegisterSyntheticTypeModels;
        }
        return false;
    }

    get Module()
    {
        return this.__module;
    }

    get Header()
    {
        if (this.__headerPath === undefined)
        {
            return undefined;
        }

        return this.__headerPath.slice(this.__headerPath.lastIndexOf("\\") + 1);
    }

    get Types()
    {
        return this.__types;
    }
};

// (public) __FieldDescription
//
// A description of a synthetic field
//
class __FieldDescription
{
    constructor(typeTable, fieldEntry)
    {
        this.__typeTable = typeTable;
        this.__fieldEntry = fieldEntry;
    }

    toString()
    {
        var entry = this.__fieldEntry;

        var desc = "";
        if (entry.fieldType !== undefined)
        {
            desc += entry.fieldType;
        }
        else
        {
            desc += entry.fieldSyntheticType;
        }
        if (entry.fieldName !== undefined)
        {
            desc += " " + entry.fieldName;
        }
        else
        {
            desc += " <unnamed>";
        }
        if (entry.bitLength !== undefined)
        {
            desc += ":" + entry.bitLength.toString();
        }
        return desc;
    }

    get Size()
    {
        return __getSyntheticFieldSize(this.__fieldEntry, this.__typeTable.Module);
    }

    get Align()
    {
        return __getSyntheticFieldAlign(this.__fieldEntry, this.__typeTable.Module);
    }
}

// (public) __TypeDescription
//
// A synthetic iterable that we return to give a description of type
//
class __TypeDescription
{
    constructor(typeTable, typeEntry)
    {
        this.__typeTable = typeTable;
        this.__typeEntry = typeEntry;
    }

    *[Symbol.iterator]()
    {
        for (var entry of this.__typeEntry)
        {
            yield new __FieldDescription(this.__typeTable, entry);
        }
    }
}

// (public) __TypeDefinition:
//
// Represents a synthetic type definition.
//
class __TypeDefinition
{
    constructor(name, typeTable, typeEntry)
    {
        this.__name = name;
        this.__typeTable = typeTable;
        this.__typeEntry = typeEntry;
    }

    toString()
    {
        return this.Name;
    }

    get Name()
    {
        return this.__name;
    }

    get Make()
    {
        return this.__make;
    }

    get Description()
    {
        return new __TypeDescription(this.__typeTable, this.__typeEntry);
    }

    get [Symbol.metadataDescriptor]()
    {
        return { Make: { PreferShow: true,
                         Help: "Make(address)- Constructs an instance of this type" } };
    }
};

// (public) __Enumerant:
//
// Represents a synthetic enumerant.
//
class __Enumerant
{
    constructor(name, value)
    {
        this.__name = name;
        this.__value = value;
    }

    toString()
    {
        return this.Name + " = " + this.Value;
    }

    get Name()
    {
        return this.__name;
    }

    get Value()
    {
        return this.__value;
    }
}

// (public) __EnumDefinition:
//
// Represents a synthetic enum definition
//
class __EnumDefinition
{
    constructor(name, baseType, enumerants)
    {
        this.__name = name;
        this.__baseType = baseType;
        this.__enumerants = enumerants;
    }

    toString()
    {
        return this.__name;
    }

    get Name()
    {
        return this.__name;
    }

    get BaseType()
    {
        return this.__baseType;
    }

    get Enumerants()
    {
        return this.__enumerants;
    }

    findEnumerant(val)
    {
        for (var enumerant of this.Enumerants)
        {
            if (enumerant.Value == val)
            {
                return enumerant;
            }
        }

        return null;
    }
};

var uniqueId = 0;

// __generateUniqueName():
//
// Generates a unique name for an unnamed type (within the bounds of this script)
//
function __generateUniqueName(typeTable, prefix)
{
    var name = "__UNNAMED_";
    if (prefix !== undefined)
    {
        name += prefix + "_";
    }
     name += uniqueId.toString();
    ++uniqueId;
    return name;
}

//*************************************************
// Simple C struct header parser.
//

var __tokenTypes = 
{
    //
    // General:
    //
    Unknown: 0,
    Identifier: 1,
    Comment: 2,
    Keyword: 3,
    Plus: 4,
    PlusEqual: 5,
    Minus: 6,
    MinusEqual: 7,
    Star: 8,
    StarEqual: 9,
    Slash: 10,
    SlashEqual: 11,
    Colon: 12,
    Semicolon: 13, 
    LParen: 14,
    RParen: 15,
    LBracket: 16,
    RBracket: 17,
    LBrace: 18,
    RBrace: 19,
    Comma: 20, 
    Int: 21,
    Percent: 22,
    PercentEqual: 23,
    Equal: 24,
    DoubleEqual: 25,
    Ampersand:  26,
    DoubleAmpersand: 27,
    Pipe: 28,
    DoublePipe : 29,
    Bang : 30,
    BangEqual: 31,
    LT : 32,
    DoubleLT : 33,
    LTEqual : 34,
    GT : 35,
    DoubleGT : 36,
    GTEqual : 37,
    Caret : 38,

    //
    // Keywords:
    //
    Struct: 101,
    Typedef: 102,
    Union: 103,
    SizeOf: 104,
    Enum: 105,

    //
    // Recognized types & modifiers:
    //
    Const: 200,
    Volatile: 201,
    Unsigned: 202,
    Char: 203,
    Short: 204,
    Int: 205,
    Long: 206,
    Int64: 207,
    True: 208,
    False: 209,

    //
    // Other
    //
    IntValue: 300
};

// __operators:
//
// Recognized operators for "limited" static expression evaluation
//
var __operators =
{
    Unknown: 0,
    BinaryOpAdd: 1,
    BinaryOpSubtract: 2,
    BinaryOpMultiply: 3,
    BinaryOpDivide: 4,
    BinaryOpModulo: 5,
    BinaryOpLogicalAnd: 6,
    BinaryOpLogicalOr: 7,
    BinaryOpEqualCompare: 8,
    BinaryOpNotEqualCompare : 9,
    BinaryOpLess : 10,
    BinaryOpLessEqual : 11,
    BinaryOpGreater : 12,
    BinaryOpGreaterEqual : 13,
    BinaryOpLeftShift : 14,
    BinaryOpRightShift : 15,
    BinaryOpBitwiseOr : 16,
    BinaryOpBitwiseXor : 17,
    BinaryOpBitwiseAnd : 18,

    UnaryOpNegative: 100,
    UnaryOpLogicalNot: 101
};

// __operatorPrecedenceMappings:
//
// Indicates the precedence of supported operators.
//
var __operatorPrecedenceMappings = {};
__operatorPrecedenceMappings[__operators.BinaryOpLogicalOr] = 3;
__operatorPrecedenceMappings[__operators.BinaryOpLogicalAnd] = 3;
__operatorPrecedenceMappings[__operators.BinaryOpBitwiseOr] = 5;
__operatorPrecedenceMappings[__operators.BinaryOpBitwiseXor] = 6;
__operatorPrecedenceMappings[__operators.BinaryOpBitwiseAnd] = 7;
__operatorPrecedenceMappings[__operators.BinaryOpEqualCompare] = 8;
__operatorPrecedenceMappings[__operators.BinaryOpNotEqualCompare] = 8;
__operatorPrecedenceMappings[__operators.BinaryOpLess] = 9;
__operatorPrecedenceMappings[__operators.BinaryOpLessEqual] = 9;
__operatorPrecedenceMappings[__operators.BinaryOpGreater] = 9;
__operatorPrecedenceMappings[__operators.BinaryOpGreaterEqual] = 9;
__operatorPrecedenceMappings[__operators.BinaryOpLeftShift] = 10;
__operatorPrecedenceMappings[__operators.BinaryOpRightShift] = 10;
__operatorPrecedenceMappings[__operators.BinaryOpAdd] = 11;
__operatorPrecedenceMappings[__operators.BinaryOpSubtract] = 11;
__operatorPrecedenceMappings[__operators.BinaryOpMultiply] = 12;
__operatorPrecedenceMappings[__operators.BinaryOpDivide] = 12;
__operatorPrecedenceMappings[__operators.BinaryOpModulo] = 12;
__operatorPrecedenceMappings[__operators.UnaryOpNegative] = 14;
__operatorPrecedenceMappings[__operators.UnaryOpLogicalNot] = 14;

// __binaryOperatorMappings
// 
// Token mappings for binary operators
//
var __binaryOperatorMappings = {};
__binaryOperatorMappings[__tokenTypes.Plus] = __operators.BinaryOpAdd;
__binaryOperatorMappings[__tokenTypes.Minus] = __operators.BinaryOpSubtract;
__binaryOperatorMappings[__tokenTypes.Star] = __operators.BinaryOpMultiply;
__binaryOperatorMappings[__tokenTypes.Slash] = __operators.BinaryOpDivide;
__binaryOperatorMappings[__tokenTypes.Percent] = __operators.BinaryOpModulo;
__binaryOperatorMappings[__tokenTypes.DoubleEqual] = __operators.BinaryOpEqualCompare;
__binaryOperatorMappings[__tokenTypes.BangEqual] = __operators.BinaryOpNotEqualCompare;
__binaryOperatorMappings[__tokenTypes.LT] = __operators.BinaryOpLess;
__binaryOperatorMappings[__tokenTypes.DoubleLT] = __operators.BinaryOpLeftShift;
__binaryOperatorMappings[__tokenTypes.LTEqual] = __operators.BinaryOpLessEqual;
__binaryOperatorMappings[__tokenTypes.GT] = __operators.BinaryOpGreater;
__binaryOperatorMappings[__tokenTypes.DoubleGT] = __operators.BinaryOpRightShift;
__binaryOperatorMappings[__tokenTypes.GTEqual] = __operators.BinaryOpGreaterEqual;
__binaryOperatorMappings[__tokenTypes.DoubleAmpersand] = __operators.BinaryOpLogicalOr;
__binaryOperatorMappings[__tokenTypes.DoublePipe] = __operators.BinaryOpLogicalAnd;
__binaryOperatorMappings[__tokenTypes.Pipe] = __operators.BinaryOpBitwiseOr;
__binaryOperatorMappings[__tokenTypes.Ampersand] = __operators.BinaryOpBitwiseAnd;
__binaryOperatorMappings[__tokenTypes.Caret] = __operators.BinaryOpBitwiseXor;

// __unaryOperatorMappings
//
// Token mappings for unary operators
//
var __unaryOperatorMappings = {};
__unaryOperatorMappings[__tokenTypes.Minus] = __operators.UnaryOpNegative;
__unaryOperatorMappings[__tokenTypes.Bang] = __operators.UnaryOpLogicalNot;

// __tokenMappings:
//
// Defines mappings between strings and their token IDs.
//
var __tokenMappings = {};
__tokenMappings["struct"] = __tokenTypes.Struct;
__tokenMappings["typedef"] = __tokenTypes.Typedef;
__tokenMappings["union"] = __tokenTypes.Union;
__tokenMappings["sizeof"] = __tokenTypes.SizeOf;
__tokenMappings["const"] = __tokenTypes.Const;
__tokenMappings["volatile"] = __tokenTypes.Volatile;
__tokenMappings["unsigned"] = __tokenTypes.Unsigned;
__tokenMappings["char"] = __tokenTypes.Char;
__tokenMappings["short"] = __tokenTypes.Short;
__tokenMappings["int"] = __tokenTypes.Int;
__tokenMappings["long"] = __tokenTypes.Long;
__tokenMappings["__int64"] = __tokenTypes.Int64;
__tokenMappings["enum"] = __tokenTypes.Enum;
__tokenMappings["true"] = __tokenTypes.True;
__tokenMappings["false"] = __tokenTypes.False;

// __remappedTypes:
//
// Defines some types that we "know" are typedefs due to the Windows environment and remaps them
//
var __remappedTypes = {};
__remappedTypes["UCHAR"] = "unsigned char";
__remappedTypes["PUCHAR"] = "unsigned char *";
__remappedTypes["UINT8"] = "unsigned char";
__remappedTypes["PUINT8"] = "unsigned char *";
__remappedTypes["CHAR"] = "char";
__remappedTypes["PCHAR"] = "char *";
__remappedTypes["USHORT"] = "unsigned short";
__remappedTypes["PUSHORT"] = "unsigned short *";
__remappedTypes["UINT16"] = "unsigned short";
__remappedTypes["PUINT16"] = "unsigned short *";
__remappedTypes["SHORT"] = "short";
__remappedTypes["PSHORT"] = "short *";
__remappedTypes["INT16"] = "short";
__remappedTypes["PINT16"] = "short *";
__remappedTypes["INT"] = "int";
__remappedTypes["PINT"] = "int *";
__remappedTypes["INT32"] = "int";
__remappedTypes["PINT32"] = "int *";
__remappedTypes["UINT"] = "unsigned int";
__remappedTypes["PUINT"] = "unsigned int *";
__remappedTypes["UINT32"] = "unsigned int";
__remappedTypes["PUINT32"] = "unsigned int *";
__remappedTypes["ULONG"] = "unsigned long";
__remappedTypes["PULONG"] = "unsigned long *";
__remappedTypes["LONG"] = "long";
__remappedTypes["PLONG"] = "long *";
__remappedTypes["ULONG64"] = "unsigned __int64";
__remappedTypes["PULONG64"] = "unsigned __int64 *";
__remappedTypes["UINT64"] = "unsigned __int64";
__remappedTypes["PUINT64"] = "unsigned __int64 *";
__remappedTypes["ULONGLONG"] = "unsigned __int64";
__remappedTypes["PULONGLONG"] = "unsigned __int64 *";
__remappedTypes["LONG64"] = "__int64";
__remappedTypes["PLONG64"] = "__int64 *";
__remappedTypes["LONGLONG"] = "__int64";
__remappedTypes["PLONGLONG"] = "__int64 *";
__remappedTypes["PVOID"] = "void *";
__remappedTypes["HANDLE"] = "void *";
__remappedTypes["BOOL"] = "unsigned long";
__remappedTypes["PBOOL"] = "unsigned long *";
__remappedTypes["BYTE"] = "unsigned char";
__remappedTypes["PBYTE"] = "unsigned char *";
__remappedTypes["WORD"] = "unsigned short";
__remappedTypes["PWORD"] = "unsigned short *";
__remappedTypes["DWORD"] = "unsigned long";
__remappedTypes["PDWORD"] = "unsigned long *";
__remappedTypes["DWORD64"] = "unsigned __int64";
__remappedTypes["PDWORD64"] = "unsigned __int64 *";
__remappedTypes["HRESULT"] = "unsigned int";
__remappedTypes["PSTR"] = "char *";
__remappedTypes["PCSTR"] = "char *";
__remappedTypes["PWSTR"] = "wchar_t *";
__remappedTypes["PCWSTR"] = "wchar_t *";

// __typeAliases:
//
// Typedefs.
//
var __typeAliases = {};
var __enumTypes = {};

// __getOperatorForToken():
//
// Returns the operator from a given token (or undefined)
//
function  __getOperatorForToken(tokenType, operandSlot)
{
    if (operandSlot)
    {
        return __unaryOperatorMappings[tokenType];
    }
    else
    {
        return __binaryOperatorMappings[tokenType];
    }
}

// __CToken:
//
// Represents a token in our simple understanding of C syntax
//
class __CToken
{
    constructor(tokenType, tokenString, value)
    {
        this.__tokenType = tokenType;
        this.__tokenString = tokenString;
        this.__value = value;
    }
};

// __CMacroParser:
//
// Simple C macro parser.
//
class __CMacroParser
{
    constructor(tokenStream)
    {
        this.__tokenStream = tokenStream;
        this.__iterator = (this.__tokenStream[Symbol.iterator])();
        this.advance(false);
    }

    throwError(msg)
    {
        throw new Error(msg);
    }

    // advance():
    //
    // Moves the tokenizer forward.
    //
    advance(require)
    {
        this.__curTokenPos = this.__iterator.next();
        this.__curToken = this.__curTokenPos.value;
        if (this.__curTokenPos.done && require)
        {
            this.throwError("Unexpected end of file in processing header");
        }
    }

    // expect():
    //
    // Expects a given token at the current position and moves the tokenizer forward.
    //
    expect(tokenType, requireFwd)
    {
        if (this.__curToken.__tokenType != tokenType)
        {
            this.throwError("Unexpected token");
        }
        var req = true;
        if (requireFwd !== undefined)
        {
            req = requireFwd;
        }
        this.advance(req);
    }

    // skipTo():
    //
    // Skips to the next occurrence of the given token type.
    //
    skipTo(tokenType)
    {
        while(!this.__curTokenPos.done && this.__curToken.__tokenType != tokenType)
        {
            this.advance(true);
        }

        if (this.__curTokenPos.done)
        {
            throwError("Did not find token skip destination");
        }
    }

    // macroConditionEval():
    //
    // Performs a simplistic #if macro evaluation.
    //
    macroConditionEval(macros, endToken)
    {
        var valStack = [];
        var opStack = [];

        var lastPrecedence = 0;
        var operand = true;
        while(true)
        {
            if (this.__curTokenPos.done)
            {
                break;
            }

            var tokenValue = this.__curToken;
            var tokenType = tokenValue.__tokenType;
            var val;

            if (tokenType == endToken)
            {
                break;
            }
            else if (tokenType == __tokenTypes.True)
            {
                valStack.push(true);
                this.advance();
                operand = false;
            }
            else if (tokenType == __tokenTypes.False)
            {
                valStack.push(false);
                this.advance();
                operand = false;
            }
            else if (tokenType == __tokenTypes.IntValue)
            {
                if (!operand)
                {
                    this.throwError("Unexpected token");
                }
                val = tokenValue.__value;
                valStack.push(val);
                this.advance();
                operand = false;
            }
            else if (tokenType == __tokenTypes.LParen)
            {
                if (!operand)
                {
                    this.throwError("Unexpected token");
                }

                this.advance();
                val = this.macroConditionEval(macros, __tokenTypes.RParen);
                this.expect(__tokenTypes.RParen, false);
                valStack.push(val);
                operand = false;
            }
            else if (tokenType == __tokenTypes.Identifier && this.__curToken.__tokenString == "defined")
            {
                if (!operand)
                {
                    this.throwError("Unexpected token");
                }

                this.advance(true);
                this.expect(__tokenTypes.LParen);
                if (this.__curToken.__tokenType != __tokenTypes.Identifier)
                {
                    this.throwError("Expected macro name");
                }

                var macroDefined = !!macros[this.__curToken.__tokenString];
                this.advance(true);
                this.expect(__tokenTypes.RParen, false);
                valStack.push(macroDefined);
                operand = false;
            }
            else if (tokenType == __tokenTypes.Identifier)
            {
                //
                // Treat an unknown identifier in a macro as zero.
                //
                var identifier = this.__curToken.__tokenString;
                this.advance();
                if (!this.__curTokenPos.done && this.__curToken.__tokenType == __tokenTypes.LParen)
                {
                    //
                    // It's a function which we do not deal with.  Right now, throw a true on the evaluation
                    // stack.
                    //
                    // Yes -- this won't handle calls with nested parenthesis and a whole bunch of other things.
                    // It is somewhat minimalistic to get more headers to parse through this.
                    //
                    this.skipTo(__tokenTypes.RParen);
                    this.advance();
                    valStack.push(true);
                    operand = false;
                }
                else
                {
                    valStack.push(0);
                }
                operand = false;
            }
            else
            {
                var operator = __getOperatorForToken(tokenType, operand);
                if (operator)
                {
                    var curPrecedence = __operatorPrecedenceMappings[operator];
                    if (curPrecedence <= lastPrecedence)
                    {
                        val = __evaluateStack(valStack, opStack);
                        valStack = [val];
                        opStack = [];
                    }
                    opStack.push(operator);
                    lastPrecedence = curPrecedence;
                    this.advance();
                    operand = true;
                }
                else
                {
                    //
                    // Let the caller determine whether ending at this token is appropriate.
                    //
                    break;
                }
            }
        }

        val = __evaluateStack(valStack, opStack);
        return val;
    }
}

// __CTokenStream:
//
// Takes a text reader and produces a token stream from the reader.
//
class __CTokenStream
{
    // constructor:
    //
    // Takes a text reader and produces a token stream.
    //
    constructor(origin, startingMacros)
    {
        if (typeof(origin) === "string")
        {
            this.__string = origin;
        }
        else
        {
            this.__reader = origin;
        }
        this.__done = false;
        this.__lineNumber = 1;
        this.__startingMacros = startingMacros;
    }

    throwError(msg)
    {
        throw new Error(msg);
    }

    isalpha(line, n)
    {
        var c = line.charAt(n);
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }

    isnum(line, n)
    {
        var c = line.charAt(n);
        return (c >= '0' && c <= '9');
    }

    ishexdigit(line, n)
    {
        var c = line.charAt(n);
        return ((c >= '0' && c <= '9') ||
                (c >= 'A' && c <= 'F') ||
                (c >= 'a' && c <= 'f'));
    }

    isalnum(line, n)
    {
        return (this.isalpha(line, n) || this.isnum(line, n));
    }

    isidentchar(line, n)
    {
        var c = line.charAt(n);
        return (c == '_' || this.isalnum(line, n));
    }

    isspace(line, n)
    {
        var c = line.charAt(n);
        return (c == ' ' || c == '\t');
    }

    // defineMacro():
    //
    // Does a macro defintition.  The line is positioned after #define
    //
    defineMacro(macros, line)
    {
        var i = 0;
        while (i < line.length && this.isidentchar(line, i)) { ++i; }
        if (i != 0)
        {
            var name = line.slice(0, i);
            line = line.slice(i);
            if (line.charAt(0) == '(')
            {
                // We do not handle function macros.
            }
            else
            {
                var macDef = line.trim();
                var cmnt = macDef.indexOf("//");
                if (cmnt != -1)
                {
                    macDef = macDef.slice(0, cmnt).trim();
                }

                // One macro can define to another.  Substitute as appropriate.
                macros[name] = this.performMacroSubstitution(macDef, macros);

                if (__diag)
                {
                    host.diagnostics.debugLog("Defined macro '", name, "' to '", macros[name], "'\n");
                }
            }
        }
    }

    // performMacroSubstitutions():
    //
    // Performs a macro substitution.
    //
    performMacroSubstitution(line, macros)
    {
        var macroNames = Object.getOwnPropertyNames(macros);
        for (var macro of macroNames)
        {
            var startIdx = 0;
            var idx = line.indexOf(macro);
            var len = macro.length;
            while (idx != -1)
            {
                var doReplace = true;

                //
                // The macro only substitutes if there's not an ident character on either side.
                //
                if (idx != 0 && (this.isalpha(line, idx - 1) || line.charAt(idx - 1) == '_'))
                {
                    doReplace = false;
                }
                if (idx != (line.length - len) && this.isidentchar(line, idx + len))
                {
                    doReplace = false;
                }

                if (doReplace)
                {
                    line = line.substr(0, idx) + macros[macro] + line.substr(idx + len);
                    idx = line.indexOf(macro);
                }
                else
                {
                    idx = line.indexOf(macro, idx + len);
                }
            }
        }
        return line;
    }

    // performMacroSubstitutionIf:
    //
    // Performs a macro substitution within the text of an #if
    //
    performMacroSubstitutionIf(line, macros)
    {
        var finalLine = "";
        var curLine = line;
        for(;;)
        {
            var idxDefined = curLine.indexOf("defined(");
            if (idxDefined == -1)
            {
                curLine = this.performMacroSubstitution(curLine, macros);
                finalLine += curLine;
                break;
            }

            //
            // Slice out until the "defined(", perform macro substitution on the
            // pre-part.  Stick back in defined( ... ) and then continue after the
            // defined.
            //
            finalLine += this.performMacroSubstitution(curLine.slice(0, idxDefined), macros);
            finalLine += "defined(";
            curLine = curLine.slice(idxDefined + 8); // +8 == len of "defined("
            var idxRParen = curLine.indexOf(")");
            if (idxRParen == -1)
            {
                this.throwError("Illegal use of defined within a macro");
            }
            finalLine += curLine.slice(0, idxRParen + 1);
            curLine = curLine.slice(idxRParen + 1);
        }

        return finalLine;
    }

    // populateStartingMacros():
    // 
    // Populates a set of starting macros.
    //
    populateStartingMacros(macros, startingMacros)
    {
        if (startingMacros)
        {
            var startingNames = Object.getOwnPropertyNames(startingMacros);
            for (var macroName of startingNames)
            {
                //
                // There may be properties on here projected by the JavaScript provider that we cannot
                // legitimately touch (e.g.: targetSize).  Until we can separate those, simply catch any
                // failure to fetch a starting macro value.
                //
                try
                {
                    var macroValue = startingMacros[macroName];
                    if (typeof(macroValue) === "string")
                    {
                        macros[macroName] = macroValue;
                    }
                }
                catch(exc)
                {
                }
            }
        }
    }

    // predefineWindowsMacros():
    //
    // Predefines a set of windows macros.
    //
    predefineWindowsMacros(macros)
    {
        macros["DUMMYSTRUCTNAME"] = "";
        macros["DUMMYUNIONNAME"] = "";
        macros["MAX_PATH"] = "260";
        macros["IN"] = "";
        macros["OUT"] = "";
        macros["ANYSIZE_ARRAY"] = "1";
        
        //
        // Treat a few key SAL annotations as empty macros.  We do not care.
        // Some headers apply these on struct fields.
        //
        macros["_In_"] = "";
        macros["_Out_"] = "";
        macros["_Inout_"] = "";
        macros["_In_opt_"] = "";
    }

    // readLine():
    //
    // Reads a line from the text reader and updates our tracking of line numbers and the like.
    //
    readLine()
    {
        //
        // @TODO: AtEOF() should be exposed by the textReader and not just the underlying file!
        //
        var line = "";
        try
        {
            if (this.__reader)
            {
                line = this.__reader.ReadLine();
            }
            else
            {
                if (this.__lineNumber == 1)
                {
                    line = this.__string;
                }
                else
                {
                    this.__done = true;
                }
            }
            ++this.__lineNumber;
        }
        catch(exc)
        {
            this.__done = true;
        }
        return line;
    }

    // *[Symbol.iterator]:
    //
    // Produce the next token in our *LIMITED* understanding of a C header
    //
    *[Symbol.iterator]()
    {
        var curTok = "";
        var line = "";
        var macros = {};
        this.predefineWindowsMacros(macros);
        this.populateStartingMacros(macros, this.__startingMacros);
        var conditionals = [];

        while(!this.__done)
        {
            var isInCompilationScope = (conditionals.length == 0) || (conditionals[conditionals.length - 1]);
            var len = line.length;
            if (len == 0)
            {
                line = this.readLine();
                while (!this.__done && line.lastIndexOf("\\") == line.length - 1)
                {
                    line = line.slice(0, -1);
                    line += this.readLine();
                }
                line = line.trim();
                len = line.length;

                //
                // Handle any pre-processor directives.
                //
                var char0 = line.charAt(0);
                if (char0 == '#')
                {
                    if (len >= 7 && line.startsWith("#define"))
                    {
                        if (isInCompilationScope)
                        {
                            line = line.slice(7).trim();
                            this.defineMacro(macros, line);
                        }
                    }
                    else if (len >= 6 && line.startsWith("#ifdef"))
                    {
                        if (isInCompilationScope)
                        {
                            line = line.slice(6).trim();
                            var defined = (macros[line] !== undefined);
                            conditionals.push(defined);
                        }
                        else
                        {
                            conditionals.push(false);
                        }
                    }
                    else if (len >= 7 && line.startsWith("#ifndef"))
                    {
                        if (isInCompilationScope)
                        {
                            line = line.slice(7).trim();
                            var defined = (macros[line] !== undefined);
                            conditionals.push(!defined);
                        }
                        else
                        {
                            conditionals.push(false);
                        }
                    }

                    else if (len >= 3 && line.startsWith("#if"))
                    {
                        if (isInCompilationScope)
                        {
                            line = line.slice(3).trim();
                            line = this.performMacroSubstitutionIf(line, macros);
                            var macroTokenizer = new __CTokenStream(line);
                            var macroParser = new __CMacroParser(macroTokenizer);
                            var conditional = macroParser.macroConditionEval(macros);
                            conditionals.push(conditional);
                        }
                        else
                        {
                            conditionals.push(false);
                        }
                    }
                    else if (len >= 6 && line.startsWith("#endif"))
                    {
                        if (conditionals.length == 0)
                        {
                            this.throwError("Mismatched #endif");
                        }
                        conditionals.pop();
                    }
                    else if (len >= 4 && line.startsWith("#else"))
                    {
                        if (isInCompilationScope)
                        {
                            if (conditionals.length == 0)
                            {
                                this.throwError("Mismatched #else");
                            }
                            var conditional = conditionals.pop();
                            conditionals.push(!conditional);
                        }
                    }

                    //
                    // All other preprocessor directives are ignored (line level) for now.
                    //
                    isInCompilationScope = false;
                }

                if (isInCompilationScope)
                {
                    line = this.performMacroSubstitution(line, macros);

                    //
                    // Ensure that we've trimmed after any macro substitution so we're at the first
                    // non whitespace.
                    //
                    line = line.trim();
                    len = line.length;
                    continue;
                }
            }

            if (!isInCompilationScope)
            {
                line = "";
                continue;
            }

            switch(line.charAt(0))
            {
                case '/':
                {
                    if (len >= 2 && line.charAt(1) == '/')
                    {
                        // We have a comment from line onward.  Do not yield it.
                        line = "";
                    }
                    else if (len >= 2 && line.charAt(1) == '*')
                    {
                        var cmnt = line.slice(0, 1);
                        line = line.slice(1);

                        var endCmnt = line.indexOf("*/");
                        while (!this.__done && endCmnt == -1)
                        {
                            cmnt += line;
                            line = this.readLine();
                            endCmnt = line.indexOf("*/");
                        }
                        cmnt += line.slice(0, endCmnt + 1);
                        line = line.slice(endCmnt + 2).trim();

                        //
                        // We have a comment in cmnt.  Do not yield it.
                        //
                    }
                    else if (len >= 2 && line.charAt(1) == '=')
                    {
                        yield new __CToken(__tokenTypes.SlashEqual, line.slice(0, 2));
                        line = line.slice(2).trim();
                    }
                    else
                    {
                        yield new __CToken(__tokenTypes.Slash, line.slice(0, 1));
                        line = line.slice(1).trim();
                    }
                    break;
                }
                case '*':
                {
                    if (len >= 2 && line.charAt(1) == '=')
                    {
                        yield new __CToken(__tokenTypes.StarEqual, line.slice(0, 2));
                        line = line.slice(2).trim();
                    }
                    else
                    {
                        yield new __CToken(__tokenTypes.Star, line.slice(0, 1));
                        line = line.slice(1).trim();
                    }
                    break;
                }
                case '+':
                {
                    if (len >= 2 && line.charAt(1) == '=')
                    {
                        yield new __CToken(__tokenTypes.PlusEqual, line.slice(0, 2));
                        line = line.slice(2).trim();
                    }
                    else
                    {
                        yield new __CToken(__tokenTypes.Plus, line.slice(0, 1));
                        line = line.slice(1).trim();
                    }
                    break;
                }
                case '-':
                {
                    if (len >= 2 && line.charAt(1) == '=')
                    {
                        yield new __CToken(__tokenTypes.MinusEqual, line.slice(0, 2));
                        line = line.slice(2).trim();
                    }
                    else
                    {
                        yield new __CToken(__tokenTypes.Minus, line.slice(0, 1));
                        line = line.slice(1).trim();
                    }
                    break;
                }
                case '%':
                {
                    if (len >= 2 && line.charAt(1) == '=')
                    {
                        yield new __CToken(__tokenTypes.PercentEqual, line.slice(0, 2));
                        line = line.slice(2).trim();
                    }
                    else
                    {
                        yield new __CToken(__tokenTypes.Percent, line.slice(0, 1));
                        line = line.slice(1).trim();
                    }
                    break;
                }
                case '=':
                {
                    if (len >= 2 && line.charAt(1) == '=')
                    {
                        yield new __CToken(__tokenTypes.DoubleEqual, line.slice(0, 2));
                        line = line.slice(2).trim();
                    }
                    else
                    {
                        yield new __CToken(__tokenTypes.Equal, line.slice(0, 1));
                        line = line.slice(1).trim();
                    }
                    break;
                }
                case '!':
                {
                    if (len >= 2 && line.charAt(1) == '=')
                    {
                        yield new __CToken(__tokenTypes.BangEqual, line.slice(0, 2));
                        line = line.slice(2).trim();
                    }
                    else
                    {
                        yield new __CToken(__tokenTypes.Bang, line.slice(0, 1));
                        line = line.slice(1).trim();
                    }
                    break;
                }
                case '&':
                {
                    if (len >= 2 && line.charAt(1) == '&')
                    {
                        yield new __CToken(__tokenTypes.DoubleAmpersand, line.slice(0, 2));
                        line = line.slice(2).trim();
                    }
                    else
                    {
                        yield new __CToken(__tokenTypes.Ampersand, line.slice(0, 1));
                        line = line.slice(1).trim();
                    }
                    break;
                }
                case '^':
                {
                    yield new __CToken(__tokenTypes.Caret, line.slice(0, 1));
                    line = line.slice(1).trim();
                    break;
                }
                case '|':
                {
                    if (len >= 2 && line.charAt(1) == '|')
                    {
                        yield new __CToken(__tokenTypes.DoublePipe, line.slice(0, 2));
                        line = line.slice(2).trim();
                    }
                    else
                    {
                        yield new __CToken(__tokenTypes.Pipe, line.slice(0, 1));
                        line = line.slice(1).trim();
                    }
                    break;
                }
                case '<':
                {
                    if (len >= 2 && line.charAt(1) == '<')
                    {
                        yield new __CToken(__tokenTypes.DoubleLT, line.slice(0, 2));
                        line = line.slice(2).trim();
                    }
                    else if (len >= 2 && line.charAt(1) == '=')
                    {
                        yield new __CToken(__tokenTypes.LTEqual, line.slice(0, 2));
                        line = line.slice(2).trim();
                    }
                    else
                    {
                        yield new __CToken(__tokenTypes.LT, line.slice(0, 1));
                        line = line.slice(1).trim();
                    }
                    break;
                }
                case '>':
                {
                    if (len >= 2 && line.charAt(1) == '>')
                    {
                        yield new __CToken(__tokenTypes.DoubleGT, line.slice(0, 2));
                        line = line.slice(2).trim();
                    }
                    else if (len >= 2 && line.charAt(1) == '=')
                    {
                        yield new __CToken(__tokenTypes.GTEqual, line.slice(0, 2));
                        line = line.slice(2).trim();
                    }
                    else
                    {
                        yield new __CToken(__tokenTypes.GT, line.slice(0, 1));
                        line = line.slice(1).trim();
                    }
                    break;
                }
                case '[':
                    yield new __CToken(__tokenTypes.LBracket, line.slice(0, 1));
                    line = line.slice(1).trim();
                    break;
                case ']':
                    yield new __CToken(__tokenTypes.RBracket, line.slice(0, 1));
                    line = line.slice(1).trim();
                    break;
                case '{':
                    yield new __CToken(__tokenTypes.LBrace, line.slice(0, 1));
                    line = line.slice(1).trim();
                    break;
                case '}':
                    yield new __CToken(__tokenTypes.RBrace, line.slice(0, 1));
                    line = line.slice(1).trim();
                    break;
                case '(':
                    yield new __CToken(__tokenTypes.LParen, line.slice(0, 1));
                    line = line.slice(1).trim();
                    break;
                case ')':
                    yield new __CToken(__tokenTypes.RParen, line.slice(0, 1));
                    line = line.slice(1).trim();
                    break;
                case ';':
                    yield new __CToken(__tokenTypes.Semicolon, line.slice(0, 1));
                    line = line.slice(1).trim();
                    break;
                case ':':
                    yield new __CToken(__tokenTypes.Colon, line.slice(0, 1));
                    line = line.slice(1).trim();
                    break;
                case ',':
                    yield new __CToken(__tokenTypes.Comma, line.slice(0, 1));
                    line = line.slice(1).trim();
                    break;
                default:
                {
                    var c = line.charAt(0);
                    if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                    {
                        var i = 1;
                        while(i < len && this.isidentchar(line, i)) { ++i; }
                        var name = line.slice(0, i);
                        line = line.slice(i).trim();
                        var lookup = __tokenMappings[name];
                        if (lookup !== undefined)
                        {
                            yield new __CToken(lookup, name);
                        }
                        else
                        {
                            yield new __CToken(__tokenTypes.Identifier, name);
                        }
                    }
                    else if (this.isnum(line, 0))
                    {
                        var i = 1;
                        if (len >= 3 && line.startsWith("0x"))
                        {
                            //
                            // parseInt will deal correctly with the 0x on the front as a hex radix
                            // specifier.  We do not need to special case that.
                            //
                            i += 2;
                            while (i < len && this.ishexdigit(line, i)) { ++i; }
                        }
                        else
                        {
                            while (i < len && this.isnum(line, i)) { ++i; }
                        }

                        var valString = line.slice(0, i);
                        yield new __CToken(__tokenTypes.IntValue, valString, parseInt(valString));
                        line = line.slice(i).trim();
                    }
                    else
                    {
                        //
                        // This isn't any real attempt to resynchronize.  Just skip the remainder of the line.
                        // We have encountered something we don't understand.
                        //
                        line = "";
                    }
                    break;
                }
            }
        }
    }
};

// __evaluateStack():
//
// Performs an evaluation of everything on the operand/operator stack and returns the result.
// The stacks are altered as a result.
//
function __evaluateStack(valStack, opStack)
{
    while(opStack.length > 0)
    {
        var op = opStack.pop();

        //*************************************************
        // Unary:
        //

        if (valStack.length < 1)
        {
            throw new Error("Expected operand in expression");
        }
        var firstVal = valStack.pop();

        if (op == __operators.UnaryOpNegative)
        {
            valStack.push(-firstVal);
            continue;
        }
        else if (op == __operators.UnaryOpLogicalNot)
        {
            valStack.push(!firstVal);
            continue;
        }

        //*************************************************
        // Binary:
        //

        if (valStack.length < 1)
        {
            throw new Error("Expected operand in expression");
        }
        var secondVal = valStack.pop();

        if (op == __operators.BinaryOpAdd)
        {
            valStack.push(secondVal + firstVal);
        }
        else if (op == __operators.BinaryOpSubtract)
        {
            valStack.push(secondVal - firstVal);
        }
        else if (op == __operators.BinaryOpMultiply)
        {
            valStack.push(secondVal * firstVal);
        }
        else if (op == __operators.BinaryOpDivide)
        {
            valStack.push(secondVal / firstVal);
        }
        else if (op == __operators.BinaryOpModulo)
        {
            valStack.push(secondVal % firstVal);
        }
        else if (op == __operators.BinaryOpLogicalAnd)
        {
            valStack.push(secondVal && firstVal);
        }
        else if (op == __operators.BinaryOpLogicalOr)
        {
            valStack.push(secondVal || firstVal);
        }
        else if (op == __operators.BinaryOpEqualCompare)
        {
            valStack.push(secondVal == firstVal);
        }
        else if (op == __operators.BinaryOpNotEqualCompare)
        {
            valStack.push(secondVal != firstval);
        }
        else if (op == __operators.BinaryOpLess)
        {
            valStack.push(secondVal < firstVal);
        }
        else if (op == __operators.BinaryOpLessEqual)
        {
            valStack.push(secondVal <= firstVal);
        }
        else if (op == __operators.BinaryOpGreater)
        {
            valStack.push(secondVal > firstVal);
        }
        else if (op == __operators.BinaryOpGreaterEqual)
        {
            valStack.push(secondVal >= firstVal);
        }
        else if (op == __operators.BinaryOpLeftShift)
        {
            valStack.push(secondVal << firstVal);
        }
        else if (op == __operators.BinaryOpRightShift)
        {
            valStack.push(secondVal >> firstVal);
        }
        else if (op == __operators.BinaryOpBitwiseOr)
        {
            valStack.push(secondVal | firstVal);
        }
        else if (op == __operators.BinaryOpBitwiseAnd)
        {
            valStack.push(secondVal & firstVal);
        }
        else if (op == __operators.BinaryOpBitwiseXor)
        {
            valStack.push(secondVal ^ firstVal);
        }
        continue;
    }

    if (opStack.length != 0 || valStack.length != 1)
    {
        throw new Error("Illegal expression");
    }

    return valStack.pop();
}


// __CParser:
//
// Simple C header parser.
//
class __CParser
{
    constructor(reader, startingMacros)
    {
        this.__tokenStream = new __CTokenStream(reader, startingMacros);
        this.__iterator = (this.__tokenStream[Symbol.iterator])();
        this.__forwardTokenPos = [];
        this.__peekAhead = 0;
        this.__peekAheadDone = false;
        this.__inScopeEnumerants = {};
    }

    throwError(msg)
    {
        if (this.__tokenStream && this.__tokenStream.__lineNumber)
        {
            var tokenString = "<unknown>";
            if (this.__curToken && this.__curToken.__tokenString)
            {
                tokenString = this.__curToken.__tokenString;
            }

            throw new Error("Line " + this.__tokenStream.__lineNumber.toString() + ": " + msg + " at " + tokenString);
        }
        else
        {
            throw new Error(msg);
        }
    }

    // advance():
    //
    // Moves the tokenizer forward.
    //
    advance(require)
    {
        if (this.__peekAhead > 0)
        {
            this.__curTokenPos = this.__forwardTokenPos.shift();
            this.__curToken = this.__curTokenPos.value;
            this.__peekAhead--;
        }
        else
        {
            this.__curTokenPos = this.__iterator.next();
            this.__curToken = this.__curTokenPos.value;
        }

        if (this.__curTokenPos.done && require)
        {
            this.throwError("Unexpected end of file in processing header");
        }
    }

    // peekAhead():
    //
    // Peeks the tokenizer N tokens forward.
    //
    peekAhead(n)
    {
        if (this.__peekAhead < n)
        {
            var nextPeek = n - this.__peekAhead;
            for (var i = 0; i < nextPeek; ++i)
            {
                this.__forwardTokenPos.push(this.__iterator.next());
            }
            this.__peekAhead += nextPeek;
        }
        if (this.__peekAhead < n || this.__forwardTokenPos[n - 1].done)
        {
            return null;
        }
        return this.__forwardTokenPos[n - 1].value;
    }

    // expect():
    //
    // Expects a given token at the current position and moves the tokenizer forward.
    //
    expect(tokenType, requireFwd)
    {
        if (this.__curToken.__tokenType != tokenType)
        {
            this.throwError("Unexpected token");
        }
        var req = true;
        if (requireFwd !== undefined)
        {
            req = requireFwd;
        }
        this.advance(req);
    }

    // skipTo():
    //
    // Skips to the next occurrence of the given token type.
    //
    skipTo(tokenType)
    {
        while(!this.__curTokenPos.done && this.__curToken.__tokenType != tokenType)
        {
            this.advance(true);
        }

        if (this.__curTokenPos.done)
        {
            throwError("Did not find token skip destination");
        }
    }

    // readAddPostQualifiers:
    //
    // Adds qualifiers after the type name (if any)
    //
    readAddPostQualifiers(name)
    {
        while(true)
        {
            if (this.__curToken.__tokenType == __tokenTypes.Star)
            {
                name += "*";
                this.advance(true);
            }
            else if (this.__curToken.__tokenType == __tokenTypes.Const ||
                     this.__curToken.__tokenType == __tokenTypes.Volatile)
            {
                //
                // We don't care about qualifiers applied to pointer types (e.g.: foo * const *)
                //
                this.advance(true);
            }
            else
            {
                break;
            }
        }
        return name;
    }

    // readCompilerType:
    //
    // Reads a compiler type.
    //
    readCompilerType()
    {
        var name = "";
        if (this.__curToken.__tokenType == __tokenTypes.Unsigned)
        {
            name = "unsigned ";
            this.advance(true);
        }
        name += this.__curToken.__tokenString;
        this.advance(true);
        name = this.readAddPostQualifiers(name);
        return { name: name, isSynthetic: false };
    }

    // __resolveTypeName:
    //
    // Resolves a type name thorugh any aliases (typedefs) to a final type name.
    //
    __resolveTypeName(typeName)
    {
        for(;;)
        {
            var remap = __remappedTypes[typeName];
            if (remap === undefined)
            {
                remap = __typeAliases[typeName];
            }
            if (remap !== undefined)
            {
                if (typeName == remap)
                {
                    break;
                }
                typeName = remap;
                continue;
            }
            break;
        }
        return typeName;
    }

    // skipModifiers():
    //
    // Walks past type modifiers like const/volatile/etc...
    //
    skipModifiers()
    {
        while(this.__curToken.__tokenType == __tokenTypes.Const ||
              this.__curToken.__tokenType == __tokenTypes.Volatile)
        {
            this.advance(true);
        }
    }

    // readTypeName:
    //
    // Reads a type name within a simple declaration.
    //
    readTypeName(typeTable)
    {
        var isSynthetic = false;
        var typeName = "";

        this.skipModifiers();

        if (this.__curToken.__tokenType == __tokenTypes.Identifier)
        {
            typeName = this.__resolveTypeName(this.__curToken.__tokenString);
            this.advance(true);
            typeName = this.readAddPostQualifiers(typeName);
            return { name: typeName, isSynthetic: (!typeTable.__isSymbolType(typeName)) };
        }
        else if (this.__curToken.__tokenType == __tokenTypes.Unsigned ||
                 this.__curToken.__tokenType == __tokenTypes.Char ||
                 this.__curToken.__tokenType == __tokenTypes.Short ||
                 this.__curToken.__tokenType == __tokenTypes.Int ||
                 this.__curToken.__tokenType == __tokenTypes.Long ||
                 this.__curToken.__tokenType == __tokenTypes.Int64)
        {
            return this.readCompilerType();
        }
        else if (this.__curToken.__tokenType == __tokenTypes.Struct ||
                 this.__curToken.__tokenType == __tokenTypes.Union)
        {
            var isStruct = (this.__curToken.__tokenType == __tokenTypes.Struct);
            
            //
            // Check for an old style "struct FOO foo" by peeking for the expected "{" which
            // would indicate a definition.
            //
            var isStructFld = false;
            var peekAhead2 = this.peekAhead(2);
            var peekAhead1 = this.peekAhead(1);
            if (peekAhead2)
            {
                //
                // We can have unnamed structs.  This could be "struct {" or "struct FOO {" as a declaration.
                // What we want to weed out is a declaration struct FOO foo;
                //          
                isStructFld = peekAhead1.__tokenType != __tokenTypes.LBrace && 
                              peekAhead2.__tokenType != __tokenTypes.LBrace;
            }

            if (isStructFld)
            {
                //
                // turn "struct FOO foo;" into "FOO foo" from the perspective of our parsing.
                // It might be nice to verify that FOO really is a struct/union
                //
                this.advance(true);
                typeName = this.__resolveTypeName(this.__curToken.__tokenString);
                this.advance(true);
                typeName = this.readAddPostQualifiers(typeName);
                return { name : typeName, isSynthetic: (!typeTable.__isSymbolType(typeName)) };
            }
            
            var typeDefinition;
            if (isStruct)
            {
                typeDefinition = this.readStruct(typeTable);
            }
            else
            {
                typeDefinition = this.readUnion(typeTable);
            }

            return { name : typeDefinition.Name, isSynthetic: !typeTable.__isSymbolType(typeDefinition.Name), isEmbeddedUDT: true };
        }
    }

    // addField:
    //
    // Reads a field definition in a data structure.
    //
    addField(typeTable, typeEntry)
    {
        var typeInfo = this.readTypeName(typeTable);

        //
        // Yes-- there are fields like "int :7" which just skip bits...
        //
        var name;
        if (this.__curToken.__tokenType == __tokenTypes.LBracket ||
            this.__curToken.__tokenType == __tokenTypes.Colon)
        {
            name = __generateUniqueName(typeTable, "FIELD");
        }
        else if (this.__curToken.__tokenType == __tokenTypes.Semicolon && typeInfo.isEmbeddedUDT)
        {
            //
            // It's unnamed.  If it's a struct or a union, we can just embed it and not generate
            // a synthetic name.
            //
            // Let name go undefined.
            //
        }
        else if (this.__curToken.__tokenType != __tokenTypes.Identifier)
        {
            this.throwError("Expected identifier");
        }    
        else
        {
            name = this.__curToken.__tokenString;
            this.advance(true);
        }

        var bitLength;
        if (this.__curToken.__tokenType == __tokenTypes.LBracket)
        {
            //
            // We have an array.  Stick it in the type name.
            //
            this.advance(true);
            var arraySize = this.staticEvaluate(typeTable);
            this.expect(__tokenTypes.RBracket);
            typeInfo.name += "[" + arraySize.toString() + "]";
        }
        else if (this.__curToken.__tokenType == __tokenTypes.Colon)
        {
            //
            // We have a bit field.
            //
            this.advance(true);
            if (this.__curToken.__tokenType == __tokenTypes.IntValue)
            {
                bitLength = this.__curToken.__value;
                this.advance();
            }
            else
            {
                this.throwError("Expected numeric value for bitfield length");
            }
        }

        if (__diag)
        {
            host.diagnostics.debugLog("    Adding a field: ", typeInfo.name, "(Syn = ", typeInfo.isSynthetic, ") as '", name, "'\n");
        }

        var fieldInfo = {};
        if (name !== undefined)
        {
            fieldInfo.fieldName = name;
        }
        if (typeInfo.isSynthetic)
        {
            fieldInfo.fieldSyntheticType = typeInfo.name;
        }
        else
        {
            fieldInfo.fieldType = typeInfo.name;
        }
        if (bitLength !== undefined)
        {
            fieldInfo.bitLength = bitLength;
        }

        typeEntry.push(fieldInfo);

        this.expect(__tokenTypes.Semicolon);
    }

    // readContents():
    //
    // Reads a struct/union and returns a list of field entries.
    //
    readContents(typeTable)
    {
        var typeEntry = [];
        var name;

        //
        // Many windows headers utilize unnamed structures and unions.  In order to create synthetics,
        // we must give such a type a name.
        //
        if (this.__curToken.__tokenType == __tokenTypes.LBrace)
        {
            name = __generateUniqueName(typeTable, "TYPE");
        }
        else
        {
            if (this.__curToken.__tokenType != __tokenTypes.Identifier)
            {
                this.throwError("Expected identifier after struct/union");
            }
            name = this.__curToken.__tokenString;
            this.advance(true);
        }
        this.expect(__tokenTypes.LBrace);

        if (__diag)
        {
            host.diagnostics.debugLog("Parsing structure '", name, "'\n");
        }

        while(this.__curToken.__tokenType != __tokenTypes.RBrace)
        {
            this.addField(typeTable, typeEntry);
        }
        this.expect(__tokenTypes.RBrace);

        return new __TypeDefinition(name, typeTable, typeEntry);
    }

    // readStruct():
    //
    // Reads a struct definition (tokenizer positioned *AT* the struct) and returns a definition.
    //
    readStruct(typeTable)
    {
        this.advance(true);
        var definition = this.readContents(typeTable);
        definition.IsUnion = false;
        __defineSyntheticType(typeTable, definition);
        return definition;
    }

    // readUnion():
    //
    // Reads a union definition (tokenizer positioned *AT* the union) and returns a definition.
    //
    readUnion(typeTable)
    {
        this.advance(true);
        var definition = this.readContents(typeTable);
        definition.IsUnion = true;
        __defineSyntheticUnion(typeTable, definition);
        return definition;
    }

    // readEnumerant():
    //
    // Reads an enumerant definition within an enum.
    //
    readEnumerant(typeTable, priorValue)
    {
        var enumVal;
        if (priorValue)
        {
            enumVal = priorValue + 1;
        }
        else
        {
            enumVal = 0;
        }

        if (this.__curToken.__tokenType != __tokenTypes.Identifier)
        {
            this.throwError("Unexpected token");
        }
        var name = this.__curToken.__tokenString;
        this.advance(true);

        if (this.__curToken.__tokenType == __tokenTypes.Equal)
        {
            this.advance(true);
            enumVal = this.staticEvaluate(typeTable);
        }

        if (this.__curToken.__tokenType != __tokenTypes.Comma &&
            this.__curToken.__tokenType != __tokenTypes.RBrace)
        {
            this.throwError("Unexpected token");
        }

        if (this.__curToken.__tokenType == __tokenTypes.Comma)
        {
            this.advance(true);
        }

        var enumerant = new __Enumerant(name, enumVal);
        this.__inScopeEnumerants[name] = enumerant;
        return enumerant;
    }

    // readEnum():
    //
    // Reads an enum definition (tokenizer positioned *AT* the enum) and returns a definition.
    //
    readEnum(typeTable)
    {
        var name;

        this.advance(true);

        //
        // Many windows headers utilize unnamed enums.  In order to create synthetics,
        // we must give such a type a name.
        //
        if (this.__curToken.__tokenType == __tokenTypes.LBrace)
        {
            name = __generateUniqueName(typeTable, "ENUM");
        }
        else
        {
            if (this.__curToken.__tokenType != __tokenTypes.Identifier)
            {
                this.throwError("Expected identifier after struct/union");
            }
            name = this.__curToken.__tokenString;
            this.advance(true);
        }
        this.expect(__tokenTypes.LBrace);

        if (__diag)
        {
            host.diagnostics.debugLog("Parsing enum '", name, "'\n");
        }

        var priorValue;
        var enumerants = [];
        while(this.__curToken.__tokenType != __tokenTypes.RBrace)
        {
            var enumerant = this.readEnumerant(typeTable, priorValue);
            priorValue = enumerant.Value;
            enumerants.push(enumerant);
        }
        this.expect(__tokenTypes.RBrace);

        var enumDef = new __EnumDefinition(name, "int", enumerants);

        __enumTypes[enumDef.Name] = {
            definition: enumDef,
            containingTable: typeTable
            };

        // __typeAliases[enumDef.Name] = enumDef.BaseType;

        return enumDef;
    }

    // __evaluateUntil():
    //
    // Evaluate until we hit a particular token (or EOF for undefined)
    //
    __evaluateUntil(typeTable, endToken)
    {
        var valStack = [];
        var opStack = [];

        var lastPrecedence = 0;
        var operand = true;
        while(true)
        {
            if (this.__curTokenPos.done)
            {
                break;
            }

            var tokenValue = this.__curToken;
            var tokenType = tokenValue.__tokenType;
            var val;

            if (tokenType == endToken)
            {
                break;
            }
            else if (tokenType == __tokenTypes.SizeOf)
            {
                if (!operand)
                {
                    this.throwError("UnexpectedToken");
                }

                this.advance(true);
                this.expect(__tokenTypes.LParen);
                var nameInfo = this.readTypeName(typeTable);
                val = __getTypeSize(typeTable, nameInfo.name);
                this.expect(__tokenTypes.RParen);
                operand = false;
            }
            else if (tokenType == __tokenTypes.True)
            {
                valStack.push(true);
                this.advance();
                operand = false;
            }
            else if (tokenType == __tokenTypes.False)
            {
                valStack.push(false);
                this.advance();
                operand = false;
            }
            else if (tokenType == __tokenTypes.IntValue)
            {
                if (!operand)
                {
                    this.throwError("Unexpected token");
                }
                val = tokenValue.__value;
                valStack.push(val);
                this.advance();
                operand = false;
            }
            else if (tokenType == __tokenTypes.LParen)
            {
                if (!operand)
                {
                    this.throwError("Unexpected token");
                }

                this.advance();
                val = this.__evaluateUntil(typeTable, __tokenTypes.RParen);
                this.expect(__tokenTypes.RParen);
                valStack.push(val);
                operand = false;
            }
            else if (tokenType == __tokenTypes.Identifier)
            {
                if (!operand)
                {
                    this.throwError("Unexpected token");
                }

                //
                // Is it an in-scope enumerant.
                //
                var identifier = this.__curToken.__tokenString;
                var enumerant = this.__inScopeEnumerants[identifier];
                if (enumerant)
                {
                    this.advance();
                    valStack.push(enumerant.Value);
                    operand = false;
                }
                else
                {
                    //
                    // We do not recognize this.  Let the caller deal with it.
                    //
                    break;
                }
            }
            else
            {
                var operator = __getOperatorForToken(tokenType, operand);
                if (operator)
                {
                    var curPrecedence = __operatorPrecedenceMappings[operator];
                    if (curPrecedence <= lastPrecedence)
                    {
                        val = __evaluateStack(valStack, opStack);
                        valStack = [val];
                        opStack = [];
                    }
                    opStack.push(operator);
                    lastPrecedence = curPrecedence;
                    this.advance();
                    operand = true;
                }
                else
                {
                    //
                    // Let the caller determine whether ending at this token is appropriate.
                    //
                    break;
                }
            }
        }

        val = __evaluateStack(valStack, opStack);
        return val;
    }

    // staticEvaluate():
    //
    // Performs a (very limited) expression evaluation in contexts where a constant expression is allowed.
    //
    staticEvaluate(typeTable)
    {
        return this.__evaluateUntil(typeTable);
    }

    // readTypeTable():
    //
    // Reads the header file and creates a type table based on it.
    //
    readTypeTable(boundModule, path, attributes)
    {
        var typeTable = new __TypeTable(boundModule, path, attributes);
        this.advance(false);

        while(true)
        {
            if (this.__curTokenPos.done)
            {
                break;
            }

            var tokenValue = this.__curToken;
            var tokenType = tokenValue.__tokenType;

            if (tokenType == __tokenTypes.Struct || tokenType == __tokenTypes.Union)
            {
                //
                // Make sure we aren't seeing struct FOO f; or the like in the middle of a function
                // prototype or something else we totally ignore.
                //
                var isStructFld = false;
                var peekAhead2 = this.peekAhead(2);
                var peekAhead1 = this.peekAhead(1);
                if (peekAhead2)
                {
                    //
                    // We can have unnamed structs.  This could be "struct {" or "struct FOO {" as a declaration.
                    // What we want to weed out is a declaration struct FOO foo;
                    //          
                    isStructFld = peekAhead1.__tokenType != __tokenTypes.LBrace && 
                                  peekAhead2.__tokenType != __tokenTypes.LBrace;
                }

                if (!isStructFld)
                {
                    if (tokenType == __tokenTypes.Struct)
                    {
                        this.readStruct(typeTable);
                    }
                    else
                    {
                        this.readUnion(typeTable);
                    }

                    this.expect(__tokenTypes.Semicolon, false);
                }
                else
                {
                    //
                    // Treat the same as something we do not deal with.  Skip this and continue looking.
                    //
                    this.advance();
                }
            }
            else if (tokenType == __tokenTypes.Enum)
            {
                this.readEnum(typeTable);
                this.expect(__tokenTypes.Semicolon, false);
            }
            else if (tokenType == __tokenTypes.Typedef)
            {
                var typeName;

                this.advance(true);
                if (this.__curToken.__tokenType == __tokenTypes.Struct || this.__curToken.__tokenType == __tokenTypes.Union)
                {
                    var typeDefinition;

                    if (this.__curToken.__tokenType == __tokenTypes.Struct)
                    {
                        typeDefinition = this.readStruct(typeTable);
                    }
                    else
                    {
                        typeDefinition = this.readUnion(typeTable);
                    }

                    typeName = typeDefinition.Name;
                }
                else if (this.__curToken.__tokenType == __tokenTypes.Enum)
                {
                    var enumDefinition = this.readEnum(typeTable);
                    typeName = enumDefinition.Name;
                }
                else
                {
                    var nameInfo = this.readTypeName(typeTable);
                    if (nameInfo !== undefined)
                    {
                        typeName = nameInfo.name;
                    }
                }

                //
                // name, name (potentially with modifiers)
                //
                while(typeName !== undefined && true)
                {
                    var quals = "";
                    while (this.__curToken.__tokenType == __tokenTypes.Star)
                    {
                        quals += "*";
                        this.advance(true);
                    }

                    if (this.__curToken.__tokenType != __tokenTypes.Identifier)
                    {
                        //
                        // If we do not understand the typedef (e.g.: a function or other typedef),
                        // just skip to the enclosing semicolon.
                        //
                        this.skipTo(__tokenTypes.Semicolon);
                        break;
                    }

                    var name = this.__curToken.__tokenString;

                    //
                    // For the typedef, insert an alias to the actual type.  Make sure we do not
                    // treat:
                    //
                    // typedef struct FOO { ... } FOO; as a typedef from FOO->FOO.  In this case,
                    // just ignore the typedef.
                    //
                    var typeTarget = typeName + quals;
                    if (name != typeTarget)
                    {
                        __typeAliases[name] = typeName + quals;
                    }

                    this.advance(true);
                    if (this.__curToken.__tokenType != __tokenTypes.Comma)
                    {
                        break;
                    }
                    this.advance(true);
                }
            }
            else
            {
                //
                // We don't care what this is...
                //
                this.advance();
            }
        }

        return typeTable;
    }
};


//*************************************************
// Script Initialization and Extensions

class __SyntheticTypes
{
    // __findTypeTable():
    //
    // Finds a type table for the given path and module (if one has already been read)
    //
    __findTypeTable(path, boundModule)
    {
        var mod = __getModuleFor(boundModule);
        for (var typeTable of __typeTables)
        {
            if (mod.Name == typeTable.Module.Name && mod.BaseAddress == typeTable.Module.BaseAddress)
            {
                //
                // We've found a type table bound to the same module.  Is it the same header read?
                //
                if (typeTable.__headerPath !== undefined && typeTable.__headerPath == path)
                {
                    return typeTable;
                }
            }
        }
        return null;
    }

    // ReadHeader():
    //
    // Performs a limited understanding read of a C header file and generates synthetic types
    // based on that understanding.  The return value is a type table.
    //
    ReadHeader(path, boundModule, attributes)
    {
        if (boundModule === undefined)
        {
            throw new Error("ReadHeader() requires a module to bind type names to");
        }

        var macros;
        if (attributes && attributes.Macros)
        {
            macros = attributes.Macros;
        }

        //
        // If we already have a type table, just return it.  Don't bother to reread the
        // table.  This will prevent things like DML links from repeatedly rereading the 
        // header and creating duplicate tables!
        //
        var typeTable = this.__findTypeTable(path, boundModule);
        if (typeTable)
        {
            return typeTable;
        }

        var file = __getAPI().FileSystem.OpenFile(path);
        var capturedException;
        try
        {
            var reader = __getAPI().FileSystem.CreateTextReader(file);
            var parser = new __CParser(reader, macros);
            typeTable = parser.readTypeTable(boundModule, path, attributes);
            __typeTables.push(typeTable);
        }
        catch(exc)
        {
            capturedException = exc;
            if (__diag)
            {
                host.diagnostics.debugLog("We hit an exception: '", exc, "'!\n");
            }
        }
        file.Close();

        //
        // If the header failed to read: pass the error back.  Do not give the user an invalid or
        // partial type table.
        //
        if (capturedException)
        {
            throw capturedException;
        }

        return typeTable;
    }

    // CreateInstance():
    //
    // Creates an instance of a given type.
    //
    CreateInstance(typeName, addrObj)
    {
        var name = typeName;
        var alias = __typeAliases[name];
        if (alias !== undefined)
        {
            name = alias;
        }
        var def = __syntheticTypes[name];
        if (def === undefined)
        {
            desc = __enumTypes[name];
            if (desc === undefined)
            {
                throw new Error("Unrecognized type name");
            }

            var enumsAsObjects = enumDesc.containingTable.ReturnEnumsAsObjects;
            return __createEnumValue(desc.definition, addr, desc.containingTable.Module, enumsAsObjects);
        }

        var ctor = def.classObject;
        return new ctor(addrObj, def.containingTable.Module);
    }

    // TypeTables():
    //
    // Returns the type tables we have read.
    //
    get TypeTables()
    {
        return __typeTables;
    }

    get [Symbol.metadataDescriptor]()
    {
        return {
            ReadHeader: { PreferShow: true,
                          Help: "ReadHeader(headerPath, module, [attributes])- Reads a header at the file and defines synthetic constructors for all structs and unions in the header referencing existing types in the given module.  Attributes is a set of key value pairs.  Presently, it may contain Macros (another set of key/value pairs), an optional ReturnEnumsAsObjects value (defaulting to false), and an optional RegisterSyntheticTypeModels value (defaulting to false).  If synthetic type models are registered, they are named DataModel.SyntheticTypes.<HeaderName>.<TypeName> and can be extended similarly."
            },
            CreateInstance: {PreferShow: true,
                             Help: "CreateInstance(typeName, addrObj) - Creates an instance of a synthetic type and returns it.  The type must have been read from a header or defined through other APIs here"
            },
            TypeTables: {Help: "The set of type tables create from prior calls to read headers or define tables"}
        };
    }
}

class __AnalysisExtension
{
    get SyntheticTypes()
    {
        return new __SyntheticTypes();
    }
};

function initializeScript()
{
    return [new host.apiVersionSupport(1, 2),
            new host.namespacePropertyParent(__AnalysisExtension, "Debugger.Models.Utility", "Debugger.Models.Utility.Analysis", "Analysis")];
}

// SIG // Begin signature block
// SIG // MIIh2wYJKoZIhvcNAQcCoIIhzDCCIcgCAQExDzANBglg
// SIG // hkgBZQMEAgEFADB3BgorBgEEAYI3AgEEoGkwZzAyBgor
// SIG // BgEEAYI3AgEeMCQCAQEEEBDgyQbOONQRoqMAEEvTUJAC
// SIG // AQACAQACAQACAQACAQAwMTANBglghkgBZQMEAgEFAAQg
// SIG // HoXf7KFjUXUpNqY4mp3zsMHRwlJbmor2X64eg4u1Mjag
// SIG // gguBMIIFCTCCA/GgAwIBAgITMwAAA4Pq27vZbyG4+gAA
// SIG // AAADgzANBgkqhkiG9w0BAQsFADB+MQswCQYDVQQGEwJV
// SIG // UzETMBEGA1UECBMKV2FzaGluZ3RvbjEQMA4GA1UEBxMH
// SIG // UmVkbW9uZDEeMBwGA1UEChMVTWljcm9zb2Z0IENvcnBv
// SIG // cmF0aW9uMSgwJgYDVQQDEx9NaWNyb3NvZnQgQ29kZSBT
// SIG // aWduaW5nIFBDQSAyMDEwMB4XDTIwMDkyNDE5MTAzNVoX
// SIG // DTIxMDkyMzE5MTAzNVowfzELMAkGA1UEBhMCVVMxEzAR
// SIG // BgNVBAgTCldhc2hpbmd0b24xEDAOBgNVBAcTB1JlZG1v
// SIG // bmQxHjAcBgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3JhdGlv
// SIG // bjEpMCcGA1UEAxMgTWljcm9zb2Z0IFdpbmRvd3MgS2l0
// SIG // cyBQdWJsaXNoZXIwggEiMA0GCSqGSIb3DQEBAQUAA4IB
// SIG // DwAwggEKAoIBAQCnt52Kmu4L6Ba3yRL/0obWfohcrE/X
// SIG // yxFhdCkbiMbB55kRKDvAu37z1cSAonm45shuXzH5EWIB
// SIG // w06wzKPt0RHFt9yp5JNQOgglKttQ+JNOjhCA5Rr6rKwP
// SIG // PjPstu/8doUJ5uvSZR6tqYee/f5krppjMclmkNC2Dgrw
// SIG // 9yOmYt5BUvCUNAto/EaX5UhodlIfdF9aNZZ5mY0+dvjq
// SIG // P99wtsRirRmkPLKyAclZHV10w0qhAcANGPLjNurpjiBI
// SIG // T5oQWOYOAGX8A91Bovzwf1Qh3HsYSPE6YdIprFLodldJ
// SIG // TawSwJSBWRWXmFjtQg0zNP8YGOKFt0CdwappX4L/eIA4
// SIG // ELIRAgMBAAGjggF9MIIBeTAfBgNVHSUEGDAWBgorBgEE
// SIG // AYI3CgMUBggrBgEFBQcDAzAdBgNVHQ4EFgQUeEXr3DrQ
// SIG // 1r71bRhURXpiKYw85w4wVAYDVR0RBE0wS6RJMEcxLTAr
// SIG // BgNVBAsTJE1pY3Jvc29mdCBJcmVsYW5kIE9wZXJhdGlv
// SIG // bnMgTGltaXRlZDEWMBQGA1UEBRMNMjI5OTAzKzQ2MTIx
// SIG // NDAfBgNVHSMEGDAWgBTm/F97uyIAWORyTrX0IXQjMubv
// SIG // rDBWBgNVHR8ETzBNMEugSaBHhkVodHRwOi8vY3JsLm1p
// SIG // Y3Jvc29mdC5jb20vcGtpL2NybC9wcm9kdWN0cy9NaWND
// SIG // b2RTaWdQQ0FfMjAxMC0wNy0wNi5jcmwwWgYIKwYBBQUH
// SIG // AQEETjBMMEoGCCsGAQUFBzAChj5odHRwOi8vd3d3Lm1p
// SIG // Y3Jvc29mdC5jb20vcGtpL2NlcnRzL01pY0NvZFNpZ1BD
// SIG // QV8yMDEwLTA3LTA2LmNydDAMBgNVHRMBAf8EAjAAMA0G
// SIG // CSqGSIb3DQEBCwUAA4IBAQC7A8TJmY/vbWihRJK+FlTv
// SIG // R+kHW/TbpVlSyuTw8/V+YfbD7JmqYLs0xLqSIq5qvDst
// SIG // 24lUOfVI2bBLBgWE/jsMZQ9QBgmEiVuw2TwgGbdyXHN0
// SIG // rggJC8zzZMfqEtyho+caqFMzLIELfAEVWd3kIAWYVNzm
// SIG // rD1rpLs3HwnIivyR9mwZyBZfT0k4lrLUUgfERjIeQcAA
// SIG // IzoKS11WsIE1s6UuCKSw2Fs3XnybcnugQrOWDGk4CYUA
// SIG // B9b1A6ShHUNybwA88859RdDY0am0aaytgAtlGEyCn/Cf
// SIG // MmpAjaLtCTYQNw7lHu63HHiMIuJ9pVvUc/0E1rczi3oU
// SIG // h+pM7d88sDdZMIIGcDCCBFigAwIBAgIKYQxSTAAAAAAA
// SIG // AzANBgkqhkiG9w0BAQsFADCBiDELMAkGA1UEBhMCVVMx
// SIG // EzARBgNVBAgTCldhc2hpbmd0b24xEDAOBgNVBAcTB1Jl
// SIG // ZG1vbmQxHjAcBgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3Jh
// SIG // dGlvbjEyMDAGA1UEAxMpTWljcm9zb2Z0IFJvb3QgQ2Vy
// SIG // dGlmaWNhdGUgQXV0aG9yaXR5IDIwMTAwHhcNMTAwNzA2
// SIG // MjA0MDE3WhcNMjUwNzA2MjA1MDE3WjB+MQswCQYDVQQG
// SIG // EwJVUzETMBEGA1UECBMKV2FzaGluZ3RvbjEQMA4GA1UE
// SIG // BxMHUmVkbW9uZDEeMBwGA1UEChMVTWljcm9zb2Z0IENv
// SIG // cnBvcmF0aW9uMSgwJgYDVQQDEx9NaWNyb3NvZnQgQ29k
// SIG // ZSBTaWduaW5nIFBDQSAyMDEwMIIBIjANBgkqhkiG9w0B
// SIG // AQEFAAOCAQ8AMIIBCgKCAQEA6Q5kUHlntcTj/QkATJ6U
// SIG // rPdWaOpE2M/FWE+ppXZ8bUW60zmStKQe+fllguQX0o/9
// SIG // RJwI6GWTzixVhL99COMuK6hBKxi3oktuSUxrFQfe0dLC
// SIG // iR5xlM21f0u0rwjYzIjWaxeUOpPOJj/s5v40mFfVHV1J
// SIG // 9rIqLtWFu1k/+JC0K4N0yiuzO0bj8EZJwRdmVMkcvR3E
// SIG // VWJXcvhnuSUgNN5dpqWVXqsogM3Vsp7lA7Vj07IUyMHI
// SIG // iiYKWX8H7P8O7YASNUwSpr5SW/Wm2uCLC0h31oVH1RC5
// SIG // xuiq7otqLQVcYMa0KlucIxxfReMaFB5vN8sZM4BqiU2j
// SIG // amZjeJPVMM+VHwIDAQABo4IB4zCCAd8wEAYJKwYBBAGC
// SIG // NxUBBAMCAQAwHQYDVR0OBBYEFOb8X3u7IgBY5HJOtfQh
// SIG // dCMy5u+sMBkGCSsGAQQBgjcUAgQMHgoAUwB1AGIAQwBB
// SIG // MAsGA1UdDwQEAwIBhjAPBgNVHRMBAf8EBTADAQH/MB8G
// SIG // A1UdIwQYMBaAFNX2VsuP6KJcYmjRPZSQW9fOmhjEMFYG
// SIG // A1UdHwRPME0wS6BJoEeGRWh0dHA6Ly9jcmwubWljcm9z
// SIG // b2Z0LmNvbS9wa2kvY3JsL3Byb2R1Y3RzL01pY1Jvb0Nl
// SIG // ckF1dF8yMDEwLTA2LTIzLmNybDBaBggrBgEFBQcBAQRO
// SIG // MEwwSgYIKwYBBQUHMAKGPmh0dHA6Ly93d3cubWljcm9z
// SIG // b2Z0LmNvbS9wa2kvY2VydHMvTWljUm9vQ2VyQXV0XzIw
// SIG // MTAtMDYtMjMuY3J0MIGdBgNVHSAEgZUwgZIwgY8GCSsG
// SIG // AQQBgjcuAzCBgTA9BggrBgEFBQcCARYxaHR0cDovL3d3
// SIG // dy5taWNyb3NvZnQuY29tL1BLSS9kb2NzL0NQUy9kZWZh
// SIG // dWx0Lmh0bTBABggrBgEFBQcCAjA0HjIgHQBMAGUAZwBh
// SIG // AGwAXwBQAG8AbABpAGMAeQBfAFMAdABhAHQAZQBtAGUA
// SIG // bgB0AC4gHTANBgkqhkiG9w0BAQsFAAOCAgEAGnTvV08p
// SIG // e8QWhXi4UNMi/AmdrIKX+DT/KiyXlRLl5L/Pv5PI4zSp
// SIG // 24G43B4AvtI1b6/lf3mVd+UC1PHr2M1OHhthosJaIxrw
// SIG // jKhiUUVnCOM/PB6T+DCFF8g5QKbXDrMhKeWloWmMIpPM
// SIG // dJjnoUdD8lOswA8waX/+0iUgbW9h098H1dlyACxphnY9
// SIG // UdumOUjJN2FtB91TGcun1mHCv+KDqw/ga5uV1n0oUbCJ
// SIG // SlGkmmzItx9KGg5pqdfcwX7RSXCqtq27ckdjF/qm1qKm
// SIG // huyoEESbY7ayaYkGx0aGehg/6MUdIdV7+QIjLcVBy78d
// SIG // TMgW77Gcf/wiS0mKbhXjpn92W9FTeZGFndXS2z1zNfM8
// SIG // rlSyUkdqwKoTldKOEdqZZ14yjPs3hdHcdYWch8ZaV4XC
// SIG // v90Nj4ybLeu07s8n07VeafqkFgQBpyRnc89NT7beBVaX
// SIG // evfpUk30dwVPhcbYC/GO7UIJ0Q124yNWeCImNr7KsYxu
// SIG // qh3khdpHM2KPpMmRM19xHkCvmGXJIuhCISWKHC1g2TeJ
// SIG // QYkqFg/XYTyUaGBS79ZHmaCAQO4VgXc+nOBTGBpQHTiV
// SIG // mx5mMxMnORd4hzbOTsNfsvU9R1O24OXbC2E9KteSLM43
// SIG // Wj5AQjGkHxAIwlacvyRdUQKdannSF9PawZSOB3slcUSr
// SIG // Bmrm1MbfI5qWdcUxghWyMIIVrgIBATCBlTB+MQswCQYD
// SIG // VQQGEwJVUzETMBEGA1UECBMKV2FzaGluZ3RvbjEQMA4G
// SIG // A1UEBxMHUmVkbW9uZDEeMBwGA1UEChMVTWljcm9zb2Z0
// SIG // IENvcnBvcmF0aW9uMSgwJgYDVQQDEx9NaWNyb3NvZnQg
// SIG // Q29kZSBTaWduaW5nIFBDQSAyMDEwAhMzAAADg+rbu9lv
// SIG // Ibj6AAAAAAODMA0GCWCGSAFlAwQCAQUAoIIBBDAZBgkq
// SIG // hkiG9w0BCQMxDAYKKwYBBAGCNwIBBDAcBgorBgEEAYI3
// SIG // AgELMQ4wDAYKKwYBBAGCNwIBFTAvBgkqhkiG9w0BCQQx
// SIG // IgQgHL3mzKh078IB0pVsmZPdrISm0tecftSvFlbhh5HY
// SIG // Gf8wPAYKKwYBBAGCNwoDHDEuDCxmR3ZLRHdDYmRkWXlW
// SIG // eDZkc0dlNzhSVEhVWGZiUkl4QXlyM1h0ZEgwYnNrPTBa
// SIG // BgorBgEEAYI3AgEMMUwwSqAkgCIATQBpAGMAcgBvAHMA
// SIG // bwBmAHQAIABXAGkAbgBkAG8AdwBzoSKAIGh0dHA6Ly93
// SIG // d3cubWljcm9zb2Z0LmNvbS93aW5kb3dzMA0GCSqGSIb3
// SIG // DQEBAQUABIIBAKETkt2TBc65wxRfmjn5c2/rSBz4prxY
// SIG // DxiXYR2x+FxIPgBgwMtcePic/nus95dMu6YWS6isr5wW
// SIG // NvmZo3N9CViWeNWoMC0zRveuupri4O2SJu5GRf5jwa4G
// SIG // sHVVWBopsGf0oQJKs2DqoRJzLf3r1tSbiRHiQmvTFHHP
// SIG // zfdrGwyEQSAOIPqu1Ehj1QPnyiMTHdkjJSE0TtQLpb4y
// SIG // 2QpH6LbRYxIUw4F56DpMqO/eBHCeGyzlbZTnyplAmiXw
// SIG // f/PEdwUvNyEp+nNNpBjWQii5J4MUE3w+ez4tHYCFNZFA
// SIG // lCTjsxZNYclH9y7q0rxQCDw5DhGr0bBObzeD/vqPSTGE
// SIG // E1ehghLlMIIS4QYKKwYBBAGCNwMDATGCEtEwghLNBgkq
// SIG // hkiG9w0BBwKgghK+MIISugIBAzEPMA0GCWCGSAFlAwQC
// SIG // AQUAMIIBUQYLKoZIhvcNAQkQAQSgggFABIIBPDCCATgC
// SIG // AQEGCisGAQQBhFkKAwEwMTANBglghkgBZQMEAgEFAAQg
// SIG // RkyUKwNUYAsiboFARQvMsPwY3FV9L3M+CzLrgTiVlNYC
// SIG // BmCJ1h4DcRgTMjAyMTA1MDgwMDQzMzMuMDM0WjAEgAIB
// SIG // 9KCB0KSBzTCByjELMAkGA1UEBhMCVVMxEzARBgNVBAgT
// SIG // Cldhc2hpbmd0b24xEDAOBgNVBAcTB1JlZG1vbmQxHjAc
// SIG // BgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3JhdGlvbjElMCMG
// SIG // A1UECxMcTWljcm9zb2Z0IEFtZXJpY2EgT3BlcmF0aW9u
// SIG // czEmMCQGA1UECxMdVGhhbGVzIFRTUyBFU046N0JGMS1F
// SIG // M0VBLUI4MDgxJTAjBgNVBAMTHE1pY3Jvc29mdCBUaW1l
// SIG // LVN0YW1wIFNlcnZpY2Wggg48MIIE8TCCA9mgAwIBAgIT
// SIG // MwAAAVHDUOdZbKrGpwAAAAABUTANBgkqhkiG9w0BAQsF
// SIG // ADB8MQswCQYDVQQGEwJVUzETMBEGA1UECBMKV2FzaGlu
// SIG // Z3RvbjEQMA4GA1UEBxMHUmVkbW9uZDEeMBwGA1UEChMV
// SIG // TWljcm9zb2Z0IENvcnBvcmF0aW9uMSYwJAYDVQQDEx1N
// SIG // aWNyb3NvZnQgVGltZS1TdGFtcCBQQ0EgMjAxMDAeFw0y
// SIG // MDExMTIxODI2MDRaFw0yMjAyMTExODI2MDRaMIHKMQsw
// SIG // CQYDVQQGEwJVUzETMBEGA1UECBMKV2FzaGluZ3RvbjEQ
// SIG // MA4GA1UEBxMHUmVkbW9uZDEeMBwGA1UEChMVTWljcm9z
// SIG // b2Z0IENvcnBvcmF0aW9uMSUwIwYDVQQLExxNaWNyb3Nv
// SIG // ZnQgQW1lcmljYSBPcGVyYXRpb25zMSYwJAYDVQQLEx1U
// SIG // aGFsZXMgVFNTIEVTTjo3QkYxLUUzRUEtQjgwODElMCMG
// SIG // A1UEAxMcTWljcm9zb2Z0IFRpbWUtU3RhbXAgU2Vydmlj
// SIG // ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEB
// SIG // AJ/Sh++qhK477ziJI1mx6bTJGA45hviRJs4Lsq/1cY2Y
// SIG // Gf4oPDJOO46kiT+UcR/7A8qoWLu4z0jvOrImYfLuwwV/
// SIG // S/CPgAfvHzz7w+LqCyg9tgaaBZeAfBcOSu0rom728Rje
// SIG // 2nS9f81vrFl5Vb6Q4RDyCgyArxHTYxky4ZLX37Y3n4PZ
// SIG // bpgTFASdhuP4OGndHQ70TZiojGV13vy5eEIP6D0s1wlB
// SIG // GKEkqmuQ/uTEYplXuf2Ey49I1a/IheOVdIU+1R/DiTuG
// SIG // CJnJ2Yaug8NRvsOgAkRnjxZjlqlvLRGdd0jJjqria05M
// SIG // MsvM8jbVbbSQF+3YhS20dErzJWyWVitCh3cCAwEAAaOC
// SIG // ARswggEXMB0GA1UdDgQWBBTFd//jaFBikzRoOjjMhOnz
// SIG // dUTqbTAfBgNVHSMEGDAWgBTVYzpcijGQ80N7fEYbxTNo
// SIG // WoVtVTBWBgNVHR8ETzBNMEugSaBHhkVodHRwOi8vY3Js
// SIG // Lm1pY3Jvc29mdC5jb20vcGtpL2NybC9wcm9kdWN0cy9N
// SIG // aWNUaW1TdGFQQ0FfMjAxMC0wNy0wMS5jcmwwWgYIKwYB
// SIG // BQUHAQEETjBMMEoGCCsGAQUFBzAChj5odHRwOi8vd3d3
// SIG // Lm1pY3Jvc29mdC5jb20vcGtpL2NlcnRzL01pY1RpbVN0
// SIG // YVBDQV8yMDEwLTA3LTAxLmNydDAMBgNVHRMBAf8EAjAA
// SIG // MBMGA1UdJQQMMAoGCCsGAQUFBwMIMA0GCSqGSIb3DQEB
// SIG // CwUAA4IBAQAr/fXAFYOZ8dEqo7y30M5roDI+XCfTROtH
// SIG // bkh9S6cR2IpvS7N1H4mHe7dCb8hMP60UxCh2851eixS5
// SIG // V/vpRyTBis2Zx7U3tjiOmRxZzYhYbYMlrmAya5uykMpD
// SIG // YtRtS27lYnvTHoZqCvoQYmZ563H2UpwUqJK7ztkBFhwt
// SIG // cZ2ecDPNlBI6axWDpHIVPukXKAo45iBRn4EszY9TCG3+
// SIG // JXCeRaFdTIOhcBeOQoozlx1V685IrDGfabg6RY4xFekw
// SIG // GOiDYDJIS3r/wFaMNLBfDH0M7SSJRWHRRJGeTRfyMs6A
// SIG // tmG/YsOGwinQa3Q9wLOpr6BkjYwgupTnc+hHqyStzYRY
// SIG // MIIGcTCCBFmgAwIBAgIKYQmBKgAAAAAAAjANBgkqhkiG
// SIG // 9w0BAQsFADCBiDELMAkGA1UEBhMCVVMxEzARBgNVBAgT
// SIG // Cldhc2hpbmd0b24xEDAOBgNVBAcTB1JlZG1vbmQxHjAc
// SIG // BgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3JhdGlvbjEyMDAG
// SIG // A1UEAxMpTWljcm9zb2Z0IFJvb3QgQ2VydGlmaWNhdGUg
// SIG // QXV0aG9yaXR5IDIwMTAwHhcNMTAwNzAxMjEzNjU1WhcN
// SIG // MjUwNzAxMjE0NjU1WjB8MQswCQYDVQQGEwJVUzETMBEG
// SIG // A1UECBMKV2FzaGluZ3RvbjEQMA4GA1UEBxMHUmVkbW9u
// SIG // ZDEeMBwGA1UEChMVTWljcm9zb2Z0IENvcnBvcmF0aW9u
// SIG // MSYwJAYDVQQDEx1NaWNyb3NvZnQgVGltZS1TdGFtcCBQ
// SIG // Q0EgMjAxMDCCASIwDQYJKoZIhvcNAQEBBQADggEPADCC
// SIG // AQoCggEBAKkdDbx3EYo6IOz8E5f1+n9plGt0VBDVpQoA
// SIG // goX77XxoSyxfxcPlYcJ2tz5mK1vwFVMnBDEfQRsalR3O
// SIG // CROOfGEwWbEwRA/xYIiEVEMM1024OAizQt2TrNZzMFcm
// SIG // gqNFDdDq9UeBzb8kYDJYYEbyWEeGMoQedGFnkV+BVLHP
// SIG // k0ySwcSmXdFhE24oxhr5hoC732H8RsEnHSRnEnIaIYqv
// SIG // S2SJUGKxXf13Hz3wV3WsvYpCTUBR0Q+cBj5nf/VmwAOW
// SIG // RH7v0Ev9buWayrGo8noqCjHw2k4GkbaICDXoeByw6ZnN
// SIG // POcvRLqn9NxkvaQBwSAJk3jN/LzAyURdXhacAQVPIk0C
// SIG // AwEAAaOCAeYwggHiMBAGCSsGAQQBgjcVAQQDAgEAMB0G
// SIG // A1UdDgQWBBTVYzpcijGQ80N7fEYbxTNoWoVtVTAZBgkr
// SIG // BgEEAYI3FAIEDB4KAFMAdQBiAEMAQTALBgNVHQ8EBAMC
// SIG // AYYwDwYDVR0TAQH/BAUwAwEB/zAfBgNVHSMEGDAWgBTV
// SIG // 9lbLj+iiXGJo0T2UkFvXzpoYxDBWBgNVHR8ETzBNMEug
// SIG // SaBHhkVodHRwOi8vY3JsLm1pY3Jvc29mdC5jb20vcGtp
// SIG // L2NybC9wcm9kdWN0cy9NaWNSb29DZXJBdXRfMjAxMC0w
// SIG // Ni0yMy5jcmwwWgYIKwYBBQUHAQEETjBMMEoGCCsGAQUF
// SIG // BzAChj5odHRwOi8vd3d3Lm1pY3Jvc29mdC5jb20vcGtp
// SIG // L2NlcnRzL01pY1Jvb0NlckF1dF8yMDEwLTA2LTIzLmNy
// SIG // dDCBoAYDVR0gAQH/BIGVMIGSMIGPBgkrBgEEAYI3LgMw
// SIG // gYEwPQYIKwYBBQUHAgEWMWh0dHA6Ly93d3cubWljcm9z
// SIG // b2Z0LmNvbS9QS0kvZG9jcy9DUFMvZGVmYXVsdC5odG0w
// SIG // QAYIKwYBBQUHAgIwNB4yIB0ATABlAGcAYQBsAF8AUABv
// SIG // AGwAaQBjAHkAXwBTAHQAYQB0AGUAbQBlAG4AdAAuIB0w
// SIG // DQYJKoZIhvcNAQELBQADggIBAAfmiFEN4sbgmD+BcQM9
// SIG // naOhIW+z66bM9TG+zwXiqf76V20ZMLPCxWbJat/15/B4
// SIG // vceoniXj+bzta1RXCCtRgkQS+7lTjMz0YBKKdsxAQEGb
// SIG // 3FwX/1z5Xhc1mCRWS3TvQhDIr79/xn/yN31aPxzymXlK
// SIG // kVIArzgPF/UveYFl2am1a+THzvbKegBvSzBEJCI8z+0D
// SIG // pZaPWSm8tv0E4XCfMkon/VWvL/625Y4zu2JfmttXQOnx
// SIG // zplmkIz/amJ/3cVKC5Em4jnsGUpxY517IW3DnKOiPPp/
// SIG // fZZqkHimbdLhnPkd/DjYlPTGpQqWhqS9nhquBEKDuLWA
// SIG // myI4ILUl5WTs9/S/fmNZJQ96LjlXdqJxqgaKD4kWumGn
// SIG // Ecua2A5HmoDF0M2n0O99g/DhO3EJ3110mCIIYdqwUB5v
// SIG // vfHhAN/nMQekkzr3ZUd46PioSKv33nJ+YWtvd6mBy6cJ
// SIG // rDm77MbL2IK0cs0d9LiFAR6A+xuJKlQ5slvayA1VmXqH
// SIG // czsI5pgt6o3gMy4SKfXAL1QnIffIrE7aKLixqduWsqdC
// SIG // osnPGUFN4Ib5KpqjEWYw07t0MkvfY3v1mYovG8chr1m1
// SIG // rtxEPJdQcdeh0sVV42neV8HR3jDA/czmTfsNv11P6Z0e
// SIG // GTgvvM9YBS7vDaBQNdrvCScc1bN+NR4Iuto229Nfj950
// SIG // iEkSoYICzjCCAjcCAQEwgfihgdCkgc0wgcoxCzAJBgNV
// SIG // BAYTAlVTMRMwEQYDVQQIEwpXYXNoaW5ndG9uMRAwDgYD
// SIG // VQQHEwdSZWRtb25kMR4wHAYDVQQKExVNaWNyb3NvZnQg
// SIG // Q29ycG9yYXRpb24xJTAjBgNVBAsTHE1pY3Jvc29mdCBB
// SIG // bWVyaWNhIE9wZXJhdGlvbnMxJjAkBgNVBAsTHVRoYWxl
// SIG // cyBUU1MgRVNOOjdCRjEtRTNFQS1CODA4MSUwIwYDVQQD
// SIG // ExxNaWNyb3NvZnQgVGltZS1TdGFtcCBTZXJ2aWNloiMK
// SIG // AQEwBwYFKw4DAhoDFQCgoq9z8T+kQgslTCUgFaDFetcj
// SIG // XqCBgzCBgKR+MHwxCzAJBgNVBAYTAlVTMRMwEQYDVQQI
// SIG // EwpXYXNoaW5ndG9uMRAwDgYDVQQHEwdSZWRtb25kMR4w
// SIG // HAYDVQQKExVNaWNyb3NvZnQgQ29ycG9yYXRpb24xJjAk
// SIG // BgNVBAMTHU1pY3Jvc29mdCBUaW1lLVN0YW1wIFBDQSAy
// SIG // MDEwMA0GCSqGSIb3DQEBBQUAAgUA5EAxyzAiGA8yMDIx
// SIG // MDUwODA1MzgxOVoYDzIwMjEwNTA5MDUzODE5WjB3MD0G
// SIG // CisGAQQBhFkKBAExLzAtMAoCBQDkQDHLAgEAMAoCAQAC
// SIG // AhQeAgH/MAcCAQACAhFDMAoCBQDkQYNLAgEAMDYGCisG
// SIG // AQQBhFkKBAIxKDAmMAwGCisGAQQBhFkKAwKgCjAIAgEA
// SIG // AgMHoSChCjAIAgEAAgMBhqAwDQYJKoZIhvcNAQEFBQAD
// SIG // gYEAq+/Tgz/Wxugapv2/MLsbkMTvphoIN/vtIII3UE7Z
// SIG // 0QpjgbrAkx/TMqECPznoqfJR1GjuKa14YkvwkbZVzU7d
// SIG // zeDHMH2aad+qbprhAZeyBuA+5oaBEacbaSeFivcpTOfm
// SIG // W+u5LB/wy7CwKdGJjWyNJoURExmKlCDquJJewOXUTMIx
// SIG // ggMNMIIDCQIBATCBkzB8MQswCQYDVQQGEwJVUzETMBEG
// SIG // A1UECBMKV2FzaGluZ3RvbjEQMA4GA1UEBxMHUmVkbW9u
// SIG // ZDEeMBwGA1UEChMVTWljcm9zb2Z0IENvcnBvcmF0aW9u
// SIG // MSYwJAYDVQQDEx1NaWNyb3NvZnQgVGltZS1TdGFtcCBQ
// SIG // Q0EgMjAxMAITMwAAAVHDUOdZbKrGpwAAAAABUTANBglg
// SIG // hkgBZQMEAgEFAKCCAUowGgYJKoZIhvcNAQkDMQ0GCyqG
// SIG // SIb3DQEJEAEEMC8GCSqGSIb3DQEJBDEiBCCi+NwDgqlZ
// SIG // /hVOIsQBPcVFc4lmJeOdNlZT4tDIshj8qTCB+gYLKoZI
// SIG // hvcNAQkQAi8xgeowgecwgeQwgb0EIC7NXJmI+NbBWQcA
// SIG // phb7/UnD+bbrlIcbL/7dAfVxeuVBMIGYMIGApH4wfDEL
// SIG // MAkGA1UEBhMCVVMxEzARBgNVBAgTCldhc2hpbmd0b24x
// SIG // EDAOBgNVBAcTB1JlZG1vbmQxHjAcBgNVBAoTFU1pY3Jv
// SIG // c29mdCBDb3Jwb3JhdGlvbjEmMCQGA1UEAxMdTWljcm9z
// SIG // b2Z0IFRpbWUtU3RhbXAgUENBIDIwMTACEzMAAAFRw1Dn
// SIG // WWyqxqcAAAAAAVEwIgQghx3lArCzWZc3a9mF1ul5+o06
// SIG // FrjC6kX9mjFHKw8X9YEwDQYJKoZIhvcNAQELBQAEggEA
// SIG // J8NEO7YK8WxlFq93vTh32N0xfP79f6bElsnVggjbtGn0
// SIG // mRE1vFIpGpqDJPEEbPzdMowCCu3Q4fLgYvs5SURV9kjl
// SIG // 6oYzQjpgsKMP4GvNYYWpOIkjJ86+EFf6E2Dow+xvUeVb
// SIG // u+qn1/kijojW9l8QZ9xssYpvFVxBCx0ukdufK8RrDJOr
// SIG // gDrzZaN1BrlWOtMJISFNIH2cqGxwEZyW6TDpV1HLWtlZ
// SIG // /PlsyCLy3eI63JIIDOR29MtJiXV/2SXqe57IAlk9sSs9
// SIG // 4Jq6IjXk1yQVtxOZLwIIQxHlIqzYQSrF9m4djwWL3d+g
// SIG // 9731YEOBkzYFQ8KMGkyTHDd5n4J5vAgkrA==
// SIG // End signature block
