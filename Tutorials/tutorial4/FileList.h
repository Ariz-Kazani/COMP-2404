
#ifndef FILELIST_H
#define FILELIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "defs.h"
#include "File.h"

using namespace std;

class FileList
{

public:
    // constructor
    FileList();

    // destructor
    ~FileList();

    // other
    bool add(File *);
    File *get(int);
    File *get(string);
    File *remove(int);
    File *remove(string);
    void clearAll(); // not in specs

    int size();
    bool isFull();

private:
    int numFiles;
    File **list;
};
#endif
