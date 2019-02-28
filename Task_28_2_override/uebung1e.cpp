#include "uebung1e.h"
#include <string>
#include <iostream>

using namespace std;
namespace {
	class A {
	public:
		virtual string getName() const { return "A"; }
	};

	class B : public A {
	public:
		 virtual string getName()  { return "B"; }
	};

	class C : public B {
	public:
		virtual string getName()  { return "C"; }
	};

	class D : public C {
	public:
		virtual string getName()  { return "D"; }
	};
}

void uebung1e::run() {

	C c;
	D d;
	A &rBase = d;
	cout << rBase.getName() << endl;
	cout << "\n A weil:  sucht ausgehend von A nach einer Ueberschreibung der A-Methode (incl const!). Der tiefste Treffer wird genommen \n";

}

