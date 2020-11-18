#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#include <list>
#include <string>

#define MAX_NAME_LEN 32

class Book {
  public:
    Book();
    Book(std::string name, std::string category);
    Book(std::string name, std::string category, int year, int month, int day,
         int ryear, int rmonth, int rday);

    void setName(std::string name);
    void setCategory(std::string category);
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setRyear(int ryear);
    void setRmonth(int rmonth);
    void setRday(int rday);

    std::string getName(void);
    std::string getCategory(void);
    int getYear(void);
    int getMonth(void);
    int getDay(void);
    int getRyear(void);
    int getRmonth(void);
    int getRday(void);

  private:
    char name[MAX_NAME_LEN + 1];
    char category[MAX_NAME_LEN + 1];
    int year;
    int month;
    int day;
    int ryear;
    int rmonth;
    int rday;
};

class User {
  public:
    User();

    std::string getName(void);

    void showList(void);
    void addBook(Book book);
    void popBook(std::string name);

  private:
    std::string name;
    std::list<Book> bookList;
};

#endif
