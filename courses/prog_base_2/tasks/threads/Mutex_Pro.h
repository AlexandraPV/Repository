#include <pthread.h>

typedef struct {
    int *number_pointer;
    pthread_mutex_t *mutex;
} Info;
