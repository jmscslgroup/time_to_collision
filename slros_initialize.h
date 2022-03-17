#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block time_to_collision/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_time_to_collision_std_msgs_Float64> Sub_time_to_collision_429;

// For Block time_to_collision/Subscribe4
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_time_to_collision_geometry_msgs_Twist> Sub_time_to_collision_430;

// For Block time_to_collision/Subscribe5
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_time_to_collision_geometry_msgs_Twist> Sub_time_to_collision_431;

// For Block time_to_collision/Subscribe6
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_time_to_collision_std_msgs_Float64> Sub_time_to_collision_476;

// For Block time_to_collision/Subscribe7
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_time_to_collision_std_msgs_Bool> Sub_time_to_collision_481;

// For Block time_to_collision/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_time_to_collision_std_msgs_Float64> Pub_time_to_collision_401;

// For Block time_to_collision/Publish2
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_time_to_collision_geometry_msgs_Twist> Pub_time_to_collision_520;

// For Block time_to_collision/time_to_collision/Get Parameter6
extern SimulinkParameterGetter<real64_T, double> ParamGet_time_to_collision_465;

void slros_node_init(int argc, char** argv);

#endif
