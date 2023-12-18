#include "sort.h"

/**
  * swap_s - swap 2 elements of a list
  * @array: array
  * @i: index
  * @j: j
  * Return: nothing
  */

void swap_s(int *array, int i, int j)
{
	int copy_num = 0;

	copy_num = array[i];
	array[i] = array[j];
	array[j] = copy_num;
}

/**
  * shell_sort - selection sort
  * @array: array
  * @size: size
  * Return: nothing
  */

void shell_sort(int *array, size_t size)
{
	int gap = 1, i = 0, j = 0, si = size;

	if (array == NULL || size < 2)
		return;

	while (gap < si / 3)
		gap = (gap * 3) + 1;

	while (gap > 0)
	{
		for (i = gap; i < si; i++)
			for (j = i; j > 0 && array[j] < array[j - gap]; j -= gap)
			{
				swap_s(array, j, j - gap);
				if (j - gap - gap < 0)
					break;
			}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
