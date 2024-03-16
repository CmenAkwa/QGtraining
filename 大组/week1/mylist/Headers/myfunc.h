#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct list1//单链表
{
    int data;
    struct list1* next;
}single;

typedef struct list2//双链表
{
    struct list2* prior;
    int data;
    struct list2* next;
}doubly;

void creative2(doubly **head, int num);
void creative1(single **head, single **end, int num);
single *middleNode(single *head);
bool iscircle(single *head);
void changenode(single** head);
single* reverselist(single* head);
single* reverselist2(single* head);