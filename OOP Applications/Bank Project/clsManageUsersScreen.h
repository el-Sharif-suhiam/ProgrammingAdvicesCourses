#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUsersList.h"
#include "clsAddUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{

    enum _enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short _ReadManageUsersMenuOption() {
        cout << setw(37) << left << "" << "Choose what you want to do ? [1 to 6]\n";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
        return Choice;
    };
    static void _GoBackToManageUsersMenu()
    {
        cout << "\n\nPress any key to go back to Transactions Menu...";
        system("pause>0");
        ShowManageUsersMenu();
    };
    static void _ShowUsersListScreen() {
        clsUsersList::ShowAllUsersScreen();
    };

    static void _ShowAddUserScreen() {
        clsAddUserScreen::ShowAddUserScreen();
    };
    static void _ShowDeleteUserScreen() {
        clsDeleteUserScreen::DeleteUserSreen();
    };
    static void _ShowUpdateUserScreen() {
        clsUpdateUserScreen::UpdateUserScreen();
    };
    static void _ShowFindUserScreen() {
        clsFindUserScreen::FindUserScreen();
    };

    static void _PerfromManageUsersMenuOption(_enManageUsersMenueOptions MenuOption){
        switch (MenuOption)
        {
        case clsManageUsersScreen::eListUsers:
            system("cls");
            _ShowUsersListScreen();
            _GoBackToManageUsersMenu();
            break;
        case clsManageUsersScreen::eAddNewUser:
            system("cls");
            _ShowAddUserScreen();
            _GoBackToManageUsersMenu();
            break;
        case clsManageUsersScreen::eDeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenu();
            break;
        case clsManageUsersScreen::eUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenu();
            break;
        case clsManageUsersScreen::eFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;
        case clsManageUsersScreen::eMainMenue:
            break;
        default:
            break;
        }
    }
public: 

    static void ShowManageUsersMenu()
    {
        if (!CheckAccessRights(clsBankUser::enUserPermissions::pManageUsers)) {
            return;
        };

        system("cls");
        _DrawScreenHeader("Manage Users Menu");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tManage Users Menu Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _PerfromManageUsersMenuOption((_enManageUsersMenueOptions)_ReadManageUsersMenuOption());
    };

};

