//_fp12.4_MyForm0.h
//Gao-Wei Chang, 220511, 201017, 200606, 180527, 171010, 170404.
#pragma once
#include "c:\_GW86\_FpDraw\_MyPixRect0.h"
#include "c:\_GW86\_FpDraw\_MyPixGr0.h"
#include "_fp12.3_MyDialog3.h"

namespace ghdia_fpatt0 {
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
    using namespace GW86::FpDraw; //自訂繪圖命名空間

	public ref class MyForm0 : public Form {
	public:
	  MyForm0(void) {
		InitializeComponent();
	  };
	  ~MyForm0() {
		  if (components) delete components;
	  };
	private: System::ComponentModel::Container^ components;
	private: MenuStrip^  menuStrip1;
	private: ToolStripMenuItem^ fileToolStripMenuItem;
	private: ToolStripMenuItem^ mathToolStripMenuItem;
	private: ToolStripMenuItem^ graphToolStripMenuItem;
	private: ToolStripMenuItem^ cmdToolStripMenuItem;
	private: ToolStripMenuItem^ drGeoToolStripMenuItem;
	private: ToolStripMenuItem^ drPFToolStripMenuItem;
	private: ToolStripMenuItem^ drDaToolStripMenuItem;
	private: ToolStripMenuItem^ clearToolStripMenuItem;
    public: PictureBox^ pictureBox1;

	private:
	static int clw = 400, clh = 300;
	static int pbw=clw-40, pbh=clh-40;
    void InitializeComponent(void) {
	  this->Text = "MyForm0";
	  this->ClientSize =System::Drawing::Size(clw, clh);
	  this->BackColor = Color::White;
	  this->menuStrip1 = gcnew MenuStrip(); //(m1.1)
	  this->Controls->Add(this->menuStrip1); //(m1.2)
	  this->Load +=gcnew EventHandler(this, &MyForm0::MyForm0_Load);

	  pictureBox1 = gcnew PictureBox;
	  pictureBox1->Location = Point(20, 30);
	  pictureBox1->Width = pbw;
	  pictureBox1->Height = pbh;
	  this->Controls->Add(pictureBox1);
      pictureBox1->Paint += gcnew PaintEventHandler
	                                        (this, &MyForm0::pictureBox1_Paint);

	  this->fileToolStripMenuItem = gcnew ToolStripMenuItem();  //(x1.1)
	  this->fileToolStripMenuItem->Text = L"File";  //(x1.2)
	  this->fileToolStripMenuItem->Enabled = false; //(x1.3)

      this->mathToolStripMenuItem = gcnew ToolStripMenuItem();  //(x2.1)
	  this->mathToolStripMenuItem->Text = L"Math";  //(x2.2)
	  this->mathToolStripMenuItem->Enabled = false;  //(x2.3)

      this->graphToolStripMenuItem = gcnew ToolStripMenuItem();  //(x3.1)
	  this->graphToolStripMenuItem->Text = L"Graph";  //(x3.2)

	  this->menuStrip1->Items->AddRange(gcnew array<ToolStripItem^>(3) {
		       fileToolStripMenuItem, mathToolStripMenuItem,
			   graphToolStripMenuItem});

	  this->cmdToolStripMenuItem = gcnew ToolStripMenuItem();
	  this->cmdToolStripMenuItem->Text = L"Cmd";
	  this->cmdToolStripMenuItem->Click += gcnew EventHandler(this,
				&MyForm0::cmdToolStripMenuItem_Click);

	  this->drGeoToolStripMenuItem = gcnew ToolStripMenuItem();
	  this->drGeoToolStripMenuItem->Text = L"DrGeo";
	  //this->drGeoToolStripMenuItem->Enabled = false;
	  this->drGeoToolStripMenuItem->Click += gcnew EventHandler(this,
				&MyForm0::drGeoToolStripMenuItem_Click);

	  this->drPFToolStripMenuItem = gcnew ToolStripMenuItem();
	  this->drPFToolStripMenuItem->Text = L"DrPF";
	  this->drPFToolStripMenuItem->Click += gcnew EventHandler(this,
				&MyForm0::drPFToolStripMenuItem_Click);

	  this->drDaToolStripMenuItem = gcnew ToolStripMenuItem();
	  this->drDaToolStripMenuItem->Text = L"DrDa";
	  this->drDaToolStripMenuItem->Enabled = false;

	  this->clearToolStripMenuItem = gcnew ToolStripMenuItem();
	  this->clearToolStripMenuItem->Text = L"Clear";
	  this->clearToolStripMenuItem->Click += gcnew EventHandler(this,
				&MyForm0::clearToolStripMenuItem_Click);

	  this->graphToolStripMenuItem->DropDownItems->AddRange
				(gcnew array<ToolStripItem^>(5){ cmdToolStripMenuItem,
				drGeoToolStripMenuItem, drPFToolStripMenuItem, drDaToolStripMenuItem, 
				clearToolStripMenuItem });

  }

private: System::Void cmdToolStripMenuItem_Click
  (System::Object^  sender, System::EventArgs^  e) {
  MyDialog3^ theDialog3 = gcnew MyDialog3();
  theDialog3->Show();
}

private: System::Void drGeoToolStripMenuItem_Click
	   (System::Object^ sender, System::EventArgs^ e) {
	pictureBox1->Refresh();
	g1->DrawEllipse(redPen1, 135, 70, 100, 100);
}

public:
Graphics^ g1;
MyRect0^ theCoord0;
System::Drawing::Font^ myFont12;
private:
Pen ^redPen1, ^redPen2;
Pen ^bluePen1, ^grayPen1, ^grayPen2;

private:
void MyForm0_Load(System::Object^ sender, System::EventArgs^ e) {
  g1=pictureBox1->CreateGraphics();
  theCoord0 = gcnew MyRect0(pictureBox1); //非常重要。
  redPen1 = gcnew Pen(Color::Red, 1);
  redPen2 = gcnew Pen(Color::Red, 2);
  bluePen1 = gcnew Pen(Color::Blue, 1);
  grayPen1 = gcnew Pen(Color::LightGray, 1);
  grayPen2 = gcnew Pen(Color::LightGray, 2);
  myFont12 = gcnew System::Drawing::Font("New Times Roman", 12);
}

private:
static float xmin = 0, xmax = 10;
static float ymin = -1, ymax = 1;
static float nDiv = 10;//區隔數目
static float xRes = float(0.1);//解析度數值
public:
static int nPt = int(xmax / xRes) + 2; //自變數樣本數目
static array<float>^ xyspan = { xmin, xmax, ymin, ymax };

private:
System::Void pictureBox1_Paint
	   (System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Graphics^ g0 = e->Graphics;
	theCoord0->drawRectCoord(g0, xmin, xmax, ymin, ymax, nDiv);
};

private: static array<double>^ opds = { 1, 5, 0, 0 };
private: System::Void drPFToolStripMenuItem_Click
	   (System::Object^ sender, System::EventArgs^ e) {
  pictureBox1->Refresh();
  MyVaGr0::drawSine(g1, theCoord0, grayPen1, opds, xyspan, nPt);
}

private: System::Void clearToolStripMenuItem_Click
	  (System::Object^ sender, System::EventArgs^ e) {
    pictureBox1->Refresh();
}

#define PATTW 150
#define PATTH 150
private:
static int pbx0 = (pbw/2) + 9;
static int pby0 = (pbh/2) - 8;

public:
void _drawGeo(Pen^, int, array<double>^);
}; } 