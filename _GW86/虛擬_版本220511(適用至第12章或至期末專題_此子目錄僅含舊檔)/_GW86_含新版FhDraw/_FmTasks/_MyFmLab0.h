//_MyFmLab0.h (¥Ø¿ý_GW86_FmTasks)
//Gao-Wei Chang, 180502.
#pragma once
namespace GW86 {
namespace FmTasks {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

public ref class MyFmLab0 : public Form {
public:
	Label^ label1;
	System::Drawing::Font^ myFont;
	MyFmLab0(int cnt) {
	  this->Width=200; this->Height=150;
	  label1=gcnew Label;
	  label1->Width = 80; label1->Height = 60;
	  myFont=gcnew System::Drawing::Font("Times New Roman", 16);
	  label1->Font =myFont;
	  label1->Text =cnt.ToString();
	  this->Controls->Add(label1);
	};
};
} }

