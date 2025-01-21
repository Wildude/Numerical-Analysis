/*
*/
//g++ "bisection method.cpp" -o "./executables/bisection method"
#include "inclusions.hpp"
double bisect(double (*func) (double), double xo, double x1){
    double x2;
    int iteration = 1;
    do{
        x2 = (xo + x1) / 2;
        if(func(x1) * func(x2) < 0) xo = x2;
        else x1 = x2;
        iteration++;
    }
    while(abs(xo - x1) >= TLV && func(x2));
    cout << ' ' << iteration << " iterations" << endl;
    cout << " root is ";
    return x2;
}
double combo(double x){
    return 3 * x + sin(x) - pow(2.718, x);
}
int main(){
    cout << bisect(combo, 0, 1) << endl;
    double x;
    cout << " Enter x for check: ";
    cin >> x;
    cout << " f(" << x << ") = " << combo(x) << endl;
}