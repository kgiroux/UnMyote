#include "..\include\TaskAcquisition.h"
using namespace System;
using namespace System::Threading;

/* Acquisition initialization */
void TaskAcquisition::initCapture(DataCollector* collector) {
	try 
	{
		this->hub = new myo::Hub("com.unmyote.myo-data-capture");
		std::cout << "Attempting to find a Myo..." << std::endl;
		this->myo = hub->waitForMyo(10000);
		// If waitForMyo() returned a null pointer, we failed to find a Myo, so exit with an error message.
		if (!myo) {
			throw std::runtime_error("Unable to find a Myo!");
		}
		// We've found a Myo.
		std::cout << "Connected to a Myo armband! \nLogging to the file system. \nCheck your home folder or the folder this application lives in.\n" << std::endl << std::endl;
		// Next we enable EMG streaming on the found Myo.
		myo->setStreamEmg(myo::Myo::streamEmgEnabled);
		// Next we construct an instance of our DeviceListener, so that we can register it with the Hub.

		hub->addListener(collector);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << "Press enter to continue.";
		std::cin.ignore();
	}
}

void TaskAcquisition::toogleAcquisition(bool value)
{
	this->acqLaunched = value;
}

/*void run(DataCollector * collector)
{
	Thread^ t = gcnew Thread(gcnew ThreadStart(&TaskAcquisition::launchAcquisition));
	t->Name = "thread1";
	t->Start();
}*/

/* Data acquisition */
void TaskAcquisition::launchAcquisition(DataCollector * collector)
{
	//Identificate datas for the current mesurement
	/*std::cout << "Mesure emg-" << collector->isMesureEmg() << ",gyro-" << collector->isMesureGyro() << ",accelerometer-" << collector->isMesureAccel << ",orientation-" << collector->isMesureOrient << ",Euler orientation-" << collector->isMesureElorient << std::endl;

	// We catch any exceptions that might occur below -- see the catch statement for more details.
	try
	{
		// Finally we enter our main loop.
		while (acqLaunched)
		{
			// In each iteration of our main loop, we run the Myo event loop for a set number of milliseconds.
			// In this case, we wish to update our display 50 times a second, so we run for 1000/20 milliseconds.
			hub->run(1000 / 20);
			//collector.onEmgData();
		}
		system("pause");
		// If a standard exception occurred, we print out its message and exit.
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << "Press enter to continue.";
		std::cin.ignore();
		this->acqLaunched = false;
	}*/
}
/* Data acquisition */
void TaskAcquisition::launchAcquisition()
{
	//Identificate datas for the current mesurement
	std::cout << "Print start" << std::endl;
	std::cout << collector->isDualMode() << std::endl;
}