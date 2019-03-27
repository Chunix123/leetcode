//
// Created by zyc on 3/27/19.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sort.h"



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


void test_sort()
{
    int arr[10] = {7,5,2,4,8,0,9,3,1,6};

    print_arr(arr, 10, 0);
    //quick_sort(arr, 0, 9);
    //quick_sort2(arr, 10);
    shell_sort(arr, 10);
    print_arr(arr, 10, 0);
}



int sort_main()
{
    test_sort();

    return 0;
}
