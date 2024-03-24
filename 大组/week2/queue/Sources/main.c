#include "..\Headers\queue.h"

int main() {
    queue queue1;//创建队列
    queue1.head = queue1.end = NULL;//队列下的头尾置空
    int n = 0;
    printf("请输入想输入的节点个数");
    scanf("%d", &n);
    system("cls");
    for (int i = 0; i < n; i++)//循环输入节点
    {
        char c;
        while ((c = getchar()) != '\n');//清空缓冲区
        printf("请输入第%d个节点\n", i + 1);
        int mode;
        printf("请输入想输入的类型\n1.整形\n2.浮点型\n3.字符串\n请输入序号");
        scanf("%d", &mode);
        switch (mode) {
            case 1: {
                int intvalue;
                printf("请输入整数:");
                scanf("%d", &intvalue);
                add(&queue1, &intvalue, mode);//传入int地址
                break;
            }
            case 2: {
                double doublevalue;
                printf("请输入浮点数:");
                scanf("%lf", &doublevalue);
                add(&queue1, &doublevalue, mode);//传入double地址
                break;
            }
            case 3: {
                char str[3000];
                printf("请输入字符串:");
                scanf("%s", str);
                add(&queue1, str, mode);//传入字符串首元素地址
                break;
            }
            default: {
                system("cls");
                printf("输入错误,请重新输入\n");
                i--;
            }
        }
    }

    int queuenum = nodenum(&queue1);//计算队列元素个数
    for (int i = 0; i < queuenum; i++)//循环出队
    {
        put(&queue1);
    }
    clearqueue(&queue1);//清空队列
    system("pause");

}

void add(queue *qlist, void *data, int type)//添加节点,入队
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

void *put(queue *qlist)//出队
{
    list *p = qlist->head;
    qlist->head = (qlist->head)->next;
    void *temp = p->data;
    switch (p->type)//根据类型输出
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
    return temp;//返回数据指针
}

int nodenum(queue *qlist)//判断队列元素个数
{
    int cnt = 0;
    list *head = qlist->head;
    list *p = head;
    for (p = head; p; p = p->next) {
        cnt++;
    }
    return cnt;
}

void clearqueue(queue *qlist)//删除队列
{
    list *p = qlist->head;
    list *next;
    while (p != NULL) {
        next = p->next;
        free(p);//释放当前节点的内存
        p = next;
    }
    qlist->head = qlist->end = NULL;//将队列头尾指针设置为 NULL
}
