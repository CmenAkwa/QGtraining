#include "..\Headers\myfunc.h"

int main() {
    single *head1 = NULL;//创建单链表头
    single *end1 = NULL;//创建单链表尾
    single *p1 = NULL;
    doubly *head2 = NULL;
    doubly *p2 = NULL;
    printf("请输入单链表的节点个数以及值,以空格分隔\n");
    printf("请输入节点个数:");
    int n = 0;
    scanf("%d", &n);
    system("cls");
    printf("请输入%d个整数节点值,以空格分隔\n",n);
    for (int i = 0; i < n; i++) {
        int temp = 0;
        scanf("%d", &temp);
        creative1(&head1, &end1, temp);
    }
    printf("请选择使用单链表还是双链表\n1.单链表\n");
    printf("2.双链表\n");
    printf("3.退出\n");
    printf("请输入:");
    int mode = 0;//操作模式选择
    scanf("%d", &mode);

    while (mode != 3) {
        if (mode == 1) {
            printf("1.单链表奇偶转换\n");
            printf("2.查询单链表中点\n");
            printf("3.反转链表(递归)非递归在递归解法下方定义\n");
            printf("4.判断链表是否成环\n");
            int judge = 0;
            scanf("%d", &judge);
            system("cls");
            switch (judge) {
                case 1:;
                    changenode(&head1);//奇偶转换函数,定义在main函数下方
                    for(p1=head1;p1;p1=p1->next)
                    {
                        printf("%d ",p1->data);
                    }
                    system("pause");
                    break;
                case 2:
                    p1 = middleNode(head1);//取中间节点
                    printf("中间节点的节点值为%d\n", p1->data);
                    break;
                case 3:
                    p1=head1;
                    printf("反转前:");
                    for(p1=head1;p1;p1=p1->next)
                    {
                        printf("%d ",p1->data);
                    }
                    printf("\n递归反转后:");
                    head1=reverselist(head1);
                    for(p1=head1;p1;p1=p1->next)
                    {
                        printf("%d ",p1->data);
                    }
                    head1= reverselist2(head1);
                    printf("\n非递归反转后(应变回原样):");
                    for(p1=head1;p1;p1=p1->next)
                    {
                        printf("%d ",p1->data);
                    }
                    printf("\n");
                    break;
                case 4:
                    p1=head1;
                    if(iscircle(p1))
                        printf("成环\n");
                    else
                        printf("不成环\n");
                    break;
                default:
                    printf("输入错误,请重新输入\n");
                    break;
            }

        } else if (mode == 2) {
            printf("双链表定义在myfunc.h中\n添加双链表节点为尾插法,定义在函数creative2中\n麻烦导师检查\n");
            system("pause");
            mode=3;
        } else if (mode == 3) {
            break;
        } else {
            printf("输入有误,请重新输入\n");
        }
    }
}











bool iscircle(single *head)//判断是否成环
{
    if(head==NULL)
        return false;
    single *fast = head->next;
    single *slow = head;
    while (fast != slow) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return true;
}


single *middleNode(single *head)//判断中间节点
{
    int cnt = 0;
    single *p;
    for (p = head; p; p = p->next) {//遍历一遍找出节点个数
        cnt++;
    }
    p = head;
    for (int i = 0; i < cnt / 2; i++) {//找到cnt/2处的节点,若节点为偶数,则中间节点为中间两个的后者
        p = p->next;
    }
    return p;
}


void creative1(single **head, single **end, int num)//添加单链表节点
{
    single *p = (single *) malloc(sizeof(single));
    p->data = num;
    p->next = NULL;
    if (*end)//如果尾结点所指不为空
        (*end)->next = p;//将尾结点指向新建节点p
    else//如果尾结点为空,则头节点必为空
        *head = p;//让头节点指向新建节点p
    *end = p;//更新尾结点的值使end指向链表的结尾
}

void creative2(doubly **head, int num)//添加双链表节点,尾插法
{
    doubly *p = (doubly *) malloc(sizeof(doubly));
    p->data = num;
    p->next = NULL;
    p->prior = NULL;
    doubly *end = *head;
    if (end == NULL) {
        *head = p;
    } else {
        while (end->next != NULL) {
            end = end->next;
        }
        end->next = p;
        p->prior = end;
        p->next = NULL;
    }
}

void changenode(single** head)//不交换值
{
    single* p=*head;
    single* temp;
    single* prior;
    if(p!=NULL&&p->next!=NULL)//第一次使头结点移动至第二个
    {
        *head=(*head)->next;
        temp=p->next->next;
        p->next->next=p;
        p->next=temp;
    }
    if(p==NULL)
    {
        return;
    }
    prior=p;//假设a->b->c->d,欲交换b,c,此时p指向a;prior指向a
    p=p->next;//p指向b
    while(p!=NULL&&p->next!=NULL)
    {
        temp=p->next->next;//temp指向d
        p->next->next=p;//将c所指改为b
        prior->next=p->next;//将a指向c
        p->next=temp;//b指向d,此时链表已变成a->c->b->d
        prior=p;//更新prior指向b
        p=p->next;//使p指向d,以便待会交换d与e
    }
}

single* reverselist(single* head)//递归反转链表
{
    if (head == NULL || head->next == NULL) {
        return head;//递归出口
    }
    single* newhead = reverselist(head->next);
    head->next->next = head;//将后面的节点指向自己
    head->next = NULL;//断开当前节点指向下一个节点的链接
    return newhead;
}

single* reverselist2(single* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    single *now=head;
    single *before=NULL;
    while(now)
    {
        single* after=now->next;
        now->next=before;
        before=now;
        now=after;
    }
    return before;//此时now已经变成null,返回的应该是before;
}




