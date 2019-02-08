#ifndef ADRESSE_H
#define ADRESSE_H
#pragma once
#include "Objekt.h"
#include<string>
#include<sstream>

class Adresse : public Objekt {
	std::string lkz;
	std::string plz;
	std::string gemeinde;
	std::string strasse;
	std::string hausnummer;

public:
	std::string getPlz();
	std::string getLkz();
	std::string getGemeinde();
	std::string getStrasse();
	std::string getHausnummer();
	Adresse(std::string, std::string, std::string, std::string, std::string);
	std::string toString() const override;
	~Adresse();
};

#endif
