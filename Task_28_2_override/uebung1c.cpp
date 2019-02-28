#include "uebung1c.h"
#include <string>
#include <iostream>

using namespace std;
namespace {
	class A {
	public:
		string getName() const { return "A"; }
	};

	class B : public A {
	public:
		virtual string getName() const { return "B"; }
	};

	class C : public B {
	public:
		virtual string getName() const { return "C"; }
	};

	class D : public C {
	public:
		virtual string getName() const { return "D"; }
	};
}

void uebung1c::run() {

	C c;
	A &rBase = c;
	cout << rBase.getName() << endl;
	cout << "\nerwartet A, weil die methode in A nicht virtuell ist und ein A referenziert wird (kein B aus der hierachie!!!)\n";

}

