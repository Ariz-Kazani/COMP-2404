#ifndef REPO_H
#define REPO_H

#include <string>
#include <iostream>
#include "FileList.h"
#include "Date.h"

using namespace std;

class Repo
{
public:
    Repo(string title, string owner);
    ~Repo();

    bool lessThan(Repo *repo); // explain this in readme
    bool addFile(string name, string content, Date &date);
    bool removeFile(int index);
    string getTitle();
    int getNumFiles();
    void print();
    void printFiles();
    void printContents(int index);
    bool isFull();

private:
    string title;
    string owner;
    FileList *fl;
};

#endif