#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Socio
{
public:
//CONSTRUCTOR

	Socio();

//CONSUTORS
	void mostraSoci() const;
	bool esMenorSoci(Socio &soci,unsigned opcio) const;
	string getDni()const;
	bool ComparaQuo(char quo) const;
//MODIFICADORS
	void llegeixSociFitxer(ifstream &in_file);
	void llegeixSociTeclat();
	void Actualitza(Socio &socistr);
	void setQuota(char quo);
	string getPob()const;
private:
	string _DNI;
	string _nom;
	string _s_cog;
	string _cog;
	string _pob;
	char _quo;
};

