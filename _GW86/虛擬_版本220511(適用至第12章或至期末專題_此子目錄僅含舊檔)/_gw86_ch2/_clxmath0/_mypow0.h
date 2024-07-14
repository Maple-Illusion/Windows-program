//_mypow0.h
//Gao-Wei Chang, 210302.
#pragma once //¥u½sÄ¶¤@¦¸
double myPow(double x, int n) {
  double pow=1;
  for (int i=0; i<n; i++) {
		pow=pow*x;
  };
  return pow;
}