// Copyright (C) 2013-2014 Thalmic Labs Inc.
// Distributed under the Myo SDK license agreement. See LICENSE.txt for details.

// This sample illustrates how to log EMG and IMU data. EMG streaming is only supported for one Myo at a time, and this entire sample is geared to one armband

#define _USE_MATH_DEFINES
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
#include "tinyxml2.h"
#include <direct.h>
#include "./include/myo/myo.hpp"
using namespace tinyxml2;
class DataCollector : public myo::DeviceListener {
public:
	DataCollector()
	{
		openFiles();
	}
	std::string namefile; 
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

	int previous_x;
	int previous_y;
	int previous_z;
	int previous_w;
	void openFiles() {
		time_t timestamp = std::time(0);
		std::stringstream ss;
		ss << timestamp;
		//create result folder
		_mkdir("./result");
		std::string pathToFolder = "./result/exc" + ss.str();
		// create excution folder in result
		_mkdir(pathToFolder.c_str());

		// Init XML Element and reset Name file
		initFileName();

		// Define file name
		emgFileString << pathToFolder << "/" << "emg-" << timestamp << ".xml";
		gyroFileString << pathToFolder << "/" << "gyro-" << timestamp << ".xml";
		accelerometerFileString << pathToFolder << "/" << "accelerometer-" << timestamp << ".xml";
		orientationFileString << pathToFolder << "/" << "orientation-" << timestamp << ".xml";
		orientationEulerFileString << pathToFolder << "/" << "orientationEuler-" << timestamp << ".xml";

	}

	void initFileName(){
		datatoStoreEMG = doc.NewElement("data");
		datatoStoreGYRO = doc.NewElement("data");
		datatoStoreACCE = doc.NewElement("data");
		datatoStoreORIEN = doc.NewElement("data");
		datatoStoreORIENEULER = doc.NewElement("data");
		emgFileString.str("");
		emgFileString.clear();
		gyroFileString.str("");
		gyroFileString.clear();
		accelerometerFileString.str("");
		accelerometerFileString.clear();
		orientationEulerFileString.str("");
		orientationEulerFileString.clear();
		orientationFileString.str("");
		orientationFileString.clear();
	}


	// onEmgData() is called whenever a paired Myo has provided new EMG data, and EMG streaming is enabled.
	void onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg)
	{
		XMLElement * timestampElem = doc.NewElement("timestamp");
		std::stringstream sstimestamp;
		sstimestamp << timestamp;

		timestampElem->SetAttribute("time", sstimestamp.str().c_str());

		//emgFile << timestamp;
		for (size_t i = 0; i < 8; i++) {
			std::stringstream ss;
			ss << i;
			std::string nameElement = "emg" + ss.str();
			XMLElement * emgData = doc.NewElement(nameElement.c_str());
			std::stringstream ssdata; 
			ssdata << static_cast<int>(emg[i]);
			emgData->SetText(ssdata.str().c_str());
			timestampElem->InsertEndChild(emgData);
		}

		datatoStoreEMG->InsertEndChild(timestampElem);
		

		//emgFile << std::endl;
	}
	void checkOrientation(float x, float y, float z, float w) {

		std::cout << "rotation x :" << x << std::endl;
		std::cout << "rotation y :" << y << std::endl;
		std::cout << "rotation z :" << z << std::endl;
		std::cout << "rotation w :" << w << std::endl;

		if (previous_x < (x)) {
			std::cout << "left" << std::endl;
			}
		else {
			std::cout << "right" << std::endl;
		}

		previous_x = x;


		if (previous_y < (y) ){
				
		}
		else {

		}

		if (previous_z < (z)) {

		}
		else {

		}

		if (previous_w < (w)) {

		}
		else {

		}
	}

	


	// onOrientationData is called whenever new orientation data is provided
	// Be warned: This will not make any distiction between data from other Myo armbands
	void onOrientationData(myo::Myo *myo, uint64_t timestamp, const myo::Quaternion< float > &rotation) {
		
		XMLElement * timestampElem = doc.NewElement("timestamp");
		std::stringstream sstring;
		sstring.str("");
		sstring.clear();
		sstring << timestamp;
		timestampElem->SetAttribute("time", sstring.str().c_str());
		

		checkOrientation(rotation.x(), rotation.y(), rotation.z(), rotation.w());


		XMLElement * xElem = doc.NewElement("X");
		sstring.str("");
		sstring.clear();
		sstring << rotation.x();
		xElem->SetText(sstring.str().c_str());
		XMLElement * yElem = doc.NewElement("Y");
		sstring.str("");
		sstring.clear();
		sstring << rotation.y();
		yElem->SetText(sstring.str().c_str());
		XMLElement * zElem = doc.NewElement("Z");
		sstring.str("");
		sstring.clear();
		sstring << rotation.z();
		zElem->SetText(sstring.str().c_str());
		XMLElement * wElem = doc.NewElement("W");
		sstring.str("");
		sstring.clear();
		sstring << rotation.w();
		wElem->SetText(sstring.str().c_str());

		timestampElem->InsertEndChild(xElem);
		timestampElem->InsertEndChild(yElem);
		timestampElem->InsertEndChild(zElem);
		timestampElem->InsertEndChild(wElem);

		datatoStoreORIEN->InsertEndChild(timestampElem);

		using std::atan2;
		using std::asin;
		using std::sqrt;
		using std::max;
		using std::min;

		// Calculate Euler angles (roll, pitch, and yaw) from the unit quaternion.
		float roll = atan2(2.0f * (rotation.w() * rotation.x() + rotation.y() * rotation.z()),
			1.0f - 2.0f * (rotation.x() * rotation.x() + rotation.y() * rotation.y()));
		float pitch = asin(max(-1.0f, min(1.0f, 2.0f * (rotation.w() * rotation.y() - rotation.z() * rotation.x()))));
		float yaw = atan2(2.0f * (rotation.w() * rotation.z() + rotation.x() * rotation.y()),
			1.0f - 2.0f * (rotation.y() * rotation.y() + rotation.z() * rotation.z()));
		
		
		sstring.clear();


		XMLElement * timestampElemEuler = doc.NewElement("timestamp");
		sstring.str("");
		sstring.clear();
		sstring << timestamp;
		timestampElemEuler->SetAttribute("time", sstring.str().c_str());

		XMLElement * rollElem = doc.NewElement("roll");
		sstring.str("");
		sstring.clear();
		sstring << roll;
		rollElem->SetText(sstring.str().c_str());
		XMLElement * pitchElem = doc.NewElement("pitch");
		sstring.str("");
		sstring.clear();
		sstring << pitch;
		pitchElem->SetText(sstring.str().c_str());
		XMLElement * yawElem = doc.NewElement("yaw");
		sstring.str("");
		sstring.clear();
		sstring << yaw;
		yawElem->SetText(sstring.str().c_str());

		timestampElemEuler->InsertEndChild(rollElem);
		timestampElemEuler->InsertEndChild(pitchElem);
		timestampElemEuler->InsertEndChild(yawElem);

		datatoStoreORIENEULER->InsertEndChild(timestampElemEuler);
	}

	// onAccelerometerData is called whenever new acceleromenter data is provided
	// Be warned: This will not make any distiction between data from other Myo armbands
	void onAccelerometerData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &accel) {
		printVectorAcce(timestamp, accel);
		//printVector(accelerometerFile, timestamp, accel);

	}

	// onGyroscopeData is called whenever new gyroscope data is provided
	// Be warned: This will not make any distiction between data from other Myo armbands
	void onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro) {
		printVectorGyro(timestamp, gyro);
		
		//printVector(gyroFile, timestamp, gyro);

	}

	void onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion) {
		//Reneable streaming
		myo->setStreamEmg(myo::Myo::streamEmgEnabled);
		//openFiles();
	}

	// Helper to print out accelerometer and gyroscope vectors
	void printVector(std::ofstream &file, uint64_t timestamp, const myo::Vector3< float > &vector) {
		file << timestamp
			<< ',' << vector.x()
			<< ',' << vector.y()
			<< ',' << vector.z()
			<< std::endl;
	}

	void printVectorGyro(uint64_t timestamp, const myo::Vector3< float > &vector) {
		XMLElement * timestampElem = doc.NewElement("timestamp");
		std::stringstream sstring;
		sstring << timestamp;
		timestampElem->SetAttribute("time", sstring.str().c_str());
		XMLElement * xElem = doc.NewElement("X");
		sstring.str("");
		sstring.clear();
		sstring << vector.x();
		xElem->SetText(sstring.str().c_str());
		XMLElement * yElem = doc.NewElement("Y");
		sstring.str("");
		sstring.clear();
		sstring << vector.y();
		yElem->SetText(sstring.str().c_str());
		XMLElement * zElem = doc.NewElement("Z");
		sstring.str("");
		sstring.clear();
		sstring << vector.z();
		zElem->SetText(sstring.str().c_str());

		timestampElem->InsertEndChild(xElem);
		timestampElem->InsertEndChild(yElem);
		timestampElem->InsertEndChild(zElem);

		datatoStoreGYRO->InsertEndChild(timestampElem);

	}

	void printVectorAcce(uint64_t timestamp, const myo::Vector3< float > &vector) {
		XMLElement * timestampElem = doc.NewElement("timestamp");
		std::stringstream sstring;
		sstring << timestamp;
		timestampElem->SetAttribute("time", sstring.str().c_str());
		XMLElement * xElem = doc.NewElement("X");
		sstring.str("");
		sstring.clear();
		sstring << vector.x();
		xElem->SetText(sstring.str().c_str());
		XMLElement * yElem = doc.NewElement("Y");
		sstring.str("");
		sstring.clear();
		sstring << vector.y();
		yElem->SetText(sstring.str().c_str());
		XMLElement * zElem = doc.NewElement("Z");
		sstring.str("");
		sstring.clear();
		sstring << vector.z();
		zElem->SetText(sstring.str().c_str());

		timestampElem->InsertEndChild(xElem);
		timestampElem->InsertEndChild(yElem);
		timestampElem->InsertEndChild(zElem);

		datatoStoreACCE->InsertEndChild(timestampElem);

	}


	void end(){
		doc.InsertFirstChild(datatoStoreEMG);
		doc.SaveFile(emgFileString.str().c_str());
		datatoStoreEMG->DeleteChildren();
		doc.DeleteChildren();

		doc.InsertFirstChild(datatoStoreACCE);
		doc.SaveFile(accelerometerFileString.str().c_str());
		datatoStoreACCE->DeleteChildren();
		doc.DeleteChildren();

		doc.InsertFirstChild(datatoStoreGYRO);
		doc.SaveFile(gyroFileString.str().c_str());
		datatoStoreGYRO->DeleteChildren();
		doc.DeleteChildren();

		doc.InsertFirstChild(datatoStoreORIEN);
		doc.SaveFile(orientationFileString.str().c_str());
		datatoStoreORIEN->DeleteChildren();
		doc.DeleteChildren();

		doc.InsertFirstChild(datatoStoreORIENEULER);
		doc.SaveFile(orientationEulerFileString.str().c_str());
		datatoStoreORIENEULER->DeleteChildren();
		doc.DeleteChildren();


		
	}

	// The files we are logging to
	std::ofstream emgFile;
	std::ofstream gyroFile;
	std::ofstream orientationFile;
	std::ofstream orientationEulerFile;
	std::ofstream accelerometerFile;

};

int main(int argc, char** argv)
{
	// We catch any exceptions that might occur below -- see the catch statement for more details.
	try {

		// First, we create a Hub with our application identifier. Be sure not to use the com.example namespace when
		// publishing your application. The Hub provides access to one or more Myos.
		myo::Hub hub("com.undercoveryeti.myo-data-capture");
		std::cout << "Attempting to find a Myo..." << std::endl;

		// Next, we attempt to find a Myo to use. If a Myo is already paired in Myo Connect, this will return that Myo
		// immediately.
		// waitForMyo() takes a timeout value in milliseconds. In this case we will try to find a Myo for 10 seconds, and
		// if that fails, the function will return a null pointer.
		myo::Myo* myo = hub.waitForMyo(10000);

		// If waitForMyo() returned a null pointer, we failed to find a Myo, so exit with an error message.
		if (!myo) {
			throw std::runtime_error("Unable to find a Myo!");
		}

		// We've found a Myo.
		std::cout << "Connected to a Myo armband! \nLogging to the file system. \nCheck your home folder or the folder this application lives in.\n" << std::endl << std::endl;

		// Next we enable EMG streaming on the found Myo.
		myo->setStreamEmg(myo::Myo::streamEmgEnabled);

		// Next we construct an instance of our DeviceListener, so that we can register it with the Hub.
		DataCollector collector;
		// Hub::addListener() takes the address of any object whose class inherits from DeviceListener, and will cause
		// Hub::run() to send events to all registered device listeners.
		hub.addListener(&collector);
		int compteur = 0;
		// Finally we enter our main loop.
		while (compteur != 10000) {
			// In each iteration of our main loop, we run the Myo event loop for a set number of milliseconds.
			// In this case, we wish to update our display 50 times a second, so we run for 1000/20 milliseconds.
			hub.run(1);
			//collector.onEmgData();
			compteur++;
			//std::cout <<"compteur : "<< compteur << std::endl;
		}
		collector.end();

		system("pause");
		// If a standard exception occurred, we print out its message and exit.
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << "Press enter to continue.";
		std::cin.ignore();
		return 1;
	}
}
