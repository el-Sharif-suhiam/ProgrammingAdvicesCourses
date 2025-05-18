// Problem #30 count letter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


string ReadMsg() {
    string msg;
    cout << "Enter you sentence : \n";
    getline(cin, msg);

    return msg;
}
char ReadLetter() {
    char letter;
    cout << "Enter your letter that what you want to count : \n";
    cin >> letter;

    return letter;
}

short countLetter(string msg, char letter) {
    short Counter = 0;
    for (short i = 0; i < msg.length(); i++) {
        if (tolower(msg[i]) == tolower(letter)) {
            Counter++;
        }
    }
    return  Counter;
}


int main()
{
    string msg = ReadMsg();
    char letter = ReadLetter();
    cout << "the Count of the letter "<< letter << " , " << countLetter(msg, letter) << " times." << "\n";
    return 0;
}
