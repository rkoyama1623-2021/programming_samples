// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-

#include <stdio.h>
#include <memory>
#include <memory.h>
#include <string>
#include "getch.h"

namespace std {
  using namespace tr1; // std::tr1:: => std::
}

class keyboard_joy : GetCharacter {
public:
  keyboard_joy();
  keyboard_joy(int tm_sec, int tm_usec);
  ~keyboard_joy();
  void read();
private:
  char* key;
  const std::string KEYCODE_U;
  const std::string KEYCODE_D;
  const std::string KEYCODE_R;
  const std::string KEYCODE_L;
};
// keyboard_joy::keyboard_joy() : GetCharacter() {
//   keyboard_joy(3,0);
// };
keyboard_joy::keyboard_joy(int tm_sec, int tm_usec)
  :GetCharacter(tm_sec, tm_usec),
   KEYCODE_U((const char[]) {0x1b, 0x5b, 0x41, 0x00}),
   KEYCODE_D((const char[]) {0x1b, 0x5b, 0x42, 0x00}),
   KEYCODE_R((const char[]) {0x1b, 0x5b, 0x43, 0x00}),
   KEYCODE_L((const char[]) {0x1b, 0x5b, 0x44, 0x00})
{
  key = NULL;
};
keyboard_joy::~keyboard_joy() {
  GetCharacter::resetTermios();
};
void keyboard_joy::read() {
  GetCharacter::read(&key, 3);
  char tmp_key[3]={0};
  //strcpy(tmp_key,key);
  memcpy(tmp_key,key,3);
  const std::string key_str(tmp_key, tmp_key+3);
  if ( key_str == KEYCODE_U) {
    printf("UP!\n");
  }
  printf("key_str: %d/%d/%d (%d)\n", key_str[0], key_str[1], key_str[2], key_str.length());
  printf("key:     %d/%d/%d\n", key[0], key[1], key[2]);
  printf("UP:      %d/%d/%d (%d)\n", KEYCODE_U[0], KEYCODE_U[1], KEYCODE_U[2], KEYCODE_U.length());
};

int main(void)
{
  std::shared_ptr<keyboard_joy> kj(new keyboard_joy(3,0));
  kj -> read();
};
