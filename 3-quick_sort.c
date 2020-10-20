#include "sort.h"
/**
 * swap - Function for swap
 * @array: Array of integers
 * @i: first element of array
 * @j: Last element of array
 * @size: Size of array
 * Return: void
 */
void swap(int *array, int i, int j, int size)
{
	int aux;

	if (array[i] == array[j])
		return;
	aux = array[i];
	array[i] = array[j];
	array[j] = aux;
	print_array(array, size);
}
/**
 * partition - Partition
 * @array: Array of integers
 * @first: first element of array
 * @last: Last element of array
 * @size: Size of array
 * Return: int (split)
 */
int partition(int *array, int first, int last, int size)
{
	int pivot = array[last];
	int split = first, idx;

	for (idx = first; idx < last; idx++)
		if (array[idx] < pivot)
			swap(array, split++, idx, size);
	swap(array, split, last, size);
	return (split);
}
/**
 * recursive - Function for recurtion
 * @array: Array of integers
 * @first: first element of array
 * @last: Last element of array
 * @size: Size of array
 * Return: void
 */
void recursive(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);

		recursive(array, first, pivot - 1, size);
		recursive(array, pivot + 1, last, size);
	}
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
	recursive(array, 0, size - 1, size);
}
