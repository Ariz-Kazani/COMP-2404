#include "Client.h"

Client::Client()
{
    repo = nullptr;
}

Client::~Client()
{
    delete repo;
}

bool Client::cloneRepo(const GetHub &getHub, int index)
{
    Repo *newRepo = nullptr;
    if (getHub.download(index, &newRepo))
    {
        if (repo != nullptr)
            delete repo;
        repo = new Repo(*newRepo);
        return true;
    }
    return false;
}

void Client::printRepo() const
{
    if (repo != nullptr)
    {
        repo->printFiles();
    }
    else
    {
        cout << "Error: No Chose Repo!" << endl;
    }
}

void Client::printFileContents(int index) const
{
    if (repo != nullptr)
    {
        repo->printContents(index);
    }
    else
    {
        cout << "Error: No Chose Repo!" << endl;
    }
}