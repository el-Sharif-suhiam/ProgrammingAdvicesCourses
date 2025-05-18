#pragma once
#include <iostream>
using namespace std;

namespace MyLib {
	void Test() {

		cout << "Hi, this my first function in my first library!" << endl;

	}

	int Sum2Num(int num1, int num2) {
		return num1 + num2;
	}
}