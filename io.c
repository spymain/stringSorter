#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

char* getIn(char* dest, int len){
    char buff[len];
    fgets(buff, len - 1, stdin);
    if(buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
    strncpy(dest, buff, strlen(buff) + 1);
    return dest;
}
char* prompt(char* prompt, char* dest, int len){
    printf("%s", prompt);
    return getIn(dest, len);
}
int getNum(int bound, int len){
    char buff[len];
    fgets(buff, len - 1, stdin);
    while(atoi(buff) > bound){
        printf("Out of Bounds.\nTry again: ");
        fgets(buff, len - 1, stdin);
    }
    return atoi(buff);
}

int promptNum(char* prompt, int bound, int len){
    printf("%s", prompt);
    return getNum(bound, len);
}