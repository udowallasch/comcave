#include <iostream>
using namespace std;

/**
Eine Funktion kann "friend" mehrerer Klassen sein.
*/
class B;//forward declaration

class A{
	
	private:
			int t;
			
	public:
			A(int t = 0):t{t}{}
		friend void print(A &a, B &b);
};


class B{
	private:
		int h;
		friend void print(A &a, B &b);// ob im private Bereich oder public - Bereich -> keine Auswirkung -> kein Mitglieder!
	public:
		B(int h = 0):h{h}{}
		
};
void print(A &a, B &b){
	cout << a.t << ", " << b.h << endl;
}

int add (int a ,int b);//forward declaration of a function

int main3(){
	add (3,7);
	A a{15};
	B b{10};
	print(a ,b);
	return 0;
}

int add (int a,int b){
	return a + b;
}
