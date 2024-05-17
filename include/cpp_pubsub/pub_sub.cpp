#include "pub_sub.hpp"

MinimalPubSub::MinimalPubSub():Node("minimal_pubsub"), count_(0)
{
    publisher_setup();
    subscriber_setup();
    timer_setup();

}

void MinimalPubSub::publisher_setup()
{
    publisher_ = this->create_publisher<String>("out",10);
}

void MinimalPubSub::subscriber_setup()
{
    subscriber_ = this->create_subscription<String>(
        "in", 10, std::bind(&MinimalPubSub::topic_callback,
        this, std::placeholders::_1)
    );
    
}

void MinimalPubSub::timer_setup()
{
    timer_ = this->create_wall_timer(10ms, 
    std::bind(&MinimalPubSub::timer_callback, 
    this)
    );
}

void MinimalPubSub::timer_callback()
{
    auto message = String();
    
    message.data = "Hello, world! " 
    + std::to_string(count_++);

    RCLCPP_INFO(this->get_logger(), "Publishing: %s"
    ,message.data.c_str());
    publisher_->publish(message);

}

void MinimalPubSub::topic_callback(const String::SharedPtr msg) const
{
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'",msg->data.c_str());
}