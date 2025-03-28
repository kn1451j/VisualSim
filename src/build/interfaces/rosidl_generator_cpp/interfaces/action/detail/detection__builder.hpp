// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:action/Detection.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__ACTION__DETAIL__DETECTION__BUILDER_HPP_
#define INTERFACES__ACTION__DETAIL__DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/action/detail/detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_Goal_img
{
public:
  Init_Detection_Goal_img()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::Detection_Goal img(::interfaces::action::Detection_Goal::_img_type arg)
  {
    msg_.img = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Detection_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Detection_Goal>()
{
  return interfaces::action::builder::Init_Detection_Goal_img();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_Result_recieved
{
public:
  Init_Detection_Result_recieved()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::Detection_Result recieved(::interfaces::action::Detection_Result::_recieved_type arg)
  {
    msg_.recieved = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Detection_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Detection_Result>()
{
  return interfaces::action::builder::Init_Detection_Result_recieved();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{


}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Detection_Feedback>()
{
  return ::interfaces::action::Detection_Feedback(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_SendGoal_Request_goal
{
public:
  explicit Init_Detection_SendGoal_Request_goal(::interfaces::action::Detection_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Detection_SendGoal_Request goal(::interfaces::action::Detection_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Detection_SendGoal_Request msg_;
};

class Init_Detection_SendGoal_Request_goal_id
{
public:
  Init_Detection_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection_SendGoal_Request_goal goal_id(::interfaces::action::Detection_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Detection_SendGoal_Request_goal(msg_);
  }

private:
  ::interfaces::action::Detection_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Detection_SendGoal_Request>()
{
  return interfaces::action::builder::Init_Detection_SendGoal_Request_goal_id();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_SendGoal_Response_stamp
{
public:
  explicit Init_Detection_SendGoal_Response_stamp(::interfaces::action::Detection_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Detection_SendGoal_Response stamp(::interfaces::action::Detection_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Detection_SendGoal_Response msg_;
};

class Init_Detection_SendGoal_Response_accepted
{
public:
  Init_Detection_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection_SendGoal_Response_stamp accepted(::interfaces::action::Detection_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Detection_SendGoal_Response_stamp(msg_);
  }

private:
  ::interfaces::action::Detection_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Detection_SendGoal_Response>()
{
  return interfaces::action::builder::Init_Detection_SendGoal_Response_accepted();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_GetResult_Request_goal_id
{
public:
  Init_Detection_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::Detection_GetResult_Request goal_id(::interfaces::action::Detection_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Detection_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Detection_GetResult_Request>()
{
  return interfaces::action::builder::Init_Detection_GetResult_Request_goal_id();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_GetResult_Response_result
{
public:
  explicit Init_Detection_GetResult_Response_result(::interfaces::action::Detection_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Detection_GetResult_Response result(::interfaces::action::Detection_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Detection_GetResult_Response msg_;
};

class Init_Detection_GetResult_Response_status
{
public:
  Init_Detection_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection_GetResult_Response_result status(::interfaces::action::Detection_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Detection_GetResult_Response_result(msg_);
  }

private:
  ::interfaces::action::Detection_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Detection_GetResult_Response>()
{
  return interfaces::action::builder::Init_Detection_GetResult_Response_status();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_FeedbackMessage_feedback
{
public:
  explicit Init_Detection_FeedbackMessage_feedback(::interfaces::action::Detection_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Detection_FeedbackMessage feedback(::interfaces::action::Detection_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Detection_FeedbackMessage msg_;
};

class Init_Detection_FeedbackMessage_goal_id
{
public:
  Init_Detection_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection_FeedbackMessage_feedback goal_id(::interfaces::action::Detection_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Detection_FeedbackMessage_feedback(msg_);
  }

private:
  ::interfaces::action::Detection_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Detection_FeedbackMessage>()
{
  return interfaces::action::builder::Init_Detection_FeedbackMessage_goal_id();
}

}  // namespace interfaces

#endif  // INTERFACES__ACTION__DETAIL__DETECTION__BUILDER_HPP_
