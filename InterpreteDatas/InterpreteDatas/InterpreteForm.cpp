#include "InterpreteForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;
using namespace InterpreteDatas;

/* Main function */
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	InterpreteDatas::InterpreteForm form;
	Application::Run(%form);
}