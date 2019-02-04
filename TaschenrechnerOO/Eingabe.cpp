#include "pch.h"
#include <regex>
#include <iostream>
#include <string>
#include "Eingabe.h"

using std::cout;
using std::cin; 
using std::string;
using std::regex;

char Eingabe::getOP() {
	char ret;
	bool ready = false;
	while (!ready) {
		cout << "\nBitte Operation oder Klammerung eingeben eingeben: +,-,*,/,(,),=  ";
		cin >> ret;
		if (!cin) {
			//kein char
			cout << "Ung\x81ltige Eingabe. Bitte Operation oder Klammerung eingeben eingeben: +,-,*,/,(,),= \n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		};
		string sret{};
		sret += ret;
		regex valid("([*()=+-/])");
		ready = (regex_search(sret, valid));
		if (!ready) {
			cout << "Ung\x81ltige Eingabe: "<<ret<<"\n Bitte Operation oder Klammerung eingeben eingeben: +,-,*,/,(,),= \n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return ret;
}

double Eingabe::getVal() {
	double ret;
	bool ready = false;
	cout << "\nBitte Operand eingeben (double): ";
	while (!ready) {
		if (!(cin >> ret)) {
			cout << "Fehlerhafte Eingabe. Bitte einen Zahlenwert (double)!\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		};
		ready = true;
		if (!ready) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return ret;
}

Eingabe::Eingabe() {}
Eingabe::~Eingabe() {}
