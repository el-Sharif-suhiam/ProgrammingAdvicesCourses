#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "..\Models\clsBankClient.h"
#include "..\Utils\clsInputValidate.h"
#include "..\Utils\clsUtil.h"
class clsTotalBalancesScreen : protected clsScreen
{
	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{

		cout << setw(25) << left <<"" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}
public:

	
	static void ShowTotalBalancesScreen()
	{
	
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		_DrawScreenHeader("   Balances List Screen", "\tBalances List(" + to_string(vClients.size()) + ") Client(s)");

		cout <<setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	
		cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	
	
		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else
	
			for (clsBankClient Client : vClients)
			{
	
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}
	
		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t\t\t\t   Total Balances = " << clsBankClient::GetTotalBalances() << endl;
		cout << clsUtil::Tabs(5) << "(" << clsUtil::NumberToText(clsBankClient::GetTotalBalances()) << ") \n\n";
	
	}

};

