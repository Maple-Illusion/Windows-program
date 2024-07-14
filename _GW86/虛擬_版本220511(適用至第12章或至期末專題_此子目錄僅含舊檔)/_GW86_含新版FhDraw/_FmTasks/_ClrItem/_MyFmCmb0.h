//_ClrItem\_MyFmCmb0.h
//Gao-Wei Chang, 180519.
#pragma once
namespace GW86 {
namespace FmTasks {
namespace ClrItem {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
public ref class MyFmCmb0 : public Form {
public:
  MyFmCmb0() { InitializeComponent(); };
private:
  ComboBox^ comboBox1;
  Label^ label1; 
  void InitializeComponent() {
    this->Width=250; this->Height=200;
    comboBox1 = gcnew ComboBox;
	this->Controls->Add(comboBox1);
	comboBox1->Items->Add("Index 0");
	comboBox1->Items->Add("Index 1");
	comboBox1->Items->AddRange
			(gcnew array<Object^>(2) {"Index 2", "Index 3"});
	comboBox1->SelectedIndexChanged += 
	  gcnew EventHandler(this, &MyFmCmb0::comboBox1_SelectedIndexChanged);
	comboBox1->Location = Point(10, 10);
	label1 = gcnew Label;
	label1->Text ="______";
	label1->Location = Point (100, 90);
	this->Controls->Add(label1);
  };

  void comboBox1_SelectedIndexChanged(Object^ s, EventArgs^ e) {
    label1->Text = "¶µ¥Ø"+Convert::ToString(comboBox1->SelectedIndex);
  };
};
} } }
