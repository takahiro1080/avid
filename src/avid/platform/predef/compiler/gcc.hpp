//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************
#ifndef INCLUDE_GUARD_AVID_PLATFORM_PREDEF_COMPILER_GCC_HPP
#define INCLUDE_GUARD_AVID_PLATFORM_PREDEF_COMPILER_GCC_HPP


#include "avid/platform/predef/version_number.hpp"


#define AVID_COMPILER_GNUC 0
#define AVID_COMPILER_GNUC_NAME "Gnu GCC C/C++"


#if defined(__GNUC__)

#if defined(__GNUC_PATCHLEVEL__)

#define AVID_COMPILER_GNUC_DETECTION \
    AVID_VERSION_NUMBER(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)

#else // #if defined(__GNUC__)

#define AVID_COMPILER_GNUC_DETECTION \
    AVID_VERSION_NUMBER(__GNUC__, __GNUC_MINOR__, 0)

#endif // #if defined(__GNUC__)


#endif // #if defined(__GNUC__)



#ifdef AVID_COMPILER_GNUC_DETECTION


#ifdef AVID_COMPILER_DETECTED

#define AVID_COMPILER_GNUC_EMULATED AVID_COMPILER_GNUC_DETECTION
#define AVID_EMULATED_COMPILER_NAME AVID_COMPILER_GNUC_NAME

#else // #ifdef AVID_COMPILER_DETECTED

#undef AVID_COMPILER_GNUC
#define AVID_COMPILER_GNUC AVID_COMPILER_GNUC_DETECTION
#define AVID_COMPILER_NAME AVID_COMPILER_GNUC_NAME

#endif // #ifdef AVID_COMPILER_DETECTED


#define AVID_COMPILER_GNUC_AVAILABLE
#include "avid/platform/predef/compiler/compiler_detected.hpp"

#endif // #ifdef AVID_COMPILER_GNUC_DETECTION


#endif // #ifndef INCLUDE_GUARD_AVID_PLATFORM_PREDEF_COMPILER_GCC_HPP

