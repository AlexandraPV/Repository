#include "director.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <time.h>

#include <libxml/tree.h>

DIRECTOR *director_new(void)
{
    DIRECTOR *director = (DIRECTOR *)malloc(sizeof(DIRECTOR));
    strcpy(director->name, "");
    strcpy(director->surname, "");
    memset(&director->birthDate, 0, sizeof(director->birthDate));
    strcpy(director->company.name, "");
    strcpy(director->company.specialization, "");
    director->year = 0;
    director->rating = 0;
    return (director);
}

void director_delete(DIRECTOR *director)
{
    free(director);
}

COMPANY *company_new(void)
{
    COMPANY *company = (COMPANY *)malloc(sizeof(COMPANY));
    strcpy(company->name, "");
    strcpy(company->specialization, "");
        return (company);
}

void company_delete(COMPANY *company)
{
    free(company);
}


static void companyXML(COMPANY *company, xmlNode * a_node)
{
    char * data;
    for(a_node = a_node->children; a_node != NULL; a_node = a_node->next)
    {

        if(!xmlStrcmp(a_node->name, (const xmlChar *)"name"))
        {
            data = (char *)xmlNodeGetContent(a_node);
            strcpy(company->name, data);
            continue;
        }

        if(!xmlStrcmp(a_node->name, (const xmlChar *)"specialization"))
        {
            data = (char *)xmlNodeGetContent(a_node);
            strcpy(company->specialization, data);
            continue;
        }
    }
}

static DIRECTOR *directorXML(DIRECTOR *director, xmlNode * a_node)
{
    char *data;
    char *elem;


    elem = (char *) xmlGetProp(a_node, (const xmlChar *)"name");
     strcpy(director->name, elem);

    elem = (char *)xmlGetProp(a_node, (const xmlChar *)"surname");
    strcpy(director->surname, elem);
    for(a_node = a_node->children; a_node != NULL; a_node = a_node->next)
    {

        if(!xmlStrcmp(a_node->name, (const xmlChar *)"birthdate"))
        {
            data = (char *)xmlNodeGetContent(a_node);
            sscanf(data, "%d-%d-%d",
                   &director->birthDate.tm_year,
                   &director->birthDate.tm_mday,
                   &director->birthDate.tm_mon);
            continue;
        }


        if(!xmlStrcmp(a_node->name, (xmlChar *)"company"))
        {

            companyXML(&(director->company), a_node);
            continue;
        }

        if(!xmlStrcmp(a_node->name, (const xmlChar *)"year"))
        {
            data = (char *)xmlNodeGetContent(a_node);
            director->year = atoi(data);
            continue;
        }

        if(!xmlStrcmp(a_node->name, (const xmlChar *)"rating"))
        {
            data = (char *)xmlNodeGetContent(a_node);
            director->rating = atof(data);
            continue;
        }
    }
    return (director);
}


void docXML(DIRECTOR **directors, const char * name_of_file)
{
    xmlDoc * doc = xmlReadFile(name_of_file, "UTF-8", 0);
    if(doc == NULL)
    {
        xmlFreeDoc(doc);
        return;
    }
    xmlNode *xml_root = xmlDocGetRootElement(doc);
    xmlNode *a_node;
    int i;
    for(i = 0, a_node = xml_root->children; a_node != NULL; a_node = a_node->next)
    {
        if(!xmlStrcmp(a_node->name, (const xmlChar *)"director"))
        {
            directorXML(directors[i++], a_node);
        }
    }
    xmlFreeDoc(doc);
}

void print_director(DIRECTOR *director)
{
    printf("\t[%s]\n", director->name);
    printf("\t[%s]\n", director->surname);
    printf("\t%d-%d-%d\n", director->birthDate.tm_year, director->birthDate.tm_mon, director->birthDate.tm_mday);
    printf("\t[%s]\n", director->company.name);
    printf("\t[%s]\n", director->company.specialization);
    printf("\t%i\n", director->year);
    printf("\t%f\n", director->rating);

}
