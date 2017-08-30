#pragma once

#include "NeuralNetwork.h"

#define HLcontrolOffset 29

namespace CoursWork_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for NewNN
	/// </summary>
	public ref class NewNN : public System::Windows::Forms::Form
	{
	public:
		NewNN(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NewNN()
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tb_input;
	private: System::Windows::Forms::TextBox^  tb_output;



	private: System::Windows::Forms::Panel^  hiddenLayers;
	private: System::Windows::Forms::TextBox^  defaultHiddenTB;












	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Button^  button3;






	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  tb_name;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::CheckBox^  momentum;
	private: System::Windows::Forms::CheckBox^  linOut;


	private: System::Windows::Forms::TextBox^  momentumValue;
	private: System::Windows::Forms::TextBox^  learningRate;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  maxError;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  maxIt;
	private: System::Windows::Forms::Panel^  outputPanel;














	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::RadioButton^  rB_trend;
	private: System::Windows::Forms::RadioButton^  rB_Scale;















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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_input = (gcnew System::Windows::Forms::TextBox());
			this->tb_output = (gcnew System::Windows::Forms::TextBox());
			this->hiddenLayers = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->defaultHiddenTB = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tb_name = (gcnew System::Windows::Forms::TextBox());
			this->momentum = (gcnew System::Windows::Forms::CheckBox());
			this->linOut = (gcnew System::Windows::Forms::CheckBox());
			this->momentumValue = (gcnew System::Windows::Forms::TextBox());
			this->learningRate = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->maxError = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->maxIt = (gcnew System::Windows::Forms::TextBox());
			this->outputPanel = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->rB_trend = (gcnew System::Windows::Forms::RadioButton());
			this->rB_Scale = (gcnew System::Windows::Forms::RadioButton());
			this->hiddenLayers->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 235);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Create";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NewNN::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(144, 235);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &NewNN::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 82);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Input-Layer:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Output-Layer:";
			// 
			// tb_input
			// 
			this->tb_input->Location = System::Drawing::Point(113, 79);
			this->tb_input->Name = L"tb_input";
			this->tb_input->Size = System::Drawing::Size(34, 20);
			this->tb_input->TabIndex = 4;
			this->tb_input->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &NewNN::textBox1_KeyPress);
			// 
			// tb_output
			// 
			this->tb_output->Location = System::Drawing::Point(113, 105);
			this->tb_output->Name = L"tb_output";
			this->tb_output->Size = System::Drawing::Size(34, 20);
			this->tb_output->TabIndex = 5;
			this->tb_output->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &NewNN::textBox1_KeyPress);
			this->tb_output->Leave += gcnew System::EventHandler(this, &NewNN::tb_output_Leave);
			// 
			// hiddenLayers
			// 
			this->hiddenLayers->AutoScroll = true;
			this->hiddenLayers->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->hiddenLayers->Controls->Add(this->panel2);
			this->hiddenLayers->Location = System::Drawing::Point(12, 131);
			this->hiddenLayers->Name = L"hiddenLayers";
			this->hiddenLayers->Size = System::Drawing::Size(206, 93);
			this->hiddenLayers->TabIndex = 6;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->defaultHiddenTB);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Location = System::Drawing::Point(3, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(170, 25);
			this->panel2->TabIndex = 10;
			// 
			// defaultHiddenTB
			// 
			this->defaultHiddenTB->Location = System::Drawing::Point(91, 3);
			this->defaultHiddenTB->Name = L"defaultHiddenTB";
			this->defaultHiddenTB->Size = System::Drawing::Size(34, 20);
			this->defaultHiddenTB->TabIndex = 9;
			this->defaultHiddenTB->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &NewNN::textBox1_KeyPress);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 6);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Hidden-Layer 1:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(186, 105);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(33, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"+";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &NewNN::addRow);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(10, 56);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Name";
			// 
			// tb_name
			// 
			this->tb_name->Location = System::Drawing::Point(51, 53);
			this->tb_name->Name = L"tb_name";
			this->tb_name->Size = System::Drawing::Size(167, 20);
			this->tb_name->TabIndex = 9;
			this->tb_name->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &NewNN::tb_name_KeyPress);
			// 
			// momentum
			// 
			this->momentum->AutoSize = true;
			this->momentum->Location = System::Drawing::Point(227, 159);
			this->momentum->Name = L"momentum";
			this->momentum->Size = System::Drawing::Size(103, 17);
			this->momentum->TabIndex = 10;
			this->momentum->Text = L"Use Momentum:";
			this->momentum->UseVisualStyleBackColor = true;
			// 
			// linOut
			// 
			this->linOut->AutoSize = true;
			this->linOut->Location = System::Drawing::Point(227, 186);
			this->linOut->Name = L"linOut";
			this->linOut->Size = System::Drawing::Size(90, 17);
			this->linOut->TabIndex = 11;
			this->linOut->Text = L"Linear Output";
			this->linOut->UseVisualStyleBackColor = true;
			// 
			// momentumValue
			// 
			this->momentumValue->Location = System::Drawing::Point(328, 157);
			this->momentumValue->Name = L"momentumValue";
			this->momentumValue->Size = System::Drawing::Size(41, 20);
			this->momentumValue->TabIndex = 10;
			this->momentumValue->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &NewNN::doubleInputControl);
			// 
			// learningRate
			// 
			this->learningRate->Location = System::Drawing::Point(328, 209);
			this->learningRate->Name = L"learningRate";
			this->learningRate->Size = System::Drawing::Size(41, 20);
			this->learningRate->TabIndex = 12;
			this->learningRate->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &NewNN::doubleInputControl);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(227, 212);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Learning Rate:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(224, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(102, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Max Error (i.e. 0.05):";
			// 
			// maxError
			// 
			this->maxError->Location = System::Drawing::Point(334, 6);
			this->maxError->Name = L"maxError";
			this->maxError->Size = System::Drawing::Size(41, 20);
			this->maxError->TabIndex = 14;
			this->maxError->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &NewNN::doubleInputControl);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(224, 35);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(100, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Maximum Iterations:";
			// 
			// maxIt
			// 
			this->maxIt->Location = System::Drawing::Point(334, 32);
			this->maxIt->Name = L"maxIt";
			this->maxIt->Size = System::Drawing::Size(41, 20);
			this->maxIt->TabIndex = 16;
			this->maxIt->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &NewNN::textBox1_KeyPress);
			// 
			// outputPanel
			// 
			this->outputPanel->AutoScroll = true;
			this->outputPanel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->outputPanel->Location = System::Drawing::Point(227, 58);
			this->outputPanel->Name = L"outputPanel";
			this->outputPanel->Size = System::Drawing::Size(148, 95);
			this->outputPanel->TabIndex = 11;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(9, 9);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(73, 13);
			this->label11->TabIndex = 19;
			this->label11->Text = L"Network type:";
			// 
			// rB_trend
			// 
			this->rB_trend->AutoSize = true;
			this->rB_trend->Location = System::Drawing::Point(88, 7);
			this->rB_trend->Name = L"rB_trend";
			this->rB_trend->Size = System::Drawing::Size(53, 17);
			this->rB_trend->TabIndex = 20;
			this->rB_trend->TabStop = true;
			this->rB_trend->Text = L"Trend";
			this->rB_trend->UseVisualStyleBackColor = true;
			this->rB_trend->CheckedChanged += gcnew System::EventHandler(this, &NewNN::rB_trend_CheckedChanged);
			// 
			// rB_Scale
			// 
			this->rB_Scale->AutoSize = true;
			this->rB_Scale->Location = System::Drawing::Point(88, 30);
			this->rB_Scale->Name = L"rB_Scale";
			this->rB_Scale->Size = System::Drawing::Size(60, 17);
			this->rB_Scale->TabIndex = 21;
			this->rB_Scale->TabStop = true;
			this->rB_Scale->Text = L"Scaling";
			this->rB_Scale->UseVisualStyleBackColor = true;
			// 
			// NewNN
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(385, 265);
			this->Controls->Add(this->rB_Scale);
			this->Controls->Add(this->rB_trend);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->outputPanel);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->maxIt);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->maxError);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->learningRate);
			this->Controls->Add(this->momentumValue);
			this->Controls->Add(this->linOut);
			this->Controls->Add(this->momentum);
			this->Controls->Add(this->tb_name);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->hiddenLayers);
			this->Controls->Add(this->tb_output);
			this->Controls->Add(this->tb_input);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"NewNN";
			this->Text = L"New N-N";
			this->Load += gcnew System::EventHandler(this, &NewNN::NewNN_Load);
			this->hiddenLayers->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public:

#pragma region Variables
			String^ name = "";
			int counter = 1;
			NeuralNetwork^ newNeuralNetwork=nullptr;
			Generic::List<TextBox^>^hiddenInput=gcnew Generic::List<TextBox^>();
			Generic::List<Control^>^ ListHiddenLayers = gcnew Generic::List<Control^>();
			Generic::List<NeuralNetwork^>^ NeuralNetworkList;
			array<int>^ hiddenValues;
			array<double, 2>^ ScaleValues;
			array<TextBox^, 2>^ ScaleInputs;

#pragma endregion

		private:
#pragma region Event Handlers
			//form load event handler
			System::Void NewNN_Load(System::Object^  sender, System::EventArgs^  e) 
			{
				hiddenInput->Clear();					//clear hidden input list
				ListHiddenLayers->Clear();				//clear hidden layer list
				hiddenInput->Add(defaultHiddenTB);		//add default to hidden input list
				rB_trend->Checked = true;				//default check trend
			}

			//text box key press
			System::Void tb_name_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
			{
				if (tb_name->BackColor == Color::Red)	//change color to white
					tb_name->BackColor = Color::White;
			}

			//text box integer key press
			System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
			{
				Control^ senderControl = dynamic_cast<Control^>(sender);
				
				if (Char::IsDigit(e->KeyChar)|| e->KeyChar == 8) //limit key input to numbers and backspace
				{
					if (senderControl != nullptr)					//if sender control valid
					{
						if (senderControl->BackColor == Color::Red)	//change color to white
							senderControl->BackColor = Color::White;
					}
				}
				else
				{
					e->Handled = true;
				}
			}

			//text box double key press
			System::Void doubleInputControl(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
			{
				Control^ senderControl = dynamic_cast<Control^>(sender);

				if (Char::IsDigit(e->KeyChar) || e->KeyChar == 8|| e->KeyChar==46||e->KeyChar==45) //limit key input to numbers, backspace, - and .
				{
					if (senderControl != nullptr)						//if control is valid
					{
						if (senderControl->BackColor == Color::Red)		//change color to white
							senderControl->BackColor = Color::White;
					}
				}
				else
				{
					e->Handled = true;
				}
			}

			//button click event
			System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				if (checkInputInformation())	//if inputs check out
				{
					createNetwork();			//create network
					this->Close();				//close this form
				}
				else
				{
					MessageBox::Show("Please check the information provided and make sure all fields are filled correctly.");
				}
			}

			//button click event
			System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
			{
				this->Close();//close this form
			}

			//delete row button click event
			System::Void deleteRow(System::Object^  sender, System::EventArgs^  e) 
			{
				Control^ senderControl = dynamic_cast<Control^>(sender);
				if (senderControl != nullptr)						//if control is valid
				{
					deleteHiddenLayerInput(senderControl->Parent);	//delete hiddne layer row
				}

			}

			//add row button click event
			System::Void addRow(System::Object^  sender, System::EventArgs^  e) 
			{
				hiddenLayers->Controls->Add(createHiddenLayerInput());//add hidden layer row
			}

			//text box output nodes leave event
			System::Void tb_output_Leave(System::Object^  sender, System::EventArgs^  e) 
			{
				outputPanel->Controls->Clear();							//clear output panel controls

				if (tb_output->Text != "" && outputPanel->Visible)		//if output has value and output panel is visible
				{
					//create Arrays for scaling purposes
					ScaleValues = gcnew array<double, 2>(Convert::ToInt32(tb_output->Text), 2);
					ScaleInputs = gcnew array<TextBox^, 2>(Convert::ToInt32(tb_output->Text), 2);

					//for all output nodes
					for (int x = 0; x < Convert::ToInt32(tb_output->Text);x++)
					{
						//create new panel
						Panel^ outputP = gcnew Panel();
							outputP->Location = System::Drawing::Point(3, 3 + 25 * x);
							outputP->Name = L"OutputScale_" + x;
							outputP->Size = System::Drawing::Size(125, 25);

						//create new label
						Label^ newLabel = gcnew Label();
							newLabel->AutoSize = true;
							newLabel->Location = System::Drawing::Point(3, 6);
							newLabel->Name = L"Outputlabel_" + x;
							newLabel->Size = System::Drawing::Size(82, 13);
							newLabel->Text = L"Output " + x + ":";

						//create new texbox min value
						TextBox^ minScale = gcnew TextBox();
							minScale->Location = System::Drawing::Point(53, 2);
							minScale->Name = "minScale_" + x;
							minScale->Size = System::Drawing::Size(34, 20);
							minScale->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &NewNN::doubleInputControl);

						//create new textbox max value
						TextBox^ maxScale = gcnew TextBox();
							maxScale->Location = System::Drawing::Point(88, 2);
							maxScale->Name = "maxScale_" + x;
							maxScale->Size = System::Drawing::Size(34, 20);
							maxScale->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &NewNN::doubleInputControl);

						//add to panel
						outputP->Controls->Add(newLabel);
						outputP->Controls->Add(minScale);
						outputP->Controls->Add(maxScale);

						//add panel to output control panel
						outputPanel->Controls->Add(outputP);

						//set scale inputs
						ScaleInputs[x, 0] = minScale;
						ScaleInputs[x, 1] = maxScale;
					}
				}
			}

			//radio button selection change
			System::Void rB_trend_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			{
				if (rB_trend->Checked)//if trend selected
				{
					outputPanel->Hide();			//hide output panel
					tb_output->Enabled = false;		//disable output
					tb_output->Text = "3";			//preset output
				}
				else
				{
					outputPanel->Show();			//show output panel
					tb_output->Enabled = true;		//enable output
					tb_output->Text = "";			//preset output
				}
			}
#pragma endregion

#pragma region Functions
			//create new Neural Network
			void createNetwork()
			{
				newNeuralNetwork = gcnew NeuralNetwork();		//create new neural network
				createHiddenArray();							//create hiddne array

				//set and init the new neural network
				newNeuralNetwork->INIT(tb_name->Text, Convert::ToInt32(tb_input->Text),hiddenValues, Convert::ToInt32(tb_output->Text), hiddenInput->Count);
				newNeuralNetwork->setLearningRate(Convert::ToDouble(learningRate->Text));
				newNeuralNetwork->setLinearOutput(linOut->Checked);
				if(momentum->Checked)
					newNeuralNetwork->setMomentum(momentum->Checked, Convert::ToDouble(momentumValue->Text));
				else
					newNeuralNetwork->setMomentum(momentum->Checked, NULL);

				newNeuralNetwork->scaling = rB_Scale->Checked;

				if (newNeuralNetwork->scaling)
				{
					fillScaleValues();
					newNeuralNetwork->scale = ScaleValues;
				}
				else
				{
					newNeuralNetwork->scale = nullptr;
				}

				if (maxError->Text == "")
					newNeuralNetwork->maxError = NULL;
				else
					newNeuralNetwork->maxError = Convert::ToDouble(maxError->Text);
				if (maxIt->Text == "")
					newNeuralNetwork->maxIterations = NULL;
				else
					newNeuralNetwork->maxIterations = Convert::ToInt32(maxIt->Text);
			}

			//build array for hidden values
			void createHiddenArray()
			{
				int x = 0;
				hiddenValues = gcnew array<int>(hiddenInput->Count);//create new array of specified size

				for each(TextBox^ tb in hiddenInput)				//for each textbox in hidden input list
				{
					hiddenValues[x] = Convert::ToInt32(tb->Text);	//set value
					x++;											//inc counter
				}
			}

			//fill values into oscaling value array
			void fillScaleValues()
			{
				for (int x = 0;x < ScaleInputs->GetLength(0);x++)	//for all scaled outputs
				{
					//fill scale values
					ScaleValues[x, 0] = Convert::ToDouble(ScaleInputs[x, 0]->Text);
					ScaleValues[x, 1] = Convert::ToDouble(ScaleInputs[x, 1]->Text);
				}
			}

			//check input information of new network
			bool checkInputInformation()
			{
				//preset check points
				bool nameCheck = false;
				bool InOutCheck = false;
				bool checkScaling = true;
				bool hiddenCheck = true;
				bool information = false;

				//check name
				if (tb_name->Text != "" && checkNNList(tb_name->Text))
					nameCheck = true;
				else
					tb_name->BackColor = Color::Red;

				//check input nodes
				if (tb_input->Text!=""&&tb_output->Text!="")
					InOutCheck = true;
				else
				{
					if(tb_input->Text == "")
						tb_input->BackColor = Color::Red;
					if(tb_output->Text == "")
						tb_output->BackColor = Color::Red;
				}

				//check hidden nodes
				for each(TextBox^ tb in hiddenInput)
				{
					if (tb->Text->Trim() == "")
					{
						tb->BackColor = Color::Red;
						hiddenCheck = false;
					}
				}

				//check learnrate
				if (learningRate->Text != "" && maxError->Text!="" && maxIt->Text!="")
				{
					if((momentum->Checked && momentumValue->Text != "")||!momentum->Checked)
						information = true;
					else
						momentumValue->BackColor = Color::Red;
				}
				else
				{
					if (learningRate->Text == "")
						learningRate->BackColor = Color::Red;
					
					if (maxIt->Text == "")
						maxIt->BackColor = Color::Red;
					
					if (maxError->Text == "")
						maxError->BackColor = Color::Red;

					if(momentum->Checked)
						if (momentumValue->Text == "")
							momentumValue->BackColor = Color::Red;
				}

				//check scales
				if (ScaleInputs != nullptr)
				{
					for (int x = 0; x < ScaleInputs->GetLength(0);x++)
					{
						if (ScaleInputs[x, 0]->Text == "")
						{
							ScaleInputs[x, 0]->BackColor = Color::Red;
							hiddenCheck = false;
						}
						if (ScaleInputs[x, 1]->Text == "")
						{
							ScaleInputs[x, 1]->BackColor = Color::Red;
							hiddenCheck = false;
						}
					}
				}

				//if all valid
				if (nameCheck&&InOutCheck&&hiddenCheck&&information&&checkScaling)
				{
					return true;
				}
				else
					return false;
			}

			//check name for new network
			bool checkNNList(String^ name)
			{
				for each(NeuralNetwork^ nn in NeuralNetworkList)//check for existing network with same name
				{
					if (nn->name == name)	//if found return false
						return false;
				}
				return true;
			}

			//create new hidden layer input
			Control^ createHiddenLayerInput()
			{
				//create containing panel
				Panel^ newPanel = gcnew Panel();
					newPanel->Location = System::Drawing::Point(3, 3+counter*HLcontrolOffset);
					newPanel->Name = "panel_"+counter;
					newPanel->Size = System::Drawing::Size(170, 25);

				//create hidden layer label
				Label^ newLabel = gcnew Label();
					newLabel->AutoSize = true;
					newLabel->Location = System::Drawing::Point(3, 6);
					newLabel->Name = L"label_"+counter;
					newLabel->Size = System::Drawing::Size(82, 13);
					newLabel->Text = L"Hidden-Layer:";

				//create hiddne layer node text box
				TextBox^ newTB = gcnew TextBox();
					newTB->Location = System::Drawing::Point(91, 3);
					newTB->Name = "textBox_"+counter;
					newTB->Size = System::Drawing::Size(34, 20);
					newTB->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &NewNN::textBox1_KeyPress);
						hiddenInput->Add(newTB);

				//create hidden layer delete button
				Button^ newButton = gcnew Button();
					newButton->Location = System::Drawing::Point(134, 3);
					newButton->Name = "button"+counter;
					newButton->Size = System::Drawing::Size(33, 20);
					newButton->Text = L"-";
					newButton->Click+= gcnew System::EventHandler(this, &NewNN::deleteRow);
				
				//ad to containing panel
				newPanel->Controls->Add(newLabel);
				newPanel->Controls->Add(newTB);
				newPanel->Controls->Add(newButton);

				//add to hidden layer panel
				ListHiddenLayers->Add(newPanel);
				counter++;

				return newPanel;	//reutn new panel
			}

			//delete hidden layer input
			void deleteHiddenLayerInput(System::Windows::Forms::Control^ selection)
			{
				System::Drawing::Point position = selection->Location;
				int Y = position.Y;	//get delete position

				hiddenLayers->Controls->Remove(selection);	//remove control from hidden layer panel
				ListHiddenLayers->Remove(selection);		//remove control from hidden layer list
				counter--;									//decrease counter

				for each(Control^ control in ListHiddenLayers)	//for each remaining hidden panel
				{
					int x = control->Location.Y;	//get location
					if (x > Y)	//if location is bigger than deleted location
					{
						Point newDrawPoint = System::Drawing::Point::Subtract(control->Location, System::Drawing::Size(0, HLcontrolOffset));	//move up 1 slot
						control->Location = newDrawPoint;	//draw at new spott
					}
				}
			}
#pragma endregion
};
}
