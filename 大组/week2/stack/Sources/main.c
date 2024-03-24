#include "..\Headers\stack.h"

int main() {
    stack *head = NULL;
    printf("请输入算式,在加减乘除以及数字后面加空格,例如6 + ( 4 - 2 ) * 3 + 9 / 3\n");
    printf("请输入:");
    char equation[5000][30];//输入的算式
    char tempstr[5000];//临时存储的str
    gets(tempstr);//获取输入
    int length = strlen(tempstr);//所输入的算数字符串
    tempstr[length] = '\n';//将获取的输入结尾改成\n
    int n = getin(equation, tempstr, length);//转换为数字和符号,n为数字和符号个数
    char inverse[5000][30];//转换后的逆波兰式
    int cnt = 0;//逆波兰式内的元素个数计数器
    char strtemp[30];
    for (int i = 0; i < n; i++) {
        if (equation[i][0] >= '0' && equation[i][0] <= '9')//如果是数字,输出
        {
            strcpy(inverse[cnt], equation[i]);
            cnt++;
        } else if (equation[i][0] == '(')//左括号直接入栈
        {
            stackin(&head, (equation[i]));
        } else if (equation[i][0] == ')')//右括号,则一直出栈直到遇到左括号
        {
            while (stacktop(head) != '(') {
                stackout(&head, inverse[cnt]);//出栈结果进入逆波兰式
                cnt++;
            }
            stackout(&head, strtemp);//将左括号出栈
        } else if (equation[i][0] == '+' || equation[i][0] == '-' || equation[i][0] == '*' ||
                   equation[i][0] == '/')//遇到加减乘除
        {
            while (isfirst(equation[i][0], stacktop(head)) == 0)//优先级小于等于栈顶,弹栈
            {
                stackout(&head, inverse[cnt]);//出栈结果进入逆波兰式
                cnt++;
            }
            stackin(&head, (equation[i]));//直到优先级大于栈顶,压栈
        } else {
            printf("输入有误,请检查算式是否正确\n");
            system("pause");
            return 0;
        }
    }
    while (stacktop(head) != '?') {
        stackout(&head, inverse[cnt]);//出栈结果进入逆波兰式
        cnt++;
    }
    printf("逆波兰式为:");
    for (int i = 0; i < n; i++)
        printf("%s ", inverse[i]);
    printf("\n");
    stackdelete(&head);//清空栈
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (inverse[i][0] >= '0' && inverse[i][0] <= '9')//数字直接入栈
        {
            stackin(&head, inverse[i]);
        } else if (inverse[i][0] == '+' || inverse[i][0] == '-' || inverse[i][0] == '*' || inverse[i][0] == '/') {
            char tempstack1[30];
            char tempstack2[30];
            char changein[30];
            stackout(&head, tempstack1);//出栈栈顶
            stackout(&head, tempstack2);//再出栈栈顶
            sum = calculate(tempstack2, tempstack1, inverse[i]);//将刚才两个栈顶进行计算,计算结果存入sum
            if (sum == -999)//判错数
            {
                printf("输入有误\n");
                system("pause");
                return 0;
            }
            int change = 0;
            while (sum != 0) {
                changein[change] = (char) (sum % 10 + '0');//将sum转化回char数组,并入栈
                sum /= 10;
                change++;
            }
            changein[change] = '\0';
            strrev(changein);//刚才转换的结果要翻转一下才是正常数字顺序
            stackin(&head, changein);//入栈
        }
    }
    stackout(&head, strtemp);//出栈最终结果
    printf("结果为%s", strtemp);
    printf("\n");
    system("pause");
}

int calculate(char a[30], char b[30], char c[30])//计算数字
{
    int numa = 0;
    int numb = 0;
    int i = 0;
    while (a[i] != '\0')//将char数组转化为数字
    {
        numa *= 10;
        numa += (int) a[i] - '0';
        i++;
    }
    i = 0;
    while (b[i] != '\0')//将char数组转化为数字
    {
        numb *= 10;
        numb += (int) b[i] - '0';
        i++;
    }
    if (c[0] == '+')//加减乘除的运算
        return numa + numb;
    else if (c[0] == '-')
        return numa - numb;
    else if (c[0] == '*')
        return numa * numb;
    else if (c[0] == '/')//不能除0特殊判断
    {
        if (numb == 0) {
            printf("0不能做除数\n");
            return -999;
        } else
            return numa / numb;
    } else//错误判断
        return -999;

}

void stackin(stack **head, char data[30])//入栈
{
    stack *p = (stack *) malloc(sizeof(stack));
    strcpy(p->data, data);
    p->next = *head;
    *head = p;
}

void stackout(stack **head, char data[30])//出栈
{
    stack *p = *head;
    *head = (*head)->next;
    strcpy(data, p->data);
    free(p);
}

int stacknum(stack *head)//获取栈内元素个数
{
    stack *p = head;
    int cnt = 0;
    for (p = head; p; p = p->next)
        cnt++;
    return cnt;
}

char stacktop(stack *head)//获取栈顶元素
{
    if (head == NULL)
        return '?';
    else
        return (head->data)[0];
}

int isfirst(char a, char b)//判断是否为高优先级运算
{
    int score1 = 0;
    int score2 = 0;
    if (a == '+' || a == '-')//加减优先级定为1
        score1 = 1;
    else if (a == '*' || a == '/')//乘除优先级定为2
        score1 = 2;

    if (b == '+' || b == '-')//加减优先级定为1
        score2 = 1;
    else if (b == '*' || b == '/')//乘除优先级定为2
        score2 = 2;
    else if (b == '?')//若栈顶为空,优先级定为0便于运算
        score2 = 0;
    if (score1 > score2)
        return 1;
    else
        return 0;
}

int getin(char data[5000][30], const char str[5000], int length)//输入转化函数,将字符串转为二维数组形式
{
    int i = 0;
    int j = 0;
    for (int k = 0; k <= length; k++) {
        if (str[k] == ' ')//遇到空格则下一行
        {
            data[i][j] = '\0';
            i++;
            j = 0;
        } else if (str[k] == '\n')//遇到换行则下一行并且返回
        {
            data[i][j] = '\0';
            i++;
            return i;
        } else {
            data[i][j] = str[k];//一直读取便于读取多位数
            j++;
        }
    }
    return i;
}

void stackdelete(stack **head)//清空栈
{
    stack *p = *head;
    for (*head; *head; (*head) = (*head)->next) {
        free(p);
        p = *head;
    }
}
