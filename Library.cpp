#include "Library.hpp"
#include <list>
#include <string.h>
#include <string>

Book::Book() {
    memset(this->name, 0x00, MAX_NAME_LEN + 1);
    memset(this->category, 0x00, MAX_NAME_LEN + 1);
    this->year = 0;
    this->month = 0;
    this->day = 0;
    this->ryear = 0;
    this->rmonth = 0;
    this->rday = 0;
}
Book::Book(std::string name, std::string category) {
    memcpy(this->name, name.c_str(), MAX_NAME_LEN);
    memcpy(this->category, category.c_str(), MAX_NAME_LEN);
    this->year = 0;
    this->month = 0;
    this->day = 0;
    this->ryear = 0;
    this->rmonth = 0;
    this->rday = 0;
}
Book::Book(std::string name, std::string category, int year, int month, int day,
           int ryear, int rmonth, int rday) {
    memcpy(this->name, name.c_str(), MAX_NAME_LEN);
    memcpy(this->category, category.c_str(), MAX_NAME_LEN);
    this->year = year;
    this->month = month;
    this->day = day;
    this->ryear = ryear;
    this->rmonth = rmonth;
    this->rday = rday;
}

void Book::setName(std::string name) {
    memcpy(this->name, name.c_str(), MAX_NAME_LEN);
}
void Book::setCategory(std::string category) {
    memcpy(this->category, category.c_str(), MAX_NAME_LEN);
}
void Book::setYear(int year) { this->year = year; }
void Book::setMonth(int month) { this->month = month; }
void Book::setDay(int day) { this->day = day; }
void Book::setRyear(int ryear) { this->ryear = ryear; }
void Book::setRmonth(int rmonth) { this->rmonth = rmonth; }
void Book::setRday(int rday) { this->rday = rday; }

std::string Book::getName(void) { return std::string(this->name); }
std::string Book::getCategory(void) { return std::string(this->category); }
int Book::getYear(void) { return this->year; }
int Book::getMonth(void) { return this->month; }
int Book::getDay(void) { return this->day; }
int Book::getRyear(void) { return this->ryear; }
int Book::getRmonth(void) { return this->rmonth; }
int Book::getRday(void) { return this->rday; }
