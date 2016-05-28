#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include "socket.h"
#include "http.h"
#include "json.h"
#include "db_manager.h"
#define MAXBUFLEN 1000
#define NO_FLAGS_SET 0
#define PORT 80
int http_getPath(const char * const request, char * pathBuf, int maxPathBuf);
void server_homepage(socket_t * client);
void server_notFound(socket_t * client);
http_request_t http_request_parse(const char * const request);

void server_database(socket_t * client);

int main() {
    lib_init();
    socket_t * server = socket_new();
    socket_bind(server, 5000);
    socket_listen(server);
	
   char buf[10000];
    char pathBuf[256];
    socket_t * client = NULL;

    while(1) {
		client = socket_accept(server);
        socket_read(client, buf, sizeof(buf));
		if (strlen(buf) == 0)
			continue;
        printf(">> Got request:\n%s\n", buf);

        http_getPath(buf, pathBuf, sizeof(pathBuf));

        http_request_t request = http_request_parse(buf);

        if (strcmp(request.uri, "/") == 0) {
            server_homepage(client);
        } else if (strcmp(request.uri, "/students") == 0) {
            server_students(client, &request);
        } else if (strcmp(request.uri, "/info") == 0) {
			server_info(client);
		} else if (strcmp(request.uri, "/database") == 0) {
			server_database(client);
		} else if (strcmp(request.uri, "/dir"))
		{
			server_dir(client, &request);
		}
		else {
            server_notFound(client);
        }
		socket_free(client);
    }
    socket_free(server);
    lib_free();
    return 0;
}

int http_getPath(const char * const request, char * pathBuf, int maxPathBuf) {
    
    char method[8];
    ptrdiff_t methodLen = strstr(request, " ") - request;
    memcpy(method, request, methodLen);
    method[methodLen] = '\0';
   
    const char * uriStartPtr = request + strlen(method) + 1;
    const char * uriEndPtr = strstr(uriStartPtr, " ");
    ptrdiff_t uriLen = uriEndPtr - uriStartPtr;
    memcpy(pathBuf, uriStartPtr, uriLen);
    pathBuf[uriLen] = '\0';
    return uriLen;
}

void server_homepage(socket_t * client) {
    const char pageText[1024] = "<!DOCTYPE html> <html> <head> <title>Director</title> </head> </body> </html>";
    char homeBuf[1024];
    sprintf(homeBuf,
        "HTTP/1.1 200 OK\n"
        "Content-Type: text/html\n"
        "Content-Length: %u\n"
        "\n%s", strlen(pageText), pageText);
    socket_write_string(client, homeBuf);
    socket_close(client);
}

void server_notFound(socket_t * client) {
    char homeBuf[1024];
	
    const char * pageText = "404 Page Not Found!";
    sprintf(homeBuf,
        "HTTP/1.1 404 \n"
        "Content-Type: text/html\n"
        "Content-Length: %u\n"
        "\n%s", strlen(pageText), pageText);
    socket_write_string(client, homeBuf);
    socket_close(client);
}

http_request_t
http_request_parse(const char * const request) {
    http_request_t req;
   
    ptrdiff_t methodLen = strstr(request, " ") - request;
    memcpy(req.method, request, methodLen);
    req.method[methodLen] = '\0';
    
    const char * uriStartPtr = request + strlen(req.method) + 1;
    const char * uriEndPtr = strstr(uriStartPtr, " ");
    ptrdiff_t uriLen = uriEndPtr - uriStartPtr;
    memcpy(req.uri, uriStartPtr, uriLen);
    req.uri[uriLen] = '\0';
    return req;
}



void server_database(socket_t * client) {
	char strbuf[10240] = "";
	char buf[1000];
	
	db_t * db = db_new("director.db");
	list_t list = database_to_list(db);
	puts(((struct admin_s *)list_get(list, 0))->name);
	char * text = list_to_xml1(list);
	sprintf(strbuf,
		"HTTP/1.1 200 OK\n"
		"Content-Type: text/xml\n"
		"Content-Length: %u\n"
		"Connection: keep-alive\n"
		"\n%s", strlen(text), text);
	
	free (text);
	
    socket_write_string(client, strbuf);
    socket_close(client);
}

