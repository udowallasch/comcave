#pragma once
#include<string>
#include<vector>
#include"Objekt.h"

class Name : Objekt {
	std::vector<std::string> vorname;
	std::vector<std::string> nachname;
public:
	void setVorname(std::string);
	void setNachname(std::string);
	std::string toString() const override;
	Name(std::string, std::string);
	Name();
	~Name();
};

