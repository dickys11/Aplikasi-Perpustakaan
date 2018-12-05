#pragma once

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "buku.h"

using namespace std;

class user
{
public:
	user();
	~user();
	void registrasi();
	int cekUser();
	int cekLogin();
	void tulisUser();
	int login();
	void tampilkanUser();
	virtual const char* passUser();
	void getPass();
	void gotoxy(short x, short y);

protected:
	struct User
	{
		char username[20];
		char password[20];
	}u,uc;
	friend class buku;
};

