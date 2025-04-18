// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:action/Detection.idl
// generated code does not contain a copyright notice
#include "interfaces/action/detail/detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `img`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
interfaces__action__Detection_Goal__init(interfaces__action__Detection_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // img
  if (!sensor_msgs__msg__Image__init(&msg->img)) {
    interfaces__action__Detection_Goal__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__action__Detection_Goal__fini(interfaces__action__Detection_Goal * msg)
{
  if (!msg) {
    return;
  }
  // img
  sensor_msgs__msg__Image__fini(&msg->img);
}

bool
interfaces__action__Detection_Goal__are_equal(const interfaces__action__Detection_Goal * lhs, const interfaces__action__Detection_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // img
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->img), &(rhs->img)))
  {
    return false;
  }
  return true;
}

bool
interfaces__action__Detection_Goal__copy(
  const interfaces__action__Detection_Goal * input,
  interfaces__action__Detection_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // img
  if (!sensor_msgs__msg__Image__copy(
      &(input->img), &(output->img)))
  {
    return false;
  }
  return true;
}

interfaces__action__Detection_Goal *
interfaces__action__Detection_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_Goal * msg = (interfaces__action__Detection_Goal *)allocator.allocate(sizeof(interfaces__action__Detection_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__Detection_Goal));
  bool success = interfaces__action__Detection_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__Detection_Goal__destroy(interfaces__action__Detection_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__Detection_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__Detection_Goal__Sequence__init(interfaces__action__Detection_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_Goal * data = NULL;

  if (size) {
    data = (interfaces__action__Detection_Goal *)allocator.zero_allocate(size, sizeof(interfaces__action__Detection_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__Detection_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__Detection_Goal__fini(&data[i - 1]);
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
interfaces__action__Detection_Goal__Sequence__fini(interfaces__action__Detection_Goal__Sequence * array)
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
      interfaces__action__Detection_Goal__fini(&array->data[i]);
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

interfaces__action__Detection_Goal__Sequence *
interfaces__action__Detection_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_Goal__Sequence * array = (interfaces__action__Detection_Goal__Sequence *)allocator.allocate(sizeof(interfaces__action__Detection_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__Detection_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__Detection_Goal__Sequence__destroy(interfaces__action__Detection_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__Detection_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__Detection_Goal__Sequence__are_equal(const interfaces__action__Detection_Goal__Sequence * lhs, const interfaces__action__Detection_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__Detection_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__Detection_Goal__Sequence__copy(
  const interfaces__action__Detection_Goal__Sequence * input,
  interfaces__action__Detection_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__Detection_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__action__Detection_Goal * data =
      (interfaces__action__Detection_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__Detection_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__action__Detection_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__Detection_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
interfaces__action__Detection_Result__init(interfaces__action__Detection_Result * msg)
{
  if (!msg) {
    return false;
  }
  // recieved
  return true;
}

void
interfaces__action__Detection_Result__fini(interfaces__action__Detection_Result * msg)
{
  if (!msg) {
    return;
  }
  // recieved
}

bool
interfaces__action__Detection_Result__are_equal(const interfaces__action__Detection_Result * lhs, const interfaces__action__Detection_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // recieved
  if (lhs->recieved != rhs->recieved) {
    return false;
  }
  return true;
}

bool
interfaces__action__Detection_Result__copy(
  const interfaces__action__Detection_Result * input,
  interfaces__action__Detection_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // recieved
  output->recieved = input->recieved;
  return true;
}

interfaces__action__Detection_Result *
interfaces__action__Detection_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_Result * msg = (interfaces__action__Detection_Result *)allocator.allocate(sizeof(interfaces__action__Detection_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__Detection_Result));
  bool success = interfaces__action__Detection_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__Detection_Result__destroy(interfaces__action__Detection_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__Detection_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__Detection_Result__Sequence__init(interfaces__action__Detection_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_Result * data = NULL;

  if (size) {
    data = (interfaces__action__Detection_Result *)allocator.zero_allocate(size, sizeof(interfaces__action__Detection_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__Detection_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__Detection_Result__fini(&data[i - 1]);
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
interfaces__action__Detection_Result__Sequence__fini(interfaces__action__Detection_Result__Sequence * array)
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
      interfaces__action__Detection_Result__fini(&array->data[i]);
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

interfaces__action__Detection_Result__Sequence *
interfaces__action__Detection_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_Result__Sequence * array = (interfaces__action__Detection_Result__Sequence *)allocator.allocate(sizeof(interfaces__action__Detection_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__Detection_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__Detection_Result__Sequence__destroy(interfaces__action__Detection_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__Detection_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__Detection_Result__Sequence__are_equal(const interfaces__action__Detection_Result__Sequence * lhs, const interfaces__action__Detection_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__Detection_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__Detection_Result__Sequence__copy(
  const interfaces__action__Detection_Result__Sequence * input,
  interfaces__action__Detection_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__Detection_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__action__Detection_Result * data =
      (interfaces__action__Detection_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__Detection_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__action__Detection_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__Detection_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
interfaces__action__Detection_Feedback__init(interfaces__action__Detection_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
interfaces__action__Detection_Feedback__fini(interfaces__action__Detection_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
interfaces__action__Detection_Feedback__are_equal(const interfaces__action__Detection_Feedback * lhs, const interfaces__action__Detection_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
interfaces__action__Detection_Feedback__copy(
  const interfaces__action__Detection_Feedback * input,
  interfaces__action__Detection_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

interfaces__action__Detection_Feedback *
interfaces__action__Detection_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_Feedback * msg = (interfaces__action__Detection_Feedback *)allocator.allocate(sizeof(interfaces__action__Detection_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__Detection_Feedback));
  bool success = interfaces__action__Detection_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__Detection_Feedback__destroy(interfaces__action__Detection_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__Detection_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__Detection_Feedback__Sequence__init(interfaces__action__Detection_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_Feedback * data = NULL;

  if (size) {
    data = (interfaces__action__Detection_Feedback *)allocator.zero_allocate(size, sizeof(interfaces__action__Detection_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__Detection_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__Detection_Feedback__fini(&data[i - 1]);
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
interfaces__action__Detection_Feedback__Sequence__fini(interfaces__action__Detection_Feedback__Sequence * array)
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
      interfaces__action__Detection_Feedback__fini(&array->data[i]);
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

interfaces__action__Detection_Feedback__Sequence *
interfaces__action__Detection_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_Feedback__Sequence * array = (interfaces__action__Detection_Feedback__Sequence *)allocator.allocate(sizeof(interfaces__action__Detection_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__Detection_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__Detection_Feedback__Sequence__destroy(interfaces__action__Detection_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__Detection_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__Detection_Feedback__Sequence__are_equal(const interfaces__action__Detection_Feedback__Sequence * lhs, const interfaces__action__Detection_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__Detection_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__Detection_Feedback__Sequence__copy(
  const interfaces__action__Detection_Feedback__Sequence * input,
  interfaces__action__Detection_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__Detection_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__action__Detection_Feedback * data =
      (interfaces__action__Detection_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__Detection_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__action__Detection_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__Detection_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "interfaces/action/detail/detection__functions.h"

bool
interfaces__action__Detection_SendGoal_Request__init(interfaces__action__Detection_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    interfaces__action__Detection_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!interfaces__action__Detection_Goal__init(&msg->goal)) {
    interfaces__action__Detection_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__action__Detection_SendGoal_Request__fini(interfaces__action__Detection_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  interfaces__action__Detection_Goal__fini(&msg->goal);
}

bool
interfaces__action__Detection_SendGoal_Request__are_equal(const interfaces__action__Detection_SendGoal_Request * lhs, const interfaces__action__Detection_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!interfaces__action__Detection_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
interfaces__action__Detection_SendGoal_Request__copy(
  const interfaces__action__Detection_SendGoal_Request * input,
  interfaces__action__Detection_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!interfaces__action__Detection_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

interfaces__action__Detection_SendGoal_Request *
interfaces__action__Detection_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_SendGoal_Request * msg = (interfaces__action__Detection_SendGoal_Request *)allocator.allocate(sizeof(interfaces__action__Detection_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__Detection_SendGoal_Request));
  bool success = interfaces__action__Detection_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__Detection_SendGoal_Request__destroy(interfaces__action__Detection_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__Detection_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__Detection_SendGoal_Request__Sequence__init(interfaces__action__Detection_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_SendGoal_Request * data = NULL;

  if (size) {
    data = (interfaces__action__Detection_SendGoal_Request *)allocator.zero_allocate(size, sizeof(interfaces__action__Detection_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__Detection_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__Detection_SendGoal_Request__fini(&data[i - 1]);
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
interfaces__action__Detection_SendGoal_Request__Sequence__fini(interfaces__action__Detection_SendGoal_Request__Sequence * array)
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
      interfaces__action__Detection_SendGoal_Request__fini(&array->data[i]);
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

interfaces__action__Detection_SendGoal_Request__Sequence *
interfaces__action__Detection_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_SendGoal_Request__Sequence * array = (interfaces__action__Detection_SendGoal_Request__Sequence *)allocator.allocate(sizeof(interfaces__action__Detection_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__Detection_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__Detection_SendGoal_Request__Sequence__destroy(interfaces__action__Detection_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__Detection_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__Detection_SendGoal_Request__Sequence__are_equal(const interfaces__action__Detection_SendGoal_Request__Sequence * lhs, const interfaces__action__Detection_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__Detection_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__Detection_SendGoal_Request__Sequence__copy(
  const interfaces__action__Detection_SendGoal_Request__Sequence * input,
  interfaces__action__Detection_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__Detection_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__action__Detection_SendGoal_Request * data =
      (interfaces__action__Detection_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__Detection_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__action__Detection_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__Detection_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
interfaces__action__Detection_SendGoal_Response__init(interfaces__action__Detection_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    interfaces__action__Detection_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__action__Detection_SendGoal_Response__fini(interfaces__action__Detection_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
interfaces__action__Detection_SendGoal_Response__are_equal(const interfaces__action__Detection_SendGoal_Response * lhs, const interfaces__action__Detection_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
interfaces__action__Detection_SendGoal_Response__copy(
  const interfaces__action__Detection_SendGoal_Response * input,
  interfaces__action__Detection_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

interfaces__action__Detection_SendGoal_Response *
interfaces__action__Detection_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_SendGoal_Response * msg = (interfaces__action__Detection_SendGoal_Response *)allocator.allocate(sizeof(interfaces__action__Detection_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__Detection_SendGoal_Response));
  bool success = interfaces__action__Detection_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__Detection_SendGoal_Response__destroy(interfaces__action__Detection_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__Detection_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__Detection_SendGoal_Response__Sequence__init(interfaces__action__Detection_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_SendGoal_Response * data = NULL;

  if (size) {
    data = (interfaces__action__Detection_SendGoal_Response *)allocator.zero_allocate(size, sizeof(interfaces__action__Detection_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__Detection_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__Detection_SendGoal_Response__fini(&data[i - 1]);
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
interfaces__action__Detection_SendGoal_Response__Sequence__fini(interfaces__action__Detection_SendGoal_Response__Sequence * array)
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
      interfaces__action__Detection_SendGoal_Response__fini(&array->data[i]);
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

interfaces__action__Detection_SendGoal_Response__Sequence *
interfaces__action__Detection_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_SendGoal_Response__Sequence * array = (interfaces__action__Detection_SendGoal_Response__Sequence *)allocator.allocate(sizeof(interfaces__action__Detection_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__Detection_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__Detection_SendGoal_Response__Sequence__destroy(interfaces__action__Detection_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__Detection_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__Detection_SendGoal_Response__Sequence__are_equal(const interfaces__action__Detection_SendGoal_Response__Sequence * lhs, const interfaces__action__Detection_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__Detection_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__Detection_SendGoal_Response__Sequence__copy(
  const interfaces__action__Detection_SendGoal_Response__Sequence * input,
  interfaces__action__Detection_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__Detection_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__action__Detection_SendGoal_Response * data =
      (interfaces__action__Detection_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__Detection_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__action__Detection_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__Detection_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
interfaces__action__Detection_GetResult_Request__init(interfaces__action__Detection_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    interfaces__action__Detection_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__action__Detection_GetResult_Request__fini(interfaces__action__Detection_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
interfaces__action__Detection_GetResult_Request__are_equal(const interfaces__action__Detection_GetResult_Request * lhs, const interfaces__action__Detection_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
interfaces__action__Detection_GetResult_Request__copy(
  const interfaces__action__Detection_GetResult_Request * input,
  interfaces__action__Detection_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

interfaces__action__Detection_GetResult_Request *
interfaces__action__Detection_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_GetResult_Request * msg = (interfaces__action__Detection_GetResult_Request *)allocator.allocate(sizeof(interfaces__action__Detection_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__Detection_GetResult_Request));
  bool success = interfaces__action__Detection_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__Detection_GetResult_Request__destroy(interfaces__action__Detection_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__Detection_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__Detection_GetResult_Request__Sequence__init(interfaces__action__Detection_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_GetResult_Request * data = NULL;

  if (size) {
    data = (interfaces__action__Detection_GetResult_Request *)allocator.zero_allocate(size, sizeof(interfaces__action__Detection_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__Detection_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__Detection_GetResult_Request__fini(&data[i - 1]);
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
interfaces__action__Detection_GetResult_Request__Sequence__fini(interfaces__action__Detection_GetResult_Request__Sequence * array)
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
      interfaces__action__Detection_GetResult_Request__fini(&array->data[i]);
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

interfaces__action__Detection_GetResult_Request__Sequence *
interfaces__action__Detection_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_GetResult_Request__Sequence * array = (interfaces__action__Detection_GetResult_Request__Sequence *)allocator.allocate(sizeof(interfaces__action__Detection_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__Detection_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__Detection_GetResult_Request__Sequence__destroy(interfaces__action__Detection_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__Detection_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__Detection_GetResult_Request__Sequence__are_equal(const interfaces__action__Detection_GetResult_Request__Sequence * lhs, const interfaces__action__Detection_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__Detection_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__Detection_GetResult_Request__Sequence__copy(
  const interfaces__action__Detection_GetResult_Request__Sequence * input,
  interfaces__action__Detection_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__Detection_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__action__Detection_GetResult_Request * data =
      (interfaces__action__Detection_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__Detection_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__action__Detection_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__Detection_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "interfaces/action/detail/detection__functions.h"

bool
interfaces__action__Detection_GetResult_Response__init(interfaces__action__Detection_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!interfaces__action__Detection_Result__init(&msg->result)) {
    interfaces__action__Detection_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__action__Detection_GetResult_Response__fini(interfaces__action__Detection_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  interfaces__action__Detection_Result__fini(&msg->result);
}

bool
interfaces__action__Detection_GetResult_Response__are_equal(const interfaces__action__Detection_GetResult_Response * lhs, const interfaces__action__Detection_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!interfaces__action__Detection_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
interfaces__action__Detection_GetResult_Response__copy(
  const interfaces__action__Detection_GetResult_Response * input,
  interfaces__action__Detection_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!interfaces__action__Detection_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

interfaces__action__Detection_GetResult_Response *
interfaces__action__Detection_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_GetResult_Response * msg = (interfaces__action__Detection_GetResult_Response *)allocator.allocate(sizeof(interfaces__action__Detection_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__Detection_GetResult_Response));
  bool success = interfaces__action__Detection_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__Detection_GetResult_Response__destroy(interfaces__action__Detection_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__Detection_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__Detection_GetResult_Response__Sequence__init(interfaces__action__Detection_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_GetResult_Response * data = NULL;

  if (size) {
    data = (interfaces__action__Detection_GetResult_Response *)allocator.zero_allocate(size, sizeof(interfaces__action__Detection_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__Detection_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__Detection_GetResult_Response__fini(&data[i - 1]);
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
interfaces__action__Detection_GetResult_Response__Sequence__fini(interfaces__action__Detection_GetResult_Response__Sequence * array)
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
      interfaces__action__Detection_GetResult_Response__fini(&array->data[i]);
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

interfaces__action__Detection_GetResult_Response__Sequence *
interfaces__action__Detection_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_GetResult_Response__Sequence * array = (interfaces__action__Detection_GetResult_Response__Sequence *)allocator.allocate(sizeof(interfaces__action__Detection_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__Detection_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__Detection_GetResult_Response__Sequence__destroy(interfaces__action__Detection_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__Detection_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__Detection_GetResult_Response__Sequence__are_equal(const interfaces__action__Detection_GetResult_Response__Sequence * lhs, const interfaces__action__Detection_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__Detection_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__Detection_GetResult_Response__Sequence__copy(
  const interfaces__action__Detection_GetResult_Response__Sequence * input,
  interfaces__action__Detection_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__Detection_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__action__Detection_GetResult_Response * data =
      (interfaces__action__Detection_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__Detection_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__action__Detection_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__Detection_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "interfaces/action/detail/detection__functions.h"

bool
interfaces__action__Detection_FeedbackMessage__init(interfaces__action__Detection_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    interfaces__action__Detection_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!interfaces__action__Detection_Feedback__init(&msg->feedback)) {
    interfaces__action__Detection_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
interfaces__action__Detection_FeedbackMessage__fini(interfaces__action__Detection_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  interfaces__action__Detection_Feedback__fini(&msg->feedback);
}

bool
interfaces__action__Detection_FeedbackMessage__are_equal(const interfaces__action__Detection_FeedbackMessage * lhs, const interfaces__action__Detection_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!interfaces__action__Detection_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
interfaces__action__Detection_FeedbackMessage__copy(
  const interfaces__action__Detection_FeedbackMessage * input,
  interfaces__action__Detection_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!interfaces__action__Detection_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

interfaces__action__Detection_FeedbackMessage *
interfaces__action__Detection_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_FeedbackMessage * msg = (interfaces__action__Detection_FeedbackMessage *)allocator.allocate(sizeof(interfaces__action__Detection_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__action__Detection_FeedbackMessage));
  bool success = interfaces__action__Detection_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__action__Detection_FeedbackMessage__destroy(interfaces__action__Detection_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__action__Detection_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__action__Detection_FeedbackMessage__Sequence__init(interfaces__action__Detection_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_FeedbackMessage * data = NULL;

  if (size) {
    data = (interfaces__action__Detection_FeedbackMessage *)allocator.zero_allocate(size, sizeof(interfaces__action__Detection_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__action__Detection_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__action__Detection_FeedbackMessage__fini(&data[i - 1]);
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
interfaces__action__Detection_FeedbackMessage__Sequence__fini(interfaces__action__Detection_FeedbackMessage__Sequence * array)
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
      interfaces__action__Detection_FeedbackMessage__fini(&array->data[i]);
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

interfaces__action__Detection_FeedbackMessage__Sequence *
interfaces__action__Detection_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__action__Detection_FeedbackMessage__Sequence * array = (interfaces__action__Detection_FeedbackMessage__Sequence *)allocator.allocate(sizeof(interfaces__action__Detection_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__action__Detection_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__action__Detection_FeedbackMessage__Sequence__destroy(interfaces__action__Detection_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__action__Detection_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__action__Detection_FeedbackMessage__Sequence__are_equal(const interfaces__action__Detection_FeedbackMessage__Sequence * lhs, const interfaces__action__Detection_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__action__Detection_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__action__Detection_FeedbackMessage__Sequence__copy(
  const interfaces__action__Detection_FeedbackMessage__Sequence * input,
  interfaces__action__Detection_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__action__Detection_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__action__Detection_FeedbackMessage * data =
      (interfaces__action__Detection_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__action__Detection_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__action__Detection_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__action__Detection_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
