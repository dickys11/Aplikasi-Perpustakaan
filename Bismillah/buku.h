#pragma once

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <ios>
#include <limits>
#include <iomanip>
#include "user.h"

using namespace std;

class buku
{
public:
	buku();
	~buku();
	void tambahBuku();
	void tampilkanBuku();
	void editBuku();
	void hapusBuku();

protected:
	struct Buku
	{
		char judul[100];
		char kode[15];
		int jumlah,dipinjam,tersedia;
	}b,bk[10];
	friend class user;
};

