#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Resources;

#define WLcontrolOffset 106
#define DPHcontrolOffset 81

void createWatchBox(String^ currencySearchPara);

void deleteWatchBox(System::Windows::Forms::Control^ selection);

void createDPHBox(String^ currencySearchPara);