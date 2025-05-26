#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "..\Utils\clsInputValidate.h"
#include "..\Models\clsCurrency.h"
class clsCurrencyCalculator : protected clsScreen
{
	static float _ExchangeCurrencies(float Amount, clsCurrency &FirstCurrency, clsCurrency& SecondCurrency) {
		if (FirstCurrency.CurrencyCode() == "USD") {
			return Amount * SecondCurrency.Rate();
		}
		else if (SecondCurrency.CurrencyCode() == "USD") {
			return Amount / FirstCurrency.Rate();
		}
		else {
			return (Amount / FirstCurrency.Rate()) * SecondCurrency.Rate();
		}
	};
	static clsCurrency _ValidateCurrency() {
		string Code = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(Code);
		while (Currency.IsEmpty()) {
			cout << "Error, Invalid Currency Code, try again : \n";
			Currency = clsCurrency::FindByCode(Code);
		}
		clsScreen::_PrintCurrency(Currency);
		return Currency;
	}
public:
	static void ShowCurrencyCalculatorScreen() {
		_DrawScreenHeader("Currency Calculator Screen");
		char Continue = 'Y';

		while (toupper(Continue) == 'Y') {

			cout << "Enter The First Currency Code : \n";
			clsCurrency FirstCurrency = _ValidateCurrency();
			cout << "\nEnter The Second Currency Code : \n";
			clsCurrency SecondCurrency = _ValidateCurrency();

			cout << "Enter the amount of " << FirstCurrency.CurrencyName() << " that you want change it to " <<
				SecondCurrency.CurrencyName() << " : \n";
			float Amount = clsInputValidate::ReadFloatNumber();

			cout << "The Result is : " << _ExchangeCurrencies(Amount, FirstCurrency, SecondCurrency) << " " << SecondCurrency.CurrencyCode();

			cout << "\n\n Do you want to preform another calculation ? \n";
			cin >> Continue;
		}
		
	}

};

