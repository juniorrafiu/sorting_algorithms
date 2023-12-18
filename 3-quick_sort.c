#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Return: Sorts the array in ascending order after each swap.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;
	int part;

	if (right - left > 0)
	{
		pivot = array + right;
		for (above = below = left; below < right; below++)
		{
			if (array[below] < *pivot)
			{
				if (above < below)
				{
					swap_ints(array + below,
							array + above);
					print_array(array, size);
				}
				above++;
			}
		}
		if (array[above] > *pivot)
		{
			swap_ints(array + above, pivot);
			print_array(array, size);
		}
		part = above;
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: prints sorted array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
