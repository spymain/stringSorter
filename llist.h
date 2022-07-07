#ifndef LLIST_H_
#define LLIST_H_

struct list {
    struct node* first;
    struct node* last;
};
struct node {
    char* data;
    struct node* prev;
    struct node* next;
    struct list* list;
};

struct list* makeList();
struct node* makeNode(char* data, int len);
struct node* addNodeEnd(char* data, int len, struct list* l);
//void swap(struct node* a, struct node* b);
struct list* splitList(struct list* l);
struct node* getNode(int indx, struct list* l);
void freeNode(struct node* n);
void delNode(struct node* node);
void delList(struct list* l);
void clearList(struct list* l);
void printList(struct list* l);
int listLen(struct list* l);

#endif