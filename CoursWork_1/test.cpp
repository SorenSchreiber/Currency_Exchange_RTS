#include "test.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

void sendData(int x)
{
	String^ test = x.ToString();
	MessageBox::Show(test);
}