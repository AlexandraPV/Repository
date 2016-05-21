//
//  system.c
//  system
//
//  Created by Alexandra on 21.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#include "system.h"

#include "list.h"
#define MAX_COUNT 10


struct system_s{
    int folder_count;
    list_t *folder;
    //folder_s * folder[MAX_COUNT];
};

struct folder_s {
    int file_count;
    // list_t *elem;
    list_t *file;
    list_t *folder;
    int fold_count;
    int size_fold;
    //file_s * file[MAX_COUNT];
    char * folder_name;
};

struct file_s{
    int size;
    char * file_name;
    char * contains;
};

system_t *new_system(){
    system_t * self = malloc(sizeof(system_t));
    self->folder_count=0;
    self->folder= list_new();
    return self;
    
}

void system_free(system_t * self){
    free(self);
}

folder_t * new_folder(char * new_name){
    folder_t * fold = malloc(sizeof(folder_t));
    fold->file=list_new();
    fold->file_count=0;
    fold->folder=list_new();
    fold->folder_name= new_name;
    fold->fold_count=0;
    fold->size_fold=0;
    return fold;
}
void fold_free(folder_t *fold){
    free(fold);
}


file_t * new_file(char * new_name, int fsize, char * cont){
    file_t * fil=malloc(sizeof(file_t));
    fil->file_name = new_name;
    fil->size = fsize;
    fil->contains = cont;
    return fil;
}
void file_free(file_t * fil){
    free(fil);
}

void addFolder_to_Folder(folder_t * genFold, folder_t * newFolder){
    list_push_back(genFold, newFolder);
    genFold->fold_count++;
    genFold->size_fold= genFold->size_fold+ newFolder->size_fold;
}
void addFile_to_Folder(folder_t * genFold, file_t * newFile){
    list_push_back(genFold, newFile);
    genFold->file_count++;
    genFold->size_fold= genFold->size_fold+ newFile->size;
}

char * getNameFolder(system_t * self, int fold_num){
    folder_t * fold = list_get(self->folder, fold_num);
    return fold->folder_name;
}
char * getNameFile(folder_t * fold, int file_num){
    file_t * file = list_get(fold->file, file_num);
    return file->file_name;
}

void renameFolder(folder_t * fold, char * new_name){
    fold->folder_name= new_name;
}
void renameFile(file_t * fil, char * new_name){
    fil->file_name=new_name;
}

void changeContenseFile( file_t * fil, char * new_cont){
    fil->contains=new_cont;
}
void printContensefile(file_t * fil){
    char * cont = fil->contains;
    printf("%s", cont);
}

void changeSitFile(file_t * fil, folder_t * new_fold){
    list_push_back(new_fold, fil);
    list_pop_back(fil);
}

int count_file(folder_t * fold){
    return fold->file_count;
}

int sizeOfFile(file_t * fil){
    return fil->size;
}

int sizeALLfolder(folder_t * fold){
    int All_fil =0 ;
    All_fil= All_fil + fold->size_fold;
    return All_fil;
}