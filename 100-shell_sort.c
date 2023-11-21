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
 * shell_sort - sort an array in place
 * using the shell sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
size_t gap = 1, j_front;
int i_back, j_back, i_front;
if (array == NULL || size < 2)
return;
while (gap < size)
gap = gap * 3 + 1;
gap = (gap - 1) / 3;
for (; gap > 0; gap = (gap - 1) / 3)
{
i_front = 0;
j_front = i_front + gap;
while (j_front <= size - 1)
{
i_back = i_front;
j_back = j_front;
while (i_back >= 0)
{
if (array[j_back] < array[i_back])
swap(&array[j_back], &array[i_back]);
j_back = i_back;
i_back -= gap;
}
i_front++;
j_front++;
}
print_array(array, size);
}
}
