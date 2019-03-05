#include "Templates.h"
#include <iostream>
using namespace std;
namespace {


	template<typename T> void v(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

	//void v(int& i, int& j) {
	//	int k = i;
	//	i = j;
	//	j = k;
	//}
}




void Templates::run() {
	int i = 3, j = 4;
	cout << "i:" << i << " j:" << j << endl;
	v(i, j);
	cout << "i:" << i << " j:" << j << endl;
	double a = 2.3, b = 3.3;
	cout << "a:" <<a << " b:" << b << endl;
	v(a, b);
	cout << "a:" << a << " b:" << b << endl;
	long l = 123;
	v<double&>(l, a);


}


Templates::Templates() {}
Templates::~Templates() {}
