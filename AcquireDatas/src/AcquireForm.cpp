#include "..\include\AcquireForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;
using namespace AcquireDatas;

#pragma region Windows control methodes
AcquireForm::AcquireForm(void)
{
	InitializeComponent();
	//this->task = new TaskAcquisition();
	//task->initCapture(collector);
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
	this->checkEOrt->Checked = true;
	this->checkEOrt->CheckState = System::Windows::Forms::CheckState::Checked;
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
	this->checkGyro->Checked = true;
	this->checkGyro->CheckState = System::Windows::Forms::CheckState::Checked;
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
	this->checkOrt->Checked = true;
	this->checkOrt->CheckState = System::Windows::Forms::CheckState::Checked;
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
	this->checkAccel->Checked = true;
	this->checkAccel->CheckState = System::Windows::Forms::CheckState::Checked;
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
	this->checkEmg->Checked = true;
	this->checkEmg->CheckState = System::Windows::Forms::CheckState::Checked;
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
	std::string filename = msclr::interop::marshal_as<std::string>(textFilename->Text);

	if (button->Text->Equals("Launch"))
	{
		//Launch acquisition
		this->collector = new DataCollector();
		std::cout << "Acquisition launched!" << std::endl;
		this->butLaunchStop->Text = "Stop";
		collector->setMesureAccel(this->checkAccel->Checked);
		collector->setMesureEmg(this->checkEmg->Checked);
		collector->setMesureGyro(this->checkGyro->Checked);
		collector->setMesureOrient(this->checkOrt->Checked);
		collector->setMesureElorient(this->checkEOrt->Checked);
		collector->setDualMode(this->dualBracelet->Checked);
		if (strcmp(filename.c_str(),"") == 0)
			filename = "acq-test-toto";
		collector->setName(filename);

		//Launch acquisition Threading
		this->task = gcnew TaskAcquisition;
		this->task->initCapture(collector);
		this->task->toogleAcquisition(true);
		ThreadStart^ taskThread = gcnew ThreadStart(task,&TaskAcquisition::launchAcquisition);
		Thread^ t = gcnew Thread(taskThread);
		t->Name = "acquisitionThread";
		t->Start();
	}
	else
	{
		//Stop acquisition
		this->task->toogleAcquisition(false);
		std::cout << "Acquisition stopped!" << std::endl;
		collector->end();
		this->butLaunchStop->Text = "Launch";

		//Reset variable
		delete task;
		delete collector;
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

