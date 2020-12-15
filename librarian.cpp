#include "librarian.hpp"
#include "book.hpp"

using namespace std;

void libMenu() {

    clearScreen();

    int libSel;
    cout << "-사서-" << endl << endl;
    cout << "(1) 도서 현황" << endl;
    cout << "(2) 사용자 현황" << endl;
    cout << "(3) 도서 추가" << endl;
    cout << "(4) 종료" << endl;
    cout << "메뉴 입력 << ";
    cin >> libSel;

    switch (libSel) {
    case 1:
        libMenu1();
        break;
    case 2:
        libMenu2();
        break;
    case 3:
        libMenu3();
        break;
    case 4:
        libMenu4();
        break;
    case 5:
        exit(0);
    }

    return;
}

void libMenu1() {
    clearScreen();

    DIR *dirp;
    struct dirent *dirInfo;
    string catName, catPath;

    DIR *dirp2;
    struct dirent *dirInfo2;
    string bookName, bookPath;
    int fd, r;
    Book book;

    dirp = opendir("./BOOK");
    while ((dirInfo = readdir(dirp)) != NULL) {
        catName = dirInfo->d_name;
        if (catName.compare(".") != 0 && catName.compare("..") != 0) {
            cout << "#" << catName << endl;

            catPath = "./BOOK/" + catName;
            dirp2 = opendir(catPath.c_str());
            while ((dirInfo2 = readdir(dirp2)) != NULL) {
                bookName = dirInfo2->d_name;
                if (bookName.compare(".") != 0 && bookName.compare("..") != 0) {
                    bookPath = catPath + "/" + bookName;
                    fd = open(bookPath.c_str(), O_CREAT | O_RDWR, 0644);
                    r = read(fd, &book, sizeof(Book));
                    cout << "\t" << book.getName() << endl;
                    close(fd);
                }
            }
            closedir(dirp2);
            cout << endl;
        }
    }
    closedir(dirp);

    string pause;
    cout << "메뉴로 돌아가려면 아무 키나 누르세요 : ";
    cin >> pause;
}

void libMenu2() {
    clearScreen();

    DIR *dirp;
    struct dirent *dirInfo;
    string catName, catPath;

    DIR *dirp2;
    struct dirent *dirInfo2;
    string bookName, bookPath;
    int fd, r;
    Book book;

    dirp = opendir("./USER");
    while ((dirInfo = readdir(dirp)) != NULL) {
        catName = dirInfo->d_name;
        if (catName.compare(".") != 0 && catName.compare("..") != 0) {
            cout << catName << " 님" << endl;

            catPath = "./USER/" + catName;
            dirp2 = opendir(catPath.c_str());
            while ((dirInfo2 = readdir(dirp2)) != NULL) {
                bookName = dirInfo2->d_name;
                if (bookName.compare(".") != 0 && bookName.compare("..") != 0) {
                    bookPath = catPath + "/" + bookName;
                    fd = open(bookPath.c_str(), O_CREAT | O_RDWR, 0644);
                    r = read(fd, &book, sizeof(Book));
                    cout << "\t" << book.getName() << "\t" << book.getYear()
                         << "." << book.getMonth() << "." << book.getDay()
                         << " ~ " << book.getRyear() << "." << book.getRmonth()
                         << "." << book.getRday() << endl;
                    close(fd);
                }
            }
            closedir(dirp2);
            cout << endl;
        }
    }
    closedir(dirp);

    string pause;
    cout << "메뉴로 돌아가려면 아무 키나 누르세요 : ";
    cin >> pause;
}

void libMenu3() {
    clearScreen();
    string title, category, path;

    cout << "Enter the bo : ";
    cin >> title;
    cout << "책 카테고리 : ";
    cin >> category;

    Book book(title, category);
    path = "./BOOK/" + category + "/" + title + ".dat";

    int fd = open(path.c_str(), O_CREAT | O_RDWR, 0644);
    write(fd, &book, sizeof(Book));
    close(fd);

    cout << "추가되었습니다." << endl;
    sleep(1);
}

void libMenu4() {
    clearScreen();

    DIR *dirp;
    struct dirent *dirInfo;
    string title, category;
    int found = 0;
    Book book;
    string del;
    string path;

    cout << "삭제할 책 이름 : ";
    cin >> title;
    cout << "삭제할 책의 카테고리 : ";
    cin >> category;

    del = title + ".dat";
    path = "./BOOK/" + category;

    while ((dirInfo = readdir(dirp)) != NULL) {
        int r = access(path.c_str(), F_OK);
        if (r == 0) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
        cout << endl;
        cout << "없는 책입니다." << endl;
        sleep(1);
        return;
    }

    dirp = opendir(path.c_str());
    remove(del.c_str());
    closedir(dirp);

    cout << endl;
    cout << "삭제되었습니다." << endl;
    sleep(1);
}
