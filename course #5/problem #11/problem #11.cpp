// problem #11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;



int ReadPostitiveNumber(string msg) {
    int number;
    do {
        cout << msg << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}


int reverseNumber(int num) {
    int reminder = 0, newNum = 0;
    while (num > 0) {
        reminder = num % 10;
        num /= 10;
        newNum = newNum * 10 + reminder;
    }
    return newNum;
}

bool isPalindrome(int num) {
  /*  int reversed = reverseNumber(num);
    short counter = 0, remain = 0, reverseRmain = 0;
    while (num > 0) {
        remain = num % 10;
        reverseRmain = reversed % 10;
        
        if (remain == reverseRmain) {
            counter++;
        }
        reversed /= 10;
        num /= 10;
    }
    if (counter > 0) {
        return true;
    }
    return false;*/

    return num == reverseNumber(num);
}
int main()
{
    int number = ReadPostitiveNumber("enter the number : ");
    cout << "\n";
    if (isPalindrome(number)) {
        cout << "Yes,it is a Palindrome number. \n";
    }
    else {
        cout << "No, it is NOT a Palindrom number. \n";
    }
    //printDigits(reverseNumber(number));
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
