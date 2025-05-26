#pragma once
#include <iostream>
#include "clsScreen.h"
#include "..\Models\clsBankClient.h"
using namespace std;
class clsAddUserScreen : protected clsScreen
{
	
public:
	static void ShowAddUserScreen() {
		_DrawScreenHeader("Add New User Screen");
		cout << "Enter the new Username : \n";
		string AccountNumber = clsInputValidate::ReadString();
		while (clsBankUser::IsUserExist(AccountNumber)) {
			cout << "Wrong Username, please try again : \n";
			AccountNumber = clsInputValidate::ReadString();
		};
		clsBankUser User = clsBankUser::GetAddNewUserObject(AccountNumber);

		cout << "\nEnter The User Info : \n";
		cout << "------------------------------------------------\n";
		_ReadUserInfo(User);

		clsBankUser::enSaveResult SaveResult;
		SaveResult = User.Save();
		switch (SaveResult)
		{
		case clsBankUser::svFaildEmptyObject:
			cout << "\nError, the User wasn't saved because it was empty..\n";
			break;
		case clsBankUser::svSuccessded:
			cout << "\nUser Updated Successfully :-)\n";
			_PrintUser(User);
			break;
		case clsBankUser::svFaildUsernameExist:
			cout << "\nError, Username is Exist ...\n";
			break;
		};

	}
};

