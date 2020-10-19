#include "sort.h"
/**
 * partition - Partition
 * 
 */
size_t partition(int *array, size_t first, size_t last)
{
	size_t pivot;
	size_t i, aux;

	if (first < last)
	{
		pivot = array[first];
		for (i = pivot + 1; array[i]; i++)
		{
			if (pivot < array[i])
			{
				aux = pivot;
				pivot = array[i];
				array[i] = aux;
			}
		}
	}
	return (pivot);
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 * 
 * Return - void
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot;

	if (!array || size < 2)
		return;

	pivot = partition(array, 0, size - 1);

	quick_sort(array, pivot - 1);
	quick_sort(array, pivot + 1);
}
