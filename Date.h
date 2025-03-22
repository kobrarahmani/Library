#pragma once
class Date
{
private:
	int month;
	int day;
	int year;
	unsigned int checkDay(int) const;
public:
	void setm(int m);
	void setd(int d);
	void sety(int y);
	int getd() { return day; };
	int gety() { return year; };
	int getm() {return month;}
	static const int monthsPerYear = 12;
	Date();
	Date(int, int , int);
	void print() const;
	~Date();
};

