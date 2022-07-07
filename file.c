#include <stdio.h>
#include "io.h"
#include "llist.h"

int fileApnd(char* filename, struct list* l){
    char buff[BUFF_SIZE];
    FILE* fp = fopen(filename, "r");
    if (!fp) return 0;
    while(!feof(fp)){
        fgets(buff, BUFF_SIZE - 1, fp);
        addNodeEnd(buff, BUFF_SIZE, l);
    }
    return 1;
}