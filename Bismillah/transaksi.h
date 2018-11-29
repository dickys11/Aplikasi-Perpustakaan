#pragma once
#include "buku.h"
#include "user.h"
#include <direct.h>
class transaksi :
	public buku,
	public user
{
public:
	transaksi();
	~transaksi();
	void peminjaman(char username[20]);
	void pengembalian(char username[20]);
	void status(char username[20]);
};

