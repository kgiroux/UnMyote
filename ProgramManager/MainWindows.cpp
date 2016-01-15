#include "MainWindows.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;
using namespace ProgramManager;

#pragma region Windows control methodes
void MainWindows::InitializeComponent(void)
{
	System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindows::typeid));
	this->Start = (gcnew System::Windows::Forms::Button());
	this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
	this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
	this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
	this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
	this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
	this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
	this->groupBox1->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
	this->SuspendLayout();
	// 
	// Start
	// 
	this->Start->Location = System::Drawing::Point(197, 226);
	this->Start->Name = L"Start";
	this->Start->Size = System::Drawing::Size(75, 23);
	this->Start->TabIndex = 0;
	this->Start->Text = L"Start";
	this->Start->UseVisualStyleBackColor = true;
	this->Start->Click += gcnew System::EventHandler(this, &MainWindows::Start_Click);
	// 
	// radioButton1
	// 
	this->radioButton1->AutoSize = true;
	this->radioButton1->Location = System::Drawing::Point(26, 29);
	this->radioButton1->Name = L"radioButton1";
	this->radioButton1->Size = System::Drawing::Size(76, 17);
	this->radioButton1->TabIndex = 8;
	this->radioButton1->TabStop = true;
	this->radioButton1->Text = L"Acquisition";
	this->radioButton1->UseVisualStyleBackColor = true;
	// 
	// groupBox1
	// 
	this->groupBox1->Controls->Add(this->radioButton4);
	this->groupBox1->Controls->Add(this->radioButton3);
	this->groupBox1->Controls->Add(this->radioButton2);
	this->groupBox1->Controls->Add(this->radioButton1);
	this->groupBox1->Location = System::Drawing::Point(12, 87);
	this->groupBox1->Name = L"groupBox1";
	this->groupBox1->Size = System::Drawing::Size(260, 133);
	this->groupBox1->TabIndex = 9;
	this->groupBox1->TabStop = false;
	this->groupBox1->Text = L"Programs";
	// 
	// radioButton4
	// 
	this->radioButton4->AutoSize = true;
	this->radioButton4->Location = System::Drawing::Point(26, 98);
	this->radioButton4->Name = L"radioButton4";
	this->radioButton4->Size = System::Drawing::Size(56, 17);
	this->radioButton4->TabIndex = 11;
	this->radioButton4->TabStop = true;
	this->radioButton4->Text = L"Others";
	this->radioButton4->UseVisualStyleBackColor = true;
	// 
	// radioButton3
	// 
	this->radioButton3->AutoSize = true;
	this->radioButton3->Location = System::Drawing::Point(26, 75);
	this->radioButton3->Name = L"radioButton3";
	this->radioButton3->Size = System::Drawing::Size(63, 17);
	this->radioButton3->TabIndex = 10;
	this->radioButton3->TabStop = true;
	this->radioButton3->Text = L"Settings";
	this->radioButton3->UseVisualStyleBackColor = true;
	// 
	// radioButton2
	// 
	this->radioButton2->AutoSize = true;
	this->radioButton2->Location = System::Drawing::Point(26, 52);
	this->radioButton2->Name = L"radioButton2";
	this->radioButton2->Size = System::Drawing::Size(87, 17);
	this->radioButton2->TabIndex = 9;
	this->radioButton2->TabStop = true;
	this->radioButton2->Text = L"Interpretation";
	this->radioButton2->UseVisualStyleBackColor = true;
	// 
	// pictureBox1
	// 
	this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
	this->pictureBox1->Location = System::Drawing::Point(13, 13);
	this->pictureBox1->Name = L"pictureBox1";
	this->pictureBox1->Size = System::Drawing::Size(259, 68);
	this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
	this->pictureBox1->TabIndex = 10;
	this->pictureBox1->TabStop = false;
	// 
	// MainWindows
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(284, 261);
	this->Controls->Add(this->pictureBox1);
	this->Controls->Add(this->groupBox1);
	this->Controls->Add(this->Start);
	this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
	this->Name = L"MainWindows";
	this->Text = L"UnMyote Program Manager";
	this->groupBox1->ResumeLayout(false);
	this->groupBox1->PerformLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
	this->ResumeLayout(false);

}

void startApplication(WCHAR appliName[MAX_PATH])
{
	//Starting informations
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	// set the size of the structures
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	//Get current pathfolder
	WCHAR pathw[MAX_PATH];
	GetModuleFileNameW(GetModuleHandleW(NULL), pathw, MAX_PATH);
	int pathSize = wcslen(pathw) - wcslen(wcsrchr(pathw, L'\\/'));
	pathw[pathSize+1] = '\0';
	LPCTSTR lpApplicationName = wcscat(pathw,appliName);

	// start the program up
	CreateProcess(lpApplicationName,   // the application path
		NULL,			// Launch args
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi);          // Pointer to PROCESS_INFORMATION structure

	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

System::Void MainWindows::Start_Click(System::Object^  sender, System::EventArgs^  e) {
	if (radioButton1->Checked) {
		//MessageBox::Show("Acquisition");
		startApplication(L"AcquireDatas.exe");
	}
	else if (radioButton2->Checked) {

	}
	else if (radioButton3->Checked) {

	}
	else if (radioButton4->Checked) {

	}
}
#pragma endregion

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ProgramManager::MainWindows form;
	Application::Run(%form);
}