﻿//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************

// declaration headers
#include "compiler.hpp"

// C library headers

// C++ library headers
#include <sstream>
#include <iostream>

// other library headers

// avid library headers




namespace avid {
namespace platform {
namespace compiler {


// get compiler name
std::string Get_CompilerName() {

#if AVID_COMPILER_CLANG

    return AVID_COMPILER_CLANG_NAME;

#elif AVID_COMPILER_GNUC

    return AVID_COMPILER_GNUC_NAME;

#elif AVID_COMPILER_MSVC

    return AVID_COMPILER_MSVC_NAME;

#else

    return "Cannot determine compiler.";

#endif
}


// get compiler version
std::string Get_CompilerVersion() {

    std::stringstream ss;
#if AVID_COMPILER_CLANG

    return Make_VersionString(AVID_COMPILER_CLANG);

#elif AVID_COMPILER_GNUC

    return Make_VersionString(AVID_COMPILER_GNUC);

#elif AVID_COMPILER_MSVC

    return Make_VersionString(AVID_COMPILER_MSVC);

#else

    return "Cannot determine compiler version.";

#endif
}


// get compiler
std::string Get_Compiler() {

    return Get_CompilerName() + "(" + Get_CompilerVersion() + ")";
}


// get emulated compiler name
std::vector<std::string> Get_EmulatedCompiler() {

    std::vector<std::string> result;
    std::string str = "";

#if defined(AVID_COMPILER_CLANG_EMULATED)

    str = AVID_COMPILER_CLANG_NAME;
    str += "(" + Make_VersionString(AVID_COMPILER_CLANG_EMULATED) + ")";
    result.push_back(str);

#elif defined(AVID_COMPILER_GNUC_EMULATED)

    str = AVID_COMPILER_GNUC_NAME;
    str += "(" + Make_VersionString(AVID_COMPILER_GNUC_EMULATED) + ")";
    result.push_back(str);

#elif defined(AVID_COMPILER_MSVC_EMULATED)

    str = AVID_COMPILER_MSVC_NAME;
    str += "(" + Make_VersionString(AVID_COMPILER_MSVC_EMULATED) + ")";
    result.push_back(str);

#else
    
    str = "Any compiler is not emulated.";
    result.push_back(str);

#endif

    return result;
}


} // namespace compiler
} // namespace platform
} // namespace avid


