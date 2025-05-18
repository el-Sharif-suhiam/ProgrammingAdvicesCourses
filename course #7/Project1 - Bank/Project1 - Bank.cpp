// Project1 - Bank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
void MainScreen();
struct sClient {
    string accountNumber;
    string PinCode;
    string name;
    string phone;
    double accountBalance;
    bool markToDel = false;
};
void TransactionsScreen(vector<sClient> &clients);

// General 
string ReadMsg() {
    string msg;
    cout << "Enter Account Number ? \n";
    getline(cin>> ws, msg);

    return msg;
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


string RecordToLine(sClient data, string sprt = " // ") {
    string line = "";
    line += data.accountNumber + sprt;
    line += data.PinCode + sprt;
    line += data.name + sprt;
    line += data.phone + sprt;
    line += to_string(data.accountBalance) + sprt;

    return line;

}


void WriteClientData(sClient data) {
    cout << "Account Number  : " << data.accountNumber << endl;
    cout << "Pin Code        : " << data.PinCode << endl;
    cout << "Name            : " << data.name << endl;
    cout << "Phone Number    : " << data.phone << endl;
    cout << "Account Balance : " << data.accountBalance << endl;

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
sClient ReadClient(string accNum) {
    sClient client;
    client.accountNumber = accNum;
    cout << "Enter Pin Code : \n";
    getline(cin >> ws, client.PinCode);
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

vector<sClient> UpdateClient(vector<sClient>& clients, string accNum) {
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

void UpdateBalances(string accNum, vector<sClient>& clients, int NewBalance) {
    for (sClient& cl : clients) {
        if (cl.accountNumber == accNum) {
           cl.accountBalance = NewBalance;
           break; 
        }
    }
    addDataToFile(clients);
}


bool MakeDeposit(string accNum, vector<sClient>& clients, sClient& cl) {
    int deposit;
    do {
        cout << "How much do you want to deposit? \n\n";
        cin >> deposit;
    } while (deposit < 0);
    char answer;
    cout << "Do you want to make Deposit ? y/n \n";
    cin >> answer;
    if (tolower(answer) == 'y') {
        UpdateBalances(accNum, clients, deposit + cl.accountBalance);
        return true;
    }
}
void MakeWithdraw(string accNum, vector<sClient>& clients, sClient & cl) {
    int withdraw;
    do {
        cout << "How much do you want to Withdraw? \n\n";
        cin >> withdraw;
    } while (withdraw < 0);
    if (withdraw <= cl.accountBalance) {
        char answer;
        cout << "Do you want to make Withdraw ? y/n \n";
        cin >> answer;
        if (tolower(answer) == 'y') {
            UpdateBalances(cl.accountNumber, clients, cl.accountBalance - withdraw);
        }
    }
    else {
        cout << "the account balance is less then this number \n\n";
    }
    
    
}

void PrintClientBalance(sClient &Client)
{
    cout << "| " << setw(15) << left << Client.accountNumber;
    cout << "| " << setw(40) << left << Client.name;
    cout << "| " << setw(12) << left << Client.accountBalance;
}
void PrintBalances(vector<sClient> &Clints) {
    int total = 0;
    cout << "\n\t\t\t\t\tClient List (" << Clints.size() << ") Clints(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    for (sClient& cli : Clints) {
        PrintClientBalance(cli);
        total += cli.accountBalance;
        cout << endl;
    }
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\n\t\t\t\t\tTotal Balances = " << total << "\n\n";

}

////////////// Screens /////////////
void ShowClientScreen(vector<sClient> &clients) {
    PrintClients(clients);
    cout << "press any key to return to main screen ?";
    system("pause>0");
    MainScreen();
};

void AddClientScreen(vector<sClient> &clients) {
    sClient cl;
    cout << "-------------------------------------------\n";
    cout << "           Add New Client Screen           \n";
    cout << "-------------------------------------------\n";
    cout << "Adding New Client: \n\n";
    string accNum = ReadMsg();

    while (GetClientByAccNum(accNum, clients, cl)) {
        cout << "Client with account [" << accNum << "] already exists, Enter anoter Account Number?";
        cin >> accNum;
    };
    sClient newCl = ReadClient(accNum);
    clients.push_back(newCl);
    addDataToFile(clients);
    cout << "The Account has been added\n\n";
    cout << "press any key to return to main screen ?";
    system("pause>0");
    MainScreen();
}

void DeleteClientScreen(vector<sClient> &clients) {
    sClient cl;
    cout << "-------------------------------------------\n";
    cout << "             Delete Client Screen           \n";
    cout << "-------------------------------------------\n";
    string accNum = ReadMsg();

    if(GetClientByAccNum(accNum, clients, cl)) {
        DeleteClientByAccNum(accNum, clients);
        cout << "Client with account [" << accNum << "] has been Deleted.....\n";
    }
    else {
        cout << "Client with account [" << accNum << "] is not exist.\n";
    }
    cout << "press any key to return to main screen ?";
    system("pause>0");
    MainScreen();
}

void UpdateScreen(vector<sClient>& clients) {
    sClient cl;
    cout << "-------------------------------------------\n";
    cout << "            Update Client Screen           \n";
    cout << "-------------------------------------------\n";
    cout << "Enter account you want to update:\n\n";
    string accNum = ReadMsg();

    if (GetClientByAccNum(accNum, clients, cl)) {
        UpdateClientByAccNum(accNum, clients);
        cout << "Client with account [" << accNum << "] has been Updated.....\n";
    }
    else {
        cout << "Client with account [" << accNum << "] is not exist.\n";
    }
    cout << "press any key to return to main screen ?";
    system("pause>0");
    MainScreen();
}

void FindScreen(vector<sClient>& clients) {
    sClient cl;
    cout << "-------------------------------------------\n";
    cout << "             Find Client Screen            \n";
    cout << "-------------------------------------------\n";
    string accNum = ReadMsg();

    if (GetClientByAccNum(accNum, clients, cl)) {
        cout << "\nThe following are the client details: \n";
        cout << "----------------------------------------\n";
        WriteClientData(cl);
        cout << "----------------------------------------\n\n\n";
    }
    else {
        cout << "Client with account [" << accNum << "] is not exist.\n";
    }
    cout << "press any key to return to main screen ?";
    system("pause>0");
    MainScreen();
}

void DepositScreen(vector<sClient>& clients) {
    sClient cl;
    cout << "-------------------------------------------\n";
    cout << "             Deposit Screen                \n";
    cout << "-------------------------------------------\n";
    string accNum = ReadMsg();

       
    while (!GetClientByAccNum(accNum, clients, cl)) {
            cout << "Client with account [" << accNum << "] is not exist.\n";
            accNum = ReadMsg();
    }
   cout << "\nThe following are the client details: \n";
   cout << "----------------------------------------\n";
   WriteClientData(cl);
   cout << "----------------------------------------\n\n";
   
   MakeDeposit(accNum, clients,cl);
   cout << "press any key to return to main screen ?";
   system("pause>0");
   TransactionsScreen(clients);
       
}
void WithdrawScreen(vector<sClient> clients) {
    sClient cl;
    cout << "-------------------------------------------\n";
    cout << "             Withdraw Screen                \n";
    cout << "-------------------------------------------\n";
    string accNum = ReadMsg();


    while (!GetClientByAccNum(accNum, clients, cl)) {
        cout << "Client with account [" << accNum << "] is not exist.\n";
        accNum = ReadMsg();
    }
    cout << "\nThe following are the client details: \n";
    cout << "----------------------------------------\n";
    WriteClientData(cl);
    cout << "----------------------------------------\n\n";

    MakeWithdraw(accNum, clients,cl);
    cout << "press any key to return to main screen ?\n";
    system("pause>0");
    TransactionsScreen(clients);
}
void TotalBalances(vector<sClient> clients) {
    PrintBalances(clients);
    cout << "press any key to return to main screen ?\n";
    system("pause>0");
    TransactionsScreen(clients);
}
void TransactionsScreen(vector<sClient>& clients) {
    system("cls");

    short answer;
    do {
        cout << "=======================================\n";
        cout << "           Transactions Menu Secreen           \n";
        cout << "=======================================\n";
        cout << "    [1] Deposit.\n";
        cout << "    [2] Withdraw.\n";
        cout << "    [3] Total Balances.\n";
        cout << "    [4] Main Menu.\n";
        cout << "=======================================\n";
        cout << "Choose what do you want to do? [1 to 4]?\n";
        cin >> answer;
    } while (answer > 4 || answer < 1);
    system("cls");
    switch (answer)
    {
    case 1:
        DepositScreen(clients);
        break;
    case 2:
        WithdrawScreen(clients);
        break;
    case 3:
        TotalBalances(clients);
        break;
    case 4:
        MainScreen();
    default:
        break;
    }
}
void ExitScreen() {
    cout << "\n-------------------------------------------\n";
    cout << "               Program Ends :-)            \n";
    cout << "--------------------------------------------";
    system("pause>0");
}
void MainScreen() {
    short answer = 0;
    vector<sClient> Clients = GetClientsFromFile("ClientData.txt");
    do {
        system("cls");
        cout << "=======================================\n";
        cout << "           Main Menu Secreen           \n";
        cout << "=======================================\n";
        cout << "    [1] Show Client List.\n";
        cout << "    [2] Add New Client.\n";
        cout << "    [3] Delete Client.\n";
        cout << "    [4] Update Client Info.\n";
        cout << "    [5] Find Client.\n";
        cout << "    [6] Transactions.\n";
        cout << "    [7] Exit.\n";
        cout << "=======================================\n";
        cout << "Choose what do you want to do? [1 to 7]?\n";
        cin >> answer;
    } while (answer > 7 || answer < 1);
    system("cls");
    switch (answer)
    {
    case 1:
        ShowClientScreen(Clients);
        break;
    case 2:
        AddClientScreen(Clients);
        break;
    case 3:
        DeleteClientScreen(Clients);
        break;
    case 4:
        UpdateScreen(Clients);
        break;
    case 5:
        FindScreen(Clients);
        break;
    case 6:
        TransactionsScreen(Clients);
        break;
    case 7:
        ExitScreen();
        break;
    default:
        break;
    }

}
int main()
{
    MainScreen();
    return 0;
}
