//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************
#ifndef INCLUDE_GUARD_AVID_PLATFORM_PREDEF_ARCHITECTURE_X86_32_HPP
#define INCLUDE_GUARD_AVID_PLATFORM_PREDEF_ARCHITECTURE_X86_32_HPP


#include "avid/platform/predef/make.hpp"


#define AVID_ARCHITECTURE_X86_32 0
#define AVID_ARCHITECTURE_X86_32_NAME "Intel x86-32"


#if defined(i386) || defined(__i386__) || defined(__i486__) || defined(__i586__) || defined(__i686__) || defined(__i386) \
    || defined(_M_IX86) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__)

#undef AVID_ARCHITECTURE_X86_32


#if !defined(AVID_ARCHITECTURE_X86_32) && defined(__I86__)

#define AVID_ARCHITECTURE_X86_32 AVID_VERSION_NUMBER(__I86__, 0, 0)

#endif // #if !defined(AVID_ARCHITECTURE_X86_32) && defined(__I86__)


#if !defined(AVID_ARCHITECTURE_X86_32) && defined(_M_IX86)

#define AVID_ARCHITECTURE_X86_32 AVID_MAKE_10_VV00(_M_IX86)

#endif // #if !defined(AVID_ARCHITECTURE_X86_32) && defined(_M_IX86)


#if !defined(AVID_ARCHITECTURE_X86_32) && defined(__i686__)

#define AVID_ARCHITECTURE_X86_32 AVID_VERSION_NUMBER(6, 0, 0)

#endif // #if !defined(AVID_ARCHITECTURE_X86_32) && defined(__i686__)


#if !defined(AVID_ARCHITECTURE_X86_32) && defined(__i586__)

#define AVID_ARCHITECTURE_X86_32 AVID_VERSION_NUMBER(5, 0, 0)

#endif // #if !defined(AVID_ARCHITECTURE_X86_32) && defined(__i586__)


#if !defined(AVID_ARCHITECTURE_X86_32) && defined(__i486__)

#define AVID_ARCHITECTURE_X86_32 AVID_VERSION_NUMBER(4, 0, 0)

#endif // #if !defined(AVID_ARCHITECTURE_X86_32) && defined(__i486__)


#if !defined(AVID_ARCHITECTURE_X86_32) && defined(__i386__)

#define AVID_ARCHITECTURE_X86_32 AVID_VERSION_NUMBER(3, 0, 0)

#endif // #if !defined(AVID_ARCHITECTURE_X86_32) && defined(__i386__)


#if !defined(AVID_ARCHITECTURE_X86_32)

#define AVID_ARCHITECTURE_X86_32 1

#endif // #if !defined(AVID_ARCHITECTURE_X86_32)


#endif


#ifdef AVID_ARCHITECTURE_X86_32

#define AVID_ARCHITECTURE_X86_32_AVAILABLE

#endif // #ifdef AVID_ARCHITECTURE_X86_32


#endif // #ifndef INCLUDE_GUARD_AVID_PLATFORM_PREDEF_ARCHITECTURE_X86_32_HPP

