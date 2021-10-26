#include "sort.h"

void shell_sort(int *array, size_t size)
{
	size_t gap;
	int i;
	size_t j;
	int tmp;
	if (size <= 1)
		return;
	while ((3 * gap + 1) <= size)
		gap = gap * 3 + 1;

	for (; gap >= 1 ; gap = (gap - 1) / 3)
	{
		for (j = gap ; j < size ; j++)
		{
			for (i = j ; i >= (int)gap  ; i = i - gap)
			{
				if (array[i - gap] < array[i])
				{
					tmp = array[i];
					array[i] = array[i - gap];
					array[i - gap] = tmp;
				}
				else
					break;
			}
		}
		print_array(array, size);
	}
}
