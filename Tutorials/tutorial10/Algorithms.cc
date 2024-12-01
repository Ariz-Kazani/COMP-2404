#include "Algorithms.h"

Algorithms::Algorithms()
{
    students = new vector<Student>;
}

Algorithms::~Algorithms()
{
    delete students;
}

void Algorithms::addStudent(const string &number, const string &name, float gpa)
{
    students->push_back(Student(number, name, gpa));
}

void Algorithms::getPassingStudents(vector<Student> &v)
{
    for (int i = 0; i < students->size(); i++)
    {
        if (students->at(i).goodGPA())
        {
            v.push_back(students->at(i));
        }
    }
}

void Algorithms::sortByNumber(vector<Student> &v)
{
    v = *students;
    sort(v.begin(), v.end(), [](const Student &a, const Student &b)
         { return a.getNumber() < b.getNumber(); });
}

void Algorithms::sortByName(vector<Student> &v)
{
    v = *students;
    sort(v.begin(), v.end(), [](const Student &a, const Student &b)
         { return a.getName() < b.getName(); });
}

bool Algorithms::highestGpa(vector<Student>::iterator &stuIt)
{
    if (students->size() == 0)
    {
        return false;
    }
    stuIt = students->begin();
    for (vector<Student>::iterator it = students->begin(); it != students->end(); ++it)
    {
        if (it->getGPA() > stuIt->getGPA())
        {
            stuIt = it;
        }
    }
    return true;
}

bool Algorithms::findStudent(const string &name, vector<Student>::iterator &stuIt)
{
    for (vector<Student>::iterator it = students->begin(); it != students->end(); ++it)
    {
        if (it->getName() == name)
        {
            stuIt = it;
            return true;
        }
    }
    return false;
}