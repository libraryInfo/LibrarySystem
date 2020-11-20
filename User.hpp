#ifndef __USER_HPP__
#define __USER_HPP__

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

class Today {
  private:
    int year;
    int month;
    int day;

  public:
    Today();
    Today(int y, int m, int d);
    int getYear();
    int getMonth();
    int getDay();
};

void UserSel();
void UserMenu();
void userOp1();
void userOp2();
void userOp3();
void userOp4();
void userOp5();

#endif
