//_ClrMath\MyFmPhase0.h
//Gao-Wei Chang, 180513, 170414, 160521.
#pragma once
namespace GW86 {
namespace FmTasks {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

public ref class MyFmPhase0: public Form {
public:
  MyFmPhase0() {
    InitializeComponent();
  };
private:
  RadioButton ^radioButton1, ^radioButton2, ^radioButton3;
  GroupBox^ groupBox1;
  Button ^button1, ^button2;
  Label^ label1;

  void InitializeComponent() {
	this->Text = "MyFmPhase0";
	this->Size =System::Drawing::Size(230, 180);
	groupBox1 = gcnew GroupBox;
	this->Controls->Add(groupBox1);
	groupBox1->Text = "Phase";
	groupBox1->Size = System::Drawing::Size(110, 110);
	groupBox1->Location = System::Drawing::Point(10, 5);

	radioButton1 = gcnew RadioButton;
	this->groupBox1->Controls->Add(radioButton1);
	radioButton1->Text = "Ratio (2PI)";
	radioButton1->Size = System::Drawing::Size(95, 20);
	radioButton1->Checked = true;
	radioButton1->Location = System::Drawing::Point(10, 20);
	radioButton1->CheckedChanged+= gcnew EventHandler(this, &MyFmPhase0::radioButton1_CheckedChanged);

	radioButton2 = gcnew RadioButton;
	this->groupBox1->Controls->Add(radioButton2);
	radioButton2->Text = "Radian";
	radioButton2->Size = System::Drawing::Size(80, 20);
	radioButton2->Location = System::Drawing::Point(10, 50);
	radioButton2->CheckedChanged+= gcnew EventHandler(this, &MyFmPhase0::radioButton2_CheckedChanged);

	radioButton3 = gcnew RadioButton;
	this->groupBox1->Controls->Add(radioButton3);
	radioButton3->Text = "Degree";
	radioButton3->Size = System::Drawing::Size(80, 20);
	radioButton3->Location = System::Drawing::Point(10, 80);
	radioButton3->CheckedChanged+= gcnew EventHandler(this, &MyFmPhase0::radioButton3_CheckedChanged);

	button1 = gcnew Button;
	this->Controls->Add(button1);
	button1->Text = "OK";
	button1->Size = System::Drawing::Size(55, 20);
	button1->Location = System::Drawing::Point(138, 15);

	button2 = gcnew Button;
	this->Controls->Add(button2);
	button2->Text = "Reset";
	button2->Size = System::Drawing::Size(55, 20);
	button2->Location = System::Drawing::Point(138, 45);
	button2->Click+= gcnew EventHandler(this, &MyFmPhase0::button2_Click);

	label1 = gcnew Label;
	this->Controls->Add(label1);
	label1->Text = "________";
	label1->Size = System::Drawing::Size(55, 20);
	label1->Location = System::Drawing::Point(142, 85);
  };

  void button2_Click(Object^ s, EventArgs^ e) {
	 radioButton1->Checked = true;
	 radioButton2->Checked = false;
	 radioButton3->Checked = false;
  };

public:
  static array<bool>^ flag_phase={0, 0, 0};
  void radioButton1_CheckedChanged(Object^ s, EventArgs^ e) {
	 if (radioButton1->Checked == true) {
		 for (int i=0; i<3; i++) flag_phase[i]=0;
		 flag_phase[0]=true;
		 label1->Text="Ratio"; }
	 else flag_phase[0]=false;
  };

  void radioButton2_CheckedChanged(Object^ s, EventArgs^ e) {
	 if (radioButton2->Checked == true) {
		 for (int i=0; i<3; i++) flag_phase[i]=0;
		 flag_phase[1]=true; label1->Text="Radian"; } 
	 else flag_phase[1]=false;
  };

  void radioButton3_CheckedChanged(Object^ s, EventArgs^ e) {
	 if (radioButton3->Checked == true) {
		 for (int i=0; i<3; i++) flag_phase[i]=0;
		 flag_phase[2]=true; label1->Text="Degree";  }
	 else flag_phase[2]=false;
  };
};
} }