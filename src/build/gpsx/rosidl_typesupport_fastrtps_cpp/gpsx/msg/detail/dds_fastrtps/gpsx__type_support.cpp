// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from gpsx:msg/Gpsx.idl
// generated code does not contain a copyright notice
#include "gpsx/msg/detail/gpsx__rosidl_typesupport_fastrtps_cpp.hpp"
#include "gpsx/msg/detail/gpsx__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace gpsx
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gpsx
cdr_serialize(
  const gpsx::msg::Gpsx & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: longitude
  cdr << ros_message.longitude;
  // Member: latitude
  cdr << ros_message.latitude;
  // Member: altitude
  cdr << ros_message.altitude;
  // Member: ground_speed
  cdr << ros_message.ground_speed;
  // Member: satellites
  cdr << ros_message.satellites;
  // Member: mode_indicator
  cdr << ros_message.mode_indicator;
  // Member: separation
  cdr << ros_message.separation;
  // Member: true_course
  cdr << ros_message.true_course;
  // Member: true_course_magnetic
  cdr << ros_message.true_course_magnetic;
  // Member: dilution
  cdr << ros_message.dilution;
  // Member: utc_time
  cdr << ros_message.utc_time;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gpsx
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  gpsx::msg::Gpsx & ros_message)
{
  // Member: longitude
  cdr >> ros_message.longitude;

  // Member: latitude
  cdr >> ros_message.latitude;

  // Member: altitude
  cdr >> ros_message.altitude;

  // Member: ground_speed
  cdr >> ros_message.ground_speed;

  // Member: satellites
  cdr >> ros_message.satellites;

  // Member: mode_indicator
  cdr >> ros_message.mode_indicator;

  // Member: separation
  cdr >> ros_message.separation;

  // Member: true_course
  cdr >> ros_message.true_course;

  // Member: true_course_magnetic
  cdr >> ros_message.true_course_magnetic;

  // Member: dilution
  cdr >> ros_message.dilution;

  // Member: utc_time
  cdr >> ros_message.utc_time;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gpsx
get_serialized_size(
  const gpsx::msg::Gpsx & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: longitude
  {
    size_t item_size = sizeof(ros_message.longitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: latitude
  {
    size_t item_size = sizeof(ros_message.latitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: altitude
  {
    size_t item_size = sizeof(ros_message.altitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ground_speed
  {
    size_t item_size = sizeof(ros_message.ground_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: satellites
  {
    size_t item_size = sizeof(ros_message.satellites);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: mode_indicator
  {
    size_t item_size = sizeof(ros_message.mode_indicator);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: separation
  {
    size_t item_size = sizeof(ros_message.separation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: true_course
  {
    size_t item_size = sizeof(ros_message.true_course);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: true_course_magnetic
  {
    size_t item_size = sizeof(ros_message.true_course_magnetic);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dilution
  {
    size_t item_size = sizeof(ros_message.dilution);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: utc_time
  {
    size_t item_size = sizeof(ros_message.utc_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gpsx
max_serialized_size_Gpsx(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: longitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: latitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: altitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: ground_speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: satellites
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: mode_indicator
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: separation
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: true_course
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: true_course_magnetic
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: dilution
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: utc_time
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Gpsx__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const gpsx::msg::Gpsx *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Gpsx__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<gpsx::msg::Gpsx *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Gpsx__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const gpsx::msg::Gpsx *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Gpsx__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Gpsx(full_bounded, 0);
}

static message_type_support_callbacks_t _Gpsx__callbacks = {
  "gpsx::msg",
  "Gpsx",
  _Gpsx__cdr_serialize,
  _Gpsx__cdr_deserialize,
  _Gpsx__get_serialized_size,
  _Gpsx__max_serialized_size
};

static rosidl_message_type_support_t _Gpsx__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Gpsx__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace gpsx

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_gpsx
const rosidl_message_type_support_t *
get_message_type_support_handle<gpsx::msg::Gpsx>()
{
  return &gpsx::msg::typesupport_fastrtps_cpp::_Gpsx__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gpsx, msg, Gpsx)() {
  return &gpsx::msg::typesupport_fastrtps_cpp::_Gpsx__handle;
}

#ifdef __cplusplus
}
#endif
