#pragma once
#ifndef TERM_H
#define TERM_H

#include<vector>
#include <variant>

using std::vector;

bool calcTermParts(vector<double>*, vector<char>*, char);

double fctAdd(double, double);
double fctSub(double, double);
double fctMul(double, double);
double fctDiv(double, double);
double fctSqrt(double);
double fctCalc(double, double, char);

class Term
{
	struct term {
		Term* const t_{ nullptr };
		double* const d_{ nullptr };
		char o_{ 'n' };

		term(Term* t) :t_(t) {}
		term(double* d, char o) :d_(d), o_(o) {}

	};
public:
	void add(term);
	void open();
	double close();
	double calc();
	void clear();
	Term(Term* t) { terms.clear();  term t_(t); terms.push_back(t_); ot = t;  };
	Term(double* d, char o) { terms.clear(); term t_(d, o); terms.push_back(t_); };
	~Term();

private:
	Term();
	Term* ot{ nullptr };	//geöffnete Klammer
	vector<term> terms;		//der komplette Ausdruck mit allen geklammerten Termen
	vector<double> vals;	//zur Berechnung des eigenen Wertes
	vector<char> ops;		//zur Berechnung des eigenen Wertes

};


#endif //TERM_H