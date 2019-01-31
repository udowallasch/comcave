//Udo Wallasch
#include "pch.h"
#include <ctime>
#include "Ziehung.h"

//liefert 6 Zufallszahen aus 1 bis 49 ohne Wiederholung
array<size_t, 6> ziehung() { 
	array<size_t, 6> z{ 0,0,0,0,0,0 };
	bool ready = false;
	for (int i = 0; i < 6; i++) {
		int k = 0;
		ready = false;
		while (!ready) {
			k = (rand() % 49 + 1);
			ready = true;
			for (int l = 0; l < 6; l++) {
				if (z[l] == k) {
					// bereits gezogen, also nächster Versuch...
					ready = false;
					break;
				}
			}
		}
		z[i] = k;
	}
	return z;
}

//liefert eine Zufallszahl aus 1 bis 10
size_t superzahl() {
	return (rand() % 10 + 1);
}

//die Schnittstelle der Klasse Ziehung.
//liefert eine komplette Ziehung (einen 'wurf') 
//bestehend aus 6 Zufallszahlen o.Wdh. und einer Superzahl
wurf Ziehung::ziehe() {
	wurf w;
	w.w = ziehung();
	w.s = superzahl();
	return w;
}

Ziehung::Ziehung() {
	srand(time(0));
}


Ziehung::~Ziehung()	{
}
