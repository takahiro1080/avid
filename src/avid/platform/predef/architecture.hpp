//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************
#ifndef INCLUDE_GUARD_AVID_PLATFORM_PREDEF_ARCHITECTURE_HPP
#define INCLUDE_GUARD_AVID_PLATFORM_PREDEF_ARCHITECTURE_HPP

#include <string>

#include "architecture/x86_32.hpp"


namespace avid {
namespace platform {
namespace architecture {

// get architecture name
std::string Get_ArchitectureName();

// get architecture version
std::string Get_ArchitectureVersion();

// get architecture
std::string Get_Architecture();

} // namespace architecture
} // namespace platform
} // namespace avid


#endif // #ifndef INCLUDE_GUARD_AVID_PLATFORM_PREDEF_ARCHITECTURE_HPP

