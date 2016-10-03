// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-

#include <termios.h>

class GetCharacter {
private:
  struct termios old_setting;
  struct termios new_setting;
  const static int stdin_fd = 0;
  fd_set set;
  int rv;
  int timeout_sec,timeout_usec;
  struct timeval timeout;
  void initTermios(int echo);
  char key[8];
public:
  GetCharacter ();
  GetCharacter (int tm_sec, int tm_usec);
  ~GetCharacter ();
  void resetTermios(void);
  bool read(char **c, int char_num);
};
