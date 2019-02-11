#include "pch.h"
#include "Teilnehmer.h"
#include<sstream>

using std::stringstream;

std::string Teilnehmer::toString() const {
	stringstream ss{};
	ss  << "Teilnehmer: "	<< Mensch::toString() 
		<< "\nKursnummer: " << kursnummer
		<< "\nEintritt: "	<< eintritt.toString(dotDat{}) 
		<< "\nAustritt: "	<< austritt.toString(dotDat{})
		<< "\nZertifikat: " << (certificat ? "Ja" : "Nein")
		<< "\nNote: "		<< note;
	return ss.str();
};

Datum Teilnehmer::getEintritt() {
	return eintritt;
};

Datum Teilnehmer::getAustritt() {
	return austritt;
};


bool Teilnehmer::getCertificat() {
	return certificat;
};

void Teilnehmer::setNote(int n) {
	note = n;
};

int Teilnehmer::getNote() {
	return note;
};

std::string Teilnehmer::getTraeger() {
	return traeger;
};

int Teilnehmer::getKursnummer(int) const {
	return kursnummer;
};

Teilnehmer::Teilnehmer(Mensch m, int k, Datum e, Datum a, bool c, std::string t)
	:
	Mensch(m), kursnummer{ k }, eintritt{ e }, austritt{ a }, certificat{c}, traeger{t}
{};

Teilnehmer::~Teilnehmer() {}
