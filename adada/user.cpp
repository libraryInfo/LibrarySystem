#include "user.hpp"
#include "book.hpp"

using namespace std;

void usrMenu() {

    clearScreen();

    int usrSel;
    cout << "-사용자-" << endl << endl;
    cout << "(1) 도서 현황" << endl;
    cout << "(2) 대여 도서 현황" << endl;
    cout << "(3) 도서 대여" << endl;
    cout << "(4) 대여 기간 연장" << endl;
    cout << "(5) 도서 반납" << endl;
    cout << "(6) 종료" << endl;
    cout << "메뉴 입력 << ";
    cin >> usrSel;

    switch (usrSel) {
    case 1:
        cout << "(1)" << endl;
        break;
    case 2:
        cout << "(2)" << endl;
        break;
    case 3:
        cout << "(3)" << endl;
        break;
    case 4:
        cout << "(4)" << endl;
        break;
    case 5:
        cout << "(5)" << endl;
        break;
    case 6:
        exit(0);
    }

    return;
}

void usrMenu1() { ; }
void usrMenu2() { ; }
void usrMenu3() { ; }
void usrMenu4() { ; }
void usrMenu5() { ; }
