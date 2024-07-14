//_ClrMath\MyFmPow0.h
//Gao-Wei Chang, 180513.
#pragma once
namespace GW86 {
namespace FmTasks {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace GW86::ClrMath;

public ref class MyFmPow0 : public Form {
public:
  MyFmPow0() {
    InitializeComponent();
  };
  TextBox ^textBox1, ^textBox2;
  Button ^button1, ^button2, ^button3;
  Label^ label1;

  void InitializeComponent() {
    this->Width=250; this->Height=200;
	textBox1=gcnew TextBox;
	this->Controls->Add(textBox1);
	textBox1->Location = Point(15, 17);
    textBox1->Width=102; textBox1->Height=30;

	textBox2=gcnew TextBox;
	this->Controls->Add(textBox2);
	textBox2->Location = Point(15, 52);
	textBox2->Multiline = true;
    textBox2->Width=102; textBox2->Height=82;

	label1=gcnew Label;
	this->Controls->Add(label1);
	label1->Location = Point(138, 22);
    label1->Width=130; label1->Height=30;
	label1->Text ="(pow 1.3 2)";

	button1=gcnew Button;
	this->Controls->Add(button1);
	button1->Location = Point(135, 51);
	button1->Text = "Cmd ex.";
	button1->Click += gcnew EventHandler(this, &MyFmPow0::button1_Click);

	button2=gcnew Button;
	this->Controls->Add(button2);
	button2->Location = Point(135, 82);
	button2->Text = "Enter";
	button2->Click += gcnew EventHandler(this, &MyFmPow0::button2_Click);

	button3=gcnew Button;
	this->Controls->Add(button3);
	button3->Location = Point(135, 113);
	button3->Text = "Clear";
	button3->Click += gcnew EventHandler(this, &MyFmPow0::button3_Click);
  };

  void button1_Click(Object^ s, EventArgs^ e); 
  void button2_Click(Object^ s, EventArgs^ e);
  void button3_Click(Object^ s, EventArgs^ e);
};
} }

