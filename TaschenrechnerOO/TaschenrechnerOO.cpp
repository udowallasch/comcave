// TaschenrechnerOO.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Term.h"
#include "Eingabe.h"

using std::cout;
using std::cin;
using std::string;
using std::stringstream;
using std::setprecision;
using std::to_string;

bool cont();

enum class STATES { 
	W_f_V, //wait for operand 
	W_f_OP //wait for opertion
};


int main()
{
 
 Eingabe eing = Eingabe();

 do {
	 STATES state;
	 Term* root = new Term();
	 state = STATES::W_f_V;
	 stringstream ausgabe{"\n"};
	 double* erg{};

	 bool ready{ false };
	 while (!ready) {
		 system("CLS");
		 cout << ausgabe.str();
		 char op;
		 switch (state) {
		 case STATES::W_f_OP:
			 op = eing.getOP();
			 ausgabe << " " << op;
			 switch (op) {
			 case '+':
			 case '-':
			 case '*':
			 case '/':
				 root->setOp(op);
				 state = STATES::W_f_V;
				 break;
			 case '(':
				 root->open();
				 break;
			 case ')':
				 erg = root->close();
				 if (nullptr != erg) ready = true;
				 break;
			 case '=':
				 erg = root->close();
				 ready = true;
				 break;
			 }
			 break;
		 case STATES::W_f_V:
			 double* val{};
			 op = eing.getValOrBracket(&val);
			 if (nullptr != val) {
				 ausgabe << " "<< setprecision(4)<<*val;
				 root->setVal(*val);
			 } else if (op == '(') {
				 ausgabe << " "<< op;
				 root->open();
				 state = STATES::W_f_V;
				 break;
			 }
			 state = STATES::W_f_OP;
			 break;
		 }
	 }
	 ausgabe << " " << setprecision(4) << *erg << "\n";
	 system("CLS");
	 cout << ausgabe.str();
	 delete root;
 } while (cont());

}


bool cont() {
	while (true) {
		char x = '?';

		cout << "\n\nWeiter? J,j/N,n: "; 
		cin >> x;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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