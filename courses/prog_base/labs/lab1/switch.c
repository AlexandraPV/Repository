#include <math.h>

int sizeOfData_type ( int data_type) {
 
    switch (data_type) {
        case 0:
            return  sizeof(char);
        case 1:
            return sizeof(signed char);
        case 2:
            return sizeof(short);
        case 3:
            return sizeof(unsigned int);
        case 4:
            return sizeof(long);
        case 5:
            return sizeof(unsigned long long);
        case 6:
            return sizeof(float);
        case 7:
            return sizeof(double);
            
        default:
            return 0;
    }
}

int exec(int op, int a, int b) {
    int result;
   if (op < 0) {
        int c = a;
        a = b;
        b = c;
        op *= -1;
    }
    switch (op)
    {
        case 0: return -a;
        case 1: return a+b;
        case 2: return a-b;
        case 3: return a*b;
        case 4: return a/b;
        case 5: return abs(a);
        case 6: return pow(a,b);
        case 7:
        case 13:
        case 77:
            return a%b;
        
        case 8: return a>b ? a : b;
        case 9: return a<b ? a : b;
        case 10: return abs(a) * sizeOfData_type(abs(b) % 8);
        case 11: if (a==1)
            return 0;
            else
                return floor((5 * cos(b*M_PI)) / (a-1));
        default:
            if (op<100)
               return(op % abs(a + 1)) + (op % abs(b + 1));
            else
              if (op>=100)
                  return -1;
    }
    return result;
}
