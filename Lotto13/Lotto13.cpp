// Lott13.cpp : Lottoprogramm mit Eingabe und statistischer Auswertung
// Udo Wallasch 

#include "pch.h"
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <stdlib.h>    
#include <ctime>     

using namespace std;

//Datentypen +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
const int MAX_ZIFF = 6;
int const MAX = 70000;

struct ziehung {
	int zahlen[MAX_ZIFF];
	int superZahl; 

};

struct ergebnis {
	int mitSZ[MAX_ZIFF + 1]; //Anzahl Richtige incl. 'kein Richtiger' 
	int ohneSZ[MAX_ZIFF + 1];
};

//funktionen ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int superzahl();
ziehung ziehe();
array<int, 6> getTop6(array<int, 49>);
void getTipp(ziehung&);
int getZiffer(string, int);
void sortiere(ziehung&);
ergebnis evalTipp(ziehung&, vector<ziehung>&);
void printStatistik(ergebnis&, ziehung&, int);
bool cont();

//Daten ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

vector<ziehung> ziehungen{};
//meinTipp
ziehung tipp{};

//Ergebnis einer Ziehung mit SuperZahl
ziehung wurf{};

//0,1,2..maxZiff Richtige mit dem Tipp bei den x ziehungen
ergebnis statistik{};

int main()
{
	do {
		system("cls");
		for (int i = 0; i < MAX_ZIFF; i++) tipp.zahlen[i] = 0;
		getTipp(tipp);
		sortiere(tipp);

		srand(time(0));
		ziehungen.clear();
		ziehungen.reserve(MAX);

		for (int w = 0; w < MAX; w++) {
			wurf = ziehe();
			sortiere(wurf);
			ziehungen.push_back(wurf);
		}

		statistik = evalTipp(tipp, ziehungen);
		printStatistik(statistik, tipp, MAX);

	} while (cont());
}

int superzahl() {
	return (rand() % 10 + 1);
}

//Liefert Tipp 6 aus 1..49 ohne Wiederholung plus Superzahl
void getTipp(ziehung& z) {
	bool ready = false;
	int k = 0;
	cout << "\nBitte Tipp abgeben. Ziffern von 1 bis 49, ohne Wiederholung.\n";
	for (int i = 0; i < MAX_ZIFF; i++) {
		k = 0;
		ready = false;
		int count = 0;
		int const max_count = 3;
		while (!ready) {
			count++;
			string text = "Bitte Ziffer " + to_string(i+1) + " : ";
			k = getZiffer(text, 49);
			ready = true;
			if (k < 0) {
				cout << "\nFehlerhaft Eingabe!";
				if (count == max_count) {
					if (!cont()) exit(0);
				}
				continue;
			}
			for (int l = 0; l < 6; l++) {
				if (z.zahlen[l] == k) {
					// bereits getippt, also nächster Versuch...
					cout << "\nBitte Zahlen nicht doppelt eingeben: " << k << "\n";
					if (count == max_count) {
						if (!cont()) exit(0);
					}
					ready = false;
					break;
				}
			}
		}
		z.zahlen[i] = k;
	}
	k = 0;
	ready = false;
	string text = "\nBitte Superzahl eingeben (Ziffer von 1 bis 10): ";
	while (!ready) {
		k = getZiffer(text, 10);
		ready = true;
		if (k < 0) {
			cout << "\nFehlerhaft Eingabe!";
			if (!cont()) exit(0);
			ready = false;
			continue;
		}
	}
	z.superZahl = k;
}

//Liefert Ziehung 6 aus 1..49 ohne Wiederholung plus Superzahl
ziehung ziehe() {
	ziehung z;
	for (int i = 0; i < MAX_ZIFF; i++) z.zahlen[i] = 0;

	bool ready = false;
	for (int i = 0; i < MAX_ZIFF; i++) {
		int k = 0;
		ready = false;
		while (!ready) {
			k = (rand() % 49 + 1);
			ready = true;
			for (int l = 0; l < MAX_ZIFF; l++) {
				if (z.zahlen[l] == k) {
					// bereits gezogen, also nächster Versuch...
					ready = false;
					break;
				}
			}
		}
		z.zahlen[i] = k;
	}
	z.superZahl = superzahl();

	return z;
}


int getZiffer(string ausgabe, int max) {
	int ret;
	bool ready = false;
	cout <<ausgabe;
	int count = 0;
	while (count < 3) {
		count++;
		if (!(cin >> ret)) {
			cout << "\nFehlerhafte Eingabe!";
			cout << "\n" << ausgabe;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		};
		if (ret >= 1 && ret <= max) {
			return ret;
		}
		cout << "\nFehlerhafte Eingabe!";
		cout << "\n" << ausgabe;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return -1;
}


bool cont() {
	while (true) {
		char x = '?';
		cout << "\n\nWeiter? J,j/N,n: "; cin >> x;
		if (!cin) { continue; };
		switch (x) {
		case 'J':
		case 'j': return true;
			break;
		case 'N':
		case 'n': return false;
			break;
		default: continue;
		}

	}
}

void sortiere(ziehung& z) {
	for (int i = 0; i < MAX_ZIFF; i++) {
		int temp = 0;
		for (int i = 0; i < MAX_ZIFF - 1; i++) {
			int min = i;
			int treffer = i;
			temp = z.zahlen[min];
			for (int j = i + 1; j < MAX_ZIFF; j++) {
				if (z.zahlen[j] < temp) {
					temp = z.zahlen[j];
					treffer = j;
				}
			}
			z.zahlen[treffer] = z.zahlen[min];
			z.zahlen[min] = temp;
		}
	}
}

ergebnis evalTipp(ziehung& tipp, vector<ziehung>& ziehungen) {
	ergebnis erg{};
	int richtige = 0; //kein richtiger
	for (ziehung z : ziehungen) {
		richtige = 0;
		for (int i = 0; i < MAX_ZIFF; i++) {

			for (int j = 0; j < MAX_ZIFF; j++) {
				if (tipp.zahlen[i] == z.zahlen[j]) richtige++;
			}
		}
		if (z.superZahl == tipp.superZahl) {
			erg.mitSZ[richtige]++;
		} else {
			erg.ohneSZ[richtige]++;
		}
	}
	return erg;
}

void printStatistik(ergebnis& erg, ziehung& tipp, int anz ) {
		system("CLS");
		cout<<"\n---------------------------------------------------------------------\n";
		cout << "\nBei " << anz << " Ziehungen wurden mit Ihrem Tipp: ";
		for (int i = 0; i < MAX_ZIFF; i++) {
			cout << tipp.zahlen[i] << (i!=(MAX_ZIFF - 1)? ", ":". ");
		}
		cout << "Superzahl: " << tipp.superZahl;
		cout << "\nfolgende Ergebnisse erzielt:";
		cout << "\n\nRichtige mit Superzahl: ";
		for (int i = 0; i < MAX_ZIFF + 1; i++) {
			cout << "\n" << i <<" Richtige: "<< erg.mitSZ[i];
		}
		cout << "\n\nRichtige ohne Superzahl: ";
		for (int i = 0; i < MAX_ZIFF + 1; i++) {
			cout << "\n" << i << " Richtige: "<< erg.ohneSZ[i];
		}
		cout<<"\n---------------------------------------------------------------------\n";

}
