// Bismillah.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "menu.h"
#include <iostream>
#include <direct.h>

using namespace std;


int main()
{
	int condition;
	menu menuObj;
	char username[30];


	_mkdir("data");
START:
	condition = menuObj.menuAwal(); 
	switch (condition)
	{
	case 1:
		//REGISTRASI
		menuObj.registrasi();
		system("pause");
		goto START;
		break;
	case 2:											
		//LOGIN
		condition = menuObj.login();

		if (condition == 1)
		{
			//LOGIN USER SUKSES (MAIN MENu)
			MENU_USER:
			condition = menuObj.mainMenu();
			if (condition == 1)
			{
				//DAFTAR BUKU
				menuObj.tampilkanBuku();
				system("pause");
				goto MENU_USER;
			}
			else if (condition == 2)
			{
				//PINJAM BUKU
				menuObj.tampilkanBuku();
				cout << endl;
				cout << endl;
				strcpy_s(username, menuObj.passUser());
				menuObj.getUsername(username);
				menuObj.peminjaman();
				system("pause");
				goto MENU_USER;
			}
			else if (condition == 3)
			{
				//STATUS BUKU
				strcpy_s(username, menuObj.passUser());
				menuObj.getUsername(username);
				menuObj.status();
				system("pause");
				goto MENU_USER;
			}
			else if (condition == 4)
			{
				//PENGEMBALIAN BUKU
				strcpy_s(username, menuObj.passUser());
				menuObj.getUsername(username);
				menuObj.status();
				cout << endl;
				cout << endl;
				menuObj.pengembalian();
				system("pause");
				goto MENU_USER;
			}
			else if (condition == 5)				
				//LOGOUT (KEMBALI KE MENU AWAL)
				goto START;
			else
			{
				//ERROR KEMBALI KE MENU SEBELUMNYA
				//Mungkin
				cout << "ERROR, PILIHAN TIDAK TERSEDIA" << endl;
				system("pause");
				goto START;
			}
		}
		else if (condition == 2)
		{
			//LOGIN ADMIN SUKSES (MENU ADMIN)
			MENU_ADMIN:
			condition = menuObj.admin_menu();
			if (condition == 1)
			{
				//MENAMPILKAN DAFTAR PENGGUNA
				menuObj.tampilkanUser();
				system("pause");
				goto MENU_ADMIN;
			}
			else if (condition == 2)
			{
				//MENAMPILKAN DAFTAR BUKU
				menuObj.tampilkanBuku();
				system("pause");
				goto MENU_ADMIN;
			}
			else if (condition == 3)
			{
				//MENAMBAHKAN DATA BUKU KE FILE
				menuObj.tambahBuku();
				system("pause");
				goto MENU_ADMIN;
			}
			else if (condition == 4)
			{
				//MENGHAPUS DATA BUKU
				menuObj.tampilkanBuku();
				cout << endl;
				cout << endl;
				menuObj.hapusBuku();
				system("pause");
				goto MENU_ADMIN;
			}
			else if(condition == 5)
			{
				//MENGEDIT DATA BUKU
				menuObj.tampilkanBuku();
				cout << endl;
				cout << endl;
				menuObj.editBuku();
				system("pause");
				goto MENU_ADMIN;
			}
			else if (condition == 6)
			{
				//LOGOUT (KEMBALI KE MENU AWAL)
				goto START;
			}
			else
			{
				//mungkin
				cout << "ERROR, PILIHAN TIDAK TERSEDIA" << endl;
				system("pause");
				goto MENU_ADMIN;
			}
		}
		else if (condition == 0)
		{
			//LOGIN GAGAL (KEMBALI KE MENU AWAL)
			goto START;
		}
		else
		{
			cout << "ERROR, PILIHAN TIDAK TERSEDIA" << endl;
			system("pause");
			goto START;
		}
		break;
	case 3: 
		//KElUAR
		exit(42);
	default:
		//PILIHAN TIDAK TERSEDIA;
		cout << "ERROR, PILIHAN TIDAK TERSEDIA" << endl;
		system("pause");
		goto START;
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
