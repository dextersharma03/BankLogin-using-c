// BankLogin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
	Header loginObj;
	string username;
	string password;

	cout << "------------------" << "----------------------------------" << "------------------" << "\n";
	cout << "------------------" << "Welcome to the Bank of Nova Scotia" << "------------------" << "\n";
	cout << "------------------" << "----------------------------------" << "------------------" << "\n\n";

	cout << "Enter your username :";
	cin >> username;
	cout << "\nEnter your password :";
	cin >> password;

	bool check = loginObj.validateLogin(username, password);
	if (check) {   //login successful
		cout << "Success!";
	}
	else
	{
		bool newAcc = loginObj.options();
		if (newAcc) { //new account registration successful
			loginObj.writeFile();
			cout << "Success!";
		}
	}

}