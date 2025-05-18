// Problem #24.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
string FirstLetter(string sentence) {
    bool FirstL = true;
    cout << "The First Letters is : \n";
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] != ' ' && FirstL) {
            sentence[i] = toupper(sentence[i]);
        }
       


        FirstL = (sentence[i] == ' ' ? true : false);
    }
    return sentence;
}
int main()
{

    cout << FirstLetter(ReadMsg()) << "\n\n";

}
