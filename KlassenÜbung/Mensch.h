#ifndef MENSCH_H
#define MENSCH_H
#pragma once
#include "Datum.h"
#include<string>


class Mensch {

public:
	enum class gender {M,W,D};
	Mensch();
	~Mensch();
private:
	gender g;
	Datum  geburtstag;
	
};

#endif