#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include "Header.h"

using namespace std;

bool Header::options() {
	string account;
	string password;
	system("CLS");

	cout << "------------------" << "----------------------------------" << "------------------" << "\n";
	cout << "------------------" << "Welcome to the Bank of Nova Scotia" << "------------------" << "\n";
	cout << "------------------" << "----------------------------------" << "------------------" << "\n\n";

	cout << "Do you want to register a new Account ?(Y/N)";
	cin >> account;
	if (account == "Y" || account == "y") {
		return true;
	}
	cout << "\nOkay see you later!";
	return false;
}

void Header::writeFile() {
	ofstream MyFile("LoginData.csv", ios::app);
	string username;
	string password;
	string data;
	system("CLS");

	cout << "------------------" << "----------------------------------" << "------------------" << "\n";
	cout << "------------------" << "Welcome to the Bank of Nova Scotia" << "------------------" << "\n";
	cout << "------------------" << "----------------------------------" << "------------------" << "\n";
	cout << "------------------" << "----------------------------------" << "------------------" << "\n\n";
	cout << "****************** Registration ****************************" << "\n\n";

	cout << "Create your username :";
	cin >> username;
	checkUniqueUsername(username);
	cout << "\Create your password :";
	cin >> password;

	//store hash of the passwords
	hash<string> passHash;

	MyFile << username << ",";
	MyFile << passHash(password) << "\n";

	MyFile.close();
}

bool Header::checkUniqueUsername(string &username) {
	string data;
	int counter = 1;

	while ((counter % 2) != 0)
	{
		ifstream myfile("LoginData.csv");

		while (getline(myfile, data)) {
			stringstream s_stream(data);

			while (s_stream.good()) {
				string substr;
				getline(s_stream, substr, ','); //get first string delimited by comma

				if (username.compare(substr) == 0) {
					cout << "Please enter a different username, as it is already taken: ";
					cin >> username;
					counter *= 2;
				}
			}
		}
		counter++;
	}
	
	return false;
}

bool Header::validateLogin(string username, string pass) {
	string data;
	vector<string> result;
	bool check = false;
	hash<string> passH;
	auto enteredHash = passH(pass);  //hash the entered pass
	string getHash = to_string(enteredHash); //convert the hash type to string

	ifstream myfile("LoginData.csv");

	while (getline(myfile, data)) {
		stringstream s_stream(data);

		while (s_stream.good()) {
			string substr;
			getline(s_stream, substr, ','); //get first string delimited by comma
			result.push_back(substr);
			if (getHash.compare(substr) == 0) { //compare hash string of password to hash stored in file
				string user = result[result.size() - 2];
				if (user.compare(username) == 0) {
					return check = true;
				}

			}
		}
	}

	return check = false;

}
