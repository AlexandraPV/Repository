#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "server.h"
#include <time.h>
#include <string.h>
#include "socket.h"

void server_info(socket_t* clientSocket)
{
    cJSON * stud = cJSON_CreateObject();
    cJSON_AddItemToObject(stud, "student", cJSON_CreateString("Pyvovarchuk Olexandra"));
    cJSON_AddItemToObject(stud, "group", cJSON_CreateString("KP-51"));
    cJSON_AddItemToObject(stud, "variant", cJSON_CreateNumber(17));
    char * jsonstud = cJSON_Print(stud);
    server_sent(clientSocket,jsonstud);
}

void server_sent(socket_t* clientSocket, char* text)
{
    char buf[10000];
    sprintf(buf,"\nHTTP1.1 200 OK\n"
            "Content-Type: application/json\n"
            "Content-Length: %i\r\n\r\n"
            "%s\n",strlen(text),text);
    socket_write_string(clientSocket,buf);
}

