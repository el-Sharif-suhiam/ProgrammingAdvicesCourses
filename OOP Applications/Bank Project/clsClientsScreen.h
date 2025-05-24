#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsBankUser.h"

class clsClientsScreen : protected clsScreen
{
	static void _PrintClientRecordLine(clsBankClient Client)
	{

		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}

public:
	
	static void ShowClientsList()
	{
		if (!CheckAccessRights(clsBankUser::enUserPermissions::pListClients)){
			return;
		}
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		string subTitle = "\tClient List (" + to_string(vClients.size()) + ") Client(s).";
		_DrawScreenHeader("\tClients Screen", subTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout  << "_________________________________________\n" << endl;
					    
		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "PinCode";
		cout << "| " << left << setw(12) << "Balance";
		cout <<setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{

				_PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

};

