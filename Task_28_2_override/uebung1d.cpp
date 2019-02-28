#include "uebung1d.h"
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
		string getName() const { return "B"; }
	};

	class C : public B {
	public:
		string getName() const { return "C"; }
	};

	class D : public C {
	public:
		string getName() const { return "D"; }
	};
}

void uebung1d::run() {

	C c;
	B &rBase = c;
	cout << rBase.getName() << endl;
	cout<<"\nerwartet C weil die virtuelle methode von B ueberschrieben wurde \n";

}

