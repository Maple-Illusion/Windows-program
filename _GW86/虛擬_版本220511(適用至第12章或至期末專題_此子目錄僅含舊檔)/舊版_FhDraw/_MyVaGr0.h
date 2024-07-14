//GW86_FhDraw_MyVGra0.h.
//Gao-Wei Chang, 200606, 180611, 160707, 140710, 140307.
#pragma once
#include "c:\_GW86\_FhDraw\_MyRect0.h"
#include "c:\_GW86\_ClrMath\_MySExppStat0.h"
#define PI 3.14159
namespace GW86 {
namespace FhDraw {
  using namespace System;
  using namespace System::Windows::Forms;
  using namespace System::Drawing;
  using namespace GW86::FhDraw;//�s�W
  using namespace GW86::ClrMath;

public ref class MyVaGr0 {
public:
static void drawSeg(Graphics^ g1, MyRect0^ theCoord0,
  Pen^ myPen1, float xval, float yval, float xmin,
  float xmax, float ymin, float ymax, int xNum) {
  static int i = 0, nTerm = 0;
  static float x_coord[2], y_coord[2];
  if (xNum == 0) { nTerm = 0; return;
  };//(1.1):�D�`���n!��xNum=0�ɡA���m���I�C
  x_coord[i] = (theCoord0->x_begin) + ((xval-xmin)/(xmax-xmin))* 
	           (theCoord0->x_end-theCoord0->x_begin); //(1.2a)
  y_coord[i] = (theCoord0->y_end) - ((yval-ymin)/(ymax-ymin))*
	           (theCoord0->y_end-theCoord0->y_begin); //(1.2b)
  if ((nTerm == 0)||(nTerm==xNum))//�P�_�O�_���_�l�I�P���I
	   g1->DrawLine(myPen1, x_coord[i], y_coord[i],
		                    x_coord[i], y_coord[i]);
  else g1->DrawLine(myPen1, x_coord[0], y_coord[0],
		                    x_coord[1], y_coord[1]); //(2.1)
  if (i==0) i=1; else i=0; //(2.2):�s��a�A�D0�h1�C
  if (nTerm<xNum) nTerm++; else nTerm = 0;//(2.3):0��xNum-1�C
};

public:
static void drawSeg(Graphics^ g1, MyRect0^ theCoord0, Pen^ myPen1,
  array<float>^ xyspan, float xval, float yval, int xNum) {
  static int i = 0, nTerm = 0;
  static float x_coord[2], y_coord[2];
  if (xNum == 0) {
    nTerm = 0; return;
  };//(1.1):�D�`���n!��xNum=0�ɡA���m���I�C
  float xmin = xyspan[0]; float xmax = xyspan[1];
  float ymin = xyspan[2]; float ymax = xyspan[3];
  x_coord[i] = (theCoord0->x_begin) + ((xval - xmin) / (xmax - xmin)) *
			           (theCoord0->x_end - theCoord0->x_begin); //(1.2a)
  y_coord[i] = (theCoord0->y_end) - ((yval - ymin) / (ymax - ymin)) *
			           (theCoord0->y_end - theCoord0->y_begin); //(1.2b)
  if ((nTerm == 0) || (nTerm == xNum))//�P�_�O�_���_�l�I�P���I
    g1->DrawLine(myPen1, x_coord[i], y_coord[i], x_coord[i], y_coord[i]);
  else g1->DrawLine(myPen1, x_coord[0], y_coord[0], x_coord[1], y_coord[1]); //(2.1)
  if (i == 0) i = 1; else i = 0; //(2.2):�s��a�A�D0�h1�C
  if (nTerm < xNum) nTerm++; else nTerm = 0;//(2.3):0��xNum-1�C
};

public:
static void drawPFn(Graphics^ g1, MyRect0^ theCoord0, Pen^ myPen1,
  array<double>^ opds, array<float>^ xyspan, int nPt) {
  double A, T, val2phase, offset; //cyc = 2;
  A = opds[0]; T = opds[1]; //�g��T = xmax/cyc;
  val2phase = opds[2]; offset = opds[3];
  float* px = new float[nPt];
  float* py = new float[nPt];
  float xRes = xyspan[1] / float(nPt-1);
  //float xRes = float(0.1);
  drawSeg(g1, theCoord0, myPen1, xyspan, 0, 0, 0);
  for (int i = 0; i < nPt; i++) {
    px[i] = i * xRes;
	double rx = (px[i] - val2phase) / T;
	rx = rx - int(rx);
	//py[i] = float(Math::Sin(2*PI*rx);
	py[i] = float(A * MySExppStat0::sin(2 * PI * rx, 10) + offset);
	drawSeg(g1, theCoord0, myPen1, xyspan, px[i], py[i], nPt);
  };
  delete[] px; delete[] py;
};


};
} }

//(��)
//GW86_Fx12Graphics_MyVGra0.h
//(0)�̾ڡGGW86_Fm12Graphics_MyVGra0x.h
//(1)�ؼСG�ۭq���uø�s(curve-drawing)���O�禡�w�C
// is to add the user defined curve-drawing functions.

//�禡myEvalScrData(...)
//(1.1):�C�@����ܪ��˥��I�ơA�䤤�[1���t��ݺ��I�C
//(1.2):�������ǤJ_totScrSample�ѼƤ���ͫ��СC
//(1.4):totScreen�N����ܹ����`�ơC
//(2.1):�����@���h�H�@���p���A�Хܥثe�̹��ئ�(�q1�}�l�p)�P�`�̹��ơC


