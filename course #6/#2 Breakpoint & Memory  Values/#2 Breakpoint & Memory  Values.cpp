// #2 Breakpoint & Memory  Values.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
using namespace std;
int MySum(int a, int b)
{
	int s = 0;
	s = a + b;
	return s;
}
int main()
{
	int arr1[5] = { 200,100,50,25,30 };
	unsigned int a, b, c;
	string vv;
	a = 10;
	b = 20;
	a++;
	++b;
	c = a + b;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	for (int i = 1; i <= 5; i++)
	{
		cout << i << endl;
		a = a + a * i;
	}
	c = MySum(a, b);
	cout << c;
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
