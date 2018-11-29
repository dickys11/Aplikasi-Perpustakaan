#include "pch.h"
#include "buku.h"


buku::buku()
{
}


buku::~buku()
{
}

void buku::tambahBuku()
{
	ofstream fo;

	cout << "===============================================" << endl;
	cout << "=                 TAMBAH BUKU                 =" << endl;
	cout << "===============================================" << endl;
	cout << "Judul	: "; cin.ignore(numeric_limits<streamsize>::max(), '\n');  cin.getline(b.judul, 100);
	cout << "Kode	: "; cin >> b.kode;
	cout << "Jumlah	: "; cin >> b.jumlah;
	b.dipinjam = 0;
	b.tersedia = b.jumlah;
	if (b.jumlah != 0)
	{
		fo.open("data\\dataBuku.bin", ios::binary | ios::app);
		fo.write((char *)&b, sizeof(b));
		fo.close();
		system("cls");
		cout << "===============================================" << endl;
		cout << "=          BUKU BERHASIL DITAMBAHKAN          =" << endl;
		cout << "===============================================" << endl;
	}
	else
	{
		system("cls");
		cout << "===============================================" << endl;
		cout << "=                    ERROR                    =" << endl;
		cout << "=         JUMLAH BUKU TIDAK BOLEH NOL         =" << endl;
		cout << "===============================================" << endl;
	}
}

void buku::tampilkanBuku()
{
	ifstream fi;
	int i = 0;

	fi.open("data\\dataBuku.bin", ios::binary);
	cout << "===================================================================================================" << endl;
	cout << "=                                           DAFTAR BUKU                                           =" << endl;
	cout << "===================================================================================================" << endl;
	cout << "=" <<setw(4) << "NO" << setw(30) << "JUDUL" << setw(20) << "KODE" << setw(10) << "JUMLAH" << setw(14) << "DIPINJAM" << setw(14) << "TERSEDIA" << "     =" << endl;
	cout << "===================================================================================================" << endl;
	if (cekFile() != 0)
	{
		while (fi.read((char *)&b, sizeof(b)))
		{
			cout << "=" << setw(4) << i + 1 << setw(30) << b.judul << setw(20) << b.kode << setw(10) << b.jumlah << setw(14) << b.dipinjam << setw(14) << b.tersedia << "     =" << endl;
			i++;
		}
		fi.close();
		cout << "===================================================================================================" << endl;
	}
	else
	{
		cout << "=                                       BUKU TIDAK TERSEDIA                                       =" << endl;
		cout << "===================================================================================================" << endl;
	}
}


void buku::hapusBuku()
{
	ifstream fi,fi1;
	ofstream fo;
	int i = 1, cariNo,x=0;

	fi1.open("data\\dataBuku.bin", ios::binary);
	while (fi.read((char *)&b, sizeof(b)))
	{
		x++;
	}
	fi1.close();

	cout << "===================================================================================================" << endl;
	cout << "=                                           HAPUS DATA                                            =" << endl;
	cout << "===================================================================================================" << endl;
	cout << "Masukkan No Buku Yang Akan Dihapus: "; cin >> cariNo;

	if (cariNo > x)
	{
		fi.open("data\\dataBuku.bin", ios::binary);
		fo.open("data\\dataBukuBaru.bin", ios::binary | ios::app);

		while (fi.read((char *)&b, sizeof(b)))
		{
			if (i != cariNo)
			{
				fo.write((char *)&b, sizeof(b));
			}
			i++;
		}
		fo.close();
		fi.close();

		remove("data\\dataBuku.bin");
		rename("data\\dataBukuBaru.bin", "data\\dataBuku.bin");

		system("cls");

		cout << "=============================================" << endl;
		cout << "=           DATA BERHASIL DIHAPUS           =" << endl;
		cout << "=============================================" << endl;
	}
	system("cls");

	cout << "=============================================" << endl;
	cout << "=            DATA TIDAK TERSEDIA            =" << endl;
	cout << "=============================================" << endl;
}

void buku::editBuku()
{
	ifstream fi,fi1;
	ofstream fo;
	int i = 1, cariNo,x=0;

	fi1.open("data\\dataBuku.bin", ios::binary);
	while (fi.read((char*)&b,sizeof(b)))
	{
		x++;
	}
	fi1.close();

	cout << "===============================================" << endl;
	cout << "=                  EDIT DATA                  =" << endl;
	cout << "===============================================" << endl;
	cout << "Masukkan No Buku Yang Akan Diedit: "; cin >> cariNo;

	if (cariNo > x)
	{
		fi.open("data\\dataBuku.bin", ios::binary);
		fo.open("data\\dataBukuBaru.bin", ios::binary | ios::app);

		while (fi.read((char *)&b, sizeof(b)))
		{
			if (i == cariNo)
			{
				cout << "Judul		:" << b.judul << endl;
				cout << "Kode		:"; cin >> b.kode;
				cout << "Jumlah		:"; cin >> b.jumlah;
				cout << "Tersedia	:"; cin >> b.tersedia;
				cout << "Dipinjam	:"; cin >> b.dipinjam;
				if (b.jumlah != 0)
				{
					if (b.tersedia <= b.jumlah && b.tersedia >= 0)
					{
						if (b.dipinjam <= b.jumlah && b.dipinjam >= 0)
						{
							if ((b.dipinjam + b.tersedia) == b.jumlah)
							{
								goto berhasil;
							}
							else
							{
								cout << "JUMLAH BUKU YANG TERSEDIA DITAMBAH YANG DIPINJAM" << endl;
								cout << "HARUS SAMA DENGAN JUMLAH BUKU SELURUHNYA" << endl;
								goto error;
							}
						}
						else
						{
							cout << "BUKU YANG DIPINJAM HARUS LEBIH BESAR SAMA DENGAN NOL" << endl;
							cout << "DAN LEBIH KECIL SAMA DENGAN JUMLAH BUKU" << endl;
							goto error;
						}
					}
					else
					{
						cout << "BUKU YANG TERSEDIA HARUS LEBIH BESAR SAMA DENGAN NOL" << endl;
						cout << "DAN LEBIH KECIL SAMA DENGAN JUMLAH BUKU" << endl;
						goto error;
					}
				}
				else
				{
					cout << "JUMLAH BUKU HARUS LEBIH BESAR DARI NOL" << endl;
					goto error;
				}
			}
		berhasil:
			i++;
			fo.write((char *)&b, sizeof(b));
		}
		fo.close();
		fi.close();

		remove("data\\dataBuku.bin");
		rename("data\\dataBukuBaru.bin", "data\\dataBuku.bin");

		system("cls");

		cout << "=============================================" << endl;
		cout << "=           DATA BERHASIL DIEDIT            =" << endl;
		cout << "=============================================" << endl;
	error:
		cout << endl;
	}
	system("cls");
	cout << "=============================================" << endl;
	cout << "=           DATA TIDAK TERSEDIA             =" << endl;
	cout << "=============================================" << endl;
}

int buku::cekFile() //cek apakah file ada isinya apa engga
{
	ifstream cek;

	cek.open("data\\dataBuku.bin", ios::binary);
	if (cek.is_open())
	{
		cek.seekg(0, ios::end);
		if (cek.tellg() == 0)
		{
			//cout << "1" << endl;
			return 0; //file kosong
		}
		else
		{
			//cout << "2" << endl;
			return 1; //file ada isinya
		}
	}
	else
	{
		//cout << "3" << endl;
		return 0; //file gabisa dibuka
	}
}