//_fp12.4_MyDialog3.cpp
//Gao-Wei Chang, 220511, 201016, 200606, 171010.
#include "_fp12.4_MyForm0.h"

System::Void ghctn_fcmpatt0::MyDialog3::button2_Click
  (System::Object^  sender, System::EventArgs^  e) {
  this->_cmRdFzMa();
  this->Refresh();
  this->theContainer0->theForm0->pictureBox1->Refresh();
  switch(this->idOpc)  {
    case ID_LINE:
    case ID_RECTANGLE:
    case ID_ELLIPSE:
      this->_drawPatt();
      this->theContainer0->theForm0->_drawGeo(redPen2, this->idOpc, this->opds);
      break;
    case ID_ERROR:
      textBox1->Text = "No match or format error.";
      break;
  };
}

System::Void ghctn_fcmpatt0::MyDialog3::button3_Click
  (System::Object^  sender, System::EventArgs^  e) {
  this->Refresh();
  this->theContainer0->theForm0->pictureBox1->Refresh();
}

void ghctn_fcmpatt0::MyDialog3::_cmRdFzMa() {
    String^ szInput = textBox1->Text;
    array<String^>^ szCmd = szInput->Split();
    int len = szCmd->Length;
    this->opds = gcnew array<double>(len - 1);//¦©°£opcode
    this->idOpc = MyCmPost0::cmFzMa(szCmd, szOpcDraw, this->opds);
}

void ghctn_fcmpatt0::MyDialog3::_drawPatt() {
    switch (this->idOpc) {
    case ID_LINE:
        g1->DrawLine(bluePen2, pattx0-5, patty0+25, pattx0+55, patty0+25);
        break;
    case ID_RECTANGLE:
        g1->DrawRectangle(bluePen2, pattx0, patty0, 50, 50);
        break;
    case ID_ELLIPSE:
        g1->DrawEllipse(bluePen2, pattx0, patty0, 50, 50);
        break;
    };
}
