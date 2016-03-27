#include "Randomizer.h"

#include <stdlib.h>
#include <pthread.h>

#include "Mutex_Pro.h"

void *Randomize (void *info_pointer) {
    Info info = *(Info *)info_pointer;
    
    pthread_mutex_lock(info.mutex);
    *(info.number_pointer) = (rand() % 511) - 255;
    pthread_mutex_unlock(info.mutex);
    
    return 0;
}
