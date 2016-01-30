#pragma once
#include <vector>


class Armband
{
public:
	Armband();
	~Armband();
	std::vector<double> getAcceX() const;
	void setAcceX(std::vector<double> acceX);
	std::vector<double> getAcceY() const;
	void setAcceY(std::vector<double> acceY);
	std::vector<double> getAcceZ() const;
	void setAcceZ(std::vector<double> acceZ);
	std::vector<double> getEmg1() const;
	void setEmg1(std::vector<double> emg1);
	std::vector<double> getEmg2() const;
	void setEmg2(std::vector<double> emg2);
	std::vector<double> getEmg3() const;
	void setEmg3(std::vector<double> emg3);
	std::vector<double> getEmg4() const;
	void setEmg4(std::vector<double> emg4);
	std::vector<double> getEmg5() const;
	void setEmg5(std::vector<double> emg5);
	std::vector<double> getEmg6() const;
	void setEmg6(std::vector<double> emg6);
	std::vector<double> getEmg7() const;
	void setEmg7(std::vector<double> emg7);
	std::vector<double> getEmg8() const;
	void setEmg8(std::vector<double> emg8);
	std::vector<double> getGyroX() const;
	void setGyroX(std::vector<double> gyroX);
	std::vector<double> getGyroY() const;
	void setGyroY(std::vector<double> gyroY);
	std::vector<double> getGyroZ() const;
	void setGyroZ(std::vector<double> gyroZ);
	std::vector<double> getOrienW() const;
	void setOrienW(std::vector<double> orienW);
	std::vector<double> getOrienX() const;
	void setOrienX(std::vector<double> orienX);
	std::vector<double> getOrienY() const;
	void setOrienY(std::vector<double> orienY);
	std::vector<double> getOrienZ() const;
	void setOrienZ(std::vector<double> orienZ);

	std::vector<double> getOrienEulerR() const;
	void setOrienEulerR(std::vector<double> orienEulerR);

	std::vector<double> getOrienEulerP() const;
	void setOrienEulerP(std::vector<double> orienEulerP);

	std::vector<double> getOrienEulerY() const;
	void setOrienEulerY(std::vector<double> orienEulerY);


	void setValueByIndexEmg(int a, double result);
	void setValueByIndexAcce(int a, double result);
	void setValueByIndexGyro(int a, double result);
	void setValueByIndexOrien(int a, double result);
	void setValueByIndexOrienEuler(int a, double result);

	std::vector<double> getValueByIndexEmg(int a);
	std::vector<double> getValueByIndexGyro(int a);
	std::vector<double> getValueByIndexAcce(int a);
	std::vector<double> getValueByIndexOrien(int a);
	std::vector<double> getValueByIndexOrienEuler(int a);
private : 

	std::vector<double> EMG1;
	
	std::vector<double> EMG2;
	std::vector<double> EMG3;
	std::vector<double> EMG4;
	std::vector<double> EMG5;
	std::vector<double> EMG6;
	std::vector<double> EMG7;
	std::vector<double> EMG8;

	std::vector<double> AcceX;
	std::vector<double> AcceY;
	std::vector<double> AcceZ;

	std::vector<double> GyroX;
	std::vector<double> GyroY;
	std::vector<double> GyroZ;

	std::vector<double> OrienX;
	std::vector<double> OrienY;
	std::vector<double> OrienZ;
	std::vector<double> OrienW;

	std::vector<double> OrienEulerR;
	std::vector<double> OrienEulerP;
	std::vector<double> OrienEulerY;
};

