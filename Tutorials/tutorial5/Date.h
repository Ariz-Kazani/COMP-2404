
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date
{

public:
	// constructor
	Date();
	Date(int year, int month, int day);
	Date(const Date &);

	// setters
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDate(int, int, int);
	void setDate(Date &);

	// getters
	int getDay();
	int getMonth();
	int getYear();
	string getMonthName();

	// other
	void incDate();
	void addDays(int);
	bool lessThan(const Date &d);
	bool equals(const Date &d);
	void print();

	// getters
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	string getMonthName() const;

	// other
	void incDate() const;
	void addDays(int) const;
	bool lessThan(const Date &d) const;
	bool equals(const Date &d) const;
	void print() const;

private:
	// functions
	int getMaxDay();

	// variables
	int day;
	int month;
	int year;
};
#endif
