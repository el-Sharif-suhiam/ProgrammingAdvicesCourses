// Problem #22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


void WriteFiboWithRecursive(short loop, short prv1, short prv2) {
    if (loop < 0)
        return;
    
    int fibo = 0;
    fibo = prv1 + prv2;

    prv2 = prv1;
    prv1 = fibo;
    cout << fibo << " ";

    WriteFiboWithRecursive(loop - 1, prv1, prv2);

}
int main()
{

    WriteFiboWithRecursive(10, 0, 1);
}