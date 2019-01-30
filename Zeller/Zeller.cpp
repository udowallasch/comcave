// Zeller.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <stdlib.h>    
#include <ctime>     

using namespace std;

enum enuDayOfWeek  {SO,MO,DI,MI,DO,FR,SA};

int getZiffer(string);
enuDayOfWeek fctZeller(int, int, int);
bool cont();

int main()
{ 
	do {
		int tag;
		int monat;
		int jahr;
		tag = getZiffer("Bitte Tag eingeben:");
		monat = getZiffer("Bitte Monat eingeben:");
		jahr = getZiffer("Bitte Jahr eingeben:");

		cout << "\n Der " << tag << "." << monat << "." << jahr << " war ein ";

		switch (fctZeller(tag, monat, jahr)) {
		case MO:
			cout << "Montag.";
			break;
		case DI:
			cout << "Dienstag.";
			break;
		case MI:
			cout << "Mittwoch.";
			break;
		case DO:
			cout << "Donnerstag.";
			break;
		case FR:
			cout << "Freitag.";
			break;
		case SA:
			cout << "Samstag.";
			break;
		case SO:
			cout << "Sonntag.";
			break;
		}
	} while (cont());
}

enuDayOfWeek fctZeller(int iA, int iB, int iC)
{
	if (iB > 2) iB -= 2;
	else
	{
		iB += 10;
		iC--;
	}
	int iY = iC / 100;
	iC %= 100;
	int iZ = (iC / 4 + iY / 4 + (13 * iB - 1) / 5 + iA + iC + 5 * iY) % 7;
	return static_cast<enuDayOfWeek>(iZ);
}

int getZiffer(string s) {
	int e;
	cout << "\n" << s;
	while (true) {
		cin >> e;
		if (!cin) continue;
		break;
	}
	return e;
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