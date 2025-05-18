// problem1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void printHeader() {
    cout << "\n\n\t\t\t Multiplication Table From 1 to 10\n\n";
    cout << "\t";
    for (short i = 1; i <= 10; i++) {
        cout << i << "\t";
    }
    //cout << "       1       2       3       4       5       6       7       8       9       10 \n\n";
    cout << "\n__________________________________________________________________________________\n";
}
string numSpertator(short i) {
    if (i < 10) {
        return "   |";
    }
    else {
        return "  |";
    }
}

void printMultiply(short num) {

    for (short i = 1; i <= 10; i++) {
    cout << i * num << "      ";
    }
    cout << "\n";
}

void printMultiplyTable() {
    printHeader();
    for (short i = 1; i <= 10; i++) {
        cout << i << numSpertator(i) << "\t";
        for (short j = 1; j <= 10; j++) {
            cout << i * j << "\t";
        }
        cout << "\n";
    }
    //for (short i = 1; i <= 10; i++) {
    //    cout << i << "  |   ";
    //    printMultiply(i);
    //   //cout << "\n";
    //}
}
int main()
{
    //printHeader();
    printMultiplyTable();

    return 0;

}
