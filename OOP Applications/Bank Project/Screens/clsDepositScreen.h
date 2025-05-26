#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "..\Models\clsBankClient.h"
#include "..\Utils\clsInputValidate.h"
using namespace std;

class clsDepositScreen : protected clsScreen
{
    static string _ReadClientAccountNumber() {
        string AccNum;
        cout << "Please enter client  account number: \n";
        AccNum = clsInputValidate::ReadString();
        return AccNum;
    };

public :
    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t Deposit Screen");

        string AccountNumber = _ReadClientAccountNumber();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadClientAccountNumber();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);
        
        cout << "\nPlease enter deposit amount? ";
        double Amount = clsInputValidate::ReadDblNumber();

        char answer = 'n';
        cout << "Are you sure you want to deposit " << Amount << " to this account ? ('Y' for yea)\n";
        cin >> answer;

        if (toupper(answer) == 'Y') {
            Client.Deposit(Amount);
            cout << "\tThe Desposit has done sueecssfully ... !! \n";
            cout << "\tThe Account new balance is : " << Client.AccountBalance << "\n";
        }
        else {
            cout << "\tSomething went wrong ..... \n";
        };

    }
};

