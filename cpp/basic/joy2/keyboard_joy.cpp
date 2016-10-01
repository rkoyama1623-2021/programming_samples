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

namespace std {
  using namespace tr1; // std::tr1:: => std::
}

class keyboard_joy : public GetCharacter {
public:
  keyboard_joy(int tm_sec, int tm_usec);
  ~keyboard_joy();
  void read_sample();
protected:
  char* key;
  const std::vector<char> KEYCODE_U;
  const std::vector<char> KEYCODE_D;
  const std::vector<char> KEYCODE_R;
  const std::vector<char> KEYCODE_L;
};
keyboard_joy::keyboard_joy(int tm_sec=3, int tm_usec=0)
  :GetCharacter(tm_sec, tm_usec),
   KEYCODE_U{0x1b, 0x5b, 0x41},
   KEYCODE_D{0x1b, 0x5b, 0x42},
   KEYCODE_R{0x1b, 0x5b, 0x43},
   KEYCODE_L{0x1b, 0x5b, 0x44}
{
  key = NULL;
};
keyboard_joy::~keyboard_joy() {
  GetCharacter::resetTermios();
};
void keyboard_joy::read_sample() {
  GetCharacter::read(&key, 3);
  const std::vector<char> key_vec(key, key+3);
  if ( key_vec == KEYCODE_U) {
    printf("UP!\n");
  } else if ( key_vec == KEYCODE_D) {
    printf("DOWN!\n");
  } else if ( key_vec == KEYCODE_R) {
    printf("RIGHT!\n");
  } else if ( key_vec == KEYCODE_L) {
    printf("LEFT!\n");
  } else {
    printf("key_vec: %d/%d/%d (%d)\n", key_vec[0], key_vec[1], key_vec[2], (int) key_vec.size());
  }
  // printf("key_vec: %d/%d/%d (%d)\n", key_vec[0], key_vec[1], key_vec[2], (int) key_vec.size());
  // printf("key:     %d/%d/%d\n", key[0], key[1], key[2]);
  // printf("UP:      %d/%d/%d (%d)\n", KEYCODE_U[0], KEYCODE_U[1], KEYCODE_U[2], (int) KEYCODE_U.size());
};


class ros_keyboard_joy : public keyboard_joy {
private:
  ros::NodeHandle nh;
  ros::Publisher chatter_pub;
  ros::Rate loop_rate;
public:
  ros_keyboard_joy(int tm_sec, int tm_usec);
  void read_sample();
  void proc_one();
  int loop;
};
ros_keyboard_joy::ros_keyboard_joy(int tm_sec=3, int tm_usec=0)
  : keyboard_joy(tm_sec, tm_usec),
    nh(),
    chatter_pub(nh.advertise<std_msgs::String>("chatter", 1000)),
    loop_rate(10),
    loop(0)
{};
void ros_keyboard_joy::proc_one() {
  std_msgs::String msg;
  std::stringstream ss;
  ss << "hello world " << loop;
  msg.data = ss.str();
  ROS_INFO("%s", msg.data.c_str());
  chatter_pub.publish(msg);
  ros::spinOnce();
  loop_rate.sleep();
  ++loop;
};
void ros_keyboard_joy::read_sample() {
  read(&key, 3);
  const std::vector<char> key_vec(key, key+3);
  if ( key_vec == KEYCODE_U) {
    printf("UP!\n");
  } else if ( key_vec == KEYCODE_D) {
    printf("DOWN!\n");
  } else if ( key_vec == KEYCODE_R) {
    printf("RIGHT!\n");
  } else if ( key_vec == KEYCODE_L) {
    printf("LEFT!\n");
  } else {
    printf("key_vec: %d/%d/%d (%d)\n", key_vec[0], key_vec[1], key_vec[2], (int) key_vec.size());
  }
  printf("key_vec: %d/%d/%d (%d)\n", key_vec[0], key_vec[1], key_vec[2], (int) key_vec.size());
  printf("key:     %d/%d/%d\n", key[0], key[1], key[2]);
  printf("UP:      %d/%d/%d (%d)\n", KEYCODE_U[0], KEYCODE_U[1], KEYCODE_U[2], (int) KEYCODE_U.size());
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "keyboard_joy");
  std::shared_ptr<ros_keyboard_joy> kj(new ros_keyboard_joy());
  kj -> read_sample();
  kj -> proc_one();
};
