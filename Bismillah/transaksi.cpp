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
	char kodePinjam[15],kodeCheck[15], namafile[20], folder[40];
	ifstream fi,fi1;
	ofstream fo;
	int f = 0;//0 Berarti kode yang dimasukin salah, 1 benar.

	cout << "=====PEMINJAMAN BUKU=====" << endl;
	cout << "Masukkan Kode Buku Yang Ingin Anda Pinjam: "; cin >> kodePinjam;
	fi.open("data\\dataBuku.bin", ios::binary);
	fo.open("data\\dataBukuBaru.bin", ios::binary | ios::app);

	strcpy_s(namafile, username);
	strcat_s(namafile, ".bin");

	_mkdir("data\\user_data");
	strcpy_s(folder, "data\\user_data\\");
	strcat_s(folder, namafile);
	//cout << folder << endl;

	while (fi.read((char *)&b, sizeof(b)))
	{
		if (strcmp(kodePinjam, b.kode) == 0)
		{
			//cout << "cek1" << endl;
			if (b.tersedia <= 0)
			{
				//cout << "cek2" << endl;
				f = 2;
			}
			else
			{
				//cout << "cek3" << endl;
				fi1.open(folder, ios::binary);
				if (fi1.is_open())
				{
					while (fi1.read((char*)kodeCheck, sizeof(kodeCheck)))
					{
						if (strcmp(kodeCheck, kodePinjam) == 0)
						{
							f = 3;
						}
						else
						{
							f = 1;
							b.dipinjam = b.dipinjam + 1;
							b.tersedia = b.jumlah - b.dipinjam;
						}
					}
				}
				else
				{
					f = 1;
					b.dipinjam = b.dipinjam + 1;
					b.tersedia = b.jumlah - b.dipinjam;
				}
				
				
			}
		}
		fo.write((char *)&b, sizeof(b));
	}
	fo.close();
	fi.close();
	remove("data\\dataBuku.bin");
	rename("data\\dataBukuBaru.bin", "data\\dataBuku.bin");

	if (f == 0)
	cout << "KODE SALAH" << endl;
	else if (f == 2)
	cout << "BUKU TIDAK TERSEDIA" << endl;
	else if (f == 3)
	cout << "ANDA TELAH MEMINJAM BUKU INI" << endl;
	else
	{
		//cout << "masuk pa eko" << endl;
		fo.open(folder, ios::binary | ios::app);
		fo.write((char *)&kodePinjam, sizeof(kodePinjam));
		fo.close();
	}
}

void transaksi::pengembalian(char username[20])
{
	char kodeCheck[15], kodeBalik[15], namafile[40], folder[40], namafileBaru[40], folderBaru[60];
	ifstream fi, fi1;
	ofstream fo,fo1;
	int f = 0, i = 1;

	strcpy_s(namafile, username);
	strcat_s(namafile, ".bin");

	//_mkdir("data\\user_data");
	strcpy_s(folder, "data\\user_data\\");
	strcat_s(folder, namafile);

	strcpy_s(namafileBaru, username);
	strcat_s(namafileBaru, "Baru.bin");

	//_mkdir("data\\user_data");
	strcpy_s(folderBaru, "data\\user_data\\");
	strcat_s(folderBaru, namafileBaru);

	cout << namafileBaru << endl;
	cout << folderBaru << endl;

	fi.open(folder, ios::binary);
	fi.seekg(0, ios::end);
	if (fi.is_open())
	{
		if (fi.tellg() != 0)
		{
			f = 1;
			//cout << "KODE" << endl;
		}
		else
		{
			f = 0;
		}
	}
	else
	{
		f = 0;
	}
	fi.close();

	fi.open(folder, ios::binary);
	fo.open(folderBaru, ios::binary | ios::app);
	if (f == 1)
	{
		cout << "=====PENGEMBALIAN BUKU=====" << endl;
		cout << "Masukkan kode buku yang akan dikembalikan: "; cin >> kodeBalik;
		while (fi.read((char *)&kodeCheck, sizeof(kodeCheck)))
		{
			fi1.open("data\\dataBuku.bin", ios::binary);
			fo1.open("data\\dataBukuBaru.bin", ios::binary | ios::app);
			if (strcmp(kodeBalik, kodeCheck) == 0)
			{

				while (fi1.read((char*)&b,sizeof(b)))
				{
					if (strcmp(b.kode, kodeBalik) == 0)
					{
						cout << b.dipinjam << endl;
						b.dipinjam = b.dipinjam - 1;
						cout << b.dipinjam << endl;
						b.tersedia = b.jumlah - b.dipinjam;
					}
					fo1.write((char*)&b, sizeof(b));
				}
				fi1.close();
				fo1.close();
				cout<<remove("data\\dataBuku.bin");
				cout<<rename("data\\dataBukuBaru.bin", "data\\dataBuku.bin");
			}
			else
			{
				cout << "masukkkkkkk" << endl;
				fo.write((char*)&kodeCheck, sizeof(kodeCheck));
			}
			cout << "tes" << endl;
			fi.open(folder, ios::binary);
			fo.open(folderBaru, ios::binary | ios::app);
			
		}
	}
	cout << remove(folder);
	cout << rename(folderBaru,folder);
	fi.close();
	fo.close();

 }


void transaksi::status(char username[20])
{
	char kodeCheck[15], namafile[20], folder[40];
	ifstream fi, fi1;
	ofstream fo;
	int f = 0,i=1;

	strcpy_s(namafile, username);
	strcat_s(namafile, ".bin");

	//_mkdir("data\\user_data");
	strcpy_s(folder, "data\\user_data\\");
	strcat_s(folder, namafile);
	cout << "=====BUKU YANG DIPINJAM=====" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << setw(5) << "NO" << setw(30) << "JUDUL" << setw(20) << "KODE" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	fi.open(folder,ios::binary);
	fi.seekg(0, ios::end);
	if (fi.is_open())
	{
		if (fi.tellg() != 0)
		{
			f = 1;
			//cout << "KODE" << endl;
		}
		else
		{
			cout << "ANDA BELUM MEMINJAM BUKU" << endl;
		}
	}
	else
	{
		cout << "ANDA BELUM MENIMJAM BUKU" << endl;
	}
	fi.close();
	
	fi.open(folder, ios::binary);
	if (f == 1)
	{
		fi1.open("data\\dataBuku.bin", ios::binary);
		while (fi.read((char *)&kodeCheck, sizeof(kodeCheck)))
		{
			cout << kodeCheck << endl;
			while (fi1.read((char*)&b,sizeof(b)))
			{
				cout << b.kode << endl;
				if (strcmp(b.kode, kodeCheck) == 0)
				{
					cout << "MASOK" << endl;
					cout << setw(5) << i << setw(30) << b.judul << setw(20) << b.kode << endl;
				}
			}
		}
	}
	fi.close();
	fi1.close();
}