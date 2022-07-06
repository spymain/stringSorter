#include <stdio.h>
#include "llist.h"
#include "io.h"
#include "merge.h"

//#define BUFF_SIZE 32

void help();

int main(void){
    char buff[BUFF_SIZE];

    struct list* tmp = makeList();
    /*
    while(1){
        prompt("Bruh: ", buff, BUFF_SIZE);
        if (buff[0] == '/') break;
        addNodeEnd(buff, BUFF_SIZE, tmp);
        printList(tmp);
    }
    //*/


    
    //*
    int run = 1;
    help();
    while(run){
        prompt("Command: ", buff, BUFF_SIZE);
        switch(buff[0]){
            case '1':
                printf("Enter '/' to return.\n");
                while(1){
                    prompt("New Title: ", buff, BUFF_SIZE);
                    if (buff[0] == '/') break;
                    addNodeEnd(buff, BUFF_SIZE, tmp);
                    printList(tmp);
                }
                break;
            case '2':
                if(listLen(tmp) < 1){
                    printf("No nodes to delete.\n");
                    break;
                }
                int del;
                while(1){
                    del = promptNum("Delete: ", listLen(tmp), BUFF_SIZE);
                    delNode(getNode(del, tmp));
                    printList(tmp);
                    prompt("Delete more? (y/n): ", buff, BUFF_SIZE);
                    if(buff[0] != 'y') break;
                }
                break;
            case '3':
                mergeSort(tmp, choose);
                printList(tmp);
                break;
            case '4':
                prompt("Are you sure? (y/n): ", buff, BUFF_SIZE);
                if(buff[0] == 'y') run = 0;
                break;
            default:
                help();
            //break;
        }
    }
    //*/
    delList(tmp);
    return 0;
}

void help(){
    printf("1. Add Titles\n2. Delete Title\n3. Sort\n4. End\n");
}