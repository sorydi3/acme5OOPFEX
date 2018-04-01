#pragma once
#include "Socio.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
class Manager
{
public:
	//CONSTRUCTOR
	Manager();
	//CONSULTORS
	  void llistaOrdenatSocis()const;//DONE
	  void llistaInpagats() const;//DONE
	  void mostraVector() const;//DONE
	  static void showMenu();
	  //MODIFICADOR
	  void altaSoci();//DONE
	  void quotaPagada();//DONE
	  void baixaSociInpagats();//DONE
	  void llegeixFitxer();//DONE
private:
	static const unsigned  MAX = 1000;
	Socio a_t[MAX];
	int a_n;
	void cercaDicotomica( string DNI, bool &is_there,int &pos_insersion)const;
	void incertaOrdenadament(int pos, Socio soci);
	void eliminaUnElementOrdenadament(int posisio);
	void insercioOrdenada(Socio soci, unsigned opcio);
	void pobAmbMesInpagament(string &ciutat, unsigned &impagat)const;

};

