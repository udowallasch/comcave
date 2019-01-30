// Aufgabe8.cpp 
//Udo Wallasch
//
//Lösen Sie folgendes Problem.
//Sie haben 3 Zahlenwerte.
//Diese Werte müssen folgende Endwerte erreichen.
//Wert 1 >= 8200 
//Wert 2 = Wert 1 * 0, 66 
//Wert 3 = Wert 2 * 0, 5


#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	float fLW1 = 1.0;
	float fLW2 = 1.0;
	float fLW3 = 1.0;

	while (fLW1 < 8200) {
		while (fLW2 < fLW1 * 0.66) {
			while (fLW3 <fLW2 * 0.5) {
				fLW3++;
				//cout << "L3 = " << fLW3 << endl;
			}
			fLW2++;
			//cout << "L2 = " << fLW2 << endl;
		}
		fLW1++;
		//cout << "L1 = " << fLW1 << endl;
		cout << "L1 = " << fLW1 << " L2 = " << fLW2 << " L3 = " << fLW3 << endl;

	}

}
