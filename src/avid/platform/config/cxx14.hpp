//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************
#ifndef INCLUDE_GUARD_AVID_PLATFORM_CONFIG_CXX14_HPP
#define INCLUDE_GUARD_AVID_PLATFORM_CONFIG_CXX14_HPP


#include <utility>
#include <memory>
#include <functional>
#include <type_traits>
#include <chrono>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
#include <complex>
#include <iomanip>
#include <vector>



// has attribute
#if !defined(__has_cpp_attribute)
#define __has_cpp_attribute(x) (0)
#endif

// has include
#if !defined(__has_include)
#define __has_include(x) (0)
#endif

// binary literals
#if !defined(__cpp_binary_literals) || (__cpp_binary_literals < 201304)
#define AVID_NO_CXX14_BINARY_LITERALS
#endif

// digit separators
#if !defined(__cpp_digit_separators) || (__cpp_digit_separators < 201309)
#define AVID_NO_CXX14_DIGIT_SEPARATORS
#endif

// lambda init captures
#if !defined(__cpp_init_captures) || (__cpp_init_captures < 201304)
#define AVID_NO_CXX14_INIT_CAPTURES
#endif

// generic lambdas
#if !defined(__cpp_generic_lambdas) || (__cpp_generic_lambdas < 201304)
#define AVID_NO_CXX14_GENERIC_LAMBDAS
#endif

// sized deallocation
#if !defined(__cpp_sized_deallocation) || (__cpp_sized_deallocation < 201309)
#define AVID_NO_CXX14_SIZED_DEALLOCATION
#endif

// relaxed c++14 constexpr
#if !defined(__cpp_constexpr) || (__cpp_constexpr < 201304)
#define AVID_NO_CXX14_CONSTEXPR
#endif

// decltype auto
#if !defined(__cpp_decltype_auto) || (__cpp_decltype_auto < 201304)
#define AVID_NO_CXX14_DECLTYPE_AUTO
#endif

// return type deduction
#if !defined(__cpp_return_type_deduction) || (__cpp_return_type_deduction < 201304)
#define AVID_NO_CXX14_RETURN_TYPE_DEDUCTION
#endif

// attribute deprecated
#if (__has_cpp_attribute(deprecated) < 201309)
#define AVID_NO_CXX14_ATTRIBUTE_DEPRECATED
#endif

// aggregate non static data menber initializers
#if !defined(__cpp_aggregate_nsdmi) || (__cpp_aggregate_nsdmi < 201304)
#define AVID_NO_CXX14_AGGREGATE_NON_STATIC_DATA_MEMBER_INITIALIZERS
#endif

// variable templates
#if !defined(__cpp_variable_templates) || (__cpp_variable_templates < 201309)
#define AVID_NO_CXX14_VARIABLE_TEMPLATES
#endif

// integer sequence
#if !defined(__cpp_lib_integer_sequence) || (__cpp_lib_integer_sequence < 201304)
#define AVID_NO_CXX14_LIB_INTEGER_SEQUENCE
#endif

// exchange function
#if !defined(__cpp_lib_exchange_function) || (__cpp_lib_exchange_function < 201304)
#define AVID_NO_CXX14_LIB_EXCHANGE_FUNCTION
#endif

// tuples by type
#if !defined(__cpp_lib_tuples_by_type) || (__cpp_lib_tuples_by_type < 201304)
#define AVID_NO_CXX14_LIB_TUPLES_TY_TYPE
#endif

// tuple_element_t
#if !defined(__cpp_lib_tuple_element_t) || (__cpp_lib_tuple_element_t < 201402)
#define AVID_NO_CXX14_LIB_TUPLE_ELEMENT_T
#endif

// make_unique
#if !defined(__cpp_lib_make_unique) || (__cpp_lib_make_unique < 201304)
#define AVID_NO_CXX14_LIB_MAKE_UNIQUE
#endif

// transparent operators 'greater<>'
#if !defined(__cpp_lib_transparent_operators) || (__cpp_lib_transparent_operators < 201210)
#define AVID_NO_CXX14_LIB_TRANSPARENT_OPERATORS
#endif

// result of sfinae
#if !defined(__cpp_lib_result_of_sfinae) || (__cpp_lib_result_of_sfinae < 201210)
#define AVID_NO_CXX14_LIB_RESULT_OF_SFINAE
#endif

// integral constant callable
#if !defined(__cpp_lib_integral_constant_callable) || (__cpp_lib_integral_constant_callable < 201304)
#define AVID_NO_CXX14_LIB_INTEGRAL_CONSTANT_CALLABLE
#endif

// transformation trait aliases
#if !defined(__cpp_lib_transformation_trait_aliases) || (__cpp_lib_transformation_trait_aliases < 201304)
#define AVID_NO_CXX14_LIB_TRANSFORMATION_TRAIT_ALIASES
#endif

// is_final
#if !defined(__cpp_lib_is_final) || (__cpp_lib_is_final < 201402)
#define AVID_NO_CXX14_LIB_IS_FINAL
#endif

// is_null_pointer
#if !defined(__cpp_lib_is_null_pointer) || (__cpp_lib_is_null_pointer < 201309)
#define AVID_NO_CXX14_LIB_IS_NULL_POINTER
#endif

// user defined literals of chrono
#if !defined(__cpp_lib_chrono_udls) || (__cpp_lib_chrono_udls < 201304)
#define AVID_NO_CXX14_LIB_CHRONO_USER_DEFINED_LITERALS
#endif

// user defined literals of string
#if !defined(__cpp_lib_string_udls) || (__cpp_lib_string_udls < 201304)
#define AVID_NO_CXX14_LIB_STRING_USER_DEFINED_LITERALS
#endif

// generic associative lookup
#if !defined(__cpp_lib_generic_associative_lookup) || (__cpp_lib_generic_associative_lookup < 201304)
#define AVID_NO_CXX14_LIB_GENERIC_ASSOCIATIVE_LOOKUP
#endif

// null iterators
#if !defined(__cpp_lib_null_iterators) || (__cpp_lib_null_iterators < 201304)
#define AVID_NO_CXX14_LIB_NULL_ITERATORS
#endif

// make_reverse_iterator
#if !defined(__cpp_lib_make_reverse_iterator) || (__cpp_lib_make_reverse_iterator < 201402)
#define AVID_NO_CXX14_LIB_MAKE_REVERSE_ITERATOR
#endif

// robust non modifying sequence operators
#if !defined(__cpp_lib_robust_nonmodifying_seq_ops) || (__cpp_lib_robust_nonmodifying_seq_ops < 201304)
#define AVID_NO_CXX14_LIB_ROBUST_NON_MODIFYING_SEQUENCE_OPERATORS
#endif

// user defined literals of complex
#if !defined(__cpp_lib_complex_udls) || (__cpp_lib_complex_udls < 201309)
#define AVID_NO_CXX14_LIB_COMPLEX_USER_DEFINED_LITERALS
#endif

// quoted string io
#if !defined(__cpp_lib_quoted_string_io) || (__cpp_lib_quoted_string_io < 201304)
#define AVID_NO_CXX14_LIB_QUATED_STRING_IO
#endif

// shared_mutex
#if  (!__has_include(<shared_mutex>))
#define AVID_NO_CXX14_INCLUDE_SHARED_MUTEX
#endif

// shared_timed_mutex
#if !defined(AVID_NO_CXX14_INCLUDE_SHARED_MUTEX)

#include <shared_mutex>

#if !defined(__cpp_lib_shared_timed_mutex) || (__cpp_lib_shared_timed_mutex < 201402)
#define AVID_NO_CXX_LIB_SHARED_TIMED_MUTEX
#endif

#endif // #if !defined(AVID_NO_CXX14_INCLUDE_SHARED_MUTEX)


namespace avid {
namespace platform {
namespace config {

// get C++14 supported functions
std::vector<std::string> Get_CXX14SupportedFunctions();

// get C++14 unsupported functions
std::vector<std::string> Get_CXX14UnsupportedFunctions();

} // namespace config
} // namespace platform
} // namespace avid


#endif // #ifndef INCLUDE_GUARD_AVID_PLATFORM_CONFIG_CXX14_HPP

