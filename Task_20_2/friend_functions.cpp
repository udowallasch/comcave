#include <iostream>
using namespace std;
/**
Motivation:
			-Encapsulation (Information hiding, Geheimnisprinzip): Bestimmte Komponente einer Klasse private deklarieren
			->Außen stehende (non-member) haben dann auf solche Komponente keinen Zugriff (access)
			->Außen stehende: non-member functions, main() -Funktion = client code, andere Klassen
Was bezweckt man mit Freunde?

			-Einen Zugriff auf private Komponenten (violates encapsulation???)
*/
class Lager{
	private:
		int stand;
	public:	
			Lager(int stand = 0):stand{stand}{}
			void add(int stand){ this->stand+= stand; }
			//int getStand(){ return stand;}
			friend void f (Lager &);
};

//

void f(Lager &t){//Lager ist kein primitiver DT, deshalb call by referenz wird empfohlen
		//this->stand = 1; error!!!
		t.stand = 0;
}

int add (int a, int b);
int main2(){
	Lager x{50};
	f(x);
	add(5, 9);
	return 0;
}

int add (int x, int y){
	return x +y;
}