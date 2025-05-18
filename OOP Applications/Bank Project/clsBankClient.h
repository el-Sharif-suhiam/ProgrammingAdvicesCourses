#pragma once
#include <iostream>
#include <vector>
#include "string"
#include "clsPerson.h"
#include "clsString.h"
#include <fstream>
using namespace std;
class clsBankClient : public clsPerson
{
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float	   _AccountBalance;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#") {
		vector<string> vcClient = clsString::Split(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, vcClient[0], vcClient[1], vcClient[2], vcClient[3], vcClient[4],
			vcClient[5], stod(vcClient[6]));
	};

	string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#") {
		string record = "";
		record += Client.FirstName + Seperator;
		record += Client.LastName + Seperator;
		record += Client.Email + Seperator;
		record += Client.Phone + Seperator;
		record += Client.AccountNumber() + Seperator;
		record += Client.PinCode + Seperator;
		record += to_string(Client.AccountBalance);

		return record;
	};

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	};


	vector<clsBankClient> _LoadClientsDataFromFile() {
		vector<clsBankClient> Clients;
		fstream File;
		File.open("Clients.txt", ios::in);
		if (File.is_open()) {
			string Line;
			while (getline(File, Line)) {
				clsBankClient ClientObj = _ConvertLineToClientObject(Line);
				Clients.push_back(ClientObj);
			};
			File.close();
		};
		return Clients;

	};

	void _SaveClientsDateToFile(vector<clsBankClient> vcClients) {
		fstream File;
		File.open("Clients.txt", ios::out);

		if (File.is_open()) {
			for (clsBankClient &C : vcClients) {
				File << _ConvertClientObjectToLine(C) << endl;
			}
			File.close();

		};
	};

	void _SaveLineToFile(string newLine) {
		fstream File;
		File.open("Clients.txt", ios::app );
		if (File.is_open()) {
			File << newLine << endl;
			File.close();
		}
	}

	void _Update() {
		vector<clsBankClient> _vcClients;
		_vcClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : _vcClients) {
			if (C.AccountNumber() == AccountNumber()) {
				C = *this;
				break;
			};
		};
		_SaveClientsDateToFile(_vcClients);
	};

	void _AddNew(clsBankClient Client) {
		_SaveLineToFile(_ConvertClientObjectToLine(Client));
	}
public:
	clsBankClient(enMode mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	};


	string AccountNumber() {
		return _AccountNumber;
	};



	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	};

	string GetPinCode() {
		return _PinCode;
	};

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;




	void SetAccountBalance(float accBal) {
		_AccountBalance = accBal;
	};

	float GetAccountBalance() {
		return _AccountBalance;
	};

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void Print() {
		cout << "\nClient Card : \n\n";
		cout << "--------------------------------------------\n\n";
		cout << "First Name      : " << FirstName << '\n';
		cout << "Last Name       : " << LastName << '\n';
		cout << "Full Name       : " << FullName() << '\n';
		cout << "Email           : " << Email << '\n';
		cout << "Phone Number    : " << Phone << '\n';
		cout << "Account Number  : " << _AccountNumber << '\n';
		cout << "Password        : " << _PinCode << '\n';
		cout << "Account Balance : " << _AccountBalance << '\n';
		cout << "--------------------------------------------\n\n";

	};

	static clsBankClient Find(string AccNum) {

		fstream File;

		File.open("Clients.txt", ios::in);
		if (File.is_open()) {
			string Line;
			while (getline(File, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccNum) {
					File.close();
					return Client;
				}
			};
			File.close();
			return _GetEmptyClientObject();
		}
	};

	static clsBankClient Find(string AccNum, string PinCode) {
		fstream File;

		File.open("Clients.txt", ios::in);
		if (File.is_open()) {
			string Line;
			while (getline(File, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccNum && Client._PinCode == PinCode) {
					File.close();
					return Client;
				}
			};
			File.close();
			return _GetEmptyClientObject();
		}
	}

	bool IsEmpty() {
		return _Mode == enMode::EmptyMode;
	};
	static bool IsClientExist(string AccNum) {
		clsBankClient Client = clsBankClient::Find(AccNum);
		return !Client.IsEmpty();
	};

	enum enSaveResult { svFaildEmptyObject, svSuccessded, svFaildAccountNumberExist };

	enSaveResult Save() {
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
			return enSaveResult::svFaildEmptyObject;
		case clsBankClient::UpdateMode:
			_Update();
			return enSaveResult::svSuccessded;
			break;
		case clsBankClient::AddNewMode:
			if (clsBankClient::IsClientExist(_AccountNumber)) {
				return enSaveResult::svFaildAccountNumberExist;
			}
			else {
				_AddNew(*this);
				_Mode = UpdateMode;
				return svSuccessded;
			};
		};
	};

	static clsBankClient GetAddNewClientObject(string AccNum) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccNum, "", 0);
	};

};