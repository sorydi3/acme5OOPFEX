//#include "stdafx.h"
#include "Socio.h"

Socio::Socio()
{
	string _DNI = "";
		string _nom = "";
		string _cog = "";
		string _pob = "";
		char _quo;
}

void Socio::llegeixSociFitxer(ifstream &in_file) {
	
		in_file >> _DNI;
		in_file.ignore();
		getline(in_file, _nom);
		getline(in_file, _cog);
		getline(in_file, _pob);
		in_file >> _quo;

}
string Socio::getDni()const {
	return _DNI;
}
void Socio::Actualitza(Socio &socistr) {
	_nom = socistr._nom;
	_cog = socistr._cog;
	_pob = socistr._pob;
	_quo = socistr._quo;
}
bool Socio::ComparaQuo(char quo) const {
	return _quo == quo;
}
void Socio::setQuota(char quo) {
	_quo = quo;
}
string Socio::getPob()const {
	return _pob;
}
void Socio::llegeixSociTeclat() {
	cout << "DNI:" << endl;
	cin >>_DNI;
	cin.ignore();
	cout << "NOM:" << endl;
	getline(cin, _nom);
	cout << "COGNOM:" << endl;
	getline(cin,_cog);
	cout << "POBLACIO:" << endl;
	getline(cin ,_pob);
	cout << "QUOTA PAGADA (S/N):" << endl;
	cin >>_quo;
}
bool Socio :: esMenorSoci(Socio &soci, unsigned opcio) const{
	//Pre: criteri = (1,2)
	//Post: retorna cert si a és menor que b segons el criteri
	bool menor = true;
	string message;
	if (opcio == 1) {
		menor = _DNI < soci._DNI;
	}
	else if (opcio == 3) {
		menor = _cog <  soci._cog;
		if (_cog ==  soci._cog) {
			menor = _nom <  soci._nom;
			if ( _nom ==  soci._nom) {
				menor = _DNI <  soci._DNI;
			}
		 }
	}
	else {
		menor = _pob < soci._pob;
		if (_pob == soci._pob) {
			  menor = _cog < soci._cog;
			 if  (_cog == soci._cog) {
					 menor = _nom < soci._nom;
					 if (_nom == soci._nom) {
						 menor = _DNI < soci._DNI;
					 }
			}
		}

	}
	return menor;

}

void Socio::mostraSoci() const{
	cout << _DNI << " " << _nom << " " <<_cog << " "<< _pob << " " << _quo << endl;
}

