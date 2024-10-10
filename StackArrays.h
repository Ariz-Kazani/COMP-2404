

#ifndef STACKARRAYS_H
#define STACKARRAYS_H

#include "File.h"
#include "defs.h"

using namespace std;

class StackArrays
{
public:
    // constructor
    StackArrays();
    ~StackArrays();

    File *getObjectArray();
    File **getPointerArray();
    File *getFilePointer(int index);
    File &getFileReference(int index);

    void addFile(File &f);

private:
    File sStack[MAX_ARRAY];
    File *dStack[MAX_ARRAY];
    int size;
};

#endif
