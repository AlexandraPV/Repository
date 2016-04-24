
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <sqlite3.h>

#include "db_manager.h"
#include "director.h"


struct db_s
{
    sqlite3 * db;
};

db_t * db_new(const char * dbFile) {
    db_t * self = malloc(sizeof(struct db_s));
    int rc = sqlite3_open(dbFile, & self->db);
    if (SQLITE_ERROR == rc) {
        printf("Can't open database\n");
        exit(1);
    }
    return self;
}

void db_free(db_t * self) {
    sqlite3_close(self->db);
    free(self);
}

void table_field(sqlite3_stmt * stmt, director_t *director)
{
    
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char *name = sqlite3_column_text(stmt, 1);
    const unsigned char *surname = sqlite3_column_text(stmt, 2);
    int budget = sqlite3_column_int(stmt, 3);
    int years = sqlite3_column_double(stmt, 4);
    const unsigned char *birthDate = sqlite3_column_text(stmt, 5);
    
    director->id = id;
    strcpy(director->name, (char *)name);
    strcpy(director->surname, (char *)surname);
    director->budget = budget;
    director->years = years;
    strcpy(director->birthDate, (char *)birthDate);
}



int db_insertDirector(db_t * self, director_t * director)
{
    int newdirectorId = -1;
    sqlite3_stmt * stmt = NULL;
    int rc = 0;
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Directors  (Name, Surname, Budget, Yers, birthData) VALUES (?,?,?, ?, ?);", -1, &stmt, NULL)) {
        printf("Not prepared!\n");
    }
    sqlite3_bind_text(stmt, 1,director->name,strlen(director->name),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2,director->surname,strlen(director->surname),SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt,3,director->budget);
    sqlite3_bind_int(stmt,4,director->years);
    sqlite3_bind_text(stmt, 5,director->birthDate,strlen(director->birthDate),SQLITE_TRANSIENT);
    
    
    if (SQLITE_DONE != (rc = sqlite3_step(stmt))) {
        printf("Not inserted! %i\n", rc);
    }
    newdirectorId = (int) sqlite3_last_insert_rowid (self->db);
    sqlite3_finalize(stmt);
    return newdirectorId;
}


director_t * db_getDirectorById(db_t * self, int id)
{
    director_t *director = (director_t *)malloc(sizeof(struct director_s));
    sqlite3_stmt * stmt = NULL;
    const char *sqlGetCommand = "SELECT * FROM Director WHERE Id=?;";
    int rc = 0;
    
   
    sqlite3_prepare_v2(self->db, sqlGetCommand, strlen(sqlGetCommand) + 1, &stmt, NULL);
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Directors  (Name, Surname, Budget, Yers, birthData) VALUES (?,?,?, ?, ?);", -1, &stmt, NULL)) {
        printf("ERROR!\n");
    }
    
    sqlite3_bind_int(stmt, 1, id);
    
    rc = sqlite3_step(stmt);
    if(rc != SQLITE_ROW)
    {
        director->id = 0;
        strcpy(director->name, "No_Name");
        strcpy(director->surname, "No_Surname");
        director->budget = 0;
        director->years = 0.0;
        strcpy(director->birthDate, "No_Birthdate");
        return (director);
    }
    
    director->id = id;
    strcpy(director->name, (char *)sqlite3_column_text(stmt, 1));
    strcpy(director->surname, (char *)sqlite3_column_text(stmt, 2));
    director->budget = sqlite3_column_int(stmt, 3);
    director->years = sqlite3_column_double(stmt, 4);
    strcpy(director->birthDate, (char *)sqlite3_column_text(stmt, 5));
    
    sqlite3_reset(stmt);
    return (director);
}

void db_updateDirector(db_t * self, director_t * director, int id)
{
    sqlite3_stmt *stmt = NULL;
    const char *sqlUpdateCommand = "UPDATE Director SET "
    "Name=?,"
    "Surname=?,"
    "Budget=?,"
    "Years=?,"
    "Birthdate=? "
    "WHERE Id=?;";
    int rc = 0;
    
    rc = sqlite3_prepare_v2(self->db, sqlUpdateCommand, strlen(sqlUpdateCommand) + 1, &stmt, NULL);
    
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Directors  (Name, Surname, Budget, Yers, birthData) VALUES (?,?,?, ?, ?);", -1, &stmt, NULL)) {
        printf("Not updated!\n");
    }
    sqlite3_bind_text(stmt, 1, director->name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, director->surname, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, director->budget);
    sqlite3_bind_double(stmt, 4, director->years);
    sqlite3_bind_text(stmt, 5, director->birthDate, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, id);
    
    sqlite3_step(stmt);
    sqlite3_reset(stmt);
}

void db_deleteDirectorById(db_t * self, int id)
{
    sqlite3_stmt *stmt = NULL;
    char *sqlDeleteCommand = "DELETE FROM Director WHERE Id=?";
    
    
    sqlite3_prepare_v2(self->db, sqlDeleteCommand, strlen(sqlDeleteCommand) + 1, &stmt, NULL);
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Directors  (Name, Surname, Budget, Yers, birthData) VALUES (?,?,?, ?, ?);", -1, &stmt, NULL)) {
        printf("Not delete!\n");
    }
    
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_step(stmt);
    sqlite3_reset(stmt);
}

int db_countDirectors(db_t * self)
{
    int rc;
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, "SELECT COUNT(*) FROM Programmers;", -1, &stmt, 0);
    rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc)
    {
        printf("Can't select count\n");
        exit(1);
    }
    int count = sqlite3_column_int(stmt,0);
    sqlite3_finalize(stmt);
    return count;
}


int db_filterDirectors(db_t * self, int K, double P, director_t * director, int size)
{
    sqlite3_stmt *stmt = NULL;
    const char *sqlCommand = "SELECT * FROM Director WHERE Budget > ? AND Years < ?;";
    int rc = 0;
    int dir_index = 0;
    
    sqlite3_prepare_v2(self->db, sqlCommand, strlen(sqlCommand) + 1, &stmt, NULL);
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Directors  (Name, Surname, Budget, Yers, birthData) VALUES (?,?,?, ?, ?);", -1, &stmt, NULL)) {
        printf("Can't select elem!\n");
    }
    sqlite3_bind_int(stmt, 1, K);
    sqlite3_bind_double(stmt, 2, P);
    
    while(1)
    {
        int returnCode = sqlite3_step(stmt);
        
        if(returnCode == SQLITE_ERROR)
        {
            printf("Can`t select directors\n");
            exit(1);
        }
        if(SQLITE_DONE == returnCode)
        {

            break;
        }
        else
        {
            table_field(stmt, &director[dir_index]);
            dir_index++;
        }
    }
    rc = sqlite3_finalize(stmt);
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Directors  (Name, Surname, Budget, Yers, birthData) VALUES (?,?,?, ?, ?);", -1, &stmt, NULL)) {
        printf("ERROR\n");
    }
    return (dir_index);
}
