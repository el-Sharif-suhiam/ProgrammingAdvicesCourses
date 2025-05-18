// Set & Get.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Person {
private:
    string _FirstName;
    string _LastName;

public:
    void SetFirstName(string FirstName) {
        _FirstName = FirstName;
    }

    string GetFirstName() {
        return _FirstName;
    }

    void SetLastName(string LastName) {
        _LastName = LastName;
    }
    string GetLastName() {
        return _LastName;
    }

    string GetFullName() {
        return _FirstName + " " + _LastName;
    }

    __declspec(property(get =  GetFirstName, put = SetFirstName)) string FirstName;
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;

    __declspec(property(get = GetFullName)) string FullName;

};
int main()
{
    Person person1;

    cout << person1.FirstName << endl;
    person1.FirstName = "Alsharif" ;
    person1.LastName = "Suhaim";
    cout << person1.FirstName << endl;

    cout << person1.FullName << endl;


}
