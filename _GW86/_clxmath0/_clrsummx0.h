//_clrsummx0.h
//Gao-Wei Chang, 210302, 180402, 170307.
#pragma once
ref class MyMath0 {
public:
    static double summ(double x) {
        static double summ = 0; //(1.1)
        summ += x; //(1.2)
        return summ;
    };
};