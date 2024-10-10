#include "HeapArrays.h"

HeapArrays::HeapArrays()
{
    sStack = new File[MAX_ARRAY];
    dStack = new File *[MAX_ARRAY];
    size = 0;
}

HeapArrays::~HeapArrays()
{
    for (int i = 0; i < size; i++)
    {
        delete dStack[i];
    }

    delete[] sStack;
    delete[] dStack;
}

File *HeapArrays::getObjectArray()
{
    return sStack;
}

File **HeapArrays::getPointerArray()
{
    return dStack;
}

File *HeapArrays::getFilePointer(int index)
{
    if (index < 0 || index >= size)
        return nullptr;

    return dStack[index];
}

File &HeapArrays::getFileReference(int index)
{
    if (index < 0 || index >= size)
        return sStack[0];

    return sStack[index];
}

void HeapArrays::addFile(File &f)
{
    if (size < MAX_ARRAY)
    {
        File *fp = new File(f);
        sStack[size] = f;
        dStack[size] = fp;
        size++;
    }
}
