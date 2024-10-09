
#ifndef FILELIST_H
#define FILELIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "File.h"
#include "defs.h"

using namespace std;

// TODO make this a linked list

class FileList {
		
	public:
		//constructor
		FileList();
		//copy constructor
		FileList(FileList&);
		
		//destructor
		~FileList();
		
		//other
		bool add(File*);
		File* get(const string& name) ;
		File* get(int) ;
		File* remove(const string& name);
		File* remove(int);
		int size();
		bool isFull();
		void print();
	
	private:
		int numFiles;
		File** files;
};
#endif
