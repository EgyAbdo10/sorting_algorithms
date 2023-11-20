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
 * selection_sort - sort an array in place
 * using the selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
size_t i, j;
size_t smallest_idx;
for (i = 0; i < size - 1; i++)
{
smallest_idx = i;
for (j = i + 1; j < size; j++)
{
if (array[j] < array[smallest_idx])
smallest_idx = j;
}
if (i != smallest_idx)
{
swap(&array[i], &array[smallest_idx]);
print_array(array, size);
}
}
}
