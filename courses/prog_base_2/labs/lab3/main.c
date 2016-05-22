#include <stdio.h>
#include "Header.h"
#include "myconio.h"
void user1call(int val)
{
    printf("at %i\n", val);
}

void user2call(int val)
{
    printf("off\n");
}

int main(){
    seismograph_t *seism = seismograph_new();
    user_t *us1 = user_new("USER1", 0);
    user_t *us2 = user_new("USER2", 1);
    
    user_subscribe_1(us1, user1call, seism);
    user_subscribe_2(us2, user2call, seism);
    
    
    for(int i=0; ; i++){
        if (i % 50 == 0)
            {
                seismograph_status(seism);
            }
        seism_check(seism);
        Sleep(50);
    }
  
    
    return 0;
}
