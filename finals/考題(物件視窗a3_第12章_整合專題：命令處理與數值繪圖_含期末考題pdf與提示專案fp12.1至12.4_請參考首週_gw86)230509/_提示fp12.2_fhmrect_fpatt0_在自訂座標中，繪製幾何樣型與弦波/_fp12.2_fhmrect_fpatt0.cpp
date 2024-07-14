//_fp12.2_fhmrect_fpatt0.cpp
//Gao-Wei Chang, 230227, 220511, 200603, 171010.
#include "C:\Users\ataraxia\Documents\AV_LAB\NTNU_Cpp\finals\考題(物件視窗a3_第12章_整合專題：命令處理與數值繪圖_含期末考題pdf與提示專案fp12.1至12.4_請參考首週_gw86)230509\_提示fp12.2_fhmrect_fpatt0_在自訂座標中，繪製幾何樣型與弦波\_fp12.2_MyForm0.h"
using namespace fhmrect_fpatt0;


void fhmrect_fpatt0::MyForm0::_drawGeo
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

