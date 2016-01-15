#pragma once
#include <vector>
#include <sstream>
#include <iostream>
#include <time.h>
#include "Acquisition.h"
#include "tinyxml2.h"

class XmlStorage
{
public:
	XmlStorage(std::string name, Acquisition acq, clock_t time);
	~XmlStorage();



};

