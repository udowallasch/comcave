#include "pch.h"
#include "Telefon.h"
#include<sstream>
using std::string;
using std::stringstream;

void Telefon::setMobil(string m){
	mobil = m;
};

void Telefon::setFestnetz(string f) {
	festnetz = f;
};

string Telefon::getMobil() const {
	return mobil;
};

string Telefon::getFestnetz() const {
	return festnetz;
};


string Telefon::toString() const {
	stringstream ss{};
	ss << "\n\tFestnetz: " << festnetz << "\n\tMobil: " << mobil;
	return ss.str();
}

Telefon::Telefon(string m, string f) : mobil{ m }, festnetz{ f } {};
Telefon::Telefon() {}


Telefon::~Telefon() {}
