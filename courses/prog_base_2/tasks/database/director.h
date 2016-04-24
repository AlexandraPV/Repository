typedef struct director_s
{
    int id;
    char name[20];
    char surname[20];
    int budget;
    double years;
    char birthDate[50];
} director_t;

void print_dir(const director_t *director);
void print_AllDir(director_t *director, int size);
