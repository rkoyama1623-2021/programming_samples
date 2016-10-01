// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include "getch.h"

GetCharacter::GetCharacter (void) {
  GetCharacter(3,0);
};
GetCharacter::GetCharacter (int tm_sec, int tm_usec) {
  this->initTermios(0);
  timeout_sec = tm_sec;
  timeout_usec = tm_usec;
};
GetCharacter::~GetCharacter () {
  this->resetTermios();
};
void GetCharacter::initTermios(int echo = 0) { /* Initialize new terminal i/o settings */
  tcgetattr(stdin_fd, &old_setting); /* grab old terminal i/o settings */
  new_setting = old_setting; /* make new settings same as old settings */
  new_setting.c_lflag &= ~ICANON; /* disable buffered i/o */
  new_setting.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new_setting); /* use these new terminal i/o settings now */
};
void GetCharacter::resetTermios(void) {
  old_setting.c_lflag |= ECHO;
  tcsetattr(0, TCSANOW, &old_setting);

};
void GetCharacter::read(char **c,int char_num=1) {
  FD_ZERO(&set); /* clear the set */
  FD_SET(stdin_fd, &set); /* add our file descriptor to the set */
  timeout.tv_sec = timeout_sec;
  timeout.tv_usec = timeout_usec;
  rv = select(stdin_fd + 1, &set, NULL, NULL, &timeout);
  if(rv == -1) {
    /* an error occured */
    *c = key;
  }
  else if(rv == 0) {
    /* a timeout occured */
    *c = key;
  }
  else {
    ::read(stdin_fd, &key, char_num);
    *c = key;
  }
};
