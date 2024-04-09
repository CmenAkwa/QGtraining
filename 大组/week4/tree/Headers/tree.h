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
    // �����������������Ϣ������ѵĴ�С��
} Heap;
//������
TreeNode *insert(TreeNode *root, int data);
TreeNode *search(TreeNode *root, int data);
TreeNode *delete(TreeNode *root, int data);
void freetree(TreeNode *root);
//�ݹ����
void preorder(TreeNode *root);
void inorder(TreeNode *root);
void postorder(TreeNode *root);
//ջ����
void push(stack **head, TreeNode *root);
void stackdelete(stack **head);
TreeNode *pop(stack **head);
//�ǵݹ����
void preorder1(TreeNode *root);
void inorder1(TreeNode *root);
void postorder1(TreeNode *root);
void levelorder(TreeNode *root);
//�������
void randomarray(int data[],int size);
//���в���
void enqueue(queue *qlist, TreeNode *root);
TreeNode *dequeue(queue *qlist);
void clearqueue(queue *qlist);
void heapify(int heap[], int index, int heapSize);
int removeTop(int heap[], int *heapSize);
void insertheap(int heap[], int value, int *heapSize);