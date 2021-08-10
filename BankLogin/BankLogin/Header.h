#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Header{

public:
	void writeFile();
	bool validateLogin(string username, string pass);
	bool options();
	bool checkUniqueUsername(string &username);
};