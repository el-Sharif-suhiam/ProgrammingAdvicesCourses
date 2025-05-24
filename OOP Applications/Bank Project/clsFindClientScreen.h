#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;
class clsFindClientScreen : protected clsScreen
{
public:
	static void FindClientScreen() {
		if (!CheckAccessRights(clsBankUser::enUserPermissions::pFindClient)) {
			return;
		}
		_DrawScreenHeader("  Find Client Screen");
		cout << "Enter the Account Number of The Client you want to Find : \n";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Wrong Account Number, please try again : \n";
			AccountNumber = clsInputValidate::ReadString();
		};
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		
		if (Client.IsEmpty()) {
			cout << "\n\nClient Not Found !!\n";
		}
		else {
			_PrintClient(Client);
		};
	};
};

