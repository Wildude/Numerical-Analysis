#include <iostream>
#include <cmath>
using namespace std;
const double TLV = 1e-7;
double d_dx(double (*func) (double), double x){
    return (func(x + TLV) - func(x)) / TLV;
}