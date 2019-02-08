#ifndef TEILNEHMER_H
#define TEILNEHMER_H
#pragma once
#include<string>
#include "Mensch.h" 
#include "Datum.h"


class Teilnehmer : public Mensch {
	int kursnummer;
	Datum eintritt, austritt;
	bool certificat;
	int note;
	std::string traeger;
		
public:
	Teilnehmer();
	~Teilnehmer();
};

#endif