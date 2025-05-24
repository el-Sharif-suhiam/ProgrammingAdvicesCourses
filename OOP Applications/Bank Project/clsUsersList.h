#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankUser.h"
using namespace std;

class clsUsersList : protected clsScreen
{

    static void _PrintUserRecordLine(clsBankUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.Username;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;
    }
public:

    static void ShowAllUsersScreen()
    {


        vector <clsBankUser> vUsers = clsBankUser::GetUsersList();
        _DrawScreenHeader(" Users List Screen", "\tUsers List(" + to_string(vUsers.size()) + ") User(s).");
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "User Name";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsBankUser User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

