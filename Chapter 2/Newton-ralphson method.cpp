/*
* Newton-raphson method:
* Algorithm description:
* given xo near the root:
* xr = xo - f(xo) / f'(xo)
* then xo = xr, until |xr - xo| < TLV
*/
// g++ "Newton-raphson method.cpp" -o "./executables/Newton-raphson method.exe"
#include <iostream>
#include <cmath>
using namespace std;
const double TLV = 1e-7;
double d_dx(double (*func) (double), double x){
    return (func(x + TLV) - func(x)) / TLV;
}
double newton(double (*func) (double), double xo){
    int iter = 0;
    double xr, xc;
    do{
        iter++;
        xr = xo - func(xo) / d_dx(func, xo);
        xc = xo;
        xo = xr;
    }
    while(abs(xo - xc) >= TLV);
    cout << ' ' << iter << " iterations" << endl;
    return xr;
}
double func(double x){
    return 3 * x + sin(x) - pow(2.718, x);
}
int main(){
    cout << " root: " << newton(func, 1) << endl;
    double x;
    cout << " Enter x for check: ";
    cin >> x;
    cout << " f(" << x << ") = " << func(x) << endl;
}
