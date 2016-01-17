//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************
#ifndef INCLUDE_GUARD_AVID_PLATFORM_PREDEF_VERSION_NUMBER_HPP
#define INCLUDE_GUARD_AVID_PLATFORM_PREDEF_VERSION_NUMBER_HPP


#define AVID_VERSION_NUMBER(major,minor,patch) ((((major)%100)*100000000) + (((minor)%100)*1000000) + ((patch)%10000))

#define AVID_VERSION_NUMBER_MAX AVID_VERSION_NUMBER(99,99,9999)
#define AVID_VERSION_NUMBER_MIN AVID_VERSION_NUMBER(0,0,1)
#define AVID_VERSION_NUMBER_ZERO AVID_VERSION_NUMBER(0,0,0)


#endif // INCLUDE_GUARD_AVID_PLATFORM_PREDEF_VERSION_NUMBER_HPP

