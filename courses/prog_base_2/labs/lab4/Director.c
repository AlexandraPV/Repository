//
//  Director.c
//  lab_2_4
//
//  Created by Alexandra on 28.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#include "Director.h"
#include <stdlib.h>
#include <string.h>




struct Director {
    char * name;
    char * surname;
    char * birthdate;
    char * company;
    char * name_com;
    char * specialization;
    int year;
    double rating;
};

direct * Director_new(void){
    direct * self =malloc(sizeof(direct));
    self->name = NULL;
    self->surname = NULL;
    self->birthdate=NULL;
    self->company=NULL;
    self->name_com=NULL;
    self->specialization= NULL;
    self->year= 0;
    self->rating=0;
    return self;
    
}
void Director_free(direct * self){
    free(self);
}


void Director_set(direct * self, char * name, char * surname, char * birthdate, char * company,char * name_com, char * specialization, int year,double rating){
    if(name!=NULL){
        self->name=malloc(sizeof(name));
        strcpy(self->name,name);
    }else
        self->name=name;
    if(surname!=NULL)
    {
        self->surname=malloc(sizeof(surname));
        strcpy(self->surname,surname);
    }
    else
        self->surname=surname;
    if ( birthdate !=NULL){
        self->birthdate=malloc(sizeof(birthdate));
        strcpy(self->birthdate,birthdate);
    }else self->birthdate=birthdate;
    
    if (company != NULL){
        self->company=malloc(sizeof(company));
        strcpy(self->company, company);
    }else self->company=company;
    
    if(name_com!=NULL){
        self->name_com= malloc(sizeof(name_com));
        strcpy(self->name_com, name_com);
    }else self->name_com=name_com;
    
    if (specialization != NULL){
        self->specialization=malloc(sizeof(specialization));
        strcpy(self->specialization, specialization);
    }
    
    self->year=year;
    self->rating=rating;
}

char * Director_name_get(direct * self){
    return self->name;
}

char * Director_surname_get(direct * self){
    return self->surname;
}

char * Director_birthdate_get(direct * self){
    return self->birthdate;
}

char * Director_company_get(direct * self){
    return self->company;
}

char * Director_name_com_get(direct * self){
    return self->name_com;
}

char * Director_specialization_get(direct * self){
  return  self->specialization;
}

int Director_year_get(direct * self){
    return self->year;
}

double Director_rating_get(direct * self){
    return self->rating;
}

void Director_print(direct * self){
    printf("name: %s\n", Director_name_get(self));
    printf("surname: %s\n", Director_surname_get(self));
    printf("birthdate: %s\n", Director_birthdate_get(self));
    printf("company: %s\n", Director_company_get(self));
    printf("    name_com: %s\n", Director_name_com_get(self));
    printf("    specialization: %s\n", Director_specialization_get(self));
    printf("year: %i\n", Director_year_get(self));
    printf("rating: %f\n", Director_rating_get(self));
}

