#include "Repo.h"

Repo::Repo(string title, string owner)
{
    this->title = title;
    this->owner = owner;
    this->fl = new FileList();
}

Repo::~Repo()
{
    delete fl;
}

bool Repo::lessThan(Repo *repo)
{
    return this->title.compare(repo->title) < 0;
}

bool Repo::addFile(string name, string content, Date &date)
{
    if (this->fl->isFull())
        return false;
    File *nf = new File(name, content, date);
    this->fl->add(nf);
}

bool Repo::removeFile(int index)
{
    File *of = this->fl->remove(index);
    if (of == nullptr)
        return false;
    delete of;
    return true;
}

int Repo::getNumFiles()
{
    return this->fl->size();
}

void Repo::print()
{
    cout << "Title: " << title << endl;
    cout << "Owner: " << owner << endl;
    cout << "Number of files: " << this->getNumFiles() << endl;
}

void Repo::printFiles()
{
    for (int i = 0; i < this->getNumFiles(); i++)
    {
        cout << i << ") ";
        fl->get(i)->print();
        cout << endl;
    }
}