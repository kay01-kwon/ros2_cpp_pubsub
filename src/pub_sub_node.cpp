#include "pub_sub.hpp"

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPubSub>());
    rclcpp::shutdown();

    return 0;
}