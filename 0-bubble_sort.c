#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

/**
 * bubble_sort - a function that sorts an array using bubble sort
 * @array: the array to be sorted
 * @size: size of the data to be sorted
 * Return: sorted array items
 */
void bubble_sort(int *array, size_t size)
{
	int y;
	size_t x;
	bool sorted = false;

	if (array == NULL || size < 2)
		return;

	while (sorted == false)
	{
		sorted = true;

		for (x = 0; x < (size - 1); x++)
		{
			if (array[x] > array[x + 1])
			{
				y = array[x];
				array[x] = array[x + 1];
				array[x + 1] = y;
				print_array(array, size);
				sorted = false;
			}
		}
	}
}
