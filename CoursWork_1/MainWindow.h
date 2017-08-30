#pragma once

#include "ACR.h"
#include "NewNN.h"
#include "ApplicationStatistics.h"

#include "NeuralNetwork.h"

#include "FileIO.h"
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <wininet.h>
#include <vcclr.h>

#pragma comment (lib, "wininet.lib")

#define WLcontrolOffset 106	//offest for Watch list
#define DPHcontrolOffset 81	//ofsetfor history data

namespace CoursWork_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Resources;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
#pragma region Components
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  hour;


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  neuralNetworkToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trainToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ComboBox^  cB_NeuralNetworks;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Timer^  TimeFrame;
	private: System::Windows::Forms::GroupBox^  groupBoxWL;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBoxDPH;

	private: System::Windows::Forms::Panel^  WLContainer;
	private: System::Windows::Forms::Panel^  DPHContainer;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  DPG;

	private: System::Windows::Forms::PictureBox^  AddCER;

	private: System::Windows::Forms::GroupBox^  groupBox11;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::PictureBox^  pictureBox14;
	private: System::Windows::Forms::GroupBox^  groupBox10;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::PictureBox^  pictureBox13;
	private: System::Windows::Forms::GroupBox^  groupBox9;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::PictureBox^  pictureBox12;
	private: System::Windows::Forms::GroupBox^  groupBox8;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::PictureBox^  pictureBox11;
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::PictureBox^  pictureBox10;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::PictureBox^  pictureBox8;
	private: System::Windows::Forms::PictureBox^  pictureBox9;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::GroupBox^  _groupBox1;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  applicationStatisticsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::CheckBox^  LTSwitch;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fromApplicationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  filesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Timer^  time;
private: System::Windows::Forms::Label^  dateLabel;

private: System::Windows::Forms::Label^  timeLabel;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
private: System::Windows::Forms::Label^  lastFeed;
private: System::Windows::Forms::PictureBox^  PredictionBox;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::TextBox^  min;

private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::TextBox^  sec;

private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::TextBox^  windowSize;
private: System::Windows::Forms::Label^  label26;







	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
#pragma endregion


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->hour = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->applicationStatisticsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->neuralNetworkToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fromApplicationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cB_NeuralNetworks = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->TimeFrame = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBoxWL = (gcnew System::Windows::Forms::GroupBox());
			this->lastFeed = (gcnew System::Windows::Forms::Label());
			this->LTSwitch = (gcnew System::Windows::Forms::CheckBox());
			this->AddCER = (gcnew System::Windows::Forms::PictureBox());
			this->WLContainer = (gcnew System::Windows::Forms::Panel());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->_groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->PredictionBox = (gcnew System::Windows::Forms::PictureBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->windowSize = (gcnew System::Windows::Forms::TextBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->DPG = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBoxDPH = (gcnew System::Windows::Forms::GroupBox());
			this->DPHContainer = (gcnew System::Windows::Forms::Panel());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->time = (gcnew System::Windows::Forms::Timer(this->components));
			this->dateLabel = (gcnew System::Windows::Forms::Label());
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->min = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->sec = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->groupBoxWL->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AddCER))->BeginInit();
			this->WLContainer->SuspendLayout();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->_groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PredictionBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DPG))->BeginInit();
			this->groupBoxDPH->SuspendLayout();
			this->DPHContainer->SuspendLayout();
			this->groupBox11->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
			this->groupBox10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			this->groupBox9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			this->groupBox8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			this->groupBox7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(137, 53);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 21);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWindow::button1_Click);
			// 
			// hour
			// 
			this->hour->Location = System::Drawing::Point(286, 55);
			this->hour->Name = L"hour";
			this->hour->Size = System::Drawing::Size(29, 20);
			this->hour->TabIndex = 2;
			this->hour->TabStop = false;
			this->hour->Text = L"0";
			this->hour->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainWindow::timeFrame_KeyPress);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuToolStripMenuItem,
					this->neuralNetworkToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(973, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->applicationStatisticsToolStripMenuItem,
					this->toolStripMenuItem3, this->exitToolStripMenuItem
			});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// applicationStatisticsToolStripMenuItem
			// 
			this->applicationStatisticsToolStripMenuItem->Name = L"applicationStatisticsToolStripMenuItem";
			this->applicationStatisticsToolStripMenuItem->Size = System::Drawing::Size(184, 22);
			this->applicationStatisticsToolStripMenuItem->Text = L"Application Statistics";
			this->applicationStatisticsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::applicationStatisticsToolStripMenuItem_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Enabled = false;
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(184, 22);
			this->toolStripMenuItem3->Text = L"------";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(184, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::exitToolStripMenuItem_Click);
			// 
			// neuralNetworkToolStripMenuItem
			// 
			this->neuralNetworkToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->newToolStripMenuItem,
					this->trainToolStripMenuItem, this->saveToolStripMenuItem, this->loadToolStripMenuItem, this->deleteToolStripMenuItem, this->toolStripMenuItem2
			});
			this->neuralNetworkToolStripMenuItem->Name = L"neuralNetworkToolStripMenuItem";
			this->neuralNetworkToolStripMenuItem->Size = System::Drawing::Size(102, 20);
			this->neuralNetworkToolStripMenuItem->Text = L"Neural Network";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->newToolStripMenuItem->Text = L"New";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::newToolStripMenuItem_Click);
			// 
			// trainToolStripMenuItem
			// 
			this->trainToolStripMenuItem->Name = L"trainToolStripMenuItem";
			this->trainToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->trainToolStripMenuItem->Text = L"Train";
			this->trainToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::trainToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Enabled = false;
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShowShortcutKeys = false;
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveToolStripMenuItem->Text = L"------";
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->saveToolStripMenuItem1,
					this->saveAsToolStripMenuItem
			});
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->loadToolStripMenuItem->Text = L"Save";
			// 
			// saveToolStripMenuItem1
			// 
			this->saveToolStripMenuItem1->Name = L"saveToolStripMenuItem1";
			this->saveToolStripMenuItem1->Size = System::Drawing::Size(114, 22);
			this->saveToolStripMenuItem1->Text = L"Save";
			this->saveToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWindow::saveToolStripMenuItem1_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->saveAsToolStripMenuItem->Text = L"Save As";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::saveAsToolStripMenuItem_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->deleteToolStripMenuItem->Text = L"Load";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::LoadSavedNN);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fromApplicationToolStripMenuItem,
					this->filesToolStripMenuItem
			});
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(152, 22);
			this->toolStripMenuItem2->Text = L"Delete";
			// 
			// fromApplicationToolStripMenuItem
			// 
			this->fromApplicationToolStripMenuItem->Name = L"fromApplicationToolStripMenuItem";
			this->fromApplicationToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->fromApplicationToolStripMenuItem->Text = L"from Application";
			this->fromApplicationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::deleteNN);
			// 
			// filesToolStripMenuItem
			// 
			this->filesToolStripMenuItem->Name = L"filesToolStripMenuItem";
			this->filesToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->filesToolStripMenuItem->Text = L"incl. Files";
			this->filesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::deleteNNIncFiles);
			// 
			// cB_NeuralNetworks
			// 
			this->cB_NeuralNetworks->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->cB_NeuralNetworks->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->cB_NeuralNetworks->FormattingEnabled = true;
			this->cB_NeuralNetworks->Location = System::Drawing::Point(10, 53);
			this->cB_NeuralNetworks->Name = L"cB_NeuralNetworks";
			this->cB_NeuralNetworks->Size = System::Drawing::Size(121, 21);
			this->cB_NeuralNetworks->TabIndex = 1;
			this->cB_NeuralNetworks->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::cB_NeuralNetworks_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Prediction Algorithm:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(134, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Get Live Data:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(293, 35);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Time Frame:";
			// 
			// TimeFrame
			// 
			this->TimeFrame->Interval = 5000;
			this->TimeFrame->Tick += gcnew System::EventHandler(this, &MainWindow::TimeFrame_Tick);
			// 
			// groupBoxWL
			// 
			this->groupBoxWL->Controls->Add(this->lastFeed);
			this->groupBoxWL->Controls->Add(this->LTSwitch);
			this->groupBoxWL->Controls->Add(this->AddCER);
			this->groupBoxWL->Controls->Add(this->WLContainer);
			this->groupBoxWL->Controls->Add(this->groupBox2);
			this->groupBoxWL->Location = System::Drawing::Point(10, 80);
			this->groupBoxWL->Name = L"groupBoxWL";
			this->groupBoxWL->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->groupBoxWL->Size = System::Drawing::Size(200, 404);
			this->groupBoxWL->TabIndex = 8;
			this->groupBoxWL->TabStop = false;
			this->groupBoxWL->Text = L"WatchList (Live Data)";
			// 
			// lastFeed
			// 
			this->lastFeed->AutoSize = true;
			this->lastFeed->Location = System::Drawing::Point(6, 16);
			this->lastFeed->Name = L"lastFeed";
			this->lastFeed->Size = System::Drawing::Size(57, 13);
			this->lastFeed->TabIndex = 16;
			this->lastFeed->Text = L"Last Feed:";
			// 
			// LTSwitch
			// 
			this->LTSwitch->AutoSize = true;
			this->LTSwitch->Location = System::Drawing::Point(6, 379);
			this->LTSwitch->Name = L"LTSwitch";
			this->LTSwitch->Size = System::Drawing::Size(83, 17);
			this->LTSwitch->TabIndex = 11;
			this->LTSwitch->Text = L"Live training";
			this->LTSwitch->UseVisualStyleBackColor = true;
			// 
			// AddCER
			// 
			this->AddCER->BackColor = System::Drawing::SystemColors::Control;
			this->AddCER->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddCER.Image")));
			this->AddCER->Location = System::Drawing::Point(162, 366);
			this->AddCER->Name = L"AddCER";
			this->AddCER->Size = System::Drawing::Size(32, 32);
			this->AddCER->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->AddCER->TabIndex = 1;
			this->AddCER->TabStop = false;
			this->AddCER->Click += gcnew System::EventHandler(this, &MainWindow::AddCER_Click);
			// 
			// WLContainer
			// 
			this->WLContainer->AutoScroll = true;
			this->WLContainer->Controls->Add(this->groupBox6);
			this->WLContainer->Controls->Add(this->groupBox5);
			this->WLContainer->Controls->Add(this->groupBox4);
			this->WLContainer->Controls->Add(this->_groupBox1);
			this->WLContainer->Location = System::Drawing::Point(0, 33);
			this->WLContainer->Name = L"WLContainer";
			this->WLContainer->Size = System::Drawing::Size(200, 327);
			this->WLContainer->TabIndex = 10;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->label10);
			this->groupBox6->Controls->Add(this->label11);
			this->groupBox6->Controls->Add(this->pictureBox8);
			this->groupBox6->Controls->Add(this->pictureBox9);
			this->groupBox6->Location = System::Drawing::Point(3, 321);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(177, 100);
			this->groupBox6->TabIndex = 14;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"GBP-EUR";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(10, 62);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(114, 13);
			this->label10->TabIndex = 13;
			this->label10->Text = L"Date/Time (Last Feed)";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(7, 20);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(81, 13);
			this->label11->TabIndex = 12;
			this->label11->Text = L"Exchange Rate";
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(139, 19);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(32, 32);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox8->TabIndex = 11;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(139, 62);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(32, 32);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox9->TabIndex = 0;
			this->pictureBox9->TabStop = false;
			// 
			// groupBox5
			// 
			this->groupBox5->BackColor = System::Drawing::Color::Transparent;
			this->groupBox5->Controls->Add(this->label8);
			this->groupBox5->Controls->Add(this->label9);
			this->groupBox5->Controls->Add(this->pictureBox6);
			this->groupBox5->Controls->Add(this->pictureBox7);
			this->groupBox5->Location = System::Drawing::Point(3, 215);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(177, 100);
			this->groupBox5->TabIndex = 14;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"GBP-EUR";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(10, 62);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(114, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Date/Time (Last Feed)";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(7, 20);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(81, 13);
			this->label9->TabIndex = 12;
			this->label9->Text = L"Exchange Rate";
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(139, 19);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(32, 32);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox6->TabIndex = 11;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(139, 62);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(32, 32);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox7->TabIndex = 0;
			this->pictureBox7->TabStop = false;
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::Color::Transparent;
			this->groupBox4->Controls->Add(this->label6);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->pictureBox4);
			this->groupBox4->Controls->Add(this->pictureBox5);
			this->groupBox4->Location = System::Drawing::Point(3, 109);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(177, 100);
			this->groupBox4->TabIndex = 14;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"GBP-EUR";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(10, 62);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(114, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Date/Time (Last Feed)";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(7, 20);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(81, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Exchange Rate";
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(139, 19);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(32, 32);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox4->TabIndex = 11;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(139, 62);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(32, 32);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox5->TabIndex = 0;
			this->pictureBox5->TabStop = false;
			// 
			// _groupBox1
			// 
			this->_groupBox1->BackColor = System::Drawing::Color::Yellow;
			this->_groupBox1->Controls->Add(this->PredictionBox);
			this->_groupBox1->Controls->Add(this->label24);
			this->_groupBox1->Controls->Add(this->label23);
			this->_groupBox1->Controls->Add(this->label4);
			this->_groupBox1->Controls->Add(this->pictureBox3);
			this->_groupBox1->Controls->Add(this->pictureBox1);
			this->_groupBox1->Location = System::Drawing::Point(3, 3);
			this->_groupBox1->Name = L"_groupBox1";
			this->_groupBox1->Size = System::Drawing::Size(177, 100);
			this->_groupBox1->TabIndex = 0;
			this->_groupBox1->TabStop = false;
			this->_groupBox1->Text = L"GBP-EUR";
			// 
			// PredictionBox
			// 
			this->PredictionBox->BackColor = System::Drawing::Color::Transparent;
			this->PredictionBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->PredictionBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PredictionBox.Image")));
			this->PredictionBox->Location = System::Drawing::Point(10, 62);
			this->PredictionBox->Name = L"PredictionBox";
			this->PredictionBox->Size = System::Drawing::Size(32, 32);
			this->PredictionBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PredictionBox->TabIndex = 16;
			this->PredictionBox->TabStop = false;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(7, 67);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(16, 13);
			this->label24->TabIndex = 15;
			this->label24->Text = L"...";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(7, 48);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(57, 13);
			this->label23->TabIndex = 14;
			this->label23->Text = L"Prediction:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Exchange Rate";
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(139, 19);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(32, 32);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox3->TabIndex = 11;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(139, 62);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(32, 32);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainWindow::button1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Location = System::Drawing::Point(206, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 363);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->windowSize);
			this->groupBox3->Controls->Add(this->label26);
			this->groupBox3->Controls->Add(this->DPG);
			this->groupBox3->Location = System::Drawing::Point(222, 80);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(541, 404);
			this->groupBox3->TabIndex = 9;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Data Progress Graph";
			// 
			// windowSize
			// 
			this->windowSize->Location = System::Drawing::Point(506, 13);
			this->windowSize->Name = L"windowSize";
			this->windowSize->Size = System::Drawing::Size(29, 20);
			this->windowSize->TabIndex = 20;
			this->windowSize->TabStop = false;
			this->windowSize->Text = L"20";
			this->windowSize->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainWindow::timeFrame_KeyPress);
			this->windowSize->Leave += gcnew System::EventHandler(this, &MainWindow::windowSize_Leave);
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(391, 16);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(109, 13);
			this->label26->TabIndex = 19;
			this->label26->Text = L"Display Window Size:";
			// 
			// DPG
			// 
			this->DPG->BackColor = System::Drawing::Color::Transparent;
			this->DPG->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->DPG->CausesValidation = false;
			chartArea1->AlignmentOrientation = static_cast<System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations>((System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Vertical | System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Horizontal));
			chartArea1->Name = L"ChartArea1";
			this->DPG->ChartAreas->Add(chartArea1);
			this->DPG->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->DPG->Location = System::Drawing::Point(6, 39);
			this->DPG->Name = L"DPG";
			this->DPG->RightToLeft = System::Windows::Forms::RightToLeft::No;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->CustomProperties = L"IsXAxisQuantitative=False, EmptyPointValue=Zero";
			series1->IsXValueIndexed = true;
			series1->Legend = L"Legend1";
			series1->Name = L"CurrencyProgression";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Time;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			this->DPG->Series->Add(series1);
			this->DPG->Size = System::Drawing::Size(529, 359);
			this->DPG->TabIndex = 0;
			this->DPG->TabStop = false;
			this->DPG->Text = L"chart1";
			// 
			// groupBoxDPH
			// 
			this->groupBoxDPH->Controls->Add(this->DPHContainer);
			this->groupBoxDPH->Location = System::Drawing::Point(769, 80);
			this->groupBoxDPH->Name = L"groupBoxDPH";
			this->groupBoxDPH->Size = System::Drawing::Size(200, 404);
			this->groupBoxDPH->TabIndex = 10;
			this->groupBoxDPH->TabStop = false;
			this->groupBoxDPH->Text = L"Data Progression History";
			// 
			// DPHContainer
			// 
			this->DPHContainer->AutoScroll = true;
			this->DPHContainer->Controls->Add(this->groupBox11);
			this->DPHContainer->Controls->Add(this->groupBox10);
			this->DPHContainer->Controls->Add(this->groupBox9);
			this->DPHContainer->Controls->Add(this->groupBox8);
			this->DPHContainer->Controls->Add(this->groupBox7);
			this->DPHContainer->Location = System::Drawing::Point(0, 19);
			this->DPHContainer->Name = L"DPHContainer";
			this->DPHContainer->Size = System::Drawing::Size(200, 379);
			this->DPHContainer->TabIndex = 11;
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->label20);
			this->groupBox11->Controls->Add(this->label21);
			this->groupBox11->Controls->Add(this->pictureBox14);
			this->groupBox11->Location = System::Drawing::Point(3, 327);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(177, 75);
			this->groupBox11->TabIndex = 16;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"GBP-EUR";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(6, 20);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(58, 13);
			this->label20->TabIndex = 13;
			this->label20->Text = L"Date/Time";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(6, 43);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(81, 13);
			this->label21->TabIndex = 12;
			this->label21->Text = L"Exchange Rate";
			// 
			// pictureBox14
			// 
			this->pictureBox14->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox14.Image")));
			this->pictureBox14->Location = System::Drawing::Point(139, 33);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(32, 32);
			this->pictureBox14->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox14->TabIndex = 11;
			this->pictureBox14->TabStop = false;
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->label18);
			this->groupBox10->Controls->Add(this->label19);
			this->groupBox10->Controls->Add(this->pictureBox13);
			this->groupBox10->Location = System::Drawing::Point(3, 246);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(177, 75);
			this->groupBox10->TabIndex = 16;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"GBP-EUR";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(6, 20);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(58, 13);
			this->label18->TabIndex = 13;
			this->label18->Text = L"Date/Time";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(6, 43);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(81, 13);
			this->label19->TabIndex = 12;
			this->label19->Text = L"Exchange Rate";
			// 
			// pictureBox13
			// 
			this->pictureBox13->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.Image")));
			this->pictureBox13->Location = System::Drawing::Point(139, 33);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(32, 32);
			this->pictureBox13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox13->TabIndex = 11;
			this->pictureBox13->TabStop = false;
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->label16);
			this->groupBox9->Controls->Add(this->label17);
			this->groupBox9->Controls->Add(this->pictureBox12);
			this->groupBox9->Location = System::Drawing::Point(3, 165);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(177, 75);
			this->groupBox9->TabIndex = 16;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"GBP-EUR";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(6, 20);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(58, 13);
			this->label16->TabIndex = 13;
			this->label16->Text = L"Date/Time";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(6, 43);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(81, 13);
			this->label17->TabIndex = 12;
			this->label17->Text = L"Exchange Rate";
			// 
			// pictureBox12
			// 
			this->pictureBox12->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.Image")));
			this->pictureBox12->Location = System::Drawing::Point(139, 33);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(32, 32);
			this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox12->TabIndex = 11;
			this->pictureBox12->TabStop = false;
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->label14);
			this->groupBox8->Controls->Add(this->label15);
			this->groupBox8->Controls->Add(this->pictureBox11);
			this->groupBox8->Location = System::Drawing::Point(3, 84);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(177, 75);
			this->groupBox8->TabIndex = 16;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"GBP-EUR";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(6, 20);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(58, 13);
			this->label14->TabIndex = 13;
			this->label14->Text = L"Date/Time";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(6, 43);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(81, 13);
			this->label15->TabIndex = 12;
			this->label15->Text = L"Exchange Rate";
			// 
			// pictureBox11
			// 
			this->pictureBox11->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.Image")));
			this->pictureBox11->Location = System::Drawing::Point(139, 33);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(32, 32);
			this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox11->TabIndex = 11;
			this->pictureBox11->TabStop = false;
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->label12);
			this->groupBox7->Controls->Add(this->label13);
			this->groupBox7->Controls->Add(this->pictureBox10);
			this->groupBox7->Location = System::Drawing::Point(3, 3);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(177, 75);
			this->groupBox7->TabIndex = 15;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"GBP-EUR";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 20);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(58, 13);
			this->label12->TabIndex = 13;
			this->label12->Text = L"Date/Time";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 43);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(81, 13);
			this->label13->TabIndex = 12;
			this->label13->Text = L"Exchange Rate";
			// 
			// pictureBox10
			// 
			this->pictureBox10->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(139, 33);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(32, 32);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox10->TabIndex = 11;
			this->pictureBox10->TabStop = false;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(321, 58);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(31, 13);
			this->label22->TabIndex = 11;
			this->label22->Text = L"hour,";
			// 
			// time
			// 
			this->time->Enabled = true;
			this->time->Interval = 1000;
			this->time->Tick += gcnew System::EventHandler(this, &MainWindow::time_Tick);
			// 
			// dateLabel
			// 
			this->dateLabel->AutoSize = true;
			this->dateLabel->Location = System::Drawing::Point(908, 34);
			this->dateLabel->Name = L"dateLabel";
			this->dateLabel->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->dateLabel->Size = System::Drawing::Size(10, 13);
			this->dateLabel->TabIndex = 12;
			this->dateLabel->Text = L"-";
			// 
			// timeLabel
			// 
			this->timeLabel->AutoSize = true;
			this->timeLabel->Location = System::Drawing::Point(908, 54);
			this->timeLabel->Name = L"timeLabel";
			this->timeLabel->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->timeLabel->Size = System::Drawing::Size(10, 13);
			this->timeLabel->TabIndex = 13;
			this->timeLabel->Text = L"-";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"txt";
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"txt";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(390, 57);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(26, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"min,";
			// 
			// min
			// 
			this->min->Location = System::Drawing::Point(355, 54);
			this->min->Name = L"min";
			this->min->Size = System::Drawing::Size(29, 20);
			this->min->TabIndex = 14;
			this->min->TabStop = false;
			this->min->Text = L"0";
			this->min->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainWindow::timeFrame_KeyPress);
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(454, 57);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(24, 13);
			this->label25->TabIndex = 17;
			this->label25->Text = L"sec";
			// 
			// sec
			// 
			this->sec->Location = System::Drawing::Point(419, 54);
			this->sec->Name = L"sec";
			this->sec->Size = System::Drawing::Size(29, 20);
			this->sec->TabIndex = 16;
			this->sec->TabStop = false;
			this->sec->Text = L"5";
			this->sec->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainWindow::timeFrame_KeyPress);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(384, 31);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(41, 21);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Apply";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainWindow::textBox1_Leave);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ClientSize = System::Drawing::Size(973, 486);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->sec);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->min);
			this->Controls->Add(this->timeLabel);
			this->Controls->Add(this->dateLabel);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->groupBoxDPH);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBoxWL);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cB_NeuralNetworks);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->hour);
			this->Controls->Add(this->button1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainWindow";
			this->Text = L"Currency Exchange Watcher";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainWindow::MainWindow_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBoxWL->ResumeLayout(false);
			this->groupBoxWL->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AddCER))->EndInit();
			this->WLContainer->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->_groupBox1->ResumeLayout(false);
			this->_groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PredictionBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DPG))->EndInit();
			this->groupBoxDPH->ResumeLayout(false);
			this->DPHContainer->ResumeLayout(false);
			this->groupBox11->ResumeLayout(false);
			this->groupBox11->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region variables
	private:
		ResourceManager^ resourceManager = gcnew ResourceManager("CoursWork_1.Images", GetType()->Assembly);
		ResourceManager^ resourceManagerStatistic = gcnew ResourceManager("CoursWork_1.Statistics", GetType()->Assembly);
		ACR^ acr = gcnew ACR();
		ApplicationStatistics^ AppStats = gcnew ApplicationStatistics();

		bool readLiveData = false;
		bool currentNetworkType=false;

		int counter = 0;
		int DPHcounter = 0;
		int neddedBuffer = 1;

		double HDnumberbuffer = 0;
		double liveHDnumberbuffer = 0;
		double historymin = 1;
		double historymax =0;

		int displayWindowSize=20;

		double oldValue = 0;
		double newValue = 0;
		double insertValue = 0;

		int countTrend;
		int correctTrend;
		int countScale;
		int correctScale;

		Control^ selectionBuffer=nullptr;

		Generic::List<Control^>^ WatchList = gcnew Generic::List<Control^>();
		Generic::List<Control^>^ HistoryData = gcnew Generic::List<Control^>();

		Generic::List<String^>^ searchParameters = gcnew Generic::List<String^>();
		Generic::List<NeuralNetwork^>^ NeuralNetworkList = gcnew Generic::List<NeuralNetwork^>();
		Generic::List<array<double>^>^ NNBufferList = gcnew Generic::List<array<double>^>();
		Generic::List<double>^ lastXR = gcnew Generic::List<double>();
		Generic::List<array<double>^>^ reTrainData = gcnew Generic::List<array<double>^>();
		Generic::List<int>^ bufferCounter= gcnew Generic::List<int>();
		Generic::List<bool>^ firstTrigger = gcnew Generic::List<bool>();

#pragma endregion

#pragma region eventHandlers
	private:
		//key press event for timer setting
		System::Void timeFrame_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
		{
			if (!Char::IsDigit(e->KeyChar)&&!(e->KeyChar == 8)) //if key press is digit or backspace
			{
				e->Handled = true;
			}
		}

		//form load event 
		System::Void MainWindow_Load(System::Object^  sender, System::EventArgs^  e)
		{
			if (!File::Exists("FileIO/Statistics/Stats.txt"))//if no stats file found
			{
				writeToFile("FileIO/Statistics/","Stats.txt","01-01-01\r\n12:00:00\r\n0\r\n0\r\n0\r\n0", false); //create default stats
			}
			loadStats();//load stats

			WLContainer->Controls->Clear(); //clear currency container
			DPHContainer->Controls->Clear(); //clear history data container
			button1->Enabled = false;		//disable start button
		}

		//time frame tick event
		System::Void TimeFrame_Tick(System::Object^  se1nder, System::EventArgs^  e) 
		{
				//RUN PREDICTION AND UPDATE FUNCTIONS
			if (searchParameters->Count > 0)	//if currencies to watch exist
			{
				array<String^, 2>^ out = parseInternetRead(getLiveData(createSearchPara()), searchParameters->Count); //get internet data
				lastFeed->Text = "Last Feed:" + out[0, 0] + " at " + out[0, 1]; //set last feed time

				runUpdate(out);	//run update

			}
			else
			{
				MessageBox::Show("Please create a WatchBox to begin reading live data.");
			}
		}

		//timer tick event
		System::Void time_Tick(System::Object^  sender, System::EventArgs^  e) 
		{
			//get and set current time and date
			String^ day = ""; String^ month = ""; String^ year = DateTime::Now.Date.Year.ToString(); String^ sec = ""; String^ min = ""; String^ hour = "";
			if (DateTime::Now.Date.Day < 10)
			{
				day = "0" + DateTime::Now.Date.Day.ToString();
			}
			else
			{
				day= DateTime::Now.Date.Day.ToString();
			}
			if (DateTime::Now.Date.Month < 10)
			{
				month = "0" + DateTime::Now.Date.Month.ToString();
			}
			else
			{
				month = DateTime::Now.Date.Month.ToString();
			}

			if (DateTime::Now.ToLocalTime().Hour < 10)
			{
				hour = "0" + DateTime::Now.ToLocalTime().Hour.ToString();
			}
			else
			{
				hour = DateTime::Now.ToLocalTime().Hour.ToString();
			}

			if (DateTime::Now.ToLocalTime().Minute < 10)
			{
				min = "0" + DateTime::Now.ToLocalTime().Minute.ToString();
			}
			else
			{
				min = DateTime::Now.ToLocalTime().Minute.ToString();
			}

			if (DateTime::Now.ToLocalTime().Second < 10)
			{
				sec = "0" + DateTime::Now.ToLocalTime().Second.ToString();
			}
			else
			{
				sec = DateTime::Now.ToLocalTime().Second.ToString();
			}

			dateLabel->Text = day+"-"+ month + "-" + year;
			timeLabel->Text = hour+ ":" + min + ":" + sec;
		}

		//start button click event
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			Control^ senderControl = dynamic_cast<Control^>(sender);

			//swap button text
			if(senderControl->Text=="Start")
			{ 
				senderControl->Text = "Stop";
			}
			else
			{
				senderControl->Text = "Start";
			}
			
			TimeFrame->Enabled = !TimeFrame->Enabled;//enable or disable update timer
		}

		//add currency button click event
		System::Void AddCER_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			acr->StartPosition = FormStartPosition::CenterParent;	//set start position center of application
			acr->ShowDialog();//shoe form
			
			if (acr->currencySelection != "" && (Controls->Find(acr->currencySelection, true)->Length == 0))	//if selection is valid
			{
				array<double>^ buffer = gcnew array<double>(neddedBuffer);	//create array for value buffer
				NNBufferList->Add(buffer);									//add to buffer lsit

				createWatchBox(acr->currencySelection);						//create currency watch box
			}
			else if(Controls->Find(acr->currencySelection, true)->Length == 1)		//if currency already watched
			{ 
				MessageBox::Show("Already in watch list.");
			}
		}

		//delete curency button click event
		System::Void deleteWLObject(System::Object^  sender, System::EventArgs^  e)
		{
			Control^ senderControl = dynamic_cast<Control^>(sender);
			if (senderControl != nullptr)		//if sender valid
			{
				if (senderControl->Parent->BackColor == Color::Yellow)	//if watch box currently selected
				{
					//clear history box and graph
					DPHContainer->Controls->Clear();
					DPG->Series[0]->Points->Clear();
					DPHcounter = 0;
				}

				deleteWatchBox(senderControl->Parent);	//delete watch box
			}
			else
			{
				MessageBox::Show("Sender element not valid please try again.");
			}
		}

		//currency segment click event
		System::Void loadHDForSelection(System::Object^  sender, System::EventArgs^  e)
		{
			Control^ senderControl = dynamic_cast<Control^>(sender);
			if (senderControl != nullptr)		//if sender element valid
			{
				if (selectionBuffer != nullptr)	//if selection buffer not null pointer
				{
					selectionBuffer->BackColor = System::Drawing::Color::Transparent; //set background color for selection buffer
				}

				senderControl->BackColor = System::Drawing::Color::Yellow;//set background color for selection
				selectionBuffer = senderControl;//place selection in buffer

				//clear history data and graph
				DPHContainer->Controls->Clear();	
				DPG->Series[0]->Points->Clear();
				DPHcounter = 0;

				buildHData(senderControl->Name);//build history data 
			}
			else
			{
				MessageBox::Show("Sender element not valid please try again.");
			}
		}

		//apply button click event
		System::Void textBox1_Leave(System::Object^  sender, System::EventArgs^  e) 
		{
			//set default values if empty
			if (hour->Text == "")
				hour->Text = "0";
			if(min->Text=="")
				min->Text = "0";
			if (sec->Text == "")
				sec->Text = "0";

			//calculate timer
			int timer = (int)(3600000 * Convert::ToDouble(hour->Text) + 60000 * Convert::ToDouble(min->Text) + 1000 * Convert::ToDouble(sec->Text));

			if(timer>0) //if timer value valid
			{
				TimeFrame->Interval = timer;//set timer
				MessageBox::Show("Time interval has been set to: "+hour->Text+" hours, "+min->Text+" minutes, "+sec->Text+" seconds");
			}
			else //set default
			{
				TimeFrame->Interval = 5000;
				sec->Text = "5";
				min->Text = "0";
				hour->Text = "0";

				MessageBox::Show("Time interval can not be les or equal to 0. Timer reset to default value 5 seconds.");
			}
		}

		//new network click event
		System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			NewNN^ newNetwork = gcnew NewNN;
			newNetwork->StartPosition = FormStartPosition::CenterParent;	//set start position for form

			newNetwork->NeuralNetworkList = NeuralNetworkList;		//parse neural network list
			newNetwork->ShowDialog();								//show form

			if (newNetwork->newNeuralNetwork != nullptr)			//if valid new network is created
			{
				NeuralNetworkList->Add(newNetwork->newNeuralNetwork);	//ad to entwork list

				//add to network combobox
				cB_NeuralNetworks->Items->Add(newNetwork->newNeuralNetwork->name);						
				cB_NeuralNetworks->AutoCompleteCustomSource->Add(newNetwork->newNeuralNetwork->name);
			}
		}

		//delete network click event
		System::Void deleteNN(System::Object^  sender, System::EventArgs^  e)
		{
			if(cB_NeuralNetworks->SelectedIndex==-1)//if combobox selection is not valid
			{
				MessageBox::Show("You need to select a Neural Network before performing this function.");
			}
			else if(MessageBox::Show(
				"Are you sure that you would like to delete the selected network?",
				"Deleting Network", MessageBoxButtons::YesNo,
				MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)//user security check
			{
				//delete network and all references to it
				NeuralNetworkList->RemoveAt(cB_NeuralNetworks->SelectedIndex);
				cB_NeuralNetworks->AutoCompleteCustomSource->RemoveAt(cB_NeuralNetworks->SelectedIndex);
				cB_NeuralNetworks->Items->RemoveAt(cB_NeuralNetworks->SelectedIndex);
				cB_NeuralNetworks->SelectedIndex=-1;
				button1->Enabled = false;
				cB_NeuralNetworks->Text = "";

				MessageBox::Show("Network has been deleted.");
			}
		}

		//delete with files click event
		System::Void deleteNNIncFiles(System::Object^  sender, System::EventArgs^  e)
		{
			if (cB_NeuralNetworks->SelectedIndex == -1)	//if combo box selection is not valid
			{
				MessageBox::Show("You need to select a Neural Network before performing this function.");
			}
			else if(MessageBox::Show(
				"Are you sure that you would like to delete the selected network and all application created files?",
				"Deleting Network and related files", MessageBoxButtons::YesNo,
				MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)//user security check
			{
				deleteFiles(NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]->name);	//selete all files created by the programm

				//remove neural network and all referenced to it
				NeuralNetworkList->RemoveAt(cB_NeuralNetworks->SelectedIndex);
				cB_NeuralNetworks->AutoCompleteCustomSource->RemoveAt(cB_NeuralNetworks->SelectedIndex);
				cB_NeuralNetworks->Items->RemoveAt(cB_NeuralNetworks->SelectedIndex);
				cB_NeuralNetworks->SelectedIndex = -1;
				cB_NeuralNetworks->Text = "";

				MessageBox::Show("Network and all application generated files have been deleted.");
			}
		}

		//show statistic click event
		System::Void applicationStatisticsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			AppStats->StartPosition = FormStartPosition::CenterParent;	//set starting position for form
			AppStats->ShowDialog();		//show form
		}

		//save neural network click event
		System::Void saveToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			try
			{
				saveNeuralNetwork(NeuralNetworkList[cB_NeuralNetworks->SelectedIndex], "FileIO/NN_Saves/","NN_Save_"+ NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]->name+".txt");//save neural network in text file
				MessageBox::Show("Neural Network saved");
			}
			catch (Exception^ e)	//catch exception
			{
				MessageBox::Show("Could not save File. Error:" + e->Message);
			}
		}

		//load neural network click event
		System::Void LoadSavedNN(System::Object^  sender, System::EventArgs^  e) 
		{
			try
			{
				if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)	//select save file
				{					
					NeuralNetwork^ loadedNetwork = loadNeuralNetwork(openFileDialog1->FileName);//load neural network

					if (loadedNetwork != nullptr)	//if network wsa created
					{
						//add network to all lists
						NeuralNetworkList->Add(loadedNetwork);

						cB_NeuralNetworks->Items->Add(loadedNetwork->name);
						cB_NeuralNetworks->AutoCompleteCustomSource->Add(loadedNetwork->name);

						MessageBox::Show("Neural Network loaded");
					}
					else
					{
						MessageBox::Show("Neural network could not be loaded");
					}
				}
			}
			catch (Exception^ e)	//catch exceptions
			{
				MessageBox::Show("Could not load File. Error:" + e->Message);
			}
		}

		//combo box index change event
		System::Void cB_NeuralNetworks_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			NNBufferList->Clear();//clear buffer lists
			if (cB_NeuralNetworks->SelectedIndex != -1)//if combobox selection valid
			{
				button1->Enabled = true;	//enable start button
				TimeFrame->Enabled = false;	//stop update timer
				button1->Text = "Start";	//set start button text to start

				neddedBuffer = NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]->_Input->LayerNodes;	//get needed buffer value
				for each(int x in bufferCounter)
				{
					//set all buffercounter values to 0
					x = 0;
				}

				for each(bool x in firstTrigger)
				{
					//set all first trigger to ture
					x = true;
				}

				for each(Control ^ control in WatchList)
				{
					//create and set all buffers
					array<double>^ buffer = gcnew array<double>(neddedBuffer);
					NNBufferList->Add(buffer);
				}

				//adjust watchlist to network type
				adjustToNetworkType(NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]->scaling);
			}
			else
			{ 
				//set everythign to defaults
				neddedBuffer = 0;

				for each(int x in bufferCounter)
				{
					x = 0;
				}
				for each(bool x in firstTrigger)
				{
					x = true;
				}

				TimeFrame->Enabled = false;
				button1->Text = "Start";
				button1->Enabled = false;
			}
		}

		//save network as click event
		System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			try
			{
				if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) //select file to save into
				{
					String^ file = saveFileDialog1->FileName;

					array<String^>^ splittInput = file->Split('\\');
					String^ fileName = splittInput[splittInput->Length - 1];
					String^ path = file->Remove(file->Length - fileName->Length);	//split complete file path into filename and file path

					if (fileName->Contains("NN_Save_")) //if it contains
					{
						NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]->name = fileName->Substring(8)->Split('.')[0]; //set name remove beginning
					}
					else
					{
						NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]->name = fileName->Split('.')[0];	//set name
						fileName = "NN_Save_" + fileName;	//add to name
					}

					NeuralNetworkList->Add(NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]); //add to network lists

					cB_NeuralNetworks->Items->Add(NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]->name);
					cB_NeuralNetworks->AutoCompleteCustomSource->Add(NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]->name);
					
					saveNeuralNetwork(NeuralNetworkList[cB_NeuralNetworks->SelectedIndex],path,fileName);//save network
					MessageBox::Show("Neural Network saved");
				}
			}
			catch (Exception^ e)	//catch error
			{
				MessageBox::Show("Could not save File. Error:" + e->Message);
			}
		}

		//on form closing event
		System::Void MainWindow_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
		{
			saveToStats();//save stats
		}

		//exit click event
		System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			this->Close();	//close this form
		}

		//set sample size event
		System::Void windowSize_Leave(System::Object^  sender, System::EventArgs^  e) 
		{
			displayWindowSize = Convert::ToInt32(windowSize->Text);//convert window size

			if (displayWindowSize <= 0)//if size smaller equal to 0
			{
				//set default 20
				displayWindowSize = 20;
				windowSize->Text = "20";
			}

			if (selectionBuffer != nullptr)//if selection buffer is nit nullptr
			{
				//clear history data
				DPHContainer->Controls->Clear();
				DPG->Series[0]->Points->Clear();
				DPHcounter = 0;

				//build history data
				buildHData(selectionBuffer->Name);
			}
		}

		//train neural net event
		System::Void trainToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (cB_NeuralNetworks->SelectedIndex != -1)	//if seletion is valid
			{
				try
				{
					if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)	//get training file
					{
						int nodes = NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]->_Input->LayerNodes + NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]->_Output->LayerNodes; //get in and out nodes
						Generic::List<array<double>^>^ trainData = parseTrainignData(nodes, openFileDialog1->FileName);	//get train data parsed

						NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]->trainNeuralNetwork(NeuralNetworkList[cB_NeuralNetworks->SelectedIndex], trainData, false); //train network

						MessageBox::Show("Neural network has been trained with given training data");
					}
				}
				catch (Exception^ e)	//catch exceptions
				{
					MessageBox::Show("Could not load File. Error:" + e->Message);
				}
			}
			else
			{
				MessageBox::Show("Please select a neural network for training.");
			}
		}
#pragma endregion

#pragma region controlBuilder
		//create new currency watch control
		void createWatchBox(String^ currencySearchPara)
		{
			WLContainer->AutoScroll = false;//set container to top position

			//create new currecy container
			GroupBox^ groupBox = gcnew GroupBox;
				groupBox->Name = currencySearchPara;
					searchParameters->Add(currencySearchPara);
				groupBox->Text = currencySearchPara->Insert(3," - ");
				groupBox->Tag = currencySearchPara;
				groupBox->Location = System::Drawing::Point(3, 3 + (counter*WLcontrolOffset));
				groupBox->Size = System::Drawing::Size(177, 100);
				groupBox->BackColor = System::Drawing::Color::Transparent;
				groupBox->Click += gcnew System::EventHandler(this, &MainWindow::loadHDForSelection);

			//create exchange label
			Label^ eRLabel = gcnew Label;
				eRLabel->Name = currencySearchPara + "_ER_Label";
				eRLabel->Text = "temp";
				eRLabel->Tag = "rate";
				eRLabel->AutoSize = true;
				eRLabel->Location = System::Drawing::Point(7, 20);
				eRLabel->Size = System::Drawing::Size(81, 13);

			//create prediction label
			Label^ Lprediction = gcnew Label;
				Lprediction->Name = currencySearchPara + "_Prediction";
				Lprediction->Text = "Prediction:";
				Lprediction->AutoSize = true;
				Lprediction->Location = System::Drawing::Point(7, 48);
				Lprediction->Size = System::Drawing::Size(57, 13);


			if (currentNetworkType)//if scaling
			{
				//prediction value label
				Label^ preValue = gcnew Label;
					preValue->Name = currencySearchPara + "_preValue";
					preValue->Tag = "prediction";
					preValue->Text = "";
					preValue->AutoSize = true;
					preValue->Location = System::Drawing::Point(7, 67);
					preValue->Size = System::Drawing::Size(16, 13);

				groupBox->Controls->Add(preValue);
			}
			else
			{
				//create prediction pictureBox
				PictureBox^ preValue = gcnew PictureBox;
					preValue->Name = currencySearchPara + "_preValue";
					preValue->Tag = "prediction";
					preValue->Location = System::Drawing::Point(10, 62);
					preValue->Size = System::Drawing::Size(32, 32);
					preValue->Image = nullptr;

				groupBox->Controls->Add(preValue);
			}

			//create change picture box
			PictureBox^ change = gcnew PictureBox;
				change->Name = currencySearchPara + "_Change";
				change->Tag = "change";
				change->Location = System::Drawing::Point(139, 19);
				change->Size = System::Drawing::Size(32, 32);
				change->Image = safe_cast<Image^>(resourceManager->GetObject(L"level"));

			//create delete picture box
			PictureBox^ deleteButton = gcnew PictureBox;
				deleteButton->Name = currencySearchPara + "_delete";
				deleteButton->Click += gcnew System::EventHandler(this, &MainWindow::deleteWLObject);
				deleteButton->Location = System::Drawing::Point(139, 62);
				deleteButton->Size = System::Drawing::Size(32, 32);
				deleteButton->Image = safe_cast<Image^>(resourceManager->GetObject(L"deleteButton"));

			//add controls to currency box
			groupBox->Controls->Add(eRLabel);
			groupBox->Controls->Add(change);
			groupBox->Controls->Add(deleteButton);
			groupBox->Controls->Add(Lprediction);
			
			//add currency to watchists and set values
			WLContainer->Controls->Add(groupBox);

			WatchList->Add(groupBox);
			bufferCounter->Add(0);
			firstTrigger->Add(true);
			lastXR->Add(0);
			counter++;

			WLContainer->AutoScroll = true;//enable scroll again
		}

		//adjsut prediction value control
		void adjustToNetworkType(bool scaling)
		{
			if (scaling == !currentNetworkType && WatchList->Count>0)	//if scaling is not surrent type and currencies to watch
			{
				currentNetworkType = scaling;	//set network type

				if (currentNetworkType)	//if scaling
				{
					for each(Control^ boxControl in WatchList)//for each watch box change predition element to label
					{
						boxControl->Controls->Remove(boxControl->Controls->Find(boxControl->Name + "_preValue", true)[0]);

						Label^ preValue = gcnew Label;
							preValue->Name = boxControl->Name + "_preValue";
							preValue->Tag = "prediction";
							preValue->Text = "...";
							preValue->AutoSize = true;
							preValue->Location = System::Drawing::Point(7, 67);
							preValue->Size = System::Drawing::Size(16, 13);

						boxControl->Controls->Add(preValue);
					}
				}
				else
				{
					for each(Control^ boxControl in WatchList)//for each watch box change predition element to picturebox
					{
						boxControl->Controls->Remove(boxControl->Controls->Find(boxControl->Name + "_preValue", true)[0]);

						PictureBox^ preValue = gcnew PictureBox;
							preValue->Name = boxControl->Name + "_preValue";
							preValue->Tag = "prediction";
							preValue->Location = System::Drawing::Point(10,62);
							preValue->Size = System::Drawing::Size(32, 32);
							preValue->Image = safe_cast<Image^>(resourceManager->GetObject(L"level"));

						boxControl->Controls->Add(preValue);
					}
				}
			}
			else
			{
				currentNetworkType = scaling;//set current net type
			}
		}

		//delete currency watch box element
		void deleteWatchBox(System::Windows::Forms::Control^ selection)
		{
			
			System::Drawing::Point position = selection->Location;
			int Y = position.Y;	//get delete position

			//remove selection from all lists
			NNBufferList->RemoveAt(WatchList->IndexOf(selection));
			bufferCounter->RemoveAt(WatchList->IndexOf(selection));
			firstTrigger->RemoveAt(WatchList->IndexOf(selection));
			lastXR->RemoveAt(WatchList->IndexOf(selection));
			WLContainer->Controls->Remove(selection);
			WatchList->Remove(selection);
			searchParameters->Remove(selection->Name);

			counter--;//change counter

			for each(Control^ control in WatchList)	//move all lower elements up 1 slot
			{
				int x = control->Location.Y;
				if (x > Y)
				{
					Point newDrawPoint = System::Drawing::Point::Subtract(control->Location, System::Drawing::Size(0, WLcontrolOffset));
					control->Location = newDrawPoint;
				}
			}
		}
		
		//build history data lsit
		void buildHData(String^ currencySearchPara)
		{
			HistoryData->Clear();

			array<String^, 2>^ data = loadHData(currencySearchPara);
			if (data != nullptr)
			{
				HDnumberbuffer = Convert::ToDouble(data[data->GetLength(0) - 1, 2]);
				liveHDnumberbuffer= Convert::ToDouble(data[data->GetLength(0) - 1, 2]);

				for (int x = data->GetLength(0) - 1, y = 0 ;x >= 0 && y< displayWindowSize;x--, y++)
				{
					double value;

					if(x>0)
						value= Convert::ToDouble(data[x - 1, 2]);
					else
						value = 0;

					GroupBox^ groupBox = gcnew GroupBox;
						groupBox->Name = currencySearchPara;
						groupBox->Text = currencySearchPara;
						groupBox->Location = System::Drawing::Point(3, 3 + (DPHcounter*DPHcontrolOffset));
						groupBox->Size = System::Drawing::Size(177, 75);

					Label^ dateTime = gcnew Label;
						dateTime->Name = currencySearchPara + "_lastFeed";
						dateTime->Text = data[x, 0]+" "+data[x,1];
						dateTime->AutoSize = true;
						dateTime->Location = System::Drawing::Point(6, 20);
						dateTime->Size = System::Drawing::Size(58, 13);

					Label^ eRate = gcnew Label;
						eRate->Name = currencySearchPara + "_ER_Label";
						eRate->Text = "X-Rate: "+data[x, 2];
						eRate->AutoSize = true;
						eRate->Location = System::Drawing::Point(6, 43);
						eRate->Size = System::Drawing::Size(81, 13);

					PictureBox^ changeER = gcnew PictureBox;
						changeER->Name = currencySearchPara + "_prediction";
						changeER->Location = System::Drawing::Point(139, 33);
						changeER->Size = System::Drawing::Size(32, 32);

					if (x > 0)
					{
						if (HDnumberbuffer > value)
							changeER->Image = safe_cast<Image^>(resourceManager->GetObject(L"up"));
						else if (HDnumberbuffer < value)
							changeER->Image = safe_cast<Image^>(resourceManager->GetObject(L"down"));
						else
							changeER->Image = safe_cast<Image^>(resourceManager->GetObject(L"level"));
					}
					else
					{
						changeER->Image = safe_cast<Image^>(resourceManager->GetObject(L"level"));
					}

					HDnumberbuffer = value;

					groupBox->Controls->Add(dateTime);
					groupBox->Controls->Add(eRate);
					groupBox->Controls->Add(changeER);

					DPHContainer->Controls->Add(groupBox);
					HistoryData->Add(groupBox);

					plotDPG(Convert::ToDateTime(data[x, 0] + " " + data[x, 1]),Convert::ToDouble(data[x, 2]),true);

					DPHcounter++;
				}
			}
		}

		//create new history data element
		void createDPHBox(String^ currencySearchPara, String^ dT, String^ value)
		{
			DPHContainer->AutoScroll = false;	//move to top location

			//create histry data box
			GroupBox^ groupBox = gcnew GroupBox;
				groupBox->Name = currencySearchPara;
				groupBox->Text = currencySearchPara;
				groupBox->Location = System::Drawing::Point(3, 3);
				groupBox->Size = System::Drawing::Size(177, 75);

			//create date and time label
			Label^ dateTime = gcnew Label;
				dateTime->Name = currencySearchPara + "_lastFeed";
				dateTime->Text = dT;
				dateTime->AutoSize = true;
				dateTime->Location = System::Drawing::Point(6, 20);
				dateTime->Size = System::Drawing::Size(58, 13);

			//create exchange rate label
			Label^ eRate = gcnew Label;
				eRate->Name = currencySearchPara + "_ER_Label_lastFeed";
				eRate->Text = "X-Rate: " + value;
				eRate->AutoSize = true;
				eRate->Location = System::Drawing::Point(6, 43);
				eRate->Size = System::Drawing::Size(81, 13);

			//create exchange change picturebox
			PictureBox^ changeER = gcnew PictureBox;
				changeER->Name = currencySearchPara + "_prediction";
				changeER->Location = System::Drawing::Point(139, 33);
				changeER->Size = System::Drawing::Size(32, 32);

				if (liveHDnumberbuffer > Convert::ToDouble(value))					//if less
					changeER->Image = safe_cast<Image^>(resourceManager->GetObject(L"down"));
				else if (liveHDnumberbuffer < Convert::ToDouble(value))				//if more
					changeER->Image = safe_cast<Image^>(resourceManager->GetObject(L"up"));
				else																//everything else
					changeER->Image = safe_cast<Image^>(resourceManager->GetObject(L"level"));

				liveHDnumberbuffer = Convert::ToDouble(value);

				if (HistoryData->Count >= displayWindowSize)
				{
					HistoryData->RemoveAt(displayWindowSize - 1); //remove last element if max size is reached
				}

			for each(Control^ control in HistoryData)	//move all other controls down 1 slot
			{
				Point newDrawPoint = System::Drawing::Point::Add(control->Location, System::Drawing::Size(0, DPHcontrolOffset));
				control->Location = newDrawPoint;
			}

			//add controls to history data box
			groupBox->Controls->Add(dateTime);
			groupBox->Controls->Add(eRate);
			groupBox->Controls->Add(changeER);

			//insert at top
			DPHContainer->Controls->Add(groupBox);
			HistoryData->Insert(0, groupBox);

			//plot graph
			plotDPG(Convert::ToDateTime(dT), Convert::ToDouble(value), false);
			DPHcounter++;

			DPHContainer->AutoScroll = true;	//enable auto scroll
		}
#pragma endregion

#pragma region Functions
		//create search parameters for online data gather
		String^ createSearchPara()
		{
			String^ search = "";
			for each(String^ watch in searchParameters)//add all currencies to be watched to the search parameters
			{
				if (search == "")
				{
					search += "'" + watch + "'";
				}
				else
				{
					search = search + ",'" + watch + "'";
				}
			}

			return search;//retur search parameteres
		}

		//get live data from internet
		String^ getLiveData(String^ searchPara)
		{
			String^ buffer=nullptr;	//set buffer string null pointer

			HINTERNET connection = InternetOpen(_T("MyBrowser"), INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);	//open internet connection

			if (connection)//if connection is valid
			{
				String^ address = "https://query.yahooapis.com/v1/public/yql?q=";	//adress
				String^ query = "select%20id,Rate%20from%20yahoo.finance.xchange%20where%20pair%20in%20("+searchPara+")";//query
				String^ param = "&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys&callback=";//parameters
				pin_ptr<const wchar_t> wSearch = PtrToStringChars(address + query + param);//create serach string
				LPCWSTR search = wSearch;

				HINTERNET openAddress = InternetOpenUrl(connection,search,
					NULL, 0, INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_SECURE, 0); //open address

				if (openAddress)//if address valid
				{
					//set variabels
					char DataRecieved[internetReadLength] = { '\0' };
					char Data[internetReadLength] = { '\0' };
					DWORD NumberOfBytesRead = 0;

					//read internet data
					while (InternetReadFile(openAddress, DataRecieved, internetReadLength, &NumberOfBytesRead) && NumberOfBytesRead);

					buffer = gcnew String(DataRecieved, 0, 4901);//put data into buffer
				}
				else//error handeling
				{
					DWORD ErrorNUM = GetLastError();
					MessageBox::Show("Failed to open URL! ErrorNumber:" + ErrorNUM.ToString());
					InternetCloseHandle(connection);
				}
			}
			else//error handeling
			{
				MessageBox::Show("Could not establish connection to the internet. Please check your internet connection and try again.");
			}

			return buffer;//return buffer
		}

		//run update
		void runUpdate(array<String^,2>^ data)
		{
			NeuralNetwork^ network = NeuralNetworkList[cB_NeuralNetworks->SelectedIndex];//get current neural network
			reTrainData->Clear();//clear retrain data

			for (int x = 1;x < data->GetLength(0);x++)//for each datat set
			{
				//save to history data
				saveToHData("FileIO/Historic_Data/", "HData_"+data[x,0]+".txt", data[0, 0] + ";" + data[0, 1] + ";" + data[x, 1]);

				array<Control^>^ exchange = WatchList[x - 1]->Controls->Find(data[x,0]+"_ER_Label", true);//find exchange control

				if (exchange->Length == 1)//if label found
				{
					if (!firstTrigger[x-1])//if not first trigger for this currency
					{
						oldValue = Convert::ToDouble(exchange[0]->Text->Split(':')[1]->Trim());//get old exchange value
						newValue = Convert::ToDouble(data[x, 1]);//get new exchange value

						if (NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]->scaling)//if network is scaling
						{
							//scale insert value
							insertValue = NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]->scaleDown(newValue-oldValue, -1,1);

							if (LTSwitch->Checked && bufferCounter[x-1] >= neddedBuffer)//if retrain is active push to retrain data
							{
								array<double>^buffer = NNBufferList[x-1];
								Array::Resize(buffer, buffer->Length + 1);
								buffer[buffer->Length-1]=insertValue;
								reTrainData->Add(buffer);
							}

							shiftArrayLeft(NNBufferList[x - 1], insertValue);//shift new value into array
							oldValue = newValue;//set old value
						}
						else//if network is trend
						{
							if (oldValue > newValue)
							{
								insertValue = 0.1;//set decrease
							}
							else if (oldValue < newValue)
							{
								insertValue = 0.9;//set increase
							}
							else
							{
								insertValue = 0.5;//set level
							}

							if (LTSwitch->Checked && bufferCounter[x-1] >= neddedBuffer)//if live training is active create and set train data set
							{
								array<double>^buffer = NNBufferList[x-1];
								Array::Resize(buffer, buffer->Length + 3);

								if (insertValue == 0.9)//set desired output values for increase
								{
									buffer[NNBufferList[0]->Length + 2] = 0.1;
									buffer[NNBufferList[0]->Length + 1] = 0.1;
									buffer[NNBufferList[0]->Length] = 0.9;
								}
								else if (insertValue == 0.1)//set desired output values for decrease
								{
									buffer[NNBufferList[0]->Length + 2] = 0.9;
									buffer[NNBufferList[0]->Length + 1] = 0.1;
									buffer[NNBufferList[0]->Length] = 0.1;
								}
								else//set desired output values for level
								{
									buffer[NNBufferList[0]->Length + 2] = 0.1;
									buffer[NNBufferList[0]->Length + 1] = 0.9;
									buffer[NNBufferList[0]->Length] = 0.1;
								}
								reTrainData->Add(buffer);
							}

							shiftArrayLeft(NNBufferList[x - 1], insertValue);//shift value into array
							oldValue = newValue;//set old value
						}
						
						if(bufferCounter[x-1]<neddedBuffer)//increase buffer count if its to low
							bufferCounter[x-1]++;
					}
					else
					{
						oldValue= Convert::ToDouble(data[x, 1]);//set first value of exchange rate
					}

					exchange[0]->Text = "X-Rate: "+data[x, 1];//show exchange rate

					PictureBox^ change = safe_cast<PictureBox^>(WatchList[x - 1]->Controls->Find(data[x, 0] + "_Change", true)[0]);//get picturebox for change

					if (lastXR[x - 1] > Convert::ToDouble(data[x, 1]))
					{
						//set to decrease
						change->Image = safe_cast<Image^>(resourceManager->GetObject(L"down"));
						change->Image->Tag = "down";
					}
					else if (lastXR[x - 1] < Convert::ToDouble(data[x, 1]))
					{
						//set to increase
						change->Image = safe_cast<Image^>(resourceManager->GetObject(L"up"));
						change->Image->Tag = "up";
					}
					else
					{
						//set to level
						change->Image = safe_cast<Image^>(resourceManager->GetObject(L"level"));
						change->Image->Tag = "level";
					}

					lastXR[x-1] = Convert::ToDouble(data[x, 1]);//set lst exchange rate

					if (WatchList[x - 1]->BackColor == Color::Yellow)//if current watch boxselected
					{
						createDPHBox(data[x, 0], data[0, 0] + " " + data[0, 1], data[x, 1]);//create history box for gathered value
					}
					
					//run prediction
					if (bufferCounter[x-1] == neddedBuffer)
					{
						array<double>^ inputs = NNBufferList[x-1];//get inputs

						for (int input = 0;input < bufferCounter[x-1]; input++)
						{
							network->SetInput(input, inputs[input]);//set inputs
						}

						network->feedData();//run network

						if (NeuralNetworkList[cB_NeuralNetworks->SelectedIndex]->scaling)
						{
							//run prediction for scaling
							int outID = network->getMaxOutputID();
							Label^ preLabel=safe_cast<Label^>(WatchList[x - 1]->Controls->Find(data[x, 0] + "_preValue", true)[0]);

							if (preLabel->Text != "")
							{
								int diff = Convert::ToDouble(preLabel->Text) - oldValue;//calc difference between old and current value

								if (preLabel->Text != "" && (-0.0002 < diff < 0.0002))//iff diffrernce is wihtin level
								{
									correctScale++;//add to correct scale
								}
							}

							if (0 < outID < network->_Output->LayerNodes)//if out id valid
							{
								//scale round and display change in rate
								double value = network->scaleUp(network->getOutput(outID), network->scale[outID, 0], network->scale[outID, 1]);
								value=Math::Round(value, 5);
								preLabel->Text = value.ToString();
								countScale++;
							}
							else//error catch
							{
								MessageBox::Show("Could not determin correct output ID. No prediction made");
								preLabel->Text = "";
							}
						}
						else
						{
							//run prediction for trend
							int outID = network->getMaxOutputID();
							PictureBox^ preBox = safe_cast<PictureBox^>(WatchList[x - 1]->Controls->Find(data[x, 0] + "_preValue", true)[0]);

							if (preBox->Image != nullptr && preBox->Image->Tag == change->Image->Tag)//if prediction was right
							{
								correctTrend++;
							}

							if (outID == 0)//set to inrease
							{
								preBox->Image= safe_cast<Image^>(resourceManager->GetObject(L"up"));
								preBox->Image->Tag = "up";
								countTrend++;
							}
							else if (outID == 1)//set to level
							{
								preBox->Image = safe_cast<Image^>(resourceManager->GetObject(L"level"));
								preBox->Image->Tag = "level";
								countTrend++;
							}
							else if (outID == 2)//set to decrease
							{
								preBox->Image = safe_cast<Image^>(resourceManager->GetObject(L"down"));
								preBox->Image->Tag = "down";
								countTrend++;
							}
							else//error catch
							{
								MessageBox::Show("Could not determin correct output ID. No prediction made");
								preBox->Image = nullptr;
							}
						}

						saveToStats();//save to stats
					}
				}
				else//error catch
				{
					MessageBox::Show("No Data available to process.");
				}
				firstTrigger[x-1] = false;//set first trigger false
			}
			

			if (WatchList->Count > 0)//if currencies in watch list
			{
				if (LTSwitch->Checked && bufferCounter[0] >= neddedBuffer) //if live train is active and retrain values are enough
				{
					network->trainNeuralNetwork(network, reTrainData, true);//retrain value
				}
			}
		}

		//shift array 1 position left
		void shiftArrayLeft(array<double>^ values, double value)
		{
			for (int x = 1; x < values->Length; x++)//move all values 1 position to the left
			{
				values[x - 1] = values[x];
			}
			values[values->Length - 1] = value;	//insert new value at the end
		}

		//plot graph for history data
		void plotDPG(DateTime time, double xchange, bool insertAtStart)
		{
			//change limit of graphs Y axis
			if (xchange > historymax)
				historymax = xchange+0.01;
			if (xchange < historymin)
				historymin = xchange-0.01;

			//set max and min Y
			DPG->ChartAreas[0]->AxisY->Maximum = historymax;
			DPG->ChartAreas[0]->AxisY->Minimum = historymin;

			
			if (DPG->Series[0]->Points->Count < displayWindowSize)//if number of points less then size fo data
			{
				if(insertAtStart)//plot old data
				{
					DPG->Series[0]->Points->InsertXY(0,time, xchange);
				}
				else//plot new data
				{
					DPG->Series[0]->Points->AddXY(time, xchange);
				}
			}
			else
			{
				//remove oldest value and place newest
				DPG->Series[0]->Points->RemoveAt(0);
				DPG->Series[0]->Points->AddXY(time, xchange);
			}
		}

		//load stats
		void loadStats()
		{
			Generic::List<String^>^ StatReadOut = readFromFile("Stats.txt", "FileIO/Statistics/");//read from file

			//place information in the appropriate place
			countTrend = Convert::ToInt32(StatReadOut[2]);
			correctTrend = Convert::ToInt32(StatReadOut[3]);
			countScale = Convert::ToInt32(StatReadOut[4]);
			correctScale = Convert::ToInt32(StatReadOut[5]);
		}

		//save stats
		void saveToStats()
		{
			//create save files data
			String^ data = dateLabel->Text+"\r\n"+timeLabel->Text+"\r\n"+countTrend+"\r\n"+correctTrend+"\r\n"+countScale+"\r\n"+correctScale;

			//write to file
			writeToFile("FileIO/Statistics/", "Stats.txt", data, false);
		}
#pragma endregion
};
}


