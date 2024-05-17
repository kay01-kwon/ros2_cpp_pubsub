# ros2_cpp_pubsub

How to build the pacakge
```
colcon build
```

Node name: pub_sub_node

Topic to publish: /out

Topic to subscribe: /in

How to run the node.

```
ros2 run cpp_pubsub pub_sub_node
```

Monitor the topic published by the node.

```
ros2 topic echo /out
```

How to publish topic to the node.

```
ros2 topic pub /in std_msgs/msg/String "{data: '10'}" -r 100
```