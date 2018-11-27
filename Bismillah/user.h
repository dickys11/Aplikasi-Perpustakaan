#pragma once

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
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

protected:
	struct User
	{
		char username[20];
		char password[20];
	}u,uc;
	friend class buku;
};

