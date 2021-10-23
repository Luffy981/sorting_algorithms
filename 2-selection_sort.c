#include "sort.h"

void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	int tmp;
	size_t j = 0;
	int *vodka = NULL;
	int *ron = NULL;
	int min_idx = 0;

	for (i = 0 ; i < size - 1 ; i++)
	{
		min_idx = i;
		vodka = &array[i];
		for (j = i + 1 ; j < size ; j++)
		{
			ron = &array[j];
			if (*ron < *vodka)
			{
				min_idx = j;
				vodka = &array[min_idx];
			}
		}
		vodka = &array[i];
		ron = &array[min_idx];
		tmp = *vodka;
		*vodka = *ron;
		*ron = tmp;
		print_array(array, size);
	}
}
