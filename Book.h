#pragma once
#include"Date.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Books
{
private:
	string name;
	string author;
	Date datePub;
	int code;
	int num;//number of book

public:
	Books();
	void Boo(string, string, int, double,Date d);
	void setN(string);
	void setC(int);
	void setNum(int);
	void setA(string);
	void setDate(Date);
	int getNum() { return num; };
	string getN() { return name; };
	int getId() { return code; };
	string getA() { return author; };
	void inBook(vector <Books> &);//inserting book specifications
	void fBook(vector<Books> &);
	void reBook();//print books list in a file
	void seBook(vector<Books> &, int);
	bool prSe(vector<Books> &, int);
	void edBook(vector<Books> &);//for editing books info
	void edFBook(vector<Books> &);
	void delId(int);//for editing id
	void vecBook(vector<Books> &);
	bool seSameN(vector<Books> &, string);
	bool seSameC(vector<Books> &, int);
	void seIdBook(vector<Books> &); //reading from file
	void delNaIdBook(vector<Books> &, int);
	~Books();
};

