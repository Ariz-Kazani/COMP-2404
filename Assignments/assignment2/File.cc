#include "File.h";

File::File(string name, string content, Date &date)
{
    this->name = name;
    this->content = content;
    this->date = date;
}

bool File::lessThan(Date &date)
{
    return this->date.lessThan(date);
}

void File::print()
{
    cout << "File: " << name << endl;
    cout << "Date: ";
    date.print();
    cout << endl;
}

void File::printContents()
{
    this->print();
    cout << "Contents: " << content << endl;
}