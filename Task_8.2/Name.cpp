#include "pch.h"
#include "Name.h"

using std::string;


void Name::setVorname(string v) {
	vorname.clear();
	vorname.push_back(v);
};

void Name::setNachname(string n) {
	nachname.clear();
	nachname.push_back(n);
};
void Name::addVorname(string v) {
	vorname.push_back(v);
};

void Name::addNachname(string n) {
	nachname.push_back(n);
};

string Name::getVorname() const {
	string vn{};
	for ( auto v : vorname) {
		if (v == "-") {
			vn = vn + v;
		} else {
			if (vn == "") {
				vn = v;
			} else {
				vn = vn + " " + v;
			}		
		}		
	}
	return vn.c_str();
};

string Name::getNachname() const {
	string nn{};
	for (auto n : nachname) {
		nn += n;
	}
	return nn.c_str();
};

string Name::toString() const {
	return getVorname() + " " + getNachname();
};

Name::Name(string v, string n) : vorname{ v }, nachname{ n } {};
Name::Name() {};
Name::~Name() {}
