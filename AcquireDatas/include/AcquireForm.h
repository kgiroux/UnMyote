#pragma once
#include <iostream>
#include "DataCollector.h";

namespace AcquireDatas 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AcquireForm : public System::Windows::Forms::Form
	{
		/* Attributs */
		private:
			bool acqLaunched = false;

		private: System::Windows::Forms::TabPage^  tabConfig;
		private: System::Windows::Forms::Label^  labelFile;
		private: System::Windows::Forms::TextBox^  textFilename;


		private: System::Windows::Forms::TabControl^  tabControl1;
		private: System::Windows::Forms::Button^  butLaunchStop;

		private: System::Windows::Forms::GroupBox^  groupDatas;
		private: System::Windows::Forms::CheckBox^  checkEOrt;
		private: System::Windows::Forms::CheckBox^  checkGyro;
		private: System::Windows::Forms::CheckBox^  checkOrt;
		private: System::Windows::Forms::CheckBox^  checkAccel;
		private: System::Windows::Forms::CheckBox^  checkEmg;
		private: System::Windows::Forms::RadioButton^  dualBracelet;
	#pragma region Windows Form Designer generated code
			/* Attributes */
			private: 




				System::ComponentModel::Container ^components;

			/* Methodes */
			public:
				AcquireForm(void);

			protected:
				~AcquireForm();
				void InitializeComponent(void);

			private: System::Void butLaunchStop_Click(System::Object^  sender, System::EventArgs^  e);
			#pragma endregion

		private: 
			void launchAcquisition(); //Function to launch datas acquisition
	};
}
