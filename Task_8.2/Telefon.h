#ifndef TELEFON_H
#define TELEFON_H
#pragma once

#include "Objekt.h"
#include<string>

class Telefon : public Objekt {
	std::string mobil;
	std::string festnetz;
public:
	void setMobil(std::string);
	void setFestnetz(std::string);
	std::string getMobil();
	std::string getFestnetz();

	std::string toString() const override;
	Telefon(std::string,std::string);
	Telefon();
	~Telefon();
};
#endif
