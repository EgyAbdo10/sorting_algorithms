#include "sort.h"

/**
 * swap_int - swap two numbers
 * @num1: the first number
 * @num2: the second number
 */
void swap_int(int *num1, int *num2)
{
int temp = *num1;
*num1 = *num2;
*num2 = temp;
}

/**
 * bubble_sort - sort an array in place
 * using the bubble sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int swapped = 0;
if (size < 2)
return;
if (array == NULL)
return;
for (i = 0; i < size - 1; i++)
{
for (j = 0; j < size - 1 - i; j++)
{
if (array[j] > array[j + 1])
{
swap_int(&array[j], &array[j + 1]);
swapped = 1;
print_array(array, size);
}
}
if (swapped == 0)
break;
}
}
