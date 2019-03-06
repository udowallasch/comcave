#include "pch.h"
#include<iostream>
#include<sstream>
#include "aufgabe4.h"


using namespace std;

	class Adresse {
	private:
		int Wohnungsnummer;
		string Strasse;
		int PLZ;
		string Ort;

	public:
		Adresse(int w = 0, string s = "", int p = 0, string o="")
			:
			Wohnungsnummer{w},
			Strasse{s},
			PLZ{p},
			Ort{o}
		{}


		int getWohnungsnummer() const {	return Wohnungsnummer;}
		string getStrasse() const { return Strasse; }
		int getPLZ() const { return PLZ; };
		string getOrt() const { return Ort; };

		void setWohnungsnummer(int w)  {  Wohnungsnummer = w; }
		void setStrasse(string s)  {  Strasse = s; }
		void setPLZ(int p)  {  PLZ = p; };
		void setOrt(string o) { Ort = o; };

		friend std::ostream& operator<<(std::ostream &, Adresse&);
		friend bool operator==( Adresse&, Adresse&);
	};


	std::ostream& operator<<(std::ostream &os , Adresse& a) {
		return os  <<"Wohnungsnummer: " << a.Wohnungsnummer \
			<< "Strasse und Nummer: " << a.Strasse\
			<< "PLZ Ort: " << a.PLZ << " " << a.Ort;
	} 

	bool operator==(Adresse& a, Adresse& b) {
		return(a.PLZ == b.PLZ \
			&& a.Ort == b.Ort \
			&& a.Strasse == b.Strasse \
			&& a.Wohnungsnummer == b.Wohnungsnummer);
	}

	class Eigentuemer{
	private:
		string Anrede;
		string Name;
	public:
		Eigentuemer(string a="Herr", string n=""): Anrede{a},Name{n}{}
		string getAnrede() const { return Anrede; }
		string getName() const { return Name; }
		void setAnrede(string a) { Anrede = a; }
		void setName(string n) { Name = n; }

		friend std::ostream& operator<<(std::ostream &, Eigentuemer&);
		friend bool operator==(Eigentuemer&, Eigentuemer&);

	};


	std::ostream& operator<<(std::ostream &is, Eigentuemer& a) {
		return is << a.Anrede << " " << a.Name;
	}

	bool operator==(Eigentuemer& a, Eigentuemer& b) {
		return(a.Anrede == b.Anrede && a.Name == b.Name );
	}



	class Wohnung {
	private:
		Eigentuemer eigentuemer;
		bool vermietet;
		Adresse adresse;
		int Baujahr;
		double Nebenkosten;
	public:
		Wohnung(Eigentuemer e, bool v, Adresse a, int bj, double nk)
			:
			eigentuemer{e},
			adresse{a},
			Baujahr{bj},
			Nebenkosten{nk}
		{}

		Eigentuemer getEigentuemer() const { return eigentuemer; }
		bool istVermietet() const { return vermietet; }
		Adresse getAdresse() const { return adresse; }
		int getBaujahr() const { return Baujahr; }
		double getNebenkosten() const { return Nebenkosten; }
		void  setEigentuemer(Eigentuemer e)  { eigentuemer = e; }
		void setVermietet(bool v)  {  vermietet = v; }
		void setAdresse(Adresse a)  {  adresse = a; }
		void setBaujahr(int bj)  {  Baujahr = bj; }
		void setNebenkosten(double nk)  {  Nebenkosten = nk; }

		friend std::ostream& operator<<(std::ostream &os, Wohnung& w) {
			return os << w.eigentuemer << " " << w.adresse << " vermietet: " << w.vermietet << " Baujahr: " << w.Baujahr << " Nebenkosten: " << w.Nebenkosten;
		}

		friend bool operator==(Wohnung& a, Wohnung& b) {
			return (a.adresse == b.adresse \
				&& a.eigentuemer == b.eigentuemer \
				&& a.Baujahr == b.Baujahr);
		}


	};

	void printWohnungen(Wohnung* w, int len) {
		for (int i = 0; i < len; i++) {
			std::cout << w[i] << endl;//Fehlerhaft abgegeben ! : *w
		}
	}

void aufgabe4::run() {
	cout << "aufgabe 4 ----------------------------------------" << endl;

	Wohnung w1{ Eigentuemer{"Herr","Meier"},true,Adresse{1,"strasse 1",4711,"irgendwo"},1970,150.99 };
	Wohnung w2{ Eigentuemer{"Herr","Mueller"},true,Adresse{2,"strasse 1",4711,"irgendwo"},1970,150.99 };
	Wohnung w3{ Eigentuemer{"Frau","Mueller"},true,Adresse{3,"strasse 4",4711,"irgendwo"},1970,150.99 };
	Wohnung w4{ Eigentuemer{"Herr","Mueller"},true,Adresse{4,"strasse 1",4711,"irgendwo"},1970,150.99 };
	Wohnung w5{ Eigentuemer{"Frau","Mueller"},true,Adresse{5,"strasse 4",4711,"irgendwo"},1970,150.99 };

	Wohnung w[] = { w1,w2,w3,w4,w5 };
	printWohnungen(w,5);
}

aufgabe4::aufgabe4() {}
aufgabe4::~aufgabe4() {}
