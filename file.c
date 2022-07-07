#include <stdio.h>
#include <string.h>
#include "io.h"
#include "llist.h"

int fileApnd(char* filename, struct list* l){
    char buff[BUFF_SIZE];
    FILE* fp = fopen(filename, "r");
    if (!fp) {fclose(fp); return 0;}
    while(1){
        fgets(buff, BUFF_SIZE - 1, fp);
        if(feof(fp)) break;
        if(buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        addNodeEnd(buff, BUFF_SIZE, l);
    }
    fclose(fp);
    return 1;
}

int printFile(char* filename, struct list* l){
    FILE* fp = fopen(filename, "w+");
    if (!fp) {fclose(fp); return 0;}
    struct node* head = l -> first;
    while(head){
        fputs(head -> data, fp);
        fputc('\n', fp);
        head = head -> next;
    }
    fclose(fp);
    return 1;
}