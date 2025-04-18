#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		string Username, PinCode;

		bool LoginFaild = false;
		short FaildLoginCount = 0;
		do
		{
			if (LoginFaild)
			{
				FaildLoginCount++;

				cout << "\nInvlaid Username/Password!\n\n";
				cout << "\nYou have " << (3 - FaildLoginCount) << " Trial(s) to login.\n\n";
			}
			if (FaildLoginCount == 3)
			{
				cout << "\nYou are Looked after 3 faild Trials\n\n";
				return false;
			}
			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> PinCode;

			CurrentUser = clsUser::Find(Username, PinCode);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();

		return true;
	}
	
public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();
		
	}
};

