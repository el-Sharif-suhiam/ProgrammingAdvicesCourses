#pragma once
#include <iostream>
#include <vector>
#include "string"
#include "clsPerson.h"
#include "clsString.h"
#include "Global.h"
#include "clsDate.h"
#include <fstream>

using namespace std;
class clsBankUser : public clsPerson
{
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode };
	enMode _Mode;
	string _Username;
	string _Password;
	int  _Permissions;
	bool   _MarkToDelete = false;

	static clsBankUser _ConvertLineToUserObject(string Line, string Seperator = "#//#") {
		vector<string> vcUser = clsString::Split(Line, Seperator);
		return clsBankUser(enMode::UpdateMode, vcUser[0], vcUser[1], vcUser[2], vcUser[3], vcUser[4],
			vcUser[5], stod(vcUser[6]));
	};

	string _ConvertUserObjectToLine(clsBankUser User, string Seperator = "#//#") {
		string record = "";
		record += User.FirstName + Seperator;
		record += User.LastName + Seperator;
		record += User.Email + Seperator;
		record += User.Phone + Seperator;
		record += User.Username + Seperator;
		record += User.Password + Seperator;
		record += to_string(User.Permissions);

		return record;
	};

	static clsBankUser _GetEmptyUserObject() {
		return clsBankUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	};


	static vector<clsBankUser> _LoadUsersDataFromFile() {
		vector<clsBankUser> Users;
		fstream File;
		File.open("Users.txt", ios::in);
		if (File.is_open()) {
			string Line;
			while (getline(File, Line)) {
				clsBankUser UserObj = _ConvertLineToUserObject(Line);
				Users.push_back(UserObj);
			};
			File.close();
		};
		return Users;

	};

	void _SaveUsersDateToFile(vector<clsBankUser> &vcUsers) {
		fstream File;
		File.open("Users.txt", ios::out);

		if (File.is_open()) {
			for (clsBankUser C : vcUsers) {
				if (C._MarkToDelete == false) {
					File << _ConvertUserObjectToLine(C) << endl;
				};
			}
			File.close();

		};
	};

	void _SaveLineToFile(string newLine) {
		fstream File;
		File.open("Users.txt", ios::app);
		if (File.is_open()) {
			File << newLine << endl;
			File.close();
		}
	}

	void _Update() {
		vector<clsBankUser> _vcUsers;
		_vcUsers = _LoadUsersDataFromFile();
		for (clsBankUser& C : _vcUsers) {
			if (C.GetUsername() == _Username) {
				C = *this;
				break;
			};
		};
		_SaveUsersDateToFile(_vcUsers);
	};

	void _AddNew(clsBankUser User) {
		_SaveLineToFile(_ConvertUserObjectToLine(User));
	}

	static string _ConvertLoginDateToLine(string Seperator = "#//#") {
		string record = "";
		record += clsDate::GetSystemDateTimeString() + Seperator;
		record += CurrentUser.Username + Seperator;
		record += CurrentUser.Password + Seperator;
		record += to_string(CurrentUser.Permissions);

		return record;
	};


public:
	clsBankUser(enMode mode, string FirstName, string LastName, string Email, string Phone,
		string Username, string Password, int Permission) :
		clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = mode;
		_Username = Username;
		_Password = Password;
		_Permissions = Permission;
	};
	
	enum enUserPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
	};

	void SetUsername(string username) {
		_Username = username;
	};
	string GetUsername() {
		return _Username;
	};

	__declspec(property(put = SetUsername, get = GetUsername)) string Username;


	void SetPassword(string Password) {
		_Password = Password;
	};

	string GetPassword() {
		return _Password;
	};

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;




	void SetPermissions(int Permissions) {
		_Permissions = Permissions;
	};

	int GetPermissions() {
		return _Permissions;
	};

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;


	static clsBankUser Find(string Username) {

		fstream File;

		File.open("Users.txt", ios::in);
		if (File.is_open()) {
			string Line;
			while (getline(File, Line)) {
				clsBankUser User = _ConvertLineToUserObject(Line);
				if (User.Username == Username) {
					File.close();
					return User;
				}
			};
			File.close();
			return _GetEmptyUserObject();
		}
	};

	static clsBankUser Find(string Username, string Password) {
		fstream File;

		File.open("Users.txt", ios::in);
		if (File.is_open()) {
			string Line;
			while (getline(File, Line)) {
				clsBankUser User = _ConvertLineToUserObject(Line);
				if (User._Username == Username && User._Password == Password) {
					File.close();
					return User;
				}
			};
			File.close();
			return _GetEmptyUserObject();
		}
	}

	bool IsEmpty() {
		return _Mode == enMode::EmptyMode;
	};
	static bool IsUserExist(string Username) {
		clsBankUser User = clsBankUser::Find(Username);
		return !User.IsEmpty();
	};

	enum enSaveResult { svFaildEmptyObject, svSuccessded, svFaildUsernameExist };

	enSaveResult Save() {
		switch (_Mode)
		{
		case clsBankUser::EmptyMode:
			return enSaveResult::svFaildEmptyObject;
		case clsBankUser::UpdateMode:
			_Update();
			return enSaveResult::svSuccessded;
			break;
		case clsBankUser::AddNewMode:
			if (clsBankUser::IsUserExist(_Username)) {
				return enSaveResult::svFaildUsernameExist;
			}
			else {
				_AddNew(*this);
				_Mode = UpdateMode;
				return svSuccessded;
			};
		};
	};

	static clsBankUser GetAddNewUserObject(string Username) {
		return clsBankUser(enMode::AddNewMode, "", "", "", "", Username, "", 0);
	};

	bool Delete() {
		vector<clsBankUser> vcUsers;
		vcUsers = _LoadUsersDataFromFile();
		for (clsBankUser& C : vcUsers) {
			if (C.GetUsername() == _Username) {
				C._MarkToDelete = true;
			}
		};

		_SaveUsersDateToFile(vcUsers);
		*this = _GetEmptyUserObject();
		return true;

	};

	static vector<clsBankUser> GetUsersList() {
		return _LoadUsersDataFromFile();
	};

	bool CheckUserPermission(enUserPermissions Permission) {
		if (this->Permissions == enUserPermissions::eAll) {
			return true;
		};

		if ((Permission & this->Permissions) == Permission) {
			return true;
		}
		else {
			return false;
		};
	};

	void SaveLoginDateToFile() {
		fstream File;
		File.open("Register.txt", ios::app | ios::out);

		if (File.is_open()) {

			File << _ConvertLoginDateToLine() << endl;
			File.close();

		};
	};
};