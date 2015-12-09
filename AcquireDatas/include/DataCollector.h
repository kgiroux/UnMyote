#pragma once
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <array>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <time.h>
#include <direct.h>
#include "myo/myo.hpp"
#include "tinyxml2.h"
#include "Acquisition.h"
#include "XmlStorage.h"

using namespace tinyxml2;

class DataCollector : public myo::DeviceListener
{
	public:
		DataCollector(std::string name, bool emg, bool accel, bool gyro, bool orient, bool eulerOrient, bool dualMode);
		void checkOrientation(float x, float y, float z, float w);
		void onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg);
		void initFileName();
		void openFiles(std::string name);
		void onOrientationData(myo::Myo *myo, uint64_t timestamp, const myo::Quaternion< float > &rotation);
		void onAccelerometerData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &accel);
		void onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro);
		void onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion);
		void printVector(std::ofstream &file, uint64_t timestamp, const myo::Vector3< float > &vector);
		void printVectorGyro(uint64_t timestamp, const myo::Vector3< float > &vector);
		void printVectorAcce(uint64_t timestamp, const myo::Vector3< float > &vector);
		size_t identifyMyo(myo::Myo* myo);
		void onPair(myo::Myo* myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion);
		void onArmSync(myo::Myo * 	myo, uint64_t 	timestamp, myo::Arm 	arm, myo::XDirection 	xDirection, float 	rotation, myo::WarmupState 	warmupState);
		void end();

		bool isMesureAccel() const;
		void setMesureAccel(bool mesureAccel);
		bool isMesureElorient() const;
		void setMesureElorient(bool mesureElorient);
		bool isMesureEmg() const;
		void setMesureEmg(bool mesureEmg);
		bool isMesureGyro() const;
		void setMesureGyro(bool mesureGyro);
		bool isMesureOrient() const;
		void setMesureOrient(bool mesureOrient);
		const std::string& getName() const;
		void setName(const std::string& name);


	private:
		Acquisition acq;
		XMLDocument doc;
		XMLElement * datatoStoreGYRO;
		XMLElement * datatoStoreACCE;
		XMLElement * datatoStoreORIEN;
		XMLElement * datatoStoreORIENEULER;
		XMLElement * datatoStoreEMG;
		std::ostringstream emgFileString;
		std::ostringstream gyroFileString;
		std::ostringstream accelerometerFileString;
		std::ostringstream orientationFileString;
		std::ostringstream orientationEulerFileString;

		// The files we are logging to
		std::ofstream emgFile;
		std::ofstream gyroFile;
		std::ofstream orientationFile;
		std::ofstream orientationEulerFile;
		std::ofstream accelerometerFile;
		int previous_x;
		int previous_y;
		int previous_z;
		int previous_w;
		std::vector<myo::Myo*> knownMyos;

		//Mesurement control
		bool mesureEMG;
		bool mesureGYRO;
		bool mesureORIENT;
		bool mesureELORIENT;
		bool mesureACCEL;
		std::string name;
};