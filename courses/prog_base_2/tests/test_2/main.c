#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "server.h"
#include <time.h>
#include <string.h>
#include "socket.h"

void server_info(socket_t* clientSocket)
{
    cJSON * SM = cJSON_CreateObject();
    cJSON_AddItemToObject(SM, "student:", cJSON_CreateString("Pyvovarchuk Olexandra"));
    cJSON_AddItemToObject(SM, "group:", cJSON_CreateString("KP-51"));
    cJSON_AddItemToObject(SM, "variant:", cJSON_CreateNumber(17));
    char * jsonSM = cJSON_Print(SM);
    server_sent(clientSocket,jsonSM);
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

