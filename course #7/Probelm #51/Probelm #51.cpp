
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

struct sClient {
    string accountNumber;
    string PinCode;
    string name;
    string phone;
    double accountBalance;
    bool markToDel = false;
};


string ReadMsg() {
    string msg;
    cout << "Enter Account Number ? \n";
    getline(cin, msg);

    return msg;
}
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
sClient LineToRecord(string txt, string sprt = " // ") {
    vector<string> vRecord = splitFunc(txt, sprt);

    sClient data;
    data.accountNumber = vRecord[0];
    data.PinCode = vRecord[1];
    data.name = vRecord[2];
    data.phone = vRecord[3];
    data.accountBalance = stod(vRecord[4]);

    return data;

}
void addDataToFile(vector<sClient>& data) {
    fstream myFile;

    myFile.open("ClientData.txt", ios::out);
    if (myFile.is_open()) {
        for (sClient& cl : data) {
            if (cl.markToDel == false) {
                string dataLine = RecordToLine(cl);
                myFile << dataLine << endl;
            }
        }
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

vector<sClient> GetClientsFromFile(string fileName) {
    fstream file;
    vector<sClient> vcClients;
    string line;
    file.open(fileName, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            vcClients.push_back(LineToRecord(line));
        }
        file.close();
    }
    return vcClients;
}

vector<sClient> UpdateClient(vector<sClient>& clients , string accNum) {
    for (sClient& cl : clients) {
        if (cl.accountNumber == accNum) {
            cout << "Enter Pin Code : \n";
            getline(cin >> ws, cl.PinCode);
            cout << "Enter Name: \n";
            getline(cin, cl.name);
            cout << "Enter Phone Number: \n";
            getline(cin, cl.phone);
            cout << "Enter Account Balance: \n";
            cin >> cl.accountBalance;
        }
    }

    return clients;
}
void PrintClientRecord(sClient Client)
{
    cout << "| " << setw(15) << left << Client.accountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.name;
    cout << "| " << setw(12) << left << Client.phone;
    cout << "| " << setw(12) << left << Client.accountBalance;
}
void PrintClients(vector<sClient> Clints) {
    cout << "\n\t\t\t\t\tClient List (" << Clints.size() << ") Clints(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    for (sClient& cli : Clints) {
        PrintClientRecord(cli);
        cout << endl;
    }
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

bool markClientToDelete(vector<sClient>& clients, string accNum) {
    for (sClient& cl : clients) {
        if (accNum == cl.accountNumber) {
            cl.markToDel = true;
            return true;
        }
    }
    return false;
}


bool GetClientByAccNum(string accNum, vector<sClient>& Clients, sClient& client) {

    for (sClient& cl : Clients) {
        if (cl.accountNumber == accNum) {
            client = cl;
            return true;
        }

    }
    return false;

}

bool DeleteClientByAccNum(string accNum, vector<sClient>& clients) {
    sClient client;
    char answer = 'n';
    if (GetClientByAccNum(accNum, clients, client)) {
        WriteClientData(client);
        cout << "Do you want to delete this accout ? 'Y' for yes \n";
        cin >> answer;
        if (toupper(answer) == 'Y') {
            markClientToDelete(clients, accNum);
            addDataToFile(clients);
            return true;
        }
    }
    return false;
}

bool UpdateClientByAccNum(string accNum, vector<sClient>& clients) {
    sClient client;
    char answer = 'n';
    if (GetClientByAccNum(accNum, clients, client)) {
        WriteClientData(client);
        cout << "Do you want to update this accout ? 'Y' for yes \n";
        cin >> answer;
        if (toupper(answer) == 'Y') {
            UpdateClient(clients, accNum);
            addDataToFile(clients);
            return true;
        }
    }
    return false;
}
int main()
{
    string accNum = ReadMsg();
    vector<sClient> Clients = GetClientsFromFile("ClientData.txt");


    if (UpdateClientByAccNum(accNum, Clients)) {
        cout << "The account with number " << accNum << " has been Updated \n";
    }
    else {
        cout << "Client with Account Number (" << accNum << ") Not Found! \n";
    }
    system("pause>0");
    return 0;
}
