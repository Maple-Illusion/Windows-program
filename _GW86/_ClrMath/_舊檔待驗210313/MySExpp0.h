//GW86_ClrMath_MySExpp0.h
//Gao-Wei Chang, 170603, 170507, 151219.
#pragma once
#define PI 3.14159

namespace GW86 {
namespace ClrMath {
public ref class MySExpp0 {
public:
  double pow(double x, int n) {
    double pow = 1;
    for (int i = 0; i < n; i++)
      pow = pow*x;
    return pow;
  };

  double fac(int n) {
    double fac = 1;
    for (int i = 0; i < n; i++)
      fac = fac*(i + 1);
    return fac;
  };

  double exp(double x, int n) {
    double summ = 0;
    for (int i = 0; i < n; i++)
      summ = summ + (pow(x, i)/fac(i));
    return summ;
  };

  double cos(double theta_x, int n) {
    double summ = 0;
    for (int i = 0; i < n; i++)
      summ = summ + (pow(-1, i)*pow(theta_x, (2*i))/fac(2*i));
    return summ;
  };

  double sin(double theta_x, int n) {
    double summ = 0;
    for (int i = 0; i < n; i++)
      summ = summ + (pow(-1, i)*pow(theta_x, (2*i+1))/fac(2*i+1));
    return summ;
  };

  double cos_p0(double theta_x, int n) {
    int int4_2pi = int(theta_x/(2*PI));
	double theta_xp0 = theta_x-(2*PI)*int4_2pi;//扣除超過2*PI的數值。
	return cos(theta_xp0, n);
  };

  double sin_p0(double theta_x, int n) {
	int int4_2pi = int(theta_x/(2*PI));
	double theta_xp0 = theta_x-(2*PI)*int4_2pi;//扣除超過2*PI的數值。
	return sin(theta_xp0, n);
  };

  double sinc(double x, int n) {
    double summ = 0;
    for (int i = 0; i < n; i++)
      summ = summ + (pow(-1, i)*pow(x, 2*i)/fac(2*i+1));
    return summ;
  };

  double atan(double x, int n) {
    double summ=0;
    for (int i=0; i<n; i++)
	  summ=summ+(pow(-1, i)*pow(x, 2*i+1)/(2*i+1));
    return summ;
  };

  double asinh(double x, int n) {
    double summ=0;
    for (int i=0; i<n; i++)
      summ=summ+(pow(-1, i)*fac(2*i)*pow(x, 2*i+1)/
	                       ((2*i+1)*pow(fac(i),2)*pow(4,i)));
    return summ;
  };
};
}
}


//GW86_ClrMath_MyStatSExpp0.h
//目標：
//(1)在組件GW86中，建立Taylor級數展開數值計算之類別函式庫
//   (靜態)。其中該類函式庫內容係源自gw86_cprog_sin0.h。
//(2)該函式庫之三角函式的輸入弳度可去除週期(2*PI)倍率。
//   即僅計算該角度對應的有效0至2*PI的範圍。如此避免計算
//   溢位(overflow)等執行期錯誤。
//Gao-Wei Chang, 160426.

