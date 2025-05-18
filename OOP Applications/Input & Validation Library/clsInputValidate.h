#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;
class clsInputValidate
{

public:
	static bool IsNumberBetween(int num, int from, int to) {
		return (num >= from && num <= to);
	};
	static bool IsNumberBetween(double num, double from, double to) {
		return (num >= from && num <= to);
	};
	static bool IsNumberBetween(float num, float from, float to) {
		return (num >= from && num <= to);
	};

	static bool IsDateBetween(clsDate currentDate, clsDate FromDate, clsDate ToDate) {
	
		if((clsDate::IsDate1AfterDate2(currentDate, FromDate) || clsDate::IsDate1EqualDate2(currentDate,FromDate)) 
			&& (clsDate::IsDate1BeforeDate2(currentDate, ToDate) || clsDate::IsDate1EqualDate2(currentDate, ToDate))) {
			return true;
		}else if((clsDate::IsDate1AfterDate2(currentDate, ToDate) || clsDate::IsDate1EqualDate2(currentDate, ToDate))
			&& (clsDate::IsDate1BeforeDate2(currentDate, FromDate) || clsDate::IsDate1EqualDate2(currentDate, FromDate))) {
				return true;
		}
		else {
			return false;
		}


	};

	static int ReadIntNumber(string PromtMsg, string ErrorMsg) {
		int number;
		cout << PromtMsg << endl;
		cin >> number;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMsg << endl;
			cin >> number;
		};
		return number;

	};

	static double ReadDblNumber(string PromtMsg, string ErrorMsg) {
		double number;
		cout << PromtMsg << endl;
		cin >> number;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMsg << endl;
			cin >> number;
		};
		return number;

	};

	static int ReadIntNumberBetween(int from, int to, string ErrorMsg) {
		int num = ReadIntNumber("Please enter a number between " + to_string(from) + " to " + to_string(to), ErrorMsg);
		while (!IsNumberBetween(num, from, to)) {

			num = ReadIntNumber("Please enter a number between " + to_string(from) + " to " + to_string(to), ErrorMsg);

		};
		return num;
	};

	static double ReadDblNumberBetween(double from, double to, string ErrorMsg) {
		double num = ReadDblNumber("Please enter a number between " + to_string(from) + " to " + to_string(to), ErrorMsg);
		while (!IsNumberBetween(num, from, to)) {
			num = ReadDblNumber("Please enter a number between " + to_string(from) + " to " + to_string(to), ErrorMsg);
		};
		return num;
	};

	static bool IsValideDate(clsDate date) {
		return clsDate::IsValidDate(date);
	};
};

