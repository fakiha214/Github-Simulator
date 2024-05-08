#ifndef GIT_H
#define GIT_H

#include"account.h"
#include"followers.h"
#include<iostream>
#include<string>

using namespace std;

class Git {
	Account* accounts;
	Followers follow;
	void loadAccounts();
	int hashFunction(string username, int size);
	bool hashSearch(string user, string pass, int size);
	bool hashSearchWitoutPass(string user, int size);

public:
	bool login(string user, string pass);
	bool followSomeone(string user, string followed);
};

#endif // !GIT_H