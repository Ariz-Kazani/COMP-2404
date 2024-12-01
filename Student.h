#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <ostream>

using namespace std;

class TestClass;

class Student
{
  friend class TestClass;
  friend ostream &operator<<(ostream &, const Student &);

public:
  Student(string = "000000000", string = "Hey you!", float = 0.0f);
  Student(const Student &);

  bool operator==(const Student &) const;

  bool goodGPA() const { return gpa >= 6.0; }
  float getGPA() const { return gpa; }
  string getNumber() const { return number; }
  string getName() const { return name; }

private:
  string number;
  string name;
  float gpa;
};

#endif
