#include "pch.h"
#include "user.h"


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
	cout << "Password: "; cin >> u.password;
	
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

	fi.open("data\\dataUser.bin", ios::binary);
	
	while (fi.read((char *)&uc, sizeof(uc)))
	{
		if (strcmp("admin", u.username) == 0 && strcmp("admin", u.password) == 0)
			check = 2;
		else if (strcmp(uc.username, u.username) == 0 && strcmp(uc.password,u.password)==0)
			check = 1;
		else check = 0;
		if (check == 1 || check == 2)
			break;
	}
	fi.close();
	
	return check;
}

int user::login()
{
	cout << "========================================" << endl;
	cout << "=                LOGIN                 =" << endl;
	cout << "========================================" << endl;
	cout << "Username: "; cin >> u.username;
	cout << "Password: "; cin >> u.password;
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