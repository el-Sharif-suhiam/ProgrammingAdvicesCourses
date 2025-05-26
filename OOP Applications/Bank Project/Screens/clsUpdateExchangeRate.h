#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "..\Utils\clsInputValidate.h"
#include "..\Models\clsCurrency.h"
class clsUpdateExchangeRate : protected clsScreen
{
public:
	static void ShowUpdateExchangeRateScreen() {
		_DrawScreenHeader("Update Exchange Rate Screen");
		cout << "Enter The Currency Code : \n";
			string Code = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(Code);
			while (Currency.IsEmpty()) {
				cout << "Error, Invalid Currency Code, try again : \n";
				Currency = clsCurrency::FindByCode(Code);
			}
				clsScreen::_PrintCurrency(Currency);
				char answer = 'n';
				cout << "\nDo you Want to update the exchange rate ? y/n :\n";
				cin >> answer;
				if (toupper(answer) == 'Y') {
					cout << "\n\nEnter the new exchange rate :\n";
					float NewRate = clsInputValidate::ReadFloatNumber();
					Currency.UpdateRate(NewRate);
					cout << "The Exchange rate has been update!! ...\n";
					clsScreen::_PrintCurrency(Currency);
				}
	}
};

