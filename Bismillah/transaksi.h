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
	void peminjaman();
	void pengembalian();
	void status();
	void getUsername(char u[20]);
	void getFileName();
	int kodeCheckBuku();
	int kodeCheckUser();
	void updateDataBukuPeminjaman();
	void updateDataUserPeminjaman();
	void updateDataBukuPengembalian();
	void updateDataUserPengembalian();
	int checkTersedia();
protected:
	char UserName[20];
	char fileName[100];
	char fileNameBaru[100];
	char filePath[100];
	char filePathBaru[100];
	char kodeInput[15];
	char kodeUser[15];
};

