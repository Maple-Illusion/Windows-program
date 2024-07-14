//summ_x0.h
//Gao-Wei Chang, 210303, 180402, 170307.
#pragma once
double mySumm(double x) {
  static double summ=0; //(1.1)
  //double summ=0; //(1.1a)
  summ+=x; //(1.2)
  //summ=summ+x; //(1.2a)¦P(1.2)
  return summ;
}