#pragma once
#include <iostream>
using namespace std;
class clsPerson {
    struct stAddress {
        string AddressLine1;
        string AddressLine2;
        string City;
        string Country;
    };
    class clsAddress
    {
        stAddress Address;
    public:

        clsAddress(string add1, string add2, string city, string country) {
            Address.AddressLine1 = add1;
            Address.AddressLine2 = add2;
            Address.City = city;
            Address.Country = country;
        }
        void Print()
        {
            cout << "\nAddress:\n";
            cout << Address.AddressLine1 << endl;
            cout << Address.AddressLine2 << endl;
            cout << Address.City << endl;
            cout << Address.Country << endl;
        }
        void SetAddress1(string add) {
            Address.AddressLine1 = add;
        };

        string Address1() {
            return Address.AddressLine1;
        };

        void SetAddress2(string add) {
            Address.AddressLine2 = add;
        };

        string Address2() {
            return Address.AddressLine2;
        };

        void SetCity(string city) {
            Address.City = city;
        };

        string City() {
            return Address.City;
        };

        void SetCountry(string country) {
            Address.Country = country;
        };

        string Country() {
            return Address.Country;
        };
    };

public:
    string FullName;
    clsAddress Address = clsAddress("", "", "", "");
    clsPerson(string name, string add1, string add2, string city, string country) {
        FullName = name;
        Address = clsAddress(add1, add2, city, country);
    }



};
