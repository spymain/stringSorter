#include <stddef.h>
#include "llist.h"
#include "merge.h"
#include "io.h"

void mergeSort(struct list* l, int (*nodeCmp)(char*, char*)){
    if (listLen(l) > 1){
        struct list* l2 = splitList(l);
        mergeSort(l, nodeCmp);
        mergeSort(l2, nodeCmp);
        merge(l, l2, nodeCmp);
    }
}

void merge(struct list* a, struct list* b, int (*nodeCmp)(char*, char*)){
    struct node *headA = a -> first, *headB = b -> first, *tmp;
    struct list merged;
    struct list* new = &merged;

    new -> first = new -> last = NULL;

    int choice;
    while(headA && headB){
        choice = nodeCmp(headA -> data, headB -> data);
        if(choice == 1){
            tmp = headA;
            headA = headA -> next;
            moveNode(tmp, new);
        } else {
            tmp = headB;
            headB = headB -> next;
            moveNode(tmp, new);
        }
    }
    while(headA){
        tmp = headA;
        headA = headA -> next;
        moveNode(tmp, new);
    }
    while(headB){
        tmp = headB;
        headB = headB -> next;
        moveNode(tmp, new);
    }

    a -> first = new -> first;
    a -> last = new -> last;
    headA = new -> first;
    while(headA){
        headA -> list = a;
        headA = headA -> next;
    }
    delList(b);
}

void moveNode(struct node* n, struct list* l){
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

    n -> list = l;
    if(l -> last){
        n -> prev = l -> last;
        l -> last = l -> last -> next = n;
    } else {
        l -> last = l -> first = n;
        n -> next = n -> prev = NULL;
    }
}