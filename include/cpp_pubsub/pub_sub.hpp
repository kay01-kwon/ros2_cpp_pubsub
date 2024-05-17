#ifndef PUB_SUB_HPP_
#define PUB_SUB_HPP_

#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std_msgs::msg::String;

class MinimalPubSub : public rclcpp::Node
{
    public:
        
        MinimalPubSub();

        void publisher_setup();

        void subscriber_setup();

        void timer_setup();


    private:

        void timer_callback();

        void topic_callback(const String::SharedPtr msg) const;

        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<String>::SharedPtr publisher_;
        rclcpp::Subscription<String>::SharedPtr subscriber_;
        size_t count_;
};

#endif