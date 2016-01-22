#include "XmlStorage.h"

using namespace tinyxml2;
using namespace std;

XmlStorage::XmlStorage(std::string name, Acquisition acq, clock_t time)
{
	tinyxml2::XMLDocument doc;
	XMLNode * rootNode = doc.NewElement("acquisition");
	string ListValue[3] = { "X","Y","Z" };
	string ListValueOrien[4] = { "X","Y","Z","W" };
	string ListValueEuler[3] = { "roll","pitch","yaw" };
	string ListSide[2] = { "right","left" };
	// Construct the xml OutPut
	
	XMLElement * nameElmt = doc.NewElement("Name");
	nameElmt->SetText(name.c_str());
	rootNode->InsertEndChild(nameElmt);
	XMLElement * durationElmt = doc.NewElement("Duration");
	stringstream ss;
	ss << time;
	durationElmt->SetText(ss.str().c_str());
	rootNode->InsertEndChild(durationElmt);
	XMLNode * armhandsRoot = doc.NewElement("Armbands");
	XMLElement * armhand;
	// Creation of the armhand for the right side;
	for (int j = 0; j < 2; j++) {
		armhand = doc.NewElement("armband");
		armhand->SetAttribute("id", ListSide[j].c_str());

		// Create Emgs 
		XMLNode * emgs = doc.NewElement("emgs");
		for (int i = 1; i < 9; i++) {
			XMLElement * emg = doc.NewElement("emg");
			emg->SetAttribute("id", i);
			vector<double> emgData = acq.getArmband(ListSide[j])->getValueByIndexEmg(i);
			vector<double>::iterator it;
			for (it = emgData.begin(); it != emgData.end(); it++) {
				XMLElement * data = doc.NewElement("data");
				std::stringstream ssdata;
				//cout <<"Value : "<<(*it) << endl;

				data->SetText((*it));
				emg->InsertEndChild(data);
			}
			emgs->InsertEndChild(emg);
		}
		armhand->InsertEndChild(emgs);

		// Create gyro
		XMLNode * gyro = doc.NewElement("gyro");
		for (int i = 1; i < 4; i++) {
			XMLElement * elmt = doc.NewElement(ListValue[i - 1].c_str());
			vector<double> Data = acq.getArmband(ListSide[j])->getValueByIndexGyro(i);
			vector<double>::iterator it;
			for (it = Data.begin(); it != Data.end(); it++) {
				XMLElement * data = doc.NewElement("data");
				std::stringstream ssdata;
				data->SetText((*it));
				elmt->InsertEndChild(data);
			}
			gyro->InsertEndChild(elmt);
		}
		armhand->InsertEndChild(gyro);


		XMLNode * acce = doc.NewElement("acce");
		for (int i = 1; i < 4; i++) {
			XMLElement * elmt = doc.NewElement(ListValue[i - 1].c_str());
			vector<double> Data = acq.getArmband(ListSide[j])->getValueByIndexAcce(i);
			vector<double>::iterator it;
			for (it = Data.begin(); it != Data.end(); it++) {
				XMLElement * data = doc.NewElement("data");
				std::stringstream ssdata;
				data->SetText((*it));
				elmt->InsertEndChild(data);
			}
			acce->InsertEndChild(elmt);
		}
		armhand->InsertEndChild(acce);


		XMLNode * orien = doc.NewElement("orien");
		for (int i = 1; i <5; i++) {
			XMLElement * elmt = doc.NewElement(ListValueOrien[i - 1].c_str());
			vector<double> Data = acq.getArmband(ListSide[j])->getValueByIndexOrien(i);
			vector<double>::iterator it;
			for (it = Data.begin(); it != Data.end(); it++) {
				XMLElement * data = doc.NewElement("data");
				std::stringstream ssdata;
				data->SetText((*it));
				elmt->InsertEndChild(data);
			}
			orien->InsertEndChild(elmt);
		}
		armhand->InsertEndChild(orien);


		XMLNode * euler = doc.NewElement("euler");
		for (int i = 1; i <4; i++) {
			XMLElement * elmt = doc.NewElement(ListValueEuler[i - 1].c_str());
			vector<double> Data = acq.getArmband(ListSide[j])->getValueByIndexOrien(i);
			vector<double>::iterator it;
			for (it = Data.begin(); it != Data.end(); it++) {
				XMLElement * data = doc.NewElement("data");
				std::stringstream ssdata;
				data->SetText((*it));
				elmt->InsertEndChild(data);
			}
			euler->InsertEndChild(elmt);
		}
		armhand->InsertEndChild(euler);
		armhandsRoot->InsertEndChild(armhand);
	}
	
	rootNode->InsertEndChild(armhandsRoot);
	doc.InsertFirstChild(rootNode);	
	doc.SaveFile(name.c_str());
}


XmlStorage::~XmlStorage()
{

}
