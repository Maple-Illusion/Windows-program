//_fp12.2_fhmrect_fpatt0.cpp
//Gao-Wei Chang, 230227, 220511, 200603, 171010.
#include "C:\Users\ataraxia\Documents\AV_LAB\NTNU_Cpp\finals\���D(�������a3_��12��_��X�M�D�G�R�O�B�z�P�ƭ�ø��_�t�������Dpdf�P���ܱM��fp12.1��12.4_�аѦҭ��g_gw86)230509\_����fp12.2_fhmrect_fpatt0_�b�ۭq�y�Ф��Aø�s�X��˫��P���i\_fp12.2_MyForm0.h"
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

