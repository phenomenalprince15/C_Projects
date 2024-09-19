#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 256


int main(int argc, char *argv[]) {

    const char filename[] = "03_pithy.txt";
    FILE *fp;
    char buffer[BSIZE];
    char *r, *entry;
    int items = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(1);
    }

    char **list_base;
    list_base = (char **)malloc(sizeof(char *) * 100);
    if (list_base == NULL) {
        fprintf(stderr, "Unable to allocate memory.\n");
        exit(1);
    }

    while (!feof(fp)) { // loop as long as file is not empty
        r = fgets(buffer, BSIZE, fp);
        if (r == NULL)
            break;
        //printf("%s", buffer);
        entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1);
        if (entry == NULL) {
            fprintf(stderr, "Unable to allocate memory.\n");
            exit(1);
        }
        strcpy(entry, buffer); // copy buffer char array to entry
        *(list_base + items) = entry; // helps store stings allocated by entry pointer
        printf("%d : %s", items, entry);
        items++;

        if (items%100) { // reallocate some memory once items is divisible by 100
            list_base = (char **)realloc(list_base,sizeof(char *)*(items+100));
			if( list_base==NULL )
			{
				fprintf(stderr,"Unable to reallocate memory\n");
				exit(1);
			}
        }
    }

    putchar('\n');
    for (int x=0; x<items; x++) {
        printf("%s", *(list_base + x));
    }

    fclose(fp);

    putchar('\n');
    srand( (unsigned)time(NULL) );
	int saying = rand() % (items-1);
	printf("%s",*(list_base+saying));

    // free memory
    for (int i=0; i<items; i++) {
        free(*(list_base+i));
    }
    free(list_base);

    return (0);
}
