#include "sort.h"

/**
 * partition - index for quicksort
 * @array: array
 * @left: index of left element
 * @right: index of right element
 * @size: array size
 * Return: index
 */

int partition(int *array, int left, int right, size_t size)
{
	int tmp, pivot = array[right];
	size_t i, j;

	i = left - 1;
	j = right + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (i);
		if (i != j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	return (0);
}

/**
 * quick_recursion - function for quicksort
 * @array: array
 * @left: index of left element
 * @right: index of right element
 * @size: array size
 */

void quick_recursion(int *array, int left, int right, size_t size)
{
	int piv;

	if (left < right)
	{
		piv = partition(array, left, right, size);
		quick_recursion(array, left, piv - 1, size);
		quick_recursion(array, piv, right, size);
	}
}

/**
 * quick_sort_hoare - sort array using quicksort algorithm
 * @array: int array
 * @size: array size
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_recursion(array, 0, (int)size - 1, size);
}
