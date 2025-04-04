// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:srv/Detection.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__DETECTION__STRUCT_H_
#define INTERFACES__SRV__DETAIL__DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'img'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in srv/Detection in the package interfaces.
typedef struct interfaces__srv__Detection_Request
{
  sensor_msgs__msg__Image img;
} interfaces__srv__Detection_Request;

// Struct for a sequence of interfaces__srv__Detection_Request.
typedef struct interfaces__srv__Detection_Request__Sequence
{
  interfaces__srv__Detection_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__Detection_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Detection in the package interfaces.
typedef struct interfaces__srv__Detection_Response
{
  bool recieved;
} interfaces__srv__Detection_Response;

// Struct for a sequence of interfaces__srv__Detection_Response.
typedef struct interfaces__srv__Detection_Response__Sequence
{
  interfaces__srv__Detection_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__Detection_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__SRV__DETAIL__DETECTION__STRUCT_H_
