#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Members
{
private:
	string name;
	string laName;
	int code;
	string address;
	string enYear;//entry year
public:
	Members();
	void Mem(string, string, int, string, string);
	void setN(string);
	void setL(string);
	void setC(int);
	void setAd(string);
	void setEnY(string);
	string getN() { return name; };
	string getL() { return laName; };
	int getId() { return code; };
	string getAd() { return address; }
	string getEnY() { return enYear; };
	void inMember(vector <Members> &);//inserting book specifications
	void fMember(vector<Members> &);
	void reMember();//print Members list in a file
	void seMember(vector<Members> &, int);
	bool prMe(vector<Members> &, int);
	void edMember(vector<Members> &);//for editing books info
	void edFMember(vector<Members> &);
	void delId(int);//for editing id
	void vecBook(vector<Members> &);
	bool seSameN(vector<Members> &, string, string);
	bool seSameC(vector<Members> &, int);
	void seIdMember(vector<Members> &);
	void delNaIdMember(vector<Members> &, int);
	~Members();
};

