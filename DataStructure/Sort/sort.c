//
// Created by zyc on 3/27/19.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#include "sort.h"


// print int arr[] numbers
void print_arr(int arr[], int len, int num)
{
    int i;

    printf("%d: ", num);
    for(i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\n");
}


// 1. Bubble Sort
void bubble_sort(int *arr, int len)
{
    int i, j;

    for(i = 1; i < len; i++)
    {
        for(j = 1; j < len; j++)
        {
            if(arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
        //print_arr(arr, len, i);
    }
}

void bubble_sort2(int *arr, int len)
{
    int i, j;

    for(i = 1; i < len; i++)
    {
        bool flag = false;
        for(j = 1; j < len; j++)
        {
            if(arr[j] < arr[j - 1])
            {
                flag = true;
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
        //print_arr(arr, len, i + 1);
        if(!flag)
            return;
    }
}

void bubble_sort3(int *arr, int len)
{
    int i, j, new, n = len;

    for(i = 0; i < len; i++)
    {
        new = 0;
        for(j = 1; j < n; j++)
        {
            if(arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                new = j;
            }
        }
        //print_arr(arr, len, i);
        n = new;

        if(n == 1)
            break;
    }
}

// 2. Insertion Sort
void insertion_sort(int *arr, int len)
{
    int i = 1, j;

    while(i < len)
    {
        j = i;
        while(j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
        //print_arr(arr, 10, i);
        i++;
    }
    /*
    int i, j;

    for(i = 0; i < len - 1; i++)
    {
        for(j = i + 1; j > 0; j--)
        {
            if(j > 0 && arr[j - 1] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }

        print_arr(arr, 10, i);
    }
    */
}

// 3. Selection Sort
void selection_sort(int *arr, int len)
{
    int i, j, index;

    for(i = 0; i < len; i++)
    {
        index = i;

        for(j = i + 1; j < len; j++)
        {
            if(arr[j] < arr[index])
                index = j;
        }

        if(index != i)
        {
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
        //print_arr(arr, 10, i);
    }
}

// 4. Quick Sort
void quick_sort(int *arr, int left, int right)
{
    if(left < right)
    {
        int i = left, j = right, target = arr[left];

        while(i < j)
        {
            while (i < j && arr[j] > target)
                j--;

            if(i < j)
                arr[i++] = arr[j];

            while(i < j && arr[i] < target)
                i++;

            if(i < j)
                arr[j] = arr[i];
        }

        arr[i] = target;
        //print_arr(arr, 10, i);
        quick_sort(arr, left, i - 1);
        quick_sort(arr, i + 1, right);
    }
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void quick_sort2(int *arr, int len)
{
    qsort(arr, len, sizeof(int), compare);
}

// 5. Shell Sort
void shell_sort(int *arr, int len)
{
    int i, j, d = len / 2;

    while(d > 0)
    {
        for(i = d; i < len; i++)
        {
            j = i - d;

            while(j >= 0 && arr[j] > arr[j + d])
            {
                int temp = arr[j];
                arr[j] = arr[j + d];
                arr[j + d] = temp;
                j = j - d;
            }
        }
        //print_arr(arr, 10, i);
        d = d / 2;
    }
}

// 6. heap_sort
void heap_adjust(int *arr, int i, int len)
{
    int child;

    for(; 2 * i + 1 < len; i = child)
    {
        child = 2 * i + 1;

        if(child < len - 1 && arr[child + 1] > arr[child])
            child++;

        if(arr[i] < arr[child])
        {
            int temp = arr[child];
            arr[child] = arr[i];
            arr[i] = temp;
        }
        else
            break;
    }
}

void heap_sort(int *arr, int len)
{
    int i;

    for(i = len / 2 - 1; i >= 0; i--)
        heap_adjust(arr, i, len);

    for(i = len - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heap_adjust(arr, 0, i);
    }
}

//7. merge sort
void merge(int *arr, int start, int mid, int end)
{
    int n1 = mid -start + 1;
    int n2 = end - mid;
    int left[n1], right[n2];
    int i, j, k;

    for(i = 0; i < n1; i++)
        left[i] = arr[start + i];

    for(j = 0; j <n2; j++)
        right[n2] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = start;

    while(i < n1 && j < n2)
    {
        if(left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while(i < n1)
        arr[k++] = left[i++];

    while(i < n2)
        arr[k++] = right[j++];
}

void merge_sort(int *arr, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;

        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

// 8. counting sort
void count_sort(int *arr, int len)
{
    int i, maxValue = arr[0];

    for(i = 0; i < len; i++)
    {
        if(arr[i] > maxValue)
            maxValue = arr[i];
    }

    maxValue += 1;

    int *countArr = (int *)malloc(maxValue * sizeof(int));
    int *sortsArr = (int *)malloc(len * sizeof(int));

    for(i = 0; i < len; i++)
        countArr[arr[i]]++;

    for(i = 1; i < maxValue; i++)
        countArr[i] += countArr[i - 1];

    for(i = len - 1; i >= 0; --i)
    {
        sortsArr[countArr[arr[i]] - 1] = arr[i];
        --countArr[arr[i]];
    }

    memcpy(arr, sortsArr, len * sizeof(int));

    free(sortsArr);
    free(countArr);
}

// 9. bucket sort
void bucket_sort(int *arr, int len)
{
    if(arr == NULL || len < 1)
        return;

    int i, j, maxValue = arr[0];

    for(i = 1; i < len; i++)
    {
        if(maxValue < arr[i])
            maxValue = arr[i];
    }
    maxValue += 1;

    int buckets[maxValue];

    for(i = 0; i < maxValue; i++)
        buckets[i] = 0;

    for(i = 0; i < len; i++)
        buckets[arr[i]]++;

    for(i = 0, j = 0; i < maxValue; i++)
    {
        while((buckets[i]--) > 0)
            arr[j++] = i;
    }
}

// 10. radix sort
int get_max(int a[], int n)
{
    int i, max = a[0];

    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

void countSort(int a[], int n, int exp)
{
    int output[n];
    int i, buckets[10] = {0};

    for (i = 0; i < n; i++)
        buckets[(a[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        buckets[i] += buckets[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[buckets[(a[i] / exp) % 10] - 1] = a[i];
        buckets[(a[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
}

void radix_sort(int *arr, int len)
{
    int exp;

    int maxValue = get_max(arr, len);

    for(exp = 1; maxValue/exp > 0; exp++)
        countSort(arr, len, exp);
}


void test_sort()
{
    int arr[10] = {7,5,2,4,8,0,9,3,1,6};

    print_arr(arr, 10, 0);
    //quick_sort(arr, 0, 9);
    //quick_sort2(arr, 10);
    radix_sort(arr, 10);
    print_arr(arr, 10, 0);
}



int sort_main()
{
    test_sort();

    return 0;
}
