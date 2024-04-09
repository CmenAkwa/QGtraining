#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
    int data;
    struct treenode *left;
    struct treenode *right;
} TreeNode;

typedef struct list1
{
    TreeNode* treepoint;
    struct list1* next;
}stack;

typedef struct list2
{
    TreeNode* treepoint;
    struct list2* next;
}queuenode;

typedef struct {
    queuenode *head;
    queuenode *end;
} queue;

typedef struct heap {
    TreeNode *root;
    // 可以添加其他辅助信息，例如堆的大小等
} Heap;
//树操作
TreeNode *insert(TreeNode *root, int data);
TreeNode *search(TreeNode *root, int data);
TreeNode *delete(TreeNode *root, int data);
void freetree(TreeNode *root);
//递归遍历
void preorder(TreeNode *root);
void inorder(TreeNode *root);
void postorder(TreeNode *root);
//栈操作
void push(stack **head, TreeNode *root);
void stackdelete(stack **head);
TreeNode *pop(stack **head);
//非递归遍历
void preorder1(TreeNode *root);
void inorder1(TreeNode *root);
void postorder1(TreeNode *root);
void levelorder(TreeNode *root);
//随机数组
void randomarray(int data[],int size);
//队列操作
void enqueue(queue *qlist, TreeNode *root);
TreeNode *dequeue(queue *qlist);
void clearqueue(queue *qlist);
void heapify(int heap[], int index, int heapSize);
int removeTop(int heap[], int *heapSize);
void insertheap(int heap[], int value, int *heapSize);