#include "sort.h"

void shell_sort(int *array, size_t size)
{
	size_t gap;
	int i;
	size_t j;
	int tmp;

	for (gap = size / 2 ; gap >= 1 ; gap = gap / 2)
	{
		for (j = gap ; j < size ; j++)
		{
			for (i = j - gap ; i >= 0; i = i - gap)
			{
				if (array[i + gap] < array[i])
				{
					tmp = array[i];
					array[i] = array[i + gap];
					array[i + gap] = tmp;
				}
				else
					break;
			}
		}
		print_array(array, size);
	}
}
