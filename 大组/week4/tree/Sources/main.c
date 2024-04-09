#include "..\Headers\tree.h"

int main() {
    int data[10] = {0};
    int size = 10;
    TreeNode *root = NULL;
    int seed = 0;
    printf("请输入种子数:");
    scanf("%d", &seed);
    while (getchar() != '\n');
    srand((unsigned int) seed);//更改随机数种子
    randomarray(data, size);//创建随机数数组
    printf("\n");
    printf("生成的随机数组,将其插入二叉树中\n");
    for (int i = 0; i < size; i++) {
        root = insert(root, data[i]);
        printf("%d ", data[i]);
    }
    printf("\n\n前序遍历\n");
    preorder(root);
    printf("\n");
    preorder1(root);
    printf("非递归\n");

    printf("\n中序遍历\n");
    inorder(root);
    printf("\n");
    inorder1(root);
    printf("非递归\n");

    printf("\n后序遍历\n");
    postorder(root);
    printf("\n");
    postorder1(root);
    printf("非递归\n");

    printf("\n层序遍历\n");
    levelorder(root);

    int heapsize = 9999;
    int heap[heapsize];
    for (int i = 0; i < size; i++) {
        insertheap(heap, data[i], &heapsize);
    }
    printf("\n堆");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }


    freetree(root);
    getchar();
}

void randomarray(int data[], int size)//随机数组
{
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 50;
    }
}

TreeNode *create(int data) {
    TreeNode *newnode = (TreeNode *) malloc(sizeof(TreeNode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

TreeNode *insert(TreeNode *root, int data)//插入,如果值已经存在就不操作
{
    if (root == NULL)//递归出口
    {
        TreeNode *p = create(data);
        return p;
    }
    if (data < (root->data))//小于放左边
        root->left = insert(root->left, data);
    else if (data > (root->data))//大于放右边
        root->right = insert(root->right, data);
    return root;//返回根节点
}

TreeNode *search(TreeNode *root, int data)//搜索
{
    if (root == NULL)
        return NULL;//到结尾了还没找到,返回NULL
    else if (data < (root->data))//小于搜左边
    {
        return search(root->left, data);
    } else if (data > (root->data))//大于搜右边
    {
        return search(root->right, data);
    } else//相等返回
    {
        return root;//返回指向值的指针
    }
}

TreeNode *delete(TreeNode *root, int data)//删除
{
    if (root == NULL) {
        return NULL;//找不到
    }
    if (data < (root->data))//小于删左边
    {
        root->left = delete(root->left, data);
    } else if (data > (root->data))//大于删右边
    {
        root->right = delete(root->right, data);
    } else//找到的情况root->data=data
    {
        if (root->left == NULL)//如果没有左节点,那就把右节点变成当前节点
        {
            TreeNode *temp = root->right;//如果左右都没节点,就是当前节点为叶子节点,那root->right就是NULL,返回NULL
            free(root);
            return temp;
        } else if (root->right == NULL)//如果没有右节点,那就把左节点变成当前节点
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        } else {
            TreeNode *temp = root->right;//找直接后继,在右子树找
            while (temp->left != NULL)//右子树的最左边是直接后继
            {
                temp = temp->left;
            }
            root->data = temp->data;//直接替换值
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void freetree(TreeNode *root)//删除树
{
    if (root == NULL) {
        return; // 如果节点为空，直接返回
    }
    // 递归释放左子树和右子树的内存
    freetree(root->left);
    freetree(root->right);
    free(root);//释放当前节点的内存
}

void preorder(TreeNode *root)//前序遍历
{
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root)//中序遍历
{
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(TreeNode *root)//后序遍历
{
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void preorder1(TreeNode *root)//前序遍历非递归
{
    if (root == NULL)//空树返回
    {
        return;
    }
    stack *head = NULL;//创建栈顶
    TreeNode *now = root;
    while (now != NULL || head != NULL)//不空时循环
    {
        while (now != NULL) {
            printf("%d ", now->data);//访问节点
            push(&head, now);//每个节点都入栈且输出
            now = now->left;//继续走左子树
        }//走完后now==NULL
        now = pop(&head);//回到上一级,且出栈
        now = now->right;//走右子树
    }
    stackdelete(&head);//删除栈
}

void inorder1(TreeNode *root)//中序遍历非递归
{
    if (root == NULL) {
        return;
    }
    stack *head = NULL;//创建栈顶
    TreeNode *now = root;
    while (now != NULL || head != NULL)//不空时循环
    {
        while (now != NULL)//将当前节点及其所有左子节点入栈
        {
            push(&head, now);
            now = now->left;
        }
        now = pop(&head);//访问栈顶节点,即最左边的叶子节点
        printf("%d ", now->data);
        now = now->right;//将当前节点的右子节点作为新的根节点继续进行中序遍历
    }
    stackdelete(&head);//删除栈
}

void postorder1(TreeNode *root)//后序遍历非递归
{
    if (root == NULL) {
        return;
    }
    stack *head = NULL;//创建栈顶
    TreeNode *now = root;
    TreeNode *pre = NULL;//用于跟踪上一个访问的节点
    while (now != NULL || head != NULL)//不空时循环
    {
        if (now != NULL)//将当前节点及其所有左子节点入栈
        {
            push(&head, now);//入栈
            now = now->left;//向左走
        } else//now=NULL时表示走到头了
        {
            now = head->treepoint;//now为栈顶元素
            if (now->right != NULL && now->right != pre)//有右节点而且没被访问过
            {
                now = now->right;//走右节点
            } else//有右节点并且访问过了,就出栈且输出
            {
                now = pop(&head);
                printf("%d ", now->data);
                pre = now;
                now = NULL;
            }
        }
    }
    stackdelete(&head);//删除栈
}

void levelorder(TreeNode *root)//层序遍历
{
    if (root == NULL)//树空则直接返回
    {
        return;
    }
    queue q;//队列名为q
    q.head = q.end = NULL;
    enqueue(&q, root);//将根节点入队
    while (q.head != NULL) {
        TreeNode *current = dequeue(&q);//出队一个节点
        printf("%d ", current->data);//输出
        if (current->left != NULL)//出队的节点如果有左子节点,将左子节点入队
        {
            enqueue(&q, current->left);
        }
        if (current->right != NULL)//出队的节点如果有右子节点,将右子节点入队
        {
            enqueue(&q, current->right);
        }

    }
    clearqueue(&q);//清空队列
}

void push(stack **head, TreeNode *root)//入栈
{
    if (head == NULL || root == NULL)//空则返回
    {
        return;
    }
    stack *p = (stack *) malloc(sizeof(stack));
    p->treepoint = root;
    p->next = *head;
    *head = p;//更新栈顶
}

TreeNode *pop(stack **head)//出栈
{
    if (*head == NULL)//空栈返回NULL
    {
        return NULL;
    }
    TreeNode *temp = (*head)->treepoint;//保存栈顶的root值
    stack *p = *head;
    *head = (*head)->next;
    free(p);//释放空间
    return temp;//返回刚才栈顶的root
}

void stackdelete(stack **head)//清空栈
{
    stack *p = *head;
    for (*head; *head; (*head) = (*head)->next)//遍历删除
    {
        free(p);
        p = *head;
    }
}

void enqueue(queue *qlist, TreeNode *root)//添加节点,入队
{
    queuenode *p = (queuenode *) malloc(sizeof(queuenode));
    p->treepoint = root;
    p->next = NULL;
    if (qlist->end) {
        qlist->end->next = p;
    } else {
        qlist->head = p;
    }
    qlist->end = p;
}

TreeNode *dequeue(queue *qlist)//出队
{
    if (qlist->head == NULL) {
        qlist->end = NULL;
        return NULL;
    }
    queuenode *p = qlist->head;
    qlist->head = qlist->head->next;//head变成后一位
    if (qlist->head == NULL) {
        qlist->end = NULL;
    }
    TreeNode *temp = p->treepoint;
    free(p);
    return temp;//返回树指针
}

void clearqueue(queue *qlist)//删除队列
{
    queuenode *p = qlist->head;
    queuenode *next;
    while (p != NULL) {
        next = p->next;
        free(p);//释放当前节点的内存
        p = next;
    }
    qlist->head = qlist->end = NULL;//将队列头尾指针设置为 NULL
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int index) {
    return (index - 1) / 2;
}

int leftChild(int index) {
    return 2 * index + 1;
}

int rightChild(int index) {
    return 2 * index + 2;
}

void heapify(int heap[], int index, int heapSize) {
    int left = leftChild(index);
    int right = rightChild(index);
    int largest = index;

    if (left < heapSize && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < heapSize && heap[right] > heap[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapify(heap, largest, heapSize);
    }
}

void insertheap(int heap[], int value, int *heapSize) {
    heap[++(*heapSize)] = value;
    int i = *heapSize;
    while (i > 0 && heap[parent(i)] < heap[i]) {
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }
}

int removeTop(int heap[], int *heapSize) {
    if (*heapSize == 0) {
        return -1;
    }
    int top = heap[0];
    heap[0] = heap[*heapSize - 1];
    (*heapSize)--;
    heapify(heap, 0, *heapSize);
    return top;
}
