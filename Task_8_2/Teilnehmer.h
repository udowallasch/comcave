#ifndef TEILNEHMER_H
#define TEILNEHMER_H
#pragma once
#include<string>
#include "Mensch.h" 
#include "Datum.h"


class Teilnehmer : public Mensch {
	int const kursnummer;
	Datum   eintritt,  austritt;
	bool const certificat;
	int note;
	std::string const traeger;
		
public:
	int getKursnummer(int) const;
	Datum getEintritt();
	Datum getAustritt();
	bool getCertificat();
	void setNote(int);
	int getNote();
	std::string getTraeger();

	std::string toString() const override;

	Teilnehmer(Mensch, int, Datum, Datum, bool, std::string);
	~Teilnehmer();
};

#endif