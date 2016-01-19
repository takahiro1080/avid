//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************
#ifndef INCLUDE_GUARD_AVID_PLATFORM_PREDEF_COMPILER_VISUALC_HPP
#define INCLUDE_GUARD_AVID_PLATFORM_PREDEF_COMPILER_VISUALC_HPP


#include "avid/platform/predef/version_number.hpp"


#define AVID_COMPILER_MSVC 0
#define AVID_COMPILER_MSVC_NAME "Microsoft Visual C/C++"


#if defined(_MSC_VER)


#if !defined(_MSC_FULL_VER)

#define AVID_COMPILER_MSVC_BUILD 0

#else // #if !defined(_MSC_FULL_VER)


#if (_MSC_FULL_VER / 10000) == _MSC_VER

#define AVID_COMPILER_MSVC_BUILD (_MSC_FULL_VER % 10000)

#elif (_MSC_FULL_VER / 100000) == _MSC_VER

#define AVID_COMPILER_MSVC_BUILD (_MSC_FULL_VER % 100000)

#else

#error "Cannot determine build number from _MSC_FULL_VER."

#endif // #if (_MSC_FULL_VER / 10000) == _MSC_VER


#if (_MSC_VER >= 1900)

#define AVID_COMPILER_MSVC_DETECTION \
    AVID_VERSION_NUMBER(_MSC_VER / 100 - 5,_MSC_VER % 100, AVID_COMPILER_MSVC_BUILD)

#else // #if (_MSC_VER >= 1900)

#define AVID_COMPILER_MSVC_DETECTION \
    AVID_VERSION_NUMBER(_MSC_VER / 100 - 6,_MSC_VER % 100, AVID_COMPILER_MSVC_BUILD)

#endif // #if (_MSC_VER >= 1900)


#endif // #if !defined(_MSC_FULL_VER)


#endif // #if defined(_MSC_VER)



#ifdef AVID_COMPILER_MSVC_DETECTION


#ifdef AVID_COMPILER_DETECTED

#define AVID_COMPILER_MSVC_EMULATED AVID_COMPILER_MSVC_DETECTION

#else // #ifdef AVID_COMPILER_DETECTED

#undef AVID_COMPILER_MSVC
#define AVID_COMPILER_MSVC AVID_COMPILER_MSVC_DETECTION

#endif // #ifdef AVID_COMPILER_DETECTED


#define AVID_COMPILER_MSVC_AVAILABLE
#include "avid/platform/predef/compiler/compiler_detected.hpp"


#endif // #ifdef AVID_COMPILER_MSVC_DETECTION


#endif // #ifndef INCLUDE_GUARD_AVID_PLATFORM_PREDEF_COMPILER_VISUALC_HPP

