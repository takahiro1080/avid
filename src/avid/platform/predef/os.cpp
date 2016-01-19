//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************
#include "os.hpp"


namespace avid {
namespace platform {
namespace os {


// get operating-system name
std::string GetOSName() {

#if AVID_OS_WINDOWS

    return AVID_OS_WINDOWS_NAME;

#else

    return "Cannot determine operating-system.";

#endif
}


} // namespace os
} // namespace platform
} // namespace avid


