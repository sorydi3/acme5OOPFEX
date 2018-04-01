//#include "stdafx.h"
#include "Manager.h"

Manager::Manager()
{
	a_n = 0;
}
void Manager::showMenu() {
	cout << "1.  ALTA" << endl;
	cout << "2.  QUOTA PAGADA" << endl;
	cout << "3.  LLISTAT D'IMPAGATS" << endl;
	cout << "4.  BAIXA DE SOCIS IMPAGATS" << endl;
	cout << "5.  LLISTAT ORDENAT DE SOCIS" << endl;
	cout << "9.  MENU" << endl;
	cout << "0.  SORTIR" << endl;
}
void Manager::altaSoci() {
		//pre:cert
		//post:Ha incerit dintre del vector l'info de l'app en cas cas existeixi
		bool is_there = false;
		int pos_insersion;
		Socio socistr;
		socistr.llegeixSociTeclat();
		cercaDicotomica(socistr.getDni(), is_there, pos_insersion);
		if (is_there) {
			a_t[pos_insersion].Actualitza(socistr);
		}
		else { 
			incertaOrdenadament(pos_insersion, socistr); }
		cout << endl;
	}
void Manager::cercaDicotomica(string DNI, bool &is_there, int &pos_ele)const {
	//Pre: 0<=v.n<=MAX, v.t[0..v.n-1] ordenat creixentment
	//Post: retorna cert si x és un dels elements de v.t[0..v.n-1] i la posicio, fals
	//altrament
	int low = 0;
	int hight = a_n - 1;
	int pos = 0;
	//cout<<"---------------------> "<<DNI << endl;
	while (low <= hight && !is_there) {
		pos = (low + hight) / 2;
		///cout "<<<" << a_t[pos].getDni() << endl;
		if (a_t[pos].getDni() == DNI) { is_there = true;
		///cout << "trobat" << endl;
		}
		else if (a_t[pos].getDni() < DNI)low = pos + 1;
		else hight = pos - 1;
	}
	if (is_there)pos_ele = pos;
	else pos_ele = low;
}
void Manager::llegeixFitxer() {
	unsigned opcio_d = 1;
	cout << "FITXER D'ENTRADA:" << endl;
	string nom_fitxer;
	cin >> nom_fitxer;
	ifstream in_file(nom_fitxer.c_str());
	if (in_file.is_open()) {
		Socio soci;
		soci.llegeixSociFitxer(in_file);
		Socio s = soci;
			while (!in_file.eof()) {
				insercioOrdenada(s, opcio_d);
				soci.llegeixSociFitxer(in_file);
				s = soci;
			}
	}
	else {
		cout << "FITXER NOT OBERT CORRECTAMENT" << endl;
	}
}
void Manager::insercioOrdenada(Socio soci, unsigned opcio) {
	//Pre: 0<=v.n<MAX, v.t[0..n-1] ordenat creixentment
	//Post: x inserit ordenadament a v.t
	int i = a_n;
	while (i > 0 && soci.esMenorSoci(a_t[i - 1], opcio)) {
		a_t[i] =a_t[i - 1];
		i--;
	}
	a_t[i] = soci;
	a_n++;
 }

void Manager :: mostraVector() const {
	//imprimeix el elements d'intre del vector
	for (int i = 0; i < a_n; i++) {
		a_t[i].mostraSoci();
	}
}

void Manager::incertaOrdenadament(int pos, Socio soci) {
	//Pre: 0<=v.n<MAX, v.t[0..n-1] ordenat creixentment
	//Post: x inserit ordenadament a v.


	for (int i = a_n; i > pos; i--) {
		a_t[i] = a_t[i - 1];
	}
	a_t[pos] = soci;
	a_n++;
}

void Manager::quotaPagada() {
	string dni;
	bool is_there = false;
	int pos_element;
	cout << "DNI:" << endl;
	cin >> dni;
	cercaDicotomica(dni, is_there, pos_element);
	if (is_there) {
		char chrN = 'N';
		char chrS = 'S';
		if (a_t[pos_element].ComparaQuo(chrN))
			a_t[pos_element].setQuota(chrS);
		cout << endl;
	}
	else {
		cout << "SOCI INEXISTENT:   " << dni << endl;
		cout << endl;
	}


}

void Manager:: eliminaUnElementOrdenadament(int pos_element) {
	//Pre: 0<=pos<v.n<MAX
	//Post: v.t[pos_elemrnt] eliminat de v.t mantenint l’ordre dels altres
	//elements
	for (int i = pos_element; i < a_n - 1; i++)
		a_t[i] = a_t[i + 1];
	a_n--;
}

void Manager:: baixaSociInpagats() {
	//elimina els socis que no hagin pagat
	int index = 0;
	char chr = 'N';
	while (index < a_n) {

		if (a_t[index].ComparaQuo(chr)) {
			eliminaUnElementOrdenadament(index);
		}

		if (a_t[index].ComparaQuo(chr) && !(a_t[index + 1].ComparaQuo(chr))) {
			index = index;
		}
		else {
			index++;
		}
	}
	cout << endl;
}

void Manager::llistaInpagats() const {
	Manager manager;
	unsigned opcio = 3;
	for (int i = 0; i <a_n; i++) {
		if (a_t[i].ComparaQuo('N')) {
			manager.insercioOrdenada(a_t[i], opcio);
		}
	}
	if (manager.a_n > 0) {
		cout << "LLISTAT D'IMPAGATS" << endl;
		cout << "DNI" << "      " << "NOM" << "   " << "COGNOM"
			<< "   " << "POBLACIO" << "   " << "S/N" << endl;
		manager.mostraVector();
		cout << endl;
	}
	else {
		cout << "NO HI HA IMPAGAMENTS DE SOCIS" << endl;
		cout << endl;
	}

}

void  Manager::llistaOrdenatSocis()const {

	cout << "LLISTAT DE SOCIS" << endl;
	cout << "DNI" << "      " << "NOM" << "   " << "COGNOM"
		<< "   " << "POBLACIO" << "   " << "S/N" << endl;
	Manager manager;
	unsigned opcio = 4;
	for (int i = 0; i < a_n; i++) {
		manager.insercioOrdenada(a_t[i], opcio);
	}
	manager.mostraVector();
	cout << endl;
	unsigned impagat = 0;
	string ciutat;
	pobAmbMesInpagament(ciutat, impagat);
	cout << "POBLACIO AMB MES IMPAGAMENTS: " << ciutat << endl;
	cout << "IMPAGAMENTS: " << impagat << endl;
	cout << endl;
}

void Manager::pobAmbMesInpagament(string &poblacio, unsigned &impagat)const {
	//pre:
	//post:
	unsigned countador;
	string ciutat;
	for (int i = 0; i < a_n; i++) {
		countador = 0;
		ciutat = a_t[i].getPob();
		for (int j = 0; j < a_n; j++) {
			if (a_t[j].getPob() == ciutat && a_t[j].ComparaQuo('N')) {
				countador++;
			}

		}

		if (countador > impagat) {
			impagat = countador;
			poblacio = ciutat;
		}
		
		if (countador == impagat && countador != 0) {
			if (poblacio > ciutat) {
				poblacio = ciutat;
			}
			else {
				poblacio = poblacio;
			}

		}

	}


}