#include "GetHub.h"

GetHub::GetHub()
{
    repoList = new RepoList();
}

GetHub::~GetHub()
{
    repoList->clearAll();
    delete repoList;
}

void GetHub::addRepo(const string &title, const string &owner)
{
    if (repoList->isFull())
    {
        cout << "Error! Cannot Creat Another Repo!" << endl;
    }
    else
    {
        Repo *newRepo = new Repo(title, owner);
        repoList->add(newRepo);
    }
}

void GetHub::deleteRepo(int index)
{
    Repo *delRepo = repoList->remove(index);
    if (delRepo == nullptr)
    {
        cout << "Error! Invalid Index!" << endl;
    }
    else
    {
        delete delRepo;
    }
}

void GetHub::addFile(const string &repo, const string &title, const string &content, Date &date)
{
    Repo *targetRepo = repoList->get(repo);
    if (targetRepo == nullptr)
    {
        cout << "Error! Repo Doesn't Exist!" << endl;
        return;
    }
    this->addFileHelper(targetRepo, title, content, date);
}

void GetHub::addFile(int repo, const string &title, const string &content, Date &date)
{
    Repo *targetRepo = repoList->get(repo);
    if (targetRepo == nullptr)
    {
        cout << "Error! Repo Doesn't Exist!" << endl;
        return;
    }
    this->addFileHelper(targetRepo, title, content, date);
}

void GetHub::addFileHelper(Repo *repo, const string &title, const string &content, Date &date)
{
    if (repo->isFull())
    {
        cout << "Error! This Repo is Full" << endl;
        return;
    }
    if (repo->addFile(title, content, date))
    {
        cout << "Success!" << endl;
    }
    else
    {
        cout << "Error! Something went very very wrong!" << endl;
    }
}

void GetHub::deleteFile(int repo, int file)
{
    Repo *thisRepo = repoList->get(repo);

    if (thisRepo == nullptr)
    {
        cout << "Invalid Repo Index" << endl;
    }
    else
    {
        thisRepo->printContents(file);
    }
}

int GetHub::getNumRepos()
{
    return this->repoList->size();
}

bool GetHub::download(int index, Repo **repo)
{
    Repo *thisRepo = repoList->get(index);
    if (thisRepo == nullptr)
        return false;
    *repo = thisRepo;
    return true;
}

void GetHub::printRepos()
{
    cout << "GetHub" << endl;
    cout << "========" << endl;
    for (int i = 0; i < this->getNumRepos(); i++)
    {
        cout << i << ") ";
        repoList->get(i)->print();
        cout << endl;
    }
}

void GetHub::printRepo(int index)
{
    Repo *thisRepo = repoList->get(index);
    if (thisRepo == nullptr)
    {
        cout << "Invalid Index" << endl;
    }
    else
    {
        thisRepo->print();
    }
}

void GetHub::printFileContents(int repoIndex, int fileIndex)
{
    Repo *thisRepo = repoList->get(repoIndex);

    if (thisRepo == nullptr)
    {
        cout << "Invalid Repo Index" << endl;
    }
    else
    {
        thisRepo->printContents(fileIndex);
    }
}