#include "pch.h"
#include <iostream>

#include "Term.h"

using std::cout;


bool calcTermParts(vector<double>* vars, vector<char>* ops, char op) {
	double erg = -1;
	auto ito = ops->begin();
	auto itv = vars->begin();
	bool ready = (ops->size() == 0);
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
		}
		else {
			itv++;
			ito++;
			ready = (ito == ops->end());
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
		return 1;
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

double Term::calc() {
	if (calcTermParts(&vals, &ops, '*')) {
		if (calcTermParts(&vals, &ops, '/')) {
			if (calcTermParts(&vals, &ops, '+')) {
				if (calcTermParts(&vals, &ops, '-')) {
				}
			}
		}
	}
	return vals.at(0);
}

void Term::open() {
	if (nullptr != ot) {
		ot->open();
	} else {
		ot = new Term();
	}
}

double* Term::close() {
	if (nullptr != ot) {
		double* val = ot->close();
		if (nullptr != val) {
			vals.push_back(*val);
			delete (val);
			ot->clear();
			ot = nullptr;
			return nullptr;
		}
	} else {
		return new double(calc());
	}
	
}

void Term::setOp(char op) {
	if (nullptr != ot) {
		ot->setOp(op);
	} else {
		ops.push_back(op);
	}
}

void Term::setVal(double val) {
	if (nullptr != ot) {
		ot->setVal(val);
	} else {
		vals.push_back(val);
	}
}

void Term::clear() {
	if (nullptr != ot) {
		ot->clear();
	}
}


