//GW86_FhDraw_MyVGra0.h.
//Gao-Wei Chang, 210827, 210816, 201012, 180611, 160707, 140307.
#pragma once
#include "c:\_GW86\_FhDraw\_MyRect0.h"
#include "c:\_GW86\_ClrMath\_MySExppStat0.h"
//#include "c:\_GW86\_FhDraw\_MyGraphID0.h"
#define PI 3.14159
namespace GW86 {
namespace FhDraw {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace GW86::ClrMath;

public ref class MyVaGr0 {
public: static void val2pixCoord(MyRect0^ theCoord0, float xval, float yval,
	float* px_coord, float* py_coord, array<float>^ xyspan) {
	float xmin = xyspan[0]; float xmax = xyspan[1];
	float ymin = xyspan[2]; float ymax = xyspan[3];
	float rx = (xval - xmin) / (xmax - xmin);
	float ry = (yval - ymin) / (ymax - ymin);
	*px_coord = (theCoord0->x_begin) + //(1.2a)
		    rx * (theCoord0->x_end - theCoord0->x_begin); 
	*py_coord = (theCoord0->y_end) - //(1.2b)
		    ry * (theCoord0->y_end - theCoord0->y_begin); 
};

public:
static void drawSeg(Graphics^ g1, MyRect0^ theCoord0, Pen^ myPen1,
	float xval, float yval, array<float>^ xyspan, int xNum) {
	static int i = 0, nTerm = 0;
	static float x_coord[2], y_coord[2];
	if (xNum == 0) { nTerm = 0; return; };//(1.1):��xNum=0�ɡA���m���I�C
	val2pixCoord(theCoord0, xval, yval, &x_coord[i], &y_coord[i], xyspan);
	if ((nTerm == 0) || (nTerm == xNum))//�P�_�O�_���_�l�I�P���I
		g1->DrawLine(myPen1, x_coord[i], y_coord[i],
			x_coord[i], y_coord[i]);
	else g1->DrawLine(myPen1, x_coord[0], y_coord[0],
		x_coord[1], y_coord[1]); //(2.1)
	if (i == 0) i = 1; else i = 0; //(2.2):�s��a�A�D0�h1�C
	if (nTerm < xNum) nTerm++; else nTerm = 0;//(2.3):0��xNum-1�C
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

/*public: static void evalMidAxes(MyRect0^ theCoord0,
	float* px_mid, float* py_mid, array<float>^ xyspan) {
  float xmin = xyspan[0]; float xmax = xyspan[1];
  float ymin = xyspan[2]; float ymax = xyspan[3];
  float xmid = (xmax + xmin) / 2;
  float ymid = (ymax + ymin) / 2;
  val2pCoord(theCoord0, xmid, ymid, px_mid, py_mid, xyspan);
};

public:
static void drawMidAxes(Graphics^ g1, MyRect0^ theCoord0,
  Pen^ myPen1, array<float>^ xyspan) {
  float x_mid, y_mid;
  evalMidAxes(theCoord0, &x_mid, &y_mid, xyspan);
  g1->DrawLine(myPen1, theCoord0->x_begin, y_mid,
										  theCoord0->x_end, y_mid); //(2.1)
  g1->DrawLine(myPen1, x_mid, theCoord0->y_begin,
										  x_mid, theCoord0->y_end); //(2.2)
};*/

