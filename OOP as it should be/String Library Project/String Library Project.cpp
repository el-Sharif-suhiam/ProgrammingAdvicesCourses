// String Library Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsString.h"

using namespace std;

int main()
{
	clsString string;
	string.Value = "Alshrif Fraj Suhaim";
	cout << "word num : " << string.CountWords() << endl;

	string.Split();
	string.Join("/--/");
	cout << "string after joining : " << string.Value << endl;
	string.Split("/--/");
	string.Join(" ");
	string.ReplaceWord("fraj", "Farag");
	cout << string.Value << endl; 
	string.RevserseWords();
	cout << string.Value << endl;

}

