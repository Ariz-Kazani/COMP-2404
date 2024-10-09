
#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;


class File {
		
	public:
		//constructor
		File(const string& name, const string& content,  Date& date);
		
		//copy constructor
		File( File&);
		bool lessThan( File&) ;

		const string& getName() {
			return name;
		}
		
		//other
		void print() ;
		void printContents() ;
	
	private:
		Date lastModified;
		string name;
		string content;
	
};
#endif
