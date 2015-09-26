//
//  main.c
//  26.09
//
//  Created by Alexandra on 26.09.15.
//  Copyright © 2015 Alexandra. All rights reserved.
//

#include <stdio.h>
int main () {
    printf ( "City code:");
    int code;
    scanf ("%d", & code);
    
    printf("Hours:");
    int hours;
    scanf ("%d", &hours);
    
    printf("Minutes:");
    int minutes;
    scanf("%d", &minutes);
    
    double tariff;
    switch (code) {
        case 44: {
            tariff = 0.44;
            break;
            }
        case 37: {
            tariff = 1.05;
            break;
            }
        case 1: {
            tariff = 30;
            break;
        }
        case 66: {
            tariff = 0;
            break;
        }
        default: {
            tariff = 1;
            break;
        }
    }
    int allMinutes = (hours * 60) + minutes;
    double resultTariff = allMinutes * tariff;
    printf ("%.2lf\n", resultTariff);
    
    return 0;
}

