#pragma once
class Rechteck {
	int a;
	int b;
public:
	int getUmfang();
	int getFlaeche();
	Rechteck(int a, int b) : a(a), b(b) {};
	~Rechteck();
};

