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
	double theta_xp0 = theta_x-(2*PI)*int4_2pi;//�����W�L2*PI���ƭȡC
	return cos(theta_xp0, n);
  };

  double sin_p0(double theta_x, int n) {
	int int4_2pi = int(theta_x/(2*PI));
	double theta_xp0 = theta_x-(2*PI)*int4_2pi;//�����W�L2*PI���ƭȡC
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
//�ؼСG
//(1)�b�ե�GW86���A�إ�Taylor�żƮi�}�ƭȭp�⤧���O�禡�w
//   (�R�A)�C�䤤�����禡�w���e�Y����gw86_cprog_sin0.h�C
//(2)�Ө禡�w���T���禡����J�y�ץi�h���g��(2*PI)���v�C
//   �Y�ȭp��Ө��׹���������0��2*PI���d��C�p���קK�p��
//   ����(overflow)����������~�C
//Gao-Wei Chang, 160426.

