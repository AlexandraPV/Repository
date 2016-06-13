//
//  Student.c
//  №3
//
//  Created by Alexandra on 13.06.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#include "Student.h"

void print_std(const student_t *std)
{
    printf("Name: %s\n", std->name);
    printf("Surname: %s\n", std->surname);
    printf("Futhername: %s\n",std->fathername);
    printf("Birthdate: %s\n", std->birthDate);
    printf("PlaceOFbirth: %s\n",std->placeOFbirth);
    printf("Booknum:%i\n", std->booknum);
   
    
    
}

void print_AllSTD(student_t *student, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%i.", (i+1));
        print_std(&student[i]);
        printf("");
    }
}