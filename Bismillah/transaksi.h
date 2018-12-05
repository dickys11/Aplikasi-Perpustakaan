#pragma once
#include "buku.h"
#include "user.h"
#include <direct.h>
#include <time.h>
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
	int kodeCheckData();
	int kodeCheckUser();
	void updateDataBukuPeminjaman();
	void updateDataUserPeminjaman();
	void updateDataBukuPengembalian();
	void updateDataUserPengembalian();
	int checkTersedia();
	int cekFileUser();
	int cekFileBuku();
	void getTime();
	double cekWaktu();
protected:
	char UserName[20];
	char fileName[100];
	char fileNameBaru[100];
	char filePath[100];
	char filePathBaru[100];
	char kodeInput[15];
	char kodeUser[15];
	struct trans
	{
		char kode[20];
		int day;
		int month;
		int year;
	}TPinjam, TBalik, TCheck;
};

