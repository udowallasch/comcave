#include "pch.h"
#include "Counter.h"


//Liefert die 6 meistgezogenen Ziffern
void Counter::getTop6(tops &t) {
	for (size_t i = 0; i < t.top6.size(); i++) {
		size_t maxc = 0;
		size_t max = 0;
		for (size_t j = 0; j < 49; j++) {
			if (maxc < (*z)[j]) {
				maxc = (*z)[j];
				max = j;
			}
		}
		t.top6[i].max = max; // die gezogene Ziffer
		t.top6[i].number = maxc; // ... und wie oft sie gezogen wurde
		(*z)[max] = 0;
	}
}

//Finde meistgezogene Superzahl
size_t Counter::getTopSZ() {
	int top1c = 0;
	int top1 = 0;
	for (int i = 0; i < (*sz).size(); i++) {
		if (top1c < (*sz)[i]) {
			top1c = (*sz)[i];
			top1 = i;
		}
	}
	return top1 + 1;
}

tops Counter::getTops() {
	tops t;
	for (size_t i = 0; i < t.top6.size(); i++) { t.top6[i].max = 0; t.top6[i].number = 0; };
	t.topSZ = getTopSZ();
	getTop6(t);
	return t;
}

void Counter::store(wurf w) {
	for (size_t k = 0; k < w.w.size(); k++) {
		(*z)[w.w[k]-1]++;// Feldelemente k von w.w sind aus 1 bis 49
	}
	(*sz)[w.s - 1]++; //die Superzahl w.s geht von 1 bis 10
}

void Counter::clear() {
	for (int i = 0; i < (*z).size(); i++) { (*z)[i] = 0; }
	for (int i = 0; i < (*sz).size(); i++) { (*sz)[i] = 0; }
}

Counter::Counter() {
	z = new array<size_t, 49>;
	for (int i = 0; i < (*z).size(); i++) { (*z)[i] = 0; }
	sz = new array<size_t, 10>;
	for (int i = 0; i < (*sz).size(); i++) { (*sz)[i] = 0; }

}

Counter::~Counter() {
	delete(z);
	delete(sz);
}
