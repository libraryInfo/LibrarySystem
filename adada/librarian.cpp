#include "librarian.hpp"
#include "book.hpp"

using namespace std;

void librarian() {

    clearScreen();

    int menu;
    cout << "-----목록-----" << endl;
    cout << "1. 도서 현황" << endl;
    cout << "2. 대여 명단" << endl;
    cout << "3. 도서 추가" << endl;
    cout << "4. 도서 삭제" << endl;
    cout << "5. 종료" << endl;
    cout << "메뉴 입력 << ";
    cin >> menu;

    if (menu == 1) {
        bookList();
    } else if (menu == 2) {
        lendingList();
    } else if (menu == 3) {
        addBook();
    } else if (menu == 4) {
        delBook();
    } else if (menu == 5) {
        exit(0);
    }

    return;
}

void bookList() {
    clearScreen();

    DIR *dirp;
    struct dirent *dirInfo;
    string category, categoryLoc;

    DIR *dirp2;
    struct dirent *dirInfo2;
    string booklist, bookLoc;
    int fd, r;
    Book book;

    dirp = opendir("./BOOK");
    cout << "카테고리   책 이름" << endl;
    cout << "-----------------" << endl;
    while ((dirInfo = readdir(dirp)) != NULL) {
        category = dirInfo->d_name;
        if (category.compare(".") != 0 && category.compare("..") != 0) {
            cout << category << endl;
            categoryLoc = "./BOOK/" + category;
            dirp2 = opendir(categoryLoc.c_str());
            while ((dirInfo2 = readdir(dirp2)) != NULL) {
                booklist = dirInfo2->d_name;
                if (booklist.compare(".") != 0 && booklist.compare("..") != 0) {
                    bookLoc = categoryLoc + "/" + booklist;
                    fd = open(bookLoc.c_str(), O_CREAT | O_RDWR, 0644);
                    r = read(fd, &book, sizeof(Book));
                    cout << "    ㄴ\t" << book.getName() << endl;
                    close(fd);
                }
            }
            closedir(dirp2);
            cout << "-----------------" << endl;
        }
    }
    closedir(dirp);

    string pause;
    cout << "메뉴로 돌아가려면 아무 키나 누르세요 : ";
    cin >> pause;
}

void lendingList() {
    clearScreen();

    DIR *dirp;
    struct dirent *dirInfo;
    string name, loc;

    DIR *dirp2;
    struct dirent *dirInfo2;
    string booklist, bookLoc;
    int fd, r;
    Book book;
    cout << "-----대여 명단-----" << endl;
    dirp = opendir("./USER");
    while ((dirInfo = readdir(dirp)) != NULL) {
        name = dirInfo->d_name;
        if (name.compare(".") != 0 && name.compare("..") != 0) {
            cout << name << "님" << endl;

            loc = "./USER/" + name;
            dirp2 = opendir(loc.c_str());
            while ((dirInfo2 = readdir(dirp2)) != NULL) {
                booklist = dirInfo2->d_name;
                if (booklist.compare(".") != 0 && booklist.compare("..") != 0) {
                    bookLoc = loc + "/" + booklist;
                    fd = open(bookLoc.c_str(), O_CREAT | O_RDWR, 0644);
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

void addBook() {
    clearScreen();

    string name, category, path;
    cout << "-----도서 추가-----" << endl;
    cout << "책 이름 : ";
    cin >> name;
    cout << "책 카테고리 : ";
    cin >> category;

    Book book(name, category);
    path = "./BOOK/" + category;
    int a = access(path.c_str(), F_OK);
    if (a == -1) {
        mkdir(path.c_str(), 0777);
    }
    path = "./BOOK/" + category + "/" + name + ".dat";
    a = access(path.c_str(), F_OK);
    if (a == 0) {
        cout << "책이 이미 존재합니다" << endl;
        sleep(1);
    } else {

        int fd = open(path.c_str(), O_CREAT | O_RDWR, 0644);
        write(fd, &book, sizeof(Book));
        close(fd);

        cout << "추가되었습니다." << endl;
        sleep(1);
    }
}

void delBook() {
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
    remove(del.c_str());

    cout << endl;
    cout << "삭제되었습니다." << endl;
    sleep(1);
}
