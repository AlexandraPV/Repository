#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    int * len = NULL;
    char * str = NULL;
    int * i = NULL;
    char * s= NULL;
    char * e = NULL;
    int * sum = NULL;
    int * sv = NULL;
    int * ev = NULL;
    
    len = (int*)malloc(sizeof(int));
    str = (char *)malloc(sizeof(char)*30);
    i = (int*)malloc(sizeof(int));
    s =(char*)malloc(sizeof(char)*2);
    e=(char*)malloc(sizeof(char)*2);
    sum=(int*)malloc(sizeof(int));
    sv = (int*)malloc(sizeof(int));
    ev = (int*)malloc(sizeof(int));;

    
    if (NULL == len || NULL == str || NULL == i || NULL == s || NULL == e || NULL == sum){
        printf("Memory error");
        return 1;
    
    }
    *sum = 0;
    gets(str);
    *len = strlen(str);
    for (*i = 0; *i < *len; (*i)++){
        if (0 != isdigit(str[*i])){
           strcpy(&s[0],&str[*i]);
            s[1] = '\0';
            *sv = atoi(s);
            //printf("%s", s);
            break;
            
    }
    
        
    }
    for (*i = *len; *i > 0; (*i)--){
        if (0 != isdigit(str[*i])){
            strcpy(&e[0],&str[*i]);
            *ev = atoi(e);
            //printf("%s", e);
            break;
            
        }
    
    }
    
    *sum = (*sv)+(*ev);
    printf("%d\n", *sum);
    
    free(len);
    free(i);
    free(s);
    free(e);
    free(sum);
    free(str);
    free(ev);
    free(sv);
}
