// TaschenrechnerOO.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "Term.h"
#include "Eingabe.h"

using std::cout;

enum class STATES { 
	W_f_V, //wait for operand 
	W_f_OP //wait for opertion
};


int main()
{
 Term* root = new Term();
 Eingabe eing = Eingabe();

 root->setVal(1);
 root->setOp('+');
 root->setVal(2);
 root->setOp('*');
 root->open();
 root->setVal(3);
 root->setOp('+');
 root->setVal(4);
 root->close();
 double* erg = root->close();
 cout << "\n Ergebnis: " << *erg;

 delete (root);
	
 root = new Term();
 root->setVal(1);
 root->setOp('+');
 root->setVal(2);
 root->setOp('*');
 root->open();
 root->setVal(3);
 root->setOp('+');
 root->setVal(4);
 root->close();
 root->setOp('+');
 root->setVal(2);
 root->setOp('*');
 root->open();
 root->setVal(3);
 root->setOp('+');
 root->setVal(4);
 root->close();
 erg = root->close();
 cout << "\n Ergebnis: " << *erg;

 delete (root);

 root = new Term();
 root->setVal(1);
 root->setOp('+');
 root->setVal(2);
 root->setOp('*');
 root->open();
 root->open();
 root->setVal(3);
 root->setOp('+');
 root->setVal(4);
 root->close();
 root->setOp('*');
 root->open();
 root->setVal(7);
 root->setOp('+');
 root->setVal(1);
 root->close();
 root->close();
 erg = root->close();
 cout << "\n Ergebnis: " << *erg;
 delete (root);


 while (true) {
	 STATES state;

	 root = new Term();

	//Berechnung startet mit einem Operanden!
	 double first = eing.getVal(); 
	 root->setVal(first);
	 state = STATES::W_f_OP;


	 bool ready{ false };
	 while (!ready) {
		 switch (state) {
		 case STATES::W_f_OP:
			 char op = eing.getOP();
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
			 double val = eing.getVal();
			 root->setVal(val);
			 state = STATES::W_f_OP;

			 break;

		 }
	 }
 }
}

