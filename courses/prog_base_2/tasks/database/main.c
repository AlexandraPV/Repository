#include <stdio.h>
#include <stdlib.h>

#include "director.h"
#include "db_manager.h"

#define ID_DIR 3
#define MIN_BUDGET 1000
#define MAX_YERAS 6

int main()
{
    db_t * db = db_new("Director.db");
    director_t filter_dir_list[10];
    
    int dir_count = db_countDirectors(db);
    printf("Directors in database: %d", dir_count);
    printf("\n\n");
    
    
    int filt_count = db_filterDirectors(db, MIN_BUDGET, MAX_YERAS,filter_dir_list, dir_count);
    printf("Directors with more than %d budget and less than %.3d years;\n>%d",
           MIN_BUDGET, MAX_YERAS, filt_count);
    printf("\n\n");
    
    
    printf("List of directors:\n\n");
    print_AllDir(filter_dir_list, filt_count);
    printf("\n\n");
    
    
    printf("Director with id %d:\n", ID_DIR);
    director_t *dir_with_id = db_getDirectorById(db, ID_DIR);
    print_dir(dir_with_id);
    printf("\n\n");
    
    
    printf("Add new director\n");
    director_t dir_for_add1 = {0, "Alex", "Shenon", 5000, 2.0, "1995-12-27"};
    db_insertDirector(db, &dir_for_add1);
    
    printf("Add new director\n");
    director_t dir_for_add2 = {1, "Max", "Maximov", 500, 7.0, "1998-01-02"};
    db_insertDirector(db, &dir_for_add2);
    
    
    printf("Delete director \n");
    db_deleteDirectorById(db, 3);
    
   
    printf("Updating director with id 1 (See comments in main).\n");
    director_t dir_for_update = {10, "Ivan", "Ivanov", 15000, 4.0, "1976-09-23"};
    db_updateDirector(db, &dir_for_update, 1);
    printf("\n\n");
    
    return 0;
}
