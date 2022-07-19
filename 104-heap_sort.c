#include "sort.h"

/**
 * swap_indcies - swaped 2 values.
 * @array: the array for swap him values.
 * @i: First index
 * @j: Second index
 * @n: The size constant for print
 */
void swap_indices(int *array, int i, int j, const int n)
{
	int tmp;
	(void) n;

	if (i != j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, (size_t)n);
	}
}

/**
 * heapify - Find the largest number between the layers
 * @array: The array for sort
 * @size: The menor element
 * @i: The largest.
 * @r_size: The size for print in swap
 * Return: Nothing.
 */
void heapify(int *array, size_t size, int i, const int n)
{
	int largest = i;
	int l = (2 * i) + 1;
	int r = (2 * i) + 2;

	if (l < (int)size && array[l] > array[largest])
		largest = l;

	if (r < (int)size && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		swap_indcies(array, i, largest, n);
		heapify(array, size, largest, n);
	}
}

/**
 * heap_sort - Call largest while exist layers
 * @array: The array that generate the layers
 * @size: Size of the array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	const int n = (const int)size;
	int i;

	if (size < 2 || !array)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, n);

	for (i = size - 1; i >= 0; i--)
	{
		swap_indicies(array, 0, i, n);
		heapify(array, i, 0, n);
	}
}
