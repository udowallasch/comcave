#include "pch.h"
#include "Datum.h"

using std::string;
using std::to_string;

string Datum::toString() const {
	return to_string(t) + "." + to_string(m) + "." + to_string(j);
};

string Datum::toString(dotDat& d) const {
	d.dat = to_string(t) + "." + to_string(m) + "." + to_string(j);
	return d.dat;
};

string Datum::toString(slashDat& d) const {
	d.dat = to_string(t) + "/" + to_string(m) + "/" + to_string(j);
	return d.dat;

};

string Datum::toString(isoDat& d) const {
	d.dat = to_string(j) + "-" + to_string(m) + "-" + to_string(t);
	return d.dat;
};


Datum::Datum(int t, monat m, int j) : t{ t }, m{ m }, j{ j } {};



Datum::~Datum() {}
