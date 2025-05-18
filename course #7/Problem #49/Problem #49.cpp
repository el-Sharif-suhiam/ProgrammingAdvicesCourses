
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


void showClientByAccNum(string accNum) {
    vector<sClient> Clients = GetClientsFromFile("ClientData.txt");
    for (sClient cl : Clients) {
        if ( cl.accountNumber == accNum) {
            cout << "The following are the client details: \n\n";
            WriteClientData(cl);
            return;
        }
        
    }
        cout << "Client with Account Number (" << accNum << ") Not Found! \n";
       
}
int main()
{
    showClientByAccNum(ReadMsg());
    system("pause>0");
    return 0;
}
