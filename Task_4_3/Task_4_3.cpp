// Task_4_3.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include "aufgabe1.h"
#include "aufgabe2.h"
#include "aufgabe3.h"

using namespace std;

// abstrakt
class A {
public:
	virtual int f1(int) = 0;

};

class B : public A {
public:
	virtual int f1(int i) override {
		return i++;
	}
};

// polymorph
class C {
public:
	int j = 0;
	virtual int f1(int i) {
		return i++;
	}

};

class D :public C {
public:
	int k = 0;
	virtual int f1(int i) override{ //polymorph
		return i--;
	}
	int f2() {
		return k;
	}
	D(){ cout << "D\n"; }
	~D() { cout << "~D\n"; }

};

//interface
class E{
public:
	virtual int f1(int) = 0;
	virtual int f2(int) = 0;

};

//diamond
class F : public E, D {
	virtual int E::f1(int i) override { return 4711; }
	virtual int f2(int) override { 7; }
};

void leak() {
	//D* d = new D[5];
	//delete[] d;
	vector<D*> vd;
	vd.push_back(new D);
	vd.push_back(new D);
	vd.push_back(new D);
	vd.push_back(new D);
	for (auto it : vd)delete it;
}

struct ret{
	int sum;
	int prod;
	int diff;
};

void relInt(int, int, ret*);

ret relInt(int, int);



int main()
{
	//C c;
	//D d;
	//c = d; //slice

	//leak();

	//ret r = relInt(7, 8);

	//cout << "sum=" << r.sum << endl;
	//cout << "diff=" << r.diff << endl;
	//cout << "prod=" << r.prod << endl;

	//ret * r1 = new ret();
	//relInt(8, 9, r1);
	//cout << "sum=" << r1->sum << endl;
	//cout << "diff=" << r1->diff << endl;
	//cout << "prod=" << r1->prod << endl;
	aufgabe1 a1;
	aufgabe2 a2;
	aufgabe3 a3;
//	a1.run();
	a2.run();
//	a3.run();
   
}


ret relInt(int a, int b) {
	ret r;
	r.diff = a - b;
	r.prod = a * b;
	r.sum = a + b;
	return r;
}
void relInt(int a, int b, ret* r) {
	r->diff = a - b;
	r->prod = a * b;
	r->sum = a + b;
}

