#include "Q3_F.h"



void C4::myDialog::Draw_Click(System::Object^ sender, System::EventArgs^ e) {
    this->_cmRdFzMa();
    this->Refresh();
    this->container->theForm->Picbox1->Refresh();
    switch (this->idOpc) {
    case ID_LINE:
    case ID_RECTANGLE:
    case ID_ELLIPSE:
        this->_drawPatt();
        this->container->theForm->_drawGeo(RedPen2, this->idOpc, this->opds);
        break;
    case ID_DRAW_DAT:
        this->container->theForm->_drawGeo(BluePen2, this->idOpc, this->opds);
        break;
    case ID_ERROR:
        textBox1->Text = "No match or format error.";
        break;
    };
}

void C4::myDialog::Clear_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Refresh();
    this->container->theForm->Picbox1->Refresh();
}

void C4::myDialog::_cmRdFzMa() {
    String^ szInput = textBox1->Text;
    array<String^>^ szCmd = szInput->Split();
    int len = szCmd->Length;
    this->opds = gcnew array<double>(len - 1);//¦©°£opcode
    this->idOpc = MyCmPost0::cmFzMa(szCmd, szOpcDraw, this->opds);
}

void C4::myDialog::_drawPatt() {
    switch (this->idOpc) {
    case ID_LINE:
        G1->DrawLine(BluePen2, pattx0 - 5, patty0 + 25, pattx0 + 55, patty0 + 25);
        break;
    case ID_RECTANGLE:
        G1->DrawRectangle(BluePen2, pattx0, patty0, 50, 50);
        break;
    case ID_ELLIPSE:
        G1->DrawEllipse(BluePen2, pattx0, patty0, 50, 50);
        break;
    
        

    };
}
