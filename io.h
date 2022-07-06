#ifndef IO_H_
#define IO_H_

#define BUFF_SIZE 32

char* getIn(char* dest, int len);
char* prompt(char* prompt, char* dest, int len);
int getNum(int bound, int len);
int promptNum(char* prompt, int bound, int len);
int choose(char* a, char* b);

#endif