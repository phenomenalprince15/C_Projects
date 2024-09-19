#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BSIZE 256

int main(int argc, char *argv[]) {

    const char filename[] = "03_pithy.txt"; // in same directory
    FILE *fp;
    char buffer[BSIZE];
    char *r;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(1);
    }

    while (!feof(fp)) { // loop as long as file is not empty
        r = fgets(buffer, BSIZE, fp);
        if (r == NULL)
            break;
        printf("%s", buffer);
    }
    fclose(fp);

    return (0);
}

