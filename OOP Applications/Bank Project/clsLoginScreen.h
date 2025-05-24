#pragma once
#include<iostream>
#include "clsBankUser.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
	
	
	static bool _Login() {
		bool LoginFaild = false;
		string username = "", password = "";
		short LoginFaildCounts = 0;

		do {
			if (LoginFaild) {
				LoginFaildCounts++;
				cout << "\nInvalid Username / Password, Try again \n";
				cout << "You have " << 3- LoginFaildCounts << " Trials to login.\n";
			};

			if (LoginFaildCounts == 3) {
				cout << "\nYour are Locked after 3 faild trails \n";
				return false;
			}

			cout << "\nEnter the username: \n";
			cin >> username;
			cout << "\nEnter the password : \n";
			cin >> password;
			CurrentUser = clsBankUser::Find(username, password);
			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);
			CurrentUser.SaveLoginDateToFile();
			clsMainScreen::ShowMainMenu();
			return true;
	}

public:
	static bool LoginScreen() {
		system("cls");
		_DrawScreenHeader("User Login Screen");
		return _Login();
	}

};

