
#include <iostream>
#include "Templates.h"

using namespace std;

class A {
	int i;
public:
	virtual void m() = 0;
	A() { cout << "A()" << endl; }
	A(int i) : i{i} { cout << "A(i)" << endl; }
};


class V : public virtual A {
	int j;
public:
	virtual void m() override { cout << "m aus V" << endl; }
	V() { cout << "V()" << endl; }
	V(int i, int j) :A(i), j{ j } { cout << "V(i,j)" << endl; }

};

class M :public virtual A {
	int j;
public:
	virtual void m() override { cout << "m aus M" << endl; }
	M() { cout << "M()" << endl; }
	M(int i, int j) :A(i), j{ j } { cout << "M(i,j)" << endl; }

};

class K :public V, public M {
	int k;
public:
	void m() { cout << "m aus K" << endl; }
	K() { cout << "K()" << endl; }
	K(int i, int j, int k) : V(i, j), M(i, j), k{ k } { cout << "K(i,j,k)" << endl; }

};

int main()
{
	//K k{ 1,2,3 };
	//k.V::m();
	//k.M::m();
	//k.m();

	Templates t;
	t.run();
}
