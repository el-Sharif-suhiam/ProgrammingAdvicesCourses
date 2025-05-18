// Problem #47.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct sClient {
    string accountNumber;
    string PinCode;
    string name;
    string phone;
    double accountBalance;
};

void WriteClientData(sClient data) {
    cout << "Enter Account Number: " << data.accountNumber << endl;
    cout << "Enter Pin Code: " << data.PinCode << endl;
    cout << "Enter Name: " << data.name << endl;
    cout << "Enter Phone Number: " << data.phone << endl;
    cout << "Enter Account Balance: " << data.accountBalance << endl;

}

string RecordToLine(sClient data, string sprt = " // ") {
    string line = "";
    line += data.accountNumber + sprt;
    line += data.PinCode + sprt;
    line += data.name + sprt;
    line += data.phone + sprt;
    line += to_string(data.accountBalance) + sprt;

    return line;

}


vector<string> splitFunc(string msg, string delmi) {
    vector<string> vcWords;
    short pos = 0;
    string subtxt;
    while ((pos = msg.find(delmi)) != std::string::npos) {
        subtxt = msg.substr(0, pos);
        if (subtxt != "") {
            vcWords.push_back(subtxt);
        }

        msg.erase(0, pos + delmi.length());
    }
    if (msg != "") {

        vcWords.push_back(msg);
    }
    return vcWords;
}
sClient LineToRecord(string txt, string sprt = "#//#") {
    vector<string> vRecord = splitFunc(txt, sprt);

    sClient data;
    data.accountNumber = vRecord[0];
    data.PinCode = vRecord[1];
    data.name = vRecord[2];
    data.phone = vRecord[3];
    data.accountBalance = stod(vRecord[4]);

    return data;

}
void addDataToFile(sClient data) {
    fstream myFile;
    string dataLine = RecordToLine(data);
    myFile.open("ClientData.txt", ios::out | ios::app);
    if (myFile.is_open()) {
        myFile << dataLine << endl;
        myFile.close();
    }
    
}
sClient ReadClient() {
    sClient client;
    cout << "Enter Account Number : \n";
    getline(cin >> ws, client.accountNumber);
    cout << "Enter Pin Code : \n";
    getline(cin, client.PinCode);
    cout << "Enter Name: \n";
    getline(cin, client.name);
    cout << "Enter Phone Number: \n";
    getline(cin, client.phone);
    cout << "Enter Account Balance: \n";
    cin >> client.accountBalance;

    return client;
}

void AddOneClient() {
    sClient client = ReadClient();
    addDataToFile(client);
}
void AddClients() {
    char wantAdd = 'Y';
    do {
        system("cls");
        AddOneClient();
        cout << "want to add new client ?";
        cin >> wantAdd;
    } while (wantAdd == 'Y');
}
int main()
{
   /* string line = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
    cout << "the line is : " << line << endl;
    sClient data = LineToRecord(line);*/

    AddClients();
    system("pause>0");
    return 0;
}
