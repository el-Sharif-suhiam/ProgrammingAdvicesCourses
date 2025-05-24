#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{

public:

	static void DeleteUserSreen() {
		_DrawScreenHeader("Delete User Screen");
		cout << "Enter the Username of The User you want to Delete : \n";
		string Username = clsInputValidate::ReadString();
		while (!clsBankUser::IsUserExist(Username)) {
			cout << "Wrong Username, please try again : \n";
			Username = clsInputValidate::ReadString();
		};
		clsBankUser User = clsBankUser::Find(Username);

		_PrintUser(User);

		char answer;
		cout << "\nAre you sure that you want to delete this User ? (enter 'Y' for yes ) \n";
		cin >> answer;

		if (toupper(answer) == 'Y') {
			if (User.Delete()) {
				cout << "The User has been deleted successfully \n";
				_PrintUser(User);
			}
			else {
				cout << "Something wrong happened, the delete not finished !! \n";
			};
		}
	};
};

