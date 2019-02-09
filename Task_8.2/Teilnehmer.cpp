#include "pch.h"
#include "Teilnehmer.h"


std::string Teilnehmer::toString() const {
	return "Teilnehmer::toString() noch nicht implementiert";
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
