#pragma once
#ifndef TERM_H
#define TERM_H

#include<vector>
#include <variant>

using std::vector;
using std::variant;

bool calcTermParts(vector<double>*, vector<char>*, char);

double fctAdd(double, double);
double fctSub(double, double);
double fctMul(double, double);
double fctDiv(double, double);
double fctSqrt(double);
double fctCalc(double, double, char);



struct term {
	void* t{ nullptr };
	double* d{ nullptr };
	char o{ 'n' };
};

class Term
{
	vector<term> terms;		//der komplette Ausdruck mit allen geklammerten Termen
	vector<double> vals;	//zur Berechnung des eigenen Wertes
	vector<char> ops;		//zur Berechnung des eigenen Wertes

public:
	void add(term);
	double calc();
	void clear();
	Term();
	~Term();
};




#endif //TERM_H