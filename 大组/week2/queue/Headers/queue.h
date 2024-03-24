#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    void *data; // ������ָ�룬ʵ�ַ�������
    struct node *next;
    int type;
} list;

typedef struct {
    list *head;
    list *end;
} queue;

void add(queue *qlist, void *data,int type);
void *put(queue *qlist);
int nodenum(queue *qlist);
void clearqueue(queue *qlist);
