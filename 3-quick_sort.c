#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @x: Pointer to the first integer
 * @y: Pointer to the second integer
 *
 * Description: This function swaps the values of two integers.
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - Partitions an array around a pivot element
 *
 * @array: Pointer to the array to be partitioned
 * @size: Size of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot element after partitioning
 *
 * Description: This function partitions an array around a pivot element,
 * placing all elements less than or equal to the pivot to its left, and
 * all elements greater than the pivot to its right.
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot_value = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			if (i < j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > pivot_value)
	{
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort_recursion - Sorts an array of integers using the -
 * QuickSort algorithm recursively
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 *
 * Description: This function sorts a partition of an integer array-
 * in ascending order using the QuickSort algorithm recursively. It -
 * selects a pivot element, partitions the array around the pivot, and -
 * recursively sorts the sub-arrays before and after the pivot.
 */
void quicksort_recursion(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot_index = partition(array, size, low, high);

		quicksort_recursion(array, size, low, pivot_index - 1);
		quicksort_recursion(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - sort a given array using quick sort algorithm.
 *
 * @array: the to array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recursion(array, size, 0, size - 1);
}
