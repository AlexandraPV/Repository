#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double long2double();
int main(){
    long num;
    printf("%.325lf",long2double(num));
}

double long2double() {
    long num;                    //num-first number
    char S, x, y;               // S - sign
    double F=0,E=0, V;         //F-mantisa, V- final number, E- exponenta
    
   printf("Long number:");
   scanf("%ld", &num);
    
    S=(num>>63)&1;
    for (y=52; y<63; ++y) {
        E+=((num>>y)&1)*(pow(2, (y-52)));
    }
    
    for (x=51; x>=0; --x) {
        F+=((num>>x)&1)*(pow(2, (x-52)));
    }
    
    
    if (E==2047 && F!=0)
        return NAN;
    
    else
        if (E==2047 && F==0 && S==1)
            return  -INFINITY;
    
    else
        if (E==2047 && F==0 && S==0)
            return INFINITY;
    
    else
    if ( E>0 && E<2047)
    {
        V=pow((-1),S)*pow(2,E-1023)*(1+F);
        return V;
    }
    
    else
    if (E==0 && F!=0 ) {
        V=pow((-1), S)*pow(2, (-1022))*(F);
        return V;
    }
    
    else
        if (E==0 && F==0 && S==1)
            return -0;
    
    else
        if (E==0 && F==0 && S==0)
            return 0;
    return num;
}
