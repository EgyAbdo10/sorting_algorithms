#include "sort.h"

void merge_sort_recursive(int *array, int l, int r);
void merge(int *array, int l, int m, int r);

void print_process(int *array, int l, int m, int r)
{
    printf("merging...\n[left]: ");
    print_array(array + l, (m - l));

    printf("[right]: ");
    print_array(array + m, (r - m + 1));

    printf("[Done]: ");
    print_array(array + l, (r - l + 1));
}

void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
    return;
    merge_sort_recursive(array, 0, size - 1);
}

void merge_sort_recursive(int *array, int l, int r)
{
    int m = r - (r - l) / 2;
    if (l < r)
    {
        merge_sort_recursive(array, l, m - 1);
        merge_sort_recursive(array, m, r);
        merge(array, l, m, r);
        print_process(array, l, m, r);
    }
}

void merge(int *array, int l, int m, int r)
{
    int left_length = m - l, right_length = r - m + 1;
    int *temp = malloc(sizeof(int) * (r - l + 1));
    int i, j, k = l;

    for (i = 0; i < left_length + right_length; i++)
    temp[i] = array[l + i];

    i = 0, j = (m - l);
    while (i < left_length && j < left_length + right_length)
    {
        if (temp[i] < temp[j])
        array[k++] = temp[i++];
        else
        array[k++] = temp[j++];
    }
    while (i < left_length)
    array[k++] = temp[i++];

    while (j < left_length + right_length)
    array[k++] = temp[j++];
    free(temp);
}
