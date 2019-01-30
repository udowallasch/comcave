#pragma once

#ifndef COUNTER_H
#define COUNTER_H

#include <array>
#include "Ziehung.h"

using  std::array;

//Ein staistisches Ergebnis der n Ziehungen 6 aus 49: 
//	max die (meist) gezogene Ziffer und 
//  number wie oft sie gesogen wurde 
struct t6 {
	size_t max; 
	size_t number;
};

// fasst das statistische Ergebnis zusammen: die meistgezogene Superzahl der n Ziehungen und die top6 der 6 aus 49
struct tops {
	size_t topSZ;
	array<t6, 6> top6;
};

class Counter
{
	//counter aaray für 6 aus 49
	array<size_t, 49> *z;

	//counter array für die Superzahl
	array<size_t, 10> *sz;

	void getTop6(tops&);
	size_t getTopSZ();

public:
	void store(wurf);
	tops getTops();
	void clear();
	Counter();
	~Counter();
};

#endif //COUNTER_H