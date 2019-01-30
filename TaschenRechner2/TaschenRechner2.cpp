// Taschenrechner2.cpp mit Term-Eingabe und PunktVorStrich
// Udo Wallasch

#include "pch.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

string sTerm{};
vector<double> vars{};
vector<char> ops{};

bool readLine(string*);
bool parseTerm(string&, vector<double>*, vector<char>*);
bool calcTermParts(vector<double>*, vector<char>*, char);
bool cont();

double fctAdd(double, double);
double fctSub(double, double);
double fctMul(double, double);
double fctDiv(double, double);
double fctSqrt(double);
double fctCalc(double, double, char);

int main()
{
	while (true) {
		system("CLS");

		sTerm.clear();
		if (!readLine(&sTerm)){
			cout<<"\n Fehlerhafte Eingabe!";
			//if(!cont) return 1;
			continue;
		};

		if (!parseTerm(sTerm, &vars, &ops)) {
			cout << "\n Fehlerhafte Eingabe: \'" << sTerm << "\'";
			if(!cont()) return 1;
			continue;
		}

		if (calcTermParts(&vars, &ops, '*')) {
			if (calcTermParts(&vars, &ops, '/')) {
				if (calcTermParts(&vars, &ops, '+')) {
					if (calcTermParts(&vars, &ops, '-')) {
					}
				}
			}
		}
		cout << "\n" << sTerm << vars.at(0);
		
		if (!cont()) { return 0; };
	}
	return 0;
}

 bool readLine(string* l ) {
	 string line{};
	 cout << "\nBitte Term eingeben (\"var op var op ...=\")\n";
	 do { // mindestens einmal getline ausführen
		 //std::getline(cin, line);
		 cin >> line;
		 l->append(line);
	 } while (line.at(line.length()-1) != '=');
	 return true;
}

 bool parseTerm(string& s, vector<double>* vars, vector<char>* ops) {

	 string tmp{};
	 string sclean{};
	 vars->clear();
	 ops->clear();
	 bool gotFirstDigit = false;
	 for (string::iterator it = s.begin(); it != s.end(); ++it) {	
		 if (isdigit(*it) || *it == '.') {
			 tmp += *it;
			 sclean += *it;
		 } else {
			if (!gotFirstDigit && tmp.length() == 0) {
				//ignore leading chars
				continue;
			 }

			if (tmp.length() > 0) {
				 gotFirstDigit = true;
				 vars->push_back(stod(tmp, 0));
				 tmp = "";
			} 
			
			string s{};
			s += *it;
			regex valid("([*+-/])");
			if (regex_search(s, valid)) {
					ops->push_back(*it);
					sclean += *it;
			}
		 }
	 }
	 sclean += '=';
	 s = sclean;
	 return (ops->size() > 0);


 }

 bool calcTermParts(vector<double>* vars, vector<char>* ops, char op) {
	 double erg = -1;
	 bool ready = false;
	 auto ito = ops->begin();
	 auto itv = vars->begin();
	 while (!ready) {
		 if (*ito == op) {
			 double var1 = *itv;
			 double var2 = *(++itv);
			 if (op == '/'&& var2 == 0) {
				 cout << "\nTssTssTss... Schlimmer Fehler! Division durch 0! ";
				 return false;
			 }
			 erg = fctCalc(var1, var2, op);
			 *(--itv) = erg;
			 vars->erase(++itv);
			 itv = vars->begin();
			 ops->erase(ito);
			 ito = ops->begin();
			 ready = (ops->size() == 0);
		 } else {
			 itv++;
			 ito++;
			 ready = (ito ==ops->end());
		 }
	 }
	 return (ops->size() > 0);
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
	 default: cout << "\nunbekannte Operation: " << op;
		 //return macht keinen Sinn, eigentlich müsste eine Exception geworfen werden.
		 if (!cont()) { return 1; };
		 break;
	 }
	 return erg;
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