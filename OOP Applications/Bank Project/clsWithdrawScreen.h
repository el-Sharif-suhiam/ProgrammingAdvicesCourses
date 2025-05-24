#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsWithdrawScreen : protected clsScreen
{
    static string _ReadClientAccountNumber() {
        string AccNum;
        cout << "Please enter client  account number: \n";
        AccNum = clsInputValidate::ReadString();
        return AccNum;
    };

public:
    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t Withdraw Screen");

        string AccountNumber = _ReadClientAccountNumber();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadClientAccountNumber();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClient(Client);

        cout << "\nPlease enter withdraw amount? ";
        double Amount = clsInputValidate::ReadDblNumber();
        while ( Client.AccountBalance < Amount) {
            cout << "Error, the withdraw amount is higher then account balance : \n";
            double Amount = clsInputValidate::ReadDblNumber();
        };
        char answer = 'n';
        cout << "Are you sure you want to deposit " << Amount << " to this account ? ('Y' for yea)\n";
        cin >> answer;

        if (toupper(answer) == 'Y') {
            if (Client.Withdraw(Amount)) {
                cout << "\tThe Withdraw has done sueecssfully ... !! \n";
                cout << "\tThe Account new balance is : " << Client.AccountBalance << "\n";
            }
            else {
                cout << "Error, something wrong \n";
            }
            
        }

    }

};

