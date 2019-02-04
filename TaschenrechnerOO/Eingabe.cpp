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
	cout << "\n----------------------------------------";
	while (!ready) {
		cout << "\nBitte Operation oder Klammerung eingeben eingeben: +,-,*,/,(,),=  ";
		cin >> ret;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

char Eingabe::getValOrBracket(double** val) {
	bool ready = false;
	char ret;
	cout << "\n----------------------------------------";
	cout << "\nBitte Operand eingeben (double): ";
	while (!ready) {
		string line{};
		ret = 'n';
		getline(cin,line);
		//	cin.ignore(256, '\n');
		if (line.length() == 0) {
			cout << "Fehlerhafte Eingabe. Bitte einen Zahlenwert oder Klammer!\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if ( line.at(0) == '(' ) {
			val = nullptr;
			ret = line.at(0);
			ready = true;
			continue;
		}

		string tmp;
		for (string::iterator it = line.begin(); it != line.end(); ++it) {
			if (isdigit(*it) || *it == '.') {
				tmp += *it;
			} else {
				cout << "Fehlerhafte Eingabe. Bitte einen Zahlenwert (double)!\n";
				tmp.clear();
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}

		}
		if (tmp.length() > 0) {
			*val = new double(stod(tmp));
			ready = true;
		}

	}
	return ret;
}

Eingabe::Eingabe() {}
Eingabe::~Eingabe() {}
