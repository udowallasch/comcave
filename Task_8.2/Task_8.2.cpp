// Task_8.2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "Teilnehmer.h"

using std::cout;


int main()
{
//Teilnehmer::Teilnehmer(Mensch m, int k, Datum e, Datum a, bool c, std::string t)

Teilnehmer t1{Mensch{Name{"Udo","Wallasch"}, Mensch::geschlecht::M, Datum{1,Datum::Nov,58}}, 4711, Datum{8,Datum::Jan,2019}, Datum{6,Datum::Mar,2019}, false, "ARGE"};

cout <<t1.getName();
cout << "\n" << t1.getGeburtstag().toString(dotDat{});
cout << "\n" << t1.getGeburtstag().toString(slashDat{});
cout << "\n" << t1.getGeburtstag().toString(isoDat{});

}

