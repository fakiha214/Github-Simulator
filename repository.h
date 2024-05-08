#ifndef REPOSITORY_H
#define REPOSITORY_H

#include"followers.h"

#include<iostream>
#include<string>

using namespace std;

class Node {
public:
	string data;
	int ch;
	Node* childs;
	int com;
	Node() {
		com = 0;
	}
};

class Repos {
	Node* git;
	Followers follower;
	void loadTree();
	void unloadTree();
	bool searchRepo(string user, string repoName);
	bool searchFile(string user, string repoName, string fileName);
public:
	bool deleteRepo(string user, string repoName);
	void addRepo(string user,string repoName);
	void addUserToRepo(string user);
	void addFile(string user, string repoName, string fileName);
	bool deleteFile(string user, string repoName, string fileName);
	bool searchRepoDetails(string repoName);
	bool searchRepoWithUser(string user);
	void commitRepo(string repoName);
	bool userDetails(string user);
};

#endif // !REPOSITORY_H