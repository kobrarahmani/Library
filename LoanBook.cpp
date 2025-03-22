//#include "LoanBooks.h"
//#include<fstream>
//#include<sstream>
//LoanBooks::LoanBooks() {};
////LoanBooks::LoanBooks(int lC,int clB,int mem,Date tim(int ,int,int),Date rT(int ,int ,int ))
////{
////	int m, d, y;
////	setL(lC);
////	setCL(clB);
////	setML(mem);
////	setTa(tim(m,d,y));
////	setRe(rT(m,d,y));
////}
//void LoanBooks::setCL(int cLB) 
//{
//	if (cLB >= 0)
//		codeB = cLB;
//	else
//		throw invalid_argument("Please enter (code>0)");
//}
//void LoanBooks::setML(int mem)
//{
//	if (mem >= 0) 
//		codeM = mem;
//	else
//		throw invalid_argument("Please enter (code>0)");
//}
//void LoanBooks::setL(int lC)
//{
//	if (lC >= 0)
//		codeL = lC;
//	else
//		throw invalid_argument("Please enter (code>0)");
//}
//bool LoanBooks::checkB(int cB) {
//	bool flag = false;
//	vector<Books> bk;
//	LoanBooks obj1;
//	if (obj1.prSe(bk, cB)) {
//		flag = true;
//	}
//	return flag;
//}
//bool LoanBooks::checkM(int cM) {
//	bool flag = false;
//	vector<Members> mL;
//	LoanBooks obj2;
//	if (obj2.prMe(mL, cM))
//		flag = true;
//	return flag;
//}
//void LoanBooks::setTa(Date ta(int,int,int)) {
//	int d, y, m;
//	cout << "Please enter the current year:\n";
//	cin >> y;
//	cout << "Please enter the month:\n";
//	cin >> m;
//	cout << "Please enter the day:\n";
//	cin >> d;
//	ta(m, d, y);
//}
//void LoanBooks::setRe(Date re(int,int,int)) {
//	int y, d, m;
//	cout << "Please enter the current year:\n";
//	cin >> y;
//	cout << "Please enter the resiving month:\n";
//	cin >> m;
//	cout << "Please enter the resiving day:\n";
//	cin >> d;
//	re(m, d, y);
//}
/////////////////////inserting new loan book////////////////////////
//void LoanBooks::inLBook(vector <LoanBooks> &B) {
//	    LoanBooks obj4;
//		int lC,clB,mem;
//		Date tim,rT;
//		obj4.vecLBook(B);
//		do {
//			cout << "PLease enter loan code:\n";
//			cin >> lC;
//			try {
//				obj4.setL(lC);
//			}
//			catch (invalid_argument &e) {
//				cout << "Error: " << e.what() << endl;
//			}
//			if (obj4.seSameLC(B, lC))
//			{
//				cout << "The Loan code is already exist!\n";
//			}
//			if ((getL()>0)||!(obj4.seSameLC(B, lC))) {
//				break;
//			}
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');//if a character enters
//		} while ((obj4.seSameLC(B, lC)) || (getL()<0));
//		do {
//			cout << "Please enter the Book code:\n";
//			cin >> clB;
//			try {
//				obj4.setCL(clB);
//			}
//			catch (invalid_argument &e) {
//				cout << "Error: " << e.what() << endl;
//			}
//			obj4.checkB(clB);
//			if ((obj4.checkB(clB)) || (getCL() > 0))
//				break;
//			if (!(obj4.checkB(clB)))
//				cout << "The code book does not exist!\n";
//		} while(!(obj4.checkB(clB))||(getCL()<0));
//		do {
//			cout << "Please enter member code:\n";
//			cin >> mem;
//			try {
//				obj4.setML(mem);
//			}
//			catch (invalid_argument &e) {
//				cout << "Error: " << e.what() << endl;
//			}
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');//if a character enters
//		} while (obj4.getML() < 0);
//		obj4.setTa(tim);
//		obj4.setRe(rT);
//		LoanBooks(getL(),getCL(),getML(),getTa(),getReDate());
//		B.push_back(obj4);
//		obj4.fLBook(B);
//		system("cls");
//	}
//bool LoanBooks::seSameLC(vector<LoanBooks> &aB, int cB) {
//		bool flag = false;
//		for (vector<int>::size_type i = 0; i < aB.size(); i++) {
//			if (aB[i].getL() == cB) {
//				flag = true;
//			}
//		}
//		return flag;
//	}
//void LoanBooks::seIdLBook(vector<LoanBooks> &vec) {
//		vec.clear();
//		LoanBooks AB;
//		ifstream fileL;
//		fileL.open("LoanBooks.txt");
//		string line = "";
//		fileL.ignore(numeric_limits<streamsize>::max(), ' ');
//		while (getline(fileL, line))
//		{
//			string temp = "";
//			string temp1 = "";
//			string temp2 = "";
//			string temp3 = "";
//			string temp4 = "";
//			string temp5 = "";
//			string temp6 = "";
//			string temp7 = "";
//			string temp8 = "";
//			stringstream inputString(line);
//			getline(inputString , temp, '\t');
//			setL(atoi(temp.c_str()));
//			getline(inputString, temp1, '\t');
//			setCL(atoi(temp.c_str()));
//			getline(inputString, temp2, '\t');
//			setML(atoi(temp.c_str()));
//			getline(inputString, temp3, '/');
//			getline(inputString, temp4, '/');
//			getline(inputString, temp5, '\t');
//			Date setTa(atoi(temp3.c_str()), atoi(temp4.c_str()), atoi(temp5.c_str()));
//			getline(inputString, temp6, '/');
//			getline(inputString, temp7, '/');
//			getline(inputString, temp8, '\n');
//			Date setRe(atoi(temp6.c_str()), atoi(temp7.c_str()), atoi(temp8.c_str()));
//			LoanBooks(getL(),getML(),getCL(),getTa(),getReDate());
//			vec.push_back(AB);
//			temp = "";
//			line = "";
//		}
//		fileL.close();
//	}
//void LoanBooks::delLId(int id) 
//{
//		id = 0;
//}
//void LoanBooks::fLBook(vector<LoanBooks> &aB) {
//	Date obj1,obj2;
//		int status;
//		status = remove("LoanBooks.txt");
//		ofstream fb("LoanBooks.txt", ios::app);
//		fb << aB.size() << " ";
//		for (vector<int>::size_type i = 0; i < aB.size(); i++) {
//			fb << aB[i].getL() << "\t" << aB[i].getCL() << "\t" << aB[i].getML()
//				<< "\t" <<aB[i].getTa()<<"\t"<<aB[i].getReDate()<<endl;
//	}
//		/*Books AB;
//		AB.
//		fb << aB.size() <<endl;
//		fb.close();*/
//	}
//void LoanBooks::reLBook() {
//		ifstream fiRe("LoanBooks.txt");
//		string n;
//		while (fiRe.good()) {
//			getline(fiRe, n);
//			cout << n << endl;
//		}
//		cin.ignore();
//	}
//void LoanBooks::vecLBook(vector<LoanBooks> &vecB) {
//		ifstream fiSe("LoanBooks.txt");
//		int i = 0;
//		string n;
//		while (fiSe.good()) {
//			getline(fiSe, n);
//		}
//		LoanBooks AB;
//		AB.seIdLBook(vecB);
//		cin.ignore();
//	}
//void LoanBooks::seLBook(vector<LoanBooks> &aB, int id) {
//		bool flag = false;
//		cout << "Please enter the Loan Book code:\n";
//		cin >> id;
//		LoanBooks AB;
//		AB.seIdLBook(aB);
//		vector<int>::size_type i = 0;
//		for (i = 0; i <aB.size(); i++) {
//			if (aB[i].getL() == id) {
//				flag = true;
//				break;
//			}
//		}
//		if (flag) {
//			cout << aB[i].getL() << " " << aB[i].getCL() << " " << aB[i].getML() << endl;
//		}
//	}
//void LoanBooks::edFLBook(vector<LoanBooks> &aB) {
//		LoanBooks B;
//		int status;
//		status = remove("LoanBooks.txt");
//		for (vector<int>::size_type i = 0; i < aB.size(); i++) {
//			for (vector<int>::size_type j = 0; j < aB.size(); j++) {
//				if (i == j)
//					continue;
//				if ( aB[i].getL() == aB[j].getL()) {
//					aB.erase(aB.begin() + j);
//				}
//			}
//		}
//		B.fLBook(aB);
//	}
//void LoanBooks::edLBook(vector<LoanBooks> &aB) {
//		bool flag = false;
//		LoanBooks obj1;
//		int naB;
//		cout << "Please enter code of loan book for editing:\n";
//		cin >> naB;
//		obj1.seIdLBook(aB);
//		vector<int>::size_type i = 0;
//		for (; i < aB.size(); i++) {
//			if (naB == aB[i].getL()) {
//				flag = true;
//				break;
//			}
//		}
//		if (flag) {
//			cout << aB[i].getL() << " " << aB[i].getCL() << " " << aB[i].getML() << endl;
//			obj1.delLId(aB[i].getL());
//			int temp;
//			cout << "Please enter new id:\n";
//			cin >> temp;
//			aB[i].setL(temp);
//			obj1.edFLBook(aB);
//		}
//		else
//			cout << "not found!\n";
//	}
//void LoanBooks::delNaIdLBook(vector<LoanBooks> &aB, int id) {
//		cout << "Plese enter book code for delete:\n";
//		cin >> id;
//		bool flag = false;
//		LoanBooks obj3;
//		obj3.seIdLBook(aB);
//		vector<int>::size_type i = 0;
//		for (; i < aB.size(); i++) {
//			if (aB[i].getL() == id) {
//				flag = true;
//				break;
//			}
//		}
//		if (flag)
//			aB.erase(aB.begin() + i);
//		int status;
//		status = remove("LoanBooks.txt");
//		obj3.fLBook(aB);
//	}
//LoanBooks::~LoanBooks()
//{
//}
