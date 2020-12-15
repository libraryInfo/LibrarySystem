#ifndef __LIBRARIAN_HPP__
#define __LIBRARIAN_HPP__

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <dirent.h>
#include <fcntl.h>
#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void librarian();
void bookList();
void lendingList();
void addBook();
void delBook();

#endif
