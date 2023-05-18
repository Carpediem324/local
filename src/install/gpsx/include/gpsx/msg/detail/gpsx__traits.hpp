// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gpsx:msg/Gpsx.idl
// generated code does not contain a copyright notice

#ifndef GPSX__MSG__DETAIL__GPSX__TRAITS_HPP_
#define GPSX__MSG__DETAIL__GPSX__TRAITS_HPP_

#include "gpsx/msg/detail/gpsx__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<gpsx::msg::Gpsx>()
{
  return "gpsx::msg::Gpsx";
}

template<>
inline const char * name<gpsx::msg::Gpsx>()
{
  return "gpsx/msg/Gpsx";
}

template<>
struct has_fixed_size<gpsx::msg::Gpsx>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gpsx::msg::Gpsx>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gpsx::msg::Gpsx>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GPSX__MSG__DETAIL__GPSX__TRAITS_HPP_
