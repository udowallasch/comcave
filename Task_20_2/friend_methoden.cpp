#include <iostream>
using namespace std;
/**
Freundschafft zwischen Klassen und Funktionen (*)
Freundschafft zwischen Klassen (**)
Freundschafft zwischen Klassen und Methoden anderer Klasse

--->
*/
class A;

class B{
	private:
			int b;
	public:
		B(int b = 0):b{b}{}
		void show(A &a);
		
		void m(A &a){
			//a.v = 21; error!, m ist kein Freund von A
		}
};

class A{
	private:
		int v;
		
	public:
		A(int v = 0):v{v}{}
		//friend class B; Alle Mitglieder der Klasse B haben uneingeschränkter Zugriff auf A-Komponenten !
		friend void B::show(A &a);//Nur Methode show der Klasse B ist mein Freund!
};

void B::show(A &a){
			cout << a.v << endl;//v in A ist private
		}


int main1(){
	cout << "\n in friend_methoden" << endl;
	A aobj{11};
	B bobj;
	bobj.m(aobj);
	cout << "\n in friend_methoden" << endl;
	bobj.show(aobj);
	cout << "\n in friend_methoden" << endl;

	return 0;
}