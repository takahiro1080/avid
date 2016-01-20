//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************
#ifndef INCLUDE_GUARD_AVID_PLATFORM_CONFIG_CXX11_HPP
#define INCLUDE_GUARD_AVID_PLATFORM_CONFIG_CXX11_HPP


#include <vector>
#include <string>


// has attribute
#if !defined(__has_cpp_attribute)
#define __has_cpp_attribute(x) (0)
#endif

// unicode characters
#if !defined(__cpp_unicode_characters) || (__cpp_unicode_characters < 200704)
#define AVID_NO_CXX11_UNICODE_CHARACTERS
#endif

// raw strings
#if !defined(__cpp_raw_strings) || (__cpp_raw_strings < 200710)
#define AVID_NO_CXX11_RAW_STRINGS
#endif

// unicode literals
#if !defined(__cpp_unicode_literals) || (__cpp_unicode_literals < 200710)
#define AVID_NO_CXX11_UNICODE_LITERALS
#endif

// user defined literals
#if !defined(__cpp_user_defined_literals) || (__cpp_user_defined_literals < 200809)
#define AVID_NO_CXX11_USER_DEFINED_LITERALS
#endif

// lambda functions
#if !defined(__cpp_lambdas) || (__cpp_lambdas < 200907)
#define AVID_NO_CXX11_LAMBDAS
#endif

// c++11 constexpr
#if !defined(__cpp_constexpr) || (__cpp_constexpr < 200704)
#define AVID_NO_CXX11_CONSTEXPR
#endif

// range based for
#if !defined(__cpp_range_based_for) || (__cpp_range_based_for < 200907)
#define AVID_NO_CXX11_RANGE_BASED_FOR
#endif

// static assert
#if !defined(__cpp_static_assert) || (__cpp_static_assert < 200410)
#define AVID_NO_CXX11_STATIC_ASSERT
#endif

// decltype
#if !defined(__cpp_decltype) || (__cpp_decltype < 200707)
#define AVID_NO_CXX11_DECLTYPE
#endif

// attributes
#if !defined(__cpp_attributes) || (__cpp_attributes < 200809)
#define AVID_NO_CXX11_ATTRIBUTES
#endif

// attribute noreturn
#if (!__has_cpp_attribute(noreturn))
#define AVID_NO_CXX11_ATTRIBUTE_NORETURN
#endif

// attribute carries_dependency
#if (!__has_cpp_attribute(carries_dependency))
#define AVID_NO_CXX11_ATTRIBUTE_CARRIES_DEPENDENCY
#endif

// rvalue references
#if !defined(__cpp_rvalue_references) || (__cpp_rvalue_references < 200610)
#define AVID_NO_CXX11_RVALUE_REFERENCES
#endif

// variadic templates
#if !defined(__cpp_variadic_templates) || (__cpp_variadic_templates < 200704)
#define AVID_NO_CXX11_VARIADIC_TEMPLATES
#endif

// initializer lists
#if !defined(__cpp_initializer_lists) || (__cpp_initializer_lists < 200806)
#define AVID_NO_CXX11_INITIALIZER_LISTS
#endif

// delegating constructors
#if !defined(__cpp_delegating_constructors) || (__cpp_delegating_constructors < 200604)
#define AVID_NO_CXX11_DELEGATING_CONSTRUCTORS
#endif

// non static data member initializers
#if !defined(__cpp_nsdmi) || (__cpp_nsdmi < 200809)
#define AVID_NO_CXX11_NON_STATIC_DATA_MEMBER_INITIALIZERS
#endif

// inheriting constructors
#if !defined(__cpp_inheriting_constructors) || (__cpp_inheriting_constructors < 200802)
#define AVID_NO_CXX11_INHERITING_CONSTRUCTORS
#endif

// ref qualifiers
#if !defined(__cpp_ref_qualifiers) || (__cpp_ref_qualifiers < 200710)
#define AVID_NO_CXX11_REF_QUALIFIERS
#endif

// alias templates
#if !defined(__cpp_alias_templates) || (__cpp_alias_templates < 200704)
#define AVID_NO_CXX11_ALIAS_TEMPLATES
#endif


#endif // #ifndef INCLUDE_GUARD_AVID_PLATFORM_CONFIG_CXX11_HPP

