#include "user.hpp"
#include "book.hpp"

using namespace std;

string usrName;
int year, month, day;
int ryear, rmonth, rday;

void usrMenu(string inputName) {

    clearScreen();

    usrName = inputName;

    time_t rTime;
    struct tm *Currtime;
    rTime = time(NULL);
    Currtime = localtime(&rTime);

    year = Currtime->tm_year + 1900;
    month = Currtime->tm_mon + 1;
    day = Currtime->tm_mday;

    ryear = year;
    rmonth = month;
    rday = day + 7;
    if (rday > 31) {
        rday -= 31;
        rmonth++;
    }
    if (rmonth > 12) {
        rmonth -= 12;
        ryear++;
    }

    string tempPath = "./USER/" + usrName;
    DIR *temp = opendir(tempPath.c_str());
    if (temp == NULL)
        mkdir(tempPath.c_str(), 0755);
    else
        closedir(temp);

    int usrSel;
    cout << "-사용자-" << endl << endl;
    cout << "이름 : " << usrName << " | 날짜 : " << year << "." << month << "."
         << day << endl
         << endl;
    cout << "(1) 도서 현황" << endl;
    cout << "(2) 도서 대여" << endl;
    cout << "(3) 대여 도서 현황" << endl;
    cout << "(4) 대여 기간 연장" << endl;
    cout << "(5) 도서 반납" << endl;
    cout << "(6) 종료" << endl;
    cout << "메뉴 입력 << ";
    cin >> usrSel;

    switch (usrSel) {
    case 1:
        usrMenu1();
        break;
    case 2:
        usrMenu2();
        break;
    case 3:
        usrMenu3();
        break;
    case 4:
        usrMenu4();
        break;
    case 5:
        usrMenu5();
        break;
    case 6:
        exit(0);
    }

    return;
}

void usrMenu1() {
    clearScreen();

    DIR *dirp;
    struct dirent *dirInfo;
    string catName, catPath;

    DIR *dirp2;
    struct dirent *dirInfo2;
    string bookName, bookPath;
    int fd, r;
    Book book;

    cout << "-도서 현황-" << endl << endl;
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
void usrMenu2() {
    clearScreen();

    DIR *dirp;
    struct dirent *dirInfo;
    string catName, catPath;

    DIR *dirp2;
    struct dirent *dirInfo2;
    string bookName, bookPath;
    int fd, r;
    Book book;

    cout << "-도서 현황-" << endl << endl;
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
        }
    }
    closedir(dirp);

    string bor, borCat, borPath, des;
    int found = 0;
    cout << endl;
    cout << "대여할 책의 이름을 입력하세요 : ";
    cin >> bor;

    dirp = opendir("./BOOK");
    while ((dirInfo = readdir(dirp)) != NULL) {
        catName = dirInfo->d_name;
        if (catName.compare(".") != 0 && catName.compare("..") != 0) {
            catPath = "./BOOK/" + catName;
            dirp2 = opendir(catPath.c_str());
            while ((dirInfo2 = readdir(dirp2)) != NULL) {
                bookName = dirInfo2->d_name;
                if (bookName.compare(".") != 0 && bookName.compare("..") != 0) {
                    bookPath = catPath + "/" + bookName;
                    fd = open(bookPath.c_str(), O_CREAT | O_RDWR, 0644);
                    r = read(fd, &book, sizeof(Book));
                    if (book.getName().compare(bor) == 0) {
                        found = 1;
                        borCat = book.getCategory();
                        book.setYear(year);
                        book.setMonth(month);
                        book.setDay(day);
                        book.setRyear(ryear);
                        book.setRmonth(rmonth);
                        book.setRday(rday);
                        lseek(fd, (off_t)0, SEEK_SET);
                        write(fd, &book, sizeof(Book));
                    }
                    close(fd);
                }
            }
            closedir(dirp2);
        }
    }
    closedir(dirp);

    if (found == 0) {
        cout << endl;
        cout << "없는 책입니다." << endl;
        sleep(1);
        return;
    }

    borPath = "./BOOK/" + borCat + "/" + bor + ".dat";
    des = "./USER/" + usrName + "/";

    pid_t pid = 0;
    int status = 0;

    pid = fork();
    if (pid == 0)
        execl("/usr/bin/mv", "mv", borPath.c_str(), des.c_str());
    else
        wait(&status);

    cout << endl;
    cout << "대여되었습니다." << endl;
    sleep(1);
}

void usrMenu3() {
    clearScreen();

    DIR *dirp;
    struct dirent *dirInfo;
    string usrPath = "./USER/" + usrName;
    string bookName, bookPath;

    int fd, r;
    Book book;

    list<Book> bookList;
    list<Book>::iterator iter;

    cout << "-대여한 도서 목록-" << endl << endl;
    dirp = opendir(usrPath.c_str());
    while ((dirInfo = readdir(dirp)) != NULL) {
        bookName = dirInfo->d_name;
        if (bookName.compare(".") != 0 && bookName.compare("..") != 0) {
            bookPath = usrPath + "/" + bookName;
            fd = open(bookPath.c_str(), O_CREAT | O_RDWR, 0644);
            r = read(fd, &book, sizeof(Book));
            bookList.push_back(book);
            close(fd);
        }
    }
    closedir(dirp);

    for (iter = bookList.begin(); iter != bookList.end(); ++iter) {
        cout << " * " << (*iter).getName() << "  |  " << (*iter).getCategory()
             << "  |  " << (*iter).getYear() << "." << (*iter).getMonth() << "."
             << (*iter).getDay() << " ~ " << (*iter).getRyear() << "."
             << (*iter).getRmonth() << "." << (*iter).getRday() << endl;
    }

    cout << endl;
    string pause;
    cout << "메뉴로 돌아가려면 아무 키나 누르세요 : ";
    cin >> pause;
}

void usrMenu4() {
    clearScreen();

    DIR *dirp;
    struct dirent *dirInfo;
    string usrPath = "./USER/" + usrName;
    string bookName, bookPath;
    int bryear, brmonth, brday;
    int fd, r;
    Book book;

    list<Book> bookList;
    list<Book>::iterator iter;

    cout << "-대여한 도서 목록-" << endl << endl;
    dirp = opendir(usrPath.c_str());
    while ((dirInfo = readdir(dirp)) != NULL) {
        bookName = dirInfo->d_name;
        if (bookName.compare(".") != 0 && bookName.compare("..") != 0) {
            bookPath = usrPath + "/" + bookName;
            fd = open(bookPath.c_str(), O_CREAT | O_RDWR, 0644);
            r = read(fd, &book, sizeof(Book));
            bookList.push_back(book);
            close(fd);
        }
    }
    closedir(dirp);

    for (iter = bookList.begin(); iter != bookList.end(); ++iter) {
        cout << " * " << (*iter).getName() << "  |  " << (*iter).getCategory()
             << "  |  " << (*iter).getYear() << "." << (*iter).getMonth() << "."
             << (*iter).getDay() << " ~ " << (*iter).getRyear() << "."
             << (*iter).getRmonth() << "." << (*iter).getRday() << endl;
    }

    cout << endl;
    string ext;
    cout << "대여 기간을 연장할 책의 이름을 입력하세요 : ";
    cin >> ext;

    int found = 0;
    dirp = opendir(usrPath.c_str());
    while ((dirInfo = readdir(dirp)) != NULL) {
        bookName = dirInfo->d_name;
        if (bookName.compare(".") != 0 && bookName.compare("..") != 0) {
            bookPath = usrPath + "/" + bookName;
            fd = open(bookPath.c_str(), O_CREAT | O_RDWR, 0644);
            r = read(fd, &book, sizeof(Book));
            if (book.getName().compare(ext) == 0) {
                found = 1;
                bryear = book.getRyear();
                brmonth = book.getRmonth();
                brday = book.getRday() + 7;

                if (brday > 31) {
                    brday -= 31;
                    brmonth++;
                }
                if (brmonth > 12) {
                    brmonth -= 12;
                    bryear++;
                }

                book.setRyear(bryear);
                book.setRmonth(brmonth);
                book.setRday(brday);
                lseek(fd, (off_t)0, SEEK_SET);
                write(fd, &book, sizeof(Book));
            }
            close(fd);
        }
    }
    closedir(dirp);

    if (found == 0) {
        cout << endl;
        cout << "없는 책입니다." << endl;
        sleep(1);
        return;
    }

    cout << endl;
    cout << "연장되었습니다." << endl;
    sleep(1);
}
void usrMenu5() {
    clearScreen();

    DIR *dirp;
    struct dirent *dirInfo;
    string usrPath = "./USER/" + usrName;
    string bookName, bookPath;
    int bryear, brmonth, brday;
    int fd, r;
    Book book;

    list<Book> bookList;
    list<Book>::iterator iter;

    cout << "-대여한 도서 목록-" << endl << endl;
    dirp = opendir(usrPath.c_str());
    while ((dirInfo = readdir(dirp)) != NULL) {
        bookName = dirInfo->d_name;
        if (bookName.compare(".") != 0 && bookName.compare("..") != 0) {
            bookPath = usrPath + "/" + bookName;
            fd = open(bookPath.c_str(), O_CREAT | O_RDWR, 0644);
            r = read(fd, &book, sizeof(Book));
            bookList.push_back(book);
            close(fd);
        }
    }
    closedir(dirp);

    for (iter = bookList.begin(); iter != bookList.end(); ++iter) {
        cout << " * " << (*iter).getName() << "  |  " << (*iter).getCategory()
             << "  |  " << (*iter).getYear() << "." << (*iter).getMonth() << "."
             << (*iter).getDay() << " ~ " << (*iter).getRyear() << "."
             << (*iter).getRmonth() << "." << (*iter).getRday() << endl;
    }

    cout << endl;
    string ext;
    int found = 0;
    cout << "반납할 책의 이름을 입력하세요 : ";
    cin >> ext;

    string retCat, retName, retPath, des;
    dirp = opendir(usrPath.c_str());
    while ((dirInfo = readdir(dirp)) != NULL) {
        bookName = dirInfo->d_name;
        if (bookName.compare(".") != 0 && bookName.compare("..") != 0) {
            bookPath = usrPath + "/" + bookName;
            fd = open(bookPath.c_str(), O_CREAT | O_RDWR, 0644);
            r = read(fd, &book, sizeof(Book));
            if (book.getName().compare(ext) == 0) {
                found = 1;
                retName = bookName;
                retCat = book.getCategory();
            }
            close(fd);
        }
    }
    closedir(dirp);

    if (found == 0) {
        cout << endl;
        cout << "없는 책입니다." << endl;
        sleep(1);
        return;
    }

    des = "./BOOK/" + retCat + "/";
    retPath = "./USER/" + usrName + "/" + retName;

    pid_t pid = 0;
    int status = 0;

    pid = fork();
    if (pid == 0)
        execl("/usr/bin/mv", "mv", retPath.c_str(), des.c_str());
    else
        wait(&status);

    cout << endl;
    cout << "반납되었습니다." << endl;
    sleep(1);
}
