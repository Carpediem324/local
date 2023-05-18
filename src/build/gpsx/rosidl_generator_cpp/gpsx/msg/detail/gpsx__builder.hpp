// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gpsx:msg/Gpsx.idl
// generated code does not contain a copyright notice

#ifndef GPSX__MSG__DETAIL__GPSX__BUILDER_HPP_
#define GPSX__MSG__DETAIL__GPSX__BUILDER_HPP_

#include "gpsx/msg/detail/gpsx__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace gpsx
{

namespace msg
{

namespace builder
{

class Init_Gpsx_utc_time
{
public:
  explicit Init_Gpsx_utc_time(::gpsx::msg::Gpsx & msg)
  : msg_(msg)
  {}
  ::gpsx::msg::Gpsx utc_time(::gpsx::msg::Gpsx::_utc_time_type arg)
  {
    msg_.utc_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gpsx::msg::Gpsx msg_;
};

class Init_Gpsx_dilution
{
public:
  explicit Init_Gpsx_dilution(::gpsx::msg::Gpsx & msg)
  : msg_(msg)
  {}
  Init_Gpsx_utc_time dilution(::gpsx::msg::Gpsx::_dilution_type arg)
  {
    msg_.dilution = std::move(arg);
    return Init_Gpsx_utc_time(msg_);
  }

private:
  ::gpsx::msg::Gpsx msg_;
};

class Init_Gpsx_true_course_magnetic
{
public:
  explicit Init_Gpsx_true_course_magnetic(::gpsx::msg::Gpsx & msg)
  : msg_(msg)
  {}
  Init_Gpsx_dilution true_course_magnetic(::gpsx::msg::Gpsx::_true_course_magnetic_type arg)
  {
    msg_.true_course_magnetic = std::move(arg);
    return Init_Gpsx_dilution(msg_);
  }

private:
  ::gpsx::msg::Gpsx msg_;
};

class Init_Gpsx_true_course
{
public:
  explicit Init_Gpsx_true_course(::gpsx::msg::Gpsx & msg)
  : msg_(msg)
  {}
  Init_Gpsx_true_course_magnetic true_course(::gpsx::msg::Gpsx::_true_course_type arg)
  {
    msg_.true_course = std::move(arg);
    return Init_Gpsx_true_course_magnetic(msg_);
  }

private:
  ::gpsx::msg::Gpsx msg_;
};

class Init_Gpsx_separation
{
public:
  explicit Init_Gpsx_separation(::gpsx::msg::Gpsx & msg)
  : msg_(msg)
  {}
  Init_Gpsx_true_course separation(::gpsx::msg::Gpsx::_separation_type arg)
  {
    msg_.separation = std::move(arg);
    return Init_Gpsx_true_course(msg_);
  }

private:
  ::gpsx::msg::Gpsx msg_;
};

class Init_Gpsx_mode_indicator
{
public:
  explicit Init_Gpsx_mode_indicator(::gpsx::msg::Gpsx & msg)
  : msg_(msg)
  {}
  Init_Gpsx_separation mode_indicator(::gpsx::msg::Gpsx::_mode_indicator_type arg)
  {
    msg_.mode_indicator = std::move(arg);
    return Init_Gpsx_separation(msg_);
  }

private:
  ::gpsx::msg::Gpsx msg_;
};

class Init_Gpsx_satellites
{
public:
  explicit Init_Gpsx_satellites(::gpsx::msg::Gpsx & msg)
  : msg_(msg)
  {}
  Init_Gpsx_mode_indicator satellites(::gpsx::msg::Gpsx::_satellites_type arg)
  {
    msg_.satellites = std::move(arg);
    return Init_Gpsx_mode_indicator(msg_);
  }

private:
  ::gpsx::msg::Gpsx msg_;
};

class Init_Gpsx_ground_speed
{
public:
  explicit Init_Gpsx_ground_speed(::gpsx::msg::Gpsx & msg)
  : msg_(msg)
  {}
  Init_Gpsx_satellites ground_speed(::gpsx::msg::Gpsx::_ground_speed_type arg)
  {
    msg_.ground_speed = std::move(arg);
    return Init_Gpsx_satellites(msg_);
  }

private:
  ::gpsx::msg::Gpsx msg_;
};

class Init_Gpsx_altitude
{
public:
  explicit Init_Gpsx_altitude(::gpsx::msg::Gpsx & msg)
  : msg_(msg)
  {}
  Init_Gpsx_ground_speed altitude(::gpsx::msg::Gpsx::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return Init_Gpsx_ground_speed(msg_);
  }

private:
  ::gpsx::msg::Gpsx msg_;
};

class Init_Gpsx_latitude
{
public:
  explicit Init_Gpsx_latitude(::gpsx::msg::Gpsx & msg)
  : msg_(msg)
  {}
  Init_Gpsx_altitude latitude(::gpsx::msg::Gpsx::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_Gpsx_altitude(msg_);
  }

private:
  ::gpsx::msg::Gpsx msg_;
};

class Init_Gpsx_longitude
{
public:
  Init_Gpsx_longitude()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Gpsx_latitude longitude(::gpsx::msg::Gpsx::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_Gpsx_latitude(msg_);
  }

private:
  ::gpsx::msg::Gpsx msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gpsx::msg::Gpsx>()
{
  return gpsx::msg::builder::Init_Gpsx_longitude();
}

}  // namespace gpsx

#endif  // GPSX__MSG__DETAIL__GPSX__BUILDER_HPP_
