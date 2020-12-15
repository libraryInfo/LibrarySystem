#include "book.hpp"
#include "librarian.hpp"
#include "user.hpp"

using namespace std;

int main() {

    clearScreen();

    int mode;
    cout << "LIBRARY MANAGEMENT PROGRAM" << endl;
    cout << "---------------------------" << endl;
    cout << "1. 사서" << endl;
    cout << "2. 사용자" << endl;
    cout << "이용 서비스를 골라주세요 : ";
    cin >> mode;

    while (1) {
        if (mode == 1) {
            librarian();
        } else if (mode == 2) {
        }
    }
    return 0;
}
