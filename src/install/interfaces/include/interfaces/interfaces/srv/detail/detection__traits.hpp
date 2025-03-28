// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/Detection.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__DETECTION__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/srv/detail/detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'img'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Detection_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: img
  {
    out << "img: ";
    to_flow_style_yaml(msg.img, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Detection_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: img
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "img:\n";
    to_block_style_yaml(msg.img, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Detection_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::Detection_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::Detection_Request & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::Detection_Request>()
{
  return "interfaces::srv::Detection_Request";
}

template<>
inline const char * name<interfaces::srv::Detection_Request>()
{
  return "interfaces/srv/Detection_Request";
}

template<>
struct has_fixed_size<interfaces::srv::Detection_Request>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value> {};

template<>
struct has_bounded_size<interfaces::srv::Detection_Request>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value> {};

template<>
struct is_message<interfaces::srv::Detection_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Detection_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: recieved
  {
    out << "recieved: ";
    rosidl_generator_traits::value_to_yaml(msg.recieved, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Detection_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: recieved
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "recieved: ";
    rosidl_generator_traits::value_to_yaml(msg.recieved, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Detection_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::Detection_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::Detection_Response & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::Detection_Response>()
{
  return "interfaces::srv::Detection_Response";
}

template<>
inline const char * name<interfaces::srv::Detection_Response>()
{
  return "interfaces/srv/Detection_Response";
}

template<>
struct has_fixed_size<interfaces::srv::Detection_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::Detection_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::Detection_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::Detection>()
{
  return "interfaces::srv::Detection";
}

template<>
inline const char * name<interfaces::srv::Detection>()
{
  return "interfaces/srv/Detection";
}

template<>
struct has_fixed_size<interfaces::srv::Detection>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::Detection_Request>::value &&
    has_fixed_size<interfaces::srv::Detection_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::Detection>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::Detection_Request>::value &&
    has_bounded_size<interfaces::srv::Detection_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::Detection>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::Detection_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::Detection_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__DETECTION__TRAITS_HPP_
