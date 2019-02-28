#include "uebung1f.h"
#include <string>
#include <iostream>

using namespace std;
namespace {
	class A {
	public:
		A() { cout << getName(); }
		virtual string getName() const { return "A"; }
	};

	class B : public A {
	public:
		virtual string getName() { return "B"; }
	};

	class C : public B {
	public:
		virtual string getName() { return "C"; }
	};

	class D : public C {
	public:
		virtual string getName() { return "D"; }
	};
}

void uebung1f::run() {

	C c;
	cout << "\nerwartet A weil konstruktor von A als erstes gerufen wird.\n";

}

