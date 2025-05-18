// Bank Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

void ReadClientInfo(clsBankClient& Client) {
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

void AddNewClient() {
	cout << "Enter the new Account Number : \n";
	string AccountNumber = clsInputValidate::ReadString();
	while (clsBankClient::IsClientExist(AccountNumber)) {
		cout << "Wrong Account Number, please try again : \n";
		AccountNumber = clsInputValidate::ReadString();
	};
	clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);

	cout << "\nEnter The Client Info : \n";
	cout << "------------------------------------------------\n";
	ReadClientInfo(Client);

	clsBankClient::enSaveResult SaveResult;
	SaveResult = Client.Save();
	switch (SaveResult)
	{
	case clsBankClient::svFaildEmptyObject:
		cout << "\nError, the Account wasn't saved because it was empty..\n";
		break;
	case clsBankClient::svSuccessded:
		cout << "\nAccount Updated Successfully :-)\n";
		Client.Print();
		break;
	case clsBankClient::svFaildAccountNumberExist:
		cout << "\nError, Account Number is Exist ...\n";
		break;
	};
	
	
};
void Update() {
	cout << "Enter the user Account Number : \n";
	string AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber)) {
		cout << "Wrong Account Number, please try again : \n";
		AccountNumber = clsInputValidate::ReadString();
	};
	clsBankClient Client = clsBankClient::Find(AccountNumber);
	Client.Print();

	cout << "\nUpdate The Client Info : \n";
	cout << "------------------------------------------------\n";
	ReadClientInfo(Client);

	clsBankClient::enSaveResult SaveReult;
	SaveReult = Client.Save();
	switch (SaveReult)
	{
	case clsBankClient::svFaildEmptyObject:
		cout << "\nError, the Account wasn't saved because it was empty..\n";
		break;
	case clsBankClient::svSuccessded:
		cout << "\nAccount Updated Successfully :-)\n";
		Client.Print();
		break;
	default:
		break;
	}

};
int main()
{
	//Update();
	AddNewClient();
	system("pause > 0"); 

	return 0;

}
