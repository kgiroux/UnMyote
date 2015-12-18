#pragma once
#include "Armband.h"
#include "DataCollector.h"

ref class TaskAcquisition
{
	private:
		myo::Myo * myo;
		myo::Hub * hub;
		bool acqLaunched = false;
		DataCollector* collector;
		
	public:
		void toogleAcquisition(bool value);
		void initCapture(DataCollector* collector);
		void launchAcquisition(); //Function to launch datas acquisition
};
