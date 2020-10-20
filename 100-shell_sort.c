#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: Array of integers
 * @size: Size of the array
 * Return - void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, gap = 1, j;
	int temp; /*Temporal variable for save number for swap*/

	if (!array || size < 2)
		return;

	if (gap <= size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (i = gap; i < size; i += 1)
			{
				temp = array[i];
				for (j = i; j >= gap && array[j - gap]
					> temp; j -= gap)
				array[j] = array[j - gap];
				array[j] = temp;
			}
		}
		print_array(array, size), gap = (gap - 1) / 3;
	}
}

