#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "..\Models\clsCurrency.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateExchangeRate.h"
#include "clsCurrencyCalculator.h"
class clsCurrencyExchangeScreen : protected clsScreen
{
    enum _enCurrencyExchangeMenuOptions { eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalaculator= 4,  eShowMainMenue = 5 };
    static short _ReadCurrencyExchangeMenuOption() {
        cout << setw(37) << left << "" << "Choose what you want to do ? [1 to 5]\n";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5);
        return Choice;
    };
    static void _GoBackToCurrencyExchangeMainMenu()
    {
        cout << "\n\nPress any key to go back to Currency Exchange Menu...";
        system("pause>0");
        _ShowCurrencyExchangeMenu();
    };
   
    static void _ShowListCurrenciesScreen() {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    };
    static void _ShowFindCurrencyScreen() {
        clsFindCurrency::ShowFindCurrency();
    };
    static void _ShowUpdateRateScreen() {
        clsUpdateExchangeRate::ShowUpdateExchangeRateScreen();
    };
    static void _ShowCurrencyCalculatorScreen() {
        clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
    };
    static void _ShowCurrencyExchangeMenu() {
        ShowCurrencyExchangeMenu();
    };
    static void _PerfromCurrencyExchangeMenuOption(_enCurrencyExchangeMenuOptions MenuOption) {
        switch (MenuOption)
        {
        case clsCurrencyExchangeScreen::eListCurrencies:
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMainMenu();
            break;
        case clsCurrencyExchangeScreen::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMainMenu();
            break;
        case clsCurrencyExchangeScreen::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMainMenu();
            break;
        case clsCurrencyExchangeScreen::eCurrencyCalaculator:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMainMenu();
            break;
        case clsCurrencyExchangeScreen::eShowMainMenue:
            break;
        default:
            break;
        }
    };

public:
    static void ShowCurrencyExchangeMenu() {

        system("cls");
        _DrawScreenHeader("Currency Exchange Menu");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerfromCurrencyExchangeMenuOption((_enCurrencyExchangeMenuOptions)_ReadCurrencyExchangeMenuOption());
    }

};

