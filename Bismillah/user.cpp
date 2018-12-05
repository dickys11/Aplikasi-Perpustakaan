#include "pch.h"
#include "user.h"
#include <conio.h>
#include <windows.h>

user::user()
{
}


user::~user()
{
}


void user::registrasi()
{
	cout << "========================================" << endl;
	cout << "=              REGISTRASI              =" << endl;
	cout << "========================================" << endl;
	cout << "Username: "; cin >> u.username;
	cout << "Password: "; getPass();
	
	system("cls");

	if (cekUser() == 1)
	{
		cout << "========================================" << endl;
		cout << "=        Username Tidak Tersedia       =" << endl;
		cout << "========================================" << endl;
	}
	else
	{
		cout << "========================================" << endl;
		cout << "=          Registrasi Sukses           =" << endl;
		cout << "========================================" << endl;
		tulisUser();
	}
}

int user::cekUser()
{
	int check=0;
	ifstream fi;

	fi.open("data\\dataUser.bin", ios::binary);
	
	while (fi.read((char *)&uc, sizeof(uc)))
	{
		if (strcmp(uc.username, u.username) == 0)
			check = 1;
		else check = 0;
		if (check == 1 || check == 2)
			break;
	}
	fi.close();
	
	return check;
}

void user::tulisUser()
{
	ofstream fo;
	
	fo.open("data\\dataUser.bin", ios::app | ios::binary);
	fo.write((char *)&u, sizeof(u));
	
	fo.close();
}

int user::cekLogin()
{
	int check=0;
	ifstream fi;

	if (strcmp("admin", u.username) == 0 && strcmp("admin", u.password) == 0)
		return 2;
	else
	{

		fi.open("data\\dataUser.bin", ios::binary);

		while (fi.read((char *)&uc, sizeof(uc)))
		{

		if (strcmp(uc.username, u.username) == 0 && strcmp(uc.password, u.password) == 0)
		check = 1;
		else check = 0;
		if (check == 1 || check == 2)
			break;
		}
		fi.close();
	}
	
	return check;
}

int user::login()
{
	cout << "========================================" << endl;
	cout << "=                LOGIN                 =" << endl;
	cout << "========================================" << endl;
	cout << "Username: "; cin >> u.username;
	cout << "Password: "; getPass();
	system("cls");
	if (cekLogin() == 1)
	{
		cout << "========================================" << endl;
		cout << "=             LOGIN SUKSES             =" << endl;
		cout << "========================================" << endl;
		
		system("pause");

		return 1; //login user sukses
	}
	else if (cekLogin() == 2)
	{
		cout << "========================================" << endl;
		cout << "=             LOGIN SUKSES             =" << endl;
		cout << "========================================" << endl;

		system("pause");
		
		return 2; //login admin sukses
	}
	else
	{
		cout << "========================================" << endl;
		cout << "=     USERNAME ATAU PASSWORD SALAH     =" << endl;
		cout << "========================================" << endl;
		
		system("pause");
		
		return 0; //login gagal
	}
}

void user::tampilkanUser()
{
	ifstream fi;
	int i = 1;

	fi.open("data\\dataUser.bin", ios::binary);

	cout << "=======================" << endl;
	cout << "=   DAFTAR PENGGUNA   =" << endl;
	cout << "=======================" << endl;
	cout << "=" << setw(4) << "NO" << setw(13) << "USER" << "    =" << endl;
	cout << "=======================" << endl;
	
	while (fi.read((char *)&u, sizeof(u)))
	{
		cout << "=" <<setw(4) <<i<<setw(13) << u.username << "    =" << endl;
		i++;
	}
	cout << "=======================" << endl;
	
	fi.close();
}

const char* user::passUser()
{
	return u.username;
}

void user::getPass()
{
#define MAX_LENGTH 16
	string password = "";
	char keypressed;

	//cout << "Enter password: ";

	for (;;) {
		keypressed = NULL; //clear
		keypressed = _getch(); //what key is pressed?

		/* KEY VALUES
		60-90 A-Z
		97-122 a-z
		48-57 0-9
		32 spacebar
		8 backspace
		13 enter */

		if (password.size() < MAX_LENGTH && ((keypressed >= 60 && keypressed <= 90) || (keypressed >= 97 && keypressed <= 122) || (keypressed >= 48 && keypressed <= 57) || keypressed == 32))
		{
			password += keypressed; //add char to password
			cout << "*";
		}
		else if (password.size() > 0 && keypressed == 8)
		{
			password.resize(password.size() - 1); //delete last character of password
			gotoxy(10, 4); //move cursor
			for (unsigned char l = 0; l < password.size(); l++) cout << "*"; //write all *
			cout << " "; //clear last character
			gotoxy(10 + password.size(), 4); //move cursor to last character
		}
		else if (keypressed == 13) break; //if ENTER is pressed
	}

	strcpy_s(u.password, password.c_str());
}

void user::gotoxy(short x, short y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}