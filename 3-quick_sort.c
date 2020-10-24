#include "sort.h"

void quicksort(int *array, size_t size, int lo, int hi);
int partition(int *array, size_t size, int lo, int hi);
void swap(int *a, int *b, int *array, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the total len of the array
 *
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
	/*array, size, lo,  hi*/
	quicksort(array, size, 0, size - 1);
}

/**
 * quicksort - sorts an array of integers in ascending order
 *             using the Quick sort algorithm with Lamuto partition scheme
 * @array: the array to be sorted
 * @size: the total len of the array
 * @lo: the inferior limit of the subarray
 * @hi: the upper limit of the subarray
 *
 * Return: Void
 */
void quicksort(int *array, size_t size, int lo, int hi)
{
	int p;

	if (lo < hi)
	{
		// printf("low -> %d  - high -> %d\n", lo, hi);
		p = partition(array, size, lo, hi);
		// printf("P -> %d\n ", p);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * partition - lamuto partition scheme
 * @array: the array to be sorted
 * @size: the total len of the array
 * @lo: the inferior limit of the subarray
 * @hi: the upper limit of the subarray
 *
 * Return: int index where the partition occurs
 */
int partition(int *array, size_t size, int lo, int hi)
{
	int pivot = array[hi], i = lo, j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
				swap(array + i, array + j, array, size);
			i++;
		}
	}
	swap(array + i, array + hi, array, size);

	return (i);
}

/**
 * swap - swaps two elements of the array
 * @a: the first element to be swaped with @b
 * @b: the second element to be swaped with @a
 * @array: the array to be sorted
 * @size: the total len of the array
 *
 * Return: Void
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;

	print_array((const int *)array, size);
}
