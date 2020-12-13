#include "book.hpp"

using namespace std;

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

Book::Book(string name, string category) {
    memcpy(this->name, name.c_str(), MAX_NAME_LEN);
    memcpy(this->category, category.c_str(), MAX_NAME_LEN);
    this->year = 0;
    this->month = 0;
    this->day = 0;
    this->ryear = 0;
    this->rmonth = 0;
    this->rday = 0;
}

void Book::setYear(int year) { this->year = year; }
void Book::setMonth(int month) { this->month = month; }
void Book::setDay(int day) { this->day = day; }
void Book::setRyear(int ryear) { this->ryear = ryear; }
void Book::setRmonth(int rmonth) { this->rmonth = rmonth; }
void Book::setRday(int rday) { this->rday = rday; }

string Book::getName(void) { return string(this->name); }
string Book::getCategory(void) { return string(this->category); }
int Book::getYear(void) { return this->year; }
int Book::getMonth(void) { return this->month; }
int Book::getDay(void) { return this->day; }
int Book::getRyear(void) { return this->ryear; }
int Book::getRmonth(void) { return this->rmonth; }
int Book::getRday(void) { return this->rday; }

void clearScreen() {
    pid_t pid = 0;
    int status = 0;

    pid = fork();
    if (pid == 0)
        execl("/usr/bin/clear", "clear");
    else
        wait(&status);
}
