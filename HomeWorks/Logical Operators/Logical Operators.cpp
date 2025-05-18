// Logical Operators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    cout << (12 >= 12) << endl; // 1
    cout << (12 > 7) << endl; // 1
    cout << (8 < 6) << endl; // 0
    cout << (8 == 8) << endl; // 1
    cout << (12 <= 12) << endl; // 1
    cout << (7 == 5) << endl; // 0
    cout << "*********************" << endl;
    cout << !(12 >= 12 ) << endl; // 0
    cout << !(12 < 7) << endl; // 1
    cout << !(8 < 6) << endl; // 1
    cout << !(8 == 8) << endl; // 0
    cout << !(12 <= 12) << endl; // 0
    cout << !(7 == 5) << endl; // 1
    cout << "*********************" << endl;
    cout << (1 && 1) << endl; // 1
    cout << (true && 0) << endl; // 0
    cout << (0 || 1) << endl; // 1
    cout << (0|| 0) << endl; // 0
    cout << (!0) << endl; // 1
    cout << !(1 || 0) << endl; // 0
    cout << "*********************" << endl;
    cout << ((7 == 7) && (7 > 5)) << endl; // 1
    cout << ((7 == 7) && (7 < 5)) << endl; // 0
    cout << ((7 == 7) || (7 < 5)) << endl; // 1
    cout << ((7 < 7) || (7 > 5)) << endl; // 1
    cout << !((7 == 7) && (7 > 5)) << endl; // 0
    cout << ((7 == 7) && !(7 < 5)) << endl; // 1
    cout << "*********************" << endl;
    cout << "second test : " << endl;
    cout << ((5 > 6 && 7 == 7) || (1 || 0)) << endl; // 1
    cout << (!(5 > 6 && 7 == 7) || (1 || 0)) << endl; // 1
    cout << (!(5 > 6 || 7 == 7) && !(1 || 0)) << endl; // 0
    cout << (((5 > 6 && 7 <= 8 ) || (8 > 1 && 4 <= 3 )) && true) << endl; // 0
    cout << (((5 > 6 && !(7 <= 8)) && (8 > 1 || 4 <= 3)) || true) << endl; // 1
             


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
