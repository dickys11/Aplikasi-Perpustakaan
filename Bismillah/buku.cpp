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

	cout << "=====TAMBAH BUKU=====" << endl;
	cout << "Judul	: "; cin.ignore(numeric_limits<streamsize>::max(), '\n');  cin.getline(b.judul, 100);
	cout << "Kode	: "; cin >> b.kode;
	cout << "Jumlah	: "; cin >> b.jumlah;
	b.dipinjam = 0;
	b.tersedia = b.jumlah;

	fo.open("dataBuku.bin", ios::binary | ios::app);
	fo.write((char *)&b, sizeof(b));
	fo.close();
}

void buku::tampilkanBuku()
{
	ifstream fi;
	int i = 0;

	fi.open("dataBuku.bin", ios::binary);
	cout << "=====DAFTAR BUKU====" << endl;
	//cout << "NO\tJUDUL\t\t\t\tKODE\t\tJUMLAH\t\tDIPINJAM\t\tTERSEDIA" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << setw(5) << "NO" << setw(30) << "JUDUL" << setw(20) << "KODE" << setw(10) << "JUMLAH" << setw(14) << "DIPINJAM" << setw(14) << "TERSEDIA" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	while (fi.read((char *)&b, sizeof(b)))
	{
		//cout << i << ".\t" << b.judul << "\t\t" << b.kode << "\t" << b.jumlah << endl;
		cout << setw(5) << i+1 << setw(30) << b.judul << setw(20) << b.kode << setw(10) << b.jumlah << setw(14) << b.dipinjam << setw(14) << b.tersedia << endl;
		i++;
	}
	fi.close();
}


void buku::hapusBuku()
{
	ifstream fi;
	ofstream fo;
	int i = 1, cariNo;
	cout << "=====HAPUS DATA=====" << endl;
	cout << "Masukkan No Buku Yang Akan Dihapus: "; cin >> cariNo;
	fi.open("dataBuku.bin", ios::binary);
	fo.open("dataBukuBaru.bin", ios::binary | ios::app);
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
	remove("dataBuku.bin");
	rename("dataBukuBaru.bin", "dataBuku.bin");
	tampilkanBuku();
}

void buku::editBuku()
{
	ifstream fi;
	ofstream fo;
	int i = 1, cariNo;
	cout << "=====EDIT DATA=====" << endl;
	cout << "Masukkan No Buku Yang Akan Diedit: "; cin >> cariNo;
	fi.open("dataBuku.bin", ios::binary);
	fo.open("dataBukuBaru.bin", ios::binary | ios::app);
	while (fi.read((char *)&b, sizeof(b)))
	{
		if (i == cariNo)
		{
			cout << "Judul	:" << b.judul << endl;
			cout << "Kode	:"; cin >> b.kode;
			cout << "Jumlah	:"; cin >> b.jumlah;
		}
		i++;
		fo.write((char *)&b, sizeof(b));
	}
	fo.close();
	fi.close();
	remove("dataBuku.bin");
	rename("dataBukuBaru.bin", "dataBuku.bin");
	tampilkanBuku();
}