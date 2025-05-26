#pragma once
#include <iostream>
#include "clsScreen.h"
#include "..\Models\clsBankClient.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
{

public:
	static void UpdateClientScreen() {
		if (!CheckAccessRights(clsBankUser::enUserPermissions::pUpdateClients)) {
			return;
		}
		_DrawScreenHeader("Update Client Screen");

		cout << "Enter the user Account Number : \n";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Wrong Account Number, please try again : \n";
			AccountNumber = clsInputValidate::ReadString();
		};
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nUpdate The Client Info : \n";
		cout << "------------------------------------------------\n";
		_ReadClientInfo(Client);

		clsBankClient::enSaveResult SaveReult;
		SaveReult = Client.Save();
		switch (SaveReult)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError, the Account wasn't saved because it was empty..\n";
			break;
		case clsBankClient::svSuccessded:
			cout << "\nAccount Updated Successfully :-)\n";
			_PrintClient(Client);
			break;
		default:
			break;
		}
	};
};

