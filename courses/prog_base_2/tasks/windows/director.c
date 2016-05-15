#include "director.h"


char * randName(){
    static char * Names[] = {"Ivan", "Max", "Jon","Vlad","David", "Ken"};
    char * name = Names[rand()%6];
    return name;
}

char * randSurname(){
    static char * Surnames[] = {"Ivanov", "Maximov", "Shenon","Kozlov","Tkachuk", "Black"};
    return Surnames[rand()%6];
}


char * randBudget(){
    static char * Budget[] = {"2000", "15000", "3000","10000", "7000"};
    return Budget[rand()%5];
}

char * randYears(){
    static char * Years[] = {"1", "1.5", "2","3", "4.5"};
    return Years[rand()%5];
}


char * randBirthDate(){
    static char * Birthday[] = {"30-12-1978", "21-11-1965", "19-07-1985","06-04-1986","04-05-1977"};
    return Birthday[rand()%5];
}
