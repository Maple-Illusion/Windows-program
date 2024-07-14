//_fp12.4_ghctn_fcmpatt0.cpp
//Gao-Wei Chang, 230227, 220511, 200603, 171010.
#include "_fp12.4_MyForm0.h"
using namespace ghctn_fcmpatt0;
void main() {
  Application::Run(gcnew MyForm0);
}

void ghctn_fcmpatt0::MyForm0::_drawGeo
  (Pen^ myPen1, int idOpc, array<double>^ opds) {
  pictureBox1->Refresh();
  int x0, y0, x1, y1, w, h;
  x0 = int(opds[0]); y0 = int(opds[1]);
  switch (idOpc) {
  case ID_LINE:
    x1 = int(opds[2]); y1 = int(opds[3]);
	g1->DrawLine(myPen1, x0, y0, x1, y1);
	break;
  case ID_RECTANGLE:
	w = int(opds[2]); h = int(opds[3]);
	g1->DrawRectangle(myPen1, x0, y0, w, h);
	break;
  case ID_ELLIPSE:
	w = int(opds[2]); h = int(opds[3]);
	g1->DrawEllipse(myPen1, x0, y0, w, h);
	break;
  };
}

