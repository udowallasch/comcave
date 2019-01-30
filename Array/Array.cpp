// Array.cpp : Lottoprogramm mit statistischer Auswertung
// Udo Wallasch 

#include "pch.h"
#include <iostream>
#include <array>
#include <string>
#include <stdlib.h>    
#include <ctime>     

using namespace std;

int superzahl();
array<int, 6> ziehung();
array<int, 6> getTop6(array<int, 49>);

//Ergebnis einer Ziehung
array<int, 6> wurf{};

//kumuliert die Ergebnisse der Ziehungen 6 aus 49
array<int, 49> counter49{};

//kumuliert die Ergebnisse der Ziehungen der Superzahl
array<int, 10>  counterSZ{};

int main()
{
	array <int, 4> max{ 10,100,1000,5000 }; //bestimmt die Anzahl der Ziehungen
	//array <int,1> max{ 5 }; //bestimmt die Anzahl der Ziehungen

	for (int i : max) {
		srand(time(0));
		for (int k = 0; k < 49; k++) counter49[k] = 0;
		for (int k = 0; k < 10; k++) counterSZ[k] = 0;
		for (int w = 0; w < i; w++){
			wurf = ziehung();
			for (int k : wurf) {
				counter49[k - 1]++;// Feldelemente k von wurf sind aus 1 bis 49
			}
			counterSZ[superzahl()-1]++; //die Superzahl geht von 1 bis 10
		}
		/*
		cout << "\nsuperzahlen:\n";
		for (int i : counterSZ) cout << i << ",";
		cout << "\nstatistic:\n";
		for (int i : counter49) cout << i << ",";
		*/

		//Finde meistgezogene Superzahl
		int top1c = 0;
		int top1 = 0;
		for (int i= 0; i<10; i++) {
				if (top1c < counterSZ[i]) {
				top1c = counterSZ[i];
				top1 = i;
			}
		}
		cout << "\n\nF\x81r " << i << " Ziehungen ist die Top1 der Superzahlen " << top1+1;
		
		//Die Top 6 bei den n Ziehungen 6 aus 49
		array<int, 6> top6 = getTop6(counter49);

		cout << "\nDie Top6 bei " << i << " Ziehungen sind (Zahl / Anzahl):";
		for (int t : top6) {
			cout << "\n " << t+1 << " / "<< counter49[t];
		}	
	}
}

int superzahl() {
	return (rand() % 10 + 1);
}

//Liefert 6 aus 1..49 ohne Wiederholung
array<int, 6> ziehung() {
	array<int, 6> z{0,0,0,0,0,0};
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

//Liefert die 6 meistgezogenen Ziffern
array<int, 6> getTop6(array<int, 49> z) {
	array<int, 6> top6{ 0,0,0,0,0,0};
	for (int i = 0; i < 6; i++) {

		int maxc = 0;
		int max = 0;
		for (int j = 0; j < 49; j++) {
			if (maxc < z[j]) {
				maxc = z[j];
				max = j;
			}
		}
		top6[i] = max;
		z[max] = 0;
	}
	return top6;
}