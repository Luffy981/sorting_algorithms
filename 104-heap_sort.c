#include "sort.h"

void max_heapify(int *array, size_t size, size_t i, size_t print_size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = (2 * i) + 2;
	int tmp;

	while (left < (int)size && array[left] > array[largest])
	{
		largest = left;
	}
	while (right < (int)size && array[right] > array[largest])
	{
		largest = right;
	}
	if (largest != (int)i)
	{
		tmp = array[largest];
		array[largest] = array[i];
		array[i] = tmp;
		print_array(array, print_size);
		max_heapify(array, size, largest, print_size);
	}

}

void heap_sort(int *array, size_t size)
{
	int i;
	int tmp;
	size_t print_size = size;

	if (size <= 1 || !array)
		return;
	for (i = (size / 2) - 1 ; i >= 0; i--)
	{
		max_heapify(array, size, i, print_size);
	}
	for (i = size - 1 ; i >= 0 ; i--)
	{
		if (i != 0)
		{
			tmp = array[0];
			array[0] = array[i];
			array[i] = tmp;
			print_array(array, print_size);
			max_heapify(array, i, 0, print_size);
		}

	}
}
