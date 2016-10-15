#include <iostream>
#include <stdlib.h>
#include <string>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include "Books.h"
using namespace std;

int main() {

	int *selection = new int;

	cout << "ENTER YOUR SELECTION" << endl;
	cout << "1.	Checkout a book.\n";
	cout << "2.	Checkin a book.\n";
	cout << "3.	Add a new book.\n";
	cout << "4.	Add a new user.\n";
	cout << "5.	List all books.\n";
	cout << "6.	List all users.\n";
	cout << "7.	Delete book.\n";
	cout << "8.	Delete user.\n";
	cout << "9.	Exit.\n";

	cin >> *selection;

	switch (*selection) {
		case 1:
		{
			delete selection;
			system("CLS");
			cin.ignore();
			checkOut *check = new checkOut;
			check->checkO();
			break;
		}
		case 2:
		{
			delete selection;
			system("CLS");
			cin.ignore();
			checkIn *check = new checkIn;
			check->checkI();
			break;
		}
		case 3:
		{
			delete selection;
			system("CLS");
			cin.ignore();
			addBook *addB = new addBook;
			addB->add();
			break;
		}
		case 4:
		{
			delete selection;
			system("CLS");
			cin.ignore();
			addUser *addU = new addUser;
			addU->addU();
		}
		case 5:
		{
			delete selection;
			system("CLS");
			listAllBooks *listB = new listAllBooks;
			listB->listB();
			break;
		}
		case 6:
		{
			delete selection;
			system("CLS");
			listAllUsers *listU = new listAllUsers;
			listU->listU();
			break;
		}
		case 7:
		{
			delete selection;
			system("CLS");
			delBook *dB = new delBook;
			dB->del();
			break;
		}
		case 8:
		{
			delete selection;
			system("CLS");
			delUser *dU = new delUser;
			dU->del();
			break;
		}
		case 9:
		{
			system("EXIT");
		}
	}
}
