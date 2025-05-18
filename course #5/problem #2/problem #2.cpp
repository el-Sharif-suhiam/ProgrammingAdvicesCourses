// problem #2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ReadPostitiveNumber(string msg) {
    int number;
    do {
        cout << msg << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}


enum enIsPrimeNum {
    notPrime = 0, Prime = 1
};

enIsPrimeNum isPrimeNum(int num) {
    if (num <= 1) {
        return enIsPrimeNum::notPrime;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return enIsPrimeNum::notPrime;

        }
        
    }
    return enIsPrimeNum::Prime;
}

void printPrimeFrom1ToN(int N) {
    for (int i = 1; i <= N; i++) {
        if (isPrimeNum(i) == enIsPrimeNum::Prime) {
            cout << i << "\n";
        }
    }
}
int main()
{
   // cout << 9 % 4;
    printPrimeFrom1ToN(ReadPostitiveNumber("Enter the number ? "));
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
