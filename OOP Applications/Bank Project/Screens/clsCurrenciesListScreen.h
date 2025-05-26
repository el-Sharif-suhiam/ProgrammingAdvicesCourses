#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "..\Models\clsCurrency.h"
class clsCurrenciesListScreen : protected clsScreen
{
    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(40) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << to_string(Currency.Rate());
       
    }
public:

    static void ShowCurrenciesListScreen()
    {


        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        _DrawScreenHeader(" Currencies List Screen", "\t(" + to_string(vCurrencies.size()) + ") Currency.");
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
      
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency Currency : vCurrencies)
            {

                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

