#pragma once

#include "C:\Users\ataraxia\Documents\AV_LAB\NTNU_Cpp\_GW86\_FpDraw\_MyPixRect0.h"

//#include "C:\Users\ataraxia\Documents\AV_LAB\NTNU_Cpp\_GW86\_FpDraw\_MyPixGr0.h"
//#include "C:\Users\ataraxia\Documents\AV_LAB\NTNU_Cpp\_GW86\_FpDraw\_MyCmTaskID0.h"


namespace F1 {
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace GW86::FpDraw;
	public ref class myform: public Form{

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

		PictureBox^ Picbox1;
		MyRect0^ myRect;
		Graphics^ G1;
		
		Pen^ RedPen;
		Pen^ BlackPen;

		float xmin = 0, xmax = 10;
		float ymin = 0, ymax = 10;
		float nDiv = 10;

	
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
			this->GraphMen->DropDownItems->AddRange(gcnew array<ToolStripItem^>(3) { DrGeo , DrPF, DrDa
			});

			this->DrGeo->Click += gcnew EventHandler(this, &myform::DrGeo_click);
			this->DrPF->Click += gcnew EventHandler(this, &myform::DrPF_click);
			this->DrDa->Click += gcnew EventHandler(this, &myform::DrDa_click);

			
			this->Mst->Items->AddRange(gcnew array<ToolStripItem^>(3) {
				FileMen, MathMen,GraphMen});

			
			this->Load += gcnew EventHandler(this,&myform::myform_load);

			Picbox1 = gcnew PictureBox();
			Picbox1->Width = 300;
			Picbox1->Height = 300;
			Picbox1->Location = Point(100,50);
			this->Controls->Add(Picbox1);
			Picbox1->Paint += gcnew PaintEventHandler(this, &myform::PB1_paint);

			
			
			


		};
		void myform_load(Object^s,EventArgs^e) {
			//G1 = Picbox1->CreateGraphics();
			myRect = gcnew GW86::FpDraw::MyRect0(Picbox1);
		};
		void PB1_paint(Object^ sender,PaintEventArgs^ e) {
			G1 = e->Graphics;
			myRect->drawRectCoord(G1, xmin, xmax, ymin, ymax, nDiv);
		};

		void DrGeo_click(Object^ s, EventArgs^ e) {

		};
		void DrPF_click(Object^ s, EventArgs^ e) {

		};
		void DrDa_click(Object^ s, EventArgs^ e) {

		};

	};
	
}
