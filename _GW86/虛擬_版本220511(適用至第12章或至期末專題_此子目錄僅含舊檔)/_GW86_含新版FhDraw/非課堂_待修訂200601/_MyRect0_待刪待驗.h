//_GW86_FmCoords\_MyRect0.h
//Gao-Wei Chang, 180526, 180118, 171108, 
//160706, 140711, 131228.
#pragma once
namespace GW86 {
namespace FmCoords {
  using namespace System;
  using namespace System::Windows::Forms;
  using namespace System::Drawing;

  public ref class MyRectTab0 {
  public:
	static bool axesFlag=1, borderFlag=1, //(0.1)
		    gridFlag=1, valFlag=1, labelFlag=1; 
    float x_begin, x_end, y_begin, y_end;//(0.2)
	float xval_xdelta, xval_ydelta,
	        yval_xdelta, yval_ydelta; //(0.3)
	float xlabel_xloc, xlabel_yloc,
	        ylabel_xloc, ylabel_yloc; //(0.4)

  private:
  void _initBorderLoc(float wBox, float hBox) {
	double	x0_margin_rate=0.11,
		        x1_margin_rate=0.94; //(0.1)
	double y0_margin_rate=0.07,
		        y1_margin_rate=0.87; //(0.2)
    x_begin = float(x0_margin_rate*wBox); //(1.1)
	x_end = float(x1_margin_rate*wBox); //(1.2)
	y_begin = float(y0_margin_rate*hBox); //(2.1)
	y_end = float(y1_margin_rate*hBox); //(2.2)
  }

  private:
  void _initValLoc(float wBox, float hBox) {
	double xval_xdelta_rate=-0.02,
		        xval_ydelta_rate=0.02; //(0.1)
	double yval_xdelta_rate=-0.075,
		        yval_ydelta_rate=-0.05; //(0.2)
    xval_xdelta = float(xval_xdelta_rate*wBox); //(1.1)
	xval_ydelta = float(xval_ydelta_rate*hBox); //(1.2)
	yval_xdelta = float(yval_xdelta_rate*wBox); //(2.1)
    yval_ydelta = float(yval_ydelta_rate*hBox); //(2.2)
  }

  private:
  void _initLabelLoc(float wBox, float hBox) {
	double xlabel_xloc_rate=0.5,
		        xlabel_yloc_rate=0.93; //(0.1)
	double ylabel_xloc_rate=0.004,
		        ylabel_yloc_rate=0.45; //(0.2)
	xlabel_xloc = float(xlabel_xloc_rate*wBox); //(1.1)
	xlabel_yloc = float(xlabel_yloc_rate*hBox); //(1.2)
	ylabel_xloc = float(ylabel_xloc_rate*wBox); //(2.1)
	ylabel_yloc = float(ylabel_yloc_rate*hBox); //(2.2)
  }

  public:
  void initAllParam(float wBox, float hBox) {
    _initBorderLoc(wBox, hBox); //(1.1)
	_initValLoc(wBox, hBox);//(2.1)
	_initLabelLoc(wBox, hBox);//(2.2)
  }

  public:
  void tuneDrawFlag(bool axesF, bool borderF,
	  bool gridF, bool valF, bool labelF) {
	this->axesFlag = axesF; //(1.1)
	this->borderFlag = borderF;  //(1.2)
	this->gridFlag = gridF;  //(1.3)
	this->valFlag = valF;  //(2.1)
    this->labelFlag = labelF;  //(2.1)
  }

  public:
  void tuneBorderLoc(float x0_delta, float x1_delta,
	  float y0_delta, float y1_delta) {
     x_begin+=x0_delta; //(1.1)
     x_end+=x1_delta; //(1.2)
     y_begin+=y0_delta; //(2.1)
     y_end+=y1_delta; //(2.2)
  }

  public:
  void tuneValLoc(float xval_xd, float xval_yd,
		  float yval_xd, float yval_yd) {
    xval_xdelta += xval_xd; //(1.1)
	xval_ydelta += xval_yd; //(1.2)
	yval_xdelta += yval_xd; //(2.1)
	yval_ydelta += yval_yd; //(2.2)
  }

  public:
  void tuneLabelLoc(float xlabel_xd, 
		  float xlabel_yd, float ylabel_xd, float ylabel_yd) {
	xlabel_xloc += xlabel_xd; //(1.1)
	xlabel_yloc += xlabel_yd; //(1.2)
	ylabel_xloc += ylabel_xd; //(2.1)
	ylabel_yloc += ylabel_yd; //(2.2)
  }
};

public ref class MyRect0 : public MyRectTab0 {
   public:
     MyRect0(PictureBox^ pictureBox1) {
	   initAllParam(float(pictureBox1->Width),
		                              float(pictureBox1->Height)); //(1.1)
	 }; 

  public:
  void drawRectCoord(Graphics^ g1, Font^ myFont, int nFloat,
		  float xmin, float xmax, float ymin, float ymax, float nDiv) { 
    float xval, yval; //(0.1)
	float xloc, yloc; //(0.2)
	if (axesFlag) { //(1.x)
	  _val2Pixel(0, 0, &xloc, &yloc, //(1.1)
		                    xmin, xmax, ymin, ymax); 
	  _drawAxes(g1, xloc, yloc); //(1.2)
    };
	for (int i=0; i<=nDiv; i++) { //(2.x)
      _gridValnPixel(i, &xval, &yval, &xloc, &yloc,
	    xmin, xmax, ymin, ymax, nDiv); //(2.1)
	  if (((i==0)||(i==nDiv))&&borderFlag) //(2.2)
	    _drawBorders(g1, xloc, yloc); 
	  else if (gridFlag) _drawGrids(g1, xloc, yloc);
	  if (valFlag) //(2.3)
	    _drawValues(g1, myFont, nFloat, xval, yval, xloc, yloc);
    };
	 if (labelFlag) _drawLabels(g1, myFont); //(3.1)
  };

  private:
  void _val2Pixel(float xval, float yval, float* p_xloc,
	float* p_yloc, float xmin, float xmax, float ymin, float ymax) {
  float xRatio=(xval-xmin)/(xmax-xmin); //(1.0a)
  float yRatio=(yval-ymin)/(ymax-ymin); //(1.0b)
  *p_xloc = x_begin+xRatio*(x_end-x_begin);//(1.1)
  *p_yloc = y_end-yRatio*(y_end-y_begin);//(1.2)
  };//�N�ƭ��ഫ���y��(����)

  private:
  void _gridValnPixel(int i, float* p_xval, float* p_yval,
		   float* p_xloc, float* p_yloc, float xmin, float xmax,
		   float ymin, float ymax, float nDiv) {
	*p_xval=xmin+(i/nDiv)*(xmax-xmin); //(2.1)
	*p_yval=ymin+(i/nDiv)*(ymax-ymin); //(2.2)
	*p_xloc=x_begin+(i/nDiv)*(x_end-x_begin); //(3.1)
	*p_yloc=y_end-(i/nDiv)*(y_end-y_begin); //(3.2)
  };

  private:
  void _drawAxes(Graphics^ g1, float xloc, float yloc) {
    Pen^ lightGrayPen2 = gcnew Pen(Color::LightGray, 2); //(1.0)
    g1->DrawLine(lightGrayPen2, x_begin, yloc, x_end, yloc); //(1.1)
	g1->DrawLine(lightGrayPen2, xloc, y_begin, xloc, y_end); //(1.2)
  };//ø�sx�Py�b(�����I)

  private:
  void _drawBorders(Graphics^ g1, float xloc, float yloc) {
	Pen^ blackPen1 = gcnew Pen(Color::Black, 1); //(1.0) 
    g1->DrawLine(blackPen1, x_begin, yloc, x_end, yloc); //(1.1)
	g1->DrawLine(blackPen1, xloc, y_begin, xloc, y_end); //(1.2)
  }; //ø�s�y�����

  private:
  void _drawGrids(Graphics^ g1, float xloc, float yloc) {
	Pen^ lightGrayPen1 = gcnew Pen(Color::LightGray, 1); //(1.0) 
    g1->DrawLine(lightGrayPen1, x_begin, yloc, x_end, yloc); //(1.1)
	g1->DrawLine(lightGrayPen1, xloc, y_begin, xloc, y_end); //(1.2)
  };//ø�s��u

  private:
  void _drawValues(Graphics^ g1, Font^ myFont, int nFloat,
		  float xval, float yval, float xloc, float yloc) {
	String^ szFloat = "F"+nFloat.ToString();
    g1->DrawString(xval.ToString(szFloat), myFont, //(1.1)
			Brushes::Gray, xloc+xval_xdelta, y_end+xval_ydelta);
    g1->DrawString(yval.ToString(szFloat), myFont, //(1.2)
			Brushes::Gray, x_begin+yval_xdelta, yloc+yval_ydelta);
  }; //�Х�x, yŪ���ܼ�

  private:
  void _drawLabels(Graphics^ g1, Font^ myFont) {
    g1->DrawString("x", myFont, Brushes::Red, 
		    xlabel_xloc, xlabel_yloc); //(1.1)
	g1->DrawString("y", myFont, Brushes::Red,
		    ylabel_xloc, ylabel_yloc);  //(1.2)
  }; //�Хܮy�Ъ�x, y�ܼƦW��

};//End of MyRect0.
} }

//�̾�x�Py�y�жb���w�q�A��̥����I�A�]������
//��ø�s����m�Y�Ѩ�y�нd��(�pxmin�Pxmax)�M�w�C

//�ª�myCoord_val2pixel(...)
//��1�G
//(0)����GW86_Fm12Graphics_MyCoord0x.h�C
//(1)�ؼСG�ۭq�y��ø�s���O(�ϥιϧβ��A��²�ٹϲ�)
//(2)�H�s��CLR�űM�ת��覡�A�إ�CLR���O�w�C�ȱo�`�N���O�A
//�b�M���ݩʭ����A�]�w�պA�ݩ�>�@�붵�ت��պA�������
//��ܰʺA�{���w(*.dll)�C
//(3)�ؼ�Framework: .NetFramework, Version=4.5�C
//(4)���x�u���: Visual Studio 2012 (v110)�C
//(5)���ϥΩR�W�Ŷ�System::ComponentModel�C

//(��):
//class MyCoord_pTab0�ۭq�y�����O���ݩʪ�
//��int��float(�γ��ׯB�I��Single)�C
//CLR�ƭȫ��A�@�묰double�A����ø�Ϩ禡���ǤJ�ѼƳq�`
//(1.x)�y����ئܹϲ���(�U)�t�Z���P�Ӳ��e(��)��
//�ۭqø�ϸ귽�F�e�m�R�W�G��m�Φr����A��m�G�j�p�C
//cn:����A�j�p�G9�C
//(2.x):Ū�ȼХܦ̪ܳ��u���I�������y�а��t�P�ϲ��e(��)��
//(3.x):�ܼƦW�٦ܹϲ���(�W)�t�Z���P�Ӳ��e(��)��C

//namespace GW86::Fx12Coords
//�Ъ`�N�A�����y�Ф����I�b���W���C
//�ۭqø�ϩR�W�Ŷ�

//���OMyCoord0 
//(1.x):��Ʀ����F�㩳�u�̬��y�й����A�L�̬��y��Ū�ȡC
//(1.1):�ϲ����e�P���C
//(1.2):�_�l�P�פ�y�й�����Ū�ȤW�U��xmin, xmax, ymin, ymax�C

//0.�غc�禡MyCoord0(���J�Ѽ�)�F��Ʀ�������l��
//(1.x):�̾ڹϧβ����ؤo�A�غc�����y�Цb�ϲ�����t�ҹ���������
//(2.x):�إ��ܼƼƭȼаO���y�а��t�q
//(3.x):�إ��ܼƦW�ټаO���y��

//1.�����禡myCoord_val2pxl0�G�u��(����)�����y��ø�s(�t�аO)
//(1.1): x(y)���椧�����ƥ�
//(1.2): �ۭq�y��Ū��
//(1.3): �ϧβ��y�й���(�㦳���u)

//(2.x): for (...) { ... };
//(2.1a):�������u��x(y)Ū��
//(2.2a): x(y)�y�й����q����k(�ѤU��W)
//(2.2b): �����q�p��j��x(y)�y��Ū��
//(2.3): �����禡_mDrawAxesGrids
//(2.4): �����禡_mDrawScales
//(3.1): �����禡_mDrawAxesLabels

//	  void _mInit_szLoc() { ... }
//xval_xdelta //�ƭ�x�۹��U��ؤ��U�谾�t�q
//xval_ydelta //�ƭ�x�۹����ؤ����谾�t�q



