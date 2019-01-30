// Vererbung.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//Udo Wallasch

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;


class Fahrzeug {
public:
	enum class MEDIUM { W, L, A, n };//W: Wasser, L: Land, A: Air, n: unbekannt
	Fahrzeug(MEDIUM m, int vm = 0, int vc = 0) : medium(m), vMax(vm), vCur(vc) { myid = instanceCount++; }
	virtual ~Fahrzeug() { cout << "delete Fahrzeug id: "<< myid <<"\n"; }

	void setVcur(int v) { vCur = v; }
	int getVcur() { return vCur; }
	int getVmax() { return vMax; }
	virtual void drucke() { cout << "id: "<< myid <<" medium: " << (int)medium << " vMax: " << vMax << " vCur: " << vCur ; }
protected:
	MEDIUM const medium{ MEDIUM::n };

private:
	//MEDIUM const medium;
	static unsigned int instanceCount;
	int  const vMax;
	int vCur;
	unsigned int myid;
};

//ganz wichtig: das static attribute muss hier initialisert werden, sonst gibt's einen Linker-Fehler
//(externe Referenz auf instanceCount kann nicht aufgelöst werden!!!
unsigned int Fahrzeug::instanceCount = 0; 



class WasserFahrzeug :  public Fahrzeug {
public:
	static size_t instanceCount;
	enum class TYPE { S, M,n };//S: segler, M: Motorboot, n: no type
	WasserFahrzeug(TYPE t = TYPE::n, int vm = 0) : Fahrzeug(MEDIUM::W, vm), type(t) {}

	void drucke() { Fahrzeug::drucke(); cout << " type: " << (int)type; }

	static WasserFahrzeug create(TYPE t, int vm) { return (WasserFahrzeug(t, vm)); }
	
//privat nach public wg. Vorwärtsdeklaration von TYPE
private:
	TYPE const type{ TYPE::n };
};

class LandFahrzeug : Fahrzeug {
public:
	enum class TYPE { P, L, M, n };//P: PKW, L: LKW, M: Motorrad, n: no type
	LandFahrzeug(TYPE t = TYPE::n, int vm = 0) : Fahrzeug(MEDIUM::L,vm), type(t) { }

	void drucke() { Fahrzeug::drucke(); cout << " type: " << (int)type <<" medium : "<< (int)medium; }
	int getAnzahlRaeder() { return raeder; }
	char getMotorTyp() { return motor; }

//privat nach public wg. Vorwärtsdeklaration von TYPE
private:
	int raeder;
	char motor;
	TYPE const type;
};

int main()
{


	WasserFahrzeug boot1(WasserFahrzeug::TYPE::S);
	WasserFahrzeug boot2(WasserFahrzeug::TYPE::M,25);
	LandFahrzeug auto1(LandFahrzeug::TYPE::P,120);
	LandFahrzeug auto2(LandFahrzeug::TYPE::M,200);

	Fahrzeug * pF1 = &boot1;
	//Fahrzeug * pf2 = &auto1; geht nicht, da Verbung nicht public
	LandFahrzeug * pf2 = &auto1;
	// pf2->getVcur(); geht nicht, da Verbung nicht public
	pf2->drucke(); cout << "\n";

	boot1.drucke(); cout<<"\n";
	boot2.drucke(); cout << "\n";
	auto1.drucke(); cout << "\n";
	auto2.drucke(); cout << "\n";

	LandFahrzeug *auto3 = new LandFahrzeug(LandFahrzeug::TYPE::L, 88);
	auto3->drucke(); cout << "\n";
	//muss explizit gerufen werden! (wg. 'new')
	delete(auto3);
}

