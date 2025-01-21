/*
* False position method:
* Algorithm description:
* for initial values xo and x1, where f(xo) * f(x1) < 0
* estimate the root, xr, as:
* xr = (x1 * f(x1) - xo * f(xo)) / (f(xo) - f(x1))
* then check:
* if f(xo) * f(xr) < 0, then x1 = xr
* else if f(xo) * f(xr) > 0, then xo = xr
* else if f(xo) * f(xr) = 0, then xr is the root
*/
// g++ "False position method.cpp" -o "./executables/False position method.exe"
#include <iostream>
#include <cmath>
using namespace std;
const double TLV = 1e-7;
double falsepos(double (*func) (double), double xo, double x1){
    double xr;
    int iter = 0;
    if(func(xo) * func(x1) >= 0){cout << " error: choose xo and x1 such that f(xo) * f(x1) < 0" << endl; return TLV;} //error
    for(;;){
        iter++;
        double xold = xr;
        xr = (x1 * func(xo) - xo * func(x1)) / (func(xo) - func(x1));
        double TLVe = abs((xr - xold) / xr) * 100;
        if(TLVe <= TLV){cout << ' ' << iter << " iterations" << endl; return xr;}
        if(func(xo) * func(xr) < 0){x1 = xr;}
        else if(func(xo) * func(xr) > 0)xo = xr;
    }
}
double func(double x){
    return 3 * x + sin(x) - pow(2.718, x);
}
int main(){
    cout << " root = " << falsepos(func, 0, 1);
    double x;
    cout << " Enter x for check: ";
    cin >> x;
    cout << " f(" << x << ") = " << func(x) << endl;
}