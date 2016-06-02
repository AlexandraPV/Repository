#include "cJSON.h"
#include "parse.h"

void parse(direct ** dir)
{
    FILE * file = fopen("director.json", "r");
    char text[10000];
    char line[100];

    while(fgets(line, 100, file) != NULL)
    {
        strcat(text, line);
    }
    fclose(file);

    cJSON * jList = cJSON_Parse(text);
    if (!jList)
    {
        printf("Error before: [%s]\n", cJSON_GetErrorPtr());
        return;
    }

    for (int i = 0; i < cJSON_GetArraySize(jList); i++)
    {
        cJSON * jItem = cJSON_GetArrayItem(jList, i);
        char * name = cJSON_GetObjectItem(jItem, "name")->valuestring;
        char * surname = cJSON_GetObjectItem(jItem, "surname")->valuestring;
        char * birthdate = cJSON_GetObjectItem(jItem, "birthdate")->valuestring;
        char * company = cJSON_GetObjectItem(jItem, "company")->valuestring;
        char * name_com = cJSON_GetObjectItem(jItem, "name_com")->valuestring;
        char * specialization = cJSON_GetObjectItem(jItem, "specialization")->valuestring;
        int year = cJSON_GetObjectItem(jItem, "year")->valueint;
        double rating = cJSON_GetObjectItem(jItem, "rating")->valuedouble;
    

        Director_set(Director[i], name, surname, birthdate, company, name_com, specialization, year, rating);
    }
    cJSON_Delete(jList);
}
