//GW86_ClrMath_MySExppStat0.h
//�w����������ƶg�����B�z�C
//Gao-Wei Chang, 200429, 180405, 170603, 151219.
#pragma once
#define PI 3.14159
namespace GW86 {
namespace ClrMath {
public ref class MySExppStat0 {
public:
  static double pow(double x, int n) {
    double pow = 1;
    for (int i = 0; i < n; i++)
      pow = pow*x;
    return pow;
  };

  static double fac(int n) {
    double fac = 1;
    for (int i = 0; i < n; i++)
      fac = fac*(i + 1);
    return fac;
  };

  static double exp(double x, int n) {
    double summ = 0; //(1.0)
    for (int i = 0; i < n; i++)
      summ = summ + (pow(x, i)/fac(i));
    return summ;
  };

  static double iexp(double x, int i) {
      static double summ = 0;
      if (i == 0) summ = 0;
      summ = summ + (pow(x, i) / fac(i));
      return summ;
  };

  static double cos(double theta_x, int n) {
    double summ = 0;
    for (int i = 0; i < n; i++)
      summ = summ + (pow(-1, i)*pow(theta_x, (2*i))/fac(2*i));
    return summ;
  };

  static double icos(double theta_x, int i) {
      static double summ = 0;
      if (i == 0) summ = 0;
      summ = summ + (pow(-1, i) * pow(theta_x, (2 * i)) / fac(2 * i));
      return summ;
  };

  static double sin(double theta_x, int n) {
    double summ = 0;
    for (int i = 0; i < n; i++)
      summ = summ + (pow(-1, i)*pow(theta_x, (2*i+1))/fac(2*i+1));
    return summ;
  };

  static double isin(double theta_x, int i) {
      static double summ = 0;
      if (i == 0) summ = 0;
      summ = summ + (pow(-1, i) * pow(theta_x, (2 * i + 1)) / fac(2 * i + 1));
      return summ;
  };

  static double sinc(double x, int n) {
    double summ = 0;
    for (int i = 0; i < n; i++)
      summ = summ + (pow(-1, i)*pow(x, 2*i)/fac(2*i+1));
    return summ;
  };

  static double isinc(double x, int i) {
      static double summ = 0;
      if (i == 0) summ = 0;
      summ = summ + (pow(-1, i) * pow(x, 2 * i) / fac(2 * i + 1));
      return summ;
  };

  static double atan(double x, int n) {
    double summ=0;
    for (int i=0; i<n; i++)
	  summ=summ+(pow(-1, i)*pow(x, 2*i+1)/(2*i+1));
    return summ;
  };

  static double iatan(double x, int i) {
      static double summ = 0;
      if (i == 0) summ = 0;
      summ = summ + (pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1));
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
//�ؼСG
//(1)�b�ե�GW86���A�إ�Taylor�żƮi�}�ƭȭp�⤧���O�禡�w
//   (�R�A)�C�䤤�����禡�w���e�Y����gw86_cprog_sin0.h�C
//(2)�Ө禡�w���T���禡����J�y�ץi�h���g��(2*PI)���v�C
//   �Y�ȭp��Ө��׹���������0��2*PI���d��C�p���קK�p��
//   ����(overflow)����������~�C
//Gao-Wei Chang, 160426.


