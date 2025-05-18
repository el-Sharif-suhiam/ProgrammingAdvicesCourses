

#include <iostream>
#include <string>
using namespace std;

// #26

int getUsernumber() {
    int n;
    cout << "please enter N ?\n";
    cin >> n;
    return n;
}

void printN(int N) {
    for (int i = 1; i <= N; i++) {
        cout << i << endl;
    }
}
// #27
void printReversN(int N) {
    for (int i = N; i >= 1; i--) {
        cout << i << endl;
    }
}
int sumOddNums(int N) {
    int sum = 0;
    for (int i = 1; i <= N; i+=2) {
        sum += i;
    }
    return sum;
}

// #29
int sumEvenNums(int N) {
    int sum = 0;
    for (int i = 0; i <= N; i += 2) {
        sum += i;
    }
    return sum;
}

// #30

int FactorialOfN(int N) {
    if (N > 0) {
        int fact = 1;
        for (int i = N; i >= 1; i--) {
            fact *= i;
        }
        return fact;
    }
    else {
        return 000;
    }
   
}

int main()
{
    
    // #26
    cout << "This program is to print numbers from 1 to N\n";
    printN(getUsernumber());

    // #27
    cout << "This program is to print numbers from N to 1\n";
    printReversN(getUsernumber());

    // #28 
    cout << "This program is to Print Sum Odd Numbers from 1 to N\n";
    cout << "The result is: " << sumOddNums(getUsernumber()) << endl;

    // #29
    cout << "This program is to Print Sum Even Numbers from 1 to N\n";
    cout << "The result is: " << sumEvenNums(getUsernumber()) << endl;

    //#30
    cout << "This program is to Print Factorial of N!\n";
    cout << "The result is: " << FactorialOfN(getUsernumber()) << endl;

}
