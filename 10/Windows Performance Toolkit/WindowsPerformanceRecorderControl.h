

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0626 */
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __windowsperformancerecordercontrol_h__
#define __windowsperformancerecordercontrol_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if _CONTROL_FLOW_GUARD_XFG
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IParsingErrorInfo_FWD_DEFINED__
#define __IParsingErrorInfo_FWD_DEFINED__
typedef interface IParsingErrorInfo IParsingErrorInfo;

#endif 	/* __IParsingErrorInfo_FWD_DEFINED__ */


#ifndef __IControlErrorInfo_FWD_DEFINED__
#define __IControlErrorInfo_FWD_DEFINED__
typedef interface IControlErrorInfo IControlErrorInfo;

#endif 	/* __IControlErrorInfo_FWD_DEFINED__ */


#ifndef __IEnumControlWarningInfo_FWD_DEFINED__
#define __IEnumControlWarningInfo_FWD_DEFINED__
typedef interface IEnumControlWarningInfo IEnumControlWarningInfo;

#endif 	/* __IEnumControlWarningInfo_FWD_DEFINED__ */


#ifndef __IProfile_FWD_DEFINED__
#define __IProfile_FWD_DEFINED__
typedef interface IProfile IProfile;

#endif 	/* __IProfile_FWD_DEFINED__ */


#ifndef __IProfile2_FWD_DEFINED__
#define __IProfile2_FWD_DEFINED__
typedef interface IProfile2 IProfile2;

#endif 	/* __IProfile2_FWD_DEFINED__ */


#ifndef __IEnumProfile_FWD_DEFINED__
#define __IEnumProfile_FWD_DEFINED__
typedef interface IEnumProfile IEnumProfile;

#endif 	/* __IEnumProfile_FWD_DEFINED__ */


#ifndef __ITraceMergeProperties_FWD_DEFINED__
#define __ITraceMergeProperties_FWD_DEFINED__
typedef interface ITraceMergeProperties ITraceMergeProperties;

#endif 	/* __ITraceMergeProperties_FWD_DEFINED__ */


#ifndef __IProfileCollection_FWD_DEFINED__
#define __IProfileCollection_FWD_DEFINED__
typedef interface IProfileCollection IProfileCollection;

#endif 	/* __IProfileCollection_FWD_DEFINED__ */


#ifndef __IProfileCollection2_FWD_DEFINED__
#define __IProfileCollection2_FWD_DEFINED__
typedef interface IProfileCollection2 IProfileCollection2;

#endif 	/* __IProfileCollection2_FWD_DEFINED__ */


#ifndef __IControlProgressHandler_FWD_DEFINED__
#define __IControlProgressHandler_FWD_DEFINED__
typedef interface IControlProgressHandler IControlProgressHandler;

#endif 	/* __IControlProgressHandler_FWD_DEFINED__ */


#ifndef __ITraceMergeTextHandler_FWD_DEFINED__
#define __ITraceMergeTextHandler_FWD_DEFINED__
typedef interface ITraceMergeTextHandler ITraceMergeTextHandler;

#endif 	/* __ITraceMergeTextHandler_FWD_DEFINED__ */


#ifndef __ITraceMergeTextHandler2_FWD_DEFINED__
#define __ITraceMergeTextHandler2_FWD_DEFINED__
typedef interface ITraceMergeTextHandler2 ITraceMergeTextHandler2;

#endif 	/* __ITraceMergeTextHandler2_FWD_DEFINED__ */


#ifndef __IControlManager_FWD_DEFINED__
#define __IControlManager_FWD_DEFINED__
typedef interface IControlManager IControlManager;

#endif 	/* __IControlManager_FWD_DEFINED__ */


#ifndef __IOnOffTransitionManager_FWD_DEFINED__
#define __IOnOffTransitionManager_FWD_DEFINED__
typedef interface IOnOffTransitionManager IOnOffTransitionManager;

#endif 	/* __IOnOffTransitionManager_FWD_DEFINED__ */


#ifndef __IEventingManager_FWD_DEFINED__
#define __IEventingManager_FWD_DEFINED__
typedef interface IEventingManager IEventingManager;

#endif 	/* __IEventingManager_FWD_DEFINED__ */


#ifndef __ISnapshotManager_FWD_DEFINED__
#define __ISnapshotManager_FWD_DEFINED__
typedef interface ISnapshotManager ISnapshotManager;

#endif 	/* __ISnapshotManager_FWD_DEFINED__ */


#ifndef __ISnapshotManager2_FWD_DEFINED__
#define __ISnapshotManager2_FWD_DEFINED__
typedef interface ISnapshotManager2 ISnapshotManager2;

#endif 	/* __ISnapshotManager2_FWD_DEFINED__ */


#ifndef __ISnapshotManager3_FWD_DEFINED__
#define __ISnapshotManager3_FWD_DEFINED__
typedef interface ISnapshotManager3 ISnapshotManager3;

#endif 	/* __ISnapshotManager3_FWD_DEFINED__ */


#ifndef __CProfile_FWD_DEFINED__
#define __CProfile_FWD_DEFINED__

#ifdef __cplusplus
typedef class CProfile CProfile;
#else
typedef struct CProfile CProfile;
#endif /* __cplusplus */

#endif 	/* __CProfile_FWD_DEFINED__ */


#ifndef __CProfileCollection_FWD_DEFINED__
#define __CProfileCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class CProfileCollection CProfileCollection;
#else
typedef struct CProfileCollection CProfileCollection;
#endif /* __cplusplus */

#endif 	/* __CProfileCollection_FWD_DEFINED__ */


#ifndef __CTraceMergeProperties_FWD_DEFINED__
#define __CTraceMergeProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class CTraceMergeProperties CTraceMergeProperties;
#else
typedef struct CTraceMergeProperties CTraceMergeProperties;
#endif /* __cplusplus */

#endif 	/* __CTraceMergeProperties_FWD_DEFINED__ */


#ifndef __CControlManager_FWD_DEFINED__
#define __CControlManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class CControlManager CControlManager;
#else
typedef struct CControlManager CControlManager;
#endif /* __cplusplus */

#endif 	/* __CControlManager_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_windowsperformancerecordercontrol_0000_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (c) 2012 Microsoft Corporation. All rights reserved.
//
//--------------------------------------------------------------------------


extern RPC_IF_HANDLE __MIDL_itf_windowsperformancerecordercontrol_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_windowsperformancerecordercontrol_0000_0000_v0_0_s_ifspec;

#ifndef __IParsingErrorInfo_INTERFACE_DEFINED__
#define __IParsingErrorInfo_INTERFACE_DEFINED__

/* interface IParsingErrorInfo */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_IParsingErrorInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B96AA961-1FC7-4FD2-9F6B-513FF7BBE38D")
    IParsingErrorInfo : public IErrorInfo
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetColumnNumber( 
            /* [retval][out] */ ULONG *pColumnNumber) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLineNumber( 
            /* [retval][out] */ ULONG *pLineNumber) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetElementType( 
            /* [retval][out] */ BSTR *pbstrElementType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetElementId( 
            /* [retval][out] */ BSTR *pbstrElementId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IParsingErrorInfoVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IParsingErrorInfo * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IParsingErrorInfo * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IParsingErrorInfo * This);
        
        DECLSPEC_XFGVIRT(IErrorInfo, GetGUID)
        HRESULT ( STDMETHODCALLTYPE *GetGUID )( 
            IParsingErrorInfo * This,
            /* [out] */ GUID *pGUID);
        
        DECLSPEC_XFGVIRT(IErrorInfo, GetSource)
        HRESULT ( STDMETHODCALLTYPE *GetSource )( 
            IParsingErrorInfo * This,
            /* [out] */ BSTR *pBstrSource);
        
        DECLSPEC_XFGVIRT(IErrorInfo, GetDescription)
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IParsingErrorInfo * This,
            /* [out] */ BSTR *pBstrDescription);
        
        DECLSPEC_XFGVIRT(IErrorInfo, GetHelpFile)
        HRESULT ( STDMETHODCALLTYPE *GetHelpFile )( 
            IParsingErrorInfo * This,
            /* [out] */ BSTR *pBstrHelpFile);
        
        DECLSPEC_XFGVIRT(IErrorInfo, GetHelpContext)
        HRESULT ( STDMETHODCALLTYPE *GetHelpContext )( 
            IParsingErrorInfo * This,
            /* [out] */ DWORD *pdwHelpContext);
        
        DECLSPEC_XFGVIRT(IParsingErrorInfo, GetColumnNumber)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetColumnNumber )( 
            IParsingErrorInfo * This,
            /* [retval][out] */ ULONG *pColumnNumber);
        
        DECLSPEC_XFGVIRT(IParsingErrorInfo, GetLineNumber)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLineNumber )( 
            IParsingErrorInfo * This,
            /* [retval][out] */ ULONG *pLineNumber);
        
        DECLSPEC_XFGVIRT(IParsingErrorInfo, GetElementType)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetElementType )( 
            IParsingErrorInfo * This,
            /* [retval][out] */ BSTR *pbstrElementType);
        
        DECLSPEC_XFGVIRT(IParsingErrorInfo, GetElementId)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetElementId )( 
            IParsingErrorInfo * This,
            /* [retval][out] */ BSTR *pbstrElementId);
        
        END_INTERFACE
    } IParsingErrorInfoVtbl;

    interface IParsingErrorInfo
    {
        CONST_VTBL struct IParsingErrorInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParsingErrorInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IParsingErrorInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IParsingErrorInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IParsingErrorInfo_GetGUID(This,pGUID)	\
    ( (This)->lpVtbl -> GetGUID(This,pGUID) ) 

#define IParsingErrorInfo_GetSource(This,pBstrSource)	\
    ( (This)->lpVtbl -> GetSource(This,pBstrSource) ) 

#define IParsingErrorInfo_GetDescription(This,pBstrDescription)	\
    ( (This)->lpVtbl -> GetDescription(This,pBstrDescription) ) 

#define IParsingErrorInfo_GetHelpFile(This,pBstrHelpFile)	\
    ( (This)->lpVtbl -> GetHelpFile(This,pBstrHelpFile) ) 

#define IParsingErrorInfo_GetHelpContext(This,pdwHelpContext)	\
    ( (This)->lpVtbl -> GetHelpContext(This,pdwHelpContext) ) 


#define IParsingErrorInfo_GetColumnNumber(This,pColumnNumber)	\
    ( (This)->lpVtbl -> GetColumnNumber(This,pColumnNumber) ) 

#define IParsingErrorInfo_GetLineNumber(This,pLineNumber)	\
    ( (This)->lpVtbl -> GetLineNumber(This,pLineNumber) ) 

#define IParsingErrorInfo_GetElementType(This,pbstrElementType)	\
    ( (This)->lpVtbl -> GetElementType(This,pbstrElementType) ) 

#define IParsingErrorInfo_GetElementId(This,pbstrElementId)	\
    ( (This)->lpVtbl -> GetElementId(This,pbstrElementId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IParsingErrorInfo_INTERFACE_DEFINED__ */


#ifndef __IControlErrorInfo_INTERFACE_DEFINED__
#define __IControlErrorInfo_INTERFACE_DEFINED__

/* interface IControlErrorInfo */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 

typedef /* [public][public] */ 
enum __MIDL_IControlErrorInfo_0001
    {
        ObjectType_Unknown	= 0,
        ObjectType_Profile	= ( ObjectType_Unknown + 1 ) ,
        ObjectType_Collector	= ( ObjectType_Profile + 1 ) ,
        ObjectType_Provider	= ( ObjectType_Collector + 1 ) 
    } 	CObjectType;


EXTERN_C const IID IID_IControlErrorInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC497FC5-E1DD-4F26-9A0A-85116DE069BD")
    IControlErrorInfo : public IErrorInfo
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetObjectType( 
            /* [retval][out] */ CObjectType *pObjectType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetHResult( 
            /* [retval][out] */ HRESULT *pHResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInnerErrorInfo( 
            /* [retval][out] */ IUnknown **ppVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IControlErrorInfoVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IControlErrorInfo * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IControlErrorInfo * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IControlErrorInfo * This);
        
        DECLSPEC_XFGVIRT(IErrorInfo, GetGUID)
        HRESULT ( STDMETHODCALLTYPE *GetGUID )( 
            IControlErrorInfo * This,
            /* [out] */ GUID *pGUID);
        
        DECLSPEC_XFGVIRT(IErrorInfo, GetSource)
        HRESULT ( STDMETHODCALLTYPE *GetSource )( 
            IControlErrorInfo * This,
            /* [out] */ BSTR *pBstrSource);
        
        DECLSPEC_XFGVIRT(IErrorInfo, GetDescription)
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IControlErrorInfo * This,
            /* [out] */ BSTR *pBstrDescription);
        
        DECLSPEC_XFGVIRT(IErrorInfo, GetHelpFile)
        HRESULT ( STDMETHODCALLTYPE *GetHelpFile )( 
            IControlErrorInfo * This,
            /* [out] */ BSTR *pBstrHelpFile);
        
        DECLSPEC_XFGVIRT(IErrorInfo, GetHelpContext)
        HRESULT ( STDMETHODCALLTYPE *GetHelpContext )( 
            IControlErrorInfo * This,
            /* [out] */ DWORD *pdwHelpContext);
        
        DECLSPEC_XFGVIRT(IControlErrorInfo, GetObjectType)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetObjectType )( 
            IControlErrorInfo * This,
            /* [retval][out] */ CObjectType *pObjectType);
        
        DECLSPEC_XFGVIRT(IControlErrorInfo, GetHResult)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetHResult )( 
            IControlErrorInfo * This,
            /* [retval][out] */ HRESULT *pHResult);
        
        DECLSPEC_XFGVIRT(IControlErrorInfo, GetInnerErrorInfo)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInnerErrorInfo )( 
            IControlErrorInfo * This,
            /* [retval][out] */ IUnknown **ppVal);
        
        END_INTERFACE
    } IControlErrorInfoVtbl;

    interface IControlErrorInfo
    {
        CONST_VTBL struct IControlErrorInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IControlErrorInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IControlErrorInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IControlErrorInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IControlErrorInfo_GetGUID(This,pGUID)	\
    ( (This)->lpVtbl -> GetGUID(This,pGUID) ) 

#define IControlErrorInfo_GetSource(This,pBstrSource)	\
    ( (This)->lpVtbl -> GetSource(This,pBstrSource) ) 

#define IControlErrorInfo_GetDescription(This,pBstrDescription)	\
    ( (This)->lpVtbl -> GetDescription(This,pBstrDescription) ) 

#define IControlErrorInfo_GetHelpFile(This,pBstrHelpFile)	\
    ( (This)->lpVtbl -> GetHelpFile(This,pBstrHelpFile) ) 

#define IControlErrorInfo_GetHelpContext(This,pdwHelpContext)	\
    ( (This)->lpVtbl -> GetHelpContext(This,pdwHelpContext) ) 


#define IControlErrorInfo_GetObjectType(This,pObjectType)	\
    ( (This)->lpVtbl -> GetObjectType(This,pObjectType) ) 

#define IControlErrorInfo_GetHResult(This,pHResult)	\
    ( (This)->lpVtbl -> GetHResult(This,pHResult) ) 

#define IControlErrorInfo_GetInnerErrorInfo(This,ppVal)	\
    ( (This)->lpVtbl -> GetInnerErrorInfo(This,ppVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IControlErrorInfo_INTERFACE_DEFINED__ */


#ifndef __IEnumControlWarningInfo_INTERFACE_DEFINED__
#define __IEnumControlWarningInfo_INTERFACE_DEFINED__

/* interface IEnumControlWarningInfo */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_IEnumControlWarningInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4D3894EE-53E0-4F0D-A928-49AC33B3CB80")
    IEnumControlWarningInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IControlErrorInfo **prgVar,
            /* [out] */ ULONG *pCeltFetched) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumControlWarningInfo **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumControlWarningInfoVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumControlWarningInfo * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumControlWarningInfo * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumControlWarningInfo * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEnumControlWarningInfo * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEnumControlWarningInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEnumControlWarningInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEnumControlWarningInfo * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IEnumControlWarningInfo, Next)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumControlWarningInfo * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IControlErrorInfo **prgVar,
            /* [out] */ ULONG *pCeltFetched);
        
        DECLSPEC_XFGVIRT(IEnumControlWarningInfo, Skip)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumControlWarningInfo * This,
            /* [in] */ ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumControlWarningInfo, Reset)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumControlWarningInfo * This);
        
        DECLSPEC_XFGVIRT(IEnumControlWarningInfo, Clone)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumControlWarningInfo * This,
            /* [out] */ IEnumControlWarningInfo **ppEnum);
        
        END_INTERFACE
    } IEnumControlWarningInfoVtbl;

    interface IEnumControlWarningInfo
    {
        CONST_VTBL struct IEnumControlWarningInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumControlWarningInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumControlWarningInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumControlWarningInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumControlWarningInfo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEnumControlWarningInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEnumControlWarningInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEnumControlWarningInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEnumControlWarningInfo_Next(This,celt,prgVar,pCeltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,prgVar,pCeltFetched) ) 

#define IEnumControlWarningInfo_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumControlWarningInfo_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumControlWarningInfo_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumControlWarningInfo_INTERFACE_DEFINED__ */


#ifndef __IProfile_INTERFACE_DEFINED__
#define __IProfile_INTERFACE_DEFINED__

/* interface IProfile */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 

typedef /* [public][public] */ 
enum __MIDL_IProfile_0001
    {
        LoggingMode_Unknown	= 0,
        LoggingMode_Memory	= ( LoggingMode_Unknown + 1 ) ,
        LoggingMode_File	= ( LoggingMode_Memory + 1 ) 
    } 	CLoggingMode;

typedef /* [public][public] */ 
enum __MIDL_IProfile_0002
    {
        DetailLevel_Unknown	= 0,
        DetailLevel_Light	= ( DetailLevel_Unknown + 1 ) ,
        DetailLevel_Verbose	= ( DetailLevel_Light + 1 ) 
    } 	CDetailLevel;


EXTERN_C const IID IID_IProfile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("71E0563A-BCBC-4784-933A-735A2EF4FB8A")
    IProfile : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsMutable( 
            /* [retval][out] */ VARIANT_BOOL *pfMutable) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IsMutable( 
            /* [in] */ VARIANT_BOOL fMutable) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ float *pVersion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Author( 
            /* [retval][out] */ BSTR *pbstrAuthor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Team( 
            /* [retval][out] */ BSTR *pbstrTeam) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Comments( 
            /* [retval][out] */ BSTR *pbstrComments) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Company( 
            /* [retval][out] */ BSTR *pbstrCompany) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Copyright( 
            /* [retval][out] */ BSTR *pbstrCopyright) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ BSTR *pbstrTag) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ BSTR *pbstrId) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *pbstrDescription) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LoggingMode( 
            /* [retval][out] */ CLoggingMode *pLoggingMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LoggingModeString( 
            /* [retval][out] */ BSTR *pbstrLoggingMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DetailLevel( 
            /* [retval][out] */ CDetailLevel *pDetailLevel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DetailLevelString( 
            /* [retval][out] */ BSTR *pbstrDetailLevel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsDefault( 
            /* [retval][out] */ VARIANT_BOOL *pfDefault) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProblemCategories( 
            /* [retval][out] */ BSTR *pbstrProblemCategories) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadFromFile( 
            /* [in] */ BSTR bstrProfileName,
            /* [in] */ BSTR bstrFileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadFromString( 
            /* [in] */ BSTR bstrProfile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsEqual( 
            /* [in] */ IProfile *pProfile) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IProfileVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProfile * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProfile * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProfile * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IProfile * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IProfile * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IProfile * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IProfile * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IProfile, get_IsMutable)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsMutable )( 
            IProfile * This,
            /* [retval][out] */ VARIANT_BOOL *pfMutable);
        
        DECLSPEC_XFGVIRT(IProfile, put_IsMutable)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsMutable )( 
            IProfile * This,
            /* [in] */ VARIANT_BOOL fMutable);
        
        DECLSPEC_XFGVIRT(IProfile, get_Version)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            IProfile * This,
            /* [retval][out] */ float *pVersion);
        
        DECLSPEC_XFGVIRT(IProfile, get_Author)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Author )( 
            IProfile * This,
            /* [retval][out] */ BSTR *pbstrAuthor);
        
        DECLSPEC_XFGVIRT(IProfile, get_Team)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Team )( 
            IProfile * This,
            /* [retval][out] */ BSTR *pbstrTeam);
        
        DECLSPEC_XFGVIRT(IProfile, get_Comments)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Comments )( 
            IProfile * This,
            /* [retval][out] */ BSTR *pbstrComments);
        
        DECLSPEC_XFGVIRT(IProfile, get_Company)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Company )( 
            IProfile * This,
            /* [retval][out] */ BSTR *pbstrCompany);
        
        DECLSPEC_XFGVIRT(IProfile, get_Copyright)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Copyright )( 
            IProfile * This,
            /* [retval][out] */ BSTR *pbstrCopyright);
        
        DECLSPEC_XFGVIRT(IProfile, get_Tag)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IProfile * This,
            /* [retval][out] */ BSTR *pbstrTag);
        
        DECLSPEC_XFGVIRT(IProfile, get_Id)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IProfile * This,
            /* [retval][out] */ BSTR *pbstrId);
        
        DECLSPEC_XFGVIRT(IProfile, get_Name)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IProfile * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        DECLSPEC_XFGVIRT(IProfile, get_Description)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IProfile * This,
            /* [retval][out] */ BSTR *pbstrDescription);
        
        DECLSPEC_XFGVIRT(IProfile, get_LoggingMode)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LoggingMode )( 
            IProfile * This,
            /* [retval][out] */ CLoggingMode *pLoggingMode);
        
        DECLSPEC_XFGVIRT(IProfile, get_LoggingModeString)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LoggingModeString )( 
            IProfile * This,
            /* [retval][out] */ BSTR *pbstrLoggingMode);
        
        DECLSPEC_XFGVIRT(IProfile, get_DetailLevel)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DetailLevel )( 
            IProfile * This,
            /* [retval][out] */ CDetailLevel *pDetailLevel);
        
        DECLSPEC_XFGVIRT(IProfile, get_DetailLevelString)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DetailLevelString )( 
            IProfile * This,
            /* [retval][out] */ BSTR *pbstrDetailLevel);
        
        DECLSPEC_XFGVIRT(IProfile, get_IsDefault)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsDefault )( 
            IProfile * This,
            /* [retval][out] */ VARIANT_BOOL *pfDefault);
        
        DECLSPEC_XFGVIRT(IProfile, get_ProblemCategories)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProblemCategories )( 
            IProfile * This,
            /* [retval][out] */ BSTR *pbstrProblemCategories);
        
        DECLSPEC_XFGVIRT(IProfile, LoadFromFile)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromFile )( 
            IProfile * This,
            /* [in] */ BSTR bstrProfileName,
            /* [in] */ BSTR bstrFileName);
        
        DECLSPEC_XFGVIRT(IProfile, LoadFromString)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromString )( 
            IProfile * This,
            /* [in] */ BSTR bstrProfile);
        
        DECLSPEC_XFGVIRT(IProfile, IsEqual)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqual )( 
            IProfile * This,
            /* [in] */ IProfile *pProfile);
        
        END_INTERFACE
    } IProfileVtbl;

    interface IProfile
    {
        CONST_VTBL struct IProfileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProfile_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProfile_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProfile_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProfile_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IProfile_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IProfile_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IProfile_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IProfile_get_IsMutable(This,pfMutable)	\
    ( (This)->lpVtbl -> get_IsMutable(This,pfMutable) ) 

#define IProfile_put_IsMutable(This,fMutable)	\
    ( (This)->lpVtbl -> put_IsMutable(This,fMutable) ) 

#define IProfile_get_Version(This,pVersion)	\
    ( (This)->lpVtbl -> get_Version(This,pVersion) ) 

#define IProfile_get_Author(This,pbstrAuthor)	\
    ( (This)->lpVtbl -> get_Author(This,pbstrAuthor) ) 

#define IProfile_get_Team(This,pbstrTeam)	\
    ( (This)->lpVtbl -> get_Team(This,pbstrTeam) ) 

#define IProfile_get_Comments(This,pbstrComments)	\
    ( (This)->lpVtbl -> get_Comments(This,pbstrComments) ) 

#define IProfile_get_Company(This,pbstrCompany)	\
    ( (This)->lpVtbl -> get_Company(This,pbstrCompany) ) 

#define IProfile_get_Copyright(This,pbstrCopyright)	\
    ( (This)->lpVtbl -> get_Copyright(This,pbstrCopyright) ) 

#define IProfile_get_Tag(This,pbstrTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pbstrTag) ) 

#define IProfile_get_Id(This,pbstrId)	\
    ( (This)->lpVtbl -> get_Id(This,pbstrId) ) 

#define IProfile_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IProfile_get_Description(This,pbstrDescription)	\
    ( (This)->lpVtbl -> get_Description(This,pbstrDescription) ) 

#define IProfile_get_LoggingMode(This,pLoggingMode)	\
    ( (This)->lpVtbl -> get_LoggingMode(This,pLoggingMode) ) 

#define IProfile_get_LoggingModeString(This,pbstrLoggingMode)	\
    ( (This)->lpVtbl -> get_LoggingModeString(This,pbstrLoggingMode) ) 

#define IProfile_get_DetailLevel(This,pDetailLevel)	\
    ( (This)->lpVtbl -> get_DetailLevel(This,pDetailLevel) ) 

#define IProfile_get_DetailLevelString(This,pbstrDetailLevel)	\
    ( (This)->lpVtbl -> get_DetailLevelString(This,pbstrDetailLevel) ) 

#define IProfile_get_IsDefault(This,pfDefault)	\
    ( (This)->lpVtbl -> get_IsDefault(This,pfDefault) ) 

#define IProfile_get_ProblemCategories(This,pbstrProblemCategories)	\
    ( (This)->lpVtbl -> get_ProblemCategories(This,pbstrProblemCategories) ) 

#define IProfile_LoadFromFile(This,bstrProfileName,bstrFileName)	\
    ( (This)->lpVtbl -> LoadFromFile(This,bstrProfileName,bstrFileName) ) 

#define IProfile_LoadFromString(This,bstrProfile)	\
    ( (This)->lpVtbl -> LoadFromString(This,bstrProfile) ) 

#define IProfile_IsEqual(This,pProfile)	\
    ( (This)->lpVtbl -> IsEqual(This,pProfile) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProfile_INTERFACE_DEFINED__ */


#ifndef __IProfile2_INTERFACE_DEFINED__
#define __IProfile2_INTERFACE_DEFINED__

/* interface IProfile2 */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_IProfile2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C732A38E-0699-4ACC-9070-A0A43F568E34")
    IProfile2 : public IProfile
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BufferSpace( 
            /* [retval][out] */ ULONG *pBufferSpace) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IProfile2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProfile2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProfile2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProfile2 * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IProfile2 * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IProfile2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IProfile2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IProfile2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IProfile, get_IsMutable)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsMutable )( 
            IProfile2 * This,
            /* [retval][out] */ VARIANT_BOOL *pfMutable);
        
        DECLSPEC_XFGVIRT(IProfile, put_IsMutable)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsMutable )( 
            IProfile2 * This,
            /* [in] */ VARIANT_BOOL fMutable);
        
        DECLSPEC_XFGVIRT(IProfile, get_Version)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            IProfile2 * This,
            /* [retval][out] */ float *pVersion);
        
        DECLSPEC_XFGVIRT(IProfile, get_Author)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Author )( 
            IProfile2 * This,
            /* [retval][out] */ BSTR *pbstrAuthor);
        
        DECLSPEC_XFGVIRT(IProfile, get_Team)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Team )( 
            IProfile2 * This,
            /* [retval][out] */ BSTR *pbstrTeam);
        
        DECLSPEC_XFGVIRT(IProfile, get_Comments)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Comments )( 
            IProfile2 * This,
            /* [retval][out] */ BSTR *pbstrComments);
        
        DECLSPEC_XFGVIRT(IProfile, get_Company)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Company )( 
            IProfile2 * This,
            /* [retval][out] */ BSTR *pbstrCompany);
        
        DECLSPEC_XFGVIRT(IProfile, get_Copyright)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Copyright )( 
            IProfile2 * This,
            /* [retval][out] */ BSTR *pbstrCopyright);
        
        DECLSPEC_XFGVIRT(IProfile, get_Tag)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IProfile2 * This,
            /* [retval][out] */ BSTR *pbstrTag);
        
        DECLSPEC_XFGVIRT(IProfile, get_Id)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IProfile2 * This,
            /* [retval][out] */ BSTR *pbstrId);
        
        DECLSPEC_XFGVIRT(IProfile, get_Name)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IProfile2 * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        DECLSPEC_XFGVIRT(IProfile, get_Description)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IProfile2 * This,
            /* [retval][out] */ BSTR *pbstrDescription);
        
        DECLSPEC_XFGVIRT(IProfile, get_LoggingMode)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LoggingMode )( 
            IProfile2 * This,
            /* [retval][out] */ CLoggingMode *pLoggingMode);
        
        DECLSPEC_XFGVIRT(IProfile, get_LoggingModeString)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LoggingModeString )( 
            IProfile2 * This,
            /* [retval][out] */ BSTR *pbstrLoggingMode);
        
        DECLSPEC_XFGVIRT(IProfile, get_DetailLevel)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DetailLevel )( 
            IProfile2 * This,
            /* [retval][out] */ CDetailLevel *pDetailLevel);
        
        DECLSPEC_XFGVIRT(IProfile, get_DetailLevelString)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DetailLevelString )( 
            IProfile2 * This,
            /* [retval][out] */ BSTR *pbstrDetailLevel);
        
        DECLSPEC_XFGVIRT(IProfile, get_IsDefault)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsDefault )( 
            IProfile2 * This,
            /* [retval][out] */ VARIANT_BOOL *pfDefault);
        
        DECLSPEC_XFGVIRT(IProfile, get_ProblemCategories)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProblemCategories )( 
            IProfile2 * This,
            /* [retval][out] */ BSTR *pbstrProblemCategories);
        
        DECLSPEC_XFGVIRT(IProfile, LoadFromFile)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromFile )( 
            IProfile2 * This,
            /* [in] */ BSTR bstrProfileName,
            /* [in] */ BSTR bstrFileName);
        
        DECLSPEC_XFGVIRT(IProfile, LoadFromString)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromString )( 
            IProfile2 * This,
            /* [in] */ BSTR bstrProfile);
        
        DECLSPEC_XFGVIRT(IProfile, IsEqual)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqual )( 
            IProfile2 * This,
            /* [in] */ IProfile *pProfile);
        
        DECLSPEC_XFGVIRT(IProfile2, get_BufferSpace)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BufferSpace )( 
            IProfile2 * This,
            /* [retval][out] */ ULONG *pBufferSpace);
        
        END_INTERFACE
    } IProfile2Vtbl;

    interface IProfile2
    {
        CONST_VTBL struct IProfile2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProfile2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProfile2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProfile2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProfile2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IProfile2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IProfile2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IProfile2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IProfile2_get_IsMutable(This,pfMutable)	\
    ( (This)->lpVtbl -> get_IsMutable(This,pfMutable) ) 

#define IProfile2_put_IsMutable(This,fMutable)	\
    ( (This)->lpVtbl -> put_IsMutable(This,fMutable) ) 

#define IProfile2_get_Version(This,pVersion)	\
    ( (This)->lpVtbl -> get_Version(This,pVersion) ) 

#define IProfile2_get_Author(This,pbstrAuthor)	\
    ( (This)->lpVtbl -> get_Author(This,pbstrAuthor) ) 

#define IProfile2_get_Team(This,pbstrTeam)	\
    ( (This)->lpVtbl -> get_Team(This,pbstrTeam) ) 

#define IProfile2_get_Comments(This,pbstrComments)	\
    ( (This)->lpVtbl -> get_Comments(This,pbstrComments) ) 

#define IProfile2_get_Company(This,pbstrCompany)	\
    ( (This)->lpVtbl -> get_Company(This,pbstrCompany) ) 

#define IProfile2_get_Copyright(This,pbstrCopyright)	\
    ( (This)->lpVtbl -> get_Copyright(This,pbstrCopyright) ) 

#define IProfile2_get_Tag(This,pbstrTag)	\
    ( (This)->lpVtbl -> get_Tag(This,pbstrTag) ) 

#define IProfile2_get_Id(This,pbstrId)	\
    ( (This)->lpVtbl -> get_Id(This,pbstrId) ) 

#define IProfile2_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IProfile2_get_Description(This,pbstrDescription)	\
    ( (This)->lpVtbl -> get_Description(This,pbstrDescription) ) 

#define IProfile2_get_LoggingMode(This,pLoggingMode)	\
    ( (This)->lpVtbl -> get_LoggingMode(This,pLoggingMode) ) 

#define IProfile2_get_LoggingModeString(This,pbstrLoggingMode)	\
    ( (This)->lpVtbl -> get_LoggingModeString(This,pbstrLoggingMode) ) 

#define IProfile2_get_DetailLevel(This,pDetailLevel)	\
    ( (This)->lpVtbl -> get_DetailLevel(This,pDetailLevel) ) 

#define IProfile2_get_DetailLevelString(This,pbstrDetailLevel)	\
    ( (This)->lpVtbl -> get_DetailLevelString(This,pbstrDetailLevel) ) 

#define IProfile2_get_IsDefault(This,pfDefault)	\
    ( (This)->lpVtbl -> get_IsDefault(This,pfDefault) ) 

#define IProfile2_get_ProblemCategories(This,pbstrProblemCategories)	\
    ( (This)->lpVtbl -> get_ProblemCategories(This,pbstrProblemCategories) ) 

#define IProfile2_LoadFromFile(This,bstrProfileName,bstrFileName)	\
    ( (This)->lpVtbl -> LoadFromFile(This,bstrProfileName,bstrFileName) ) 

#define IProfile2_LoadFromString(This,bstrProfile)	\
    ( (This)->lpVtbl -> LoadFromString(This,bstrProfile) ) 

#define IProfile2_IsEqual(This,pProfile)	\
    ( (This)->lpVtbl -> IsEqual(This,pProfile) ) 


#define IProfile2_get_BufferSpace(This,pBufferSpace)	\
    ( (This)->lpVtbl -> get_BufferSpace(This,pBufferSpace) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProfile2_INTERFACE_DEFINED__ */


#ifndef __IEnumProfile_INTERFACE_DEFINED__
#define __IEnumProfile_INTERFACE_DEFINED__

/* interface IEnumProfile */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_IEnumProfile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DBF29874-763E-492F-8D36-9AE8DBD89A1C")
    IEnumProfile : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IProfile **prgVar,
            /* [out] */ ULONG *pCeltFetched) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumProfile **ppEnum) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEnumProfileVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumProfile * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumProfile * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumProfile * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEnumProfile * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEnumProfile * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEnumProfile * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEnumProfile * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IEnumProfile, Next)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumProfile * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IProfile **prgVar,
            /* [out] */ ULONG *pCeltFetched);
        
        DECLSPEC_XFGVIRT(IEnumProfile, Skip)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumProfile * This,
            /* [in] */ ULONG celt);
        
        DECLSPEC_XFGVIRT(IEnumProfile, Reset)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumProfile * This);
        
        DECLSPEC_XFGVIRT(IEnumProfile, Clone)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumProfile * This,
            /* [out] */ IEnumProfile **ppEnum);
        
        END_INTERFACE
    } IEnumProfileVtbl;

    interface IEnumProfile
    {
        CONST_VTBL struct IEnumProfileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumProfile_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumProfile_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumProfile_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumProfile_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEnumProfile_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEnumProfile_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEnumProfile_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEnumProfile_Next(This,celt,prgVar,pCeltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,prgVar,pCeltFetched) ) 

#define IEnumProfile_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumProfile_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumProfile_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumProfile_INTERFACE_DEFINED__ */


#ifndef __ITraceMergeProperties_INTERFACE_DEFINED__
#define __ITraceMergeProperties_INTERFACE_DEFINED__

/* interface ITraceMergeProperties */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_ITraceMergeProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("629E2BBB-9629-45D8-8314-5D72324AE33F")
    ITraceMergeProperties : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadFromFile( 
            /* [in] */ BSTR bstrTraceMergeName,
            /* [in] */ BSTR bstrFileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadFromString( 
            /* [in] */ BSTR bstrTraceMerge) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsEqual( 
            /* [in] */ ITraceMergeProperties *pTraceMergeProperties) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITraceMergePropertiesVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITraceMergeProperties * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITraceMergeProperties * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITraceMergeProperties * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITraceMergeProperties * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITraceMergeProperties * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITraceMergeProperties * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITraceMergeProperties * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ITraceMergeProperties, LoadFromFile)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromFile )( 
            ITraceMergeProperties * This,
            /* [in] */ BSTR bstrTraceMergeName,
            /* [in] */ BSTR bstrFileName);
        
        DECLSPEC_XFGVIRT(ITraceMergeProperties, LoadFromString)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadFromString )( 
            ITraceMergeProperties * This,
            /* [in] */ BSTR bstrTraceMerge);
        
        DECLSPEC_XFGVIRT(ITraceMergeProperties, IsEqual)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqual )( 
            ITraceMergeProperties * This,
            /* [in] */ ITraceMergeProperties *pTraceMergeProperties);
        
        END_INTERFACE
    } ITraceMergePropertiesVtbl;

    interface ITraceMergeProperties
    {
        CONST_VTBL struct ITraceMergePropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITraceMergeProperties_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITraceMergeProperties_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITraceMergeProperties_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITraceMergeProperties_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITraceMergeProperties_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITraceMergeProperties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITraceMergeProperties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITraceMergeProperties_LoadFromFile(This,bstrTraceMergeName,bstrFileName)	\
    ( (This)->lpVtbl -> LoadFromFile(This,bstrTraceMergeName,bstrFileName) ) 

#define ITraceMergeProperties_LoadFromString(This,bstrTraceMerge)	\
    ( (This)->lpVtbl -> LoadFromString(This,bstrTraceMerge) ) 

#define ITraceMergeProperties_IsEqual(This,pTraceMergeProperties)	\
    ( (This)->lpVtbl -> IsEqual(This,pTraceMergeProperties) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITraceMergeProperties_INTERFACE_DEFINED__ */


#ifndef __IProfileCollection_INTERFACE_DEFINED__
#define __IProfileCollection_INTERFACE_DEFINED__

/* interface IProfileCollection */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_IProfileCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BB5ED25C-A7A8-4CEF-BFFD-2D9C64CB457A")
    IProfileCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IProfile *pProfile,
            /* [in] */ VARIANT_BOOL fMerge) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ IProfile *pProfile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsEqual( 
            /* [in] */ IProfileCollection *pProfileCollection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadIntoXML( 
            /* [out] */ BSTR *pbstrResults) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IProfileCollectionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProfileCollection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProfileCollection * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProfileCollection * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IProfileCollection * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IProfileCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IProfileCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IProfileCollection * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IProfileCollection, Add)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IProfileCollection * This,
            /* [in] */ IProfile *pProfile,
            /* [in] */ VARIANT_BOOL fMerge);
        
        DECLSPEC_XFGVIRT(IProfileCollection, Remove)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IProfileCollection * This,
            /* [in] */ IProfile *pProfile);
        
        DECLSPEC_XFGVIRT(IProfileCollection, Clear)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IProfileCollection * This);
        
        DECLSPEC_XFGVIRT(IProfileCollection, IsEqual)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqual )( 
            IProfileCollection * This,
            /* [in] */ IProfileCollection *pProfileCollection);
        
        DECLSPEC_XFGVIRT(IProfileCollection, LoadIntoXML)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadIntoXML )( 
            IProfileCollection * This,
            /* [out] */ BSTR *pbstrResults);
        
        END_INTERFACE
    } IProfileCollectionVtbl;

    interface IProfileCollection
    {
        CONST_VTBL struct IProfileCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProfileCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProfileCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProfileCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProfileCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IProfileCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IProfileCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IProfileCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IProfileCollection_Add(This,pProfile,fMerge)	\
    ( (This)->lpVtbl -> Add(This,pProfile,fMerge) ) 

#define IProfileCollection_Remove(This,pProfile)	\
    ( (This)->lpVtbl -> Remove(This,pProfile) ) 

#define IProfileCollection_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IProfileCollection_IsEqual(This,pProfileCollection)	\
    ( (This)->lpVtbl -> IsEqual(This,pProfileCollection) ) 

#define IProfileCollection_LoadIntoXML(This,pbstrResults)	\
    ( (This)->lpVtbl -> LoadIntoXML(This,pbstrResults) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProfileCollection_INTERFACE_DEFINED__ */


#ifndef __IProfileCollection2_INTERFACE_DEFINED__
#define __IProfileCollection2_INTERFACE_DEFINED__

/* interface IProfileCollection2 */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_IProfileCollection2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("47C60A6D-30A2-46C9-85AC-79EED0D584E4")
    IProfileCollection2 : public IProfileCollection
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTraceMergeProperties( 
            /* [out] */ ITraceMergeProperties **ppTraceMergeProperties) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IProfileCollection2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProfileCollection2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProfileCollection2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProfileCollection2 * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IProfileCollection2 * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IProfileCollection2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IProfileCollection2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IProfileCollection2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IProfileCollection, Add)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IProfileCollection2 * This,
            /* [in] */ IProfile *pProfile,
            /* [in] */ VARIANT_BOOL fMerge);
        
        DECLSPEC_XFGVIRT(IProfileCollection, Remove)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IProfileCollection2 * This,
            /* [in] */ IProfile *pProfile);
        
        DECLSPEC_XFGVIRT(IProfileCollection, Clear)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IProfileCollection2 * This);
        
        DECLSPEC_XFGVIRT(IProfileCollection, IsEqual)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqual )( 
            IProfileCollection2 * This,
            /* [in] */ IProfileCollection *pProfileCollection);
        
        DECLSPEC_XFGVIRT(IProfileCollection, LoadIntoXML)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadIntoXML )( 
            IProfileCollection2 * This,
            /* [out] */ BSTR *pbstrResults);
        
        DECLSPEC_XFGVIRT(IProfileCollection2, GetTraceMergeProperties)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTraceMergeProperties )( 
            IProfileCollection2 * This,
            /* [out] */ ITraceMergeProperties **ppTraceMergeProperties);
        
        END_INTERFACE
    } IProfileCollection2Vtbl;

    interface IProfileCollection2
    {
        CONST_VTBL struct IProfileCollection2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProfileCollection2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProfileCollection2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProfileCollection2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProfileCollection2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IProfileCollection2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IProfileCollection2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IProfileCollection2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IProfileCollection2_Add(This,pProfile,fMerge)	\
    ( (This)->lpVtbl -> Add(This,pProfile,fMerge) ) 

#define IProfileCollection2_Remove(This,pProfile)	\
    ( (This)->lpVtbl -> Remove(This,pProfile) ) 

#define IProfileCollection2_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IProfileCollection2_IsEqual(This,pProfileCollection)	\
    ( (This)->lpVtbl -> IsEqual(This,pProfileCollection) ) 

#define IProfileCollection2_LoadIntoXML(This,pbstrResults)	\
    ( (This)->lpVtbl -> LoadIntoXML(This,pbstrResults) ) 


#define IProfileCollection2_GetTraceMergeProperties(This,ppTraceMergeProperties)	\
    ( (This)->lpVtbl -> GetTraceMergeProperties(This,ppTraceMergeProperties) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProfileCollection2_INTERFACE_DEFINED__ */


#ifndef __IControlProgressHandler_INTERFACE_DEFINED__
#define __IControlProgressHandler_INTERFACE_DEFINED__

/* interface IControlProgressHandler */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_IControlProgressHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3BFF3423-C44D-480E-9A91-60941D5D6E59")
    IControlProgressHandler : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnBegin( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnUpdate( 
            /* [in] */ ULONG CurrentValuePercent) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnEnd( 
            /* [in] */ HRESULT hrResult,
            /* [in] */ ULONG EventsLost) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IControlProgressHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IControlProgressHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IControlProgressHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IControlProgressHandler * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IControlProgressHandler * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IControlProgressHandler * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IControlProgressHandler * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IControlProgressHandler * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IControlProgressHandler, OnBegin)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnBegin )( 
            IControlProgressHandler * This);
        
        DECLSPEC_XFGVIRT(IControlProgressHandler, OnUpdate)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnUpdate )( 
            IControlProgressHandler * This,
            /* [in] */ ULONG CurrentValuePercent);
        
        DECLSPEC_XFGVIRT(IControlProgressHandler, OnEnd)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnEnd )( 
            IControlProgressHandler * This,
            /* [in] */ HRESULT hrResult,
            /* [in] */ ULONG EventsLost);
        
        END_INTERFACE
    } IControlProgressHandlerVtbl;

    interface IControlProgressHandler
    {
        CONST_VTBL struct IControlProgressHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IControlProgressHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IControlProgressHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IControlProgressHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IControlProgressHandler_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IControlProgressHandler_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IControlProgressHandler_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IControlProgressHandler_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IControlProgressHandler_OnBegin(This)	\
    ( (This)->lpVtbl -> OnBegin(This) ) 

#define IControlProgressHandler_OnUpdate(This,CurrentValuePercent)	\
    ( (This)->lpVtbl -> OnUpdate(This,CurrentValuePercent) ) 

#define IControlProgressHandler_OnEnd(This,hrResult,EventsLost)	\
    ( (This)->lpVtbl -> OnEnd(This,hrResult,EventsLost) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IControlProgressHandler_INTERFACE_DEFINED__ */


#ifndef __ITraceMergeTextHandler_INTERFACE_DEFINED__
#define __ITraceMergeTextHandler_INTERFACE_DEFINED__

/* interface ITraceMergeTextHandler */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_ITraceMergeTextHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9F8FB077-7E67-4454-8A9E-31D43A0CDD4E")
    ITraceMergeTextHandler : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ ULONG *cText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetText( 
            /* [in] */ ULONG iText,
            /* [out] */ BSTR *pbstrText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WaitForText( 
            /* [in] */ ULONG Milliseconds) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFileName( 
            /* [out] */ BSTR *pbstrFileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNGenPdbsPath( 
            /* [out] */ VARIANT_BOOL *pfEnable,
            /* [out] */ BSTR *pbstrNGenPdbsCachePath,
            /* [out] */ BSTR *pbstrNGenPdbsTargetPath) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITraceMergeTextHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITraceMergeTextHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITraceMergeTextHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITraceMergeTextHandler * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITraceMergeTextHandler * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITraceMergeTextHandler * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITraceMergeTextHandler * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITraceMergeTextHandler * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ITraceMergeTextHandler, get_Count)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ITraceMergeTextHandler * This,
            /* [retval][out] */ ULONG *cText);
        
        DECLSPEC_XFGVIRT(ITraceMergeTextHandler, GetText)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ITraceMergeTextHandler * This,
            /* [in] */ ULONG iText,
            /* [out] */ BSTR *pbstrText);
        
        DECLSPEC_XFGVIRT(ITraceMergeTextHandler, WaitForText)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WaitForText )( 
            ITraceMergeTextHandler * This,
            /* [in] */ ULONG Milliseconds);
        
        DECLSPEC_XFGVIRT(ITraceMergeTextHandler, GetFileName)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFileName )( 
            ITraceMergeTextHandler * This,
            /* [out] */ BSTR *pbstrFileName);
        
        DECLSPEC_XFGVIRT(ITraceMergeTextHandler, GetNGenPdbsPath)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNGenPdbsPath )( 
            ITraceMergeTextHandler * This,
            /* [out] */ VARIANT_BOOL *pfEnable,
            /* [out] */ BSTR *pbstrNGenPdbsCachePath,
            /* [out] */ BSTR *pbstrNGenPdbsTargetPath);
        
        END_INTERFACE
    } ITraceMergeTextHandlerVtbl;

    interface ITraceMergeTextHandler
    {
        CONST_VTBL struct ITraceMergeTextHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITraceMergeTextHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITraceMergeTextHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITraceMergeTextHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITraceMergeTextHandler_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITraceMergeTextHandler_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITraceMergeTextHandler_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITraceMergeTextHandler_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITraceMergeTextHandler_get_Count(This,cText)	\
    ( (This)->lpVtbl -> get_Count(This,cText) ) 

#define ITraceMergeTextHandler_GetText(This,iText,pbstrText)	\
    ( (This)->lpVtbl -> GetText(This,iText,pbstrText) ) 

#define ITraceMergeTextHandler_WaitForText(This,Milliseconds)	\
    ( (This)->lpVtbl -> WaitForText(This,Milliseconds) ) 

#define ITraceMergeTextHandler_GetFileName(This,pbstrFileName)	\
    ( (This)->lpVtbl -> GetFileName(This,pbstrFileName) ) 

#define ITraceMergeTextHandler_GetNGenPdbsPath(This,pfEnable,pbstrNGenPdbsCachePath,pbstrNGenPdbsTargetPath)	\
    ( (This)->lpVtbl -> GetNGenPdbsPath(This,pfEnable,pbstrNGenPdbsCachePath,pbstrNGenPdbsTargetPath) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITraceMergeTextHandler_INTERFACE_DEFINED__ */


#ifndef __ITraceMergeTextHandler2_INTERFACE_DEFINED__
#define __ITraceMergeTextHandler2_INTERFACE_DEFINED__

/* interface ITraceMergeTextHandler2 */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_ITraceMergeTextHandler2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F99DBE52-715F-4410-927C-C58D9EB7A252")
    ITraceMergeTextHandler2 : public ITraceMergeTextHandler
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEmbeddedPdbsPath( 
            /* [out] */ VARIANT_BOOL *pfEnable,
            /* [out] */ BSTR *pbstrEmbeddedPdbsTargetPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadIntoXML( 
            /* [out] */ BSTR *pbstrResults) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITraceMergeTextHandler2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITraceMergeTextHandler2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITraceMergeTextHandler2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITraceMergeTextHandler2 * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITraceMergeTextHandler2 * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITraceMergeTextHandler2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITraceMergeTextHandler2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITraceMergeTextHandler2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ITraceMergeTextHandler, get_Count)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ITraceMergeTextHandler2 * This,
            /* [retval][out] */ ULONG *cText);
        
        DECLSPEC_XFGVIRT(ITraceMergeTextHandler, GetText)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ITraceMergeTextHandler2 * This,
            /* [in] */ ULONG iText,
            /* [out] */ BSTR *pbstrText);
        
        DECLSPEC_XFGVIRT(ITraceMergeTextHandler, WaitForText)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WaitForText )( 
            ITraceMergeTextHandler2 * This,
            /* [in] */ ULONG Milliseconds);
        
        DECLSPEC_XFGVIRT(ITraceMergeTextHandler, GetFileName)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFileName )( 
            ITraceMergeTextHandler2 * This,
            /* [out] */ BSTR *pbstrFileName);
        
        DECLSPEC_XFGVIRT(ITraceMergeTextHandler, GetNGenPdbsPath)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNGenPdbsPath )( 
            ITraceMergeTextHandler2 * This,
            /* [out] */ VARIANT_BOOL *pfEnable,
            /* [out] */ BSTR *pbstrNGenPdbsCachePath,
            /* [out] */ BSTR *pbstrNGenPdbsTargetPath);
        
        DECLSPEC_XFGVIRT(ITraceMergeTextHandler2, GetEmbeddedPdbsPath)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetEmbeddedPdbsPath )( 
            ITraceMergeTextHandler2 * This,
            /* [out] */ VARIANT_BOOL *pfEnable,
            /* [out] */ BSTR *pbstrEmbeddedPdbsTargetPath);
        
        DECLSPEC_XFGVIRT(ITraceMergeTextHandler2, LoadIntoXML)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadIntoXML )( 
            ITraceMergeTextHandler2 * This,
            /* [out] */ BSTR *pbstrResults);
        
        END_INTERFACE
    } ITraceMergeTextHandler2Vtbl;

    interface ITraceMergeTextHandler2
    {
        CONST_VTBL struct ITraceMergeTextHandler2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITraceMergeTextHandler2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITraceMergeTextHandler2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITraceMergeTextHandler2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITraceMergeTextHandler2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITraceMergeTextHandler2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITraceMergeTextHandler2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITraceMergeTextHandler2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITraceMergeTextHandler2_get_Count(This,cText)	\
    ( (This)->lpVtbl -> get_Count(This,cText) ) 

#define ITraceMergeTextHandler2_GetText(This,iText,pbstrText)	\
    ( (This)->lpVtbl -> GetText(This,iText,pbstrText) ) 

#define ITraceMergeTextHandler2_WaitForText(This,Milliseconds)	\
    ( (This)->lpVtbl -> WaitForText(This,Milliseconds) ) 

#define ITraceMergeTextHandler2_GetFileName(This,pbstrFileName)	\
    ( (This)->lpVtbl -> GetFileName(This,pbstrFileName) ) 

#define ITraceMergeTextHandler2_GetNGenPdbsPath(This,pfEnable,pbstrNGenPdbsCachePath,pbstrNGenPdbsTargetPath)	\
    ( (This)->lpVtbl -> GetNGenPdbsPath(This,pfEnable,pbstrNGenPdbsCachePath,pbstrNGenPdbsTargetPath) ) 


#define ITraceMergeTextHandler2_GetEmbeddedPdbsPath(This,pfEnable,pbstrEmbeddedPdbsTargetPath)	\
    ( (This)->lpVtbl -> GetEmbeddedPdbsPath(This,pfEnable,pbstrEmbeddedPdbsTargetPath) ) 

#define ITraceMergeTextHandler2_LoadIntoXML(This,pbstrResults)	\
    ( (This)->lpVtbl -> LoadIntoXML(This,pbstrResults) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITraceMergeTextHandler2_INTERFACE_DEFINED__ */


#ifndef __IControlManager_INTERFACE_DEFINED__
#define __IControlManager_INTERFACE_DEFINED__

/* interface IControlManager */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_IControlManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C66BC1C2-D913-4BF0-9E08-014523E4A205")
    IControlManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ControlProgressHandler( 
            /* [retval][out] */ IControlProgressHandler **ppControlProgressHandler) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ControlProgressHandler( 
            /* [in] */ IControlProgressHandler *pControlProgressHandler) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Start( 
            /* [in] */ IProfileCollection *pProfileCollection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Update( 
            /* [in] */ IProfileCollection *pProfileCollection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Cancel( 
            /* [in] */ IProfileCollection *pProfileCollection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ BSTR bstrFileName,
            /* [in] */ IProfileCollection *pProfileCollection,
            /* [in] */ ITraceMergeProperties *pTraceMergeProperties) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( 
            /* [in] */ BSTR bstrFileName,
            /* [in] */ IProfileCollection *pProfileCollection,
            /* [in] */ ITraceMergeProperties *pTraceMergeProperties) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QueryXML( 
            /* [out] */ BSTR *pbstrResults,
            /* [in] */ VARIANT_BOOL fValidateRuntimeState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Query( 
            /* [out] */ IProfileCollection **ppProfileCollection,
            /* [in] */ VARIANT_BOOL fValidateRuntimeState) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TraceMergeTextHandler( 
            /* [retval][out] */ ITraceMergeTextHandler **ppTraceMergeTextHandler) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TraceMergeTextHandler( 
            /* [in] */ ITraceMergeTextHandler *pTraceMergeTextHandler) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TemporaryTraceDirectory( 
            /* [retval][out] */ BSTR *pbstrTemporaryTraceDirectory) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TemporaryTraceDirectory( 
            /* [in] */ BSTR bstrTemporaryTraceDirectory) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProviderNameFromGuid( 
            /* [out] */ BSTR *bstrProviderIdStr,
            /* [in] */ REFGUID ProviderId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProviderGuidFromName( 
            /* [out] */ GUID *ProviderId,
            /* [in] */ BSTR bstrProViderName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CaptureStateOnDemand( 
            /* [in] */ IProfileCollection *pProfileCollection) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IControlManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IControlManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IControlManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IControlManager * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IControlManager * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IControlManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IControlManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IControlManager * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IControlManager, get_ControlProgressHandler)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ControlProgressHandler )( 
            IControlManager * This,
            /* [retval][out] */ IControlProgressHandler **ppControlProgressHandler);
        
        DECLSPEC_XFGVIRT(IControlManager, put_ControlProgressHandler)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ControlProgressHandler )( 
            IControlManager * This,
            /* [in] */ IControlProgressHandler *pControlProgressHandler);
        
        DECLSPEC_XFGVIRT(IControlManager, Start)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Start )( 
            IControlManager * This,
            /* [in] */ IProfileCollection *pProfileCollection);
        
        DECLSPEC_XFGVIRT(IControlManager, Update)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IControlManager * This,
            /* [in] */ IProfileCollection *pProfileCollection);
        
        DECLSPEC_XFGVIRT(IControlManager, Cancel)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IControlManager * This,
            /* [in] */ IProfileCollection *pProfileCollection);
        
        DECLSPEC_XFGVIRT(IControlManager, Save)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IControlManager * This,
            /* [in] */ BSTR bstrFileName,
            /* [in] */ IProfileCollection *pProfileCollection,
            /* [in] */ ITraceMergeProperties *pTraceMergeProperties);
        
        DECLSPEC_XFGVIRT(IControlManager, Stop)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IControlManager * This,
            /* [in] */ BSTR bstrFileName,
            /* [in] */ IProfileCollection *pProfileCollection,
            /* [in] */ ITraceMergeProperties *pTraceMergeProperties);
        
        DECLSPEC_XFGVIRT(IControlManager, QueryXML)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QueryXML )( 
            IControlManager * This,
            /* [out] */ BSTR *pbstrResults,
            /* [in] */ VARIANT_BOOL fValidateRuntimeState);
        
        DECLSPEC_XFGVIRT(IControlManager, Query)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Query )( 
            IControlManager * This,
            /* [out] */ IProfileCollection **ppProfileCollection,
            /* [in] */ VARIANT_BOOL fValidateRuntimeState);
        
        DECLSPEC_XFGVIRT(IControlManager, get_TraceMergeTextHandler)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TraceMergeTextHandler )( 
            IControlManager * This,
            /* [retval][out] */ ITraceMergeTextHandler **ppTraceMergeTextHandler);
        
        DECLSPEC_XFGVIRT(IControlManager, put_TraceMergeTextHandler)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TraceMergeTextHandler )( 
            IControlManager * This,
            /* [in] */ ITraceMergeTextHandler *pTraceMergeTextHandler);
        
        DECLSPEC_XFGVIRT(IControlManager, get_TemporaryTraceDirectory)
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TemporaryTraceDirectory )( 
            IControlManager * This,
            /* [retval][out] */ BSTR *pbstrTemporaryTraceDirectory);
        
        DECLSPEC_XFGVIRT(IControlManager, put_TemporaryTraceDirectory)
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TemporaryTraceDirectory )( 
            IControlManager * This,
            /* [in] */ BSTR bstrTemporaryTraceDirectory);
        
        DECLSPEC_XFGVIRT(IControlManager, GetProviderNameFromGuid)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProviderNameFromGuid )( 
            IControlManager * This,
            /* [out] */ BSTR *bstrProviderIdStr,
            /* [in] */ REFGUID ProviderId);
        
        DECLSPEC_XFGVIRT(IControlManager, GetProviderGuidFromName)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProviderGuidFromName )( 
            IControlManager * This,
            /* [out] */ GUID *ProviderId,
            /* [in] */ BSTR bstrProViderName);
        
        DECLSPEC_XFGVIRT(IControlManager, CaptureStateOnDemand)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CaptureStateOnDemand )( 
            IControlManager * This,
            /* [in] */ IProfileCollection *pProfileCollection);
        
        END_INTERFACE
    } IControlManagerVtbl;

    interface IControlManager
    {
        CONST_VTBL struct IControlManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IControlManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IControlManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IControlManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IControlManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IControlManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IControlManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IControlManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IControlManager_get_ControlProgressHandler(This,ppControlProgressHandler)	\
    ( (This)->lpVtbl -> get_ControlProgressHandler(This,ppControlProgressHandler) ) 

#define IControlManager_put_ControlProgressHandler(This,pControlProgressHandler)	\
    ( (This)->lpVtbl -> put_ControlProgressHandler(This,pControlProgressHandler) ) 

#define IControlManager_Start(This,pProfileCollection)	\
    ( (This)->lpVtbl -> Start(This,pProfileCollection) ) 

#define IControlManager_Update(This,pProfileCollection)	\
    ( (This)->lpVtbl -> Update(This,pProfileCollection) ) 

#define IControlManager_Cancel(This,pProfileCollection)	\
    ( (This)->lpVtbl -> Cancel(This,pProfileCollection) ) 

#define IControlManager_Save(This,bstrFileName,pProfileCollection,pTraceMergeProperties)	\
    ( (This)->lpVtbl -> Save(This,bstrFileName,pProfileCollection,pTraceMergeProperties) ) 

#define IControlManager_Stop(This,bstrFileName,pProfileCollection,pTraceMergeProperties)	\
    ( (This)->lpVtbl -> Stop(This,bstrFileName,pProfileCollection,pTraceMergeProperties) ) 

#define IControlManager_QueryXML(This,pbstrResults,fValidateRuntimeState)	\
    ( (This)->lpVtbl -> QueryXML(This,pbstrResults,fValidateRuntimeState) ) 

#define IControlManager_Query(This,ppProfileCollection,fValidateRuntimeState)	\
    ( (This)->lpVtbl -> Query(This,ppProfileCollection,fValidateRuntimeState) ) 

#define IControlManager_get_TraceMergeTextHandler(This,ppTraceMergeTextHandler)	\
    ( (This)->lpVtbl -> get_TraceMergeTextHandler(This,ppTraceMergeTextHandler) ) 

#define IControlManager_put_TraceMergeTextHandler(This,pTraceMergeTextHandler)	\
    ( (This)->lpVtbl -> put_TraceMergeTextHandler(This,pTraceMergeTextHandler) ) 

#define IControlManager_get_TemporaryTraceDirectory(This,pbstrTemporaryTraceDirectory)	\
    ( (This)->lpVtbl -> get_TemporaryTraceDirectory(This,pbstrTemporaryTraceDirectory) ) 

#define IControlManager_put_TemporaryTraceDirectory(This,bstrTemporaryTraceDirectory)	\
    ( (This)->lpVtbl -> put_TemporaryTraceDirectory(This,bstrTemporaryTraceDirectory) ) 

#define IControlManager_GetProviderNameFromGuid(This,bstrProviderIdStr,ProviderId)	\
    ( (This)->lpVtbl -> GetProviderNameFromGuid(This,bstrProviderIdStr,ProviderId) ) 

#define IControlManager_GetProviderGuidFromName(This,ProviderId,bstrProViderName)	\
    ( (This)->lpVtbl -> GetProviderGuidFromName(This,ProviderId,bstrProViderName) ) 

#define IControlManager_CaptureStateOnDemand(This,pProfileCollection)	\
    ( (This)->lpVtbl -> CaptureStateOnDemand(This,pProfileCollection) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IControlManager_INTERFACE_DEFINED__ */


#ifndef __IOnOffTransitionManager_INTERFACE_DEFINED__
#define __IOnOffTransitionManager_INTERFACE_DEFINED__

/* interface IOnOffTransitionManager */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_IOnOffTransitionManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0B626B7D-C028-411A-84B2-1FE7EE6EF9A0")
    IOnOffTransitionManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableBootRecording( 
            /* [in] */ IProfileCollection *pProfileCollection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisableBootRecording( 
            /* [in] */ IProfileCollection *pProfileCollection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartShutdownRecording( 
            /* [in] */ IProfileCollection *pProfileCollection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateShutdownRecording( 
            /* [in] */ IProfileCollection *pProfileCollection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MergeShutdownRecording( 
            /* [in] */ BSTR bstrFileName,
            /* [in] */ IProfileCollection *pProfileCollection,
            /* [in] */ ITraceMergeProperties *pTraceMergeProperties) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOnOffTransitionManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOnOffTransitionManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOnOffTransitionManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOnOffTransitionManager * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOnOffTransitionManager * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOnOffTransitionManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOnOffTransitionManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOnOffTransitionManager * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IOnOffTransitionManager, EnableBootRecording)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableBootRecording )( 
            IOnOffTransitionManager * This,
            /* [in] */ IProfileCollection *pProfileCollection);
        
        DECLSPEC_XFGVIRT(IOnOffTransitionManager, DisableBootRecording)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisableBootRecording )( 
            IOnOffTransitionManager * This,
            /* [in] */ IProfileCollection *pProfileCollection);
        
        DECLSPEC_XFGVIRT(IOnOffTransitionManager, StartShutdownRecording)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartShutdownRecording )( 
            IOnOffTransitionManager * This,
            /* [in] */ IProfileCollection *pProfileCollection);
        
        DECLSPEC_XFGVIRT(IOnOffTransitionManager, UpdateShutdownRecording)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateShutdownRecording )( 
            IOnOffTransitionManager * This,
            /* [in] */ IProfileCollection *pProfileCollection);
        
        DECLSPEC_XFGVIRT(IOnOffTransitionManager, MergeShutdownRecording)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MergeShutdownRecording )( 
            IOnOffTransitionManager * This,
            /* [in] */ BSTR bstrFileName,
            /* [in] */ IProfileCollection *pProfileCollection,
            /* [in] */ ITraceMergeProperties *pTraceMergeProperties);
        
        END_INTERFACE
    } IOnOffTransitionManagerVtbl;

    interface IOnOffTransitionManager
    {
        CONST_VTBL struct IOnOffTransitionManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOnOffTransitionManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOnOffTransitionManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOnOffTransitionManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOnOffTransitionManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOnOffTransitionManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOnOffTransitionManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOnOffTransitionManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOnOffTransitionManager_EnableBootRecording(This,pProfileCollection)	\
    ( (This)->lpVtbl -> EnableBootRecording(This,pProfileCollection) ) 

#define IOnOffTransitionManager_DisableBootRecording(This,pProfileCollection)	\
    ( (This)->lpVtbl -> DisableBootRecording(This,pProfileCollection) ) 

#define IOnOffTransitionManager_StartShutdownRecording(This,pProfileCollection)	\
    ( (This)->lpVtbl -> StartShutdownRecording(This,pProfileCollection) ) 

#define IOnOffTransitionManager_UpdateShutdownRecording(This,pProfileCollection)	\
    ( (This)->lpVtbl -> UpdateShutdownRecording(This,pProfileCollection) ) 

#define IOnOffTransitionManager_MergeShutdownRecording(This,bstrFileName,pProfileCollection,pTraceMergeProperties)	\
    ( (This)->lpVtbl -> MergeShutdownRecording(This,bstrFileName,pProfileCollection,pTraceMergeProperties) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOnOffTransitionManager_INTERFACE_DEFINED__ */


#ifndef __IEventingManager_INTERFACE_DEFINED__
#define __IEventingManager_INTERFACE_DEFINED__

/* interface IEventingManager */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_IEventingManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("545725DB-6AB0-4C9F-AECD-9373A380082C")
    IEventingManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FireEvent( 
            /* [in] */ BSTR bstrMarkerName,
            /* [in] */ VARIANT_BOOL fFlush) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEventingManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEventingManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEventingManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEventingManager * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEventingManager * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEventingManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEventingManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEventingManager * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IEventingManager, FireEvent)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FireEvent )( 
            IEventingManager * This,
            /* [in] */ BSTR bstrMarkerName,
            /* [in] */ VARIANT_BOOL fFlush);
        
        END_INTERFACE
    } IEventingManagerVtbl;

    interface IEventingManager
    {
        CONST_VTBL struct IEventingManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEventingManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEventingManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEventingManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEventingManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEventingManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEventingManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEventingManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEventingManager_FireEvent(This,bstrMarkerName,fFlush)	\
    ( (This)->lpVtbl -> FireEvent(This,bstrMarkerName,fFlush) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEventingManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_windowsperformancerecordercontrol_0000_0015 */
/* [local] */ 

#ifndef _TRACEHANDLE_DEFINED
#define _TRACEHANDLE_DEFINED
typedef ULONG64 TRACEHANDLE;

typedef ULONG64 *PTRACEHANDLE;

#endif


extern RPC_IF_HANDLE __MIDL_itf_windowsperformancerecordercontrol_0000_0015_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_windowsperformancerecordercontrol_0000_0015_v0_0_s_ifspec;

#ifndef __ISnapshotManager_INTERFACE_DEFINED__
#define __ISnapshotManager_INTERFACE_DEFINED__

/* interface ISnapshotManager */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 

typedef /* [public][public][public][public][public][public] */ 
enum __MIDL_ISnapshotManager_0001
    {
        SnapshotType_Undefined	= 0,
        SnapshotType_Heap	= ( SnapshotType_Undefined + 1 ) 
    } 	SnapshotType;


EXTERN_C const IID IID_ISnapshotManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4A9F4BAC-C4C3-4D50-8721-910827DA1691")
    ISnapshotManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnablePeriodicSnapshot( 
            /* [in] */ SnapshotType snapshotType,
            /* [in] */ ULONG interval,
            /* [in] */ ULONG *pids,
            /* [in] */ ULONG cPids) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisablePeriodicSnapshot( 
            /* [in] */ SnapshotType snapshotType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SnapshotOnDemand( 
            /* [in] */ SnapshotType snapshotType,
            /* [in] */ ULONG *pids,
            /* [in] */ ULONG cPids) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VerifySnapshotSupported( 
            /* [in] */ TRACEHANDLE traceHandle,
            /* [out][in] */ ULONG *frequencyInSeconds,
            /* [out][in] */ ULONG *cProviders) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISnapshotManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISnapshotManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISnapshotManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISnapshotManager * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISnapshotManager * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISnapshotManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISnapshotManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISnapshotManager * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ISnapshotManager, EnablePeriodicSnapshot)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnablePeriodicSnapshot )( 
            ISnapshotManager * This,
            /* [in] */ SnapshotType snapshotType,
            /* [in] */ ULONG interval,
            /* [in] */ ULONG *pids,
            /* [in] */ ULONG cPids);
        
        DECLSPEC_XFGVIRT(ISnapshotManager, DisablePeriodicSnapshot)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisablePeriodicSnapshot )( 
            ISnapshotManager * This,
            /* [in] */ SnapshotType snapshotType);
        
        DECLSPEC_XFGVIRT(ISnapshotManager, SnapshotOnDemand)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SnapshotOnDemand )( 
            ISnapshotManager * This,
            /* [in] */ SnapshotType snapshotType,
            /* [in] */ ULONG *pids,
            /* [in] */ ULONG cPids);
        
        DECLSPEC_XFGVIRT(ISnapshotManager, VerifySnapshotSupported)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VerifySnapshotSupported )( 
            ISnapshotManager * This,
            /* [in] */ TRACEHANDLE traceHandle,
            /* [out][in] */ ULONG *frequencyInSeconds,
            /* [out][in] */ ULONG *cProviders);
        
        END_INTERFACE
    } ISnapshotManagerVtbl;

    interface ISnapshotManager
    {
        CONST_VTBL struct ISnapshotManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISnapshotManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISnapshotManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISnapshotManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISnapshotManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISnapshotManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISnapshotManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISnapshotManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISnapshotManager_EnablePeriodicSnapshot(This,snapshotType,interval,pids,cPids)	\
    ( (This)->lpVtbl -> EnablePeriodicSnapshot(This,snapshotType,interval,pids,cPids) ) 

#define ISnapshotManager_DisablePeriodicSnapshot(This,snapshotType)	\
    ( (This)->lpVtbl -> DisablePeriodicSnapshot(This,snapshotType) ) 

#define ISnapshotManager_SnapshotOnDemand(This,snapshotType,pids,cPids)	\
    ( (This)->lpVtbl -> SnapshotOnDemand(This,snapshotType,pids,cPids) ) 

#define ISnapshotManager_VerifySnapshotSupported(This,traceHandle,frequencyInSeconds,cProviders)	\
    ( (This)->lpVtbl -> VerifySnapshotSupported(This,traceHandle,frequencyInSeconds,cProviders) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISnapshotManager_INTERFACE_DEFINED__ */


#ifndef __ISnapshotManager2_INTERFACE_DEFINED__
#define __ISnapshotManager2_INTERFACE_DEFINED__

/* interface ISnapshotManager2 */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_ISnapshotManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("21AB4191-347E-44B8-846D-D12F427B2740")
    ISnapshotManager2 : public ISnapshotManager
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConfigSnapshotByPID( 
            /* [in] */ ULONG *pids,
            /* [in] */ ULONG cPids,
            /* [in] */ VARIANT_BOOL fEnable) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConfigSnapshotByProcess( 
            /* [in] */ BSTR bstrProcName,
            /* [in] */ VARIANT_BOOL fEnable) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISnapshotManager2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISnapshotManager2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISnapshotManager2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISnapshotManager2 * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISnapshotManager2 * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISnapshotManager2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISnapshotManager2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISnapshotManager2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ISnapshotManager, EnablePeriodicSnapshot)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnablePeriodicSnapshot )( 
            ISnapshotManager2 * This,
            /* [in] */ SnapshotType snapshotType,
            /* [in] */ ULONG interval,
            /* [in] */ ULONG *pids,
            /* [in] */ ULONG cPids);
        
        DECLSPEC_XFGVIRT(ISnapshotManager, DisablePeriodicSnapshot)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisablePeriodicSnapshot )( 
            ISnapshotManager2 * This,
            /* [in] */ SnapshotType snapshotType);
        
        DECLSPEC_XFGVIRT(ISnapshotManager, SnapshotOnDemand)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SnapshotOnDemand )( 
            ISnapshotManager2 * This,
            /* [in] */ SnapshotType snapshotType,
            /* [in] */ ULONG *pids,
            /* [in] */ ULONG cPids);
        
        DECLSPEC_XFGVIRT(ISnapshotManager, VerifySnapshotSupported)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VerifySnapshotSupported )( 
            ISnapshotManager2 * This,
            /* [in] */ TRACEHANDLE traceHandle,
            /* [out][in] */ ULONG *frequencyInSeconds,
            /* [out][in] */ ULONG *cProviders);
        
        DECLSPEC_XFGVIRT(ISnapshotManager2, ConfigSnapshotByPID)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConfigSnapshotByPID )( 
            ISnapshotManager2 * This,
            /* [in] */ ULONG *pids,
            /* [in] */ ULONG cPids,
            /* [in] */ VARIANT_BOOL fEnable);
        
        DECLSPEC_XFGVIRT(ISnapshotManager2, ConfigSnapshotByProcess)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConfigSnapshotByProcess )( 
            ISnapshotManager2 * This,
            /* [in] */ BSTR bstrProcName,
            /* [in] */ VARIANT_BOOL fEnable);
        
        END_INTERFACE
    } ISnapshotManager2Vtbl;

    interface ISnapshotManager2
    {
        CONST_VTBL struct ISnapshotManager2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISnapshotManager2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISnapshotManager2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISnapshotManager2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISnapshotManager2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISnapshotManager2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISnapshotManager2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISnapshotManager2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISnapshotManager2_EnablePeriodicSnapshot(This,snapshotType,interval,pids,cPids)	\
    ( (This)->lpVtbl -> EnablePeriodicSnapshot(This,snapshotType,interval,pids,cPids) ) 

#define ISnapshotManager2_DisablePeriodicSnapshot(This,snapshotType)	\
    ( (This)->lpVtbl -> DisablePeriodicSnapshot(This,snapshotType) ) 

#define ISnapshotManager2_SnapshotOnDemand(This,snapshotType,pids,cPids)	\
    ( (This)->lpVtbl -> SnapshotOnDemand(This,snapshotType,pids,cPids) ) 

#define ISnapshotManager2_VerifySnapshotSupported(This,traceHandle,frequencyInSeconds,cProviders)	\
    ( (This)->lpVtbl -> VerifySnapshotSupported(This,traceHandle,frequencyInSeconds,cProviders) ) 


#define ISnapshotManager2_ConfigSnapshotByPID(This,pids,cPids,fEnable)	\
    ( (This)->lpVtbl -> ConfigSnapshotByPID(This,pids,cPids,fEnable) ) 

#define ISnapshotManager2_ConfigSnapshotByProcess(This,bstrProcName,fEnable)	\
    ( (This)->lpVtbl -> ConfigSnapshotByProcess(This,bstrProcName,fEnable) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISnapshotManager2_INTERFACE_DEFINED__ */


#ifndef __ISnapshotManager3_INTERFACE_DEFINED__
#define __ISnapshotManager3_INTERFACE_DEFINED__

/* interface ISnapshotManager3 */
/* [local][unique][helpstring][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID_ISnapshotManager3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FEC35006-1F64-4805-869F-B75E40049B85")
    ISnapshotManager3 : public ISnapshotManager2
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConfigSnapshotByPIDEx( 
            /* [in] */ SnapshotType snapshotType,
            /* [in] */ ULONG *pids,
            /* [out][in] */ HRESULT *pResults,
            /* [in] */ ULONG cPids,
            /* [in] */ VARIANT_BOOL fEnable) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConfigSnapshotByProcessEx( 
            /* [in] */ SnapshotType snapshotType,
            /* [in] */ BSTR bstrProcName,
            /* [in] */ VARIANT_BOOL fEnable) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISnapshotManager3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISnapshotManager3 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISnapshotManager3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISnapshotManager3 * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISnapshotManager3 * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISnapshotManager3 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISnapshotManager3 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISnapshotManager3 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ISnapshotManager, EnablePeriodicSnapshot)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnablePeriodicSnapshot )( 
            ISnapshotManager3 * This,
            /* [in] */ SnapshotType snapshotType,
            /* [in] */ ULONG interval,
            /* [in] */ ULONG *pids,
            /* [in] */ ULONG cPids);
        
        DECLSPEC_XFGVIRT(ISnapshotManager, DisablePeriodicSnapshot)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisablePeriodicSnapshot )( 
            ISnapshotManager3 * This,
            /* [in] */ SnapshotType snapshotType);
        
        DECLSPEC_XFGVIRT(ISnapshotManager, SnapshotOnDemand)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SnapshotOnDemand )( 
            ISnapshotManager3 * This,
            /* [in] */ SnapshotType snapshotType,
            /* [in] */ ULONG *pids,
            /* [in] */ ULONG cPids);
        
        DECLSPEC_XFGVIRT(ISnapshotManager, VerifySnapshotSupported)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VerifySnapshotSupported )( 
            ISnapshotManager3 * This,
            /* [in] */ TRACEHANDLE traceHandle,
            /* [out][in] */ ULONG *frequencyInSeconds,
            /* [out][in] */ ULONG *cProviders);
        
        DECLSPEC_XFGVIRT(ISnapshotManager2, ConfigSnapshotByPID)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConfigSnapshotByPID )( 
            ISnapshotManager3 * This,
            /* [in] */ ULONG *pids,
            /* [in] */ ULONG cPids,
            /* [in] */ VARIANT_BOOL fEnable);
        
        DECLSPEC_XFGVIRT(ISnapshotManager2, ConfigSnapshotByProcess)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConfigSnapshotByProcess )( 
            ISnapshotManager3 * This,
            /* [in] */ BSTR bstrProcName,
            /* [in] */ VARIANT_BOOL fEnable);
        
        DECLSPEC_XFGVIRT(ISnapshotManager3, ConfigSnapshotByPIDEx)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConfigSnapshotByPIDEx )( 
            ISnapshotManager3 * This,
            /* [in] */ SnapshotType snapshotType,
            /* [in] */ ULONG *pids,
            /* [out][in] */ HRESULT *pResults,
            /* [in] */ ULONG cPids,
            /* [in] */ VARIANT_BOOL fEnable);
        
        DECLSPEC_XFGVIRT(ISnapshotManager3, ConfigSnapshotByProcessEx)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConfigSnapshotByProcessEx )( 
            ISnapshotManager3 * This,
            /* [in] */ SnapshotType snapshotType,
            /* [in] */ BSTR bstrProcName,
            /* [in] */ VARIANT_BOOL fEnable);
        
        END_INTERFACE
    } ISnapshotManager3Vtbl;

    interface ISnapshotManager3
    {
        CONST_VTBL struct ISnapshotManager3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISnapshotManager3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISnapshotManager3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISnapshotManager3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISnapshotManager3_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISnapshotManager3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISnapshotManager3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISnapshotManager3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISnapshotManager3_EnablePeriodicSnapshot(This,snapshotType,interval,pids,cPids)	\
    ( (This)->lpVtbl -> EnablePeriodicSnapshot(This,snapshotType,interval,pids,cPids) ) 

#define ISnapshotManager3_DisablePeriodicSnapshot(This,snapshotType)	\
    ( (This)->lpVtbl -> DisablePeriodicSnapshot(This,snapshotType) ) 

#define ISnapshotManager3_SnapshotOnDemand(This,snapshotType,pids,cPids)	\
    ( (This)->lpVtbl -> SnapshotOnDemand(This,snapshotType,pids,cPids) ) 

#define ISnapshotManager3_VerifySnapshotSupported(This,traceHandle,frequencyInSeconds,cProviders)	\
    ( (This)->lpVtbl -> VerifySnapshotSupported(This,traceHandle,frequencyInSeconds,cProviders) ) 


#define ISnapshotManager3_ConfigSnapshotByPID(This,pids,cPids,fEnable)	\
    ( (This)->lpVtbl -> ConfigSnapshotByPID(This,pids,cPids,fEnable) ) 

#define ISnapshotManager3_ConfigSnapshotByProcess(This,bstrProcName,fEnable)	\
    ( (This)->lpVtbl -> ConfigSnapshotByProcess(This,bstrProcName,fEnable) ) 


#define ISnapshotManager3_ConfigSnapshotByPIDEx(This,snapshotType,pids,pResults,cPids,fEnable)	\
    ( (This)->lpVtbl -> ConfigSnapshotByPIDEx(This,snapshotType,pids,pResults,cPids,fEnable) ) 

#define ISnapshotManager3_ConfigSnapshotByProcessEx(This,snapshotType,bstrProcName,fEnable)	\
    ( (This)->lpVtbl -> ConfigSnapshotByProcessEx(This,snapshotType,bstrProcName,fEnable) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISnapshotManager3_INTERFACE_DEFINED__ */



#ifndef __WindowsPerformanceRecorderControlLibrary_LIBRARY_DEFINED__
#define __WindowsPerformanceRecorderControlLibrary_LIBRARY_DEFINED__

/* library WindowsPerformanceRecorderControlLibrary */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_WindowsPerformanceRecorderControlLibrary;

EXTERN_C const CLSID CLSID_CProfile;

#ifdef __cplusplus

class DECLSPEC_UUID("D66D26BF-6098-4B78-9D94-7BC219612AE4")
CProfile;
#endif

EXTERN_C const CLSID CLSID_CProfileCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("B98B53F3-83BA-4837-8946-E886BE8D4003")
CProfileCollection;
#endif

EXTERN_C const CLSID CLSID_CTraceMergeProperties;

#ifdef __cplusplus

class DECLSPEC_UUID("CAB2BDD5-5B3B-40AC-985F-2EA49E430FE4")
CTraceMergeProperties;
#endif

EXTERN_C const CLSID CLSID_CControlManager;

#ifdef __cplusplus

class DECLSPEC_UUID("971A7808-88BE-4AAD-9E1E-7C7E258512E3")
CControlManager;
#endif
#endif /* __WindowsPerformanceRecorderControlLibrary_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_windowsperformancerecordercontrol_0000_0019 */
/* [local] */ 

namespace WindowsPerformanceRecorder
{
//
// WPRControl Helper Functions
//

__control_entrypoint(DLL) HRESULT WPRCCreateInstance(_In_  REFCLSID rclsid, _In_opt_ LPUNKNOWN pUnkOuter, _In_  DWORD dwClsContext, _In_  REFIID riid, _Outptr_  LPVOID *ppv);
__control_entrypoint(DLL) HRESULT WPRCCreateInstanceUnderInstanceName(_In_opt_ BSTR bstrInstanceName, _In_  REFCLSID rclsid, _In_opt_ LPUNKNOWN pUnkOuter, _In_  DWORD dwClsContext, _In_  REFIID riid, _Outptr_  LPVOID *ppv);
__control_entrypoint(DLL) HRESULT WPRCQueryBuiltInProfiles(_In_  HMODULE hModule, _Out_  BSTR* pbstrProfiles);
__control_entrypoint(DLL) HRESULT WPRCFormatError(_In_ HRESULT Hresult, _In_opt_ LPUNKNOWN pUnknown, _Out_ BSTR* pbstrMessage, _Out_opt_ BSTR* pbstrDescription, _Out_opt_ BSTR* pbstrDetailedDescription);
__control_entrypoint(DLL) HRESULT WPRCControlLogging(_In_ BOOL fEnabled);
__control_entrypoint(DLL) HRESULT WPRCRemoveLogging();
__control_entrypoint(DLL) HRESULT WPRCDisableBuiltinProfiles();
__control_entrypoint(DLL) HRESULT WPRCReleaseInstanceByName(_In_ BSTR bstrInstanceName);

}    // namespace WindowsPerformanceRecorder



extern RPC_IF_HANDLE __MIDL_itf_windowsperformancerecordercontrol_0000_0019_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_windowsperformancerecordercontrol_0000_0019_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


