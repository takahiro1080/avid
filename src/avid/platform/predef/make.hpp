//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************
#ifndef INCLUDE_GUARD_PLATFORM_PREDEF_MAKE_HPP
#define INCLUDE_GUARD_PLATFORM_PREDEF_MAKE_HPP


#include "avid/platform/predef/version_number.hpp"


#define AVID_MAKE_0X_VRP(v) AVID_VERSION_NUMBER(((v) & 0xF00) >> 8, ((v) & 0xF0) >> 4, ((v) & 0xF))

#define AVID_MAKE_0X_VVRP(v) AVID_VERSION_NUMBER(((v) & 0xFF00) >> 8, ((v) & 0xF0) >> 4, ((v) & 0xF))

#define AVID_MAKE_0X_VRPP(v) AVID_VERSION_NUMBER(((v) & 0xF000) >> 12, ((v) & 0xF00) >> 8, ((v) & 0xFF))

#define AVID_MAKE_0X_VVRR(v) AVID_VERSION_NUMBER(((v) & 0xFF00) >> 8, ((v) & 0xFF), 0)

#define AVID_MAKE_0X_VRRPPPP(v) AVID_VERSION_NUMBER(((v) & 0xF000000) >> 24, ((v) & 0xFF0000) >> 16, ((v) & 0xFFFF))

#define AVID_MAKE_0X_VVRRP(v) AVID_VERSION_NUMBER(((v) & 0xFF000) >> 12, ((v) & 0xFF0) >> 4, ((v) & 0xF))

#define AVID_MAKE_0X_VRRPP000(v) AVID_VERSION_NUMBER(((v) & 0xF0000000) >> 28, ((v) & 0xFF00000) >> 20, ((v) & 0xFF000) >> 12)

#define AVID_MAKE_0X_VVRRPP(v) AVID_VERSION_NUMBER(((v) & 0xFF0000) >> 16, ((v) & 0xFF00) >> 8, ((v) & 0xFF))

#define AVID_MAKE_10_VPPP(v) AVID_VERSION_NUMBER(((v) / 1000) % 10, 0, (v) % 1000)

#define AVID_MAKE_10_VRP(v) AVID_VERSION_NUMBER(((v) / 100) % 10, ((v) / 10) % 10, (v) % 10)

#define AVID_MAKE_10_VRP000(v) AVID_VERSION_NUMBER(((v) / 100000) % 10, ((v) / 10000) % 10, ((v) / 1000) % 10)

#define AVID_MAKE_10_VRPP(v) AVID_VERSION_NUMBER(((v) / 1000) % 10, ((v) / 100) % 10, (v) % 100)

#define AVID_MAKE_10_VRR(v) AVID_VERSION_NUMBER(((v) / 100) % 10, (v) % 100, 0)

#define AVID_MAKE_10_VRRPP(v) AVID_VERSION_NUMBER(((v) / 10000) % 10, ((v) / 100) % 100, (v) % 100)

#define AVID_MAKE_10_VRR000(v) AVID_VERSION_NUMBER(((v) / 100000) % 10, ((v) / 1000) % 100, 0)

#define AVID_MAKE_10_VV00(v) AVID_VERSION_NUMBER(((v) / 100) % 100, 0, 0)

#define AVID_MAKE_10_VVRR(v) AVID_VERSION_NUMBER(((v) / 100) % 100, (v) % 100, 0)

#define AVID_MAKE_10_VVRRPP(v) AVID_VERSION_NUMBER(((v) / 10000) % 100, ((v) / 100) % 100, (v) % 100)

#define AVID_MAKE_10_VVRR0PP00(v) AVID_VERSION_NUMBER(((v) / 10000000) % 100, ((v) / 100000) % 100, ((v) / 100) % 100)

#define AVID_MAKE_10_VVRR0PPPP(v) AVID_VERSION_NUMBER(((v) / 10000000) % 100, ((v) / 100000) % 100, (v) % 10000)

#define AVID_MAKE_10_VVRR00PP00(v) AVID_VERSION_NUMBER(((v) / 100000000) % 100, ((v) / 1000000) % 100, ((v) / 100) % 100)



#define AVID_MAKE_DATE(year, month, day) AVID_VERSION_NUMBER((year) % 10000 - 1970, (month) % 100, (day) % 100)

#define AVID_MAKE_YYYYMMDD(v) AVID_MAKE_DATE(((v) / 10000) % 10000, ((v) / 100) % 100, (v) % 100)

#define AVID_MAKE_YYYY(v) AVID_MAKE_DATE(v, 1, 1)

#define AVID_MAKE_YYYYMM(v) AVID_MAKE_DATE((v) / 100, (v) % 100, 1)


#endif // INCLUDE_GUARD_PLATFORM_PREDEF_MAKE_HPP

