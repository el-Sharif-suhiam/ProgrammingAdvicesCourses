#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "..\Models\clsTransfer.h"
using namespace std;
class clsTransferLogsScreen : protected clsScreen
{

    static void _PrintTransferRecordLine(clsTransfer Log)
    {

        cout << setw(8) << left << "" << "| " << setw(22) << left << Log.GetTime();
        cout << "| " << setw(10) << left << Log.GetFrom();
        cout << "| " << setw(10) << left << Log.GetTo();
        cout << "| " << setw(10) << left << Log.GetAmount();
        cout << "| " << setw(12) << left << Log.GetFromBalanceAfter();
        cout << "| " << setw(12) << left << Log.GetToBalanceAfter();
        cout << "| " << setw(12) << left << Log.GetUser();

    }
public:

    static void ShowTransferLogsScreen()
    {


        vector <clsTransfer> vLogs = clsTransfer::LoadtranferLogsFromFile();
        _DrawScreenHeader(" Transfer Logs Screen", "\tNumber of Records(" + to_string(vLogs.size()) + ") Transfer(s).");
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(22) << "Date/Time";
        cout << "| " << left << setw(10) << "S.Acct";
        cout << "| " << left << setw(10) << "D.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(12) << "S.Balance";
        cout << "| " << left << setw(12) << "D.Balance";
        cout << "| " << left << setw(10) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLogs.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsTransfer log : vLogs)
            {

                _PrintTransferRecordLine(log);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

