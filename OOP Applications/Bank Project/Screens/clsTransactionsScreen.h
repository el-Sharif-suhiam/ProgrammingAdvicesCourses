#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "..\Models\clsBankClient.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogsScreen.h"
using namespace std;
class clsTransactionsScreen : protected clsScreen
{
	enum _enTransactionsMenuOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3,eTransfer= 4,eTransferLog =5, eShowMainMenue = 6 };
    static short _ReadTransactionsMenuOption() {
        cout << setw(37) << left << "" << "Choose what you want to do ? [1 to 6]\n";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
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
    static void _ShowTotalBalancesMenu() {
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    };
    static void _ShowTransferMenu() {
        clsTransferScreen::ShowTransferScreen();
   }
    static void _ShowTransferLogs() {
        clsTransferLogsScreen::ShowTransferLogsScreen();
    };
    static void _PerfromTransactionsMenuOption(_enTransactionsMenuOptions MenuOption) {
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
            _ShowTotalBalancesMenu();
            _GoBackToTransactionsMainMenu();

            break;
        case clsTransactionsScreen::eTransfer:
            system("cls");
            _ShowTransferMenu();
            _GoBackToTransactionsMainMenu();
        case clsTransactionsScreen::eTransferLog:
            system("cls");
            _ShowTransferLogs();
            _GoBackToTransactionsMainMenu();
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
        cout << setw(37) << left << ""<< "\t\tTransactions Menu Screen\n";
        cout << setw(37) << left << ""<< "===========================================\n";
        cout << setw(37) << left << ""<< "\t[1] Deposit.\n";
        cout << setw(37) << left << ""<< "\t[2] Withdraw.\n";
        cout << setw(37) << left << ""<< "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Logs List.\n";
        cout << setw(37) << left << ""<< "\t[6] Main Menu.\n";
        cout << setw(37) << left << ""<< "===========================================\n";
        _PerfromTransactionsMenuOption((_enTransactionsMenuOptions)_ReadTransactionsMenuOption());
    }

};

