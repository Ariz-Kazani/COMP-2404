

#ifndef HEAPARRAYS_H
#define HEAPARRAYS_H

#include "File.h"
#include "defs.h"

using namespace std;

class HeapArrays
{
public:
    // constructor
    HeapArrays();
    ~HeapArrays();

    File *getObjectArray();
    File **getPointerArray();
    File *getFilePointer(int index);
    File &getFileReference(int index);

    void addFile(File &f);

private:
    File *sStack;
    File **dStack;
    int size;
};

#endif
