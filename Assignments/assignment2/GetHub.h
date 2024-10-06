#ifndef GETHUB_H
#define GETHUB_H

#include "RepoList.h"
#include <string>
#include <iostream>

using namespace std;

class GetHub
{
public:
    GetHub();
    ~GetHub();

    // adders and removers
    void addRepo(const string &title, const string &owner);
    void deleteRepo(int index);
    // note that there are two addFile functions
    void addFile(const string &repo, const string &title,
                 const string &content, Date &date);
    void addFile(int repo, const string &title,
                 const string &content, Date &date);
    bool download(int index, Repo **);
    void deleteFile(int repo, int file);
    int getNumRepos();

    // print functions
    void printRepos();
    void printRepo(int index);
    void printFileContents(int repoIndex, int fileIndex);

private:
    // not in specs explain this later
    void addFileHelper(Repo *repo, const string &title, const string &content, Date &date);
    RepoList *repoList;
};

#endif