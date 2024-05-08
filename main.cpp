#include"account.h"
#include"git.h"
#include"repository.h"
#include"followers.h"

#include<iostream>

using namespace std;

int main() {
	Followers follow;
	string user, pass, repoName,fileName,search;
	int inp,inp2;
	Account account;
	Git git;
	Repos repos;
	bool log = false;
	do {
		cout << "\t\t\t\t*****************************************\n";
		cout << "\t\t\t\t*****************************************\n";
		cout << "\t\t\t\t**                                     **\n";
		cout << "\t\t\t\t**  Enter to Select an Option          **\n";
		cout << "\t\t\t\t**                                     **\n";
		cout << "\t\t\t\t**  1.  LOGIN TO AN ACCOUNT            **\n";
		cout << "\t\t\t\t**  2.  REGISTER AN ACCOUNT            **\n";
		cout << "\t\t\t\t**  3.  Exit                           **\n";
		cout << "\t\t\t\t**                                     **\n";
		cout << "\t\t\t\t*****************************************\n";
		cout << "\t\t\t\t*****************************************\n\n";
		cout << "\t\t\t\t           Enter Choice   :   ";
		cin >> inp;
		cout << "\n\t\t\t\t*****************************************\n";
		cout << '\n';

		if (inp == 1) {
			cout << "\t\t\t\t       Enter Username   :   ";
			cin >> user;
			cout << "\t\t\t\t       Enter Password   :   ";
			cin >> pass;
			cout << "\n";
			log = git.login(user, pass);
			if (log) {
				cout << "\t\t\t\t*****************************************\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t**          LOGIN SUCCESSFULLY         **\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t*****************************************\n";
			}
			else {

				cout << "\t\t\t\t*****************************************\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t**     INVALID USERNAME/PASSWORD       **\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t*****************************************\n";
			}
		}
		else if (inp == 2) {
			string user, pass;
			cout << "\t\t\t\t       Enter Username   :   ";
			cin >> user;
			cout << "\t\t\t\t       Enter Password   :   ";
			cin >> pass;
			cout << "\n";
			if (account.regsiter(user, pass)) {
				cout << "\t\t\t\t*****************************************\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t**       REGISTERED SUCCESSFULLY       **\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t*****************************************\n";
			}
			else {

				cout << "\t\t\t\t*****************************************\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t**          INVALID USERNAME           **\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t*****************************************\n";
			}
		}
		if (log) {

			do {
				cout << "\t\t\t\t*****************************************\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t**  Enter to Select an Option          **\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t**  1.   Search Repository             **\n";
				cout << "\t\t\t\t**  2.   All Your Repositories         **\n";
				cout << "\t\t\t\t**  3.   Add Repository                **\n";
				cout << "\t\t\t\t**  4.   Add File to Repository        **\n";
				cout << "\t\t\t\t**  5.   Delete Repository             **\n";
				cout << "\t\t\t\t**  6.   Delete File from Repository   **\n";
				cout << "\t\t\t\t**  7.   Commit in Repository          **\n";
				cout << "\t\t\t\t**  8.   Follow other User             **\n";
				cout << "\t\t\t\t**  9.   See User Profiles             **\n";
				cout << "\t\t\t\t**  10.  See User Followers            **\n";
				cout << "\t\t\t\t**  11.  EXIT                          **\n";
				cout << "\t\t\t\t**                                     **\n";
				cout << "\t\t\t\t*****************************************\n";
				cout << "\t\t\t\t           Enter Choice   :   ";
				cin >> inp2;
				cout << "\n\t\t\t\t*****************************************\n\n";

				if (inp2 == 1) {
					cout << "\t\t\t\t       Enter Repo Name  :   ";
					cin >> repoName;
					cout << "\n\t\t\t\t*****************************************\n\n";
					if (!repos.searchRepoDetails(repoName)) {
						cout << "\t\t\t\t          REPOSITORY NOT FOUND!\n";
					}
					cout << "\n\n\t\t\t\t*****************************************\n";
				}
				if (inp2 == 2) {
					if (!repos.searchRepoWithUser(user)) {
						cout << "\n\t\t\t\t*****************************************\n\n";
						cout << "\t\t\t\t          REPOSITORY NOT FOUND!\n";
						cout << "\n\n\t\t\t\t*****************************************\n";
					}
				}
				else if (inp2 == 3) {
					cout << "\t\t\t\t       Enter Repo Name  :   ";
					cin >> repoName;
					cout << "\n\t\t\t\t*****************************************\n\n";
					repos.addRepo(user,repoName);
					cout << "\t\t\t\t         REPOSITORY ADDED!\n";
					cout << "\n\n\t\t\t\t*****************************************\n";
				}
				else if (inp2 == 4) {
					cout << "\t\t\t\t       Enter Repo Name  :   ";
					cin >> repoName;
					cout << "\t\t\t\t       Enter File Name  :   ";
					cin >> fileName;
					cout << "\n\t\t\t\t*****************************************\n\n";
					repos.addFile(user, repoName,fileName);
					cout << "\t\t\t\t           FILE ADDED!\n";
					cout << "\n\n\t\t\t\t*****************************************\n";
				}
				else if (inp2 == 5) {
					cout << "\t\t\t\t       Enter Repo Name  :   ";
					cin >> repoName;
					cout << "\n\t\t\t\t*****************************************\n\n";
					if(repos.deleteRepo(user, repoName))
						cout << "\t\t\t\t          REPOSITORY DELETED!\n";
					else
						cout << "\t\t\t\t        REPOSITORY NOT DELETED!\n";
					cout << "\n\n\t\t\t\t*****************************************\n";
				}
				else if (inp2 == 6) {
					cout << "\t\t\t\t       Enter Repo Name  :   ";
					cin >> repoName;
					cout << "\t\t\t\t       Enter File Name  :   ";
					cin >> fileName;
					cout << "\n\t\t\t\t*****************************************\n\n";
					if(repos.deleteFile(user, repoName, fileName))
						cout << "\t\t\t\t            FILE DELETED!\n";
					else
						cout << "\t\t\t\t          FILE NOT DELETED!\n";
					cout << "\n\n\t\t\t\t*****************************************\n";
				}
				else if (inp2 == 7) {
					cout << "\t\t\t\t       Enter Repo Name  :   ";
					cin >> repoName;
					cout << "\n\t\t\t\t*****************************************\n\n";
					repos.commitRepo(repoName);
					cout << "\t\t\t\t         REPOSITORY COMMITED!\n";
					cout << "\n\n\t\t\t\t*****************************************\n";
				}
				else if (inp2 == 8) {
					cout << "\t\t\t\t       Username To Follow  : ";
					cin >> search;
					cout << "\n\t\t\t\t*****************************************\n\n";
					if (git.followSomeone(user,search))
						cout << "\t\t\t\t            FOLLOWED!    \n";
					else
						cout << "\t\t\t\tCAN'T FOLLOW THIS ACCOUNT!\n";
					cout << "\n\n\t\t\t\t*****************************************\n";
				}
				else if (inp2 == 9) {
					cout << "\t\t\t\tUsername To search Profile  : ";
					cin >> search;
					cout << "\n\t\t\t\t*****************************************\n\n";
					if (!repos.userDetails(search))
						cout << "\t\t\t\tCAN'T FIND THIS ACCOUNT!\n";
					cout << "\n\n\t\t\t\t*****************************************\n";
				}
				else if (inp2 == 10) {
					cout << "\t\t\t\tUsername to See Followers  : ";
					cin >> search;
					cout << "\n\t\t\t\t*****************************************\n\n";
					follow.userFollowersList(search);
					cout << "\n\n\t\t\t\t*****************************************\n";
				}
			} while (inp2 != 11);
			log = false;
		}
	} while (inp != 3);

	system("pause");
	return 0;
}