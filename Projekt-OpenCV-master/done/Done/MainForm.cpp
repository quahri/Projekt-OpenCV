#include "MainForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main(){
	Application::EnableVisualStyles;
	Application::SetCompatibleTextRenderingDefault;
	done::MainForm form;
	Application::Run(%form);
}

