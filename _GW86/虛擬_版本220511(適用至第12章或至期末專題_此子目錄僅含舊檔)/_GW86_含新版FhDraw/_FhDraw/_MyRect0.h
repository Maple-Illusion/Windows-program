//_MyRect0.h
//Gao-Wei Chang, 200606, 180526, 160614, 140711, 131228.
#pragma once
namespace GW86 {
 namespace FhDraw {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
public ref class MyRectTab0 {
public:
  static double
  x0_margin_rate=0.11, x1_margin_rate=0.94, 
  y0_margin_rate=0.07, y1_margin_rate=0.87;
  static double
  xval_xdelta_rate=-0.02, xval_ydelta_rate=0.02,
  yval_xdelta_rate=-0.075, yval_ydelta_rate=-0.05,
  xlabel_xloc_rate=0.5, xlabel_yloc_rate=0.93,
  ylabel_xloc_rate=0.004, ylabel_yloc_rate=0.45;
  static System::Drawing::Font^ cnFont9 = 
		     gcnew System::Drawing::Font("�s�ө���", 9); 
  static Pen^ blackPen1 = gcnew Pen(Color::Black, 1);
  static Pen^ lightGrayPen1 = gcnew Pen(Color::LightGray, 1);
  static Pen^ lightGrayPen2 = gcnew Pen(Color::LightGray, 2);
};
 } }

namespace GW86 {
 namespace FhDraw {
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
public ref class MyRect0 : public MyRectTab0 {
public:
  float wBox, hBox;
  float x_begin, x_end, y_begin, y_end;
  float xval_xdelta, xval_ydelta;
  float yval_xdelta, yval_ydelta;
  float xlabel_xloc, xlabel_yloc;
  float ylabel_xloc, ylabel_yloc;

  public:
  MyRect0(PictureBox^ pictureBox1) {
    wBox=float(pictureBox1->Width);
    hBox=float(pictureBox1->Height);
    x_begin = float(x0_margin_rate*wBox);
    x_end = float(x1_margin_rate*wBox);
    y_begin = float(y0_margin_rate*hBox);
    y_end = float(y1_margin_rate*hBox);
    xval_xdelta = float(xval_xdelta_rate*wBox);
    xval_ydelta = float(xval_ydelta_rate*hBox);
    yval_xdelta = float(yval_xdelta_rate*wBox);
    yval_ydelta = float(yval_ydelta_rate*hBox);
    xlabel_xloc = float(xlabel_xloc_rate*wBox);
    xlabel_yloc = float(xlabel_yloc_rate*hBox);
    ylabel_xloc = float(ylabel_xloc_rate*wBox);
    ylabel_yloc = float(ylabel_yloc_rate*hBox);
};

  public:
  void drawRectCoord(Graphics^ g1, float xmin, float xmax,
		                  float ymin, float ymax, float nDiv) { 
    float x_div = float((x_end-x_begin)/nDiv);
	float y_div = float((y_end-y_begin)/nDiv);
	float xval, yval; float xloc, yloc;

	for (int i=0; i<=nDiv; i++) {
	  xval=xmin+(i/nDiv)*(xmax-xmin);
	  yval=ymin+(i/nDiv)*(ymax-ymin);
	  xloc=x_begin+(i*x_div);
	  yloc=y_end-(i*y_div);
	  if ((xval==0)&&(yval==0)) {
	    g1->DrawLine(lightGrayPen2, x_begin, yloc, x_end, yloc);
		g1->DrawLine(lightGrayPen2, xloc, y_begin, xloc, y_end);
      };
	  if (i==0||i==nDiv) {//ø�s�y�����
        g1->DrawLine(blackPen1, x_begin, yloc, x_end, yloc);
	    g1->DrawLine(blackPen1, xloc, y_begin, xloc, y_end); }
	  else {//ø�s��u
	    g1->DrawLine(lightGrayPen1, x_begin, yloc, x_end, yloc);
	    g1->DrawLine(lightGrayPen1, xloc, y_begin, xloc, y_end);
	  };
	  g1->DrawString(xval.ToString(), cnFont9, //�Х�x(y)Ū���ܼ�
			  Brushes::Gray, xloc+xval_xdelta, y_end+xval_ydelta);
	  g1->DrawString(yval.ToString(), cnFont9,
			  Brushes::Gray, x_begin+yval_xdelta, yloc+yval_ydelta);
	};
	g1->DrawString("x", cnFont9, Brushes::Red, 
		  xlabel_xloc, xlabel_yloc);//�Хܮy�Ъ�x(y)�ܼƦW��
	g1->DrawString("y", cnFont9, Brushes::Red,
		  ylabel_xloc, ylabel_yloc);
  }
};//End of MyCoord0.
} }

//(��)�G
//����GW86_Fm12Graphics_MyCoord0.h
//�ۭq�y��ø�s���O(�ϥιϧβ��A��²�ٹϲ�)
//namespace GW86 {//�Ъ`�N�A�����y�Ф����I�b���W���C
 //namespace Fx12Coords {//�ۭqø�ϩR�W�Ŷ� }}
//public ref class MyCoord_pTab0 //�ۭq�y�����O���ݩʪ�
//CLR�ƭȫ��A�@�묰double�A����ø�Ϩ禡���ǤJ�ѼƳq�`
 //��int��float(�γ��ׯB�I��Single)�C
//�y����ئܹϲ���(�U)�t�Z���P�Ӳ��e(��)��

//Ū�ȼХܦ̪ܳ��u���I�������y�а��t�P�ϲ��e(��)��
//xval_xdelta_rate=-0.02, xval_ydelta_rate=0.02,
//yval_xdelta_rate=-0.075, yval_ydelta_rate=-0.05,
//�ܼƦW�٦ܹϲ���(�W)�t�Z���P�Ӳ��e(��)��
//xlabel_xloc_rate=0.5, xlabel_yloc_rate=0.93,
//ylabel_xloc_rate=0.004, ylabel_yloc_rate=0.45;

 //�ۭqø�ϸ귽�F�e�m�R�W�G��m�Φr����A��m�G�j�p�C
//static System::Drawing::Font^ cnFont9 = //cn:����A�j�p�G9�C
//gcnew System::Drawing::Font("�s�ө���", 9); 

//public ref class MyCoord0 : public MyCoord_pTab0 {
//public://��Ʀ����F�㩳�u�̬��y�й����A�L�̬��y��Ū�ȡC
//float wBox, hBox;//�ϲ����e�P���C
//float x_begin, x_end, y_begin, y_end;//�_�l�P�פ�y��
//������Ū�ȤW�U��xmin, xmax, ymin, ymax�C
//float xval_xdelta, xval_ydelta;
//0.�غc�禡(���J�Ѽ�)�F��Ʀ�������l��
//MyCoord0(PictureBox^ pictureBox1) {
//wBox=float(pictureBox1->Width);
//�غc�����y�Цb�ϲ�����t�ҹ���������
//x_begin = float(x0_margin_rate*wBox);
//�إ��ܼƼƭȼаO���y�а��t�q
//xval_xdelta = float(xval_xdelta_rate*wBox);
//�إ��ܼƦW�ټаO���y��
//xlabel_xloc = float(xlabel_xloc_rate*wBox);

//  public: //1.�����禡�G�u��(����)�����y��ø�s(�t�аO)
//void drawRectCoord(Graphics^ g1, float xmin, float xmax,
//		                  float ymin, float ymax, float nDiv) { 
//	  float x_div = float((x_end-x_begin)/nDiv);//x(y)���椧�����ƥ�
//	  float y_div = float((y_end-y_begin)/nDiv);
//	  float xval, yval; //�ۭq�y��Ū��
//	  float xloc, yloc; //�ϧβ��y�й���(�㦳���u)
//for (float i=0; i<=nDiv; i++) {
//	  xval=xmin+(i/nDiv)*(xmax-xmin); //�������u��x(y)Ū��
//	  yval=ymin+(i/nDiv)*(ymax-ymin);
//	  xloc=x_begin+(i*x_div);//x(y)�y�й����q����k(�ѤU��W)
//	  yloc=y_end-(i*y_div);//�����q�p��j��x(y)�y��Ū��
//	  if ((xval==0)&&(yval==0)) {//ø�sx�Py�b(�����I)
//	    g1->DrawLine(lightGrayPen2, x_begin, yloc, x_end, yloc);
//		g1->DrawLine(lightGrayPen2, xloc, y_begin, xloc, y_end);
 //   };



