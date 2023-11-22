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

void print_array(const int *array, size_t size)
{
size_t i;

i = 0;
while (array && i < size)
{
if (i > 0)
printf(", ");
printf("%d", array[i]);
++i;
}
printf("\n");
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
    int temp_left[left_length], temp_right[right_length];
    int i, j, k = l;

    for (i = 0; i < left_length; i++)
    temp_left[i] = array[i + l];

    for (j = 0; j < right_length; j++)
    temp_right[j] = array[m + j];

    i = 0, j = 0;
    while (i < left_length && j < right_length)
    {
        if (temp_left[i] < temp_right[j])
        array[k++] = temp_left[i++];
        else
        array[k++] = temp_right[j++];
    }
    while (i < left_length)
    array[k++] = temp_left[i++];

    while (j < right_length)
    array[k++] = temp_right[j++];
    
}


int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    merge_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
