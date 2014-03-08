#pragma once

#include "MotorController.h"
#include "ImageProcessor.h"

namespace TennisBallCollection {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RobotControlUI
	/// </summary>
	public ref class RobotControlUI : public System::Windows::Forms::Form
	{
		private:
			MotorController* mcPointer;
		public:
			RobotControlUI(MotorController &mc): mcPointer(&mc)
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
			~RobotControlUI()
			{
				if (components)
				{
					delete components;
				}
			}

		protected: 

		private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
		private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
		private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
		private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Button^  button3;
		private: System::Windows::Forms::Button^  button4;
		private: System::Windows::Forms::Button^  button5;
		private: System::Windows::Forms::Button^  button6;
		private: System::Windows::Forms::Button^  button7;
		private: System::Windows::Forms::Button^  button8;
		private: System::Windows::Forms::Button^  button9;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
		private: System::Windows::Forms::Button^  button10;
		private: System::Windows::Forms::Button^  button11;
		private: System::Windows::Forms::Button^  button12;



		protected: 













		protected: 

		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>
			System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>

			void InitializeComponent(void)
			{
				this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
				this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
				this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
				this->button10 = (gcnew System::Windows::Forms::Button());
				this->button11 = (gcnew System::Windows::Forms::Button());
				this->button12 = (gcnew System::Windows::Forms::Button());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
				this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->button2 = (gcnew System::Windows::Forms::Button());
				this->button3 = (gcnew System::Windows::Forms::Button());
				this->button4 = (gcnew System::Windows::Forms::Button());
				this->button5 = (gcnew System::Windows::Forms::Button());
				this->button6 = (gcnew System::Windows::Forms::Button());
				this->button7 = (gcnew System::Windows::Forms::Button());
				this->button8 = (gcnew System::Windows::Forms::Button());
				this->button9 = (gcnew System::Windows::Forms::Button());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->tableLayoutPanel1->SuspendLayout();
				this->tableLayoutPanel3->SuspendLayout();
				this->tableLayoutPanel5->SuspendLayout();
				this->tableLayoutPanel4->SuspendLayout();
				this->tableLayoutPanel2->SuspendLayout();
				this->SuspendLayout();
				// 
				// tableLayoutPanel1
				// 
				this->tableLayoutPanel1->ColumnCount = 2;
				this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					50)));
				this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					50)));
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 0);
				this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 1, 0);
				this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
				this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 1;
				this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
				this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
				this->tableLayoutPanel1->Size = System::Drawing::Size(572, 255);
				this->tableLayoutPanel1->TabIndex = 0;
				// 
				// tableLayoutPanel3
				// 
				this->tableLayoutPanel3->ColumnCount = 1;
				this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					100)));
				this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel5, 0, 1);
				this->tableLayoutPanel3->Controls->Add(this->label2, 0, 0);
				this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
				this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				this->tableLayoutPanel3->RowCount = 2;
				this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 8.56F)));
				this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 91.44F)));
				this->tableLayoutPanel3->Size = System::Drawing::Size(280, 249);
				this->tableLayoutPanel3->TabIndex = 1;
				// 
				// tableLayoutPanel5
				// 
				this->tableLayoutPanel5->ColumnCount = 7;
				this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					5.46875F)));
				this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					26.04167F)));
				this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					5.46875F)));
				this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					26.04167F)));
				this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					5.46875F)));
				this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					26.04167F)));
				this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					5.46875F)));
				this->tableLayoutPanel5->Controls->Add(this->button10, 1, 0);
				this->tableLayoutPanel5->Controls->Add(this->button11, 3, 0);
				this->tableLayoutPanel5->Controls->Add(this->button12, 5, 0);
				this->tableLayoutPanel5->Location = System::Drawing::Point(3, 24);
				this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
				this->tableLayoutPanel5->RowCount = 6;
				this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 28.50679F)));
				this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.826546F)));
				this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 28.50679F)));
				this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.826546F)));
				this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 28.50679F)));
				this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.826546F)));
				this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
				this->tableLayoutPanel5->Size = System::Drawing::Size(274, 222);
				this->tableLayoutPanel5->TabIndex = 3;
				// 
				// button10
				// 
				this->button10->Location = System::Drawing::Point(17, 3);
				this->button10->Name = L"button10";
				this->button10->Size = System::Drawing::Size(65, 57);
				this->button10->TabIndex = 0;
				this->button10->Text = L"Manual";
				this->button10->UseVisualStyleBackColor = true;
				this->button10->Click += gcnew System::EventHandler(this, &RobotControlUI::button10_Click);
				// 
				// button11
				// 
				this->button11->Location = System::Drawing::Point(102, 3);
				this->button11->Name = L"button11";
				this->button11->Size = System::Drawing::Size(65, 57);
				this->button11->TabIndex = 1;
				this->button11->Text = L"Roomba";
				this->button11->UseVisualStyleBackColor = true;
				this->button11->Click += gcnew System::EventHandler(this, &RobotControlUI::button11_Click);
				// 
				// button12
				// 
				this->button12->Location = System::Drawing::Point(187, 3);
				this->button12->Name = L"button12";
				this->button12->Size = System::Drawing::Size(65, 57);
				this->button12->TabIndex = 2;
				this->button12->Text = L"Intelligent";
				this->button12->UseVisualStyleBackColor = true;
				this->button12->Click += gcnew System::EventHandler(this, &RobotControlUI::button12_Click);
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(0)));
				this->label2->Location = System::Drawing::Point(3, 0);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(129, 21);
				this->label2->TabIndex = 2;
				this->label2->Text = L"Robot Mode";
				// 
				// tableLayoutPanel4
				// 
				this->tableLayoutPanel4->ColumnCount = 1;
				this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					100)));
				this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel2, 0, 1);
				this->tableLayoutPanel4->Controls->Add(this->label1, 0, 0);
				this->tableLayoutPanel4->Location = System::Drawing::Point(289, 3);
				this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
				this->tableLayoutPanel4->RowCount = 2;
				this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 8.564141F)));
				this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 91.43585F)));
				this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
				this->tableLayoutPanel4->Size = System::Drawing::Size(280, 249);
				this->tableLayoutPanel4->TabIndex = 2;
				// 
				// tableLayoutPanel2
				// 
				this->tableLayoutPanel2->ColumnCount = 7;
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					5.46875F)));
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					26.04167F)));
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					5.46875F)));
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					26.04167F)));
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					5.46875F)));
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					26.04167F)));
				this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
					5.46875F)));
				this->tableLayoutPanel2->Controls->Add(this->button1, 1, 0);
				this->tableLayoutPanel2->Controls->Add(this->button2, 3, 0);
				this->tableLayoutPanel2->Controls->Add(this->button3, 5, 0);
				this->tableLayoutPanel2->Controls->Add(this->button4, 1, 2);
				this->tableLayoutPanel2->Controls->Add(this->button5, 3, 2);
				this->tableLayoutPanel2->Controls->Add(this->button6, 5, 2);
				this->tableLayoutPanel2->Controls->Add(this->button7, 1, 4);
				this->tableLayoutPanel2->Controls->Add(this->button8, 3, 4);
				this->tableLayoutPanel2->Controls->Add(this->button9, 5, 4);
				this->tableLayoutPanel2->Location = System::Drawing::Point(3, 24);
				this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				this->tableLayoutPanel2->RowCount = 6;
				this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 28.50679F)));
				this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.826546F)));
				this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 28.50679F)));
				this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.826546F)));
				this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 28.50679F)));
				this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.826546F)));
				this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
				this->tableLayoutPanel2->Size = System::Drawing::Size(274, 222);
				this->tableLayoutPanel2->TabIndex = 0;
				// 
				// button1
				// 
				this->button1->Location = System::Drawing::Point(17, 3);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(65, 57);
				this->button1->TabIndex = 0;
				this->button1->Text = L"<< Crude";
				this->button1->UseVisualStyleBackColor = true;
				// 
				// button2
				// 
				this->button2->Location = System::Drawing::Point(102, 3);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(65, 57);
				this->button2->TabIndex = 1;
				this->button2->Text = L"/\\";
				this->button2->UseVisualStyleBackColor = true;
				this->button2->Click += gcnew System::EventHandler(this, &RobotControlUI::button2_Click);
				// 
				// button3
				// 
				this->button3->Location = System::Drawing::Point(187, 3);
				this->button3->Name = L"button3";
				this->button3->Size = System::Drawing::Size(65, 57);
				this->button3->TabIndex = 2;
				this->button3->Text = L"Crude >>";
				this->button3->UseVisualStyleBackColor = true;
				// 
				// button4
				// 
				this->button4->Location = System::Drawing::Point(17, 76);
				this->button4->Name = L"button4";
				this->button4->Size = System::Drawing::Size(65, 57);
				this->button4->TabIndex = 3;
				this->button4->Text = L"<< Swing";
				this->button4->UseVisualStyleBackColor = true;
				// 
				// button5
				// 
				this->button5->Location = System::Drawing::Point(102, 76);
				this->button5->Name = L"button5";
				this->button5->Size = System::Drawing::Size(65, 57);
				this->button5->TabIndex = 4;
				this->button5->Text = L"Stop";
				this->button5->UseVisualStyleBackColor = true;
				// 
				// button6
				// 
				this->button6->Location = System::Drawing::Point(187, 76);
				this->button6->Name = L"button6";
				this->button6->Size = System::Drawing::Size(65, 57);
				this->button6->TabIndex = 5;
				this->button6->Text = L"Swing >>";
				this->button6->UseVisualStyleBackColor = true;
				// 
				// button7
				// 
				this->button7->Location = System::Drawing::Point(17, 149);
				this->button7->Name = L"button7";
				this->button7->Size = System::Drawing::Size(65, 57);
				this->button7->TabIndex = 6;
				this->button7->Text = L"<< Point";
				this->button7->UseVisualStyleBackColor = true;
				// 
				// button8
				// 
				this->button8->Location = System::Drawing::Point(102, 149);
				this->button8->Name = L"button8";
				this->button8->Size = System::Drawing::Size(65, 57);
				this->button8->TabIndex = 7;
				this->button8->Text = L"\\/";
				this->button8->UseVisualStyleBackColor = true;
				// 
				// button9
				// 
				this->button9->Location = System::Drawing::Point(187, 149);
				this->button9->Name = L"button9";
				this->button9->Size = System::Drawing::Size(65, 57);
				this->button9->TabIndex = 8;
				this->button9->Text = L"Point >>";
				this->button9->UseVisualStyleBackColor = true;
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					static_cast<System::Byte>(0)));
				this->label1->Location = System::Drawing::Point(3, 0);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(158, 21);
				this->label1->TabIndex = 1;
				this->label1->Text = L"Manual Control";
				// 
				// RobotControlUI
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(596, 279);
				this->Controls->Add(this->tableLayoutPanel1);
				this->Name = L"RobotControlUI";
				this->Text = L"RobotControlUI";
				this->tableLayoutPanel1->ResumeLayout(false);
				this->tableLayoutPanel3->ResumeLayout(false);
				this->tableLayoutPanel3->PerformLayout();
				this->tableLayoutPanel5->ResumeLayout(false);
				this->tableLayoutPanel4->ResumeLayout(false);
				this->tableLayoutPanel4->PerformLayout();
				this->tableLayoutPanel2->ResumeLayout(false);
				this->ResumeLayout(false);

			}
			#pragma endregion

		private: 
			System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
			{
			 }

		private:
			System::Void button10_Click(System::Object^  sender, System::EventArgs^  e)
			{
			 }

		private:
			System::Void button11_Click(System::Object^  sender, System::EventArgs^  e)
			{
				button10->FlatStyle = FlatStyle::Flat;
				button11->FlatStyle = FlatStyle::Flat;

				//MotorController motorController;
				//motorController.start("\\\\.\\COM17");

				ImageProcessor ip(*mcPointer);
				ip.process();

			}

		private:
			System::Void button12_Click(System::Object^  sender, System::EventArgs^  e)
			{
			}
};
}
