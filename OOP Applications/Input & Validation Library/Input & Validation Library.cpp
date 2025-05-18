// Input & Validation Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsInputValidate.h"

using namespace std;

int main()
{
	cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
	cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.0) << endl;

	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(8,3,2025), 
		clsDate(31,12,2025))<< endl;

	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(31, 12, 2025),
		clsDate(8, 3, 2025)) << endl;

	int x = clsInputValidate::ReadIntNumber("Please enter a number : ", "Invalid Number, Enter again: ");
	cout << "x= " << x << endl;

	int y = clsInputValidate::ReadIntNumberBetween(18, 70, "The number is not within " + to_string(18) + " and " + to_string(70));
	cout << "y = " << y << endl;

	double a = clsInputValidate::ReadDblNumber("Please enter a Double number: ", "Invalid Number try again :");
	cout << "a = " << a << endl;

	double b = clsInputValidate::ReadDblNumberBetween(20.66, 25.88, "The number is not within " + to_string(20.66) + " and " + to_string(25.88));
	cout << "b = " << b << '\n';

	cout << clsInputValidate::IsValideDate(clsDate(35, 12,2022)) << '\n';
	system("pause >0");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
