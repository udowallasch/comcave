/**
Abgeleitete Elemente publizieren
Abgeleitete Elemente verstecken
*/

#include <iostream>

using namespace std;

class Base{
	private:
		int i;
	protected:
		int j;
		void m(){cout << "m aus der Klasse Base " << endl;}
	public:
		Base(int i = 0, int j = 0): i{i}, j{j}{}
		void f() {cout << "f aus Base " << endl;}
};

class Derived : public Base{
	private:
		int k;
		using Base::j;
	protected:
		using Base::f;
		//using Base::i; //error?
	public:
	/**
	Für die Initialisierung der geerbten Elemente ist der Basiskonstruktor verantwortlich!!!
	*/
		Derived (int i , int j, int k): Base{i,j} /*i{i}, j{j},-> error*/ ,k{k}{
			//this->i = i;//Error, i ist in Base private
			this->j = j;//Assignement
		}
	using Base::m;
};

class Derived_Derived : public Derived{
	
	public:
			Derived_Derived(int i, int j, int k): Derived{i, j,k}{
				//this->i = 1;//error
				//this->j = 2;//error
			}
};
int main1(){
	Base b{10,20};
	//b.m();//error
	b.f();
	Derived d{1,2,3};
	d.m();//
	//d.f();
	Derived_Derived dd{10,20,30};
	dd.m();
	//dd.f();
	return 0;
}