#include <stdio.h>
#include <stdlib.h>
void print_array(int *arr, int n);

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void shell_sort(int *array, int size)
{
    int i_front, j_front, i_back, j_back, gap;
    for (gap = size / 2; gap > 0; gap /= 2)
    {
        i_front = 0;
        j_front = i_front + gap;
        while (j_front <= size - 1)
        {
            j_back = j_front;
            i_back = i_front;
            while (array[j_back] < array[i_back] && i_back >= 0)
            {
                swap(&array[j_back], &array[i_back]);
                print_array(array, size);
                j_back = i_back;
                i_back = j_back - gap;
            }
            i_front++;
            j_front++;
        }
    }
}

// void shell_sort(int *array, int size)
// {
//     int i, j, gap, temp;
//     for (gap = size / 2; gap > 0; gap /= 2)
//     {
//         for (i = gap; i < size; i++)
//         {
//             temp = array[i];
//             for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
//             {
//                 array[j] = array[j - gap];
//             }
//             array[j] = temp;
//         }
//     }
// }


void print_array(int *arr, int n)
{
    int i = 0;
    for (; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    shell_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
