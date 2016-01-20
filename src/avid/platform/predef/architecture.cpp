//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************

// declaration headers
#include "architecture.hpp"

// C library headers

// C++ library headers

// other library headers

// avid library headers


namespace avid {
namespace platform {
namespace architecture {


// get architecture name
std::string GetArchitectureName() {

#if AVID_ARCHITECTURE_X86_32

    return AVID_ARCHITECTURE_X86_32_NAME;

#else

    return "Cannot determine architecture.";

#endif
}


// get architecture version
std::string GetArchitectureVersion() {

#if AVID_ARCHITECTURE_X86_32

    return MakeVersionString(AVID_ARCHITECTURE_X86_32);

#else

    return "Cannot determine architecture version.";

#endif

}


// get architecture
std::string GetArchitecture() {

    return GetArchitectureName() + "(" + GetArchitectureVersion() + ")";

}


} // namespace architecture
} // namespace platform
} // namespace avid



