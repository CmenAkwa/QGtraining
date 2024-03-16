#include "..\Headers\myfunc.h"

int main() {
    single *head1 = NULL;//����������ͷ
    single *end1 = NULL;//����������β
    single *p1 = NULL;
    doubly *head2 = NULL;
    doubly *p2 = NULL;
    printf("�����뵥����Ľڵ�����Լ�ֵ,�Կո�ָ�\n");
    printf("������ڵ����:");
    int n = 0;
    scanf("%d", &n);
    system("cls");
    printf("������%d�������ڵ�ֵ,�Կո�ָ�\n",n);
    for (int i = 0; i < n; i++) {
        int temp = 0;
        scanf("%d", &temp);
        creative1(&head1, &end1, temp);
    }
    printf("��ѡ��ʹ�õ�������˫����\n1.������\n");
    printf("2.˫����\n");
    printf("3.�˳�\n");
    printf("������:");
    int mode = 0;//����ģʽѡ��
    scanf("%d", &mode);

    while (mode != 3) {
        if (mode == 1) {
            printf("1.��������żת��\n");
            printf("2.��ѯ�������е�\n");
            printf("3.��ת����(�ݹ�)�ǵݹ��ڵݹ�ⷨ�·�����\n");
            printf("4.�ж������Ƿ�ɻ�\n");
            int judge = 0;
            scanf("%d", &judge);
            system("cls");
            switch (judge) {
                case 1:;
                    changenode(&head1);//��żת������,������main�����·�
                    for(p1=head1;p1;p1=p1->next)
                    {
                        printf("%d ",p1->data);
                    }
                    system("pause");
                    break;
                case 2:
                    p1 = middleNode(head1);//ȡ�м�ڵ�
                    printf("�м�ڵ�Ľڵ�ֵΪ%d\n", p1->data);
                    break;
                case 3:
                    p1=head1;
                    printf("��תǰ:");
                    for(p1=head1;p1;p1=p1->next)
                    {
                        printf("%d ",p1->data);
                    }
                    printf("\n�ݹ鷴ת��:");
                    head1=reverselist(head1);
                    for(p1=head1;p1;p1=p1->next)
                    {
                        printf("%d ",p1->data);
                    }
                    head1= reverselist2(head1);
                    printf("\n�ǵݹ鷴ת��(Ӧ���ԭ��):");
                    for(p1=head1;p1;p1=p1->next)
                    {
                        printf("%d ",p1->data);
                    }
                    printf("\n");
                    break;
                case 4:
                    p1=head1;
                    if(iscircle(p1))
                        printf("�ɻ�\n");
                    else
                        printf("���ɻ�\n");
                    break;
                default:
                    printf("�������,����������\n");
                    break;
            }

        } else if (mode == 2) {
            printf("˫��������myfunc.h��\n���˫����ڵ�Ϊβ�巨,�����ں���creative2��\n�鷳��ʦ���\n");
            system("pause");
            mode=3;
        } else if (mode == 3) {
            break;
        } else {
            printf("��������,����������\n");
        }
    }
}











bool iscircle(single *head)//�ж��Ƿ�ɻ�
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


single *middleNode(single *head)//�ж��м�ڵ�
{
    int cnt = 0;
    single *p;
    for (p = head; p; p = p->next) {//����һ���ҳ��ڵ����
        cnt++;
    }
    p = head;
    for (int i = 0; i < cnt / 2; i++) {//�ҵ�cnt/2���Ľڵ�,���ڵ�Ϊż��,���м�ڵ�Ϊ�м������ĺ���
        p = p->next;
    }
    return p;
}


void creative1(single **head, single **end, int num)//��ӵ�����ڵ�
{
    single *p = (single *) malloc(sizeof(single));
    p->data = num;
    p->next = NULL;
    if (*end)//���β�����ָ��Ϊ��
        (*end)->next = p;//��β���ָ���½��ڵ�p
    else//���β���Ϊ��,��ͷ�ڵ��Ϊ��
        *head = p;//��ͷ�ڵ�ָ���½��ڵ�p
    *end = p;//����β����ֵʹendָ������Ľ�β
}

void creative2(doubly **head, int num)//���˫����ڵ�,β�巨
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

void changenode(single** head)//������ֵ
{
    single* p=*head;
    single* temp;
    single* prior;
    if(p!=NULL&&p->next!=NULL)//��һ��ʹͷ����ƶ����ڶ���
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
    prior=p;//����a->b->c->d,������b,c,��ʱpָ��a;priorָ��a
    p=p->next;//pָ��b
    while(p!=NULL&&p->next!=NULL)
    {
        temp=p->next->next;//tempָ��d
        p->next->next=p;//��c��ָ��Ϊb
        prior->next=p->next;//��aָ��c
        p->next=temp;//bָ��d,��ʱ�����ѱ��a->c->b->d
        prior=p;//����priorָ��b
        p=p->next;//ʹpָ��d,�Ա���ύ��d��e
    }
}

single* reverselist(single* head)//�ݹ鷴ת����
{
    if (head == NULL || head->next == NULL) {
        return head;//�ݹ����
    }
    single* newhead = reverselist(head->next);
    head->next->next = head;//������Ľڵ�ָ���Լ�
    head->next = NULL;//�Ͽ���ǰ�ڵ�ָ����һ���ڵ������
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
    return before;//��ʱnow�Ѿ����null,���ص�Ӧ����before;
}




