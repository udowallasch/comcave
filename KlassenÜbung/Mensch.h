#ifndef MENSCH_H
#define MENSCH_H
#pragma once

#include "Objekt.h"
#include "Datum.h"
#include "Adresse.h"
#include "Telefon.h"
#include "Name.h"
#include<string>
#include<sstream>


class Mensch : public Objekt {

public:
	enum class geschlecht {M,W,D};

	void setAdresse(Adresse);
	Adresse getAdresse() const;
	void setEmail(std::string);
	std::string getEmail() const;
	void setTelefon(Telefon);
	Telefon getTelefon() const;
	std::string toString() const override;

	Mensch(geschlecht, Datum);
	Mensch(geschlecht, Datum, Adresse);
	Mensch(geschlecht, Datum, Adresse, Telefon);
	Mensch(geschlecht, Datum, Adresse, std::string);
	Mensch(geschlecht, Datum, Adresse, std::string, Telefon );
	~Mensch();

private:

	geschlecht const g;
	Datum  const geburtstag;
	Name name;
	Adresse adresse;
	std::string email;
	Telefon tel;
		
};

#endif