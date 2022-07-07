#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

struct list* makeList(){
    struct list* tmp = malloc(sizeof(struct list));
    tmp -> first = tmp -> last = NULL;
    return tmp;
}

struct node* makeNode(char* data, int len){
    char buff[len];
    strncpy(buff, data, len);
    //printf("Len: %li\n", strlen(buff));
    char* tmp = malloc(sizeof(char) * (strlen(buff) + 1));
    strncpy(tmp, data, strlen(buff) + 1);

    struct node* n = malloc(sizeof(struct node));
    n -> data = tmp;
    n -> prev = n -> next = NULL;
    n -> list = NULL;
    return n;
}

struct node* addNodeEnd(char* data, int len, struct list* l){
    struct node* n = makeNode(data, len);
    if(l -> last){//list with nodes
        l -> last -> next = n;
        n -> prev = l -> last;
        l -> last = n;
        n -> list = l;
    } else{//Empty List
        l -> first = l -> last = n;
        n -> list = l;
    }
    return n;
}

struct list* splitList(struct list* l){
    if(listLen(l) <= 1) return NULL;
    struct list* tmp = makeList();
    tmp -> last = l -> last;
    l -> last = getNode((listLen(l)/2 - 1), l);
    tmp -> first = l -> last -> next;
    l -> last -> next = tmp -> first -> prev = NULL;

    struct node* head = tmp -> first;
    while(head){
        head -> list = tmp;
        head = head -> next;
    }
    return tmp;
}

struct node* getNode(int indx, struct list* l){
    if(indx >= listLen(l)) return NULL;
    struct node* head = l -> first;
    for(int i=0; i < indx; i++) if(head -> next) head = head -> next;
    return head;
}

/*
void swap(struct node* a, struct node* b){
    struct node* tmp;
    if (a -> next == b || b -> next == a){//the nodes are adjacent
        //
    } else{
        tmp = b -> next;
        b -> next = a -> next;
        a -> next = tmp;
        tmp = b -> prev;
        b -> prev = a -> prev;
        a -> prev = tmp;
    }
    if(a -> next) a -> next -> prev = a;
    else a -> list -> last = a;
    if (a -> prev) a -> prev -> next = a;
    else a -> list -> first = a;
    
    if(b -> next) b -> next -> prev = b;
    else b -> list -> last = b;
    if (b -> prev) b -> prev -> next = b;
    else b -> list -> first = b;
}
//*/

void freeNode(struct node* n){
    free(n -> data);
    free(n);
}

void delNode(struct node* n){
    //fix pointers
    struct node *np = n -> prev;
    struct node *nn = n -> next;
    if(n -> next){
        n -> next -> prev = np;
        if(!(n -> prev)) n -> next -> list -> first = n -> next;
    }
    if(n -> prev){
        n -> prev -> next = nn;
        if(!(n -> next)) n -> prev -> list -> last = n -> prev;
    }
    if(!(n -> next || n -> prev)) n -> list -> first = n -> list -> last = NULL;
    //edge cases
    freeNode(n);
}

void delList(struct list* l){
    //printf("Deleting List..\n");
    if(l -> first){
        struct node* head = l -> first, *headPrev = l -> first;
        while (head){
            head = head -> next;
            freeNode(headPrev);
            headPrev = head;
        }
    }
    free(l);
    //printf("Done.\n");
}

void clearList(struct list* l){
    struct node* head = l -> first, *headPrev = l -> first;
    while (head){
        head = head -> next;
        freeNode(headPrev);
        headPrev = head;
    }
    l -> first = l -> last = NULL;
}

void printList(struct list* l){
    struct node* head = l -> first;
    int count = 0;
    printf("\n│ Length: %i\n│ ----\n", listLen(l));
    while(head){
        printf("│ %i.\t%s\n", count++, head -> data);
        head = head -> next;
    }
    printf("└───────────────────────\n\n");
}

int listLen(struct list* l){
    struct node* head = l -> first;
    int len = 0;
    while(head){
        len++;
        head = head -> next;
    }
    return len;
}