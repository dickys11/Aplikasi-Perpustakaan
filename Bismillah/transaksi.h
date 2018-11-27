#pragma once
#include "buku.h"
#include "user.h"
class transaksi :
	public buku,
	public user
{
public:
	transaksi();
	~transaksi();
	void peminjaman(char username[20]);
	void pengembalian();
};

