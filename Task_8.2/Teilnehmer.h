#ifndef TEILNEHMER_H
#define TEILNEHMER_H
#pragma once
#include<string>
#include "Mensch.h" 
#include "Datum.h"


class Teilnehmer : public Mensch {
	int const kursnummer;
	Datum eintritt, austritt;
	bool certificat;
	int note;
	std::string traeger;
	std::string toString() const override;
		
public:
	Teilnehmer();
	~Teilnehmer();
};

#endif