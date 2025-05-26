#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "..\Models\clsLoginRecord.h"
using namespace std;

class clsLoginHistoryScreen : protected clsScreen
{

   
    static void _PrintLoginRecordLine(clsLoginRecord record)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << record.Time();
        cout << "| " << setw(20) << left << record.Username();
        cout << "| " << setw(20) << left << record.Password();
        cout << "| " << setw(10) << left << record.Permissions();
    }
public:

    static void ShowLoginHistoryScreen()
    {
        if (!CheckAccessRights(clsBankUser::enUserPermissions::pLoginRegister)) {
            return;
        }

        vector <clsLoginRecord> vRecords = clsLoginRecord::LoadLoginRecordsFromFile();

        _DrawScreenHeader(" Login Register Screen", "\tRegister List(" + to_string(vRecords.size()) + ").");
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "Username";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vRecords.size() == 0)
            cout << "\t\t\t\tNo Record Available In the System!";
        else

            for (clsLoginRecord Record : vRecords)
            {

                _PrintLoginRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

