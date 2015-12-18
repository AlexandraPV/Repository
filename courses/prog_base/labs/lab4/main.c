#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ShowCommands (){
  const char *command[]= {" ",
    "List of commands:",
    "1-playlists - ",
    "2-show playlist ",
    "3-show composition ",
    "4-create composition ",
    "5-delete composition ",
    "6-create playlist",
    "7-delete playlist",
    "8-rename composition",
    "9-rename playlist",
    "10-exit",
    "11-help"};
    for(int i=0; i<13; i++)
        printf("%s\n", command[i]);
}

void ShowNotes (){
    const char *notes[]= {" ",
        "List of notes:",
        "0-do",
        "1-re",
        "2-mi",
        "3-fa",
        "4-sol",
        "5-la",
        "6-si"};
    for(int i=0; i<9; i++)
        printf("%s\n", notes[i]);
}

typedef struct {
    int number;
    char *name;
} Note;

typedef struct {
    int noteQ;
    char *name;
    Note **notes;
}Composition;

typedef struct {
    int composQ;
    char *name;
    Composition **compositions;
}Playlist;

typedef struct {
    Playlist **playlists;
    int playlistQ;
    Composition **compositions;
    int composQ;
    Note **notes;
    int noteQ;
}All;

Note *createNote (int number, char *name) {
    Note *note = malloc(sizeof(Note));
    note->number = number;
    note->name = name;
    //printf("%s\n", note->name);
    return note;
}

Composition *createComposition (Note **notes , int noteQ, char *name) {
    Composition *composition = malloc (sizeof(Composition));
    composition->name = name;
    composition->noteQ = noteQ;
    composition->notes = notes;
    return composition;
}

Playlist *createPlaylist ( char *name,int composQ, Composition **compositions) {
    Playlist *playlist = malloc (sizeof(Playlist));
    playlist->name = name;
    playlist->composQ = composQ;
    playlist->compositions = compositions;
    return playlist;
}

 void renameComposition ( Composition *composition, char *name) {
    composition->name = name;
}
void renamePlaylist ( Playlist *playlist, char *name) {
    playlist->name = name;
}
void deleteCompositionFromPlaylist (Composition *composition, All *all) {
    for (int i = 0; i < all->playlistQ; i++) {
        Playlist *playlist = all->playlists[i];
        for (int j = 0; j < playlist->composQ; j++) {
            if (composition == playlist->compositions[j]) {
                //free(playlist->compositions[j]);
                playlist->compositions[j] = NULL;
            }
        }
    }
}
void deleteComposition (Composition *composition, All *all) {
    for (int i = 0; i < all->composQ; i++) {
        if (composition == all->compositions[i]) {
            //free(all->compositions[i]);
            all->compositions[i] = NULL;
            break;
        }
    }
    
    deleteCompositionFromPlaylist(composition, all);
}
void deletePlaylist (Playlist *playlist, All *all) {
    for (int i = 0; i < all->playlistQ; i++) {
        if (playlist == all->playlists[i]) {
            //free(all->playlists[i]);
            all->playlists[i] = NULL;
            break;
        }
    }
}
void printPlaylist(Playlist *playlist){
    printf(" Playlist \"%s\" :", playlist->name);
    for (int i=0; i<playlist->composQ; i++){
        if (playlist->compositions[i] == NULL) {
            continue;
        }
        printf("\n%s", playlist->compositions[i]->name);
        
    }
}
void printComposition(Composition *composition){
    printf(" Composition \"%s\": ", composition->name);
    for (int i=0; i<composition->noteQ; i++){
        Note **notes = composition->notes;
        Note *note = notes[i];
        char *name = note->name;
        printf("%s ", name);
        
    }
}

void printAllCompositions(Composition **compositions, All *all){
    printf("All compositions:\n");
    for (int i=0; i<all->composQ; i++) {
        if (compositions[i] == NULL) {
            continue;
        }
        printf("%s\n",compositions[i]->name);
    }
}

void printAll(Playlist **playlists, int playlistQ ){
    printf("All playlists:\n");
    for (int i=0; i<playlistQ; i++) {
        if (playlists[i] == NULL) {
            continue;
        }
        printf("%s\n",playlists[i]->name);
    }
 
}

Note* Switch (char note){
switch (note) {
    case 0:
        return createNote(0, "do");
    case 1:
        return createNote(1, "re");
    case 2:
        return createNote(2, "mi");
    case 3:
        return createNote(3, "fa");
    case 4:
        return createNote(4, "sol");
    case 5:
        return createNote(5, "la");
    case 6:
        return createNote(6, "si");
        
    default:
        break;
  }
    return NULL;
}

Composition *findComposition (char *name, All *all){
    for (int i=0; i<all->composQ; i++){
        if (all->compositions[i] == NULL) {
            continue;
        }
        if ( !strcmp( name, all->compositions[i]->name)) {
            return all->compositions[i];
        }
    }
    return NULL;
}
Playlist *findPlaylist (char *name, All *all ){
    for (int i=0; i<all->playlistQ; i++){
        if (all->playlists[i] == NULL) {
            continue;
        }
        if ( !strcmp( name, all->playlists[i]->name))
            return all->playlists[i];
    }
    return NULL;
}


Note **createALLNOTES () {
    Note **notes = malloc(7 * sizeof(Note*));
    for (int i = 0; i < 7; i++) {
        notes[i] = Switch(i);
    }
    return notes;
}

int recalculatePlaylists (All *all) {
    int newPlaylistQ = all->playlistQ;
    for (int i=0; i < all->playlistQ; i++) {
        if (all->playlists[i] == NULL) {
            newPlaylistQ--;
        }
    }
    return newPlaylistQ;
}
int recalculateCompositions (Composition **compositions, int composQ) {
    int newComposQ = composQ;
    for (int j = 0; j < composQ; j++) {
        if (compositions[j] == NULL) {
            newComposQ--;
        }
    }
    return newComposQ;
}
void fileWrite(All *all){
    FILE * f = fopen("all.txt", "w");
    if (f==NULL){
        printf("Can not open the file\n");
        return;
    }
    //список композицій + список нот у кожній
    int newComposQ = recalculateCompositions(all->compositions, all->composQ);
    
    fprintf(f, "%d\n", newComposQ);
    for (int i=0; i<all->composQ; i++) {
        if (all->compositions[i] != NULL) {
            fprintf(f, "%s\n", all->compositions[i]->name);
            for (int j=0; j<all->compositions[i]->noteQ; j++) {
                fprintf(f, "%d", all->compositions[i]->notes[j]->number);
            }
            fprintf(f, "\n");
        }
    }
    
    //список плейлістів + список композицій у кожному
    int newPlaylistQ = recalculatePlaylists(all);
    
    fprintf(f, "%d\n",newPlaylistQ);
    for (int i=0; i<all->playlistQ; i++ ){
        if (all->playlists[i] != NULL) {
            
            int newComposQ = recalculateCompositions(all->playlists[i]->compositions, all->playlists[i]->composQ);
            
            fprintf(f, "%s\n%d\n", all->playlists[i]->name, newComposQ);
            for (int j=0; j<all->playlists[i]->composQ; j++) {
                if (all->playlists[i]->compositions[j] != NULL) {
                    fprintf(f, "%s\n", all->playlists[i]->compositions[j]->name);
                }
            }
        }
    }
    
    fclose(f);
}

void fileRead(All *all){
    FILE * f = fopen("all.txt", "r");
    if (f==NULL){
        printf("Can not open the file\n");
        return;
    }
    
    //список композицій + список нот у кожній
    fscanf(f, "%d\n", &all->composQ);
    for (int i = 0; i < all->composQ; i++) {
        char *name = malloc(100 * sizeof(char));
        fscanf(f, "%s\n", name);
        
        char *notesSTR = malloc(100 * sizeof(char));
        fscanf(f, "%s\n", notesSTR);
        
        Note **noteMas=malloc(strlen(notesSTR)*sizeof(Note*));
        for (int i=0; i<strlen(notesSTR); i++) {
            int noteIndex = notesSTR[i] - 48;
            noteMas[i] = all->notes[noteIndex];
        }
        
        Composition *composition = createComposition (noteMas, (int)strlen(notesSTR), name);
        all->compositions[i]=composition;
    }
    
    //список плейлістів + список композицій у кожному
    fscanf(f,"%d\n", &all->playlistQ);
    for (int i=0; i<all->playlistQ; i++) {
        
        char *playlistName = malloc(100*sizeof(char));
        int composQ;
        fscanf(f, "%s\n%d\n", playlistName, &composQ);
        
        Composition **compositions = malloc(composQ * sizeof(Composition *));
        
        for (int j=0; j<composQ; j++) {
            char *name = malloc(100 * sizeof(char));
            fscanf(f, "%s\n", name);
            compositions[j] = findComposition(name, all);
        }
        
        all->playlists[i] = createPlaylist(playlistName, composQ, compositions);
    }
    
    fclose(f);
}

void freeAll (All * all){
    for (int i = 0; i < all->composQ; i++) {
        free(all->compositions[i]);
    }
    for (int i = 0; i < all->playlistQ; i++) {
        free(all->playlists[i]);
    }
    
}

void Choose (int command, All *all){
    
    switch (command) {
        case 11:
            return ShowCommands ();
        
        case 1:
            return printAll( all->playlists,all->playlistQ );
       
        case 2:{
            char * name = malloc(100 * sizeof(char));
            printf("Enter the name of playlist:");
            scanf("%s", name);
            Playlist * playlist = findPlaylist (name, all);
            if (playlist!=NULL)
                printPlaylist(playlist);
            else printf("Playlist not found!");
            break;}
        
        case 3:{
            char * name = malloc(100 * sizeof(char));
            printf("Enter the name of composition:");
            scanf("%s", name);
            Composition *composition = findComposition(name, all);
            if (composition!=NULL)
                printComposition(composition);
            else printf("Composition not found");
            break;}
        
        case 4:{
            char * name = malloc(100 * sizeof(char));
            printf("Enter the name of new composition:");
            scanf("%s", name);
            Composition *composition = findComposition(name, all);
            if (composition==NULL) {
                ShowNotes ();
                printf("Enter notes of composition:");
                char * notesSTR = malloc(100 * sizeof(char));
                scanf("%s", notesSTR);
                Note **noteMas=malloc(strlen(notesSTR)*sizeof(Note*));
                for (int i=0; i<strlen(notesSTR); i++) {
                    int noteIndex = notesSTR[i] - 48;
                    if (noteIndex>6 || noteIndex<0) {
                        printf("This note not found");
                        return;
                    }
                    noteMas[i] = all->notes[noteIndex];
                }

                composition = createComposition (noteMas , (int)strlen(notesSTR), name);
                all->compositions[all->composQ]=composition;
                all->composQ++;
                printComposition(composition);
                
            }
            else printf("This composition already exists\n");
            break;}
       
        case 5:{
            char * name = malloc(100 * sizeof(char));
            printf("Enter the name of composition:");
            scanf("%s", name);
            Composition *composition=findComposition(name, all);
            if (composition!=NULL) {
                deleteComposition (composition, all);
            }
            else printf("This composition not found\n");
            break;}
        
        case 6:{
            char * name = malloc(100 * sizeof(char));
        
            printf("Enter the name of new playlist:");
            scanf("%s", name);
            Playlist *playlist = findPlaylist(name, all);
            if (playlist==NULL) {
                printf("Enter compositions of new playlist(Example: composition1/composition2):");
                char *str=malloc(100*sizeof(char));
                scanf("%s", str);
                
                char **masC=malloc(1000*sizeof(char*));
            
                char sep[] = "/";
                char *istr;
                istr = strtok (str,sep);
                int i = 0;
                while (istr != NULL)
                {
                    masC[i] = malloc(100*sizeof(char));
                    strcpy(masC[i], istr);
                    istr = strtok (NULL,sep);
                    
                    i++;
                }
                Composition **compositions = malloc(i * sizeof(Composition *));
                int j;
                for (j = 0; j < i; j++) {
                    Composition *composition = findComposition(masC[j], all);
                    if (composition != NULL)
                        compositions[j] = composition;
                    else {
                        printf("This composition not found\n");
                        break;
                    }
                }
                if (j == i) {
                    Playlist *playlist= createPlaylist (name,i, compositions);
                    all->playlists[all->playlistQ]= playlist;
                    all->playlistQ++;
                    printPlaylist(playlist);
                }
            }
            else printf("This playlist already exists\n");
            break;}
        
        case 7:{
            char * name = malloc(100 * sizeof(char));
            printf("\nEnter the name of playlist for delete:");
            scanf("%s", name);
            Playlist *playlist = findPlaylist (name, all);
            if (playlist!=NULL) {
                deletePlaylist(playlist, all);
            }
            else printf("This playlist not found\n");
            break;}
        
        case 8:{
            char * name = malloc(100 * sizeof(char));
            printf("Enter the name of composition:");
            scanf("%s", name);
            Composition *composition=findComposition(name, all);
            if (composition!=NULL) {
                char * newName = malloc(100 * sizeof(char));
                printf("Enter the new name of composition:");
                scanf("%s", newName);
                Composition *comp=findComposition(newName, all);
                if (comp==NULL) {
                    renameComposition (composition, newName);
                } else {
                    printf("This name already exists\n");
                }
            }
            else
                printf("This composition not found\n");
            break;}
        
        case 9:{
            char * name = malloc(100 * sizeof(char));
            printf("Enter the name of playlist:");
            scanf("%s", name);
            Playlist *playlist=findPlaylist(name, all);
            if (playlist!=NULL) {
                char * newName = malloc(100 * sizeof(char));
                printf("Enter the new name of playlist:");
                scanf("%s", newName);
                Playlist *pl=findPlaylist(newName, all);
                if (pl==NULL) {
                    renamePlaylist(playlist, newName);
                } else {
                    printf("This name already exists\n");
                }
            }
            else
                printf("This playlist not found\n");
            break;}
            
        case 10:{
            printf("Good bye\n");
            fileWrite(all);
            freeAll(all);
            break;
        }
        
        default: printf("Wrong command. Press 11 for help\n");
            break;
    }
}

int main(){

    // Create All All
    All *all=malloc(sizeof(All));
    all->playlists = malloc(100 * sizeof(Playlist*));
    all->playlistQ = 0;
    all->compositions = malloc(1000 * sizeof(Composition*));
    all->composQ = 0;
    all->notes = createALLNOTES();
    
    fileRead(all);
    
    
    printf("Welсome!\n");
    ShowCommands ();
    
    while (1) {
        printf("\nEnter command:");
        char *commandStr = malloc(100 * sizeof(char));
        scanf("%s", commandStr);
        int command = atoi(commandStr);
        Choose (command, all);
        if (command == 10) {
            break;
        }
    }

        return 0;
   }
