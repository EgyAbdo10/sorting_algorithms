#include <stdio.h>


void merge_sort(int *arr, int n);
void split_arr(int *arr, int l, int r);
void merge(int *arr, int l, int r, int m);

/**
 * merge_sort - get the array sorted
 * @arr: a pointer to the first element to the array
 * @n: number of elements of the array
 */
void merge_sort(int *arr, int n)
{
    split_arr(arr, 0, n - 1);
}

void split_arr(int *arr, int l, int r)
{
    int m = l + (r - l) / 2;
    if (l < r)
    {   
        split_arr(arr, l, m); // for the left part of the array
        split_arr(arr, m + 1, r); // for the right part of the array
        merge(arr, l, r, m);
    }
}

void merge(int *arr, int l, int r, int m)
{
    int left_length = m - l + 1;
    int right_length = r - m;

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;

    for (i = 0; i < left_length; i++)
        temp_left[i] = arr[l + i];
    for (j = 0; j < right_length; j++)
        temp_right[j] = arr[m + 1 + j];
        
    i = 0, j = 0, k = l;

    while (i < left_length && j < right_length)
    {
        if (temp_left[i] <= temp_right[j])
            arr[k++] = temp_left[i++];
        else
            arr[k++] = temp_right[j++];
    }

    while (i < left_length)
        arr[k++] = temp_left[i++];
    while (j < right_length)
        arr[k++] = temp_right[j++]; 

//     for (i = 0, j = 0, k = l; k <= (r); k++)
//         {
//             if ((i < left_length) &&
//                (j >= right_length || temp_left[i] <= temp_right[j]))
//             {
//                 arr[k] = temp_left[i];
//                 i++;
//             }
//             else
//             {
//                 arr[k] = temp_right[j];
//                 j++;
//             }
//         }   

}

void print_arr(int *arr, int n)
{
    int i = 0;
    for (; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int nums[] = {3,2, 1, 7, 0};
    printf("array before sorting\n");
    print_arr(nums, 5);
    printf("array after sorting\n");
    merge_sort(nums, 5);
    print_arr(nums, 5);
    return (0);
}
