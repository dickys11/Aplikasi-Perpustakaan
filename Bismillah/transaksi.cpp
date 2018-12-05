#include "pch.h"
#include "transaksi.h"
#define _CRT_SECURE_NO_WARNINGS


transaksi::transaksi()
{
}


transaksi::~transaksi()
{
}

/*void transaksi::peminjaman(char username[20])
{

	char kodePinjam[15], kodeCheck[15], namafile[20], folder[40];
	ifstream fi, fi1;
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
	fi.close();
	fo.close();
	fo1.close();
	fi1.close();
	cout << remove(folder);
	cout << rename(folderBaru,folder);


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
	fo.close();
}
*/

void transaksi::peminjaman()
{
	int c = 0, b = 0;
	
	getFileName();
	
	if (cekFileBuku() == 1)
	{
		cout << "=============================================================================" << endl;
		cout << "=                              PEMINJAMAN BUKU                              =" << endl;
		cout << "=============================================================================" << endl;
		cout << "Masukkan Kode Buku Yang Ingin Anda Pinjam: "; cin >> TPinjam.kode;
		
		system("cls");
		c = kodeCheckUser();
		b = checkTersedia();
		//cout << "c: " <<c<< endl;
		//cout << "tersedia" << checkTersedia() << endl;
		//system("pause");

		if (kodeCheckData() == 1)
		{

			if (checkTersedia() == 1)
			{
				//cout << "tersedia" << endl;
				if (c == 1)
				{
					cout << "================================================" << endl;
					cout << "=         ANDA TELAH MEMINJAM BUKU INI         =" << endl;
					cout << "================================================" << endl;
				}
				else
				{
					cout << "================================================" << endl;
					cout << "=            BUKU BERHASIL DIPINJAM            =" << endl;
					cout << "=               MOHON KEMBALIKAN               =" << endl;
					cout << "=              SETELAH TUJUH HARI              =" << endl;
					cout << "================================================" << endl;

					getTime();
					updateDataBukuPeminjaman();
					updateDataUserPeminjaman();
				}
			}
			else
			{
				//cout << "cek" << endl;
				cout << "================================================" << endl;
				cout << "=             BUKU TIDAK TERSEDIA              =" << endl;
				cout << "================================================" << endl;
			}
		}
		else
		{
			//cout << "ceklagi" << endl;
			cout << "================================================" << endl;
			cout << "=             BUKU TIDAK TERSEDIA              =" << endl;
			cout << "================================================" << endl;
		}
	}
	else
	{
		cout << "================================================" << endl;
		cout << "=             BUKU TIDAK TERSEDIA              =" << endl;
		cout << "================================================" << endl;
	}
}

void transaksi::pengembalian()
{
	int c = 0,d;
	long denda;
	ifstream cekBuku;
	
	if (cekFileUser() == 1)
	{
		cekBuku.close();
		cout << "=============================================================================" << endl;
		cout << "=                             PENGEMBALIAN BUKU                             =" << endl;
		cout << "=============================================================================" << endl;
		cout << "Masukkan Kode Buku Yang Ingin Anda Kembalikan: "; cin >> TPinjam.kode;
		
		c = kodeCheckUser();
		system("cls");
		
		if (kodeCheckData() == 1)
		{
			if (c == 1)
			{
				getTime();
				d = cekWaktu();
				//cout << "d:" <<d;
				if (d > 7)
				{
					denda = d * 2000;
					cout << "==============================================" << endl;
					cout << "       ANDA TERLAMBAT MENGEMBALIKAN BUKU      " << endl;
					cout << "   ANDA DIKENAKAN DENDA SEBESAR RP"<<denda << endl;
					cout << "   SILAHKAN MEMBAYAR DENDA TERLEBIH DAHULU" << endl;
					cout << "==============================================" << endl;
					system("pause");
					cout << endl << endl << endl;
				}

				cout << "================================================" << endl;
				cout << "=          BUKU BERHASIL DIKEMBALIKAN          =" << endl;
				cout << "=                 TERIMA KASIH                 =" << endl;
				cout << "================================================" << endl;
				updateDataBukuPengembalian();
				updateDataUserPengembalian();
			}
			else
			{
				cout << "================================================" << endl;
				cout << "=             BUKU TIDAK TERSEDIA              =" << endl;
				cout << "================================================" << endl;
			}
		}
		else
		{
			cout << "================================================" << endl;
			cout << "=             BUKU TIDAK TERSEDIA              =" << endl;
			cout << "================================================" << endl;
		}
	}

}

void transaksi::status()
{
	ifstream bacaBukuUser, bacaBuku;
	getFileName();
	int i = 1;

	cout << "=====================================================================================" << endl;
	cout << "=                             BUKU YANG SEDANG DIPINJAM                             =" << endl;
	cout << "=====================================================================================" << endl;
	cout << "=" << setw(4) << "NO" << setw(30) << "JUDUL" << setw(20) << "KODE" << setw(25) << "TANGGAL PEMINJAMAN" << "    =" <<endl;
	cout << "=====================================================================================" << endl;

	bacaBukuUser.open(filePath, ios::binary);
	bacaBukuUser.seekg(0, ios::end);

	if (bacaBukuUser.is_open()) //cek file kebuka apa engga, kalo gak kebuka berarti belom ada
	{
		if (bacaBukuUser.tellg() != 0)
		{
			bacaBukuUser.seekg(0, ios::beg);
			bacaBukuUser.seekg(0, ios::beg);
			
			while (bacaBukuUser.read((char*)&TCheck, sizeof(TCheck)))
			{
				bacaBuku.open("data\\dataBuku.bin", ios::binary);
				while (bacaBuku.read((char*)&b, sizeof(b)))
				{
					if (strcmp(b.kode, TCheck.kode) == 0)
					{
						cout << "=" << setw(4) << i << setw(30) << b.judul << setw(20) << b.kode << setw(17)<<TCheck.day<<"/"<<TCheck.month<<"/"<<TCheck.year<< "    =" << endl;
						i++;
					}
				}
				bacaBuku.close();
			}
			cout << "=====================================================================================" << endl;
		}
		else
		{
			//filenya kosong, belum menjem
			cout << "=                             ANDA BELUM MEMINJAM BUKU                              =" << endl;
			cout << "=====================================================================================" << endl;
		}
	}
	else
	{
		//filenya belum ada, belum minjem
		cout << "=                             ANDA BELUM MEMINJAM BUKU                              =" << endl;
		cout << "=====================================================================================" << endl;
	}
	bacaBuku.close();
	bacaBukuUser.close();
}

void transaksi::getUsername(char u[20])
{
	strcpy_s(fileName, u);
	strcpy_s(fileNameBaru, u);
	//cout << "filenamebaru:" << fileNameBaru << endl;
}

void transaksi::getFileName()
{
	_mkdir("data\\user_data");

	strcat_s(fileName, ".bin");						//nambahin .bin di belakang username
	strcpy_s(filePath, "data\\user_data\\");		//copy "data\\user_data\\" ke "FileName"
	strcat_s(filePath, fileName);					//copy "UserName" ke belakang "FileName"

	strcat_s(fileNameBaru, "Baru.bin");
	strcpy_s(filePathBaru, "data\\user_data\\");
	strcat_s(filePathBaru, fileNameBaru);
}

int transaksi::kodeCheckBuku()						//ngecek kode yang di input dengan database buku
{
	ifstream bacaBuku;

	bacaBuku.open("data\\dataBuku.bin", ios::binary);		//buka file
	if (bacaBuku.is_open())									//cek file kebuka apa engga, kebuka true gak kebuka false
	{
		bacaBuku.seekg(0, ios::end);
		if (bacaBuku.tellg() == 0)							//cek file buku kosong apa engga, kosong true, gak kosong false
		{
			return 0;										//kodeInput =/= kodeFile
		}
		else
		{
			bacaBuku.seekg(0, ios::beg);
			while (bacaBuku.read((char*)&b, sizeof(b)))		//baca file masukin ke variable kodeFile
			{
				if (strcmp(b.kode, kodeInput) == 0)			//kodeFile sama dengan KodeInput return 1
				{
					return 1;								//kodeInput=KodeFile
				}
			}
		}
	}
	else
	{
		return 0;											//kodeInput =/= kodeFile 
	}
	return 2;
	bacaBuku.close();
}

int transaksi::kodeCheckData()
{
	ifstream bacaData;
	int a;

	bacaData.open("data\\dataBuku.bin");
	while (bacaData.read((char*)&b,sizeof(b)))
	{
		if (strcmp(b.kode, TPinjam.kode) == 0)
		{
			a = 1;
			return 1; //kodeInput ada di database
		}
		else
			a = 0;
	}
	return a;
}

int transaksi::kodeCheckUser()								//ngecek kodeInput dengan kodeUser(kode dari file user) 0 gak sama, 1 sama
{
	ifstream bacaBukuUser;
	int a = 0;

	bacaBukuUser.open(filePath, ios::binary);
	if (bacaBukuUser.is_open())
	{
		bacaBukuUser.seekg(0, ios::end);
		if (bacaBukuUser.tellg() == 0)
		{
			return 0;
		}
		else
		{
			bacaBukuUser.seekg(0, ios::beg);
			while (bacaBukuUser.read((char*)&TBalik,sizeof(TBalik)))
			{
				if (strcmp(TBalik.kode, TPinjam.kode) == 0)
				{
					return 1;
				}
				else
				{
					a = 0;
				}
			}
		}
	}
	else
	{
		return 0;
	}
	bacaBukuUser.close();
	return a;
}


void transaksi::updateDataBukuPeminjaman()
{
	ifstream bacaBuku;
	ofstream tulisBukuBaru;

	bacaBuku.open("data\\dataBuku.bin", ios::binary);
	tulisBukuBaru.open("data\\dataBukuBaru.bin", ios::binary | ios::app);
	while (bacaBuku.read((char*)&b, sizeof(b)))
	{
		if (strcmp(b.kode, TPinjam.kode) == 0)
		{
			b.dipinjam = b.dipinjam + 1;
			b.tersedia = b.jumlah - b.dipinjam;
		}
		tulisBukuBaru.write((char*)&b, sizeof(b));
	}
	bacaBuku.close();
	tulisBukuBaru.close();
	remove("data\\dataBuku.bin");
	rename("data\\dataBukuBaru.bin", "data\\dataBuku.bin");
	//system("pause");
}

void transaksi::updateDataUserPeminjaman()
{
	ofstream tulisDataUser;

	tulisDataUser.open(filePath, ios::binary | ios::app);
	//cout << fileName << endl;
	tulisDataUser.write((char*)&TPinjam, sizeof(TPinjam));
	tulisDataUser.close();
}

void transaksi::updateDataBukuPengembalian()
{
	ifstream bacaBuku;
	ofstream tulisBukuBaru;

	bacaBuku.open("data\\dataBuku.bin", ios::binary);
	tulisBukuBaru.open("data\\dataBukuBaru.bin", ios::binary | ios::app);
	while (bacaBuku.read((char*)&b, sizeof(b)))
	{
		if (strcmp(b.kode, TPinjam.kode) == 0)
		{
			b.dipinjam = b.dipinjam - 1;
			b.tersedia = b.jumlah - b.dipinjam;
		}
		tulisBukuBaru.write((char*)&b, sizeof(b));
	}
	bacaBuku.close();
	tulisBukuBaru.close();
	remove("data\\dataBuku.bin");
	rename("data\\dataBukuBaru.bin", "data\\dataBuku.bin");
	//system("pause");
}

void transaksi::updateDataUserPengembalian()
{
	ifstream bacaDataUser;
	ofstream tulisDataUserBaru;
	//cout << fileNameBaru << endl;
	bacaDataUser.open(filePath, ios::binary);
	tulisDataUserBaru.open(filePathBaru, ios::binary | ios::app);
	while (bacaDataUser.read((char*)&TCheck, sizeof(TCheck)))
	{
		if (strcmp(TPinjam.kode, TCheck.kode) != 0)
		{
			tulisDataUserBaru.write((char*)&TPinjam, sizeof(TPinjam));
		}
	}
	bacaDataUser.close();
	tulisDataUserBaru.close();
	//cout << filePath << endl;
	//cout << filePathBaru << endl;
	remove(filePath);
	rename(filePathBaru, filePath);
}

int transaksi::checkTersedia() //cek buku tersedia apa engga, tersedia = 1, engga = 0
{
	ifstream cekBuku;
	int a;

	cekBuku.open("data\\dataBuku.bin", ios::binary);
	while (cekBuku.read((char*)&b,sizeof(b)))
	{
		if (strcmp(b.kode, TPinjam.kode) == 0)
		{
			if (b.tersedia <= 0)
				a = 0;
		}
		else
		{
			a = 1;
		}
	}
	cekBuku.close();
	return a;
}

int transaksi::cekFileUser() //cek apakah file ada isinya apa engga
{
	ifstream cek;

	cek.open(filePath, ios::binary);
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

int transaksi::cekFileBuku() //cek apakah file ada isinya apa engga
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

void transaksi::getTime()
{
	time_t now = time(0);

	tm ltm;

	localtime_s(&ltm,&now);

	/*
	// print various components of tm structure.
	cout << "Year " << 1900 + ltm->tm_year << endl;
	cout << "Month: " << 1 + ltm->tm_mon << endl;
	cout << "Day: " << ltm->tm_mday << endl;
	cout << "Time: " << 1 + ltm->tm_hour << ":";
	cout << 1 + ltm->tm_min << ":";
	cout << 1 + ltm->tm_sec << endl;
	*/


	TPinjam.month = 1 + ltm.tm_mon;
	TPinjam.day = ltm.tm_mday;
	TPinjam.year = 1900 + ltm.tm_year;

	//cout << TPinjam.month << endl;
	//cout << TPinjam.day << endl;
	//cout << TPinjam.year << endl;

	//system("pause");
}

double transaksi::cekWaktu()
{
	ifstream baca;
	int dDay, dMonth, dYear;
	double difference;

	baca.open(filePath, ios::binary);
	while (baca.read((char*)&TCheck,sizeof(TCheck)))
	{
		cout << "waktu pinjam: " << TCheck.day << "/" << TCheck.month << "/" << TCheck.year << endl;
		cout <<"waktu balik: "<< TPinjam.day+8 << "/" << TPinjam.month << "/" << TPinjam.year << endl;
		cout << "buku yang dipinjam: " << TCheck.kode << endl;
		cout << "Buku yang dibalikin: " << TPinjam.kode << endl;
		if (strcmp(TCheck.kode, TPinjam.kode) == 0)
		{
			dDay = TPinjam.day - TCheck.day;
			dMonth = TPinjam.month - TCheck.month;
			dYear = TPinjam.year - TCheck.year;
			break;
		}
	}
	system("pause");
	system("cls");
	struct tm a = { 0,0,0,TPinjam.day,TPinjam.month,TPinjam.year - 1900 };
	struct tm b = { 0,0,0,TCheck.day,TCheck.month,TCheck.year - 1900 };

	time_t x = mktime(&a);
	time_t y = mktime(&b);
	char c[50], d[50];

	if (x != (time_t)(-1) && y != (time_t)(-1))
	{
		difference = difftime(x, y) / (60 * 60 * 24);
		cout << ctime_s(c, 50, &x);
		cout << ctime_s(d, 50, &y);
		cout << "difference = " << difference << " days" << endl;
	}
	return difference;
}