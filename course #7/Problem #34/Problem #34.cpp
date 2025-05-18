// Problem #34.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    cout << "Enter your letter : \n";
    cin >> letter;

    return letter;
}

bool isVowle(char letter) {
    letter = tolower(letter);
    return (letter == 'a' || letter == 'e' || letter == 'o' || letter == 'i' || letter == 'u');
}
void WriteVowels(string msg) {
   
    for (short i = 0; i < msg.length(); i++) {
        if (isVowle(msg[i])) {
            cout << msg[i] << " ";
        }
    }
    cout << endl;
}


int main()
{
    string msg = ReadMsg();
    //char letter = ReadLetter();

    cout << "\nVowles in string are: "; 
    WriteVowels(msg);
    return 0;
}
