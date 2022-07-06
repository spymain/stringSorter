#ifndef MERGE_H_
#define MERGE_H_

void mergeSort(struct list* l, int (*nodeCmp)(char*, char*));
void merge(struct list* a, struct list* b, int (*nodeCmp)(char*, char*));
void moveNode(struct node* n, struct list* l);

#endif