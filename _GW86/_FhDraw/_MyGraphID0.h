//GW86_FhDraw_MyGraphID0.h.
//Gao-Wei Chang, 210911, 210827, 210822, 210810.
#pragma once
#define ID_NONE 0
#define ID_LINE 1
#define ID_CROSS ID_LINE
#define ID_RECT 2
#define ID_ELLIP 3
#define ID_FRECT 22
#define ID_FELLIP 33
#define ID_TMR 100
#define TA_NONE 0
#define TA_PATT 1000
#define ID_DARR 2000
#define TA_DARR ID_DARR+ID_TMR
#define ID_SINE 3000
#define TA_SINE ID_SINE+ID_TMR

#define LEN_SPAN  4
#define LEN_GEO 4
#define ID_ERR1 -1
#define ID_ERR2 -2
#define ID_ERR3 -3
#define ID_ERR4 -4

namespace GW86 {
namespace FhDraw {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
public ref class MyGraphID {
public:
static int postShapeID(bool bFilled, int iShape) {
  if (!bFilled) {
	if (iShape == ID_FRECT) iShape = ID_RECT;
    if (iShape == ID_FELLIP) iShape = ID_ELLIP; }
  else {
	if (iShape == ID_RECT) iShape = ID_FRECT;
	if (iShape == ID_ELLIP) iShape = ID_FELLIP;
  };
  return iShape;
};
};
} }