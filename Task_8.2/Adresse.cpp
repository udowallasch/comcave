#include "pch.h"
#include "Adresse.h"

using std::stringstream;

std::string Adresse::getPlz() const {
	return plz;
};

std::string Adresse::getLkz() const {
	return lkz;
};

std::string Adresse::getGemeinde() const {
	return gemeinde;
};

std::string Adresse::getStrasse() const {
	return strasse;
};

std::string Adresse::getHausnummer() const {
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
