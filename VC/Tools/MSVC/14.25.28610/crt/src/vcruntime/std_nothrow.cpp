//
// std_nothrow.cpp
//
//      Copyright (c) Microsoft Corporation. All rights reserved.
//
// Defines std::nothrow.
//
#include <vcruntime_internal.h>
#include <vcruntime_new.h>

namespace std
{
    // Note:  We use aggregate initialization in order to avoid use of a dynamic
    // initializer.
    const nothrow_t nothrow = { }; // TRANSITION, VSO#406237
}
