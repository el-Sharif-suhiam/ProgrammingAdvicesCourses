#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankUser.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{

public:
	static void UpdateUserScreen() {

		_DrawScreenHeader("Update User Screen");

		cout << "Enter the Username : \n";
		string Username = clsInputValidate::ReadString();
		while (!clsBankUser::IsUserExist(Username)) {
			cout << "Wrong Username, please try again : \n";
			Username = clsInputValidate::ReadString();
		};
		clsBankUser User = clsBankUser::Find(Username);
		_PrintUser(User);

		cout << "\nUpdate The User Info : \n";
		cout << "------------------------------------------------\n";
		_ReadUserInfo(User);

		clsBankUser::enSaveResult SaveReult;
		SaveReult = User.Save();
		switch (SaveReult)
		{
		case clsBankUser::svFaildEmptyObject:
			cout << "\nError, the User wasn't saved because it was empty..\n";
			break;
		case clsBankUser::svSuccessded:
			cout << "\nUser Updated Successfully :-)\n";
			_PrintUser(User);
			break;
		default:
			break;
		}
	};
};

