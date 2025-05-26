#pragma once
#include <iostream>
#include <fstream>
#include "..\Utils\clsString.h"
#include <string>
using namespace std;
class clsLoginRecord
{

    string _Time;
    string _Username;
    string _Password;
    int _Permissions;

    static clsLoginRecord _ConvertLineToLoginData(string Line, string Seperator = "#//#") {
        vector<string> vcData = clsString::Split(Line, Seperator);
        clsLoginRecord LoginData;
        LoginData._Time = vcData[0];
        LoginData._Username = vcData[1];
        LoginData._Password = clsUtil::DecryptText(vcData[2],EncryptKey);
        LoginData._Permissions = stoi(vcData[3]);
        return LoginData;
    };
public:

    string Time() {
        return _Time;
    };

    string Username() {
        return _Username;
    };

    string Password() {
        return _Password;
    };

    int Permissions() {
        return _Permissions;
    }

    
    static vector<clsLoginRecord> LoadLoginRecordsFromFile() {
        vector<clsLoginRecord> Records;
        fstream File;
        File.open("Register.txt", ios::in);
        if (File.is_open()) {
            string Line;
            while (getline(File, Line)) {
                clsLoginRecord RecordObj = _ConvertLineToLoginData(Line);
                Records.push_back(RecordObj);
            };
            File.close();
        };
        return Records;

    };
};

