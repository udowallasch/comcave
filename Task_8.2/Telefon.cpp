#include "pch.h"
#include "Telefon.h"

using std::string;

void Telefon::setMobil(string m){
	mobil = m;
};

void Telefon::setFestnetz(string f) {
	festnetz = f;
};

string Telefon::getMobil() {
	return mobil;
};

string Telefon::getFestnetz() {
	return festnetz;
};


string Telefon::toString() const {
	return "Telefon::toString() noch nicht implementiert";
}

Telefon::Telefon(string m, string f) : mobil{ m }, festnetz{ f } {};
Telefon::Telefon() {}


Telefon::~Telefon() {}
