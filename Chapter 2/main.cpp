#include "inclusions.hpp"
double f(double x){
    return sin(x) + 2 * x;
}
int main(){
    falsepos(f, 2, 5);
}