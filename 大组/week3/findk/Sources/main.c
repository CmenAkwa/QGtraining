#include <stdio.h>
#include <stdlib.h>

void randomarray(int array[], int n);

void swap(int *a, int *b);

int partition(int arr[], int low, int high);

void quick_sort(int arr[], int low, int high, int k);

int cmp(const void *a, const void *b);

int main() {
    printf("要找第几大的数:");
    int k;
    scanf("%d", &k);
    int data[9999];
    printf("\n要生成多大的随机数组:");
    int n = 0;
    scanf("%d", &n);
    randomarray(data, n);
    quick_sort(data, 0, n, k);//快排执行一半,判断mid和k的相对位置,只执行半边的排序
    printf("\n第k大的数是%d", data[k - 1]);
    printf("\n");


    //以下为验证,可省略
    printf("借用函数验证是否正确(可省略)\n");
    qsort(data, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }


    system("pause");
}


void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];//选择最右边为比较值
    int i = (low);//左分区最大索引

    for (int j = low; j <= high - 1; j++)//j为遍历指针
    {
        if (arr[j] < pivot)//当前数比比较值小
        {
            swap(&arr[i], &arr[j]);//把当前数移到做分区的末尾,然后让索引++,遍历完之后i左边的都是小于比较值的,右边都是大于比较值的
            i++;
        }
    }
    swap(&arr[i], &arr[high]);//最后把比较值移到arr[i]的位置也就是分界点
    return (i);
}

void quick_sort(int arr[], int low, int high, int k) {
    if (low < high) {
        int mid = partition(arr, low, high);
        if (k - 1 < mid) {
            quick_sort(arr, low, mid - 1, k);//判断k属于哪半区,小于mid只用遍历左半区
        } else {
            quick_sort(arr, mid + 1, high, k);//判断k属于哪半区,小于mid只用遍历右半区
        }

    }
}

void randomarray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 1000;
    }
}


//验证用
int cmp(const void *a, const void *b) {
    int a1 = *(int *) a;
    int b1 = *(int *) b;
    if (a1 < b1) {
        return -1;
    } else if (a1 > b1) {
        return 1;
    }
    return 0;
}


