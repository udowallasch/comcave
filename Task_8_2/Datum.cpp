#include "pch.h"
#include "Datum.h"

using std::string;
using std::to_string;

string Datum::toString() const {
	return to_string(t) + "." + to_string(m) + "." + to_string(j);
};

string Datum::toString(dotDat d) const {
	return to_string(t) + "." + to_string(m) + "." + to_string(j);
};

string Datum::toString(slashDat) const {
	return to_string(t) + "/" + to_string(m) + "/" + to_string(j);

};

string Datum::toString(isoDat) const {
	return to_string(j) + "-" + to_string(m) + "-" + to_string(t);
};


Datum::Datum(int t, monat m, int j) : t{ t }, m{ m }, j{ j } {};



Datum::~Datum() {}
