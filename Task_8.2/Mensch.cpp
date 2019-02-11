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
	ss << name.toString() <<"\n"<< adresse.toString() << "\nemail: " << email << "\nTelefon: " << tel.toString();
	return ss.str();
};

Name Mensch::getName() const {
	return name;
}

Datum Mensch::getGeburtstag() const {
	return geburtstag;
}


Mensch::Mensch(Name n, geschlecht g, Datum d) : name{n}, g(g), geburtstag(d) {};
//hier wird noch nicht delegiert!
// weil  : g(g), geburtstag(d), adresse(a) { }; ist (wohl?) noch schneller als
//		 : Mensch(g, d)  {adresse(a)};
Mensch::Mensch(Name n, geschlecht g, Datum d, Adresse a) : name{ n }, g(g), geburtstag(d), adresse(a) { };
//...jetzt wird delegiert
Mensch::Mensch(Name n, geschlecht g, Datum d, Adresse a, Telefon t) : Mensch(n, g, d, a) { tel = t; };
Mensch::Mensch(Name n, geschlecht g, Datum d, Adresse a, std::string e) : Mensch(n, g, d, a) { email = e; };
Mensch::Mensch(Name n, geschlecht g, Datum d, Adresse a, std::string e, Telefon t) : Mensch(n, g, d, a, e) { tel = t; };

Mensch::~Mensch() {}
