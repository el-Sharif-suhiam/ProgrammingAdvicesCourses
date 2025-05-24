#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
using namespace std;
class clsTransactionsScreen : protected clsScreen
{
	enum _enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eShowMainMenue = 4 };
    static short _ReadTransactionsMenuOption() {
        cout << setw(37) << left << "" << "Choose what you want to do ? [1 to 4]\n";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4);
        return Choice;
    };
    static void _GoBackToTransactionsMainMenu()
    {
        cout << "\n\nPress any key to go back to Transactions Menu...";
        system("pause>0");
        ShowTransactionsMenu();
    };
    static void _ShowDepositMenu() {
        clsDepositScreen::ShowDepositScreen();
    };
    static void _ShowWithdrawMenu() {
        clsWithdrawScreen::ShowWithdrawScreen();
    };
    static void _ShowShowTotalBalancesMenu() {
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    };
   
    static void _PerfromTransactionsMenuOption(_enTransactionsMenueOptions MenuOption) {
        switch (MenuOption)
        {
        case clsTransactionsScreen::eDeposit:
            system("cls");
            _ShowDepositMenu();
            _GoBackToTransactionsMainMenu();
            break;
        case clsTransactionsScreen::eWithdraw:
            system("cls");
            _ShowWithdrawMenu();
            _GoBackToTransactionsMainMenu();

            break;
        case clsTransactionsScreen::eShowTotalBalance:
            system("cls");
            _ShowShowTotalBalancesMenu();
            _GoBackToTransactionsMainMenu();

            break;
        case clsTransactionsScreen::eShowMainMenue:

            break;
        default:
            break;
        }

    };

public:
    static void ShowTransactionsMenu() {

        if (!CheckAccessRights(clsBankUser::enUserPermissions::pTranactions)) {
            return;
        }

        system("cls");
        _DrawScreenHeader("\tTransactions Menu");
        cout << setw(37) << left << ""<< "===========================================\n";
        cout << setw(37) << left << ""<< "\t\tTransactions Menue Screen\n";
        cout << setw(37) << left << ""<< "===========================================\n";
        cout << setw(37) << left << ""<< "\t[1] Deposit.\n";
        cout << setw(37) << left << ""<< "\t[2] Withdraw.\n";
        cout << setw(37) << left << ""<< "\t[3] Total Balances.\n";
        cout << setw(37) << left << ""<< "\t[4] Main Menue.\n";
        cout << setw(37) << left << ""<< "===========================================\n";
        _PerfromTransactionsMenuOption((_enTransactionsMenueOptions)_ReadTransactionsMenuOption());
    }

};

