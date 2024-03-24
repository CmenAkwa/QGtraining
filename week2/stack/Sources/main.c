#include "..\Headers\stack.h"

int main() {
    stack *head = NULL;
    printf("��������ʽ,�ڼӼ��˳��Լ����ֺ���ӿո�,����6 + ( 4 - 2 ) * 3 + 9 / 3\n");
    printf("������:");
    char equation[5000][30];//�������ʽ
    char tempstr[5000];//��ʱ�洢��str
    gets(tempstr);//��ȡ����
    int length = strlen(tempstr);//������������ַ���
    tempstr[length] = '\n';//����ȡ�������β�ĳ�\n
    int n = getin(equation, tempstr, length);//ת��Ϊ���ֺͷ���,nΪ���ֺͷ��Ÿ���
    char inverse[5000][30];//ת������沨��ʽ
    int cnt = 0;//�沨��ʽ�ڵ�Ԫ�ظ���������
    char strtemp[30];
    for (int i = 0; i < n; i++) {
        if (equation[i][0] >= '0' && equation[i][0] <= '9')//���������,���
        {
            strcpy(inverse[cnt], equation[i]);
            cnt++;
        } else if (equation[i][0] == '(')//������ֱ����ջ
        {
            stackin(&head, (equation[i]));
        } else if (equation[i][0] == ')')//������,��һֱ��ջֱ������������
        {
            while (stacktop(head) != '(') {
                stackout(&head, inverse[cnt]);//��ջ��������沨��ʽ
                cnt++;
            }
            stackout(&head, strtemp);//�������ų�ջ
        } else if (equation[i][0] == '+' || equation[i][0] == '-' || equation[i][0] == '*' ||
                   equation[i][0] == '/')//�����Ӽ��˳�
        {
            while (isfirst(equation[i][0], stacktop(head)) == 0)//���ȼ�С�ڵ���ջ��,��ջ
            {
                stackout(&head, inverse[cnt]);//��ջ��������沨��ʽ
                cnt++;
            }
            stackin(&head, (equation[i]));//ֱ�����ȼ�����ջ��,ѹջ
        } else {
            printf("��������,������ʽ�Ƿ���ȷ\n");
            system("pause");
            return 0;
        }
    }
    while (stacktop(head) != '?') {
        stackout(&head, inverse[cnt]);//��ջ��������沨��ʽ
        cnt++;
    }
    printf("�沨��ʽΪ:");
    for (int i = 0; i < n; i++)
        printf("%s ", inverse[i]);
    printf("\n");
    stackdelete(&head);//���ջ
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (inverse[i][0] >= '0' && inverse[i][0] <= '9')//����ֱ����ջ
        {
            stackin(&head, inverse[i]);
        } else if (inverse[i][0] == '+' || inverse[i][0] == '-' || inverse[i][0] == '*' || inverse[i][0] == '/') {
            char tempstack1[30];
            char tempstack2[30];
            char changein[30];
            stackout(&head, tempstack1);//��ջջ��
            stackout(&head, tempstack2);//�ٳ�ջջ��
            sum = calculate(tempstack2, tempstack1, inverse[i]);//���ղ�����ջ�����м���,����������sum
            if (sum == -999)//�д���
            {
                printf("��������\n");
                system("pause");
                return 0;
            }
            int change = 0;
            while (sum != 0) {
                changein[change] = (char) (sum % 10 + '0');//��sumת����char����,����ջ
                sum /= 10;
                change++;
            }
            changein[change] = '\0';
            strrev(changein);//�ղ�ת���Ľ��Ҫ��תһ�²�����������˳��
            stackin(&head, changein);//��ջ
        }
    }
    stackout(&head, strtemp);//��ջ���ս��
    printf("���Ϊ%s", strtemp);
    printf("\n");
    system("pause");
}

int calculate(char a[30], char b[30], char c[30])//��������
{
    int numa = 0;
    int numb = 0;
    int i = 0;
    while (a[i] != '\0')//��char����ת��Ϊ����
    {
        numa *= 10;
        numa += (int) a[i] - '0';
        i++;
    }
    i = 0;
    while (b[i] != '\0')//��char����ת��Ϊ����
    {
        numb *= 10;
        numb += (int) b[i] - '0';
        i++;
    }
    if (c[0] == '+')//�Ӽ��˳�������
        return numa + numb;
    else if (c[0] == '-')
        return numa - numb;
    else if (c[0] == '*')
        return numa * numb;
    else if (c[0] == '/')//���ܳ�0�����ж�
    {
        if (numb == 0) {
            printf("0����������\n");
            return -999;
        } else
            return numa / numb;
    } else//�����ж�
        return -999;

}

void stackin(stack **head, char data[30])//��ջ
{
    stack *p = (stack *) malloc(sizeof(stack));
    strcpy(p->data, data);
    p->next = *head;
    *head = p;
}

void stackout(stack **head, char data[30])//��ջ
{
    stack *p = *head;
    *head = (*head)->next;
    strcpy(data, p->data);
    free(p);
}

int stacknum(stack *head)//��ȡջ��Ԫ�ظ���
{
    stack *p = head;
    int cnt = 0;
    for (p = head; p; p = p->next)
        cnt++;
    return cnt;
}

char stacktop(stack *head)//��ȡջ��Ԫ��
{
    if (head == NULL)
        return '?';
    else
        return (head->data)[0];
}

int isfirst(char a, char b)//�ж��Ƿ�Ϊ�����ȼ�����
{
    int score1 = 0;
    int score2 = 0;
    if (a == '+' || a == '-')//�Ӽ����ȼ���Ϊ1
        score1 = 1;
    else if (a == '*' || a == '/')//�˳����ȼ���Ϊ2
        score1 = 2;

    if (b == '+' || b == '-')//�Ӽ����ȼ���Ϊ1
        score2 = 1;
    else if (b == '*' || b == '/')//�˳����ȼ���Ϊ2
        score2 = 2;
    else if (b == '?')//��ջ��Ϊ��,���ȼ���Ϊ0��������
        score2 = 0;
    if (score1 > score2)
        return 1;
    else
        return 0;
}

int getin(char data[5000][30], const char str[5000], int length)//����ת������,���ַ���תΪ��ά������ʽ
{
    int i = 0;
    int j = 0;
    for (int k = 0; k <= length; k++) {
        if (str[k] == ' ')//�����ո�����һ��
        {
            data[i][j] = '\0';
            i++;
            j = 0;
        } else if (str[k] == '\n')//������������һ�в��ҷ���
        {
            data[i][j] = '\0';
            i++;
            return i;
        } else {
            data[i][j] = str[k];//һֱ��ȡ���ڶ�ȡ��λ��
            j++;
        }
    }
    return i;
}

void stackdelete(stack **head)//���ջ
{
    stack *p = *head;
    for (*head; *head; (*head) = (*head)->next) {
        free(p);
        p = *head;
    }
}
