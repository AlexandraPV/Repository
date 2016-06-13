//
//  Student.h
//  №3
//
//  Created by Alexandra on 13.06.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include <stdio.h>

typedef struct student_s
{
    int id;
    char name[20];
    char surname[20];
    char fathername[20];
    char birthDate[50];
    char * placeOFbirth[50];
    int booknum;
} student_t;

void print_std(const student_t *std);
void print_AllSTD(student_t *std, int size);

#endif /* Student_h */
