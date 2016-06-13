//
//  db_manager.c
//  №3
//
//  Created by Alexandra on 13.06.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#include "db_manager.h"

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <sqlite3.h>

#include "db_manager.h"
#include "Student.h"


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

void table_field(sqlite3_stmt * stmt, student_t *student)
{
    
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char *name = sqlite3_column_text(stmt, 1);
    const unsigned char *surname = sqlite3_column_text(stmt, 2);
     const unsigned char *fathername = sqlite3_column_text(stmt, 3);
     const unsigned char *birthDate = sqlite3_column_text(stmt, 4);
     const unsigned char *placeOFbirth = sqlite3_column_text(stmt, 5);
    int booknum = sqlite3_column_int(stmt, 6);
   
   
    
    student->id = id;
    strcpy(student->name, (char *)name);
    strcpy(student->surname, (char *)surname);
    strcpy(student->fathername, (char *)fathername);
    strcpy(student->birthDate, (char *)birthDate);
    strcpy(student->placeOFbirth, (char *)placeOFbirth);
    student->booknum = booknum;
   
}



int db_insertStudent(db_t * self, student_t * student)
{
    int newdirectorId = -1;
    sqlite3_stmt * stmt = NULL;
    int rc = 0;
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Directors  (Name, Surname, Fathername, BirthDate, PlaceOFbirth, Booknum ) VALUES (?,?,?, ?, ?, ?);", -1, &stmt, NULL)) {
        printf("Not prepared!\n");
    }
    sqlite3_bind_text(stmt, 1,student->name,strlen(student->name),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2,student->surname,strlen(student->surname),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3,student->fathername,strlen(student->fathername),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4,student->birthDate,strlen(student->birthDate),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5,student->placeOFbirth,strlen(student->placeOFbirth),SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt,6,student->booknum);
   
    
    
    
    if (SQLITE_DONE != (rc = sqlite3_step(stmt))) {
        printf("Not inserted! %i\n", rc);
    }
    newdirectorId = (int) sqlite3_last_insert_rowid (self->db);
    sqlite3_finalize(stmt);
    return newdirectorId;
}


student_t * db_getStudentById(db_t * self, int id)
{
    student_t *student = (student_t *)malloc(sizeof(struct student_s));
    sqlite3_stmt * stmt = NULL;
    const char *sqlGetCommand = "SELECT * FROM Director WHERE Id=?;";
    int rc = 0;
    
    
    sqlite3_prepare_v2(self->db, sqlGetCommand, strlen(sqlGetCommand) + 1, &stmt, NULL);
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Students  (Name, Surname, Fathername, BirthData,PlaceOFbirth, Booknum ) VALUES (?,?,?, ?, ?, ?);", -1, &stmt, NULL)) {
        printf("ERROR!\n");
    }
    
    sqlite3_bind_int(stmt, 1, id);
    
    rc = sqlite3_step(stmt);
    if(rc != SQLITE_ROW)
    {
        student->id = 0;
        strcpy(student->name, "No_Name");
        strcpy(student->surname, "No_Surname");
        strcpy(student->fathername, "No_Fathername");
        strcpy(student->birthDate, "No_Birthdate");
        strcpy(student->placeOFbirth, "No_PlaceOFbirth");
        student->booknum = 0;

        return (student);
    }
    
    student->id = id;
    strcpy(student->name, (char *)sqlite3_column_text(stmt, 1));
    strcpy(student->surname, (char *)sqlite3_column_text(stmt, 2));
    strcpy(student->fathername, (char *)sqlite3_column_text(stmt, 3));
    strcpy(student->birthDate, (char *)sqlite3_column_text(stmt, 4));
    strcpy(student->placeOFbirth, (char *)sqlite3_column_text(stmt, 5));
    student->booknum = sqlite3_column_int(stmt, 6);

    sqlite3_reset(stmt);
    return (student);
}

void db_updateStudent(db_t * self, student_t * student, int id)
{
    sqlite3_stmt *stmt = NULL;
    const char *sqlUpdateCommand = "UPDATE Director SET "
    "Name=?,"
    "Surname=?,"
    "Futhername=? "
    "Birthdate=? "
    "PlaceOFbirth=?,"
    "Booknum=?,"
    
    "WHERE Id=?;";
    int rc = 0;
    
    rc = sqlite3_prepare_v2(self->db, sqlUpdateCommand, strlen(sqlUpdateCommand) + 1, &stmt, NULL);
    
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Students  (Name, Surname,Fathername, BirthData,PlaceOFbirth, Bookname) VALUES (?,?,?, ?, ?, ?);", -1, &stmt, NULL)) {
        printf("Not updated!\n");
    }
    sqlite3_bind_text(stmt, 1, student->name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, student->surname, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, student->fathername, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, student->birthDate, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, student->placeOFbirth, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, student->booknum);
    
    sqlite3_bind_int(stmt, 6, id);
    
    sqlite3_step(stmt);
    sqlite3_reset(stmt);
}

void db_deleteStudentById(db_t * self, int id)
{
    sqlite3_stmt *stmt = NULL;
    char *sqlDeleteCommand = "DELETE FROM Student WHERE Id=?";
    
    
    sqlite3_prepare_v2(self->db, sqlDeleteCommand, strlen(sqlDeleteCommand) + 1, &stmt, NULL);
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Students  (Name, Surname,Fathername, BirthData,PlaceOFbirth, Bookname) VALUES (?,?,?, ?, ?, ?);", -1, &stmt, NULL)) {
        printf("Not delete!\n");
    }
    
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_step(stmt);
    sqlite3_reset(stmt);
}

int db_countStudents(db_t * self)
{
    int rc;
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, "SELECT COUNT(*) FROM Students;", -1, &stmt, 0);
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


int db_filterStudents(db_t * self, int K, double P, student_t * student, int size)
{
    sqlite3_stmt *stmt = NULL;
    const char *sqlCommand = "SELECT * FROM Student WHERE Budget > ? AND Years < ?;";
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