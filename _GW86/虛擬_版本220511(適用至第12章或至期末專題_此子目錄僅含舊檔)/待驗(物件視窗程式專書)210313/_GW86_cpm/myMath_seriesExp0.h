//myMath_seriesExp0.h
//Gao-Wei Chang, 170108.
#pragma once
#define PI 3.14159

double myPow(double x, int n) {
    double pow = 1;
	for (int i = 0; i < n; i++)
	  pow = pow*x;
	return pow;
}

 double myFac(int n) {
	double fac = 1;
	for (int i = 0; i < n; i++)
	  fac = fac*(i + 1);
	return fac;
}

 double myExp(double x, int n) {
	double summ = 0;
	for (int i = 0; i < n; i++)
	  summ = summ + (myPow(x, i) / myFac(i));
	return summ;
}

 double mySin(double theta_x, int n) {
	double summ = 0;
	for (int i = 0; i < n; i++)
	  summ = summ + 
	  (myPow(-1, i)*myPow(theta_x, (2*i+1))/myFac(2*i+1));
	return summ;
}

 double myCos(double theta_x, int n) {
	double summ = 0;
	for (int i = 0; i < n; i++)
	  summ = summ + (myPow(-1, i)*myPow(theta_x, (2*i))/myFac(2*i));
	return summ;
}

