cmake_minimum_required(VERSION 3.5)
project(cpp_pubsub)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(
  include/cpp_pubsub
  ${rclcpp_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
)

add_executable(pub_sub_node 
include/cpp_pubsub/pub_sub.cpp
src/pub_sub_node.cpp)

ament_target_dependencies(pub_sub_node rclcpp std_msgs)

install(TARGETS
  pub_sub_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
