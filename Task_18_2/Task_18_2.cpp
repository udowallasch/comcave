#include "pch.h"
#include <iostream>
#include <string>
#include <utility> //Die Funktion swap ist hier definiert.
using namespace std;


/** Schreiben Sie ein Programm, das:
* Fragt den Benutzer, wie viele Namen er eingeben möchte.
* Fordert den Benutzer auf, jeden Namen einzugeben.
* Ruft eine Funktion zum Sortieren der Namen auf: Die unten angegegbene Funktion, sort_names, sortiert die Namen alphabetisch.
* Druckt die sortierte Namensliste.


Lernziel:
		 unter anderem dynamische Speicherverwaltung
*/

void sort_names(string*, int);

class Box {
	int i;
	Box(int i) : i{ i } {};
};

int main() {

	int * const ia = new int[3]{ 1,2,3 };
	cout << ia << endl;
	for (int i = 0; i < 3; i++) {
		//cout << *(ia++) << ", "; -> geht nicht wg. ' * const' (Fehlervermeidung!!). Sonst würde mit ia++ delete nicht funktionieren und ein Speicherloch gerissen!!!
		cout << *(ia + i) << ", "; //besser, da der Zeiger nicht verändert wird.
	}
	cout << ia << endl;





	int count;
	//system("CLS");
	cout << "Wieviel Namen sollen sortiert werden? ";
	cin >> count;

	//normalerweise würde jetzt ein vector benutzt. Der kümmert sich selbst um seinen Speicher.
	//...aber soll ja Speicherorganisation üben...
	string  * const names = new string[count];

	for (int i = 0; i < count; i++) {
		string tmp; //tmp auf den stack
		cout << "\nBitte Namen #" + to_string(i + 1)<< " eingeben: ";
		cin >> tmp; 
		names[i] = tmp; // auf den heap kopieren
	} //und tmp verschwindet...

	sort_names(names, count);

	cout << "\n Die sortierte Namensliste:";

	for (int i = 0; i < count; i++) {
		cout << "\n "+names[i];
	}

	delete[] names;
	return 0;
}




void sort_names(string *array, int length) {

	for (int s_i = 0; s_i < length - 1; s_i++) {

		int smallestIndex = s_i;


		for (int currentIndex = s_i + 1; currentIndex < length; ++currentIndex) {

			if (array[currentIndex] < array[smallestIndex])

				smallestIndex = currentIndex;
		}


		swap(array[s_i], array[smallestIndex]);
	}
}

