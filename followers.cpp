#include "followers.h"


#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void Followers::loadFollowers() {
	ifstream in;
	in.open("followers.txt");

	in >> totalFols;

	fols = new int*[totalFols];

	for (int i = 0; i < totalFols; i++) {
		fols[i] = new int[totalFols];
	}

	for (int i = 0; i < totalFols; i++) {
		for (int j = 0; j < totalFols; j++) {
			in >> fols[i][j];
		}
	}
	in.close();
}

void Followers::unloadFollowers() {
	ofstream out;
	out.open("followers.txt");

	out << totalFols << endl;

	for (int i = 0; i < totalFols; i++) {
		for (int j = 0; j < totalFols; j++) {
			out << fols[i][j] << endl;
		}
	}
	out.close();
}

void Followers::addPerson() {
	loadFollowers();

	ofstream out;

	out.open("followers.txt");

	totalFols++;

	out << totalFols << endl;

	for (int i = 0; i < totalFols; i++) {
		for (int j = 0; j < totalFols; j++) {
			if (i == totalFols - 1 || j == totalFols - 1)
				out << 0 << endl;
			else
				out << fols[i][j] << endl;
		}
	}

	out.close();
}

int Followers::userFollowers(string user) {
	loadFollowers();
	int index = userIndex(user);
	int folow = 0;

	for (int i = 0; i < totalFols; i++) {
		if (fols[i][index] == 1)
			folow++;
	}
	return folow;
}

void Followers::userFollowersList(string user){
	loadFollowers();
	int index = userIndex(user);
	
	for (int i = 0; i < totalFols; i++) {
		if (fols[i][index] == 1)
			cout << "\t\t\t\t           " << userString(i) << endl;
	}
}

bool Followers::addFollow(string followee, string followed) {
	int folee = userIndex(followee);
	int folod = userIndex(followed);
	loadFollowers();
	if (fols[folee][folod] == 1)
		return 0;
	fols[folee][folod] = 1;
	unloadFollowers();
	return 1;
}

void Followers::removeFollow(string followee, string followed) {
	int folee = userIndex(followee);
	int folod = userIndex(followed);
	loadFollowers();
	fols[folee][folod] = 0;
	unloadFollowers();
}

int Followers::userIndex(string user) {
	ifstream in;
	in.open("accountCount.txt");
	int count;
	in >> count;
	string* users = new string[count];
	string str;
	in.close();

	in.open("accounts.txt");

	for (int i = 0; i < count; i++) {
		getline(in, str);
		users[i] = str;
		getline(in, str);
	}

	for (int i = 0; i < count; i++) {
		if (users[i] == user)
			return i;
	}
	return -1;
}

string Followers::userString(int index) {
	ifstream in;
	in.open("accountCount.txt");
	int count;
	in >> count;
	string* users = new string[count];
	string str;
	in.close();

	in.open("accounts.txt");

	for (int i = 0; i < count; i++) {
		getline(in, str);
		users[i] = str;
		getline(in, str);
	}

	if (index < count)
		return users[index];
	return "-";
}