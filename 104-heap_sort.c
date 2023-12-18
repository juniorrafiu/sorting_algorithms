#include "sort.h"

/**
  * swap_s - swap 2 elements of a list
  * @array: array
  * @i: index
  * @j: j
  * @size: size
  * Return: nothing
  */

void swap_s(int *array, int i, int j, int size)
{
	int copy_num = 0;

	copy_num = array[i];
	array[i] = array[j];
	array[j] = copy_num;
	print_array(array, size);
}

/**
  * heaphy - selection sort
  * @array: array
  * @si: si
  * @bin: bin
  * @size: size
  * Return: nothing
  */

void heaphy(int *array, int si, int bin, int size)
{
	int largt = bin, left = (bin * 2) + 1, rigth = (bin * 2) + 2;

	if (left < si && array[left] > array[largt])
		largt = left;

	if (rigth < si && array[rigth] > array[largt])
		largt = rigth;

	if (largt != bin)
	{
		swap_s(array, bin, largt, size);
		heaphy(array, si, largt, size);
	}
}

/**
  * heap_sort - selection sort
  * @array: array
  * @size: size
  * Return: nothing
  */

void heap_sort(int *array, size_t size)
{
	int bin = 0, si = size;

	for (bin = (size / 2) - 1; bin >= 0; bin--)
		heaphy(array, si, bin, size);

	for (bin = size - 1; bin >= 0; bin--)
	{
		if (bin != 0)
			swap_s(array, bin, 0, size);
		heaphy(array, bin, 0, size);
	}
}
