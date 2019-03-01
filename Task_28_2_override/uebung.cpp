#include "uebung.h"
#include <string>
#include <iostream>

using namespace std;
namespace {
	class A {
	public:
		virtual string getName() const { return "A"; }
		virtual string getName(int i) const { return "A"; }
	};

	class B : public A {
	public:
		virtual string getName()  { return "B"; }
		//string getName(string d) { return "B"+d; }
	};

	class C : public B {

	};

	class D : public C {
	public:
		virtual string getName() const { return "D"; }
	};
}

void uebung::run() {
	B b;
	b.getName();
	B* br= &b;
//	br->getName(1); //geht nicht
	A * ar = &b;
	ar->getName(1);


}

