//_fp12.3_MyDialog3.h
//Gao-Wei Chang, 220511, 201016, 200603, 171010.
#pragma once
#include "c:\_GW86\_FpDraw\_MyCmTaskID0.h"
#include "c:\_GW86\_FpDraw\_MyCmProc0.h"

namespace ghdia_fpatt0 {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace GW86::FpDraw;

public ref class MyDialog3: public Form {
public:
  MyDialog3() {
    InitializeComponent();
  };
private:
  TextBox^ textBox1;
  Button ^button1, ^button2, ^ button3;
  static int clw = 250, clh = 200;
private:
  void InitializeComponent() {
	this->Text = "MyDialog3";
	this->ClientSize = System::Drawing::Size(clw, clh);
	this->BackColor = Color::WhiteSmoke;
	this->Load +=gcnew EventHandler(this, &MyDialog3::MyDialog3_Load);

	textBox1 = gcnew TextBox;
	this->Controls->Add(textBox1);
	textBox1->Text = "Cmd";
	textBox1->Location = System::Drawing::Point(10, 20);
	textBox1->Width =(clw/2)-10; textBox1->Height =clh-90;
	textBox1->Multiline = true;

	button1 = gcnew Button;
	this->Controls->Add(button1);
	button1->Text = "Ex.";
	int btw = 55; int bth = 25;
	int xSepa = (clw - 3 * btw) / 4;
	button1->Location = System::Drawing::Point(xSepa, clh-50);
	button1->Size=System::Drawing::Size(btw, bth);
	button1->Click += gcnew EventHandler(this, &MyDialog3::button1_Click);

	button2 = gcnew Button;
	this->Controls->Add(button2);
	button2->Text = "Draw";
	button2->Location = System::Drawing::Point(btw+2*xSepa, clh-50);
	button2->Size=System::Drawing::Size(btw, bth);
	button2->Click += gcnew EventHandler(this, &MyDialog3::button2_Click);

	button3 = gcnew Button;
	this->Controls->Add(button3);
	button3->Text = "Clear";
	button3->Location = System::Drawing::Point(clw-btw-xSepa, clh-50);
	button3->Size=System::Drawing::Size(btw, bth);
	button3->Click += gcnew EventHandler(this, &MyDialog3::button3_Click);
  }

private:
void MyDialog3_Load(System::Object^ sender, System::EventArgs^ e) {
}

private:
void button1_Click(System::Object^ sender, System::EventArgs^ e) { }
private:
System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {};
System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {};

};
}

//textBox1->Multiline = true; //必要。
//設定為多列，我們才可改變文字盒textBox1的高度。
