#include "push_swap.h"

void    merge_arrays(int *arr, int left, int right, int middle)
{
    int *left_arr;
    int *right_arr;
    int side1;
    int side2;
    int first_sub_arr;
    int second_sub_arr;
    int merged_arr;

    side1 = middle - left + 1;
    side2 = right - middle;
    first_sub_arr = 0;
    second_sub_arr = 0;

    while (first_sub_arr < side1)
    {
        left_arr[first_sub_arr] = arr[left + first_sub_arr];
        first_sub_arr++;
    }
    while (second_sub_arr < side2)
    {
        right_arr[second_sub_arr] = arr[middle + 1 + second_sub_arr];
        second_sub_arr++;
    }
    first_sub_arr = 0; //index primeiro subarray
    second_sub_arr = 0; //index segundo subarray
    merged_arr = left; //index  merged array
    while (first_sub_arr < side1 && second_sub_arr < side2)
    {
        if (left_arr[first_sub_arr]<= right_arr[second_sub_arr])
        {
            arr[merged_arr] = left_arr[first_sub_arr];
            first_sub_arr++;
        }
        else
        {
            arr[merged_arr] = right_arr[second_sub_arr];
            second_sub_arr++; 
        }
        merged_arr++;
    }
    while (first_sub_arr < side1)
    {
        arr[merged_arr] = left_arr[first_sub_arr];
        first_sub_arr++;
        merged_arr++;
    }
    while (second_sub_arr < side2)
    {
        arr[merged_arr] = right_arr[second_sub_arr];
        second_sub_arr++;
        merged_arr++;
    }
}

void    merge_sort(int *arr, int left, int right) //algorithm
{
    int middle;

    if (left > right)
        return ;
    if (left < right)
    {
        middle = (left + right) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}