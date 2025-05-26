#pragma once
#include <iostream>
#include <iomanip>
#include "..\Screens\clsScreen.h"
#include "..\Models\clsBankClient.h"
#include "..\Utils\clsInputValidate.h"
#include "..\Utils\clsDate.h"
#include "fstream"
#include <vector>
using namespace std;

class clsTransfer
{
		string _Time;
		string _From;
		string _To;
		float _Amount;
		float _FromBalanceAfter;
		float _ToBalanceAfter;
		string _User;

	static string _ConvertTransferDateToLine(clsTransfer Data,string Seperator = "#//#") {
		string stringData = "";
		stringData += Data.GetTime() + Seperator;
		stringData += Data.GetFrom() + Seperator;
		stringData += Data.GetTo() + Seperator;
		stringData += to_string(Data.GetAmount()) + Seperator;
		stringData += to_string(Data.GetFromBalanceAfter()) + Seperator;
		stringData += to_string(Data.GetToBalanceAfter()) + Seperator;
		stringData += Data.GetUser();
		return stringData;
	}

	static clsTransfer _ConverStringTotransferData(string line , string Seperator = "#//#") {

			vector<string> vcData = clsString::Split(line, Seperator);
			clsTransfer LoginData;
			LoginData._Time = vcData[0];
			LoginData._From = vcData[1];
			LoginData._To = vcData[2];
			LoginData._Amount = stoi(vcData[3]);
			LoginData._FromBalanceAfter = stoi(vcData[4]);
			LoginData._ToBalanceAfter = stoi(vcData[5]);
			LoginData._User = vcData[6];

			return LoginData;
	}

	static void _SaveTransferDataToFile(clsTransfer Data) {
		fstream File;
		File.open("TransferLogs.txt", ios::out | ios::app);
		if (File.is_open()) {
			File << _ConvertTransferDateToLine(Data) << endl;
			File.close();
		};
	};
	
public :
	clsTransfer() {};
	clsTransfer(string From, string To, float Amount, float FromBalanceAfter, float ToBalanceAfter) {
		_Time = clsDate::GetSystemDateTimeString();
		_From = From;
		_To = To;
		_Amount = Amount;
		_FromBalanceAfter = FromBalanceAfter;
		_ToBalanceAfter = ToBalanceAfter;
		_User = CurrentUser.Username;
	};
	string GetTime() const {
		return _Time;
	}

	string GetFrom() const {
		return _From;
	}

	string GetTo() const {
		return _To;
	}

	float GetAmount() const {
		return _Amount;
	}

	float GetFromBalanceAfter() const {
		return _FromBalanceAfter;
	}

	float GetToBalanceAfter() const {
		return _ToBalanceAfter;
	}

	string GetUser() const {
		return _User;
	}
	static void PrintClientTransferInfo(clsBankClient& Client) {
		cout << "\n\n________________________________________\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc Number  : " << Client.AccountNumber();
		cout << "\nAcc Balance : " << Client.AccountBalance;
		cout << "\n\n________________________________________\n";
	}

	static bool Transfer(clsBankClient& From, clsBankClient& To) {
		cout << "\nEnter the Amount you want to transfer from Account " << From.AccountNumber()
			<< "\nto Acoount " << To.AccountNumber() << " : \n";
		float TransferAmount = clsInputValidate::ReadFloatNumberBetween(0.99, From.AccountBalance,
			"Amount Exceeds the available Balance, Enter another Amount ?");
		char Answer = 'n';
		cout << "\nAre you sure you want to preform this transaction ? y/n? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y') {
			From.Withdraw(TransferAmount);
			To.Deposit(TransferAmount);
			clsTransfer TransferData(From.AccountNumber(), To.AccountNumber(),TransferAmount, From.AccountBalance, To.AccountBalance);
			
			_SaveTransferDataToFile(TransferData);
			return true;
		}
		else {
			return false;
		}

	}


	static vector<clsTransfer> LoadtranferLogsFromFile() {
		vector<clsTransfer> Records;
		fstream File;
		File.open("TransferLogs.txt", ios::in);
		if (File.is_open()) {
			string Line;
			while (getline(File, Line)) {
				clsTransfer RecordObj = _ConverStringTotransferData(Line);
				Records.push_back(RecordObj);
			};
			File.close();
		};
		return Records;

	};
};

