#ifndef DATUM_H
#define DATUM_H
#pragma once


#include "Objekt.h"
#include <string>


class Datum : public Objekt {
public:
	std::string toString() const override;

	Datum();
	~Datum();
};

#endif
