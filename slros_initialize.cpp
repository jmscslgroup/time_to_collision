#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "time_to_collision";

// For Block time_to_collision/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_time_to_collision_std_msgs_Float64> Sub_time_to_collision_429;

// For Block time_to_collision/Subscribe4
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_time_to_collision_geometry_msgs_Twist> Sub_time_to_collision_430;

// For Block time_to_collision/Subscribe5
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_time_to_collision_geometry_msgs_Twist> Sub_time_to_collision_431;

// For Block time_to_collision/Subscribe6
SimulinkSubscriber<std_msgs::Float64, SL_Bus_time_to_collision_std_msgs_Float64> Sub_time_to_collision_476;

// For Block time_to_collision/Subscribe7
SimulinkSubscriber<std_msgs::Bool, SL_Bus_time_to_collision_std_msgs_Bool> Sub_time_to_collision_481;

// For Block time_to_collision/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_time_to_collision_std_msgs_Float64> Pub_time_to_collision_401;

// For Block time_to_collision/Publish2
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_time_to_collision_geometry_msgs_Twist> Pub_time_to_collision_520;

// For Block time_to_collision/time_to_collision/Get Parameter6
SimulinkParameterGetter<real64_T, double> ParamGet_time_to_collision_465;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

