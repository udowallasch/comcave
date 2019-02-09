#include "pch.h"
#include "Adresse.h"

using std::stringstream;

std::string Adresse::getPlz() {
	return plz;
};

std::string Adresse::getLkz() {
	return lkz;
};

std::string Adresse::getGemeinde() {
	return gemeinde;
};

std::string Adresse::getStrasse() {
	return strasse;
};

std::string Adresse::getHausnummer() {
	return hausnummer;
};

Adresse::Adresse(std::string l, std::string p, std::string g, std::string s, std::string h )
	:
	lkz{l},
	plz{ p },
	gemeinde{g},
	strasse{ s },
	hausnummer{ h }
{};


std::string Adresse::toString() const {
	stringstream ss{};
	ss << strasse << " " << hausnummer << "\n" << lkz << "-" << plz<< " " << gemeinde;
	return ss.str();
};



Adresse::~Adresse() {}
