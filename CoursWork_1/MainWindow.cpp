#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace CoursWork_1;

[STAThread]

void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CoursWork_1::MainWindow form;
	Application::Run(%form);
}