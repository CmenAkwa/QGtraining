#include "..\Headers\sort.h"

int main() {
    for (int epoch = 0; epoch < 1; epoch++) {
        int mode;
        printf("1.��ѯ���������������㷨ʱ��\n2.��ѯ����С�������������㷨ʱ��\n3.��д�ļ���������\n");
        printf("���������:");
        scanf("%d", &mode);
        switch (mode) {
            case 1://��������
            {
                system("cls");
                const int sizes[] = {10000, 50000, 200000};//��ͬ������
                const int n = 3;
                int i, size;
                clock_t start, end;//clock_t��������
                double usetime;
                for (i = 0; i < n; i++)//��������
                {
                    size = sizes[i];
                    int *arr = (int *) malloc(size * sizeof(int));//��̬���������С������
                    randomarray(arr, size);
                    start = clock();
                    insertion_sort(arr, size);
                    end = clock();
                    usetime = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;//����Ϊ��λ
                    printf("������Ϊ %d ʱ��������ʱ��: %.3f ����\n", size, usetime);
                    free(arr);
                }
                printf("\n");
                for (i = 0; i < n; i++)//�鲢����
                {
                    size = sizes[i];
                    int *arr = (int *) malloc(size * sizeof(int));
                    randomarray(arr, size);
                    start = clock();
                    merge_sort(arr, 0, size);
                    end = clock();
                    usetime = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
                    printf("������Ϊ %d ʱ�鲢����ʱ��: %.3f ����\n", size, usetime);
                    free(arr);
                }
                printf("\n");
                for (i = 0; i < n; i++)//��������
                {
                    size = sizes[i];
                    int *arr = (int *) malloc(size * sizeof(int));
                    randomarray(arr, size);
                    start = clock();
                    quick_sort(arr, 0, size);
                    end = clock();
                    usetime = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
                    printf("������Ϊ %d ʱ��������ʱ��: %.3f ����\n", size, usetime);
                    free(arr);
                }
                printf("\n");
                for (i = 0; i < n; i++)//��������
                {
                    size = sizes[i];
                    int *arr = (int *) malloc(size * sizeof(int));
                    randomarray(arr, size);
                    start = clock();
                    count_sort(arr, size);
                    end = clock();
                    usetime = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
                    printf("������Ϊ %d ʱ��������ʱ��: %.3f ����\n", size, usetime);
                    free(arr);
                }
                printf("\n");
                for (i = 0; i < n; i++)//������������
                {
                    size = sizes[i];
                    int *arr = (int *) malloc(size * sizeof(int)); // ��̬���������С������
                    randomarray(arr, size);
                    start = clock();
                    radix_count_sort(arr, size);
                    end = clock();
                    usetime = ((double) (end - start)) / CLOCKS_PER_SEC * 1000; // ����Ϊ��λ
                    printf("������Ϊ %d ʱ������������ʱ��: %.3f ����\n", size, usetime);
                    free(arr);
                }
                system("pause");
                break;
            }
            case 2://���С����
            {
                system("cls");
                clock_t alltime;
                int datasize = 100;
                int size = 100000;

                alltime = 0;
                for (int i = 0; i < size; i++)//��������
                {
                    int *arr = (int *) malloc(datasize * sizeof(int));//��̬���������С������
                    randomarray(arr, datasize);//�����������
                    clock_t start = clock();
                    insertion_sort(arr, datasize);//ִ�в��������㷨
                    clock_t end = clock();
                    alltime += (end - start);
                    free(arr);//�ͷ������ڴ�
                }
                double finaltime = (double) alltime;
                printf("���������� %d ��������ִ�� %d ���������ʱ��Ϊ: %.3lf ����\n", datasize, size, finaltime);
                printf("\n");

                alltime = 0;
                for (int i = 0; i < size; i++)//�鲢����
                {
                    int *arr = (int *) malloc(datasize * sizeof(int));
                    randomarray(arr, datasize);
                    clock_t start = clock();
                    merge_sort(arr, 0, datasize);
                    clock_t end = clock();
                    alltime += (end - start);
                    free(arr);
                }
                finaltime = (double) alltime;
                printf("�鲢������ %d ��������ִ�� %d ���������ʱ��Ϊ: %.3lf ����\n", datasize, size, finaltime);
                printf("\n");

                alltime = 0;
                for (int i = 0; i < size; i++)//��������
                {
                    int *arr = (int *) malloc(datasize * sizeof(int));
                    randomarray(arr, datasize);
                    clock_t start = clock();
                    quick_sort(arr, 0, datasize);
                    clock_t end = clock();
                    alltime += (end - start);
                    free(arr);
                }
                finaltime = (double) alltime;
                printf("���������� %d ��������ִ�� %d ���������ʱ��Ϊ: %.3lf ����\n", datasize, size, finaltime);
                printf("\n");

                alltime = 0;
                for (int i = 0; i < size; i++)//��������
                {
                    int *arr = (int *) malloc(datasize * sizeof(int));
                    randomarray(arr, datasize);
                    clock_t start = clock();
                    count_sort(arr, datasize);
                    clock_t end = clock();
                    alltime += (end - start);
                    free(arr);
                }
                finaltime = (double) alltime;
                printf("���������� %d ��������ִ�� %d ���������ʱ��Ϊ: %.3lf ����\n", datasize, size, finaltime);
                printf("\n");

                alltime = 0;
                for (int i = 0; i < size; i++)//������������
                {
                    int *arr = (int *) malloc(datasize * sizeof(int));
                    randomarray(arr, datasize);
                    clock_t start = clock();
                    radix_count_sort(arr, datasize);
                    clock_t end = clock();
                    alltime += (end - start);
                    free(arr);
                }
                finaltime = (double) alltime;
                printf("�������������� %d ��������ִ�� %d ���������ʱ��Ϊ: %.3lf ����\n", datasize, size, finaltime);
                printf("\n");

                system("pause");
                break;
            }
            case 3: {
                system("cls");
                printf("�����������ɵĸ���");
                int innum = 0;
                scanf("%d", &innum);
                while (innum >= 200000) {
                    system("cls");
                    printf("����,����������:");
                    scanf("%d", &innum);
                    while (getchar() != '\n');//ѭ����ջ�����,������ѭ��
                }
                int *array = (int *) malloc(sizeof(int) * innum);
                printf("���ɵ�������Ϊ%d\n",innum);
                addfile(array, innum, 0);//mode��ʾ����ģʽ,0�Ǵ��������,1��ֱ��д���ļ�
                free(array);
                int *filearray = (int *) malloc(sizeof(int) * innum);
                readfile(filearray);
                quick_sort(filearray, 0, innum);
                addfile(filearray, innum, 1);//mode��ʾ����ģʽ,0�Ǵ��������,1��ֱ��д���ļ�
                for(int i=0;i<innum;i++)
                {
                    printf("%d ",filearray[i]);
                }
                system("pause");
                break;
            }
            default: {
                system("cls");
                printf("�������,����������\n");
                epoch--;
                while (getchar() != '\n');//ѭ����ջ�����,������ѭ��
            }
        }
    }
    
    return 0;
}

int addfile(int arr[], int size, int mode) {
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("�޷����ļ� %s\n", "test.txt");
        return -1;
    }
    if (mode == 0) {
        randomarray(arr, size);
    }
    for (int i = 0; i < size; ++i) {
        fprintf(fp, "%d\n", arr[i]);//�������д���ļ�
    }
    fclose(fp);
    printf("д��ɹ�\n����test.txt�ڲ鿴\n");
}

int readfile(int arr[]) {
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("�޷����ļ� %s\n", "test.txt");
        return -1;
    }
    int cnt = 0;
    while (fscanf(fp, "%d", &arr[cnt]) != EOF) {
        cnt++;
    }
    printf("��ȡ�ɹ�\n");
    return 0;
}

void randomarray(int arr[], int size)//�������
{
    int i;
    for (i = 0; i < size; ++i) {
        arr[i] = rand() % 1000000;//�ڷ�Χ[0,999999]�����������
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//��������
void insertion_sort(int arr[], int n) {
    int i, now, j;
    for (i = 1; i < n; i++) {
        now = arr[i];//arr[i]�Ǳ������Ԫ��
        j = i - 1;//j���³����������е����λ��
        while (j >= 1 && arr[j] > now)//���arr[j]Ҳ���ǵ�ǰ��Ԫ�ر�now��,������Ų,��now���ռ�
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = now;
    }
}

//�鲢����
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;//������ĳ���
    int n2 = right - mid;//������ĳ���
    int *left_arr = (int *) malloc(n1 * sizeof(int));//����������
    int *right_arr = (int *) malloc(n2 * sizeof(int));//����������
    for (i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];//����ԭ��ֵ����������
    for (j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];//����ԭ��ֵ����������
    i = 0;//ָ��left��ǰ��Ԫ��
    j = 0;//ָ��right��ǰ��Ԫ��
    k = left;//ָ��arr��ǰ��Ԫ��
    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j])//���left�ĵ�һ��Ԫ�ر�right�ĵ�һ��Ԫ��С,�Ͱ�left�ĵ�һ��Ԫ���������,Ȼ������ƶ�i
        {
            arr[k] = left_arr[i];//���left�ĵ�һ��Ԫ�ر�right�ĵ�һ��Ԫ�ش�,�Ͱ�right�ĵ�һ��Ԫ���������,Ȼ������ƶ�j
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;//ÿ����ֵk++
    }
    //��ʱ����һ�������Ѿ�����,���ԼӾ���,�յ����鲻�����ѭ��
    while (i < n1)//�󲻿ռ���
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < n2)//�Ҳ��ռ���
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
    free(left_arr);
    free(right_arr);
}

void merge_sort(int arr[], int left, int right) {
    if (left < right)//һֱ�ݹ鵽left��right����,��ʱmid����right
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);//�ݹ����
        merge_sort(arr, mid + 1, right);//�ݹ��ұ�
        merge(arr, left, mid, right);
    }
}

//�����������ѡȡ����ֵ
int partition(int arr[], int low, int high)
{

    int pivotindex = low + rand() % (high - low + 1); // ���ѡ�����������
    int pivot = arr[pivotindex];
    swap(&arr[pivotindex], &arr[high]); // �����ѡ���Ԫ�������һ��Ԫ�ؽ���
    int i = low;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int mid = partition(arr, low, high);

        quick_sort(arr, low, mid - 1);
        quick_sort(arr, mid + 1, high);
    }
}

//��������
void count_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)//�ҳ����ֵ����ȷ�������С
    {
        if (arr[i] > max)
            max = arr[i];
    }
    int *count = (int *) malloc((max + 1) * sizeof(int));//�����������
    for (int i = 0; i <= max; i++)//�������
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;//����ӦԪ��++
    }
    int cnt = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            count[i]--;//�ѳ��ִ���--
            arr[cnt] = i;//��ԭ�������ϵ�ǰ����
            cnt++;//ԭ��������++;
        }
    }
    free(count);
}

//������������
void radix_count_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)//�ҳ������,���������ȷ�����λ��,�������λ��ȷ��ѭ������
    {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    //�����������ʱ����
    int count[10] = {0};
    int *output = (int *) malloc(sizeof(int) * n);
    //����������ÿ��Ԫ�صĳ��ִ���
    for (int exp = 1; max / exp > 0; exp *= 10)//exp��λ�ò�����,exp=1���������λ,10��ʮλ
    {
        for (int i = 0; i < 10; i++)//��ռ�������
        {
            count[i] = 0;
        }
        for (int i = 0; i < n; i++)//ͳ��ÿ�����ֳ��ֵĴ���
        {
            int digit = arr[i] / exp;//digit�����һλ����Ҫ�Ƚϵ���
            count[digit % 10]++;//ȡ�����һλ,����֮��count�ʹ����ŵ�ǰλ���ж�����
        }
        for (int i = 1; i < 10; i++)//��count[i]����Ϊi���ֵ�����λ�õ�����
        {
            count[i] += count[i - 1];//״̬ת��,����dp����,��count[0]��ʼ,Խ���м��ظ�����
        }
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;//���arr[i]��ǰ���жϵ�λ�����Ǹ�ֵ
            output[count[digit] - 1] = arr[i];//����digitֵ��count�в�ѯ,��arr�е�Ԫ�ذ�����������output��,-1��Ϊ�˴�0��ʼ����
            count[digit]--;//��count��������ֵ--,���������
        }
        for (int i = 0; i < n; i++)//�����ݸ��ƻ�ԭʼ����
        {
            arr[i] = output[i];
        }//ѭ��ÿһλ,�������齫����
    }
    free(output);
}

void bubble_sort(int arr[], int n)//�Ż�1.û�н�����ǰ��ֹ 2.��¼���һ�ν���λ������ظ��ж�
{
    int i, j;
    int judge;//�ж��Ƿ��н��н���
    int last = n - 1;//���һ�ν���
    for (i = 0; i < n - 1; i++) {
        judge = 0;
        for (j = 0; j < last; j++) {
            if (arr[j] > arr[j + 1]) {
                // ���� arr[j] �� arr[j+1]
                swap(&arr[j], &arr[j + 1]);
                judge = 1;
                last = j; // ��¼���һ�ν���λ��
            }
        }
        if (judge == 0)//û�н���,��ǰ��ֹ
            break;
    }
}

void cocktail_sort(int arr[], int n)//3.��β������,Ҳ����ð�������˫���
{
    int left = 0, right = n - 1;
    while (left <= right) {
        int i;
        // ������ɨ�裬�����Ԫ���ƶ�������ĩβ
        for (i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
            }
        }
        right--;
        // ���ҵ���ɨ�裬����СԪ���ƶ������鿪ͷ
        for (i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(&arr[i], &arr[i - 1]);
            }
        }
        left++;
    }
}
