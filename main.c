#include <stdio.h>
#include "llist.h"
#include "io.h"
#include "merge.h"
#include "file.h"

//#define BUFF_SIZE 32

char* helps[] = {
    "1. Manipulate List\n2. Arrange List\n3. File I/O\n4. End\n",
    "1. Add Titles\n2. Delete Title\n3. Clear Titles\n4. Back\n",
    "1. Alphabetize\n2. Sort\n3. Back\n",
    "1. New from File\n2. Append from file\n3. Back\n"
};

void help(int menu);

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
    int choice;

    int menu = 0;
    int dispMenu = 1;
    while(run){
        if(menu != dispMenu) {help(menu); dispMenu = menu;}
        choice = promptNum("Command: ", 4, BUFF_SIZE);
        switch(menu){
            case 0://Main Menu
                switch(choice){
                    case 1://Manipulate List
                    case 2://Arrange List
                    case 3://File I/O
                        menu = choice;
                        break;
                    case 4://End
                        prompt("Are you sure? (y/n): ", buff, BUFF_SIZE);
                        if(buff[0] == 'y') run = 0;
                        break;
                    default:
                        help(menu);
                    //break;
                }
                break;
            case 1://Manipulate List
                switch(choice){
                    case 1://Add
                        printf("Enter '/' to return.\n");
                        while(1){
                            prompt("New Title: ", buff, BUFF_SIZE);
                            if (buff[0] == '/') break;
                            addNodeEnd(buff, BUFF_SIZE, tmp);
                            printList(tmp);
                        }
                        break;
                    case 2://Delete
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
                    case 3://Clear
                        break;
                    case 4://Back
                        menu = 0;
                        break;
                    default:
                        help(menu);
                    //break;
                }
                break;
            case 2://Arrange List
                switch(choice){
                    case 1://Alphabetize
                        mergeSort(tmp, alph);
                        printList(tmp);
                        break;
                    case 2://Sort
                        mergeSort(tmp, choose);
                        printList(tmp);
                        break;
                    case 3://Back
                        menu = 0;
                        break;
                    default:
                        help(menu);
                    //break;
                }
                break;
            case 3://File I/0
                switch(choice){
                    case 1://New
                        break;
                    case 2://Append
                        break;
                    case 3://Back
                        menu = 0;
                        break;
                    default:
                        help(menu);
                    //break;
                }
                break;
            //
        }
    }
    //*/
    delList(tmp);
    return 0;
}

void help(int menu){
    //printf("1. Add Titles\n2. Delete Title\n3. Alphabetize\n4. Sort\n5. End\n");
    printf("%s", helps[menu]);
}