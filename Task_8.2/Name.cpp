#include "pch.h"
#include "Name.h"
#include<sstream>#
#include<iostream>
using std::string;
using std::stringstream;
using std::cout;

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
	stringstream ss{};
	for ( string v : vorname) {
		if (v == "-") {
			ss << v;
		} else {
			if (ss.str() == "") {
				ss << v;
			} else {
				ss << " "<< v;
			}		
		}		
	}
	return ss.str();
};

string Name::getNachname() const {
	stringstream ss{};
	for (auto n : nachname) {
		ss << n;
	}
	return ss.str();
};

string Name::toString() const {
	return getVorname() + " " + getNachname();
};

Name::Name(string v, string n) : vorname{ v }, nachname{ n } {};
Name::Name() {};
Name::~Name() {}
