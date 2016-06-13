//
//  task_1.c
//  №1
//
//  Created by Alexandra on 13.06.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#include "task_1.h"
#include <string.h>

int findString( char * text,  char * add){
    
    if(strlen(text) > strlen(add))
        return 0;
    
    int func = 0;
    int length = 0;
    
    for(int i = 0; i < strlen(add); i++){
        
        if(add[i] == '\n')
            continue;
        
        if(text[length] == add[i] && func == 0 ){
            if(length == strlen(text) - 1){
                return 0;
            }
            else
            {
                func = 1;
                length++;
            }
        }
        else if(text[length] == add[i] && func == 1){
            if(length == strlen(text) - 1){
                return 1;
            }
            else {
                length++;
            }
        }
        else if(text[length] != add[i]){
            func = 0;
            length = 0;
        }
    }
    return 0;
}