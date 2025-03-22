#include "Members.h"
#include<fstream>
#include <sstream>
Members::Members() {
}
void Members::Mem(string naM, string laM, int cM, string adM, string enY)
{
	setN(naM);
	setL(laM);
	setC(cM);
	setAd(adM);
	setEnY(enY);
}
void Members::setN(string naM) {
	if (naM != "")
		name = naM;
	else
		throw invalid_argument("The name is invalid!");
}
void Members::setL(string laM) {
	if (laM != "")
		laName = laM;
	else
		throw invalid_argument("The last_name is invalid!");
}
void Members::setC(int cM) {
	if (cM >= 0)
		code = cM;
	else
		throw invalid_argument("The code is invalid! Try (code>0)");
}
void Members::setAd(string adM) {
	if (adM != "")
		address = adM;
	else
		throw invalid_argument("The address is invalid!");
}
void Members::setEnY(string enY) {
	if (enY != "")
		enYear = enY;
	else
		throw invalid_argument("The year is invalid!");
}
void Members::inMember(vector <Members> &M) {
	Members obj1;
	string naM, laM, adM, enY;
	int cM;
	obj1.vecBook(M);
	do {
		cout << "PLease enter member name:\n";
		getline(cin, naM);
		try {
			obj1.setN(naM);
		}
		catch (invalid_argument &e) {
			cout << "Error: " << e.what() << endl;
		}
		cout << "Please enter the last_name:\n";
		getline(cin, laM);
		try {
			obj1.setL(laM);
		}
		catch (invalid_argument &e) {
			cout << "Error: " << e.what() << endl;
		}
		if (obj1.seSameN(M, naM, laM))
		{
			cout << "The member name is already exist!\n";
		}
		if ((obj1.getN() == "") && (obj1.getL() == "") && !(obj1.seSameN(M, naM, laM))) {
			break;
		}
	} while ((obj1.getN() == "") || (obj1.getL() == "") || (obj1.seSameN(M, naM, laM)));
	do {
		cout << "Please enter member code:\n";
		cin >> cM;
		try {
			obj1.setC(cM);
		}
		catch (invalid_argument &e) {
			cout << "Error: " << e.what() << endl;
		}
		if (obj1.seSameC(M, cM)) {
			cout << "The member code is already exist!\n";
		}
		if ((obj1.getId() >= 0) && !(obj1.seSameC(M, cM))) {
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//if a character enters
	} while ((obj1.getId() <0) || (obj1.seSameC(M, cM)));
	do {
		cout << "Please enter the address:\n";
		cin.ignore();
		getline(cin, adM);
		try {
			obj1.setAd(adM);
		}
		catch (invalid_argument &e) {
			cout << "Error: " << e.what() << endl;
		}
	} while (obj1.getAd() == "");
	do {
		cout << "Please enter the entry year:\n";
		getline(cin, enY);
		try {
			obj1.setEnY(enY);
		}
		catch (invalid_argument &e) {
			cout << "Error: " << e.what() << endl;
		}
	} while (obj1.getEnY() == "");
	obj1.Mem(naM, laM, cM, adM, enY);
	M.push_back(obj1);
	obj1.fMember(M);
	system("cls");
}
bool Members::seSameN(vector<Members> &aM, string na, string la) {
	bool flag = false;
	for (vector<int>::size_type i = 0; i < aM.size(); i++) {
		if ((aM[i].getN() == na) && (aM[i].getL() == la)) {
			flag = true;
		}
	}
	return flag;
}
bool Members::seSameC(vector<Members> &aM, int cM) {
	bool flag = false;
	for (vector<int>::size_type i = 0; i < aM.size(); i++) {
		if (aM[i].getId() == cM) {
			flag = true;
		}
	}
	return flag;
}
void Members::seIdMember(vector<Members> &vec) {
	vec.clear();
	Members obj2;
	ifstream seFile;
	seFile.open("Members.txt");
	string line = "";
	seFile.ignore(numeric_limits<streamsize>::max(), ' ');
	while (getline(seFile, line))
	{
		string temp = "";
		string temp1 = "";
		string temp2 = "";
		string temp3 = "";
		string temp4 = "";
		stringstream inputString(line);
		getline(inputString >> ws, temp, '\t');
		setN(temp);
		getline(inputString, temp1, '\t');
		setL(temp1);
		getline(inputString, temp2, '\t');
		setC(atoi(temp2.c_str()));
		getline(inputString, temp3, '\t');
		setAd(temp3);
		getline(inputString, temp4, '\n');
		setEnY(temp4);
		obj2.Mem(getN(), getL(), getId(), getAd(), getEnY());
		vec.push_back(obj2);
		temp = "";
		line = "";
	}
	seFile.close();
}
void Members::delId(int id) {
	id = 0;
}
void Members::fMember(vector<Members> &aM) {
	int status;
	status = remove("Members.txt");
	ofstream fb("Members.txt", ios::app);
	fb << aM.size() << " ";
	for (vector<int>::size_type i = 0; i < aM.size(); i++) {
		fb << aM[i].getN() << "\t" << aM[i].getL() << "\t" << aM[i].getId()
			<< "\t" << aM[i].getAd() << "\t" << aM[i].getEnY() << endl;
	}
	//Books AB;
	//AB.seIdBook(vecBo);
	//fb << vecBo.size() <<endl;
	fb.close();
}
void Members::reMember() {
	ifstream fiRe("Members.txt");
	string n;
	while (fiRe.good()) {
		getline(fiRe, n);
		cout << n << endl;
	}
	cin.ignore();
}
void Members::vecBook(vector<Members> &vecM) {
	ifstream fiSe("Members.txt");
	int i = 0;
	string n;
	while (fiSe.good()) {
		getline(fiSe, n);
	}
	Members AM;
	AM.seIdMember(vecM);
	cin.ignore();
}
void Members::seMember(vector<Members> &aM, int id) {
	bool flag = false;
	cout << "Please enter member new code:\n";
	cin >> id;
	Members AB;
	AB.seIdMember(aM);
	vector<int>::size_type i = 0;
	for (i = 0; i <aM.size(); i++) {
		if (aM[i].getId() == id) {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << aM[i].getN() << " " << aM[i].getId() << " " << aM[i].getL() << endl;
	}
}
bool Members::prMe(vector<Members> &aM, int id) {
	bool flag = false;
	cout << "Please enter member new code:\n";
	cin >> id;
	Members AB;
	AB.seIdMember(aM);
	vector<int>::size_type i = 0;
	for (i = 0; i <aM.size(); i++) {
		if (aM[i].getId() == id) {
			flag = true;
			break;
		}
	}
	return flag;
}
void Members::edFMember(vector<Members> &aM) {
	Members M;
	int status;
	status = remove("Members.txt");
	for (vector<int>::size_type i = 0; i < aM.size(); i++) {
		for (vector<int>::size_type j = 0; j < aM.size(); j++) {
			if (i == j)
				continue;
			if (aM[i].getId() == aM[j].getId()) {
				aM.erase(aM.begin() + j);
			}
		}
	}
	M.fMember(aM);
}
void Members::edMember(vector<Members> &aM) {
	bool flag = false;
	Members obj1;
	string naM;
	cout << "Please enter Member name for editing:\n";//try and catch?
	getline(cin, naM);
	getline(cin >> ws, naM);
	obj1.seIdMember(aM);
	vector<int>::size_type i = 0;
	for (; i < aM.size(); i++) {
		if (naM == aM[i].getN()) {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << aM[i].getN() << " " << aM[i].getL() << " " << aM[i].getId() << endl;
		obj1.delId(aM[i].getId());
		int temp;
		cout << "Please enter new id:\n";
		cin >> temp;
		aM[i].setC(temp);
		obj1.edFMember(aM);
	}
	else
		cout << "not found!\n";
}
void Members::delNaIdMember(vector<Members> &aM, int id) {
	cout << "Plese enter book code for delete:\n";
	cin >> id;
	bool flag = false;
	Members obj3;
	obj3.seIdMember(aM);
	vector<int>::size_type i = 0;
	for (; i < aM.size(); i++) {
		if (aM[i].getId() == id) {
			flag = true;
			break;
		}
	}
	if (flag)
		aM.erase(aM.begin() + i);
	int status;
	status = remove("Books.txt");
	obj3.fMember(aM);
}
Members::~Members()
{
}
