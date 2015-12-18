#pragma once
#include "Armband.h"
#include "DataCollector.h"

ref class TaskAcquisition
{
	private:
		myo::Myo * myo;
		myo::Hub * hub;
		bool acqLaunched = false;
		
	public:
		DataCollector * collector;
		void toogleAcquisition(bool value);
		//void run(DataCollector * collector);
		void initCapture(DataCollector* collector);
		void launchAcquisition(DataCollector * collector); //Function to launch datas acquisition
		void launchAcquisition(); //Function to launch datas acquisition
};
