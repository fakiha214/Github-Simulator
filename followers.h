#ifndef FOLLOWERS_H
#define FOLLOWERS_H

#include<iostream>

using namespace std;

class Followers {
	int** fols;
	int totalFols;
public:
	void loadFollowers();
	void unloadFollowers();
	void addPerson();
	int userFollowers(string user);
	void userFollowersList(string user);
	bool addFollow(string followee,string followed);
	void removeFollow(string followee, string followed);
	int userIndex(string user);
	string userString(int index);
};

#endif // !FOLLOWERS_H
