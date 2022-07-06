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
    while(atoi(buff) > bound || atoi(buff) < 0){
        printf("Out of Bounds.\nTry again: ");
        fgets(buff, len - 1, stdin);
    }
    return atoi(buff);
}

int promptNum(char* prompt, int bound, int len){
    printf("%s", prompt);
    return getNum(bound, len);
}

int choose(char* a, char* b){
    int choice;
    do {
        printf("\n1. %s\nor\n2. %s\n\n", a, b);
        choice = getNum(2, BUFF_SIZE);
    } while(choice != 1 && choice != 2);
    return choice;
}