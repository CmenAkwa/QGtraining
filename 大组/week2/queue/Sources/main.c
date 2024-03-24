#include "..\Headers\queue.h"

int main() {
    queue queue1;//��������
    queue1.head = queue1.end = NULL;//�����µ�ͷβ�ÿ�
    int n = 0;
    printf("������������Ľڵ����");
    scanf("%d", &n);
    system("cls");
    for (int i = 0; i < n; i++)//ѭ������ڵ�
    {
        char c;
        while ((c = getchar()) != '\n');//��ջ�����
        printf("�������%d���ڵ�\n", i + 1);
        int mode;
        printf("�����������������\n1.����\n2.������\n3.�ַ���\n���������");
        scanf("%d", &mode);
        switch (mode) {
            case 1: {
                int intvalue;
                printf("����������:");
                scanf("%d", &intvalue);
                add(&queue1, &intvalue, mode);//����int��ַ
                break;
            }
            case 2: {
                double doublevalue;
                printf("�����븡����:");
                scanf("%lf", &doublevalue);
                add(&queue1, &doublevalue, mode);//����double��ַ
                break;
            }
            case 3: {
                char str[3000];
                printf("�������ַ���:");
                scanf("%s", str);
                add(&queue1, str, mode);//�����ַ�����Ԫ�ص�ַ
                break;
            }
            default: {
                system("cls");
                printf("�������,����������\n");
                i--;
            }
        }
    }

    int queuenum = nodenum(&queue1);//�������Ԫ�ظ���
    for (int i = 0; i < queuenum; i++)//ѭ������
    {
        put(&queue1);
    }
    clearqueue(&queue1);//��ն���
    system("pause");

}

void add(queue *qlist, void *data, int type)//��ӽڵ�,���
{
    list *p = (list *) malloc(sizeof(list));
    p->data = data;
    p->type = type;
    p->next = NULL;
    list *last = qlist->end;
    if (last) {
        last->next = p;
    } else {
        qlist->head = p;
    }
    qlist->end = p;
}

void *put(queue *qlist)//����
{
    list *p = qlist->head;
    qlist->head = (qlist->head)->next;
    void *temp = p->data;
    switch (p->type)//�����������
    {
        case 1:
            printf("%d\n", *(int *) (p->data));
            break;
        case 2:
            printf("%lf\n", *(double *) (p->data));
            break;
        case 3:
            printf("%s\n", (char *) (p->data));
            break;
    }
    free(p);
    return temp;//��������ָ��
}

int nodenum(queue *qlist)//�ж϶���Ԫ�ظ���
{
    int cnt = 0;
    list *head = qlist->head;
    list *p = head;
    for (p = head; p; p = p->next) {
        cnt++;
    }
    return cnt;
}

void clearqueue(queue *qlist)//ɾ������
{
    list *p = qlist->head;
    list *next;
    while (p != NULL) {
        next = p->next;
        free(p);//�ͷŵ�ǰ�ڵ���ڴ�
        p = next;
    }
    qlist->head = qlist->end = NULL;//������ͷβָ������Ϊ NULL
}
