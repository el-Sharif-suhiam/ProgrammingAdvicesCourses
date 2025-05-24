// Bank Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsLoginScreen.h"
int main()
{
	while (true) {
		if (!clsLoginScreen::LoginScreen()) {
			break;
		};

	};
	system("pause > 0"); 
	
	return 0;

}
