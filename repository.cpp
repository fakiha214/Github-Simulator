#include "repository.h"

#include<iostream>
#include<fstream>

using namespace std;

void Repos::loadTree() {
	ifstream in;
	in.open("repoDetails.txt");

	int users, repos, files;
	string str;
	int coms;
	in >> users;
	git = new Node;
	git->childs = new Node[users];
	git->ch = users;

	for (int i = 0; i < users; i++) {
		in >> str;
		git->childs[i].data = str;
		in >> repos;
		git->childs[i].childs = new Node[repos];
		git->childs[i].ch = repos;
		for (int j = 0; j < repos; j++) {
			in >> str;
			git->childs[i].childs[j].data = str;
			in >> coms;
			git->childs[i].childs[j].com = coms;
			in >> files;
			git->childs[i].childs[j].childs = new Node[files];
			git->childs[i].childs[j].ch = files;
			for (int k = 0; k < files; k++) {
				in >> str;
				git->childs[i].childs[j].childs[k].data = str;
			}
		}
	}
	in.close();
}

void Repos::unloadTree() {
	ofstream out;
	out.open("repoDetails.txt");

	out << git->ch << endl;
	for (int i = 0; i < git->ch; i++) {
		out << git->childs[i].data << endl;
		out << git->childs[i].ch << endl;
		for (int j = 0; j < git->childs[i].ch; j++) {
			out << git->childs[i].childs[j].data << endl;
			out << git->childs[i].childs[j].com << endl;
			out << git->childs[i].childs[j].ch << endl;
			for (int k = 0; k < git->childs[i].childs[j].ch; k++) {
				out << git->childs[i].childs[j].childs[k].data << endl;
			}
		}
	}
}

void Repos::addRepo(string user, string repoName) {
	ifstream in;
	in.open("repoDetails.txt");

	int users, repos, files;
	string str;
	int coms;
	in >> users;
	git = new Node;
	git->childs = new Node[users];
	git->ch = users;

	for (int i = 0; i < users; i++) {
		in >> str;
		git->childs[i].data = str;
		in >> repos;
		if (str == user)
			repos++;
		git->childs[i].childs = new Node[repos];
		git->childs[i].ch = repos;
		for (int j = 0; j < repos; j++) {
			if (git->childs[i].data == user && j == repos - 1) {
				git->childs[i].childs[j].data = repoName;
				git->childs[i].childs[j].com = 0;
				git->childs[i].childs[j].ch = 0;
			}
			else {
				in >> str;
				git->childs[i].childs[j].data = str;
				in >> coms;
				git->childs[i].childs[j].com = coms;
				in >> files;
				git->childs[i].childs[j].childs = new Node[files];
				git->childs[i].childs[j].ch = files;
				for (int k = 0; k < files; k++) {
					in >> str;
					git->childs[i].childs[j].childs[k].data = str;
				}
			}
		}
	}
	in.close();

	unloadTree();
}

bool Repos::searchRepo(string user, string repoName) {
	bool flag = false;
	for (int i = 0; i < git->ch; i++) {
		for (int j = 0; j < git->childs[i].ch; j++) {
			if (git->childs[i].data == user && git->childs[i].childs[j].data == repoName)
				return true;
			else if(git->childs[i].data != user)
				break;
		}
	}
	return false;
}

bool Repos::searchFile(string user, string repoName, string fileName) {
	for (int i = 0; i < git->ch; i++) {
		for (int j = 0; j < git->childs[i].ch; j++) {
			for (int k = 0; k < git->childs[i].childs[j].ch; k++) {
				if (git->childs[i].data == user && git->childs[i].childs[j].data == repoName && git->childs[i].childs[j].childs[k].data == fileName)
					return true;
				else if (git->childs[i].data != user || git->childs[i].childs[j].data != repoName)
					break;
			}
		}
	}
	return false;
}

bool Repos::deleteRepo(string user, string repoName) {
	loadTree();

	if (!searchRepo(user, repoName))
		return false;

	ofstream out;
	out.open("repoDetails.txt");

	out << git->ch << endl;
	for (int i = 0; i < git->ch; i++) {
		out << git->childs[i].data << endl;
		if (git->childs[i].data == user)
			out << git->childs[i].ch - 1 << endl;
		else
			out << git->childs[i].ch << endl;
		for (int j = 0; j < git->childs[i].ch; j++) {
			if (git->childs[i].data == user && git->childs[i].childs[j].data == repoName) {
				//deleted
			}
			else {
				out << git->childs[i].childs[j].data << endl;
				out << git->childs[i].childs[j].com << endl;
				out << git->childs[i].childs[j].ch << endl;
				for (int k = 0; k < git->childs[i].childs[j].ch; k++) {
					out << git->childs[i].childs[j].childs[k].data << endl;
				}
			}
		}
	}
	return true;
}

void Repos::addFile(string user, string repoName, string fileName) {
	ifstream in;
	in.open("repoDetails.txt");

	int users, repos, files,coms;
	string str;
	in >> users;
	git = new Node;
	git->childs = new Node[users];
	git->ch = users;

	for (int i = 0; i < users; i++) {
		in >> str;
		git->childs[i].data = str;
		in >> repos;
		git->childs[i].childs = new Node[repos];
		git->childs[i].ch = repos;
		for (int j = 0; j < repos; j++) {
			in >> str;
			git->childs[i].childs[j].data = str;
			in >> coms;
			git->childs[i].childs[j].com = coms;
			in >> files;
			if (git->childs[i].data == user && git->childs[i].childs[j].data == repoName)
				files++;
			git->childs[i].childs[j].childs = new Node[files];
			git->childs[i].childs[j].ch = files;
			for (int k = 0; k < files; k++) {
				if (git->childs[i].data == user && git->childs[i].childs[j].data == repoName && k == files - 1)
					git->childs[i].childs[j].childs[k].data = fileName;
				else {
					in >> str;
					git->childs[i].childs[j].childs[k].data = str;
				}
			}
		}
	}
	in.close();

	unloadTree();
}

bool Repos::deleteFile(string user, string repoName, string fileName) {
	loadTree();

	if (!searchFile(user, repoName,fileName))
		return false;

	ofstream out;
	out.open("repoDetails.txt");

	out << git->ch << endl;
	for (int i = 0; i < git->ch; i++) {
		out << git->childs[i].data << endl;
		out << git->childs[i].ch << endl;
		for (int j = 0; j < git->childs[i].ch; j++) {
			out << git->childs[i].childs[j].data << endl;
			out << git->childs[i].childs[j].com << endl;
			if (git->childs[i].data == user && git->childs[i].childs[j].data == repoName)
				out << git->childs[i].childs[j].ch - 1 << endl;
			else
				out << git->childs[i].childs[j].ch << endl;
			for (int k = 0; k < git->childs[i].childs[j].ch; k++) {
				if (git->childs[i].data == user && git->childs[i].childs[j].data == repoName && git->childs[i].childs[j].childs[k].data == fileName) 
				{ }
				else
					out << git->childs[i].childs[j].childs[k].data << endl;
			}
		}
	}

	return true;
}

bool Repos::searchRepoDetails(string repoName) {
	loadTree();
	bool flag = false;
	for (int i = 0; i < git->ch; i++) {
		for (int j = 0; j < git->childs[i].ch; j++) {
			if (git->childs[i].childs[j].data == repoName) {
				cout << "\t\t\t\tUser           :  " << git->childs[i].data << endl;
				cout << "\t\t\t\tRepo Name      :  " << git->childs[i].childs[j].data << endl;
				cout << "\t\t\t\tTotal Files    :  " << git->childs[i].childs[j].ch << endl;
				cout << "\t\t\t\tCommits        :  " << git->childs[i].childs[j].com << endl;
				return true;
			}
		}
	}
	return false;
}

bool Repos::searchRepoWithUser(string user) {
	loadTree();
	bool flag = false;
	for (int i = 0; i < git->ch; i++) {
		if (git->childs[i].data == user) {
			for (int j = 0; j < git->childs[i].ch; j++) {
				flag = true;
				cout << "\n\n\t\t\t\t*****************************************\n";
				cout << "\t\t\t\t\t\tRepository No. " << j << endl;
				cout << "\t\t\t\tRepo Name      :  " << git->childs[i].childs[j].data << endl;
				cout << "\t\t\t\tTotal Files    :  " << git->childs[i].childs[j].ch << endl;
				cout << "\t\t\t\tCommits        :  " << git->childs[i].childs[j].com << endl;
				cout << "\n\n\t\t\t\t*****************************************\n";
			}
		}
	}
	return flag;
}

void Repos::commitRepo(string repoName) {
	loadTree();
	for (int i = 0; i < git->ch; i++) {
		for (int j = 0; j < git->childs[i].ch; j++) {
			if (git->childs[i].childs[j].data == repoName) {
				git->childs[i].childs[j].com++;
			}
		}
	}
	unloadTree();
}

bool Repos::userDetails(string user) {
	loadTree();
	bool flag = false;
	for (int i = 0; i < git->ch; i++) {
		if (git->childs[i].data == user) {
			cout << "\n\n\t\t\t\t*****************************************\n";
			cout << "\t\t\t\tUsername              :  " << user << endl;
			cout << "\t\t\t\tTotal Repositories    :  " << git->childs[i].ch << endl;
			cout << "\t\t\t\tTotal Followers       :  " << follower.userFollowers(user) << endl;
			cout << "\n\n\t\t\t\t*****************************************\n";
			return 1;
		}
	}
	return 0;
}

void Repos::addUserToRepo(string user) {
	loadTree();
	ofstream out;

	out.open("repoDetails.txt");
	
	out << git->ch + 1 << endl;
	for (int i = 0; i < git->ch; i++) {
		out << git->childs[i].data << endl;
		out << git->childs[i].ch << endl;
		for (int j = 0; j < git->childs[i].ch; j++) {
			out << git->childs[i].childs[j].data << endl;
			out << git->childs[i].childs[j].com << endl;
			out << git->childs[i].childs[j].ch << endl;
			for (int k = 0; k < git->childs[i].childs[j].ch; k++) {
				out << git->childs[i].childs[j].childs[k].data << endl;
			}
		}
	}
	out << user << endl;
	out << 0 << endl;
	out.close();

	loadTree();
}