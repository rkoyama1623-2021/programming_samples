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
  void read_key();
  void set_axes();
protected:
  //char* key;
  std::vector<char> key;
  bool read_success;
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
void keyboard_joy::read_key() {
  char* key_ptr;
  for (int i=0; i<key.size(); i++) {
    key[i]=0;
  }
  GetCharacter::read(&read_success, &key_ptr, 3);
  if ( read_success ) {
    for (int i=0; i < key.size(); i++) {
      key[i] = key_ptr[i];
    }
  }
};
void keyboard_joy::set_axes() {
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
    printf("key: %d/%d/%d (%d)\n", key[0], key[1], key[2], (int) key.size());
  }
  // display
  printf("axes: ");
  for (int i=0; i<tmp_axes.size(); i++) {
    printf("%f ", tmp_axes[i]);
  }
  printf("\n");
};
void keyboard_joy::read_sample() {
  printf("\n\nplease enter key.\n");
  read_key();
  set_axes();
};

class ros_keyboard_joy : public keyboard_joy {
private:
  ros::NodeHandle nh;
  ros::Publisher chatter_pub;
  ros::Publisher joy_pub;
  ros::Rate loop_rate;
  sensor_msgs::Joy msg;
public:
  ros_keyboard_joy(int tm_sec, int tm_usec, int ros_rate);
  void set_axes(sensor_msgs::Joy &joy_msg);
  void proc_one();
  int loop;
};
ros_keyboard_joy::ros_keyboard_joy(int tm_sec=1, int tm_usec=0, int ros_rate=1)
  : keyboard_joy(tm_sec, tm_usec),
    nh(),
    joy_pub(nh.advertise<sensor_msgs::Joy>("joy", 1000)),
    loop_rate(ros_rate),
    loop(0)
{};
void ros_keyboard_joy::proc_one() {
  sensor_msgs::Joy joy_msg;
  read_key();
  joy_msg.header.stamp = ros::Time::now();
  //joy_msg.axes.push_back((double) 0.5);
  set_axes(joy_msg);
  //ros::spinOnce();
  loop_rate.sleep();
  joy_pub.publish(joy_msg);
  ++loop;
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
  // std::shared_ptr<keyboard_joy> kj(new keyboard_joy(0,100000));
  // while (ros::ok()) {
  //   kj->read_sample();
  // }

  std::shared_ptr<ros_keyboard_joy> kj(new ros_keyboard_joy(0,100000,10));
  while (ros::ok()) {
    kj -> proc_one();
  }
};




/*
http://askubuntu.com/questions/350026/why-there-is-a-delay-between-when-a-key-is-pressed-and-when-it-is-accepted
*/
