// Problem #27 invert char.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string >
using namespace std;

char ReadMsg() {
    char msg;
    cout << "Enter your char : \n";
    cin >> msg;

    return msg;
}
char InvertChar(char letter) {
    cout << "Inverted char : \n";
    return isupper(letter) ? tolower(letter) : toupper(letter);
   
}

int main()
{
    char msg = ReadMsg();
    cout << InvertChar(msg) << "\n\n";

    return 0;
}