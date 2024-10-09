#include "File.h"

File::File(const string& name, const string& content,  Date& date): lastModified(date), name(name), content(content) {}

File::File( File& e): File( e.name, e.content, e.lastModified){  }

void File::print() {
	cout <<"File:          "<<name<<endl;
	cout <<"Last modified: ";
	lastModified.print(); cout<<endl;
}

bool File::lessThan( File& e) {
	//TODO change this implementation
	return (lastModified.lessThan(e.lastModified));
}

void File::printContents() {
	print();
	cout <<endl<< content<<endl<<endl;
}
