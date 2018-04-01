// exerciciAcme1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include<string>
#include "Manager.h"
using namespace std;
void Handler(unsigned opcio, Manager &manager) {
	switch (opcio)
	{
	case 1:
		manager.altaSoci();
		break;
	case 2:
		manager.quotaPagada();
		break;
	case 3:
		manager.llistaInpagats();
		break;
	case 4:
		manager.baixaSociInpagats();
		break;
	case 5:
		manager.llistaOrdenatSocis();
		break;
	case 9:
		Manager::showMenu();
		break;
	default:
		cout << "NOT A VALID OPTION" << endl;
		break;
	}
}

int main()
{

	Manager manager;
	manager.llegeixFitxer();
	unsigned opcio;
	Manager::showMenu();
	cout << "OPCIO:" << endl;
	cin >> opcio;
	while (opcio != 0) {
		Handler(opcio, manager);
		cout << "OPCIO:" << endl;
		cin >> opcio;
	}
}



