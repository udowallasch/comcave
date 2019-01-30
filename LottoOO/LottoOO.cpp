//LottoOO.cpp : Lottoprogramm mit statistischer Auswertung diesmal mit Objekten
// Udo Wallasch  

#include "pch.h"
#include <iostream>
#include "Counter.h"
#include "Ziehung.h"

using std::cout;

class Lotto {

Counter myCounter = Counter();
Ziehung myZiehung = Ziehung();

public:
	void run(int i) {
		//putzen
		myCounter.clear();
		//... und los geht's
		for (int w = 0; w < i; w++) {
			myCounter.store(myZiehung.ziehe());
		}
		//auswerten...
		tops t = myCounter.getTops();

		//...und anzeigen.
		cout << "\n\nF\x81r " << i << " Ziehungen ist die Top1 der Superzahlen " << t.topSZ;

		cout << "\nDie Top6 bei " << i << " Ziehungen sind (Zahl / Anzahl):";
		for (size_t i = 0; i < t.top6.size(); i++) {
			cout << "\n " << t.top6[i].max << " / " << t.top6[i].number;
		}
	};
};

int main()
{
	//bestimmt die Anzahl der Ziehungen
	array <int, 4> max{ 10,100,1000,5000 };
	//hier geht's los
	Lotto myLotto = Lotto();
	//lass laufen...
	for (int i : max)	myLotto.run(i);
	//und schon fertig!
}

