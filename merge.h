#ifndef MERGE_H_
#define MERGE_H_

void mergeSort(struct list* l);
void merge(struct list* a, struct list* b);
int nodeCmp(struct node* a, struct node* b);
void moveNode(struct node* n, struct list* l);

#endif