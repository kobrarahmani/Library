#include "Books.h"
#include"Date.h"
#include<fstream>
#include <sstream>
Books::Books(){
}
void Books::Boo(string naB, string auB, int cB, double numB,Date da)
{
	setN(naB);
	setA(auB);
	setC(cB);
	setNum(numB);
	setDate(da);
}
void Books::setN(string naB) {
	if (naB != "")
		name = naB;
	else
		throw invalid_argument("The book name is invalid!");
}
void Books::setA(string auB) {
	if (auB != "")
		author = auB;
	else
		throw invalid_argument("The author name is invalid!");
}
void Books::setC(int cB) {
	if (cB >= 0)
		code = cB;
	else
		throw invalid_argument("The code is invalid! Try (code>0)");
}
void Books::setNum(int numB) {
	if (numB >= 0)
		num = numB;
	else
		throw invalid_argument("The number is invalid! Try (number of book >0)");
}
void Books::setDate(Date da) {
	datePub = da;
}
void Books::inBook(vector <Books> &B) {
	Books Bo;
	int cB, numB,d,m,y;
	string naB, auB;
	Date date;
	Bo.vecBook(B);
	do {
		cout << "PLease enter book name:\n";
		getline(cin, naB);
		try {
			Bo.setN(naB);
		}
		catch (invalid_argument &e) {
			cout << "Error: " << e.what() << endl;
		}
		if (Bo.seSameN(B, naB))
		{
			cout << "The book name is already exist!\n";
		}
		if ((Bo.getN() != "") && !(Bo.seSameN(B, naB))) {
			break;
		}
	} while ((Bo.getN() == "") || (Bo.seSameN(B, naB)));
	do {
		cout << "Please enter the author:\n";
		getline(cin, auB);
		try {
			Bo.setA(auB);
		}
		catch (invalid_argument &e) {
			cout << "Error: " << e.what() << endl;
		}
	} while (Bo.getA() == "");
	do {
		cout << "Please enter book code:\n";
		cin >> cB;
		try {
			Bo.setC(cB);
		}
		catch (invalid_argument &e) {
			cout << "Error: " << e.what() << endl;
		}
		if (Bo.seSameC(B, cB)) {
			cout << "The book code is already exist!\n";
		}
		if ((Bo.getId() >= 0) && !(Bo.seSameC(B, cB))) {
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//if a character enters
	} while ((Bo.getId() <0) || (Bo.seSameC(B, cB)));
	do {
		cout << "Please enter num of book:\n";
		cin >> numB;
		try {
			Bo.setNum(numB);
		}
		catch (invalid_argument &e) {
			cout << "Error: " << e.what() << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (Bo.getNum() < 0);
	do {
		cout << "Please enter the month: ";
		cin >> m;
		try {
			date.setm(m);
		}
		catch (invalid_argument &e) {
			cout << "Error: " << e.what() << endl;
		}
		cout << "Please enter the day: ";
		cin >> d;
		try
		{
			date.setd(d);
		}
		catch (invalid_argument &e) {
			cout << "Error: " << e.what() << endl;
		}
		cout << "Please enter the year: ";
		cin >> y;
		try {
			date.sety(y);
		}
		catch (invalid_argument &e) {
			cout << "Error: " << e.what() << endl;
		}
	} while (date.getm() < 0 && date.getm() > date.monthsPerYear && date.getd() < 1 &&
		date.getd() > 30 && date.gety() < 0);
	
	Bo.Boo(naB, auB, cB, numB, date);
	B.push_back(Bo);
	Bo.fBook(B);
	system("cls");
}
bool Books::seSameN(vector<Books> &aB, string na) {
	bool flag = false;
	for (vector<int>::size_type i = 0; i < aB.size(); i++) {
		if (aB[i].getN() == na) {
			flag = true;
		}
	}
	return flag;
}
bool Books::seSameC(vector<Books> &aB, int cB) {
	bool flag = false;
	for (vector<int>::size_type i = 0; i < aB.size(); i++) {
		if (aB[i].getId() == cB) {
			flag = true;
		}
	}
	return flag;
}
//////reading from file///////////
void Books::seIdBook(vector<Books> &vec) {
	vec.clear();
	Books AB;
	Date date;
	ifstream seFile;
	seFile.open("Books.txt");
	string line = "";
	seFile.ignore(numeric_limits<streamsize>::max(), ' ');//ignores the first line that is the count
	while (getline(seFile, line))
	{
		string temp = "";
		string temp1 = "";
		string temp2 = "";
		string temp3 = "";
		string temp4 = "";
		string temp5 = "";
		string temp6 = "";
		stringstream inputString(line);
		getline(inputString >> ws, temp, '\t');
		setN(temp);
		getline(inputString, temp1, '\t');
		setA(temp1);
		getline(inputString, temp2, '\t');
		setC(atoi(temp2.c_str()));
		getline(inputString, temp3, '\t');
		setNum(atof(temp3.c_str()));
		getline(inputString, temp4, '/');
		date.setd(atoi(temp4.c_str()));
		getline(inputString, temp5, '/');
		date.setm(atoi(temp5.c_str()));
		getline(inputString, temp6, '\n');
		date.sety(atoi(temp6.c_str()));
		AB.Boo(getN(), getA(), getId(), getNum(),date);
		vec.push_back(AB);
		temp = "";
		line = "";
	}
	seFile.close();
}
void Books::delId(int id) {
	id = 0;
}
//////inserting to file////////
void Books::fBook(vector<Books> &aB) {
	int status;
	status = remove("Books.txt");
	ofstream fb("Books.txt", ios::app);
	fb << aB.size() << " ";
	for (vector<int>::size_type i = 0; i < aB.size(); i++) {
		fb << aB[i].getN() << "\t" << aB[i].getA() << "\t" << aB[i].getId()
			<< "\t" << aB[i].getNum() << "\t" << aB[i].datePub.getd()<<"/"<<aB[i].datePub.getm()<<
			"/"<<aB[i].datePub.gety()<< endl;
	}
	//Books AB;
	//AB.seIdBook(vecBo);
	//fb << vecBo.size() <<endl;
	fb.close();
}
void Books::reBook() {
	ifstream fiRe("Books.txt");
	string n;
	while (fiRe.good()) {
		getline(fiRe, n);
		cout << n << endl;
	}
	cin.ignore();
}
void Books::vecBook(vector<Books> &vecB) {
	ifstream fiSe("Books.txt");
	int i = 0;
	string n;
	while (fiSe.good()) {
		getline(fiSe, n);
	}
	Books AB;
	AB.seIdBook(vecB);
	cin.ignore();
}
void Books::seBook(vector<Books> &aB, int id) {
	bool flag = false;
	cout << "Please enter the Book code:\n";
	cin >> id;
	Books AB;
	AB.seIdBook(aB);
	vector<int>::size_type i = 0;
	for (i = 0; i <aB.size(); i++) {
		if (aB[i].getId() == id) {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << aB[i].getN() << " " << aB[i].getId() << " " << aB[i].getA()<<endl;
	}
}
bool Books::prSe(vector<Books>&aB, int id) {
	bool flag = false;
	Books AB;
	AB.seIdBook(aB);
	vector<int>::size_type i = 0;
	for (i = 0; i <aB.size(); i++) {
		if (aB[i].getId() == id) {
			flag = true;
			break;
		}
	}
	return flag;
}
void Books::edFBook(vector<Books> &aB) {
	Books B;
	int status;
	status = remove("Books.txt");
	for (vector<int>::size_type i = 0; i < aB.size(); i++) {
		for (vector<int>::size_type j = 0; j < aB.size(); j++) {
			if (i == j)
				continue;
			if (aB[i].getN() == aB[j].getN() || aB[i].getId() == aB[j].getId()) {
				aB.erase(aB.begin() + j);
			}
		}
	}
	B.fBook(aB);
}
void Books::edBook(vector<Books> &aB) {
	bool flag = false;
	Books obj1;
	string naB;
	cout << "Please enter name of book for editing:\n";
	getline(cin, naB);
	getline(cin >> ws, naB);
	obj1.seIdBook(aB);
	vector<int>::size_type i = 0;
	for (; i < aB.size(); i++) {
		if (naB == aB[i].getN()) {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << aB[i].getN() << " " << aB[i].getId() << " " << aB[i].getNum() << endl;
		obj1.delId(aB[i].getId());
		int temp;
		cout << "Please enter new id:\n";
		cin >> temp;
		aB[i].setC(temp);
		obj1.edFBook(aB);
	}
	else
		cout << "not found!\n";
}
void Books::delNaIdBook(vector<Books> &aB, int id) {
	cout << "Plese enter book code for delete:\n";
	cin >> id;
	bool flag = false;
	Books obj3;
	obj3.seIdBook(aB);
	vector<int>::size_type i = 0;
	for (; i < aB.size(); i++) {
		if (aB[i].getId() == id) {
			flag = true;
			break;
		}
	}
	if (flag)
		aB.erase(aB.begin() + i);
	int status;
	status = remove("Books.txt");
	obj3.fBook(aB);
}
Books::~Books()
{
}


