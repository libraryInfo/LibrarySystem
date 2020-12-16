#ifndef __BOOK_HPP__
#define __BOOK_HPP__

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_NAME_LEN 128

using namespace std;

class Book {
  public:
    Book();
    Book(string name, string category);

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setRyear(int ryear);
    void setRmonth(int rmonth);
    void setRday(int rday);

    string getName(void);
    string getCategory(void);
    int getYear(void);
    int getMonth(void);
    int getDay(void);
    int getRyear(void);
    int getRmonth(void);
    int getRday(void);

    char name[MAX_NAME_LEN + 1];
    char category[MAX_NAME_LEN + 1];
    int year;
    int month;
    int day;
    int ryear;
    int rmonth;
    int rday;
};
void clearScreen();

#endif
