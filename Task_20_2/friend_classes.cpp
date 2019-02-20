#include <iostream>
using namespace std;
/**
Freundschafft zwischen Klassen und Funktionen (*)
Freundschafft zwischen Klassen (**)

--->
*/


namespace {


	class A {
	private:
		int v;
	public:
		A(int v = 0) :v{ v } {}
		friend class B;
	};

	class B {
	private:
		int b;
	public:
		B(int b = 0) :b{ b } {}
		void show(A &a) {
			cout << a.v << endl;//v in A ist private
		}
		void m(A &a) {
			a.v = 21;
		}
	};

}

int main0(){
	A aobj{12};
	B bobj;
	bobj.m(aobj);
	bobj.show(aobj);
	return 0;
}


