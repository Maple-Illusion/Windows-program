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
		     gcnew System::Drawing::Font("新細明體", 9); 
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
	  if (i==0||i==nDiv) {//繪製座標邊框
        g1->DrawLine(blackPen1, x_begin, yloc, x_end, yloc);
	    g1->DrawLine(blackPen1, xloc, y_begin, xloc, y_end); }
	  else {//繪製格線
	    g1->DrawLine(lightGrayPen1, x_begin, yloc, x_end, yloc);
	    g1->DrawLine(lightGrayPen1, xloc, y_begin, xloc, y_end);
	  };
	  g1->DrawString(xval.ToString(), cnFont9, //標示x(y)讀值變數
			  Brushes::Gray, xloc+xval_xdelta, y_end+xval_ydelta);
	  g1->DrawString(yval.ToString(), cnFont9,
			  Brushes::Gray, x_begin+yval_xdelta, yloc+yval_ydelta);
	};
	g1->DrawString("x", cnFont9, Brushes::Red, 
		  xlabel_xloc, xlabel_yloc);//標示座標的x(y)變數名稱
	g1->DrawString("y", cnFont9, Brushes::Red,
		  ylabel_xloc, ylabel_yloc);
  }
};//End of MyCoord0.
} }

//(註)：
//源自GW86_Fm12Graphics_MyCoord0.h
//自訂座標繪製類別(使用圖形盒，或簡稱圖盒)
//namespace GW86 {//請注意，像素座標之原點在左上角。
 //namespace Fx12Coords {//自訂繪圖命名空間 }}
//public ref class MyCoord_pTab0 //自訂座標類別之屬性表
//CLR數值型態一般為double，但其繪圖函式的傳入參數通常
 //為int或float(或單精度浮點數Single)。
//座標邊框至圖盒左(下)緣距離與該盒寬(高)比

//讀值標示至最近格線端點之像素座標偏差與圖盒寬(高)比
//xval_xdelta_rate=-0.02, xval_ydelta_rate=0.02,
//yval_xdelta_rate=-0.075, yval_ydelta_rate=-0.05,
//變數名稱至圖盒左(上)緣距離與該盒寬(高)比
//xlabel_xloc_rate=0.5, xlabel_yloc_rate=0.93,
//ylabel_xloc_rate=0.004, ylabel_yloc_rate=0.45;

 //自訂繪圖資源；前置命名：色彩或字型體，後置：大小。
//static System::Drawing::Font^ cnFont9 = //cn:中文，大小：9。
//gcnew System::Drawing::Font("新細明體", 9); 

//public ref class MyCoord0 : public MyCoord_pTab0 {
//public://資料成員；具底線者為座標像素，無者為座標讀值。
//float wBox, hBox;//圖盒之寬與長。
//float x_begin, x_end, y_begin, y_end;//起始與終止座標
//對應於讀值上下限xmin, xmax, ymin, ymax。
//float xval_xdelta, xval_ydelta;
//0.建構函式(具輸入參數)；資料成員之初始化
//MyCoord0(PictureBox^ pictureBox1) {
//wBox=float(pictureBox1->Width);
//建構直角座標在圖盒的邊緣所對應之像素
//x_begin = float(x0_margin_rate*wBox);
//建立變數數值標記之座標偏差量
//xval_xdelta = float(xval_xdelta_rate*wBox);
//建立變數名稱標記的座標
//xlabel_xloc = float(xlabel_xloc_rate*wBox);

//  public: //1.成員函式：線性(均勻)直角座標繪製(含標記)
//void drawRectCoord(Graphics^ g1, float xmin, float xmax,
//		                  float ymin, float ymax, float nDiv) { 
//	  float x_div = float((x_end-x_begin)/nDiv);//x(y)間格之像素數目
//	  float y_div = float((y_end-y_begin)/nDiv);
//	  float xval, yval; //自訂座標讀值
//	  float xloc, yloc; //圖形盒座標像素(具有底線)
//for (float i=0; i<=nDiv; i++) {
//	  xval=xmin+(i/nDiv)*(xmax-xmin); //對應於格線之x(y)讀值
//	  yval=ymin+(i/nDiv)*(ymax-ymin);
//	  xloc=x_begin+(i*x_div);//x(y)座標像素從左到右(由下到上)
//	  yloc=y_end-(i*y_div);//對應從小到大的x(y)座標讀值
//	  if ((xval==0)&&(yval==0)) {//繪製x與y軸(交於原點)
//	    g1->DrawLine(lightGrayPen2, x_begin, yloc, x_end, yloc);
//		g1->DrawLine(lightGrayPen2, xloc, y_begin, xloc, y_end);
 //   };



