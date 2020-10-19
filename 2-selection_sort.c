#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minimum;
	int tmp;

	if (size < 2 || !array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minimum = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minimum])
				minimum = j;
		}
		if (minimum != i)
		{
			tmp = array[i];
			array[i] = array[minimum];
			array[minimum] = tmp;
			print_array(array, size);
		}
	}
}
