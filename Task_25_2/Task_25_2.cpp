// Task_25_2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	string name{};
	int age;
	bool isFemale;
	bool isAlive;
public:
	Person(string name, int age, bool isFemale, bool isAlive=true) 
		: name{ name }, age{ age }, isFemale{ isFemale }, isAlive{ isAlive }
	{
		//cout << "\nPerson " << name << " erzeugt" << endl;
	};

	Person(const Person& p)
		: name{ p.name }, age{ p.age }, isFemale{ p.isFemale }, isAlive{ p.isAlive }
	{
		cout << "\nPerson " << this->name << " kopiert" << endl;
	};

	~Person() {
		//cout << "\nPerson " << name << " entfernt" << endl;
	};
	bool operator<(const Person&);
	Person operator!() const;
	Person& operator++();
	Person operator++(int);

	friend ostream& operator<<(ostream&, const Person&);
};

bool Person::operator<(const Person& p) {
	return this->age < p.age;
}

Person Person::operator!() const {
	return Person(name, age, isFemale, !isAlive);
}

ostream& operator<<(ostream& os, const Person &p) {
	return os << p.name << " " << p.age << " " << (p.isFemale ? "female" : "male") << " "<< (p.isAlive ? "alive" : "dead");
}

Person& Person::operator++() {
	cout << "\n in ++x" << endl;
	age++;
	return *this;
}

Person Person::operator++(int ) {
	cout << "\n in i++";
	Person tmp = *this;
	++age;
	return tmp;
}



int main() {

	Person p{ "Wondmu", 38, false };
	Person p2{ "Umut", 30, false };
	cout << p << ", " << p2 << endl;//Wondmu 38 Male alive, Umut 30 Male alive
	cout << (p2 < p) << endl;// true bzw 1
	cout << (!p) << endl;// Wondmu 38 Male dead
	cout << (p++) << endl;//Wondmu 38 Male alive
	cout << (++p) << endl;//Wondmu 40 Male alive


	return 0;

}