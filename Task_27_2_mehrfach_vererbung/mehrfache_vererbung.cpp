
/**
Mehrfache Vererbung:
					-C++ erlaubt es - aber es ist nicht empfohlen
					-Java, C#, Smalltalk erlauben es nicht
					-Java, C# -> werden Interfaces benutzt
*/
#include <iostream>
using namespace std;
class Esel{
	public:
		int s = 12;
		Esel(){
			cout << "Ich bin Esel " << endl;
		}
		void e(){
			cout << "e aus Esel " << endl;
		}
		void c(){
			cout << "c aus Esel " << endl;
		}
};
class Pferd{
		
	public:
		int f = 13;
		Pferd(){ cout << "Ich bin Pferd " << endl;}
		void p(){
			cout << "p aus Pferd " << endl;
		}
		void c(){
			cout << "c aus Pferd " << endl;
		}
};
class Maultier : public Pferd, public Esel{
	public:
	int m = 14;
		Maultier(){cout << "Ich bin Maultier " << endl;}
		void t(){
			cout << "t aus Maultier " << endl;
		}
};

int main2(){
	Maultier mt;
	mt.s = 100; mt.f = 200; mt.m = 300;
	mt.e(); mt.p(); mt.t();
	//mt.c();---> ambiguous
	mt.Esel::c();//Esel Version
	mt.Pferd::c();//Pferd Version
	return 0;
}