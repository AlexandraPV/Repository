#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h> //  ptrdiff_t
#include <ctype.h>

#include "server.h"
#include "socket.h"


void server_sent(socket_t* clientSocket, char* text)
{
    char buf[10000];
    sprintf(buf,"\nHTTP1.1 200 OK\n"
            "Content-Type: application/json\n"
            "Content-Length: %i\r\n\r\n"
            "%s\n",strlen(text),text);
    socket_write_string(clientSocket,buf);
}

