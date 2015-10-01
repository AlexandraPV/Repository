#import <math.h>
int satisfies(int a, int b, int c) {
    int result;
    int modmin,min,max,sum2;
    if (a<0 && b<0 && c<0)
    {
        if (a<b && a<c)
        {
            modmin=abs(a); sum2=b+c;
        }
        else
            if (b<c && b<a)
            {
                modmin=abs(b); sum2=a+c;
            }
            else
            {
                modmin=abs(c); sum2=a+b;
            }
        
        if (sum2<-256 && modmin==1 && modmin==2 && modmin==4 && modmin==8 && modmin==16 && modmin==32 && modmin==64 && modmin==128)
        {
            result=1;
        }
        else
            if ((abs(sum2)-modmin)<16 || (abs(sum2)<16))
            {
                result=1;
            }
        
    }
    else
        if (a<0 && b>=0 && c>=0 && a>-256)
        {
            result=1;
        }
        else
            if ( b<0 && a>=0 && c>=0 && b>-256)
            {
                result=1;
            }
            else
                if(c<0 && a>=0 && b>=0 && c>-256)
                {
                    result=1;
                }
                else
                    if ( a<0 && b<0 && c>=0 && ((a+b)*5)>-256)
                    {
                        result=1;
                    }
                    else
                        if(b<0 && c<0 && a>=0 && ((b+c)*5)>-256)
                        {
                            result=1;
                        }
                        else
                            if( a<0 && c<0 && b>=0 && ((a+c)*5)>-256)
                            {
                                result=1;
                            }
                            else
                                if ( a>=0 && b>=0 && c>=0 )
                                {
                                    if (a>b && a>c)
                                    {
                                        max=a;
                                    }
                                    else
                                        if (b>a && b>c)
                                        {
                                            max=b;
                                        }
                                        else
                                            max=c;
                                    
                                    
                                    if (a<b && a<c)
                                    {
                                        min=a;
                                    }
                                    else
                                        if (b<a && b<c)
                                        {
                                            min=b;
                                        }
                                        else
                                            min=c;
                                    if ((pow(max,min)<32767) && (pow(max,min)>-32767))
                                    {
                                        result=1;
                                    }
                                
                                else
                                {
                                    result=0;
                                }
                        }
                                else
                                {
                                    result=0;
                                }
    
    return result;
}
