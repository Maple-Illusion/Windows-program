//_fp12.4_MyDialog3.h
//Gao-Wei Chang, 220511, 201016, 200603, 171010.
#pragma once
#include "c:\_GW86\_FpDraw\_MyCmTaskID0.h"
#include "c:\_GW86\_FpDraw\_MyCmProc0.h"

namespace ghctn_fcmpatt0 {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace GW86::FpDraw;

public ref class MyDialog3: public Form {
public:
  MyContainer0^ theContainer0;
public:
  MyDialog3(MyContainer0^ theContainer0) {
    InitializeComponent();
	this->theContainer0=theContainer0;
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
Graphics^ g1;
Pen ^redPen2, ^bluePen2;
void MyDialog3_Load(System::Object^ sender, System::EventArgs^ e) {
  g1 = this->CreateGraphics();
  redPen2 = gcnew Pen(Color::Red, 2);
  bluePen2 = gcnew Pen(Color::Blue, 2);
}

private:
void button1_Click(System::Object^ sender, System::EventArgs^ e) {
  array<String^>^ szExCm ={"draw 0.2 0.4 0.6 0.8", "sinw 1 5 0 0",
	     "line 130 122 250 122", "ellipse 140 72 100 100", "rectangle 140 72 100 100"};
  textBox1->Text =szExCm[0]+"\r\n"+szExCm[1] + "\r\n" + 
	                          szExCm[2] + "\r\n" + szExCm[3] + "\r\n" + szExCm[4];
}

private:
System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);

public:
static int idOpc = ID_DRAW_SINW;
static array<double>^ opds = { 1, 5, 0, 0 };
static array<String^>^ szOpcDraw = 
         {"line", "rectangle", "ellipse", "draw", "sinw"};

private:
static int pattx0 = 3 * (clw / 4) - 25;
static int patty0 = (clh / 2) - 50;
void _cmRdFzMa();
void _drawPatt();

};
}

//textBox1->Multiline = true; //必要。
//設定為多列，我們才可改變文字盒textBox1的高度。
