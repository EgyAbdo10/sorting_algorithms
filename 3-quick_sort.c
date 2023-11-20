#include "sort.h"

/**
 * swap- swap two numbers
 * @num1: the address of the first number
 * @num2: the address of the second number
 */
void swap(int *num1, int *num2)
{
int temp = *num1;
*num1 = *num2;
*num2 = temp;
}

/**
 * quick_sort_recursive - sort an array in place
 * using the quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * @f_idx: the first element index of teh array
 * @l_idx: the last element index of teh array
 */
void quick_sort_recursive(int *array, size_t size, int f_idx, int l_idx)
{
int i, j, p_idx = l_idx;
if (f_idx < l_idx)
{
for (i = f_idx - 1, j = f_idx; j < l_idx; j++)
{
if (array[j] < array[p_idx])
{
i++;
if (j != i)
{
swap(&array[j], &array[i]);
print_array(array, size);
}
}
}
i++;
if (array[i] != array[p_idx])
{
swap(&array[i], &array[p_idx]);
print_array(array, size);
p_idx = i;
}
quick_sort_recursive(array, size, f_idx, p_idx - 1);
quick_sort_recursive(array, size, p_idx + 1, l_idx);
}
}

/**
 * quick_sort - call the function quick_sort_recursive
 * to sort an array using the quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quick_sort_recursive(array, size, 0, size - 1);
}

