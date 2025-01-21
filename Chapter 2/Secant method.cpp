/* 
* Secant Method:
* Algorithm description: 
* for given values xo and x1 near the root x2, a line is constructed along (xo, f(xo)) and (x1, f(x1)). 
* x2 = x1 - f(x1) * ((x1 - xo)/(f(x1) - f(xo))) 
* then, xo = x1 and x1 = x2, until |x1 - x2| < TLV
* NOTE: f(x1) * f(xo) < 0 is not satisfied.
*/
#include "inclusions.hpp"
double secant(double (*func) (double), double xo, double x1){
    int iter = 0;
    double x2;
    do{
        iter++;
        x2 = x1 - func(x1) * ((x1 - xo)/(func(x1) - func(xo)));
        xo = x1;
        x1 = x2;
    }
    while(abs(x2 - xo) >= TLV);
    cout << ' ' << iter << " iterations" << endl;
    return x2;
}
double func(double x){
    return 3 * x + sin(x) - pow(2.718, x);
}
int main(){
    cout << " root = " << secant(func, 0, 1) << endl;
    double x;
    cout << " Enter x for check: ";
    cin >> x;
    cout << " f(" << x << ") = " << func(x) << endl;
}