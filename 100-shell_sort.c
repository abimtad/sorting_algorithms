#include "sort.h"

/**
 * swap_ints - Swap two integers in an arr.
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort the arr using shell sort algorithm
 * @arr: the array to be sorted
 * @size: The size of the arr
 */

void shell_sort(int *arr, size_t size)
{
	size_t h = 1, j, i;

	if (arr == NULL || size < 2)
		return;

	while (h < size / 3)
	{
		h =  3 * h + 1;
	}

	while (h > 0)
	{
		for (i = h; i < size; i++)
		{
			j = i;
			while (j >= h && arr[j - h] > array[j])
			{
				swap_ints(arr + j, array + (j - h));
				j -= h;
			}
		}
		print_arr(array, size);

		h = h / 3;
	}
}
