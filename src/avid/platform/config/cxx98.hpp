﻿//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************
#ifndef INCLUDE_GUARD_AVID_PLATFORM_CONFIG_CXX98_HPP
#define INCLUDE_GUARD_AVID_PLATFORM_CONFIG_CXX98_HPP


#include <vector>
#include <string>


// rtti (run-time-type-identification)
#if !defined(__cpp_rtti) || (__cpp_rtti < 199711)
#define AVID_NO_CXX98_RTTI
#endif

// exceptions
#if !defined(__cpp_exceptions) || (__cpp_exceptions < 199711)
#define AVID_NO_CXX98_EXCEPTIONS
#endif


namespace avid {
namespace platform {
namespace config {

// get C++98 supported functions
std::vector<std::string> Get_CXX98SupportedFunctions();

// get C++98 unsupported functions
std::vector<std::string> Get_CXX98UnsupportedFunctions();

} // namespace config
} // namespace platform
} // namespace avid


#endif // #ifndef INCLUDE_GUARD_AVID_PLATFORM_CONFIG_CXX98_HPP
