#include "uebung1a.h"
#include "uebung.h"
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
		virtual string getName() const { return "B"; }
	};

	class C : public B {

	};

	class D : public C {
	public:
		virtual string getName() const { return "D"; }
	};
}

void uebung1a::run() {

	C c;
	A &rBase = c;
	cout << rBase.getName() << endl;
	cout << "\nerwartet B weils die letzte Ueberschreibung auf dem Weg nach unten ist\n";
}

