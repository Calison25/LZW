#include "main.h"


DIC *dictionary,*begin,*aux,*end = NULL;

void main()
{
    //initDictionary();

    compress();

    aux = begin;
    while ( aux != NULL){
          printf("\n\tIndex =>%d    Info=>%s\n",aux->index,aux->info);
          aux = aux->next;
    }
}

void compress()
{
    char previously[STRINGLENGTH];
    char sum[STRINGLENGTH];
    char str[STRINGLENGTH];
    char temp[STRINGLENGTH];
    int sizeOfString,i = 0;
    strcpy(str,"wabbawabba");
    strcpy(previously,"");
    strcpy(sum,"");
    strcpy(temp,"");

    sizeOfString = strlen(str);
    for(i=0;i<sizeOfString;i++){
       temp[0] = str[i];
       strcat(sum,strcat(previously,temp));
       if((existInDictionary(sum))){
            strcpy(previously,sum);
       }else{
            updateDictionary(sum);
            strcpy(previously,"");
            strcpy(previously,temp);
       }
       strcpy(sum,"");
    }
}

void updateDictionary(char caracter[])
{
   DIC *temp = NULL;
   temp = end;

   if ( (dictionary = (DIC*)malloc(sizeof(DIC)))!=NULL){
        if(begin == NULL){
            dictionary->index = 1;
            strcpy(dictionary->info,caracter);
            dictionary->next = NULL;
            temp = dictionary;
            begin = dictionary;
            end = dictionary;
        }else{
            dictionary->index = temp->index + 1;
            strcpy(dictionary->info,caracter);
            temp->next = dictionary;
            dictionary->next = NULL;
            end = dictionary;
        }
   }
}

int existInDictionary(char caracter[])
{
    DIC *temp;

    temp = begin;
    while ( temp != NULL){
          if( (strcmp(temp->info,caracter) == 0) ){
            return 1;
          }
          temp = temp->next;
    }
    return 0;
}

void initDictionary()
{
    //Carregar do arquivo
}
