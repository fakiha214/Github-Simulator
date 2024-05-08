#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>
#include<string>

using namespace std;

class Account {
	string username, password;
	static int totalAccounts;

	bool valid(string user);

	friend class Git;
public:
	bool regsiter(string username, string password);
};

#endif // !ACCOUNT_H