#include "pch.h"
#include "transaksi.h"


transaksi::transaksi()
{
}


transaksi::~transaksi()
{
}

void transaksi::peminjaman(char username[20])
{
	char kodePinjam[15],namafile[20];
	ifstream fi;
	ofstream fo;
	int f = 0;//0 Berarti kode yang dimasukin salah, 1 benar.

	cout << "=====PEMINJAMAN BUKU=====" << endl;
	cout << "Masukkan Kode Buku Yang Ingin Anda Pinjam: "; cin >> kodePinjam;
	fi.open("dataBuku.bin", ios::binary);
	fo.open("dataBukuBaru.bin", ios::binary | ios::app);
	while (fi.read((char *)&b, sizeof(b)))
	{
		if (strcmp(kodePinjam, b.kode) == 0)
		{
			b.dipinjam = b.dipinjam + 1;
			b.tersedia = b.jumlah - b.dipinjam;
			f = 1;
		}
		fo.write((char *)&b, sizeof(b));
	}
	fo.close();
	fi.close();
	remove("dataBuku.bin");
	rename("dataBukuBaru.bin", "dataBuku.bin");

	if (f == 0)
		cout << "KODE SALAH" << endl;

	strcpy_s(namafile, username);
	strcat_s(namafile, ".bin");
	fo.open(namafile, ios::binary|ios::app);
	fo.write((char *)&kodePinjam, sizeof(kodePinjam));
	fo.close();
}

void transaksi::pengembalian()
{

}