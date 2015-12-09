#include "..\include\Acquisition.h"



Acquisition::Acquisition()
{
	this->left = new Armband();
	this->right = new Armband();	
}

Acquisition::~Acquisition() {
	delete left;
	delete right;
}

void Acquisition::setIDLeft(int id) {
	this->leftId = id;
}

void Acquisition::setIDRight(int id) {
	this->rightId = id;
}

Armband * Acquisition::getArmbandByID(int id) {
	if (id == this->leftId) {
		return left;
	}
	else {
		return right;
	}
}

Armband * Acquisition::getArmband(std::string side) {
	if (side == "left") {
		return left;
	}
	else {
		return right;
	}
}
