#ifndef OBJEKT_H
#define OBJEKT_H
#pragma once
#include<string> 

class Objekt {
public:
	virtual std::string toString() const = 0;
	Objekt();
	~Objekt();
};

#endif