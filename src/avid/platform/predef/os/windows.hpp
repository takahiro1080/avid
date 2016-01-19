//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************
#ifndef INCLUDE_GUARD_AVID_PLATFORM_PREDEF_OS_WINDOWS_HPP
#define INCLUDE_GUARD_AVID_PLATFORM_PREDEF_OS_WINDOWS_HPP


#define AVID_OS_WINDOWS 0
#define AVID_OS_WINDOWS_NAME "Microsoft Windows"


#ifndef AVID_OS_DETECTED


#if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(_WINDOWS) || defined(__WINDOWS__)

#undef AVID_OS_WINDOWS
#define AVID_OS_WINDOWS 1
#define AVID_OS_WINDOWS_AVAILABLE
#define AVID_OS_DETECTED 1

#endif


#endif // AVID_OS_DETECTED


#endif // INCLUDE_GUARD_AVID_PLATFORM_PREDEF_OS_WINDOWS_HPP

