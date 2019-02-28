#include <cmath>
#include <iostream>
#include <array>
#include <vector>
#include <string>

/**
Aufgabe:
1. Fehler beheben
*/

using namespace std;


class Point{
	private:
		double x;
		double y;
	public:
		Point(double x, double y) : x{x},y{y}{}
};

class Figure{
	protected:
		Point p;
		Figure(Point p) :p{ p } {};
public:
	virtual double area() const { cout << "area aus f\n"; return 0; }

};


class Circle : public Figure{
	private:
		double radius;
	public:
		Circle(Point p, double radius) : Figure {p}, radius{radius}{}
		double area() const override {return 3.14 * pow(radius, 2);}
		double circumference() const {return 2 * 3.14 * radius;}
};

class Rectangle : public Figure{
	private:
		double breite;
		double laenge;
	public:
		Rectangle(Point p, double breite, double laenge) : Figure{p}, breite{breite}, laenge{laenge}{}
		double area() const {return breite * laenge;}
		double circumference() const {return 2 * (breite + laenge);}
};
/**
Schreibt eine Funktion getFlaeche, die den Flächeninhalt eines Gebiets (besteht aus Rectangles und Circles) brerechnet unr zurück gibt
*/

double getFlaeche(Figure** f,int length) {
	double ff{ 0 };
	for (int i = 0; i < length; i++) {
		//ff += f[i]->area();
		ff += (*f++)->area();
	}
	return ff;
}

double getFlaeche(vector<Figure*>& v) {
	double ff{ 0 };
	for (auto it : v) {
		ff += (*it).area();
	}
	return ff;
}

int main1(){
	//testet Eure Funktion getFlaeche
	Rectangle r1{ Point(1, 2), 3, 4 };
	Rectangle r2{ Point(1, 2), 3, 4 };
	Rectangle r3{ Point(1, 2), 3, 4 };
	Circle c1{ Point(0, 0), 1 };
	Circle c2{ Point(0, 0), 1 };

	Figure* g[]= { &r1,&r2,&r3,&c1,&c2 };

	cout << "\nFlaeche ist: " << getFlaeche(g, 5) << endl;
	
	vector <Figure*> gebiet{};

	gebiet.push_back(new Rectangle{ Point(1, 2), 3, 4 });
	gebiet.push_back(new Rectangle{ Point(1, 2), 3, 4 });
	gebiet.push_back(new Rectangle{ Point(1, 2), 3, 4 });
	gebiet.push_back(new Circle{ Point(0, 0), 1 });
	gebiet.push_back(new Circle{ Point(0, 0), 1 });

	cout << "\nFlaeche ist: " << getFlaeche(gebiet) << endl;

	Figure f = r1;
	cout << "\nf: " << f.area();
	Figure * rf = &r1;
	cout << "\nrf: " << rf->area();
	return 0;
}
