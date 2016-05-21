//
//  system.h
//  system
//
//  Created by Alexandra on 21.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "list/list.h"

typedef struct system_s system_t;
typedef struct folder_s folder_t;
typedef struct file_s file_t;
typedef struct all_s all_t;

file_t * file_new (char * name_file);
void file_free(file_t *file);

system_t * system_new ();
void system_free(system_t *self);

folder_t * folder_new (char * name_folder);
void folder_free(folder_t *fold);

void system_print (system_t *self);


void folder_print (folder_t * fold);
folder_t * folder_return(system_t *self, folder_t *fold);


void system_addfolder(system_t * self, char * name);

void system_removefolder(system_t * self, char * rem_name);


void folder_addfile( folder_t * fold, char * name);
folder_t * folder_removefolder(folder_t * fold, file_t *file);
int file_return(file_t *file);
