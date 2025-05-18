// Constructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class clsAddress {
private:
    string _FirstAddress;
    string _SecondAddress;
    string _PhoneNumber;
    int _ZipCode;
public:
    clsAddress(string firstAdd, string secondAdd, string phoneNum, int zipCode) {
        _FirstAddress = firstAdd;
        _SecondAddress = secondAdd;
        _PhoneNumber = phoneNum;
        _ZipCode = zipCode;
    };

    void PrintAddress() {
        cout << "Your First  Address is : " << _FirstAddress << endl;
        cout << "Your Second Address is : " << _SecondAddress << endl;
        cout << "Your Phone  Number is : "  << _PhoneNumber << endl;
        cout << "Your Zip code is : "  << _ZipCode << endl;
    }

};
int main()
{
    clsAddress Address1("Brega Libya", "100 street", "4546468927", 48620);
    Address1.PrintAddress();

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
