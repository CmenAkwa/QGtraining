#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
    char data[30];
    struct list* next;
}stack;

typedef struct normal
{
    char data;
    struct normal* next;
}queue;
void stackin(stack **head, char data[30]);
void stackout(stack **head,char data[30]);
int stacknum(stack *head);
char stacktop(stack *head);
int isfirst(char a,char b);
int getin(char data[5000][30],const char str[5000],int length);
void stackdelete(stack** head);
int calculate(char a[30],char b[30],char c[30]);