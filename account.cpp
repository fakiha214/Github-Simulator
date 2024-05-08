#include"account.h"
#include"repository.h"


#include<iostream>
#include<fstream>

using namespace std;

int Account::totalAccounts = 0;

bool Account::regsiter(string username, string password) {
	if (valid(username)) {
		ofstream out;
		Repos rr;
		Followers follow;
		out.open("accounts.txt",ios::app);
		out << username << endl << password << endl;
		out.close();

		int count;
		ifstream in;
		in.open("accountCount.txt");
		in >> count;
		in.close();

		out.open("accountCount.txt");
		count++;
		out << count;
		out.close();
		rr.addUserToRepo(username);
		follow.addPerson();
		return true;
	}
	return false;
}

bool Account::valid(string user) {
	ifstream in;
	in.open("accounts.txt");
	
	while (!in.eof()) {
		in >> username >> password;
		if (username == user)
			return false;
	}
	in.close();
	return true;
}