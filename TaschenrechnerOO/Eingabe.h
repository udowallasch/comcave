#pragma once
#ifndef EINGABE_H
#define EINGABE_H


class Eingabe {
public:
	char getValOrBracket(double**);
	char getOP(); //+,-,*,/,(,),=
	Eingabe();
	~Eingabe();
};




#endif //EINGABE_H
