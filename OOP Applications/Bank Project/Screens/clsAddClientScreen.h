#pragma once
#include <iostream>
#include "clsScreen.h"

#include "..\Models\clsBankClient.h"
#include "..\Models\clsBankUser.h"

using namespace std;
class clsAddClientScreen : protected clsScreen
{

public:
	static void ShowAddClientScreen() {
		if (!CheckAccessRights(clsBankUser::enUserPermissions::pAddNewClient)) {
			return;
		}
		_DrawScreenHeader("Add New Client Screen");
		cout << "Enter the new Account Number : \n";
		string AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Wrong Account Number, please try again : \n";
			AccountNumber = clsInputValidate::ReadString();
		};
		clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);

		cout << "\nEnter The Client Info : \n";
		cout << "------------------------------------------------\n";
		_ReadClientInfo(Client);

		clsBankClient::enSaveResult SaveResult;
		SaveResult = Client.Save();
		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError, the Account wasn't saved because it was empty..\n";
			break;
		case clsBankClient::svSuccessded:
			cout << "\nAccount Updated Successfully :-)\n";
			_PrintClient(Client);
			break;
		case clsBankClient::svFaildAccountNumberExist:
			cout << "\nError, Account Number is Exist ...\n";
			break;
		};

	}
};

