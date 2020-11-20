#include "User.hpp"
#include "main.hpp"

using namespace std;
extern int yearT, monthT, dayT;
// Today::Today(int y, int m, int d) {
//     this->year = y;
//     this->month = m;
//     this->day = d;
// }

// int Today::getYear() { return this->year; }
// int Today::getMonth() { return this->month; }
// int Today::getDay() { return this->day; }
string userName;

void Menu() {
    int option;

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
        cout << "DATE : " << yearT << "-" << monthT << "-" << dayT << endl;
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
}

void UserSel() {
    int userfd = 0;
    pid_t pid = 0;
    int status = 0;

    pid = fork();
    if (pid == -1) {
        perror("fork() error");
        exit(0);
    } else if (pid == 0) {
        execl("/usr/bin/clear", "clear"); // screen clear
    } else {
        wait(&status);
        cout << "NAME : ";
        cin >> userName;

        string userPath = "./USER/";
        userPath = userPath + userName + ".dat";
        userfd = open(userPath.c_str(), O_CREAT | O_RDWR, 0644);

        Menu();
    }
    close(userfd);
}

void userOp1() {
    system("clear");
    char key;
    cout << "op1" << endl;

    cout << "Q or q back to Menu" << endl;
    cin >> key;
    if (key == 'q' || key == 'Q') {
        Menu();
    }
}
void userOp2() { cout << "op2" << endl; }
void userOp3() { cout << "op3" << endl; }
void userOp4() { cout << "op4" << endl; }
void userOp5() { cout << "op5" << endl; }
