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

class Term {
public:
	void setOp(char);
	void setVal(double);
	void open();
	double* close();
	double calc();
	void clear();
private:
	Term* ot{ nullptr };		//sub-Term
	vector<double> vals;		//zur Berechnung des eigenen Wertes
	vector<char> ops;			//zur Berechnung des eigenen Wertes

};


#endif //TERM_H