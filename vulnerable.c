/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bof(char *str)
{
    char buffer[12];

    /* The following statement has a buffer overflow problem */ 
    strcpy(buffer, str);

    return 1;
}

int main(int argc, char **argv)
{
    char str[517];
    FILE *badfile;
    size_t res;

    badfile = fopen("badfile", "r");
    if(badfile == NULL){
      perror("Impossible to open badfile");
      exit(-1);
    }
    res = fread(str, sizeof(char), 517, badfile);
    if(res == 0 && ferror(badfile)){
      perror("Error while reading file");
      exit(-1);
    }
    if(res < 517){
      fprintf(stderr, "Impossible to read enough data. Only %d bytes read.\n", res);
      exit(-1);
    }
    bof(str);
    printf("Returned Properly\n");
    return 1;
}
