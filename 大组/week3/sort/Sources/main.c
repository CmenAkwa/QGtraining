#include "..\Headers\sort.h"

int main() {
    for (int epoch = 0; epoch < 1; epoch++) {
        int mode;
        printf("1.查询大数据量下排序算法时间\n2.查询大量小数据量下排序算法时间\n3.读写文件数据排序\n");
        printf("请输入序号:");
        scanf("%d", &mode);
        switch (mode) {
            case 1://大数据量
            {
                system("cls");
                const int sizes[] = {10000, 50000, 200000};//不同数据量
                const int n = 3;
                int i, size;
                clock_t start, end;//clock_t是类型名
                double usetime;
                for (i = 0; i < n; i++)//插入排序
                {
                    size = sizes[i];
                    int *arr = (int *) malloc(size * sizeof(int));//动态分配给定大小的数组
                    randomarray(arr, size);
                    start = clock();
                    insertion_sort(arr, size);
                    end = clock();
                    usetime = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;//毫秒为单位
                    printf("数据量为 %d 时插入排序时间: %.3f 毫秒\n", size, usetime);
                    free(arr);
                }
                printf("\n");
                for (i = 0; i < n; i++)//归并排序
                {
                    size = sizes[i];
                    int *arr = (int *) malloc(size * sizeof(int));
                    randomarray(arr, size);
                    start = clock();
                    merge_sort(arr, 0, size);
                    end = clock();
                    usetime = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
                    printf("数据量为 %d 时归并排序时间: %.3f 毫秒\n", size, usetime);
                    free(arr);
                }
                printf("\n");
                for (i = 0; i < n; i++)//快速排序
                {
                    size = sizes[i];
                    int *arr = (int *) malloc(size * sizeof(int));
                    randomarray(arr, size);
                    start = clock();
                    quick_sort(arr, 0, size);
                    end = clock();
                    usetime = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
                    printf("数据量为 %d 时快速排序时间: %.3f 毫秒\n", size, usetime);
                    free(arr);
                }
                printf("\n");
                for (i = 0; i < n; i++)//计数排序
                {
                    size = sizes[i];
                    int *arr = (int *) malloc(size * sizeof(int));
                    randomarray(arr, size);
                    start = clock();
                    count_sort(arr, size);
                    end = clock();
                    usetime = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
                    printf("数据量为 %d 时计数排序时间: %.3f 毫秒\n", size, usetime);
                    free(arr);
                }
                printf("\n");
                for (i = 0; i < n; i++)//基数计数排序
                {
                    size = sizes[i];
                    int *arr = (int *) malloc(size * sizeof(int)); // 动态分配给定大小的数组
                    randomarray(arr, size);
                    start = clock();
                    radix_count_sort(arr, size);
                    end = clock();
                    usetime = ((double) (end - start)) / CLOCKS_PER_SEC * 1000; // 毫秒为单位
                    printf("数据量为 %d 时基数计数排序时间: %.3f 毫秒\n", size, usetime);
                    free(arr);
                }
                system("pause");
                break;
            }
            case 2://多次小数量
            {
                system("cls");
                clock_t alltime;
                int datasize = 100;
                int size = 100000;

                alltime = 0;
                for (int i = 0; i < size; i++)//插入排序
                {
                    int *arr = (int *) malloc(datasize * sizeof(int));//动态分配给定大小的数组
                    randomarray(arr, datasize);//生成随机数组
                    clock_t start = clock();
                    insertion_sort(arr, datasize);//执行插入排序算法
                    clock_t end = clock();
                    alltime += (end - start);
                    free(arr);//释放数组内存
                }
                double finaltime = (double) alltime;
                printf("插入排序在 %d 个数据上执行 %d 次排序的总时间为: %.3lf 毫秒\n", datasize, size, finaltime);
                printf("\n");

                alltime = 0;
                for (int i = 0; i < size; i++)//归并排序
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
                printf("归并排序在 %d 个数据上执行 %d 次排序的总时间为: %.3lf 毫秒\n", datasize, size, finaltime);
                printf("\n");

                alltime = 0;
                for (int i = 0; i < size; i++)//快速排序
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
                printf("快速排序在 %d 个数据上执行 %d 次排序的总时间为: %.3lf 毫秒\n", datasize, size, finaltime);
                printf("\n");

                alltime = 0;
                for (int i = 0; i < size; i++)//计数排序
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
                printf("计数排序在 %d 个数据上执行 %d 次排序的总时间为: %.3lf 毫秒\n", datasize, size, finaltime);
                printf("\n");

                alltime = 0;
                for (int i = 0; i < size; i++)//基数计数排序
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
                printf("基数计数排序在 %d 个数据上执行 %d 次排序的总时间为: %.3lf 毫秒\n", datasize, size, finaltime);
                printf("\n");

                system("pause");
                break;
            }
            case 3: {
                system("cls");
                printf("请输入想生成的个数");
                int innum = 0;
                scanf("%d", &innum);
                while (innum >= 200000) {
                    system("cls");
                    printf("过大,请重新输入:");
                    scanf("%d", &innum);
                    while (getchar() != '\n');//循环清空缓冲区,以免死循环
                }
                int *array = (int *) malloc(sizeof(int) * innum);
                printf("生成的数据量为%d\n",innum);
                addfile(array, innum, 0);//mode表示操作模式,0是创建随机数,1是直接写入文件
                free(array);
                int *filearray = (int *) malloc(sizeof(int) * innum);
                readfile(filearray);
                quick_sort(filearray, 0, innum);
                addfile(filearray, innum, 1);//mode表示操作模式,0是创建随机数,1是直接写入文件
                for(int i=0;i<innum;i++)
                {
                    printf("%d ",filearray[i]);
                }
                system("pause");
                break;
            }
            default: {
                system("cls");
                printf("输入错误,请重新输入\n");
                epoch--;
                while (getchar() != '\n');//循环清空缓冲区,以免死循环
            }
        }
    }
    
    return 0;
}

int addfile(int arr[], int size, int mode) {
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("无法打开文件 %s\n", "test.txt");
        return -1;
    }
    if (mode == 0) {
        randomarray(arr, size);
    }
    for (int i = 0; i < size; ++i) {
        fprintf(fp, "%d\n", arr[i]);//将随机数写入文件
    }
    fclose(fp);
    printf("写入成功\n请在test.txt内查看\n");
}

int readfile(int arr[]) {
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("无法打开文件 %s\n", "test.txt");
        return -1;
    }
    int cnt = 0;
    while (fscanf(fp, "%d", &arr[cnt]) != EOF) {
        cnt++;
    }
    printf("读取成功\n");
    return 0;
}

void randomarray(int arr[], int size)//随机数组
{
    int i;
    for (i = 0; i < size; ++i) {
        arr[i] = rand() % 1000000;//在范围[0,999999]内生成随机数
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//插入排序
void insertion_sort(int arr[], int n) {
    int i, now, j;
    for (i = 1; i < n; i++) {
        now = arr[i];//arr[i]是被插入的元素
        j = i - 1;//j更新成已排序数列的最大位置
        while (j >= 1 && arr[j] > now)//如果arr[j]也就是当前的元素比now大,就往后挪,给now留空间
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = now;
    }
}

//归并排序
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;//左数组的长度
    int n2 = right - mid;//右数组的长度
    int *left_arr = (int *) malloc(n1 * sizeof(int));//创建左数组
    int *right_arr = (int *) malloc(n2 * sizeof(int));//创建右数组
    for (i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];//根据原数值创建左数组
    for (j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];//根据原数值创建右数组
    i = 0;//指向left当前的元素
    j = 0;//指向right当前的元素
    k = left;//指向arr当前的元素
    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j])//如果left的第一个元素比right的第一个元素小,就把left的第一个元素填回数组,然后向后移动i
        {
            arr[k] = left_arr[i];//如果left的第一个元素比right的第一个元素大,就把right的第一个元素填回数组,然后向后移动j
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;//每次填值k++
    }
    //此时必有一个数组已经空了,无脑加就行,空的数组不会进入循环
    while (i < n1)//左不空加左
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < n2)//右不空加左
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
    free(left_arr);
    free(right_arr);
}

void merge_sort(int arr[], int left, int right) {
    if (left < right)//一直递归到left和right相邻,此时mid等于right
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);//递归左边
        merge_sort(arr, mid + 1, right);//递归右边
        merge(arr, left, mid, right);
    }
}

//快速排序随机选取枢轴值
int partition(int arr[], int low, int high)
{

    int pivotindex = low + rand() % (high - low + 1); // 随机选择枢轴的索引
    int pivot = arr[pivotindex];
    swap(&arr[pivotindex], &arr[high]); // 将随机选择的元素与最后一个元素交换
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

//计数排序
void count_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)//找出最大值便于确定数组大小
    {
        if (arr[i] > max)
            max = arr[i];
    }
    int *count = (int *) malloc((max + 1) * sizeof(int));//申请计数数组
    for (int i = 0; i <= max; i++)//清空数组
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;//将对应元素++
    }
    int cnt = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            count[i]--;//把出现次数--
            arr[cnt] = i;//把原数组填上当前数字
            cnt++;//原数组索引++;
        }
    }
    free(count);
}

//基数计数排序
void radix_count_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)//找出最大数,根据最大数确定最大位数,根据最大位数确定循环次数
    {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    //计数数组和临时数组
    int count[10] = {0};
    int *output = (int *) malloc(sizeof(int) * n);
    //计数数组中每个元素的出现次数
    for (int exp = 1; max / exp > 0; exp *= 10)//exp是位置操作数,exp=1代表操作个位,10是十位
    {
        for (int i = 0; i < 10; i++)//清空计数数组
        {
            count[i] = 0;
        }
        for (int i = 0; i < n; i++)//统计每个数字出现的次数
        {
            int digit = arr[i] / exp;//digit的最后一位就是要比较的数
            count[digit % 10]++;//取出最后一位,加完之后count就代表着当前位置有多少数
        }
        for (int i = 1; i < 10; i++)//将count[i]更新为i出现的最终位置的索引
        {
            count[i] += count[i - 1];//状态转移,类似dp问题,从count[0]开始,越过中间重复的数
        }
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;//算出arr[i]当前所判断的位数的那个值
            output[count[digit] - 1] = arr[i];//根据digit值在count中查询,将arr中的元素按照索引填入output中,-1是为了从0开始放置
            count[digit]--;//把count计数器的值--,待会操作的
        }
        for (int i = 0; i < n; i++)//将数据复制回原始数组
        {
            arr[i] = output[i];
        }//循环每一位,最终数组将有序
    }
    free(output);
}

void bubble_sort(int arr[], int n)//优化1.没有交换提前终止 2.记录最后一次交换位置免得重复判断
{
    int i, j;
    int judge;//判断是否有进行交换
    int last = n - 1;//最后一次交换
    for (i = 0; i < n - 1; i++) {
        judge = 0;
        for (j = 0; j < last; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j+1]
                swap(&arr[j], &arr[j + 1]);
                judge = 1;
                last = j; // 记录最后一次交换位置
            }
        }
        if (judge == 0)//没有交换,提前终止
            break;
    }
}

void cocktail_sort(int arr[], int n)//3.鸡尾酒排序,也就是冒泡排序的双向版
{
    int left = 0, right = n - 1;
    while (left <= right) {
        int i;
        // 从左到右扫描，将最大元素移动到数组末尾
        for (i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
            }
        }
        right--;
        // 从右到左扫描，将最小元素移动到数组开头
        for (i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(&arr[i], &arr[i - 1]);
            }
        }
        left++;
    }
}
