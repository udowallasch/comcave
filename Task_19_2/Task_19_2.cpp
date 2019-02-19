// Task_19_2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Produkt {
public:
	Produkt(string , int );
	Produkt(string , int , int preis);
	~Produkt();
	
	string getName() const;
	int getArtikelnummer() const;

	double getPreis() const;
	void setPreis(double);

	static int getMwst();
	static void setMwst(int);
	static int getAnzahl();

	string drucke() const;

private:
	string const name;
	int const artikelnummer;
	double preis = 0;
	static int mwst;
	static int anzahl;


};
int Produkt::anzahl = 0;
int Produkt::mwst = 17;

Produkt::Produkt(string name, int artikelnummer) 
	: name{ name }, artikelnummer{ artikelnummer } 
{ 
	anzahl++; 
	cout << "\n Artikel "<<name <<" hinzugefuegt.";

}

Produkt::Produkt(string name, int artikelnummer, int preis) 
	: Produkt(name, artikelnummer) 
{
	this->preis = preis;

}

Produkt::~Produkt() {
	anzahl--;  cout << "\n Artikel " << name << " entfernt.";
}

string  Produkt::getName() const {
	Produkt p("asa",5);
	return name;
	
}

int  Produkt::getArtikelnummer() const {
	return artikelnummer;
}

double  Produkt::getPreis() const {
	return preis;
}

void  Produkt::setPreis(double preis) {
	this->preis = preis;
}

int  Produkt::getMwst() {
	return mwst;
}

void  Produkt::setMwst(int mwst) {
	Produkt::mwst = mwst;
}

int  Produkt::getAnzahl() {
	Produkt p("dsdsd", 4);
	mwst = 1;
	return Produkt::anzahl;
}

string  Produkt::drucke() const {
	stringstream ss{ };
	ss	<< "\nProdukt: "	<< name \
		<< "\nArtikel: "	<< artikelnummer \
		<< "\nPreis: "		<< preis \
		<< "\nMwst: "		<< Produkt::mwst \
		<< "\nAnzahl: "		<< Produkt::anzahl;
	return ss.str();
}


int main() {
	vector<Produkt*> lager;
	lager.clear();
	lager.push_back(new Produkt("radio", 4711, 99.99));
	lager.push_back(new Produkt("Stecker", 4712, 5.55));
	lager.push_back(new Produkt("uhr", 4713, 77.55));

	for (Produkt* p : lager) cout << p->drucke() \
		<< "\n-----------------------";

	cout << "\n++++++++++++++\n";
	delete *(lager.begin() + 1);
	lager.erase(lager.begin() + 1);
	cout << "\n++++++++++++++\n";

	for (Produkt* p : lager) cout << p->drucke() \
		<< "\n-----------------------";
	cout << "\n++++++++++++++\n";

	(*lager.begin())->getName();
	cout << "\n++++++++++++++\n";


	Produkt::getAnzahl();
	cout << "\n++++++++++++++\n";


}