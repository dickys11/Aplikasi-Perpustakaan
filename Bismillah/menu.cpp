#include "pch.h"
#include "menu.h"


menu::menu()
{
}


menu::~menu()
{
}

int menu::menuAwal()
{
	int pilih;

	system("cls");
	cout << "===================================================" << endl;
	cout << "=              APLIKASI PERPUSTAKAAN              =" << endl;
	cout << "===================================================" << endl;
	cout << "= 1. Registrasi                                   =" << endl;
	cout << "= 2. Login                                        =" << endl;
	cout << "= 3. Keluar                                       =" << endl;
	cout << "===================================================" << endl;
	cout << "Masukkan Pilihan Anda [1..3] = "; cin >> pilih;
	system("cls");
	return pilih;
}

int menu::mainMenu()
{
	int pilih;

	system("cls");
	cout << "===================================================" << endl;
	cout << "=               Liblary Application               =" << endl;
	cout << "===================================================" << endl;
	cout << "= 1. Daftar Buku                                  =" << endl;
	cout << "= 2. Pinjam Buku                                  =" << endl;
	cout << "= 3. Buku Yang Sedang Dipinjam                    =" << endl;
	cout << "= 4. Pengembalian Buku                            =" << endl;
	cout << "= 5. Log Out                                      =" << endl;
	cout << "===================================================" << endl;
	cout << "Masukkan Pilihan Anda [1..5] = "; cin >> pilih;
	system("cls");
	return pilih;
}

int menu::admin_menu()
{
	int pilih;

	system("cls");
	cout << "==================================================" << endl;
	cout << "=                   Admin Menu                   =" << endl;
	cout << "==================================================" << endl;
	cout << "= 1. User List                                   =" << endl;
	cout << "= 2. Daftar Buku                                 =" << endl;
	cout << "= 3. Tambah Buku                                 =" << endl;
	cout << "= 4. Hapus Buku                                  =" << endl;
	cout << "= 5. Edit Buku                                   =" << endl;
	cout << "= 6. Log Out                                     =" << endl;
	cout << "==================================================" << endl;
	cout << "Masukkan Pilihan Anda [1..6] = "; cin >> pilih;
	system("cls");
	return pilih;
}
