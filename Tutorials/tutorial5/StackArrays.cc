#include "StackArrays.h"

StackArrays::StackArrays()
{
    size = 0;
}

StackArrays::~StackArrays()
{
    for (int i = 0; i < size; i++)
    {
        delete dStack[i];
    }
}

File *StackArrays::getObjectArray()
{
    return sStack;
}

File **StackArrays::getPointerArray()
{
    return dStack;
}

File *StackArrays::getFilePointer(int index)
{
    if (index < 0 || index >= size)
        return nullptr;

    return dStack[index];
}

File &StackArrays::getFileReference(int index)
{
    if (index < 0 || index >= size)
        return sStack[0];

    return sStack[index];
}

void StackArrays::addFile(File &f)
{
    if (size < MAX_ARRAY)
    {
        File *fp = new File(f);
        sStack[size] = f;
        dStack[size] = fp;
        size++;
    }
}
