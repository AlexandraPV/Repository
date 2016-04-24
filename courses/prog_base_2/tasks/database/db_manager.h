#include "director.h"
#include <sqlite3.h>

typedef struct db_s db_t;

db_t * db_new(const char * dbFile);
void db_free(db_t * self);
void table_field(sqlite3_stmt * stmt, director_t *director);
int db_insertDirector(db_t * self, director_t * director);
director_t * db_getDirectorById(db_t * self, int id);
void db_updateDirector(db_t * self, director_t * director, int id);
void db_deleteDirectorById(db_t * self, int id);
int db_countDirectors(db_t * self);
int db_filterDirectors(db_t * self, int K, double P, director_t * director, int size);

