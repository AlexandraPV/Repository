//
//  Director.h
//  lab_2_4
//
//  Created by Alexandra on 28.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//



typedef struct Director direct;

direct * Director_new(void);
void Director_free(direct * self);
void Director_print(direct * self);

void Director_set(direct * self, char * name, char * surname, char * birthdate, char * company,char * name_com, char * specialization, int year,double rating);

char * Director_name_get(direct * self);
char * Director_surname_get(direct * self);
char * Director_birthdate_get(direct * self);
char * Director_company_get(direct * self);
char * Director_name_com_get(direct * self);
char * Director_specialization_get(direct * self);
int Director_year_get(direct * self);
double Director_rating_get(direct * self);
