#pragma once
#include <iostream>

using namespace std;

namespace MyInput {
	int ReadPostiveNumber(string msg) {
		int num;
		do {
			cout << msg << endl;
			cin >> num;
		} while (num >= 0);
		return num;
	}
	int readNumber() {
		int num;
		cout << "Enter the number ? \n";
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invaild Number, enter a valid one \n";
			cin >> num;
		}
		return num;
	}
}