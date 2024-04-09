#include "..\Headers\tree.h"

int main() {
    int data[10] = {0};
    int size = 10;
    TreeNode *root = NULL;
    int seed = 0;
    printf("������������:");
    scanf("%d", &seed);
    while (getchar() != '\n');
    srand((unsigned int) seed);//�������������
    randomarray(data, size);//�������������
    printf("\n");
    printf("���ɵ��������,��������������\n");
    for (int i = 0; i < size; i++) {
        root = insert(root, data[i]);
        printf("%d ", data[i]);
    }
    printf("\n\nǰ�����\n");
    preorder(root);
    printf("\n");
    preorder1(root);
    printf("�ǵݹ�\n");

    printf("\n�������\n");
    inorder(root);
    printf("\n");
    inorder1(root);
    printf("�ǵݹ�\n");

    printf("\n�������\n");
    postorder(root);
    printf("\n");
    postorder1(root);
    printf("�ǵݹ�\n");

    printf("\n�������\n");
    levelorder(root);

    int heapsize = 9999;
    int heap[heapsize];
    for (int i = 0; i < size; i++) {
        insertheap(heap, data[i], &heapsize);
    }
    printf("\n��");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }


    freetree(root);
    getchar();
}

void randomarray(int data[], int size)//�������
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

TreeNode *insert(TreeNode *root, int data)//����,���ֵ�Ѿ����ھͲ�����
{
    if (root == NULL)//�ݹ����
    {
        TreeNode *p = create(data);
        return p;
    }
    if (data < (root->data))//С�ڷ����
        root->left = insert(root->left, data);
    else if (data > (root->data))//���ڷ��ұ�
        root->right = insert(root->right, data);
    return root;//���ظ��ڵ�
}

TreeNode *search(TreeNode *root, int data)//����
{
    if (root == NULL)
        return NULL;//����β�˻�û�ҵ�,����NULL
    else if (data < (root->data))//С�������
    {
        return search(root->left, data);
    } else if (data > (root->data))//�������ұ�
    {
        return search(root->right, data);
    } else//��ȷ���
    {
        return root;//����ָ��ֵ��ָ��
    }
}

TreeNode *delete(TreeNode *root, int data)//ɾ��
{
    if (root == NULL) {
        return NULL;//�Ҳ���
    }
    if (data < (root->data))//С��ɾ���
    {
        root->left = delete(root->left, data);
    } else if (data > (root->data))//����ɾ�ұ�
    {
        root->right = delete(root->right, data);
    } else//�ҵ������root->data=data
    {
        if (root->left == NULL)//���û����ڵ�,�ǾͰ��ҽڵ��ɵ�ǰ�ڵ�
        {
            TreeNode *temp = root->right;//������Ҷ�û�ڵ�,���ǵ�ǰ�ڵ�ΪҶ�ӽڵ�,��root->right����NULL,����NULL
            free(root);
            return temp;
        } else if (root->right == NULL)//���û���ҽڵ�,�ǾͰ���ڵ��ɵ�ǰ�ڵ�
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        } else {
            TreeNode *temp = root->right;//��ֱ�Ӻ��,����������
            while (temp->left != NULL)//���������������ֱ�Ӻ��
            {
                temp = temp->left;
            }
            root->data = temp->data;//ֱ���滻ֵ
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void freetree(TreeNode *root)//ɾ����
{
    if (root == NULL) {
        return; // ����ڵ�Ϊ�գ�ֱ�ӷ���
    }
    // �ݹ��ͷ������������������ڴ�
    freetree(root->left);
    freetree(root->right);
    free(root);//�ͷŵ�ǰ�ڵ���ڴ�
}

void preorder(TreeNode *root)//ǰ�����
{
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root)//�������
{
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(TreeNode *root)//�������
{
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void preorder1(TreeNode *root)//ǰ������ǵݹ�
{
    if (root == NULL)//��������
    {
        return;
    }
    stack *head = NULL;//����ջ��
    TreeNode *now = root;
    while (now != NULL || head != NULL)//����ʱѭ��
    {
        while (now != NULL) {
            printf("%d ", now->data);//���ʽڵ�
            push(&head, now);//ÿ���ڵ㶼��ջ�����
            now = now->left;//������������
        }//�����now==NULL
        now = pop(&head);//�ص���һ��,�ҳ�ջ
        now = now->right;//��������
    }
    stackdelete(&head);//ɾ��ջ
}

void inorder1(TreeNode *root)//��������ǵݹ�
{
    if (root == NULL) {
        return;
    }
    stack *head = NULL;//����ջ��
    TreeNode *now = root;
    while (now != NULL || head != NULL)//����ʱѭ��
    {
        while (now != NULL)//����ǰ�ڵ㼰���������ӽڵ���ջ
        {
            push(&head, now);
            now = now->left;
        }
        now = pop(&head);//����ջ���ڵ�,������ߵ�Ҷ�ӽڵ�
        printf("%d ", now->data);
        now = now->right;//����ǰ�ڵ�����ӽڵ���Ϊ�µĸ��ڵ���������������
    }
    stackdelete(&head);//ɾ��ջ
}

void postorder1(TreeNode *root)//��������ǵݹ�
{
    if (root == NULL) {
        return;
    }
    stack *head = NULL;//����ջ��
    TreeNode *now = root;
    TreeNode *pre = NULL;//���ڸ�����һ�����ʵĽڵ�
    while (now != NULL || head != NULL)//����ʱѭ��
    {
        if (now != NULL)//����ǰ�ڵ㼰���������ӽڵ���ջ
        {
            push(&head, now);//��ջ
            now = now->left;//������
        } else//now=NULLʱ��ʾ�ߵ�ͷ��
        {
            now = head->treepoint;//nowΪջ��Ԫ��
            if (now->right != NULL && now->right != pre)//���ҽڵ����û�����ʹ�
            {
                now = now->right;//���ҽڵ�
            } else//���ҽڵ㲢�ҷ��ʹ���,�ͳ�ջ�����
            {
                now = pop(&head);
                printf("%d ", now->data);
                pre = now;
                now = NULL;
            }
        }
    }
    stackdelete(&head);//ɾ��ջ
}

void levelorder(TreeNode *root)//�������
{
    if (root == NULL)//������ֱ�ӷ���
    {
        return;
    }
    queue q;//������Ϊq
    q.head = q.end = NULL;
    enqueue(&q, root);//�����ڵ����
    while (q.head != NULL) {
        TreeNode *current = dequeue(&q);//����һ���ڵ�
        printf("%d ", current->data);//���
        if (current->left != NULL)//���ӵĽڵ���������ӽڵ�,�����ӽڵ����
        {
            enqueue(&q, current->left);
        }
        if (current->right != NULL)//���ӵĽڵ���������ӽڵ�,�����ӽڵ����
        {
            enqueue(&q, current->right);
        }

    }
    clearqueue(&q);//��ն���
}

void push(stack **head, TreeNode *root)//��ջ
{
    if (head == NULL || root == NULL)//���򷵻�
    {
        return;
    }
    stack *p = (stack *) malloc(sizeof(stack));
    p->treepoint = root;
    p->next = *head;
    *head = p;//����ջ��
}

TreeNode *pop(stack **head)//��ջ
{
    if (*head == NULL)//��ջ����NULL
    {
        return NULL;
    }
    TreeNode *temp = (*head)->treepoint;//����ջ����rootֵ
    stack *p = *head;
    *head = (*head)->next;
    free(p);//�ͷſռ�
    return temp;//���ظղ�ջ����root
}

void stackdelete(stack **head)//���ջ
{
    stack *p = *head;
    for (*head; *head; (*head) = (*head)->next)//����ɾ��
    {
        free(p);
        p = *head;
    }
}

void enqueue(queue *qlist, TreeNode *root)//��ӽڵ�,���
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

TreeNode *dequeue(queue *qlist)//����
{
    if (qlist->head == NULL) {
        qlist->end = NULL;
        return NULL;
    }
    queuenode *p = qlist->head;
    qlist->head = qlist->head->next;//head��ɺ�һλ
    if (qlist->head == NULL) {
        qlist->end = NULL;
    }
    TreeNode *temp = p->treepoint;
    free(p);
    return temp;//������ָ��
}

void clearqueue(queue *qlist)//ɾ������
{
    queuenode *p = qlist->head;
    queuenode *next;
    while (p != NULL) {
        next = p->next;
        free(p);//�ͷŵ�ǰ�ڵ���ڴ�
        p = next;
    }
    qlist->head = qlist->end = NULL;//������ͷβָ������Ϊ NULL
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
