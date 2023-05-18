// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gpsx:srv/GetSatList.idl
// generated code does not contain a copyright notice

#ifndef GPSX__SRV__DETAIL__GET_SAT_LIST__TRAITS_HPP_
#define GPSX__SRV__DETAIL__GET_SAT_LIST__TRAITS_HPP_

#include "gpsx/srv/detail/get_sat_list__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<gpsx::srv::GetSatList_Request>()
{
  return "gpsx::srv::GetSatList_Request";
}

template<>
inline const char * name<gpsx::srv::GetSatList_Request>()
{
  return "gpsx/srv/GetSatList_Request";
}

template<>
struct has_fixed_size<gpsx::srv::GetSatList_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gpsx::srv::GetSatList_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gpsx::srv::GetSatList_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<gpsx::srv::GetSatList_Response>()
{
  return "gpsx::srv::GetSatList_Response";
}

template<>
inline const char * name<gpsx::srv::GetSatList_Response>()
{
  return "gpsx/srv/GetSatList_Response";
}

template<>
struct has_fixed_size<gpsx::srv::GetSatList_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<gpsx::srv::GetSatList_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<gpsx::srv::GetSatList_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<gpsx::srv::GetSatList>()
{
  return "gpsx::srv::GetSatList";
}

template<>
inline const char * name<gpsx::srv::GetSatList>()
{
  return "gpsx/srv/GetSatList";
}

template<>
struct has_fixed_size<gpsx::srv::GetSatList>
  : std::integral_constant<
    bool,
    has_fixed_size<gpsx::srv::GetSatList_Request>::value &&
    has_fixed_size<gpsx::srv::GetSatList_Response>::value
  >
{
};

template<>
struct has_bounded_size<gpsx::srv::GetSatList>
  : std::integral_constant<
    bool,
    has_bounded_size<gpsx::srv::GetSatList_Request>::value &&
    has_bounded_size<gpsx::srv::GetSatList_Response>::value
  >
{
};

template<>
struct is_service<gpsx::srv::GetSatList>
  : std::true_type
{
};

template<>
struct is_service_request<gpsx::srv::GetSatList_Request>
  : std::true_type
{
};

template<>
struct is_service_response<gpsx::srv::GetSatList_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // GPSX__SRV__DETAIL__GET_SAT_LIST__TRAITS_HPP_
