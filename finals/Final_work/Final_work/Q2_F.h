#pragma once

#include "C:\Users\ataraxia\Documents\AV_LAB\NTNU_Cpp\_GW86\_FpDraw\_MyPixRect0.h"

#include "C:\Users\ataraxia\Documents\AV_LAB\NTNU_Cpp\_GW86\_FpDraw\_MyPixGr0.h"
#include "C:\Users\ataraxia\Documents\AV_LAB\NTNU_Cpp\_GW86\_FpDraw\_MyCmTaskID0.h"

namespace F2 {
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace GW86::FpDraw;
	public ref class myform : public Form {

	public:
		myform(void) {
			InitializeComponent();
		};
	private:
		MenuStrip^ Mst;
		ToolStripMenuItem^ FileMen;
		ToolStripMenuItem^ MathMen;
		ToolStripMenuItem^ GraphMen;

		ToolStripMenuItem^ DrGeo;
		ToolStripMenuItem^ DrPF;
		ToolStripMenuItem^ DrDa;


		Pen^ RedPen;
		Pen^ RedPen2;
		Pen^ BluePen;
		Pen^ GrayPen;
		Pen^ BlackPen;

		System::Drawing::Font^ FontSize;

		static float xmin = 0, xmax = 10;
		static float ymin = -1, ymax = 1;
		static float nDiv = 10;

		PictureBox^ Picbox1;
		MyRect0^ myRect;
		Graphics^ G1;

	private:
		void InitializeComponent(void) {
			this->Text = "myform";
			this->Width = 500;
			this->Height = 400;

			this->Mst = gcnew MenuStrip();
			this->Controls->Add(this->Mst);

			this->FileMen = gcnew ToolStripMenuItem();
			this->FileMen->Text = "File";


			this->MathMen = gcnew ToolStripMenuItem();
			this->MathMen->Text = "Math";


			this->GraphMen = gcnew ToolStripMenuItem();
			this->GraphMen->Text = "Graph";

			this->DrGeo = gcnew ToolStripMenuItem();
			this->DrPF = gcnew ToolStripMenuItem();
			this->DrDa = gcnew ToolStripMenuItem();
			this->DrGeo->Text = "DrGeo";
			this->DrPF->Text = "DrPF";
			this->DrDa->Text = "DrDa";
			this->GraphMen->DropDownItems->AddRange(gcnew array<ToolStripItem^>(3) {
				DrGeo, DrPF, DrDa
			});
			this->Load += gcnew EventHandler(this, &myform::myform_load);

			this->DrGeo->Click += gcnew EventHandler(this, &myform::DrGeo_click);
			this->DrPF->Click += gcnew EventHandler(this, &myform::DrPF_click);
			this->DrDa->Click += gcnew EventHandler(this, &myform::DrDa_click);


			this->Mst->Items->AddRange(gcnew array<ToolStripItem^>(3) {
				FileMen, MathMen, GraphMen
			});


			

			Picbox1 = gcnew PictureBox();
			Picbox1->Width = 400;
			Picbox1->Height = 300;
			Picbox1->Location = Point(50, 50);
			this->Controls->Add(Picbox1);
			Picbox1->Paint += gcnew PaintEventHandler(this, &myform::PB1_paint);





	
		};

	private:
		Graphics^ G2;
		static int clw = 400, clh = 300;
		static int pbw = clw - 40, pbh = clh - 40;
		static array<double>^ opds = { 1, 5, 0, 0 };
		static float xRes = float(0.1);
	private:
		static int nPt = int(xmax / xRes) + 2; //自變數樣本數目
		static array<float>^ xyspan = { xmin, xmax, ymin, ymax };
	private:
		void myform_load(Object^ s, EventArgs^ e) {
			G1 = Picbox1->CreateGraphics();
			myRect = gcnew GW86::FpDraw::MyRect0(Picbox1);
			RedPen = gcnew Pen(Color::Red, 1);
			RedPen2 = gcnew Pen(Color::Red, 2);
			BluePen = gcnew Pen(Color::Blue, 1);
			GrayPen = gcnew Pen(Color::LightGray, 1);
			//grayPen2 = gcnew Pen(Color::LightGray, 2);
			FontSize = gcnew System::Drawing::Font("New Times Roman", 12);
		};
		void PB1_paint(Object^ sender, PaintEventArgs^ e) {
			G2 = e->Graphics;
			myRect->drawRectCoord(G2, xmin, xmax, ymin, ymax, nDiv);
		};

		void DrGeo_click(Object^ s, EventArgs^ e) {
			Picbox1->Refresh();
			G1->DrawEllipse(RedPen, 135, 70, 100, 100);
		};
		void DrPF_click(Object^ s, EventArgs^ e) {
			Picbox1->Refresh();
			MyVaGr0::drawSine(G1, myRect, GrayPen, opds, xyspan, nPt);

		};
		void DrDa_click(Object^ s, EventArgs^ e) {
			Picbox1->Refresh();
		};
		#define PATTW 150
		#define PATTH 150
		private:
		static int pbx0 = (pbw / 2) + 9;
		static int pby0 = (pbh / 2) - 8;
	public:
		void _drawGeo(Pen^, int, array<double>^);
	};
	

}

