#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "..\Utils\clsInputValidate.h"
#include "..\Models\clsCurrency.h"
class clsFindCurrency : protected clsScreen
{

public:
	static void ShowFindCurrency(){
		_DrawScreenHeader("Find Currency Screen");
		cout << "Find Currency by: 1 - Country, 2 - Code : \n";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 2);
		if (choice == 1) {
			cout << "\nEnter The Country Name : \n";
			string Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			if (!Currency.IsEmpty())
				clsScreen::_PrintCurrency(Currency);
			else
				cout << "\nError, Invalid Country Name \n\n";
		}
		else {
			cout << "\nEnter The Currency Code  : \n";
			string Code = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(Code);
			if (!Currency.IsEmpty())
				clsScreen::_PrintCurrency(Currency);
			else
				cout << "\nError, Invalid Currency Code \n\n";
		}
	}
};

