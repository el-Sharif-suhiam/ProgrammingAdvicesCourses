#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "..\Models\clsBankClient.h"
#include "..\Utils\clsInputValidate.h"
#include "..\Models\clsTransfer.h"

using namespace std;
class clsTransferScreen : protected clsScreen
{
	static clsBankClient _CheckAccountNumber(string Msg) {
		cout << Msg;
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Wrong Account Number, please try again : \n";
			AccountNumber = clsInputValidate::ReadString();
		};
		return  clsBankClient::Find(AccountNumber);
	}
public:
	static void ShowTransferScreen() {

		_DrawScreenHeader("Transfer Screen");
		clsBankClient Client1 = _CheckAccountNumber("Enter the user Account Number that you want to transfer from : \n");
		
		clsTransfer::PrintClientTransferInfo(Client1);

		
		clsBankClient Client2 = _CheckAccountNumber("\nNow Enter the user Account Number that you want to transfer to : \n");

		clsTransfer::PrintClientTransferInfo(Client2);


		if (clsTransfer::Transfer(Client1, Client2)) {
			cout << "\nThe Transfer has done sueecssfully !!";
			clsTransfer::PrintClientTransferInfo(Client1);
			clsTransfer::PrintClientTransferInfo(Client2);
		}
		else {
			cout << "The Transfer has been Aborted !!";
		};

	}
};

