//
//  system.h
//  Kr_kr
//
//  Created by Alexandra on 21.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//



#include <stdio.h>

typedef struct system_s system_t;
typedef struct folder_s folder_t;
typedef struct file_s file_t;

system_t *new_system();
void system_free(system_t * self);

folder_t * new_folder(char * new_name);
void fold_free(folder_t *fold);


file_t * new_file(char * new_name, int fsize, char * cont);
void file_free(file_t * fil);

void addFolder_to_Folder(folder_t * genFold, folder_t * newFolder);
void addFile_to_Folder(folder_t * genFold, file_t * newFile);

char * getNameFolder(system_t * self, int fold_num);
char * getNameFile(folder_t * fold, int file_num);

void renameFolder(folder_t * fold, char * new_name);
void renameFile(file_t * fil, char * new_name);

void changeContenseFile( file_t * fil, char * new_cont);
void printContensefile(file_t * fil);

void changeSitFile(file_t * fil, folder_t * new_fold);

int count_file(folder_t * fold);

int sizeOfFile(file_t * fil);

int sizeALLfolder(folder_t * fold);