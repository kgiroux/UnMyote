// Copyright (C) 2013-2014 Thalmic Labs Inc.
// Distributed under the Myo SDK license agreement. See LICENSE.txt for details.
// This sample illustrates how to log EMG and IMU data. EMG streaming is only supported for one Myo at a time, and this entire sample is geared to one armband
#define _USE_MATH_DEFINES

#include "..\include\DataCollector.h"
DataCollector::DataCollector()
{
}


void DataCollector:: openFiles(std::string name)
{
	time_t timestamp = std::time(0);
	//create result folder
	_mkdir("./result");
	std::string pathToFolder = "./result/" + name;
	// create excution folder in result
	_mkdir(pathToFolder.c_str());

	// Init XML Element and reset Name file
	initFileName();

	// Define file name
	emgFileString << pathToFolder << "/" <<"FileResult"<< timestamp << ".xml";

}

void DataCollector::initFileName()
{
	datatoStoreEMG = doc.NewElement("emgs");
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
	if (run) {
		if (mesureEMG)
		{
			//acq.getArmbandByID()
			size_t id = identifyMyo(myo);
			for (size_t i = 0; i < 8; i++) {
				acq.getArmbandByID(id)->setValueByIndexEmg(i, emg[i]);
			}
		}
	}
}
void DataCollector::checkOrientation(float x, float y, float z, float w) 
{
}

size_t DataCollector ::identifyMyo(myo::Myo* myo) {
	// Walk through the list of Myo devices that we've seen pairing events for.
	for (size_t i = 0; i < knownMyos.size(); ++i) {
		// If two Myo pointers compare equal, they refer to the same Myo device.
		if (knownMyos[i] == myo) {
			return i + 1;
		}
	}

	return 0;
}


// onOrientationData is called whenever new orientation data is provided
// Be warned: This will not make any distiction between data from other Myo armbands
void DataCollector::onOrientationData(myo::Myo *myo, uint64_t timestamp, const myo::Quaternion< float > &rotation) 
{
	if (run) {
		if (mesureORIENT)
		{
			size_t id = identifyMyo(myo);
			acq.getArmbandByID(id)->setValueByIndexOrien(1, rotation.x());
			acq.getArmbandByID(id)->setValueByIndexOrien(2, rotation.y());
			acq.getArmbandByID(id)->setValueByIndexOrien(3, rotation.z());
			acq.getArmbandByID(id)->setValueByIndexOrien(4, rotation.w());
		}

		using std::atan2;
		using std::asin;
		using std::sqrt;
		using std::max;
		using std::min;

		if (mesureELORIENT)
		{
			// Calculate Euler angles (roll, pitch, and yaw) from the unit quaternion.
			float roll = atan2(2.0f * (rotation.w() * rotation.x() + rotation.y() * rotation.z()),
				1.0f - 2.0f * (rotation.x() * rotation.x() + rotation.y() * rotation.y()));
			float pitch = asin(max(-1.0f, min(1.0f, 2.0f * (rotation.w() * rotation.y() - rotation.z() * rotation.x()))));
			float yaw = atan2(2.0f * (rotation.w() * rotation.z() + rotation.x() * rotation.y()),
				1.0f - 2.0f * (rotation.y() * rotation.y() + rotation.z() * rotation.z()));

			size_t id = identifyMyo(myo);
			acq.getArmbandByID(id)->setValueByIndexOrienEuler(1, roll);
			acq.getArmbandByID(id)->setValueByIndexOrienEuler(2, pitch);
			acq.getArmbandByID(id)->setValueByIndexOrienEuler(3, yaw);
		}
	}
}

void DataCollector::onArmSync(myo::Myo * 	myo, uint64_t 	timestamp, myo::Arm 	arm, myo::XDirection 	xDirection,float 	rotation, myo::WarmupState 	warmupState) {
	while (warmupState != myo::warmupStateWarm) {
		if (arm == myo::armLeft) {
			std::cout << "Left" << std::endl;
			acq.setIDLeft(identifyMyo(myo));
			//myo->notifyUserAction();
		}
		else {

			std::cout << "Right" << std::endl;
			acq.setIDRight(identifyMyo(myo));
			//myo->notifyUserAction();
		}
	}
	if (arm == myo::armLeft) {
		std::cout << "Left" << std::endl;
		acq.setIDLeft(identifyMyo(myo));
	}
	else {

		std::cout << "Right" << std::endl;
		acq.setIDRight(identifyMyo(myo));
	}

}


// onAccelerometerData is called whenever new acceleromenter data is provided
// Be warned: This will not make any distiction between data from other Myo armbands
void DataCollector::onAccelerometerData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &accel) 
{
	if (run) {
		if (mesureACCEL)
		{
			size_t id = identifyMyo(myo);
			acq.getArmbandByID(id)->setValueByIndexAcce(1, accel.x());
			acq.getArmbandByID(id)->setValueByIndexAcce(2, accel.y());
			acq.getArmbandByID(id)->setValueByIndexAcce(3, accel.z());
		}
	}
	
}

// onGyroscopeData is called whenever new gyroscope data is provided
// Be warned: This will not make any distiction between data from other Myo armbands
void DataCollector::onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro) 
{
	if (run) {
		if (mesureGYRO)
		{
			size_t id = identifyMyo(myo);
			acq.getArmbandByID(id)->setValueByIndexGyro(1, gyro.x());
			acq.getArmbandByID(id)->setValueByIndexGyro(2, gyro.y());
			acq.getArmbandByID(id)->setValueByIndexGyro(3, gyro.z());
		}
	}
}

void DataCollector::onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion) {
	//Reneable streaming
	myo->setStreamEmg(myo::Myo::streamEmgEnabled);
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

}
void DataCollector::onPair(myo::Myo* myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion)
{
	knownMyos.push_back(myo);
	// Now that we've added it to our list, get our short ID for it and print it out.
	std::cout << "Paired with " << identifyMyo(myo) << "." << std::endl;
	
}
void DataCollector::printVectorAcce(uint64_t timestamp, const myo::Vector3< float > &vector) {

}

void DataCollector::end()
{
	openFiles(name);
	XmlStorage xmlStorage(name, acq);
}


bool DataCollector::isMesureAccel() const {
	return mesureACCEL;
}

void DataCollector::setMesureAccel(bool mesureAccel) {
	mesureACCEL = mesureAccel;
}

bool DataCollector::isMesureElorient() const {
	return mesureELORIENT;
}

void DataCollector::setMesureElorient(bool mesureElorient) {
	mesureELORIENT = mesureElorient;
}

bool DataCollector::isMesureEmg() const {
	return mesureEMG;
}

void DataCollector::setMesureEmg(bool mesureEmg) {
	mesureEMG = mesureEmg;
}

bool DataCollector::isMesureGyro() const {
	return mesureGYRO;
}

void DataCollector::setMesureGyro(bool mesureGyro) {
	mesureGYRO = mesureGyro;
}

bool DataCollector::isMesureOrient() const {
	return mesureORIENT;
}

void DataCollector::setMesureOrient(bool mesureOrient) {
	mesureORIENT = mesureOrient;
}

const std::string& DataCollector::getName() const {
	return name;
}

void DataCollector::setName(const std::string& name) {
	this->name = name;
}

bool DataCollector::isDualMode() const{
	return dualMode;
}

void DataCollector::setDualMode(bool dual) {
	this->dualMode = dual;
}