#pragma once
#include "FileIO.h"

namespace CoursWork_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Resources;

	/// <summary>
	/// Summary for ApplicationStatistics
	/// </summary>
	public ref class ApplicationStatistics : public System::Windows::Forms::Form
	{
	public:
		ApplicationStatistics(void)
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
		~ApplicationStatistics()
		{
			if (components)
			{
				delete components;
			}
		}
#pragma region Components
	private: System::Windows::Forms::ComboBox^  cB_NetworkType;
	protected:


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Label^  date;



	private: System::Windows::Forms::Label^  acc;



	private: System::Windows::Forms::Label^  predicCount;
	private: System::Windows::Forms::Label^  time;
	private: System::Windows::Forms::Button^  close;
	private: System::Windows::Forms::Timer^  timer1;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint1 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(0,
				5));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint2 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(1,
				10));
			this->cB_NetworkType = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->date = (gcnew System::Windows::Forms::Label());
			this->acc = (gcnew System::Windows::Forms::Label());
			this->predicCount = (gcnew System::Windows::Forms::Label());
			this->time = (gcnew System::Windows::Forms::Label());
			this->close = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// cB_NetworkType
			// 
			this->cB_NetworkType->FormattingEnabled = true;
			this->cB_NetworkType->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"All", L"Trending", L"Scaling" });
			this->cB_NetworkType->Location = System::Drawing::Point(12, 25);
			this->cB_NetworkType->Name = L"cB_NetworkType";
			this->cB_NetworkType->Size = System::Drawing::Size(186, 21);
			this->cB_NetworkType->TabIndex = 0;
			this->cB_NetworkType->SelectedIndexChanged += gcnew System::EventHandler(this, &ApplicationStatistics::cB_NetworkType_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Prediction Algorithm";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Date:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Time:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 159);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(112, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"# of made predictions:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 182);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(105, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Prediction Accuracy:";
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Location = System::Drawing::Point(204, 12);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->CustomProperties = L"LabelStyle=Bottom";
			series1->Name = L"Series1";
			dataPoint1->AxisLabel = L"Correct";
			dataPoint1->Color = System::Drawing::Color::LawnGreen;
			dataPoint1->CustomProperties = L"LabelStyle=Bottom";
			dataPoint1->IsValueShownAsLabel = true;
			dataPoint1->IsVisibleInLegend = true;
			dataPoint1->Label = L"";
			dataPoint2->AxisLabel = L"Predictions";
			dataPoint2->Color = System::Drawing::Color::Red;
			dataPoint2->CustomProperties = L"LabelStyle=Bottom";
			dataPoint2->IsValueShownAsLabel = true;
			series1->Points->Add(dataPoint1);
			series1->Points->Add(dataPoint2);
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(300, 219);
			this->chart1->TabIndex = 7;
			this->chart1->Text = L"chart1";
			// 
			// date
			// 
			this->date->AutoSize = true;
			this->date->Location = System::Drawing::Point(137, 79);
			this->date->Name = L"date";
			this->date->Size = System::Drawing::Size(61, 13);
			this->date->TabIndex = 8;
			this->date->Text = L"10.02.2017";
			// 
			// acc
			// 
			this->acc->AutoSize = true;
			this->acc->Location = System::Drawing::Point(137, 182);
			this->acc->Name = L"acc";
			this->acc->Size = System::Drawing::Size(27, 13);
			this->acc->TabIndex = 11;
			this->acc->Text = L"75%";
			// 
			// predicCount
			// 
			this->predicCount->AutoSize = true;
			this->predicCount->Location = System::Drawing::Point(137, 159);
			this->predicCount->Name = L"predicCount";
			this->predicCount->Size = System::Drawing::Size(31, 13);
			this->predicCount->TabIndex = 10;
			this->predicCount->Text = L"2015";
			// 
			// time
			// 
			this->time->AutoSize = true;
			this->time->Location = System::Drawing::Point(137, 102);
			this->time->Name = L"time";
			this->time->Size = System::Drawing::Size(34, 13);
			this->time->TabIndex = 9;
			this->time->Text = L"19:45";
			// 
			// close
			// 
			this->close->Location = System::Drawing::Point(429, 237);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(75, 23);
			this->close->TabIndex = 13;
			this->close->Text = L"Close";
			this->close->UseVisualStyleBackColor = true;
			this->close->Click += gcnew System::EventHandler(this, &ApplicationStatistics::close_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 300000;
			this->timer1->Tick += gcnew System::EventHandler(this, &ApplicationStatistics::timer1_Tick);
			// 
			// ApplicationStatistics
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(510, 267);
			this->Controls->Add(this->close);
			this->Controls->Add(this->acc);
			this->Controls->Add(this->predicCount);
			this->Controls->Add(this->time);
			this->Controls->Add(this->date);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cB_NetworkType);
			this->Name = L"ApplicationStatistics";
			this->Text = L"Application Statistics";
			this->Load += gcnew System::EventHandler(this, &ApplicationStatistics::ApplicationStatistics_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region Varaibles
	private:
		double accuracy;	//accuracy value

		int countTrend;		//total predictions trend network
		int correctTrend;	//corect prediction count trend network
		int countScale;		//total predictions scale network
		int correctScale;	//correct predictions count scale network

		double totalCount;	//total predictions
		double totalCorrect;//total correct predictions
#pragma endregion

#pragma region Event Handlers
	private: 
		//timer tick handler
		System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
		{
			loadInformation();	//reload information
		}

		//on form load event trigger
		System::Void ApplicationStatistics_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			cB_NetworkType->SelectedIndex = 0;	//preselect combo box value
		}

		//button click event
		System::Void close_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->Close();	//close this form
		}

		//selection chang event handler for combo box
		System::Void cB_NetworkType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		{
			loadInformation();	//reload information
		}
#pragma endregion

#pragma region functions
		void loadInformation()
		{
			//clear chart
			chart1->Series[0]->Points->RemoveAt(0);
			chart1->Series[0]->Points->RemoveAt(0);

			Generic::List<String^>^ StatReadOut = readFromFile("Stats.txt", "FileIO/Statistics/");
			accuracy=0.0;

			try
			{
				countTrend = Convert::ToInt32(StatReadOut[2]);
				correctTrend = Convert::ToInt32(StatReadOut[3]);
				countScale = Convert::ToInt32(StatReadOut[4]);
				correctScale = Convert::ToInt32(StatReadOut[5]);
			}
			catch(Exception^ e)
			{
				MessageBox::Show("Statistics file is compromised. Please delete statistics file to allo wfor new creation.\r\n Error Message reads: "+e->Message);
				countTrend = 0;
				correctTrend = 0;
				countScale = 0;
				correctScale = 0;
			}

			totalCount=0;
			totalCorrect=0;

			if (cB_NetworkType->SelectedIndex == 1)//if trand selected
			{
				//set values
				totalCount = countTrend;
				totalCorrect = correctTrend;
			}
			else if (cB_NetworkType->SelectedIndex == 2)//if scale selected
			{
				// set values
				totalCount = countScale;
				totalCorrect = correctScale;
			}
			else //if all selected
			{
				//set values
				totalCount = countTrend+countScale;
				totalCorrect = correctTrend+correctScale;
			}

			//set date and time
			date->Text = StatReadOut[0];
			time->Text = StatReadOut[1];


			if (totalCount != 0)
			{
				accuracy = (totalCorrect / totalCount) * 100;	//calc accuracy
				accuracy = Math::Round(accuracy, 2);			//round accuracy to 2 digits
				acc->Text = accuracy.ToString() + "%";			//set acc text
			}
			else //if would divide by 0
			{
				acc->Text = "N?A";								//set acc text
			}

			predicCount->Text = totalCount.ToString();			//set prediction count text
			
			//plot graph bars
			chart1->Series[0]->Points->AddXY(0,totalCorrect);
			chart1->Series[0]->Points->AddXY(1, totalCount);
			chart1->Series[0]->Points[0]->Color = Color::LightGreen;
			chart1->Series[0]->Points[1]->Color = Color::Red;

			chart1->Series[0]->Points[0]->AxisLabel="Correct";
			chart1->Series[0]->Points[1]->AxisLabel = "Predictions";

			chart1->Series[0]->Points[0]->Label= totalCorrect.ToString();
			chart1->Series[0]->Points[1]->Label = totalCount.ToString();
		}
#pragma endregion

};
}
