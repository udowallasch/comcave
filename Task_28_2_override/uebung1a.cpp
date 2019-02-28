#include "uebung1a.h"
#include <string>
#include <iostream>

using namespace std;

class A {
public:
	virtual string getName() const { return "A"; }
};

class B: public A {
public:
	virtual string getName() const { return "B"; }
};

class C : public B {

};

class D : public C {
public:
	virtual string getName() const { return "D"; }
};


void uebung1a::run() {

	C c;
	A &rBase = c;
	cout << rBase.getName() << endl;
	//erwartet B 
}

