#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRINGLENGTH 254

typedef struct dictionary{
    int index;
    char info[STRINGLENGTH];
struct dictionary *next;
}DIC;

void initDictionary();

void compress();

void updateDictionary(char caracter[]);

int existInDictionary(char caracter[]);


#endif // MAIN_H_INCLUDED
