#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "string.h"
#include "socket.h"
#include "server.h"
#include "cJSON.h"

http_request_t http_request_parse(const char * const request)
{
    http_request_t req;

    ptrdiff_t methodLen = strstr(request, " ") - request;
    memcpy(req.method, request, methodLen);
    req.method[methodLen] = '\0';

    const char * uriStartPtr = request + strlen(req.method) + 1;
    const char * uriEndPtr = strstr(uriStartPtr, " ");
    ptrdiff_t uriLen = uriEndPtr - uriStartPtr;
    memcpy(req.uri, uriStartPtr, uriLen);
    req.uri[uriLen] = '\0';

    req.form = malloc(sizeof(keyvalue_t));
    const char * bodyStartPtr = strstr(request, "\r\n\r\n") + strlen("\r\n\r\n");
    const char * cur = bodyStartPtr;
    const char * pairEndPtr = cur;
    const char * eqPtr = cur;
    while (strlen(cur) > 0)
    {
        pairEndPtr = strchr(cur, '&');
        if (NULL == pairEndPtr)
        {
            pairEndPtr = cur + strlen(cur);
        }
        keyvalue_t kv;

        eqPtr = strchr(cur, '=');
        ptrdiff_t keyLen = eqPtr - cur;
        memcpy(kv.key, cur, keyLen);
        kv.key[keyLen] = '\0';

        eqPtr++;
        ptrdiff_t valueLen = pairEndPtr - eqPtr;
        memcpy(kv.value, eqPtr, valueLen);
        kv.value[valueLen] = '\0';

        req.formLength += 1;
        req.form = realloc(req.form, sizeof(keyvalue_t) * req.formLength);
        req.form[req.formLength - 1] = kv;
        cur = pairEndPtr + ((strlen(pairEndPtr) > 0) ? 1 : 0);
    }
    return req;
}

void server_info(socket_t * clientSock)
{
    char homeBuf[10000];

    cJSON * jInfo = cJSON_CreateObject();
    cJSON_AddItemToObject(jInfo, "name", cJSON_CreateString("Olexandra"));
    cJSON_AddItemToObject(jInfo, "surname", cJSON_CreateString("Pyvovarchuk"));
    cJSON_AddItemToObject(jInfo, "group", cJSON_CreateString("KP-51"));
    cJSON_AddItemToObject(jInfo, "variant", cJSON_CreateNumber(17));
    char * pageText = cJSON_Print(jInfo);

    sprintf(homeBuf,
            "HTTP/1.1 404 \n"
            "Content-Type: text/html/application/json\n"
            "Content-Length: %zu\n"
            "\n%s", strlen(pageText), pageText);
    socket_write(client, homeBuf,sizeof(homeBuf));
}
