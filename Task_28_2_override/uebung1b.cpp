#include "uebung1b.h"
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
	public:
		virtual string getName() const { return "C"; }
	};

	class D : public C {
	public:
		virtual string getName() const { return "D"; }
	};
}

	void uebung1b::run() {

		C c;
		B &rBase = c;
		cout << rBase.getName() << endl;
		cout << "\nerwartet C wg virtual\n";
	}

