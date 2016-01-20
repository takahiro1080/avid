//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************

// declaration headers
#include "version_number.hpp"

// C library headers

// C++ library headers
#include <sstream>

// other library headers

// avid library headers


namespace avid {


// make version string
std::string MakeVersionString(std::uint32_t version) {

    std::uint32_t major, minor, patch;

    patch = version % 1000000;
    minor = (version % 100000000) / 1000000;
    major = (version % 10000000000) / 100000000;

    std::stringstream ss;
    ss << major << "." << minor << "." << patch;
    return ss.str();
}


} // namespace avid



