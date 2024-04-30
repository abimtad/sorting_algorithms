#include "sort.h"

/**
 * swap_nums - Swapping two given number inside an array
 *
 * @num_one: fist number to swap
 * @num_two: the second number to swap
 */

void swap_nums(int *num_one, int *num_two)
{
	int tmp;

	tmp = *num_one;
	*num_one = *num_two;
	*num_two = tmp;
}
/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: The array to sort
 * @size: The size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, len = size;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_nums(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
