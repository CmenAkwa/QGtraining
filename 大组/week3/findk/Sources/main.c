#include <stdio.h>
#include <stdlib.h>

void randomarray(int array[], int n);

void swap(int *a, int *b);

int partition(int arr[], int low, int high);

void quick_sort(int arr[], int low, int high, int k);

int cmp(const void *a, const void *b);

int main() {
    printf("Ҫ�ҵڼ������:");
    int k;
    scanf("%d", &k);
    int data[9999];
    printf("\nҪ���ɶ����������:");
    int n = 0;
    scanf("%d", &n);
    randomarray(data, n);
    quick_sort(data, 0, n, k);//����ִ��һ��,�ж�mid��k�����λ��,ִֻ�а�ߵ�����
    printf("\n��k�������%d", data[k - 1]);
    printf("\n");


    //����Ϊ��֤,��ʡ��
    printf("���ú�����֤�Ƿ���ȷ(��ʡ��)\n");
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
    int pivot = arr[high];//ѡ�����ұ�Ϊ�Ƚ�ֵ
    int i = (low);//������������

    for (int j = low; j <= high - 1; j++)//jΪ����ָ��
    {
        if (arr[j] < pivot)//��ǰ���ȱȽ�ֵС
        {
            swap(&arr[i], &arr[j]);//�ѵ�ǰ���Ƶ���������ĩβ,Ȼ��������++,������֮��i��ߵĶ���С�ڱȽ�ֵ��,�ұ߶��Ǵ��ڱȽ�ֵ��
            i++;
        }
    }
    swap(&arr[i], &arr[high]);//���ѱȽ�ֵ�Ƶ�arr[i]��λ��Ҳ���Ƿֽ��
    return (i);
}

void quick_sort(int arr[], int low, int high, int k) {
    if (low < high) {
        int mid = partition(arr, low, high);
        if (k - 1 < mid) {
            quick_sort(arr, low, mid - 1, k);//�ж�k�����İ���,С��midֻ�ñ��������
        } else {
            quick_sort(arr, mid + 1, high, k);//�ж�k�����İ���,С��midֻ�ñ����Ұ���
        }

    }
}

void randomarray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 1000;
    }
}


//��֤��
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


