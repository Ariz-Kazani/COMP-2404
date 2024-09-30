
#include "FileList.h"

FileList::FileList()
{
	numFiles = 0;
	list = new File *[MAX_ARRAY];
}

FileList::~FileList()
{
	delete[] list;
}

bool FileList::add(File *p)
{
	if (numFiles >= MAX_ARRAY)
		return false;
	list[numFiles++] = p;
	int index = numFiles - 1;
	while (index > 0 && list[index]->lessThan(*list[index - 1]->getDate()))
	{
		File *temp = list[index];
		list[index] = list[index - 1];
		list[index--] = temp;
	}
	return true;
}

File *FileList::remove(int index)
{
	if (index < 0 || index >= numFiles)
		return nullptr;
	File *temp = list[index];
	for (int i = index; i < numFiles - 1; ++i)
	{
		list[i] = list[i + 1];
	}
	numFiles--;
	return temp;
}

File *FileList::remove(string name)
{
	File *temp = nullptr;
	int i = 0;
	for (; i < numFiles; i++)
	{
		if (*list[i]->getName() == name)
		{
			temp = list[i];
			numFiles--;
			break;
		}
	}

	for (; i < numFiles; i++)
	{
		list[i] = list[i + 1];
	}

	return temp;
}

File *FileList::get(int index)
{
	if (index < 0 || index >= numFiles)
		return nullptr;
	return list[index];
}

File *FileList::get(string name)
{
	for (int i = 0; i < numFiles; i++)
	{
		if (*list[i]->getName() == name)
			return list[i];
	}
	return nullptr;
}

bool FileList::isFull()
{
	return numFiles >= MAX_ARRAY;
}

int FileList::size()
{
	return numFiles;
}
