//cla_summx0.h
//Gao-Wei Chang, 180402, 170307.
#pragma once
class MyMath0 {
public:
    static double summ(double x) {
        static double summ = 0; //(1.1)
        summ += x; //(1.2)
        return summ;
    };
};