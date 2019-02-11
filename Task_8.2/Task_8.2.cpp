// Task_8.2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "Teilnehmer.h"

using std::cout;


int main()
{
//Teilnehmer::Teilnehmer(Mensch m, int k, Datum e, Datum a, bool c, std::string t)
Teilnehmer t1{Mensch{Name{"Bruno","Mustermann"}, Mensch::geschlecht::M, Datum{1,Datum::Apr,1911}}, 4711, Datum{8,Datum::Jan,2019}, Datum{6,Datum::Mar,2019}, false, "ARGE"};
t1.getName().addVorname("Karl");
cout << t1.getName().toString();
cout << "\n" << t1.getGeburtstag().toString(dotDat{});
cout << "\n" << t1.getGeburtstag().toString(slashDat{});
cout << "\n" << t1.getGeburtstag().toString(isoDat{});

//Adresse::Adresse(std::string l, std::string p, std::string g, std::string s, std::string h)
t1.setAdresse(Adresse{ "D","112233","MusterStadt","Musterstrasse", "13" });
t1.setEmail("Bruno.Mustermann@xyz.de");
t1.setTelefon(Telefon{ "04711-1234","123-456" });

cout << "\nAdresse: " << t1.getAdresse().toString();

cout << "\n" << t1.toString();

}

