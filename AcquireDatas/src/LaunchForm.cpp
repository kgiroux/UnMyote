#include "..\include\AcquireForm.h"
using namespace System;
using namespace System::Windows::Forms;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	AcquireDatas::AcquireForm form;
	Application::Run(%form);
}

