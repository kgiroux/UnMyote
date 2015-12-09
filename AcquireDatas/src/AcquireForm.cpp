#include "..\include\AcquireForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace AcquireDatas;

#pragma region Windows control methodes
AcquireForm::AcquireForm(void)
{
	InitializeComponent();
	initCapture();
}
AcquireForm::~AcquireForm()
{
	if (components)
		delete components;
}

//Initialize form components
void AcquireForm::InitializeComponent(void)
{
	this->tabConfig = (gcnew System::Windows::Forms::TabPage());
	this->groupDatas = (gcnew System::Windows::Forms::GroupBox());
	this->dualBracelet = (gcnew System::Windows::Forms::RadioButton());
	this->checkEOrt = (gcnew System::Windows::Forms::CheckBox());
	this->checkGyro = (gcnew System::Windows::Forms::CheckBox());
	this->checkOrt = (gcnew System::Windows::Forms::CheckBox());
	this->checkAccel = (gcnew System::Windows::Forms::CheckBox());
	this->checkEmg = (gcnew System::Windows::Forms::CheckBox());
	this->butLaunchStop = (gcnew System::Windows::Forms::Button());
	this->labelFile = (gcnew System::Windows::Forms::Label());
	this->textFilename = (gcnew System::Windows::Forms::TextBox());
	this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
	this->tabConfig->SuspendLayout();
	this->groupDatas->SuspendLayout();
	this->tabControl1->SuspendLayout();
	this->SuspendLayout();
	// 
	// tabConfig
	// 
	this->tabConfig->Controls->Add(this->groupDatas);
	this->tabConfig->Controls->Add(this->butLaunchStop);
	this->tabConfig->Controls->Add(this->labelFile);
	this->tabConfig->Controls->Add(this->textFilename);
	this->tabConfig->Location = System::Drawing::Point(4, 22);
	this->tabConfig->Name = L"tabConfig";
	this->tabConfig->Padding = System::Windows::Forms::Padding(3);
	this->tabConfig->Size = System::Drawing::Size(423, 396);
	this->tabConfig->TabIndex = 0;
	this->tabConfig->Text = L"Config";
	this->tabConfig->UseVisualStyleBackColor = true;
	// 
	// groupDatas
	// 
	this->groupDatas->Controls->Add(this->dualBracelet);
	this->groupDatas->Controls->Add(this->checkEOrt);
	this->groupDatas->Controls->Add(this->checkGyro);
	this->groupDatas->Controls->Add(this->checkOrt);
	this->groupDatas->Controls->Add(this->checkAccel);
	this->groupDatas->Controls->Add(this->checkEmg);
	this->groupDatas->Location = System::Drawing::Point(6, 41);
	this->groupDatas->Name = L"groupDatas";
	this->groupDatas->Size = System::Drawing::Size(411, 136);
	this->groupDatas->TabIndex = 4;
	this->groupDatas->TabStop = false;
	this->groupDatas->Text = L"Acquired Datas";
	// 
	// dualBracelet
	// 
	this->dualBracelet->AutoSize = true;
	this->dualBracelet->Location = System::Drawing::Point(316, 19);
	this->dualBracelet->Name = L"dualBracelet";
	this->dualBracelet->Size = System::Drawing::Size(89, 17);
	this->dualBracelet->TabIndex = 5;
	this->dualBracelet->TabStop = true;
	this->dualBracelet->Text = L"Dual Bracelet";
	this->dualBracelet->UseVisualStyleBackColor = true;
	// 
	// checkEOrt
	// 
	this->checkEOrt->AutoSize = true;
	this->checkEOrt->Location = System::Drawing::Point(6, 111);
	this->checkEOrt->Name = L"checkEOrt";
	this->checkEOrt->Size = System::Drawing::Size(104, 17);
	this->checkEOrt->TabIndex = 7;
	this->checkEOrt->Text = L"Euler Orientation";
	this->checkEOrt->UseVisualStyleBackColor = true;
	// 
	// checkGyro
	// 
	this->checkGyro->AutoSize = true;
	this->checkGyro->Location = System::Drawing::Point(6, 88);
	this->checkGyro->Name = L"checkGyro";
	this->checkGyro->Size = System::Drawing::Size(77, 17);
	this->checkGyro->TabIndex = 6;
	this->checkGyro->Text = L"Gyroscope";
	this->checkGyro->UseVisualStyleBackColor = true;
	// 
	// checkOrt
	// 
	this->checkOrt->AutoSize = true;
	this->checkOrt->Location = System::Drawing::Point(6, 65);
	this->checkOrt->Name = L"checkOrt";
	this->checkOrt->Size = System::Drawing::Size(77, 17);
	this->checkOrt->TabIndex = 5;
	this->checkOrt->Text = L"Orientation";
	this->checkOrt->UseVisualStyleBackColor = true;
	// 
	// checkAccel
	// 
	this->checkAccel->AutoSize = true;
	this->checkAccel->Location = System::Drawing::Point(6, 42);
	this->checkAccel->Name = L"checkAccel";
	this->checkAccel->Size = System::Drawing::Size(94, 17);
	this->checkAccel->TabIndex = 4;
	this->checkAccel->Text = L"Accelerometer";
	this->checkAccel->UseVisualStyleBackColor = true;
	// 
	// checkEmg
	// 
	this->checkEmg->AutoSize = true;
	this->checkEmg->Location = System::Drawing::Point(6, 19);
	this->checkEmg->Name = L"checkEmg";
	this->checkEmg->Size = System::Drawing::Size(47, 17);
	this->checkEmg->TabIndex = 3;
	this->checkEmg->Text = L"Emg";
	this->checkEmg->UseVisualStyleBackColor = true;
	// 
	// butLaunchStop
	// 
	this->butLaunchStop->Location = System::Drawing::Point(342, 367);
	this->butLaunchStop->Name = L"butLaunchStop";
	this->butLaunchStop->Size = System::Drawing::Size(75, 23);
	this->butLaunchStop->TabIndex = 2;
	this->butLaunchStop->Text = L"Launch";
	this->butLaunchStop->UseVisualStyleBackColor = true;
	this->butLaunchStop->Click += gcnew System::EventHandler(this, &AcquireForm::butLaunchStop_Click);
	// 
	// labelFile
	// 
	this->labelFile->AutoSize = true;
	this->labelFile->Location = System::Drawing::Point(6, 18);
	this->labelFile->Name = L"labelFile";
	this->labelFile->Size = System::Drawing::Size(52, 13);
	this->labelFile->TabIndex = 1;
	this->labelFile->Text = L"Filename:";
	// 
	// textFilename
	// 
	this->textFilename->Location = System::Drawing::Point(58, 15);
	this->textFilename->Name = L"textFilename";
	this->textFilename->Size = System::Drawing::Size(359, 20);
	this->textFilename->TabIndex = 0;
	// 
	// tabControl1
	// 
	this->tabControl1->Controls->Add(this->tabConfig);
	this->tabControl1->Location = System::Drawing::Point(12, 12);
	this->tabControl1->Name = L"tabControl1";
	this->tabControl1->SelectedIndex = 0;
	this->tabControl1->Size = System::Drawing::Size(431, 422);
	this->tabControl1->TabIndex = 0;
	// 
	// AcquireForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(455, 446);
	this->Controls->Add(this->tabControl1);
	this->Name = L"AcquireForm";
	this->Text = L"AcquireForm";
	this->tabConfig->ResumeLayout(false);
	this->tabConfig->PerformLayout();
	this->groupDatas->ResumeLayout(false);
	this->groupDatas->PerformLayout();
	this->tabControl1->ResumeLayout(false);
	this->ResumeLayout(false);

}

//Component control
System::Void AcquireForm::butLaunchStop_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Process or stop data's acquisition
	System::Windows::Forms::Button^ button = (System::Windows::Forms::Button^)sender;
	DataCollector * collector;
	if (button->Text->Equals("Launch"))
	{
		//Launch acquisition
		std::cout << "Acquisition launched!" << std::endl;
		this->acqLaunched = true;
		this->butLaunchStop->Text = "Stop";
		collector->setMesureAccel(this->checkAccel->Checked);
		collector->setMesureEmg(this->checkEmg->Checked);
		collector->setMesureGyro(this->checkGyro->Checked);
		collector->setMesureOrient(this->checkOrt->Checked);
		collector->setMesureElorient(this->checkEOrt->Checked);
		collector->setDualMode(this->dualBracelet->Checked);
	}
	else
	{
		//Stop acquisition
		std::cout << "Acquisition stopped!" << std::endl;
		collector->end();
		delete collector;
		this->butLaunchStop->Text = "Launch";
		this->acqLaunched = false;
	}
}
#pragma endregion

/* Main function */
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	AcquireDatas::AcquireForm form;
	Application::Run(%form);
}

void AcquireForm::initCapture() {
	try {
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
		collector = new DataCollector();

		hub->addListener(collector);
	}
	catch(const std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << "Press enter to continue.";
		std::cin.ignore();
		this->butLaunchStop->Text = "Launch";
		this->acqLaunched = false;
	}
	

}

void AcquireForm::run() {
	while (run) {

	}
	hub->run(1000 / 20);
	hub->run
}


/* Data acquisition */
void AcquireForm::launchAcquisition(DataCollector * collector)
{
	//Identificate datas for the current mesurement
	bool emg, accel, gyro, orient, eulerOrient, dualMode = false;
	std::string filename = "exc";
	emg = 
	accel = this->checkAccel->Checked;
	gyro = this->checkGyro->Checked;
	orient = this->checkOrt->Checked;
	eulerOrient = this->checkEOrt->Checked;
	dualMode = this->dualBracelet->Checked;
	//filename = this->textFilename->Text;
	std::cout << "Mesure emg-" << emg << ",gyro-" << gyro << ",accelerometer-" << accel << ",orientation-" << orient << ",Euler orientation-" << eulerOrient << std::endl;

	// We catch any exceptions that might occur below -- see the catch statement for more details.
	try 
	{
		// First, we create a Hub with our application identifier. Be sure not to use the com.example namespace when
		// publishing your application. The Hub provides access to one or more Myos.
		myo::Hub hub();
		

		// Next, we attempt to find a Myo to use. If a Myo is already paired in Myo Connect, this will return that Myo
		// immediately.
		// waitForMyo() takes a timeout value in milliseconds. In this case we will try to find a Myo for 10 seconds, and
		// if that fails, the function will return a null pointer.
		myo::Myo* myo = hub.waitForMyo(10000);

		

		
		
		
		
		// Hub::addListener() takes the address of any object whose class inherits from DeviceListener, and will cause
		// Hub::run() to send events to all registered device listeners.
		

		// Finally we enter our main loop.
		while (acqLaunched)
		{
			// In each iteration of our main loop, we run the Myo event loop for a set number of milliseconds.
			// In this case, we wish to update our display 50 times a second, so we run for 1000/20 milliseconds.
			hub.run(1000/20);
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
		this->butLaunchStop->Text = "Launch";
		this->acqLaunched = false;
	}
}

