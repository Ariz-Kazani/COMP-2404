#include "Client.h"

Client::Client()
{
    repo = nullptr;
    monitoredRepoIndex = -1;
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
        monitoredRepoIndex = index; // track which repo we're monitoring
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

bool Client::checkForChanges(const GetHub &getHub, int index) const
{
    if (repo == nullptr)
    {
        cout << "Error: No cloned repo to compare!" << endl;
        return false;
    }
    
    if (monitoredRepoIndex == -1 || monitoredRepoIndex != index)
    {
        cout << "Error: Not monitoring this repo!" << endl;
        return false;
    }
    
    Repo *currentRepo = nullptr;
    if (!getHub.download(index, &currentRepo))
    {
        cout << "Error: Could not access current repo!" << endl;
        return false;
    }
    
    // Compare file counts
    int currentFileCount = currentRepo->getNumFiles();
    int localFileCount = repo->getNumFiles();
    
    return (currentFileCount != localFileCount);
}

void Client::printChanges(const GetHub &getHub, int index) const
{
    if (repo == nullptr)
    {
        cout << "Error: No cloned repo to compare!" << endl;
        return;
    }
    
    if (monitoredRepoIndex == -1 || monitoredRepoIndex != index)
    {
        cout << "Error: Not monitoring this repo!" << endl;
        return;
    }
    
    Repo *currentRepo = nullptr;
    if (!getHub.download(index, &currentRepo))
    {
        cout << "Error: Could not access current repo!" << endl;
        return;
    }
    
    cout << endl << "Repository Change Report" << endl;
    cout << "=========================" << endl;
    cout << "Monitoring: " << repo->getTitle() << " by " << repo->getOwner() << endl;
    
    int currentFileCount = currentRepo->getNumFiles();
    int localFileCount = repo->getNumFiles();
    
    if (currentFileCount != localFileCount)
    {
        cout << "CHANGES DETECTED:" << endl;
        cout << "  Local file count: " << localFileCount << endl;
        cout << "  Remote file count: " << currentFileCount << endl;
        
        if (currentFileCount > localFileCount)
        {
            cout << "  Status: " << (currentFileCount - localFileCount) << " file(s) added" << endl;
        }
        else
        {
            cout << "  Status: " << (localFileCount - currentFileCount) << " file(s) removed" << endl;
        }
    }
    else
    {
        cout << "No changes detected - file count unchanged (" << localFileCount << " files)" << endl;
    }
    cout << endl;
}