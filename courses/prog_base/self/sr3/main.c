#include <stdio.h>
#include <stdlib.h>
int ChangeV ( int mas[], int size);
int Vkaz (int mas[], int size);
int Function (int mas[], int size);
int main(){
    int i;
    printf("size of mas = ");
    int size;
    scanf("%d", &size);
    int mas[size];
    for (int j=0; j<size; j++){
        mas[j] = rand()%100 + 99;
        printf("%d ", mas[j]);}
    printf("\n");
    
    
    ChangeV(mas, size);
    for (i=0; i<size; i++) {
        printf("%d ", mas[i]);
    }
    printf("\nptr= %d\n",Vkaz(mas, size) );
    Function(mas, size);
    for (i=0; i<size; i++)
        printf("%d ", mas[i]);
    printf("\n");
    
    return 0;
}


int ChangeV ( int mas[], int size){
    mas[0]=-1;
    mas[size-1]=-1;
    return 0;
}

int Vkaz (int mas[], int size){
    int *ptr;
    ptr = & mas[size-2];
    return *ptr;
}


int Function (int mas[], int size){
  int  N= Vkaz(mas, size);
    int j=0;
    int mas2[size];
    
    for (int i=0; i<size-1; i++)
    {
        mas2[j]=mas[i];
        j++;
    }
    for (int i=0; i<size; i++)
        mas[i]=mas2[i];
    return 0;
}



