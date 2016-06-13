
#ifndef db_manager_h
#define db_manager_h

#include <stdio.h>


#include "Student.h"
#include <sqlite3.h>

typedef struct db_s db_t;

db_t * db_new(const char * dbFile);
void db_free(db_t * self);
void table_field(sqlite3_stmt * stmt, student_t *student);
int db_insertStudent(db_t * self, student_t * student);
student_t * db_getStudentById(db_t * self, int id);
void db_updateStudent(db_t * self, student_t * student, int id);
void db_deleteStudentById(db_t * self, int id);
int db_countStudents(db_t * self);
int db_filterStudents(db_t * self, int K, double P, student_t * student, int size);

#endif /* db_manager_h */
