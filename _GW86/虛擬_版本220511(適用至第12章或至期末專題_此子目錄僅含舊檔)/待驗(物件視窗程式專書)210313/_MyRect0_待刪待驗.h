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
  };//將數值轉換為座標(像素)

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
  };//繪製x與y軸(交於原點)

  private:
  void _drawBorders(Graphics^ g1, float xloc, float yloc) {
	Pen^ blackPen1 = gcnew Pen(Color::Black, 1); //(1.0) 
    g1->DrawLine(blackPen1, x_begin, yloc, x_end, yloc); //(1.1)
	g1->DrawLine(blackPen1, xloc, y_begin, xloc, y_end); //(1.2)
  }; //繪製座標邊框

  private:
  void _drawGrids(Graphics^ g1, float xloc, float yloc) {
	Pen^ lightGrayPen1 = gcnew Pen(Color::LightGray, 1); //(1.0) 
    g1->DrawLine(lightGrayPen1, x_begin, yloc, x_end, yloc); //(1.1)
	g1->DrawLine(lightGrayPen1, xloc, y_begin, xloc, y_end); //(1.2)
  };//繪製格線

  private:
  void _drawValues(Graphics^ g1, Font^ myFont, int nFloat,
		  float xval, float yval, float xloc, float yloc) {
	String^ szFloat = "F"+nFloat.ToString();
    g1->DrawString(xval.ToString(szFloat), myFont, //(1.1)
			Brushes::Gray, xloc+xval_xdelta, y_end+xval_ydelta);
    g1->DrawString(yval.ToString(szFloat), myFont, //(1.2)
			Brushes::Gray, x_begin+yval_xdelta, yloc+yval_ydelta);
  }; //標示x, y讀值變數

  private:
  void _drawLabels(Graphics^ g1, Font^ myFont) {
    g1->DrawString("x", myFont, Brushes::Red, 
		    xlabel_xloc, xlabel_yloc); //(1.1)
	g1->DrawString("y", myFont, Brushes::Red,
		    ylabel_xloc, ylabel_yloc);  //(1.2)
  }; //標示座標的x, y變數名稱

};//End of MyRect0.
} }

//依據x與y座標軸的定義，兩者交於原點，因此它們
//所繪製的位置係由其座標範圍(如xmin與xmax)決定。

//舊版myCoord_val2pixel(...)
//註1：
//(0)源自GW86_Fm12Graphics_MyCoord0x.h。
//(1)目標：自訂座標繪製類別(使用圖形盒，或簡稱圖盒)
//(2)以新建CLR空專案的方式，建立CLR類別庫。值得注意的是，
//在專案屬性頁中，設定組態屬性>一般項目的組態類型欄位
//選擇動態程式庫(*.dll)。
//(3)目標Framework: .NetFramework, Version=4.5。
//(4)平台工具組: Visual Studio 2012 (v110)。
//(5)不使用命名空間System::ComponentModel。

//(註):
//class MyCoord_pTab0自訂座標類別之屬性表
//為int或float(或單精度浮點數Single)。
//CLR數值型態一般為double，但其繪圖函式的傳入參數通常
//(1.x)座標邊框至圖盒左(下)緣距離與該盒寬(高)比
//自訂繪圖資源；前置命名：色彩或字型體，後置：大小。
//cn:中文，大小：9。
//(2.x):讀值標示至最近格線端點之像素座標偏差與圖盒寬(高)比
//(3.x):變數名稱至圖盒左(上)緣距離與該盒寬(高)比。

//namespace GW86::Fx12Coords
//請注意，像素座標之原點在左上角。
//自訂繪圖命名空間

//類別MyCoord0 
//(1.x):資料成員；具底線者為座標像素，無者為座標讀值。
//(1.1):圖盒之寬與長。
//(1.2):起始與終止座標對應於讀值上下限xmin, xmax, ymin, ymax。

//0.建構函式MyCoord0(具輸入參數)；資料成員之初始化
//(1.x):依據圖形盒之尺寸，建構直角座標在圖盒的邊緣所對應之像素
//(2.x):建立變數數值標記之座標偏差量
//(3.x):建立變數名稱標記的座標

//1.成員函式myCoord_val2pxl0：線性(均勻)直角座標繪製(含標記)
//(1.1): x(y)間格之像素數目
//(1.2): 自訂座標讀值
//(1.3): 圖形盒座標像素(具有底線)

//(2.x): for (...) { ... };
//(2.1a):對應於格線之x(y)讀值
//(2.2a): x(y)座標像素從左到右(由下到上)
//(2.2b): 對應從小到大的x(y)座標讀值
//(2.3): 成員函式_mDrawAxesGrids
//(2.4): 成員函式_mDrawScales
//(3.1): 成員函式_mDrawAxesLabels

//	  void _mInit_szLoc() { ... }
//xval_xdelta //數值x相對於下邊框之下方偏差量
//xval_ydelta //數值x相對於左邊框之左方偏差量



