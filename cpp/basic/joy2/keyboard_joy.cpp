// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-

#include <stdio.h>
#include <memory>
#include <memory.h>
#include <string>
#include "getch.h"
// for ros
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "sensor_msgs/Joy.h"

namespace std {
  using namespace tr1; // std::tr1:: => std::
}

class keyboard_joy : public GetCharacter {
public:
  keyboard_joy(int tm_sec, int tm_usec);
  ~keyboard_joy();
  void read_sample();
protected:
  //char* key;
  std::vector<char> key;
  const std::vector<char> KEYCODE_U;
  const std::vector<char> KEYCODE_D;
  const std::vector<char> KEYCODE_R;
  const std::vector<char> KEYCODE_L;
};
keyboard_joy::keyboard_joy(int tm_sec=3, int tm_usec=0)
  :GetCharacter(tm_sec, tm_usec),
   key{0,0,0},
   KEYCODE_U{0x1b, 0x5b, 0x41},
   KEYCODE_D{0x1b, 0x5b, 0x42},
   KEYCODE_R{0x1b, 0x5b, 0x43},
   KEYCODE_L{0x1b, 0x5b, 0x44}
{
  //key = NULL;
};
keyboard_joy::~keyboard_joy() {
  GetCharacter::resetTermios();
};
void keyboard_joy::read_sample() {
  char* key_ptr;
  GetCharacter::read(&key_ptr, 3);
  for (int i=0; i < key.size(); i++) {
    key[i] = key_ptr[i];
  }
  //const std::vector<char> key_vec(key, key+3);
  if ( key == KEYCODE_U) {
    printf("UP!\n");
  } else if ( key == KEYCODE_D) {
    printf("DOWN!\n");
  } else if ( key == KEYCODE_R) {
    printf("RIGHT!\n");
  } else if ( key == KEYCODE_L) {
    printf("LEFT!\n");
  } else {
    printf("key_ptr: %d/%d/%d\n", key_ptr[0], key_ptr[1], key_ptr[2]);
    printf("key_: %d/%d/%d (%d)\n", key[0], key[1], key[2], (int) key.size());
  }
  // printf("key_vec: %d/%d/%d (%d)\n", key_vec[0], key_vec[1], key_vec[2], (int) key_vec.size());
  // printf("key:     %d/%d/%d\n", key[0], key[1], key[2]);
  // printf("UP:      %d/%d/%d (%d)\n", KEYCODE_U[0], KEYCODE_U[1], KEYCODE_U[2], (int) KEYCODE_U.size());
};


class ros_keyboard_joy : public keyboard_joy {
private:
  ros::NodeHandle nh;
  ros::Publisher chatter_pub;
  ros::Publisher joy_pub;
  ros::Rate loop_rate;
  sensor_msgs::Joy msg;
public:
  ros_keyboard_joy(int tm_sec, int tm_usec);
  bool read_key();
  void set_axes(sensor_msgs::Joy &joy_msg);
  void proc_one_sample();
  void proc_one();
  int loop;
};
ros_keyboard_joy::ros_keyboard_joy(int tm_sec=3, int tm_usec=0)
  : keyboard_joy(tm_sec, tm_usec),
    nh(),
    chatter_pub(nh.advertise<std_msgs::String>("chatter", 1000)),
    joy_pub(nh.advertise<sensor_msgs::Joy>("joy", 1000)),
    loop_rate(1),
    loop(0)
{};
void ros_keyboard_joy::proc_one_sample() {
  std_msgs::String msg;
  std::stringstream ss;
  ss << "hello world " << loop;
  msg.data = ss.str();
  ROS_INFO("%s", msg.data.c_str());
  chatter_pub.publish(msg);
  //ros::spinOnce();
  loop_rate.sleep();
  ++loop;
};
void ros_keyboard_joy::proc_one() {
  read_key();
  sensor_msgs::Joy joy_msg;
  joy_msg.header.stamp = ros::Time::now();
  //joy_msg.axes.push_back((double) 0.5);
  set_axes(joy_msg);
  joy_pub.publish(joy_msg);
  ros::spinOnce();
  loop_rate.sleep();
  ++loop;
};
bool ros_keyboard_joy::read_key() {
  bool read_success;
  char* key_ptr;
  read_success = GetCharacter::read(&key_ptr, 3);
  for (int i=0; i < key.size(); i++) {
    key[i] = key_ptr[i];
  }
  return read_success;
};
void ros_keyboard_joy::set_axes(sensor_msgs::Joy &joy_msg) {
  std::vector<double> tmp_axes(2);
  if ( key == KEYCODE_U) {
    //printf("UP!\n");
    tmp_axes[0]=1;
  } else if ( key == KEYCODE_D) {
    //printf("DOWN!\n");
    tmp_axes[0]=-1;
  } else if ( key == KEYCODE_R) {
    //printf("RIGHT!\n");
    tmp_axes[1]=-1;
  } else if ( key == KEYCODE_L) {
    //printf("LEFT!\n");
    tmp_axes[1]=1;
  } else {
    //printf("key: %d/%d/%d (%d)\n", key[0], key[1], key[2], (int) key.size());
  }
  ROS_INFO("%f,%f", tmp_axes[0], tmp_axes[1]);
  joy_msg.axes.clear();
  for (int i=0; i < tmp_axes.size(); ++i) {
    joy_msg.axes.push_back(tmp_axes[i]);
  }
};


int main(int argc, char **argv)
{
  ros::init(argc, argv, "keyboard_joy");
  std::shared_ptr<ros_keyboard_joy> kj(new ros_keyboard_joy(1,0));
  //std::shared_ptr<keyboard_joy> kj(new keyboard_joy(3,0));
  //kj->read_sample();
  kj -> proc_one_sample();
  while (ros::ok()) {
    kj -> proc_one();
  }
};
