#include"git.h"

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int hashEvaluate(string username,int size) {
	int dig = username[0];

	int hashValue = int(dig) % size;
	return hashValue;
}

int Git::hashFunction(string username,int size) {
	int hashValue = hashEvaluate(username,size);
	while (accounts[hashValue].username != "-") {
		if (hashValue == size)
			hashValue = 0;
		hashValue++;
	}
	return hashValue;
}

void Git::loadAccounts() {
	int count;
	ifstream in;
	in.open("accountCount.txt");
	in >> count;
	in.close();

	accounts->totalAccounts = count*2;

	accounts = new Account[count*2];

	for (int i = 0; i < count*2; i++) {
		accounts[i].username = "-";
	}

	in.open("accounts.txt");

	int index;
	string user, pass;
	for (int i = 0; i < count; i++) {
		in >> user >> pass;
		index = hashFunction(user, count * 2);
		accounts[index].username = user;
		accounts[index].password = pass;
	}
}

bool Git::hashSearch(string user, string pass,int size) {
	int hashValue = hashEvaluate(user,size);
	while (accounts[hashValue].username != "-" && accounts[hashValue].username != user) {
		if (hashValue == size)
			hashValue = 0;
		hashValue++;
	}
	if (accounts[hashValue].username == user && accounts[hashValue].password == pass)
		return true;
	return false;
}

bool Git::hashSearchWitoutPass(string user, int size) {
	int hashValue = hashEvaluate(user, size);
	while (accounts[hashValue].username != "-" && accounts[hashValue].username != user) {
		if (hashValue == size)
			hashValue = 0;
		hashValue++;
	}
	if (accounts[hashValue].username == user)
		return true;
	return false;
}

bool Git::login(string user,string pass) {
	loadAccounts();

	return hashSearch(user, pass, accounts->totalAccounts);
}

bool Git::followSomeone(string user, string followed) {
	loadAccounts();
	if (!hashSearchWitoutPass(user, accounts->totalAccounts)) {
		return 0;
	}
	return follow.addFollow(user, followed);
}