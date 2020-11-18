//#include "Library.hpp"
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

void userOp1();
void userOp2();
void userOp3();
void userOp4();
void userOp5();

int main(void) {
    int yearT, monthT, dayT;
    cout << "YEAR : ";
    cin >> yearT;
    cout << "MONTH : ";
    cin >> monthT;
    cout << "DAY : ";
    cin >> dayT;

    string userName;
    cout << "NAME : ";
    cin >> userName;

    string userPath = "./USER/";
    userPath = userPath + userName + ".dat";
    int userfd = open(userPath.c_str(), O_CREAT | O_RDONLY | O_WRONLY, 0644);

    int option;
    while (1) {
        cout << "------------------------------------------------" << endl;
        cout << "DATE : " << yearT << " " << monthT << " " << dayT << endl;
        cout << "NAME : " << userName << endl;
        cout << "1) List of Books" << endl;
        cout << "2) List of Borrowed Books" << endl;
        cout << "3) Borrow Book" << endl;
        cout << "4) Extend the Borrowing Period of Book" << endl;
        cout << "5) Return Book" << endl;
        cout << "6) Exit" << endl;

        cout << "Choose Option <<";
        cin >> option;

        switch (option) {
        case 1:
            userOp1();
            break;
        case 2:
            userOp2();
            break;
        case 3:
            userOp3();
            break;
        case 4:
            userOp4();
            break;
        case 5:
            userOp5();
            break;
        case 6:
            exit(0);
        default:
            cout << "Wrong Input!" << endl;
        }
    }

    close(userfd);
}

void userOp1() { cout << "op1" << endl; }
void userOp2() { cout << "op2" << endl; }
void userOp3() { cout << "op3" << endl; }
void userOp4() { cout << "op4" << endl; }
void userOp5() { cout << "op5" << endl; }
