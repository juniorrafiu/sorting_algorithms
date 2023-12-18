#include "sort.h"

/**
 *top_down_merge - merge sort algorithm
 *@array: int array
 *@ini:  array size
 *@midd:  array size
 *@end:  array size
 *@dest: array pointer
 */

void top_down_merge(int *array, size_t ini, size_t midd, size_t end, int *dest)
{
	size_t i = ini, j = midd, k;

	for (k = ini; k < end; k++)
	{
		if (i < midd && (j >= end || array[i] <= array[j]))
		{
			dest[k] = array[i];
			i = i + 1;
		}
		else
		{
			dest[k] = array[j];
			j = j + 1;
		}
	}
}

/**
 *top_down_split - merge sort algorithm
 *@dest: array pointer
 *@ini:  array size
 *@end:  array size
 *@array: int array
 */

void top_down_split(int *dest, size_t ini, size_t end, int *array)
{
	size_t middle, i;

	if (end - ini < 2)
		return;
	middle = (end + ini) / 2;
	top_down_split(array, ini, middle, dest);
	top_down_split(array, middle, end, dest);
	top_down_merge(dest, ini, middle, end, array);
	printf("Merging...\n");
	printf("[left]: ");
	for (i = ini; i < middle; i++)
	{
		printf("%d", dest[i]);
		if (i < middle - 1)
			printf(", ");
	}
	printf("\n[right]: ");
	for (i = middle; i < end; i++)
	{
		printf("%d", dest[i]);
		if (i < end - 1)
			printf(", ");
	}
	printf("\n[Done]: ");
	for (i = ini; i < end; i++)
	{
		printf("%d", array[i]);
		if (i < end - 1)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 *copy - merge sort algorithm
 *@array: int array
 *@dest: destination array
 *@size: array size
 */

void copy(int *array, int *dest, size_t size)
{
	size_t pos = 0;

	for (pos = 0; pos < size; pos++)
	{
		dest[pos] = array[pos];
	}
}


/**
 *merge_sort - merge sort algorithm
 *@array: int array
 *@size: array size
 */

void merge_sort(int *array, size_t size)
{
	int *dest = malloc(sizeof(int) * size);

	copy(array, dest, size);
	top_down_split(dest, 0, size, array);
	free(dest);
}
