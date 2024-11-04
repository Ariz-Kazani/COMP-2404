
#ifndef FILELIST_H
#define FILELIST_H

#include <string>
#include <iomanip>
#include "File.h"
#include "defs.h"

using namespace std;

class FileList
{

public:
	// constructor
	FileList();
	// copy constructor
	FileList(FileList &);

	// destructor
	~FileList();

	bool add(File *);

	// getters
	File *get(const string &name) const;
	File *get(int) const;

	// removers
	File *remove(const string &name);
	File *remove(int);

	// other
	int size() const;
	bool isFull() const;
	void print() const;

private:
	class Node
	{
	public:
		Node *next;
		Node *prev;
		File *data;
	};
	Node *dummy;
	int numFiles;

	// helper functions
	Node *getNode(int index) const;
};
#endif
