#include "pch.h"
#include "Mensch.h"

using std::string;
using std::stringstream;


void Mensch::setAdresse(Adresse a) {
	adresse = a;
};

Adresse Mensch::getAdresse() const {
	return adresse;
};

void Mensch::setEmail(std::string e) {
	email = e;
};

std::string Mensch::getEmail() const {
	return email;
};

void Mensch::setTelefon(Telefon t) {
	tel = t;
};

Telefon Mensch::getTelefon() const {
	return tel;
};

std::string Mensch::toString() const {
	stringstream ss{};
	ss << name.toString << adresse.toString << "\nemail: " << email << "\nTelefon:" << tel.toString;
};


Mensch::Mensch(geschlecht g, Datum d) : g(g), geburtstag(d) {};
//hier wird noch nicht delegiert!
// weil  : g(g), geburtstag(d), adresse(a) { }; ist (wohl?) noch schneller als
//		 : Mensch(g, d)  {adresse(a)};
Mensch::Mensch(geschlecht g, Datum d, Adresse a) : g(g), geburtstag(d), adresse(a) { };
//...jetzt wird delegiert
Mensch::Mensch(geschlecht g, Datum d, Adresse a, Telefon t) : Mensch(g, d, a) { Telefon(t); };
Mensch::Mensch(geschlecht g, Datum d, Adresse a, std::string e) : Mensch(g, d, a) { email = e; };
Mensch::Mensch(geschlecht g, Datum d, Adresse a, std::string e, Telefon t) : Mensch(g, d, a, e) { Telefon(t); };

Mensch::~Mensch() {}
