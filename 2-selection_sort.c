#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *a, int *b);

/**
 * selection_sort -  sorts an array of integers in ascending order
 * @array: the array to be sorted
 * @size: length of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y;
	int *z;

	if (array == NULL || size < 2)
		return;
	for (x = 0; x < size - 1; x++)
	{
		z = array + x;
		for (y = x + 1; y < size; y++)
			z = (array[y] < *z) ? (array + y) : z;
		if ((array + x) != z)
		{
			swap(array + x, z);
			print_array(array, size);
		}
	}
}
/**
 * swap - used to alternate values
 * @a: first value to alternate
 * @b: second value to alternate
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
