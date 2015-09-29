double calc(double x, double y, double z) {
    double a;
    if ( (x!=y) && (z!=0) && (x!=0) && (sin(x)!=0) )
    {
        a=((pow(x,y+1))/(pow(x-y, 1/z))) + ((4*y)+(z/x)) + sqrt(fabs(cos(y)/sin(x)+1));
    }
    else
    {
    return NAN;
    }
    return a;
    }
