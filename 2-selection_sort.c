#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j = 0;
	int minimum = 0, tmp = 0;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minimum = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minimum])
				minimum = j;
		}
		if (tmp != minimum)
		{
			tmp = array[minimum];
			array[minimum] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
