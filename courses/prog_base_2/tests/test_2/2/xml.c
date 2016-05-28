
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "list.h"
#include "db_manager.h"




char * list_to_xml1(list_t list) {
    xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	xmlNode * studentNode = NULL;
	xmlNode * groupNode = NULL;
	char strBuf[100];
	char * text = malloc(sizeof (char) * 10000);
	doc = xmlNewDoc("1.0");
	rootNode = xmlNewNode(NULL, "directors");

	for (int i = 0;i < list_size(list); i++)
	{
		if (list_get(list, i) == NULL)
			continue;
		puts(((struct admin_s *)list_get(list, i))->name);
		xmlDocSetRootElement(doc, rootNode);
		studentNode = xmlNewChild(rootNode, NULL, "director", NULL);
		xmlNewChild(studentNode, NULL, "name", ((struct admin_s *)list_get(list, i))->name);
		xmlNewChild(studentNode, NULL, "surname", ((struct admin_s *)list_get(list, i))->surname);
		sprintf(strBuf, "%i", ((struct admin_s *)list_get(list, i))->buget);
		xmlNewChild(studentNode, NULL, "buget", strBuf);
		sprintf(strBuf, "%llf", ((struct admin_s *)list_get(list, i))->years);
		xmlNewChild(studentNode, NULL, "years", strBuf);
		xmlNewChild(studentNode, NULL, "birthdate", ((struct admin_s *)list_get(list, i))->birthdate);
	}
	xmlBuffer * bufferPtr = xmlBufferCreate();
		xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
		printf("%s", (const char *)bufferPtr->content);
    
		strcpy(text, (const char *)bufferPtr->content);
		xmlBufferFree(bufferPtr);
      xmlFreeDoc(doc);
	xmlCleanupParser();
	return text;
}
