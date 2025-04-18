#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <vector>
#include <iomanip>

class clsLoginRegister : protected clsScreen
{
private:

	static void;
    static  vector <clsLoginRegister> _LoadLoginRegisterFromFile()
    {

        vector <clsLoginRegister> vUsers;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

public :
	static void ShowLoginRegister()
	{
		string Title = "\t  Login Register Screen";
		string SubTitle = "\t    (" + to_string(vUsers.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);
	}
};

