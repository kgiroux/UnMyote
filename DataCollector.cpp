// Copyright (C) 2013-2014 Thalmic Labs Inc.
// Distributed under the Myo SDK license agreement. See LICENSE.txt for details.
// This sample illustrates how to log EMG and IMU data. EMG streaming is only supported for one Myo at a time, and this entire sample is geared to one armband

#define _USE_MATH_DEFINES

#include "DataCollector.h"


DataCollector::DataCollector()
{
	openFiles();
}

	
	
void DataCollector:: openFiles() {
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

void DataCollector::initFileName(){
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
void DataCollector::onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg)
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
void DataCollector::checkOrientation(float x, float y, float z, float w) {

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
void DataCollector::onOrientationData(myo::Myo *myo, uint64_t timestamp, const myo::Quaternion< float > &rotation) {
		
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
void DataCollector::onAccelerometerData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &accel) {
	printVectorAcce(timestamp, accel);
	//printVector(accelerometerFile, timestamp, accel);

}

// onGyroscopeData is called whenever new gyroscope data is provided
// Be warned: This will not make any distiction between data from other Myo armbands
void DataCollector::onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro) {
	printVectorGyro(timestamp, gyro);
		
	//printVector(gyroFile, timestamp, gyro);

}

void DataCollector::onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion) {
	//Reneable streaming
	myo->setStreamEmg(myo::Myo::streamEmgEnabled);
	//openFiles();
}

// Helper to print out accelerometer and gyroscope vectors
void DataCollector::printVector(std::ofstream &file, uint64_t timestamp, const myo::Vector3< float > &vector) {
	file << timestamp
		<< ',' << vector.x()
		<< ',' << vector.y()
		<< ',' << vector.z()
		<< std::endl;
}

void DataCollector::printVectorGyro(uint64_t timestamp, const myo::Vector3< float > &vector) {
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

void DataCollector::printVectorAcce(uint64_t timestamp, const myo::Vector3< float > &vector) {
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


void DataCollector::end(){
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
