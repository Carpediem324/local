// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gpsx:msg/Gpsx.idl
// generated code does not contain a copyright notice
#include "gpsx/msg/detail/gpsx__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
gpsx__msg__Gpsx__init(gpsx__msg__Gpsx * msg)
{
  if (!msg) {
    return false;
  }
  // longitude
  // latitude
  // altitude
  // ground_speed
  // satellites
  // mode_indicator
  // separation
  // true_course
  // true_course_magnetic
  // dilution
  // utc_time
  return true;
}

void
gpsx__msg__Gpsx__fini(gpsx__msg__Gpsx * msg)
{
  if (!msg) {
    return;
  }
  // longitude
  // latitude
  // altitude
  // ground_speed
  // satellites
  // mode_indicator
  // separation
  // true_course
  // true_course_magnetic
  // dilution
  // utc_time
}

bool
gpsx__msg__Gpsx__are_equal(const gpsx__msg__Gpsx * lhs, const gpsx__msg__Gpsx * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // longitude
  if (lhs->longitude != rhs->longitude) {
    return false;
  }
  // latitude
  if (lhs->latitude != rhs->latitude) {
    return false;
  }
  // altitude
  if (lhs->altitude != rhs->altitude) {
    return false;
  }
  // ground_speed
  if (lhs->ground_speed != rhs->ground_speed) {
    return false;
  }
  // satellites
  if (lhs->satellites != rhs->satellites) {
    return false;
  }
  // mode_indicator
  if (lhs->mode_indicator != rhs->mode_indicator) {
    return false;
  }
  // separation
  if (lhs->separation != rhs->separation) {
    return false;
  }
  // true_course
  if (lhs->true_course != rhs->true_course) {
    return false;
  }
  // true_course_magnetic
  if (lhs->true_course_magnetic != rhs->true_course_magnetic) {
    return false;
  }
  // dilution
  if (lhs->dilution != rhs->dilution) {
    return false;
  }
  // utc_time
  if (lhs->utc_time != rhs->utc_time) {
    return false;
  }
  return true;
}

bool
gpsx__msg__Gpsx__copy(
  const gpsx__msg__Gpsx * input,
  gpsx__msg__Gpsx * output)
{
  if (!input || !output) {
    return false;
  }
  // longitude
  output->longitude = input->longitude;
  // latitude
  output->latitude = input->latitude;
  // altitude
  output->altitude = input->altitude;
  // ground_speed
  output->ground_speed = input->ground_speed;
  // satellites
  output->satellites = input->satellites;
  // mode_indicator
  output->mode_indicator = input->mode_indicator;
  // separation
  output->separation = input->separation;
  // true_course
  output->true_course = input->true_course;
  // true_course_magnetic
  output->true_course_magnetic = input->true_course_magnetic;
  // dilution
  output->dilution = input->dilution;
  // utc_time
  output->utc_time = input->utc_time;
  return true;
}

gpsx__msg__Gpsx *
gpsx__msg__Gpsx__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gpsx__msg__Gpsx * msg = (gpsx__msg__Gpsx *)allocator.allocate(sizeof(gpsx__msg__Gpsx), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gpsx__msg__Gpsx));
  bool success = gpsx__msg__Gpsx__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gpsx__msg__Gpsx__destroy(gpsx__msg__Gpsx * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gpsx__msg__Gpsx__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gpsx__msg__Gpsx__Sequence__init(gpsx__msg__Gpsx__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gpsx__msg__Gpsx * data = NULL;

  if (size) {
    data = (gpsx__msg__Gpsx *)allocator.zero_allocate(size, sizeof(gpsx__msg__Gpsx), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gpsx__msg__Gpsx__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gpsx__msg__Gpsx__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
gpsx__msg__Gpsx__Sequence__fini(gpsx__msg__Gpsx__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      gpsx__msg__Gpsx__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

gpsx__msg__Gpsx__Sequence *
gpsx__msg__Gpsx__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gpsx__msg__Gpsx__Sequence * array = (gpsx__msg__Gpsx__Sequence *)allocator.allocate(sizeof(gpsx__msg__Gpsx__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gpsx__msg__Gpsx__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gpsx__msg__Gpsx__Sequence__destroy(gpsx__msg__Gpsx__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gpsx__msg__Gpsx__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gpsx__msg__Gpsx__Sequence__are_equal(const gpsx__msg__Gpsx__Sequence * lhs, const gpsx__msg__Gpsx__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gpsx__msg__Gpsx__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gpsx__msg__Gpsx__Sequence__copy(
  const gpsx__msg__Gpsx__Sequence * input,
  gpsx__msg__Gpsx__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gpsx__msg__Gpsx);
    gpsx__msg__Gpsx * data =
      (gpsx__msg__Gpsx *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gpsx__msg__Gpsx__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          gpsx__msg__Gpsx__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gpsx__msg__Gpsx__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
