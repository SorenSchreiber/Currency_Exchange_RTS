#pragma once
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <wininet.h>

#pragma comment (lib, "wininet.lib")

#define internetReadLength 4901

namespace CoursWork_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ACR
	/// </summary>
	public ref class ACR : public System::Windows::Forms::Form
	{
	public:
		ACR(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			dataValues->Clear();

			readCurrencyList();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ACR()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Components
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ComboBox^  selCurrency1;
	private: System::Windows::Forms::ComboBox^  selCurrency2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  reverseSelection;

	private: System::Windows::Forms::Label^  label3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
#pragma endregion

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ACR::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->selCurrency1 = (gcnew System::Windows::Forms::ComboBox());
			this->selCurrency2 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->reverseSelection = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->reverseSelection))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 129);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ACR::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(216, 129);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ACR::button2_Click);
			// 
			// selCurrency1
			// 
			this->selCurrency1->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->selCurrency1->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->selCurrency1->FormattingEnabled = true;
			this->selCurrency1->Location = System::Drawing::Point(116, 12);
			this->selCurrency1->Name = L"selCurrency1";
			this->selCurrency1->Size = System::Drawing::Size(175, 21);
			this->selCurrency1->TabIndex = 2;
			// 
			// selCurrency2
			// 
			this->selCurrency2->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->selCurrency2->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->selCurrency2->FormattingEnabled = true;
			this->selCurrency2->Location = System::Drawing::Point(116, 75);
			this->selCurrency2->Name = L"selCurrency2";
			this->selCurrency2->Size = System::Drawing::Size(175, 21);
			this->selCurrency2->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Select Currency";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Select Currency";
			// 
			// reverseSelection
			// 
			this->reverseSelection->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"reverseSelection.Image")));
			this->reverseSelection->Location = System::Drawing::Point(188, 39);
			this->reverseSelection->Name = L"reverseSelection";
			this->reverseSelection->Size = System::Drawing::Size(34, 30);
			this->reverseSelection->TabIndex = 6;
			this->reverseSelection->TabStop = false;
			this->reverseSelection->Click += gcnew System::EventHandler(this, &ACR::reverseSelection_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(90, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"exchange rate for";
			// 
			// ACR
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(303, 164);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->reverseSelection);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->selCurrency2);
			this->Controls->Add(this->selCurrency1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"ACR";
			this->Text = L"Add Currency Rate";
			this->Load += gcnew System::EventHandler(this, &ACR::ACR_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->reverseSelection))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:

#pragma region Variables
		String^ currencySelection="";											//currency selection string
		Generic::List<String^>^ dataValues = gcnew Generic::List<String^>();	//String list for data values
#pragma endregion

	private: 

#pragma region Event Handlers
		//close button click event handler
		System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			currencySelection = "";		//set empty string
			this->Close();				//close form
		}

		//add button click event handler
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (selCurrency1->SelectedIndex != selCurrency2->SelectedIndex && selCurrency1->SelectedIndex!=-1 && selCurrency2->SelectedIndex!=-1)//if selections valid
			{
				currencySelection = generateSearchParameter(); //set currency selection

				this->Close();		//close this form
			}
			else //if 1 or more combox boxes have no selection
			{
				MessageBox::Show("Please select 2 diffenrent currencies");

				selCurrency2->SelectedIndex = -1;//set index -1
			}
		}

		//form load event handler
		System::Void ACR_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			selCurrency1->SelectedIndex = -1;	//pre select default empty
			selCurrency2->SelectedIndex = -1;	//pre select default empty
		}

		//reverse selection click event handler
		System::Void reverseSelection_Click(System::Object^  sender, System::EventArgs^  e)
		{
			int bufferSelection;
		
			if (selCurrency1->SelectedIndex != -1 && selCurrency2->SelectedIndex != -1)//if selections are valid
			{
				//swap selections
				bufferSelection = selCurrency1->SelectedIndex;
				selCurrency1->SelectedIndex = selCurrency2->SelectedIndex;
				selCurrency2->SelectedIndex = bufferSelection;
			}
			else
			{
				MessageBox::Show("Please select both currencies and try again.");
			}
		}

#pragma endregion

#pragma region Functions
	
	//create search parameter for main programm
	String^ generateSearchParameter()
	{
		return dataValues[selCurrency1->SelectedIndex]->ToString() + dataValues[selCurrency2->SelectedIndex]->ToString();
	}

	//read currency list and fill combo boxes
	void readCurrencyList()
	{
		HINTERNET connection = InternetOpen(_T("MyBrowser"), INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0); //establish connection to internet

		if (connection)//if connection is valid
		{
			//open internet address
			HINTERNET openAddress = InternetOpenUrl(connection,
				_T("https://openexchangerates.org/api/currencies.json"),
				NULL, 0, INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_SECURE, 0);

			if (openAddress)//if address is valid
			{
				char DataRecieved[internetReadLength] = { '\0' };
				char Data[internetReadLength] = { '\0' };
				DWORD NumberOfBytesRead = 0;

				//read data from internet
				while (InternetReadFile(openAddress, DataRecieved, internetReadLength, &NumberOfBytesRead) && NumberOfBytesRead);

				String^ buffer = gcnew String(DataRecieved, 0, 4901);

				buffer = buffer->Substring(1, buffer->Length - 4);

				createCBList(buffer);//create List with read data
			}
			else
			{
				DWORD ErrorNUM = GetLastError();
				MessageBox::Show("Failed to open URL! ErrorNumber:" + ErrorNUM);
				InternetCloseHandle(connection);
			}
		}
		else
		{
			MessageBox::Show("Could not establish a connection. Returning to main menu!\r\n");
		}
	}

	//fill combo boxes
	void createCBList(String^ data)
	{
		//clear combo boxes
		selCurrency1->Items->Clear();
		selCurrency2->Items->Clear();

		array<String^>^ splittData = data->Split(',');	//split data into single currency array

		for each (String^ dataSeg in splittData)
		{
			array<String^>^ bufferSeg = dataSeg->Split(':');

			//create currency tag
			bufferSeg[0] = bufferSeg[0]->Remove(0, 4);
			bufferSeg[0] = bufferSeg[0]->Remove(bufferSeg[0]->Length - 1);

			//create currency name
			bufferSeg[1] = bufferSeg[1]->Remove(0, 2);
			bufferSeg[1] = bufferSeg[1]->Remove(bufferSeg[1]->Length - 1);

			dataValues->Add(bufferSeg[0]);	//add tag to data values

			//add currency name to combo boxes
			selCurrency1->Items->Add(bufferSeg[1]);
			selCurrency2->Items->Add(bufferSeg[1]);

			//add currency to autocomplete source
			selCurrency1->AutoCompleteCustomSource->Add(bufferSeg[1]);
			selCurrency2->AutoCompleteCustomSource->Add(bufferSeg[1]);
		}
	}
#pragma endregion

};
}
