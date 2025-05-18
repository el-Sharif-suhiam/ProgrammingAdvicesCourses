// peoblem #18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

string ReadWord(string msg) {
    string word;
    cout << "\n" << msg << "\n";
    cin >> word;

    return word;
}

int ReadPostitiveNumber(string msg) {
    int number;
    do {
        cout << msg << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}

string encryption(string name , short key) {
    string encrypted = "";
    short theKey = key;
    if (key > 122) {
        theKey = 2;
    }
    

    for (int i = 0; i < name.length(); i++) {
        name[i] = char(int(name[i]) + theKey);
    }
    return name;
}


string decryption(string name, short key) {
    string decrypted = "";
    short theKey = key;
    if (key > 122) {
        theKey = 2;
    }

    for (int i = 0; i < name.length(); i++) {
        name[i] = char(int(name[i]) - theKey);
    }
    return name;
}
int main()
{
    string word = ReadWord("enter the word that you want to encrypt it ? ");
    short key = ReadPostitiveNumber("enter enryption key ?");
    string encryptedWord = encryption(word, key);

    cout << "Text Before Encryption: " << word << endl;

    cout << "Text After Encryption: " << encryptedWord << endl;
    cout << "Text After Decryption: " << decryption(encryptedWord, key) << endl;
    
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
