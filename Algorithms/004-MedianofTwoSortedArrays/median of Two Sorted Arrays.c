//
// Created by zyc on 3/29/19.
//
/* 4. Median of Two Sorted Arrays
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.

    Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

    You may assume nums1 and nums2 cannot be both empty.

    Example 1:

    nums1 = [1, 3]
    nums2 = [2]

    The median is 2.0
    Example 2:

    nums1 = [1, 2]
    nums2 = [3, 4]

    The median is (2 + 3)/2 = 2.5
 *
 */
#include "median of Two Sorted Arrays.h"



/*
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    if(nums1Size < 1)
    {
        if(nums2Size % 2)
            return (nums2[nums2Size / 2] / 1.0);
        else
            return ((nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0);
    }

    if(nums2Size < 1)
    {
        if(nums1Size % 2)
            return (nums1[nums1Size / 2] / 1.0);
        else
            return ((nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2.0);
    }

    int i, m = 0, n = 0, len = nums1Size + nums2Size;
    int nums[len];

    memset(nums, 0, len * sizeof(int));

    for(i = 0; i < len; i++)
    {
        if(m < nums1Size && n < nums2Size)
        {
            if(nums1[m] < nums2[n])
                nums[i] = nums1[m++];
            else
                nums[i] = nums2[n++];
        }
        else if(m < nums1Size)
        {
            nums[i] = nums1[m++];
        }
        else if(n < nums2Size)
        {
            nums[i] = nums2[n++];
        }
        //printf("%d ", nums[i]);
    }

    if((nums1Size + nums2Size) % 2)
        return ((double)nums[len / 2] / 1.0);
    else
        return ((((double)nums[(len / 2 - 1)] + (double)nums[len / 2])) / 2.0);

    return 0.0;
}
*/

double get_k_th(int *nums1, int nums1Size, int* nums2, int nums2Size, int k)
{
    if(nums1Size > nums2Size)
        return get_k_th(nums2, nums2Size, nums1, nums1Size,k);

    if(nums1Size == 0)
        return nums2[k - 1];

    if(k == 1)
        return nums1[0] < nums2[0] ? nums1[0] : nums2[0];


    int i = k / 2, j = k / 2;

    if(i > nums1Size)
        i = nums1Size;
    if(j > nums2Size)
        j = nums2Size;

    if(nums1[i - 1] > nums2[j - 1])
        return get_k_th(nums1, nums1Size, nums2 + j, nums2Size - j, k - j);
    else
        return get_k_th(nums1 + i, nums1Size - i, nums2, nums2Size, k - i);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int k = nums1Size + nums2Size;
    int l = (k - 1)/2;
    int r = k / 2;

    return 0.5 * (get_k_th(nums1, nums1Size, nums2, nums2Size, l + 1) + get_k_th(nums1, nums1Size, nums2, nums2Size, r + 1));
}

int findMedianSortedArrays_main()
{

    return 0;
}