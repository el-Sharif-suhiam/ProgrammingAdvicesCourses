#pragma once
#include <iostream>
#include "..\Utils\clsInputValidate.h"
#include "..\Utils\clsDate.h"
#include "..\Models\clsBankClient.h"
#include "..\Models\clsBankUser.h"
#include "..\Global\Global.h"
using namespace std;

class clsScreen
{
	static int _ReadPermissionsToSet()
	{

		int Permissions = 0;
		char Answer = 'n';


		cout << "\nDo you want to give full access? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{


			Permissions += clsBankUser::enUserPermissions::pListClients;
		}


		cout << "\nAdd New Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsBankUser::enUserPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsBankUser::enUserPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsBankUser::enUserPermissions::pUpdateClients;
		}

		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsBankUser::enUserPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsBankUser::enUserPermissions::pTranactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsBankUser::enUserPermissions::pManageUsers;
		}

		cout << "\nLogin History List? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsBankUser::enUserPermissions::pLoginRegister;
		}

		return Permissions;

	}

protected:
	static void _DrawScreenHeader(string ScreenHeader, string subTitle = "") {
		cout << "\t\t\t\t   _______________________________________________";
		cout << "\n\n\t\t\t\t		" << ScreenHeader;
		if (subTitle != "") {
			cout << "\n\t\t\t\t	" << subTitle;
		};
		cout << "\n\n\t\t\t\t   _______________________________________________\n\n";
		cout << "\t\t\t\t   User: " << CurrentUser.Username;
		cout << "\n\t\t\t\t   Date: " << clsDate::DateToString(clsDate()) << "\n\n";
	}

	static void _PrintClient(clsBankClient& Client) {
		cout << "\nClient Card : \n\n";
		cout << "--------------------------------------------\n\n";
		cout << "First Name      : " << Client.FirstName << '\n';
		cout << "Last Name       : " << Client.LastName << '\n';
		cout << "Full Name       : " << Client.FullName() << '\n';
		cout << "Email           : " << Client.Email << '\n';
		cout << "Phone Number    : " << Client.Phone << '\n';
		cout << "Account Number  : " << Client.AccountNumber() << '\n';
		cout << "Password        : " << Client.PinCode << '\n';
		cout << "Account Balance : " << Client.AccountBalance << '\n';
		cout << "--------------------------------------------\n\n";

	};

	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "\nEnter the new First Name \n";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter the new Last Name \n";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter the new Email \n";
		Client.Email = clsInputValidate::ReadString();
		cout << "\nEnter the Phone \n";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter the new Password \n";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter the new Balance \n";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	};


	static void _PrintUser(clsBankUser& User) {
		cout << "\nUser Card : \n\n";
		cout << "--------------------------------------------\n\n";
		cout << "First Name      : " << User.FirstName << '\n';
		cout << "Last Name       : " << User.LastName << '\n';
		cout << "Full Name       : " << User.FullName() << '\n';
		cout << "Email           : " << User.Email << '\n';
		cout << "Phone Number    : " << User.Phone << '\n';
		cout << "UserName        : " << User.Username << '\n';
		cout << "Password        : " << User.Password << '\n';
		cout << "Permissions     : " << User.Permissions << '\n';
		cout << "--------------------------------------------\n\n";

	};


	static void _ReadUserInfo(clsBankUser& User) {
		cout << "\nEnter the new First Name \n";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter the new Last Name \n";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter the new Email \n";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter the Phone \n";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter the new Password \n";
		User.Password = clsInputValidate::ReadString();
		cout << "\nEnter the new Permissions \n";
		User.Permissions = _ReadPermissionsToSet();
	};

	static bool CheckAccessRights(clsBankUser::enUserPermissions Permission) {
		if (CurrentUser.CheckUserPermission(Permission)) {
			return true;
		}
		else {
			cout << "\t\t\t\t========================================================\n\n";
			cout << "\t\t\t\t\t    Access Denied! Contact your Admin   \n\n";
			cout << "\t\t\t\t=========================================================\n\n";
			
			return false;
		};
		
	}

};

