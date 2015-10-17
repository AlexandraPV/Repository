#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    long num;                //num-first number
    int E=0, S, x, y;        // E- exponenta, S - sign
    double F=0, V;           //F-mantisa, V- final number
    
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
        printf("V=Nan");
    
    else
    if (E==2047 && F==0 && S==1)
        printf("V= -Infinity");
    
    else
    if (E==2047 && F==0 && S==0)
        printf("V= Infinity");
    
    else
    if ( E>0 && E<2047)
    {
        V=pow((-1),S)*pow(2,E-1023)*(1+F);
        printf("%.325f",V);
    }
    
    else
    if (E==0 && F!=0 ) {
        V=pow((-1), S)*pow(2, (-1022))*(F);
        printf("%.325f",V);
    }
    
    else
    if (E==0 && F==0 && S==1)
        printf("V=-0");
    
    else
    if (E==0 && F==0 && S==0)
        printf("V=0");
    
}
