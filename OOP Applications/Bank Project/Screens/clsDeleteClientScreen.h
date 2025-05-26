#pragma once
#include <iostream>
#include "clsScreen.h"
#include "..\Models\clsBankClient.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
{

public:

	static void DeleteClientSreen() {
		if (!CheckAccessRights(clsBankUser::enUserPermissions::pDeleteClient)) {
			return;
		};
		_DrawScreenHeader("Delete Client Screen");
			cout << "Enter the Account Number of The Client you want to Delete : \n";
			string AccountNumber = clsInputValidate::ReadString();
			while (!clsBankClient::IsClientExist(AccountNumber)) {
				cout << "Wrong Account Number, please try again : \n";
				AccountNumber = clsInputValidate::ReadString();
			};
			clsBankClient Client = clsBankClient::Find(AccountNumber);
		
			_PrintClient(Client);
		
			char answer;
			cout << "\nAre you sure that you want to delete this client ? (enter 'Y' for yes ) \n";
			cin >> answer;
		
			if (toupper(answer) == 'Y') {
				if (Client.Delete()) {
					cout << "The Account has been deleted successfully \n";
					_PrintClient(Client);
				}
				else {
					cout << "Something wrong happened, the delete not finished !! \n";
				};
			}
		};
};

