#pragma once

#ifndef ZIEHUNG_H
#define ZIEHUNG_H

#include <array>
using  std::array;

struct wurf {
	array<size_t, 6> w; //die 6 gezogenen Zahlen 
	size_t s;			//die Superzahl
};

class Ziehung
{
	public:
		wurf ziehe(); // eine Ziehung 6 aus 49 ohne Wiederholung plus Superzahl aus 1 bis 10.

		Ziehung();
		~Ziehung();
};

#endif //ZIEHUNG_H
