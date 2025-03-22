#include "Date.h"
#include<array>
#include<iostream>
#include<stdexcept>
using namespace std;

Date::Date() {}
Date::Date(int mn,int dy,int yr)
{
	setm(mn);
	setd(dy);
	sety(yr);
}
void Date::setd(int da) {
	if (da >= 1 && da <= 30 )
		day = checkDay(da);
	else
		throw invalid_argument("day is invalid!");
}
void Date::setm(int mo) {
	if (mo > 0 && mo <= monthsPerYear)
		month = mo;
	else
		throw invalid_argument("month must be 1-12");
}
void Date::sety(int ye) {
	if (ye > 0)
		year = ye;
	else
		throw invalid_argument("year cant be less then 0");
}
void Date::print() const
{
	cout << month << '/' << day << '/' << year;
}
unsigned int Date::checkDay(int testDay) const {
	static const array<int, monthsPerYear + 1>daysPerMonth =
	{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (testDay > 0 && testDay <= daysPerMonth[month])
		return testDay;
	if (month == 2 && testDay == 29 && (year % 400 == 0 ||
		(year % 4 == 0 && year % 100 != 0)))
		return testDay;
	throw invalid_argument("Invalid day for current month and yeat.");
}

Date::~Date()
{
}
