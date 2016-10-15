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
using namespace std;

class addBook {
public:
	string *title = new string;
	string *author = new string;
	string *isbn = new string;
	string *publisher = new string;
	int *pages = new int;
	int *pubdate = new int;

	void add() {
		try {
			
			sql::Driver *driver;
			sql::Connection *con;
			sql::PreparedStatement *pstmt;

			driver = get_driver_instance();
			con = driver->connect("tcp://192.168.0.12:3306", "testusername", "testpassword");
			con->setSchema("books");

			cout << "Enter the title: ";
			getline(cin, *title);
			cout << "Enter the author's name: ";
			getline(cin, *author);
			cout << "Enter the book's ISBN: ";
			getline(cin, *isbn);
			cout << "Enter the publisher's name: ";
			getline(cin, *publisher);	
			cin.sync();
			cout << "Enter the number of pages: ";
			cin >> *pages;
			cout << "Enter the publication date(MMDDYYYY): ";
			cin >> *pubdate;

			pstmt = con->prepareStatement("INSERT INTO bookinfo (title, author, isbn, publisher, pages, publicationdate) VALUES (?, ?, ?, ?, ?, ?)");

			pstmt->setString(1, *title);
			pstmt->setString(2, *author);
			pstmt->setString(3, *isbn);
			pstmt->setString(4, *publisher);
			pstmt->setInt(5, *pages);
			pstmt->setInt(6, *pubdate);
			pstmt->execute();

			delete title;
			delete author;
			delete isbn;
			delete publisher;
			delete pages;
			delete pubdate;

			cout << "Book added!" << endl;
			system("pause");
		}
		catch (sql::SQLException &e) {
			cout << "Error connecting to the database." << endl;
		} 
	}
};

class addUser {
public:
	string *firstname = new string;
	string *lastname = new string;
	string *address = new string;
	string *phonenumber = new string;
	int *dateofbirth = new int;

	void addU() {
		try {
			sql::Driver *driver;
			sql::Connection *con;
			sql::PreparedStatement *pstmt;

			driver = get_driver_instance();
			con = driver->connect("tcp://192.168.0.12:3306", "testusername", "testpassword");
			con->setSchema("books");

			cout << "Enter the first name: ";
			getline(cin, *firstname);
			cout << "Enter the last name: ";
			getline(cin, *lastname);
			cout << "Enter the address: ";
			getline(cin, *address);
			cout << "Enter the phone number: ";
			getline(cin, *phonenumber);
			cin.sync();
			cout << "Enter the date of birth (MMDDYYYY): ";
			cin >> *dateofbirth;

			pstmt = con->prepareStatement("INSERT INTO users (firstname, lastname, address, phonenumber, dateofbirth) VALUES (?, ?, ?, ?, ?)");

			pstmt->setString(1, *firstname);
			pstmt->setString(2, *lastname);
			pstmt->setString(3, *address);
			pstmt->setString(4, *phonenumber);
			pstmt->setInt(5, *dateofbirth);
			pstmt->execute();

			delete firstname;
			delete lastname;
			delete address;
			delete phonenumber;
			delete dateofbirth;

			cout << "User added!" << endl;
			system("pause");
		}
		catch (sql::SQLException &e) {
			cout << "Error connecting to the database." << endl;
		}
	}
};

class listAllBooks {
public:
	void listB() {
		try {
			sql::Driver *driver;
			sql::Connection *con;
			sql::Statement *stmt;
			sql::ResultSet *res;

			driver = get_driver_instance();
			con = driver->connect("tcp://192.168.0.12:3306", "testusername", "testpassword");
			con->setSchema("books");

			stmt = con->createStatement();
			res = stmt->executeQuery("SELECT * FROM bookinfo");

			while (res->next()) {
				cout << "ID: " << res->getInt("id") << " Title: " << res->getString("title") << " Author: " << res->getString("author") << " ISBN: " <<
					res->getString("isbn") << " Publisher: " << res->getString("publisher") << " # of pages: " << res->getInt("pages") << " Publication date: " << res->getInt("publicationdate") << endl << endl;
			}
			system("pause");
		}
		catch (sql::SQLException &e) {
			cout << "Error connecting to the database." << endl;
		}
	}
};

class listAllUsers {
public:
	void listU() {
		try {
			sql::Driver *driver;
			sql::Connection *con;
			sql::Statement *stmt;
			sql::ResultSet *res;

			driver = get_driver_instance();
			con = driver->connect("tcp://192.168.0.12:3306", "testusername", "testpassword");
			con->setSchema("books");

			stmt = con->createStatement();
			res = stmt->executeQuery("SELECT * FROM users");

			while (res->next()) {
				cout << "ID: " << res->getInt("id") << " First name: " << res->getString("firstname") << " Last name: " << res->getString("lastname") << " Address: " <<
					res->getString("address") << " Phone number: " << res->getString("phonenumber") << " Date of birth: " << res->getInt("dateofbirth") << endl << endl;
			}
			system("pause");
		}catch (sql::SQLException &e) {
			cout << "Error connecting to the database." << endl;
		}	
	}
};

class checkOut {
public:
	string *isbn = new string;
	int *checkoutdate = new int;

	void checkO() {
		try {
			sql::Driver *driver;
			sql::Connection *con;
			sql::PreparedStatement *pstmt;

			driver = get_driver_instance();
			con = driver->connect("tcp://192.168.0.12:3306", "testusername", "testpassword");
			con->setSchema("books");

			cout << "Enter the isbn of the book to check out: ";
			cin >> *isbn;
			cout << "Enter the check out date (MMDDYYYY): ";
			cin >> *checkoutdate;

			pstmt = con->prepareStatement("INSERT INTO checkout (isbn, checkoutdate) VALUES (?, ?)");

			pstmt->setString(1, *isbn);
			pstmt->setInt(2, *checkoutdate);
			pstmt->executeUpdate();

			delete con;
			delete pstmt;
			delete isbn;
			delete checkoutdate;

			cout << "Book checked out!" << endl;
			system("pause");
		}
		catch (sql::SQLException &e) {
			cout << "Error connecting to the database." << endl;
		}
	}
};

class checkIn {
public:
	string *isbn = new string;
	int *checkoutdate = new int;

	void checkI() {
		try {
			sql::Driver *driver;
			sql::Connection *con;
			sql::PreparedStatement *pstmt;

			driver = get_driver_instance();
			con = driver->connect("tcp://192.168.0.12:3306", "testusername", "testpassword");
			con->setSchema("books");

			cout << "Enter the isbn of the book to check in: ";
			cin >> *isbn;
			cout << "Enter the check in date (MMDDYYYY): ";
			cin >> *checkoutdate;

			pstmt = con->prepareStatement("INSERT INTO checkin (isbn, checkoutdate) VALUES (?, ?)");

			pstmt->setString(1, *isbn);
			pstmt->setInt(2, *checkoutdate);
			pstmt->executeUpdate();

			delete isbn;
			delete checkoutdate;

			cout << "Book checked in!" << endl;
			system("pause");

		}
		catch (sql::SQLException &e) {
			cout << "Error connecting to the database." << endl;
		}
	}
};

class delBook {
public:
	void del() {
		try {
			sql::Driver *driver;
			sql::Connection *con;
			sql::PreparedStatement *pstmt;

			driver = get_driver_instance();
			con = driver->connect("tcp://192.168.0.12", "testusername", "testpassword");
			con->setSchema("books");

			listAllBooks *list = new listAllBooks;
			list->listB();

			int erase = 0;
			cout << "Enter the ID of the book you want to erase: ";
			cin >> erase;

			pstmt = con->prepareStatement("DELETE FROM bookinfo WHERE id=?");
			pstmt->setInt(1, erase);
			pstmt->execute();

			delete pstmt;
			delete con;

			cout << "Book deleted!" << endl;
			system("pause");
		}
		catch (sql::SQLException &e) {
			cout << "Error connecting to the database." << endl;
		}
	}
};

class delUser {
public:
	void del() {
		try {
			sql::Driver *driver;
			sql::Connection *con;
			sql::PreparedStatement *pstmt;

			driver = get_driver_instance();
			con = driver->connect("tcp://192.168.0.12", "testusername", "testpassword");
			con->setSchema("books");

			listAllUsers *list = new listAllUsers;
			list->listU();

			int erase = 0;
			cout << "Enter the ID of the user you want to delete: ";
			cin >> erase;

			pstmt = con->prepareStatement("DELETE FROM users WHERE id=?");
			pstmt->setInt(1, erase);
			pstmt->execute();

			delete pstmt;
			delete con;

			cout << "User deleted!" << endl;
			system("pause");
		}
		catch (sql::SQLException &e) {
			cout << "Error connecting to the database." << endl;
		}
	}
};