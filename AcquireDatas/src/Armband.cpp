#include "..\include\Armband.h"

using namespace std;

Armband::Armband()
{

}
void Armband::setValueByIndexEmg(int a, double result) {
	switch (a) {
		case 1 : 
			this->EMG1.push_back(result);
			break;
		case 2 : 
			this->EMG2.push_back(result);
			break;
		case 3 : 
			this->EMG3.push_back(result);
			break;
		case 4 : 
			this->EMG4.push_back(result);
			break;
		case 5 : 
			this->EMG5.push_back(result);
			break;
		case 6 : 
			this->EMG6.push_back(result);
			break;
		case 7 : 
			this->EMG7.push_back(result);
			break;
		case 8 : 
			this->EMG8.push_back(result);
			break;
	}
}

vector<double> Armband::getValueByIndexEmg(int a) {
	switch (a) {
	case 1:
		return EMG1;
	case 2:
		return EMG2;
	case 3:
		return EMG3;
	case 4:
		return EMG4;
	case 5:
		return EMG5;
	case 6:
		return EMG6;
	case 7:
		return EMG7;
	case 8:
		return EMG8;
	}
}

std::vector<double> Armband::getValueByIndexGyro(int a) {
	switch (a) {
	case 1:
		return GyroX;
	case 2:
		return GyroY;
	case 3:
		return GyroZ;
	}
}
std::vector<double> Armband::getValueByIndexAcce(int a) {
	switch (a) {
	case 1:
		return AcceX;
	case 2:
		return AcceY;
	case 3:
		return AcceZ;
	}
}
std::vector<double> Armband::getValueByIndexOrien(int a) {
	switch (a) {
	case 1:
		return OrienX;
	case 2:
		return OrienY;
	case 3:
		return OrienZ;
	case 4:
		return OrienW;
	}
}
std::vector<double> Armband::getValueByIndexOrienEuler(int a) {
	switch (a) {
	case 1:
		return OrienEulerR;
	case 2:
		return OrienEulerP;
	case 3:
		return OrienEulerY;
	}
}








void Armband::setValueByIndexAcce(int a, double result) {
	switch (a) {
	case 1 : 
		this->AcceX.push_back(result);
		break;
	case 2 :
		this->AcceY.push_back(result);
		break;
	case 3 : 
		this->AcceZ.push_back(result);
		break;
	}
}


void Armband::setValueByIndexGyro(int a, double result) {
	switch (a) {
	case 1:
		this->GyroX.push_back(result);
		break;
	case 2:
		this->GyroY.push_back(result);
		break;
	case 3:
		this->GyroZ.push_back(result);
		break;
	}
}
void Armband::setValueByIndexOrien(int a, double result) {
	switch (a) {
	case 1:
		this->OrienX.push_back(result);
		break;
	case 2:
		this->OrienY.push_back(result);
		break;
	case 3:
		this->OrienZ.push_back(result);
		break;
	case 4:
		this->OrienZ.push_back(result);
		break;
	}
}

void Armband::setValueByIndexOrienEuler(int a, double result) {
	switch (a) {
	case 1:
		this->OrienEulerR.push_back(result);
		break;
	case 2:
		this->OrienEulerP.push_back(result);
		break;
	case 3:
		this->OrienEulerY.push_back(result);
		break;
	}
}


std::vector<double> Armband::getAcceX() const {
	return AcceX;
}

void Armband::setAcceX(std::vector<double> acceX) {
	AcceX = acceX;
}

std::vector<double> Armband::getAcceY() const {
	return AcceY;
}

void Armband::setAcceY(std::vector<double> acceY) {
	AcceY = acceY;
}

std::vector<double> Armband::getAcceZ() const {
	return AcceZ;
}

void Armband::setAcceZ(std::vector<double> acceZ) {
	AcceZ = acceZ;
}

std::vector<double> Armband::getEmg1() const {
	return EMG1;
}

void Armband::setEmg1(std::vector<double> emg1) {
	EMG1 = emg1;
}

std::vector<double> Armband::getEmg2() const {
	return EMG2;
}

void Armband::setEmg2(std::vector<double> emg2) {
	EMG2 = emg2;
}

std::vector<double> Armband::getEmg3() const {
	return EMG3;
}

void Armband::setEmg3(std::vector<double> emg3) {
	EMG3 = emg3;
}

std::vector<double> Armband::getEmg4() const {
	return EMG4;
}

void Armband::setEmg4(std::vector<double> emg4) {
	EMG4 = emg4;
}

std::vector<double> Armband::getEmg5() const {
	return EMG5;
}

void Armband::setEmg5(std::vector<double> emg5) {
	EMG5 = emg5;
}

std::vector<double> Armband::getEmg6() const {
	return EMG6;
}

void Armband::setEmg6(std::vector<double> emg6) {
	EMG6 = emg6;
}

std::vector<double> Armband::getEmg7() const {
	return EMG7;
}

void Armband::setEmg7(std::vector<double> emg7) {
	EMG7 = emg7;
}

std::vector<double> Armband::getEmg8() const {
	return EMG8;
}

void Armband::setEmg8(std::vector<double> emg8) {
	EMG8 = emg8;
}

std::vector<double> Armband::getGyroX() const {
	return GyroX;
}

void Armband::setGyroX(std::vector<double> gyroX) {
	GyroX = gyroX;
}

std::vector<double> Armband::getGyroY() const {
	return GyroY;
}

void Armband::setGyroY(std::vector<double> gyroY) {
	GyroY = gyroY;
}

std::vector<double> Armband::getGyroZ() const {
	return GyroZ;
}

void Armband::setGyroZ(std::vector<double> gyroZ) {
	GyroZ = gyroZ;
}

std::vector<double> Armband::getOrienW() const {
	return OrienW;
}

void Armband::setOrienW(std::vector<double> orienW) {
	OrienW = orienW;
}

std::vector<double> Armband::getOrienX() const {
	return OrienX;
}

void Armband::setOrienX(std::vector<double> orienX) {
	OrienX = orienX;
}

std::vector<double> Armband::getOrienY() const {
	return OrienY;
}

void Armband::setOrienY(std::vector<double> orienY) {
	OrienY = orienY;
}

std::vector<double> Armband::getOrienZ() const {
	return OrienZ;
}

void Armband::setOrienZ(std::vector<double> orienZ) {
	OrienZ = orienZ;
}





std::vector<double> Armband::getOrienEulerR() const {
	return OrienEulerR;
}

void Armband::setOrienEulerR(std::vector<double> orienEulerR) {
	OrienEulerR = orienEulerR;
}

std::vector<double> Armband::getOrienEulerP() const {
	return OrienEulerP;
}

void Armband::setOrienEulerP(std::vector<double> orienEulerP) {
	OrienEulerP = orienEulerP;
}

std::vector<double> Armband::getOrienEulerY() const {
	return OrienEulerY;
}

void Armband::setOrienEulerY(std::vector<double> orienEulerY) {
	OrienEulerY = orienEulerY;
}