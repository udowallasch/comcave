// Taschenrechner.cpp
//liest zeilenweise eine Operation und ihre Operanden ein und gibt das Ergebnis
//Kettenrechnungen sind möglich - das jeweils letzte Ergebnis wird als erster
//Operand der nächsten Rechnung genommen.
//Udo Wallasch

#include "pch.h"
#include <iostream>
#include <string>
#include <regex>


using namespace std;

double var1 = 0;
double var2 = 0;
char op = '?';
string sErg = "";
double erg = -1;

double getVar();
char getOp();
bool cont();
string compose(string, double, char);
string compose_sqrt(string);

double fctAdd(double, double);
double fctSub(double, double);
double fctMul(double, double);
double fctDiv(double, double);
double fctSqrt(double);
double fctCalc(double, double, char);

int main()
{
	//initiale operation s wie start
	op = 's';

	while (true) {
		// clear screen if we just start...
		if (op == 's') { system("CLS"); }
		
		op = getOp();
		switch (op) {
		case 'x':
		case 'X': return 1;
			break;
		case 'c':
		case 'C': 
			system("CLS");
			sErg = "";
			continue;
		default:
			break;
		}

		if (sErg.length() == 0) {
			var1 = getVar();
		}
		else {
			var1 = erg;
		}


		//check for division by zero
		if (op == '/' && var2 == 0) {
			cout << "Division durch 0 nicht m\x94glich!";
			if (!cont()) {
				return 1;
			}
			else {
				continue;
			};
		}

		if (op == 'W'|| op == 'w') {
			//Quadratwurzel
			erg = fctSqrt(var1);
			cout << "\n" << "SQRT (" << var1 << ")" << " = " << erg;

			if (sErg.length() == 0) {
				//single or first operation
				sErg = compose_sqrt(to_string(var1));
			}
			else {
				//multiple operation
				sErg = compose_sqrt(sErg);
			}
		}
		else {
			//alle anderen Operationen
			var2 = getVar();

			// get new result of operation ...
			//cout << ".... " << erg;
			erg = fctCalc(var1, var2, op);
			//cout << ".... " << erg;

			// ...and report..
			if (sErg.length() == 0) {
				//single or first operation
				cout << "\n" << var1 << " " << op << " " << var2 << " = " << erg;
				sErg = compose(to_string(var1), var2, op);
			}
			else {
				//multiple operation
				cout << "\n" << sErg << " " << op << " " << var2 << " = " << erg;
				sErg = compose(sErg, var2, op);
			}
		}

		if (!cont()) { return 1; };
	}	 
	return 1;
}

double getVar() {
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

char getOp() {
	char ret;
	bool ready = false;
	while (!ready) {
		cout << "\nBitte Operation eingeben eingeben +,-,*,/ \noder W/w f\x81r Quadratwurzel\noder X/x f\x81r beenden \noder C/c f\x81r neue Berechnung: ";
		cin >> ret;
		if (!cin) { 
			//kein char
			cout << "Ung\x81ltige Eingabe. Bitte +,-,*,/ \noder W/w f\x81r Quadratwurzel\noder X/x f\x81r beenden \noder C/c f\x81r neue Berechnung eingeben!\n"; 
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		};
		/*
		char aret[2] = {'x',0};
		aret[0] = ret;
		string sret(aret);
		*/
		string sret{};
		sret += ret;
		regex valid("([*XxCcWw+-/])");
		ready = (regex_search(sret, valid));
		if(!ready){
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return ret;
}

double fctAdd(double a, double b) {
	return a + b;
}

double fctSub(double a, double b) {
	return a - b;
}

double fctMul(double a, double b) {
	return a * b;
}

double fctDiv(double a, double b) {
	return a / b;
}
double fctSqrt(double s) {
	return sqrt(s);
}

bool cont() {
	while (true) {
		char x = '?';
		cout << "\n\nWeitere Berechnung ausf\x81hren? J,j/N,n: "; cin >> x;
		if (!cin) {	continue;};
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

double fctCalc(double a, double b, char op) {
	double erg = -1;
	//double erg2 = -1;
	switch (op) {
	case '+': erg = fctAdd(a, b);
		//erg2++;
		break;
	case '-': erg = fctSub(a, b);
		break;
	case '*': erg = fctMul(a, b);
		break;
	case '/': erg = fctDiv(a, b);
		break;
	default: cout << "\nunbekannte Operation: "<< op;
		//return macht keinen Sinn, eigentlich müsste eine Exception geworfen werden.
		if (!cont()) { return 1; };
		break;
	}
	return erg;
}

string compose(string s, double e, char o) {
	char buff[1024];
	int n;
	//convert string to char*
	char *c = &s[0u];
	n=sprintf_s(buff, 1024,"(%s %c %f)", c, o, e);
	return string(buff);
}

string compose_sqrt(string s) {
	char buff[1024];
	int n;
	//convert string to char*
	char *c = &s[0u];
	n = sprintf_s(buff, 1024, "(SQRT(%s)", c);
	return string(buff);
}
