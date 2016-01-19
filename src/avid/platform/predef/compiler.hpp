//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************
#ifndef INCLUDE_GUARD_AVID_PLATFORM_PREDEF_COMPILER_HPP
#define INCLUDE_GUARD_AVID_PLATFORM_PREDEF_COMPILER_HPP

#include <vector>

#include <string>

#include "avid/platform/predef/compiler/clang.hpp"

#include "avid/platform/predef/compiler/gcc.hpp"

#include "avid/platform/predef/compiler/visualc.hpp"


namespace avid {
namespace platform {
namespace compiler {

// get compiler name
std::string GetCompilerName();

// get compiler version
std::string GetCompilerVersion();

// get compiler
std::string GetCompiler();

// get emulated compiler
std::vector<std::string> GetEmulatedCompiler();

} // namespace compiler
} // namespace platform
} // namespace avid



#endif // INCLUDE_GUARD_AVID_PLATFORM_PREDEF_COMPILER_HPP

