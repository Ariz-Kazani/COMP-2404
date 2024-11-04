#include "File.h"

File::File(const string &name, const string &content, Date &date) : lastModified(date), name(name), content(content) {}

File::File(File &e) : File(e.name, e.content, e.lastModified) {}

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
