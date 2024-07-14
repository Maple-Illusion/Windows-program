#pragma once
#include "C:\Users\ataraxia\Documents\AV_LAB\NTNU_Cpp\_GW86\_FpDraw\_MyCmTaskID0.h"
#include "C:\Users\ataraxia\Documents\AV_LAB\NTNU_Cpp\_GW86\_FpDraw\_MyCmProc0.h"


namespace C4 {
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace GW86::FpDraw;

	public ref class myDialog : public Form {

	public:
		MyContainer^ container;
	public:
		myDialog(MyContainer^container) {
			InitializeComponent();
			this->container = container;
		};
	private:
		
		TextBox^ textBox1;
		Button^ button1, ^ button2, ^ button3;
		static int clw = 250, clh = 200;
	private:
		void InitializeComponent() {
			this->Text = "MyDialog";
			this->ClientSize = System::Drawing::Size(clw, clh);
			this->BackColor = Color::WhiteSmoke;
			this->Load += gcnew EventHandler(this, &myDialog::MyDialog_Load);

			textBox1 = gcnew TextBox;
			this->Controls->Add(textBox1);
			textBox1->Text = "Cmd";
			textBox1->Location = System::Drawing::Point(10, 20);
			textBox1->Width = (clw / 2) - 10; textBox1->Height = clh - 90;
			textBox1->Multiline = true;

			button1 = gcnew Button;
			this->Controls->Add(button1);
			button1->Text = "Ex.";
			int btw = 55; int bth = 25;
			int xSepa = (clw - 3 * btw) / 4;
			button1->Location = System::Drawing::Point(xSepa, clh - 50);
			button1->Size = System::Drawing::Size(btw, bth);
			button1->Click += gcnew EventHandler(this, &myDialog::Ex_Click);

			button2 = gcnew Button;
			this->Controls->Add(button2);
			button2->Text = "Draw";
			button2->Location = System::Drawing::Point(btw + 2 * xSepa, clh - 50);
			button2->Size = System::Drawing::Size(btw, bth);
			button2->Click += gcnew EventHandler(this, &myDialog::Draw_Click);

			button3 = gcnew Button;
			this->Controls->Add(button3);
			button3->Text = "Clear";
			button3->Location = System::Drawing::Point(clw - btw - xSepa, clh - 50);
			button3->Size = System::Drawing::Size(btw, bth);
			button3->Click += gcnew EventHandler(this, &myDialog::Clear_Click);
		}

	private:
		Graphics^ G1;
		Pen^ RedPen2;
		Pen^ BluePen2;
		void MyDialog_Load(System::Object^ sender, System::EventArgs^ e) {
			G1 = this->CreateGraphics();
			RedPen2 = gcnew Pen(Color::Red, 2);
			BluePen2 = gcnew Pen(Color::Blue, 2);
		}

	private:
		void Ex_Click(System::Object^ sender, System::EventArgs^ e) {
			array<String^>^ szExCm = { "draw 0.2 0.4 0.8 0.4", "sinw 1 5 0 0",
		 "line 130 122 250 122", "ellipse 140 72 100 100", "rectangle 140 72 100 100" };
			textBox1->Text = szExCm[0] + "\r\n" + szExCm[1] + "\r\n" +
				szExCm[2] + "\r\n" + szExCm[3] + "\r\n" + szExCm[4];
		}
	private:
		void _cmRdFzMa();
		void _drawPatt();

		void Draw_Click(System::Object^ sender, System::EventArgs^ e) ;
		void Clear_Click(System::Object^ sender, System::EventArgs^ e) ;
		void Draw_custom(Pen^ pen) {
			

		};
	public:
		static int idOpc = ID_DRAW_SINW;
		static array<double>^ opds = { 1, 5, 0, 0 };
		static array<String^>^ szOpcDraw =
		{ "line", "rectangle", "ellipse", "draw", "sinw" };

	private:
		static int pattx0 = 3 * (clw / 4) - 25;
		static int patty0 = (clh / 2) - 50;
	};

}

