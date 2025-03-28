// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/Detection.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__DETECTION__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/srv/detail/detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_Detection_Request_img
{
public:
  Init_Detection_Request_img()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::Detection_Request img(::interfaces::srv::Detection_Request::_img_type arg)
  {
    msg_.img = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::Detection_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::Detection_Request>()
{
  return interfaces::srv::builder::Init_Detection_Request_img();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_Detection_Response_recieved
{
public:
  Init_Detection_Response_recieved()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::Detection_Response recieved(::interfaces::srv::Detection_Response::_recieved_type arg)
  {
    msg_.recieved = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::Detection_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::Detection_Response>()
{
  return interfaces::srv::builder::Init_Detection_Response_recieved();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__DETECTION__BUILDER_HPP_
