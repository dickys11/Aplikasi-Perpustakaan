#include "pch.h"
#include "transaksi.h"


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
	int c = 0;
	getFileName();
	cout << "=====PEMINJAMAN BUKU=====" << endl;
	cout << "Masukkan Kode Buku Yang Ingin Anda Pinjam: "; cin >> kodeInput;
	c = kodeCheckUser();
	if (c == 1)
	{
		cout << "ANDA TELAH MEMINJAM BUKU INI" << endl;
	}
	else
	{
		cout << "cek" <<endl ;
		updateDataBukuPeminjaman();
		updateDataUserPeminjaman();
	}
}

void transaksi::pengembalian()
{
	int c = 0;
	cout << "=====PENGEMBALIAN BUKU" << endl;
	cout << "Masukkan Kode Buku Yang Ingin Anda Kembalikan: "; cin >> kodeInput;
	c = kodeCheckUser();
	if (c == 1)
	{
		cout << "cek"<<endl;
		updateDataBukuPengembalian();
		updateDataUserPengembalian();
	}
}

void transaksi::status()
{
	ifstream bacaBukuUser, bacaBuku;
	getFileName();
	int i = 1;

	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << setw(5) << "NO" << setw(30) << "JUDUL" << setw(20) << "KODE" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	bacaBukuUser.open(filePath, ios::binary);
	bacaBukuUser.seekg(0, ios::end);
	cout << filePath << endl;
	if (bacaBukuUser.is_open()) //cek file kebuka apa engga, kalo gak kebuka berarti belom ada
	{
		if (bacaBukuUser.tellg() != 0)
		{
			bacaBukuUser.seekg(0, ios::beg);
			bacaBuku.open("data\\dataBuku.bin", ios::binary);
			while (bacaBukuUser.read((char*)&kodeUser, sizeof(kodeUser)))
			{
				while (bacaBuku.read((char*)&b, sizeof(b)))
				{
					if (strcmp(b.kode, kodeUser) == 0)
					{
						cout << setw(5) << i << setw(30) << b.judul << setw(20) << b.kode << endl;
					}
				}
			}
		}
		else
		{
			cout << "ANDA BELUM MEMINJAM BUKU" << endl;
		}
	}
	else
	{
		cout << "ANDA BELUM MEMINJAM BUKU" << endl;
	}
	bacaBuku.close();
	bacaBukuUser.close();
}

void transaksi::getUsername(char u[20])
{
	strcpy_s(fileName, u);
	strcpy_s(fileNameBaru, u);
	cout << "filenamebaru:" << fileNameBaru << endl;
}



void transaksi::getFileName()
{
	strcat_s(fileName, ".bin"); //nambahin .bin di belakang username
	_mkdir("data\\user_data");
	strcpy_s(filePath, "data\\user_data\\"); //copy "data\\user_data\\" ke "FileName"
	strcat_s(filePath, fileName); //copy "UserName" ke belakang "FileName"

	strcat_s(fileNameBaru, "Baru.bin");
	cout <<"bin:"<<fileNameBaru << endl;
	strcpy_s(filePathBaru, "data\\user_data\\");
	cout << "lagi:" << filePathBaru << endl;
	strcat_s(filePathBaru, fileNameBaru);
	cout<<"jadinya: "<<filePathBaru<<endl;
}

int transaksi::kodeCheckBuku() //ngecek kode yang di input dengan database buku
{
	ifstream bacaBuku;
	
	bacaBuku.open("data\\dataBuku.bin", ios::binary); //buka file
	if (bacaBuku.is_open()) //cek file kebuka apa engga, kebuka true gak kebuka false
	{
		bacaBuku.seekg(0, ios::end);
		if (bacaBuku.tellg() == 0) //cek file buku kosong apa engga, kosong true, gak kosong false
		{
			return 0; //kodeInput =/= kodeFile
		}
		else
		{
			bacaBuku.seekg(0, ios::beg);
			while (bacaBuku.read((char*)&b, sizeof(b))) //baca file masukin ke variable kodeFile
			{
				if (strcmp(b.kode, kodeInput) == 0) //kodeFile sama dengan KodeInput return 1
				{
					return 1; //kodeInput=KodeFile
				}
			}
		}
	}
	else
	{
		return 0; //kodeInput =/= kodeFile 
	}
	return 2;
	bacaBuku.close();
}

int transaksi::kodeCheckUser() //ngecek kodeInput dengan kodeUser(kode dari file user)
{
	ifstream bacaBukuUser;


	bacaBukuUser.open(filePath, ios::binary); //buka file
	if (bacaBukuUser.is_open()) //cek file kebuka apa engga, kebuka true gak kebuka false
	{
		bacaBukuUser.seekg(0, ios::end);
		if (bacaBukuUser.tellg() == 0) //cek file buku kosong apa engga, kosong true, gak kosong false
		{
			cout << "cek1" << endl;
			return 0; //kodeInput =/= kodeFile
		}
		else
		{
			cout << "cek6" << endl;
			bacaBukuUser.seekg(0, ios::beg);
			while (bacaBukuUser.read((char*)&kodeUser, sizeof(kodeUser))) //baca file masukin ke variable kodeFile
			{
				cout << "cek8";
				if (strcmp(kodeUser, kodeInput) == 0) //kodeFile sama dengan KodeInput return 1
				{
					cout << "cek7";
					return 1; //kodeInput=KodeFile
				}
			}
		}
	}
	else
	{
		cout << "cek2" << endl;
		return 0; //kodeInput =/= kodeFile 
	}
	bacaBukuUser.close();
	return 2;
}


void transaksi::updateDataBukuPeminjaman()
{
	ifstream bacaBuku;
	ofstream tulisBukuBaru;

	bacaBuku.open("data\\dataBuku.bin", ios::binary);
	tulisBukuBaru.open("data\\dataBukuBaru.bin", ios::binary | ios::app);
	while (bacaBuku.read((char*)&b,sizeof(b)))
	{
		if (strcmp(b.kode, kodeInput) == 0)
		{
			b.dipinjam = b.dipinjam + 1;
			b.tersedia = b.jumlah - b.dipinjam;
		}
		tulisBukuBaru.write((char*)&b, sizeof(b));
	}
	bacaBuku.close();
	tulisBukuBaru.close();
	cout<<remove("data\\dataBuku.bin");
	cout<<rename("data\\dataBukuBaru.bin", "data\\dataBuku.bin");
	system("pause");
}

void transaksi::updateDataUserPeminjaman()
{
	ofstream tulisDataUser;

	tulisDataUser.open(filePath, ios::binary | ios::app);
	cout << fileName << endl;
	tulisDataUser.write((char*)&kodeInput, sizeof(kodeInput));
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
		if (strcmp(b.kode, kodeInput) == 0)
		{
			b.dipinjam = b.dipinjam - 1;
			b.tersedia = b.jumlah - b.dipinjam;
		}
		tulisBukuBaru.write((char*)&b, sizeof(b));
	}
	bacaBuku.close();
	tulisBukuBaru.close();
	cout << remove("data\\dataBuku.bin");
	cout << rename("data\\dataBukuBaru.bin", "data\\dataBuku.bin");
	system("pause");
}

void transaksi::updateDataUserPengembalian()
{
	ifstream bacaDataUser;
	ofstream tulisDataUserBaru;
	cout << fileNameBaru << endl;
	bacaDataUser.open(filePath, ios::binary);
	tulisDataUserBaru.open(filePathBaru, ios::binary | ios::app);
	while (bacaDataUser.read((char*)&kodeUser,sizeof(kodeUser)))
	{
		if (strcmp(kodeInput, kodeUser) != 0)
		{
			tulisDataUserBaru.write((char*)kodeUser, sizeof(kodeUser));
		}
	}
	bacaDataUser.close();
	tulisDataUserBaru.close();
	cout << remove(filePath);
	cout << rename(filePathBaru, filePath);
}