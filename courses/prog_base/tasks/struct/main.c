#include <stdio.h>
#include <string.h>


struct game {
    char name[100];
    int top;
    int released;
};

int count(int size, struct game masGame[]) {
    int i, RPG = 0;
    for (i = 0; i < size; i++) {
            RPG++;
    }
    return RPG;
}

void change(struct game *pVar, const char *newValue) {
    strcpy(pVar->name, newValue);
}

void print(struct game *pVar) {
    printf("Name of game: %s\n", (*pVar).name);
    printf("Top: %d\n", (*pVar).top);
    printf("Released: %d\n", (*pVar).released);
}

int main() {
    int i, num = 1, countV = 0, N, size = 6;
    struct game masGame [] = { {"The Last of Us", 1, 2013}, {"The Elder Scrolls V: Skyrim", 2, 2011}, {"Fallout", 3, 1997}, {"The Witcher 3: Wild Hunt", 4, 2015}, {"The Elder Scrolls V: Skyrim - Dawnguard", 5, 2012}, {"The Elder Scrolls V: Skyrim - Dragonborn", 6, 2012} };
    
    puts("");
    
    for (i = 0; i < size; i++) {
        struct game *ptr = &masGame[i];
        printf("%d.", num);
        print(ptr);
        num++;
    }
    
    puts("");
    
    countV = count(size, masGame);
    printf("Games RPG: %d\n", countV);
    
    puts("");
    
    puts(" Enter the number of game:");
    scanf("%d", &N);
    struct game *a = &masGame[N-1];
    change(a, "GAME");
    printf("\nAfter changing:\n");
    print(a);
    

    
    getchar();
    return 0;
}
