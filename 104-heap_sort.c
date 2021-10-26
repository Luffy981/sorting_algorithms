#include "sort.h"

void max_heapify(int *array, size_t size, size_t i)
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
		print_array(array, size);
		max_heapify(array, size, largest);
	}

}

void heap_sort(int *array, size_t size)
{
	int i;
	int tmp;

	if (size <= 1 || !array)
		return;
	for (i = (size / 2) - 1 ; i >= 0; i--)
	{
		max_heapify(array, size, i);
	}
	for (i = size - 1 ; i >= 0 ; i--)
	{
		if (i != 0)
		{
			tmp = array[1];
			array[1] = array[i];
			array[i] = tmp;
			print_array(array, size);
			max_heapify(array, size, 1);
		}

	}
}
