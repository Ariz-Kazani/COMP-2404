#include "FileList.h"

FileList::FileList()
{
    dummy = new Node;
    dummy->next = dummy;
    dummy->prev = dummy;
    dummy->data = nullptr;
    numFiles = 0;
}

FileList::FileList(FileList &other)
{
    dummy = new Node;
    dummy->next = dummy;
    dummy->prev = dummy;
    dummy->data = nullptr;

    Node *current = dummy;
    Node *otherCurrent = other.dummy->next;
    while (current != other.dummy)
    {
        Node *newNode = new Node;
        newNode->data = otherCurrent->data;
        newNode->next = dummy;
        newNode->prev = current;
        current->next = newNode;
        dummy->prev = newNode;
        current = newNode;
        otherCurrent = otherCurrent->next;
    }
}

FileList::~FileList()
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

bool FileList::add(File *file)
{
    Node *cur = dummy;
    while (cur->next != dummy && cur->data->lessThan(*file))
    {
        cur = cur->next;
    }

    Node *newNode = new Node;
    newNode->data = file;
    newNode->next = cur->prev->next;
    newNode->prev = cur->prev;
    cur->prev->next = newNode;
    cur->prev = newNode;
    ++numFiles;
    return true;
}

File *FileList::get(const string &name)
{
    Node *cur = dummy->next;
    while (cur != dummy)
    {
        if (cur->data->getName() == name)
        {
            return cur->data;
        }
        cur = cur->next;
    }
    return nullptr;
}

File *FileList::get(int index)
{
    Node *cur = this->getNode(index);
    return cur == nullptr ? nullptr : cur->data;
}

File *FileList::remove(const string &name)
{
    Node *cur = dummy->next;
    while (cur != dummy)
    {
        if (cur->data->getName() == name)
        {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            File *temp = cur->data;
            --numFiles;
            delete cur;
            return temp;
        }
        cur = cur->next;
    }
    return nullptr;
}

File *FileList::remove(int index)
{
    Node *cur = this->getNode(index);
    if (cur == nullptr)
        return nullptr;
    File *returnData = cur->data;
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
    --numFiles;
    return returnData;
}

bool FileList::isFull()
{
    return false;
}

FileList::Node *FileList::getNode(int index)
{
    if (index < 0 || index >= numFiles)
        return nullptr;
    Node *cur;

    if (index < numFiles / 2)
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
        for (int i = numFiles - 1; i > index; i--)
        {
            cur = cur->prev;
        }
    }

    return cur;
}
