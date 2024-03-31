#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b);
void insertion_sort(int arr[], int n);
void merge(int arr[], int left, int mid, int right);
void merge_sort(int arr[], int left, int right);
int partition(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);
void count_sort(int arr[], int n);
void radix_count_sort(int arr[], int n);
void randomarray(int arr[], int size);
int addfile(int arr[],int size,int mode);
int readfile(int arr[]);
void bubble_sort(int arr[], int n);
void cocktail_sort(int arr[], int n);