#pragma once
#include "Armband.h"

class Acquisition
{
public:
	Acquisition();
	~Acquisition();
	Armband * getArmbandByID(int id);
	Armband * getArmband(std::string side);
	void setIDLeft(int id);
	void setIDRight(int id);

private : 
	int leftId;
	int rightId;
	Armband * left;
	Armband * right;
};

