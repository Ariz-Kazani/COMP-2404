#include "RepoList.h"

RepoList::RepoList()
{
    dummy = new Node;
    dummy->next = dummy;
    dummy->prev = dummy;
    dummy->data = nullptr;
    numRepos = 0;
}

RepoList::RepoList(RepoList &other)
{
    dummy = new Node;
    dummy->next = dummy;
    dummy->prev = dummy;
    dummy->data = nullptr;

    Node *otherCurrent = other.dummy->next;
    while (otherCurrent != other.dummy)
    {
        Node *newNode = new Node;
        newNode->data = otherCurrent->data;
        newNode->next = dummy;
        newNode->prev = dummy->prev;
        dummy->prev->next = newNode;
        dummy->prev = newNode;
        otherCurrent = otherCurrent->next;
        ++numRepos;
    }
}

RepoList::~RepoList()
{
    Node *current = dummy->next;
    while (current != dummy)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    delete dummy;
}

bool RepoList::add(Repo *repo)
{
    if (repo == nullptr)
        return false;
    Node *newNode = new Node;
    newNode->data = repo;
    newNode->next = dummy->prev->next;
    dummy->prev->next = newNode;
    newNode->prev = dummy->prev;
    dummy->prev = newNode;
    ++numRepos;
    return true;
}

Repo *RepoList::get(const string &title)
{
    Node *cur = dummy->next;
    while (cur != dummy)
    {
        if (cur->data->getTitle() == title)
        {
            return cur->data;
        }
        cur = cur->next;
    }

    return nullptr;
}

Repo *RepoList::remove(const string &title)
{
    Node *cur = dummy->next;
    while (cur != dummy)
    {
        if (cur->data->getTitle() == title)
        {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            Repo *temp = cur->data;
            delete cur;
            --numRepos;
            return temp;
        }
        cur = cur->next;
    }
    return nullptr;
}

Repo *RepoList::get(int index)
{
    Node *cur = this->getNode(index);
    return cur == nullptr ? nullptr : cur->data;
}

Repo *RepoList::remove(int index)
{
    Node *cur = this->getNode(index);
    if (cur == nullptr)
        return nullptr;
    Repo *returnData = cur->data;
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
    --numRepos;
    return returnData;
}

int RepoList::size()
{
    return numRepos;
}

bool RepoList::isFull()
{
    return false;
}

void RepoList::print()
{
    cout << "Repos: " << this->numRepos << endl;
}

RepoList::Node *RepoList::getNode(int index) const
{
    if (index < 0 || index >= numRepos)
        return nullptr;
    Node *cur = nullptr;

    if (index < numRepos / 2)
    {
        cur = dummy->next;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
    }
    else
    {
        cur = dummy->prev;
        for (int i = numRepos - 1; i > index; i--)
        {
            cur = cur->prev;
        }
    }

    return cur;
}