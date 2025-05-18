// Person Exercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class clsPerson {
private:
    short _id;
    string _FirstName;
    string _LastName;
    string _Email;
    string _PhoneNum;
public:
    clsPerson(short id, string fName, string lName, string email, string phoneNum) {
        _id = id;
        _FirstName = fName;
        _LastName = lName;
        _Email = email;
        _PhoneNum = phoneNum;
    }

    void Print() {
        cout << "\nInfo: \n\n";
        cout << "______________________________________\n";
        cout << "id            : " << _id << endl;
        cout << "First Name    : " << _FirstName << endl;
        cout << "Last Nam      : " << _LastName << endl;
        cout << "Full Name     : " << _FirstName << " " << _LastName << endl;
        cout << "Email         : " << _Email << endl;
        cout << "Phone Number  : " << _PhoneNum << endl;
        cout << "_______________________________________\n";
    }
    void SendEmail(string subject, string body) {
        cout << "\nThe following message sent successfully to email : " << _Email << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
    }

    void SendSms(string sms) {
        cout << "\nThe following SMS sent successfully to phone: " << _PhoneNum << endl;
        cout << sms << endl;
    }
};


int main()
{
    clsPerson person(10, "ALsharif", "Suhaim", "ehy@email.com", "4434864131876");
    person.Print();
    person.SendEmail("hi", "hello how are you ?");
    person.SendSms("hi my brother");
    system("pause >0");
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
