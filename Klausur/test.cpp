#include "pch.h"
#include "test.h"
#include<iostream>
#include<sstream>

using namespace std;

namespace {





	class A {
	public:
		void m() const{};
	};







}

void test::run() {
	cout << "test begin----------------------------------------" << endl;
	//int a = 1, b = 2, c = 3;
	//cout << ((a < b) && (b < c)) << endl;
	//cout << !(b || a) << endl;
	//cout << !!(a || !a) << endl;
	//cout << (a >= b && b >= a) << endl;

	const A a;
	a.m();

	


	cout << "test end----------------------------------------" << endl<<endl<<endl;
}

test::test() {}
test::~test() {}
