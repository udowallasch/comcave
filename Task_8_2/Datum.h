#ifndef DATUM_H
#define DATUM_H
#pragma once


#include "Objekt.h"
#include <string>

struct isoDat {
	//1981 - 01 - 19 iso 8601
};

struct dotDat {
	//19.01.1981
};

struct slashDat {
	//19 / 01 / 1981
};

class Datum : public Objekt {
public:
	enum monat {Jan=1,Feb,Mar,Apr,Mai,Jun,Jul,Aug,Sep,Okt,Nov,Dez};

	std::string toString() const override;

	std::string toString(dotDat) const;
	std::string toString(slashDat) const;
	std::string toString(isoDat) const;


	Datum(int,monat,int);
	~Datum();

private:
	// Datum ist Zeitstempel! -> keine setter.
	int const t;
	int const j;
	monat const m;

};

#endif
