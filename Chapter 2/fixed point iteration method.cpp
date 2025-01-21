/*
* Fixed point iteration method:
* Algorithm description:
* for inputs:
* - g (a particular function or rearrangement such that g(x) = x) and
* - xo initial guess
* REPEAT:
* SET x1 = xo
* SET xo = g(xo)
* UNTIL: |x1 - xo| < TLV
* RETURN x0
*/
// g++ "fixed point iteration method.cpp" -o "./executables/fixed point iteration method.exe"
#include <iostream>
#include <cmath>
using namespace std;
const double TLV = 1e-7;
double FPI(double (*g)(double), double xo){
    double x1;
    int iter = 0;
    do{
        iter++;
        x1 = xo;
        xo = g(xo);
        cout << ' ' << iter << " iterations: x = " << xo << endl;
    }
    while(abs(x1 - xo) >= TLV);
    cout << ' ' << iter << " iterations" << endl;
    return xo;
}
// original function is: f(x) = x^2 - 2x - 3
double g1(double x){
    return cbrt((5 - pow(2.71828, x)) / 2);
}
double g2(double x){
    return log10(5 - 2 * x * x * x) / log10(2.71828);
}
int main(){
    cout << " root_1: " << FPI(g1, 4) << endl;
    cout << " root_2: " << FPI(g2, 4) << endl;
}