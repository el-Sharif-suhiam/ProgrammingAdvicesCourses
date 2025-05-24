#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"

using namespace std;
class clsFindUserScreen : protected clsScreen
{
public:
	static void FindUserScreen() {
		_DrawScreenHeader("  Find User Screen");
		cout << "Enter the Username of The User you want to Find : \n";
		string Username = clsInputValidate::ReadString();
		while (!clsBankUser::IsUserExist(Username)) {
			cout << "Wrong Username, please try again : \n";
			Username = clsInputValidate::ReadString();
		};
		clsBankUser User = clsBankUser::Find(Username);

		if (User.IsEmpty()) {
			cout << "\n\nUser Not Found !!\n";
		}
		else {
			cout << "\n\nUser Found :-) \n";
			_PrintUser(User);
		};
	};
};

