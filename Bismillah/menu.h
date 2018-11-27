#pragma once

#include "transaksi.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

class menu : public transaksi
{
public:
	menu();
	~menu();
	int menuAwal();
	int mainMenu();
	int admin_menu();
};

