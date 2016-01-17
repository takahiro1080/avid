//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************
#ifndef INCLUDE_GUARD_AVID_PLATFORM_PREDEF_COMPILER_CLANG_HPP
#define INCLUDE_GUARD_AVID_PLATFORM_PREDEF_COMPILER_CLANG_HPP


#include "avid/platform/predef/version_number.hpp"


#define AVID_COMPILER_CLANG 0
#define AVID_COMPILER_CLANG_NAME "Clang"


#if defined(__clang__)

#define AVID_COMPILER_CLANG_DETECTION \
    AVID_VERSION_NUMBER(__clang_major__, __clang_minor__, __clang_patchlevel__)

#endif // #if defined(__clang__)



#ifdef AVID_COMPILER_CLANG_DETECTION


#ifdef AVID_COMPILER_DETECTED

#define AVID_COMPILER_CLANG_EMULATED AVID_COMPILER_CLANG_DETECTION
#define AVID_EMULATED_COMPILER_NAME AVID_COMPILER_CLANG_NAME

#else // #ifdef AVID_COMPILER_DETECTED

#undef AVID_COMPILER_CLANG
#define AVID_COMPILER_CLANG AVID_COMPILER_CLANG_DETECTION
#define AVID_COMPILER_NAME AVID_COMPILER_CLANG_NAME

#endif // #ifdef AVID_COMPILER_DETECTED


#define AVID_COMPILER_CLANG_AVAILABLE
#include "avid/platform/predef/compiler/compiler_detected.hpp"


#endif // #ifdef AVID_COMPILER_CLANG_DETECTION


#endif // #ifndef INCLUDE_GUARD_AVID_PLATFORM_PREDEF_COMPILER_CLANG_HPP

