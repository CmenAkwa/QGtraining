#include <stdio.h>
#include <stdlib.h>
void randomarray(int arr[], int size);
void colorsort(int data[],int size);
void swap(int* a,int *b);
int main()
{
    int n=0;
    printf("�봴������ɫԪ�ظ���,�Զ������������\n");
    printf("������");
    scanf("%d",&n);
    int* data=(int*) malloc(sizeof(int)*n);
    randomarray(data,n);
    printf("����ǰ\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",data[i]);
    }
    colorsort(data,n);
    printf("\n");
    printf("�����\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
    system("pause");

}
void colorsort(int data[],int size)
{
    int i=0;
    int j=size-1;
    int p=0;
    for(p=0;p<=j;p++)
    {
        if(data[p]==0)
        {
            swap(&data[i],&data[p]);
            i++;
        }
        else if(data[p]==2)
        {
            swap(&data[j],&data[p]);
            j--;
        }
        if(data[p]!=1)
        p--;
    }
}
void swap(int* a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void randomarray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 3;//�ڷ�Χ [0,2]�����������
    }
}