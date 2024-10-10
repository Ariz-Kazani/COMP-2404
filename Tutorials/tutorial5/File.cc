#include "File.h"

File::File(const string &name, const string &content, const Date &date) : lastModified(date), name(name), content(content) {}

File::File() : lastModified(), name(""), content("") {}

File::File(const File &e) : File(e.name, "RCMP", e.lastModified) {}

void File::print()
{
	cout << "File:          " << name << endl;
	cout << "Last modified: ";
	lastModified.print();
	cout << endl;
}

bool File::lessThan(const File &e)
{
	// TODO: change this implementation
	return e.getName() == name ? lastModified.lessThan(e.lastModified) : name < e.getName();
}

bool File::equals(const File &e)
{
	return name == e.getName() && lastModified.equals(e.lastModified);
}

void File::printContents()
{
	print();
	cout << endl
		 << content << endl
		 << endl;
}

void File::print() const
{
	cout << "File:          " << name << endl;
	cout << "Last modified: ";
	lastModified.print();
	cout << endl;
}

bool File::lessThan(const File &e) const
{
	// TODO: change this implementation
	return e.getName() == name ? lastModified.lessThan(e.lastModified) : name < e.getName();
}

bool File::equals(const File &e) const
{
	return name == e.getName() && lastModified.equals(e.lastModified);
}

void File::printContents() const
{
	print();
	cout << endl
		 << content << endl
		 << endl;
}