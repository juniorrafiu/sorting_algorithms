#include "sort.h"

/**
  * counting_sort - selection sort
  * @array: array
  * @size: size
  * Return: nothing
  */

void counting_sort(int *array, size_t size)
{
	int *counter = NULL, *c_a = NULL;
	int max_num = -1, i = 0, si = size, num = 0;

	if (array == NULL || size < 2)
		return;

	c_a = malloc(sizeof(int) * size);
	if (!c_a)
		return;

	for (i = 0; i < si; i++)
	{
		c_a[i] = array[i];
		if (array[i] > max_num)
			max_num = array[i];
	}
	counter = malloc(sizeof(int) * (max_num + 1));
	if (!counter)
	{
		free(c_a);
		return;
	}
	for (i = 0; i < si; i++)
		counter[array[i]] += 1;

	for (i = 0; i < max_num + 1; i++)
		if (i - 1 >= 0)
			counter[i] += counter[i - 1];

	print_array(counter, max_num + 1);

	for (i = 0; i < si; i++)
	{
		num = counter[c_a[i]] - 1;
		array[num] = c_a[i];
		counter[c_a[i]] -= 1;
	}

	free(c_a);
	free(counter);
}
