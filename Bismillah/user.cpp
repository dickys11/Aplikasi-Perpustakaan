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
	cout << "=====REGISTRASI=====" << endl;
	cout << "Masukkan Username: "; cin >> u.username;
	cout << "Masukkan Password: "; cin >> u.password;
	system("cls");
	if (cekUser() == 1)
		cout << "Username Tidak Tersedia" << endl;
	else
	{
		cout << "Registrasi Sukses" << endl;
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
	cout << "=====LOGIN=====" << endl;
	cout << "Masukkan Username: "; cin >> u.username;
	cout << "Masukkan Password: "; cin >> u.password;
	system("cls");
	if (cekLogin() == 1)
	{
		cout << "SUKSES" << endl;
		system("pause");
		return 1; //login sukses
	}
	else if (cekLogin() == 2)
	{
		cout << "SUKSES" << endl;
		system("pause");
		return 2; //login admin
	}
	else
	{
		cout << "USERNAME ATAU PASSWORD SALAH" << endl;
		system("pause");
		return 0;
	}
}

void user::tampilkanUser()
{
	ifstream fi;
	int i = 1;

	fi.open("data\\dataUser.bin", ios::binary);
	cout << "=====DAFTAR PENGGUNA====" << endl;
	while (fi.read((char *)&u, sizeof(u)))
	{
		cout << i << ". " << u.username << endl;
		i++;
	}
	fi.close();
}

const char* user::passUser()
{
	return u.username;
}