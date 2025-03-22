#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include <iomanip>
#include <string>
#include"Books.h"
#include"Members.h"
#include"LoanBooks.h"
using namespace std;
void chBook() {
	int m, n = 0, id = 0;
	Books objB;
	vector<Books> A;
	do {
		cout << "Please choose from choices below:\n" <<
			"1.Print books\n"
			<< "2.insert book\n"
			<< "3.Search for book\n"
			<< "4.edit\n"
			<< "5.Delete a book\n" <<
			"6.Back\n";
		cin >> m;
		system("cls");
		switch (m) {
		case 1:
			objB.reBook();////////read books from file////////
			break;
		case 2:
			objB.inBook(A);
			++n;
			break;
		case 3:
			objB.seBook(A, id);
			break;
		case 4:
			objB.edBook(A);
			break;
		case 5:
			objB.delNaIdBook(A, id);
			break;
		case 6:
			break;
		default:
			cin.fail();
			cout << "Please enter an integet(1-6)\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (m != 6);
}
/////////members choices////////////
void chMember() {
	int m, n = 0, id = 0;
	Members objB;
	vector<Members> A;
	do {
		cout << "Please choose from choices below:\n" <<
			"1.Print Members\n"
			<< "2.insert Members\n"
			<< "3.Search for Members\n"
			<< "4.edit\n"
			<< "5.Delete a Member\n" <<
			"6.Back\n";
		cin >> m;
		system("cls");
		switch (m) {
		case 1:
			objB.reMember();////////read members from file////////
			break;
		case 2:
			objB.inMember(A);
			++n;
			break;
		case 3:
			objB.seMember(A, id);
			break;
		case 4:
			objB.edMember(A);
			break;
		case 5:
			objB.delNaIdMember(A, id);
			break;
		case 6:
			break;
		default:
			cin.fail();
			cout << "Please enter an integet(1-6)\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (m != 6);
}
///////loan choices////////////
//void chLoan() {
//	int m, n = 0, id = 0;
//	LoanBooks objB;
//	vector<LoanBooks> A;
//	do {
//		cout << "Please choose from choices below:\n" <<
//			"1.Print LoanBooks\n"
//			<< "2.insert new record\n"
//			<< "3.Search for Loanbook\n"
//			<< "4.edit\n"
//			<< "5.Delete a record\n" <<
//			"6.Back\n";
//		cin >> m;
//		system("cls");
//		switch (m) {
//		case 1:
//			objB.reLBook();////////read books from file////////
//			break;
//		case 2:
//			objB.inLBook(A);
//			++n;
//			break;
//		case 3:
//			objB.seLBook(A, id);
//			break;
//		case 4:
//			objB.edLBook(A);
//			break;
//		case 5:
//			objB.delNaIdLBook(A, id);
//			break;
//		case 6:
//			break;
//		default:
//			cin.fail();
//			cout << "Please enter an integet(1-6)\n";
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//		}
//	} while (m != 6);
//}
///////general choices////////////
void chioce() {
	int n, b = 0;
	do {
		cout << "please enter a choice: \n" <<
			"1.Book section\n" <<
			"2.Member \n" <<
			"3.Loan a Book\n"<<
			"4.exit\n";
		cin >> n;
		system("cls");
		switch (n) {
		case 1:
			chBook();
			break;
		case 2:
			chMember();
			break;
		/*case 3:
			chLoan();*/
		case 3:
			break;
		case 4:
			break;
		default:
			cin.fail();
			cout << "Please enter an integet(1-2)\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (n != 4 || n !=3);
}
int main() {
	chioce();
	system("pause");
}
