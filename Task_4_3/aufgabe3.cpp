#include "pch.h"
#include "aufgabe3.h"
#include <iostream>
#include <string>
using namespace std;

namespace {
	int a[] = { 33,47,23,9,49,3,4,5,7,47,9,8 };

	int minimum(int*, int);
	int minimum(int*, int, int&);

	int minimum(int* ia, int len) {
		int m = *ia;
		for (int i = 0; i < len - 1; i++) {
			if (*(++ia) < m) m = *ia;
		}
		return m;
	}

	int minimum(int* ia, int len, int& pos) {
		int m = *ia;
		pos = 0;
		for (int i = 0; i < len - 1; i++) {
			if (*++ia < m) {
				m = *ia;
				pos = i + 1;
			}
		}
		return m;
	}
}

void aufgabe3::run() {
	int pos = -47;
	cout << "min: " << minimum(a, 11, pos) << " pos: " << pos << endl;
}