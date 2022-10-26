#include <stdio.h>
#include <math.h>
#include <function.cpp>
#include "head.h"
//метод трапеций по определению
double trapetion(double x_i, double step, int n){
    double value = 0;
    for (int i=0; i<n; i++){
        value+=step*(function(x_i)+function(x_i+step))/2;
        x_i+=step;
    }
    return value;
}

//int main(){return 0;}