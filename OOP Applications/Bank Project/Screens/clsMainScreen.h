#pragma once 
#include <iostream>
#include <iomanip>
#include "..\Global\Global.h"
#include "..\Utils\clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientsScreen.h"
#include "clsAddClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginScreen.h"
#include "clsLoginHistoryScreen.h"
class clsMainScreen : protected clsScreen
{

    enum _enMainMenuOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
        eManageUsers = 7, eLoginRegister = 8 ,eExit = 9
    };
    static short _ReadMainMenuOption() {
        cout << setw(37) << left << "" << "Choose what you want to do ? [1 to 9]\n";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 9);
        return Choice;
    };
    static void _GoBackToMainMenu()
    {
        cout << "\n\nPress any key to go back to Main Menu...";
        system("pause>0");
        ShowMainMenu();
    }
    static void _ShowClientsScreen() {
        clsClientsScreen::ShowClientsList();
    };
    static void _AddClientScreen() {
        clsAddClientScreen::ShowAddClientScreen();
    };

    static void _deleteClientScreen() {
        clsDeleteClientScreen::DeleteClientSreen();
    };
    static void _UpdateClientScreen() {
        clsUpdateClientScreen::UpdateClientScreen();
    };
    static void _FindClientScreen() {
        clsFindClientScreen::FindClientScreen();
    };
    static void _ShowTransactionsScreen() {
        clsTransactionsScreen::ShowTransactionsMenu();
    };
    static void _ManageUsersScreen() {
        clsManageUsersScreen::ShowManageUsersMenu();

    };
    
    static void _LoginHistoryScreen() {
        clsLoginHistoryScreen::ShowLoginHistoryScreen();
    }
    /*static void _ShowEndScreen() {
        cout << setw(37) << left << "" << "\n\t-----------------------------------\n";
        cout << setw(37) << left << "" << "\tProgram Ends :-)";
        cout << setw(37) << left << "" << "\n\t-----------------------------------\n";
        system("pause>0");

    };*/
    static void _LogOut() {
        CurrentUser = clsBankUser::Find("", "");
    };
    static void _PerfromMainMenuOption(_enMainMenuOptions MenuOption) {
        switch (MenuOption)
        {
        case clsMainScreen::eListClients:
            system("cls");
            _ShowClientsScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eAddNewClient:
            system("cls");
            _AddClientScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eDeleteClient:
            system("cls");
            _deleteClientScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eUpdateClient:
            system("cls");
            _UpdateClientScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eFindClient:
            system("cls");
            _FindClientScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eShowTransactionsMenu:
            system("cls");
            _ShowTransactionsScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eManageUsers:
            system("cls");
            _ManageUsersScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eLoginRegister:
            system("cls");
            _LoginHistoryScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eExit:
            system("cls");
            _LogOut();
            break;
        default:
            break;
        }

    }
public:

    static void ShowMainMenu()
    {
        system("cls");
        _DrawScreenHeader("\tMain Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login History List.\n";
        cout << setw(37) << left << "" << "\t[9] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenuOption((_enMainMenuOptions)_ReadMainMenuOption());
    }
};

