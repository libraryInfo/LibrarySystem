//#include "Library.hpp"
#include "main.hpp"
#include "User.hpp"
using namespace std;

int sel;
int yearT, monthT, dayT;

int main(void) {
    setDay();
    while (1) {
        MainMenu();
    }
}

void setDay() {
    time_t rTime;
    struct tm *Currtime;

    rTime = time(NULL);           // Curr time
    Currtime = localtime(&rTime); // Curr time struct

    yearT = Currtime->tm_year + 1900;
    monthT = Currtime->tm_mon + 1;
    dayT = Currtime->tm_mday;
}

void MainMenu() {
    pid_t pid = 0;
    int status = 0;

    pid = fork();
    if (pid == -1) {
        perror("fork() error");
        exit(-1);
    } else if (pid == 0) {
        execl("/usr/bin/clear", "clear");
    } else {
        wait(&status);
        cout << "------------------------------------------------" << endl;
        cout << "1. 사서" << endl;
        cout << "2. 사용자" << endl;
        cout << "1(사서) or 2(사용자) 숫자입력 : ";
        cin >> sel;

        if (sel == 1) {
        } else if (sel == 2) {
            UserSel();
        } else {
            cout << "error" << endl;
        }
    }
}
