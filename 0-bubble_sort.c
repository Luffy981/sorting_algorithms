#include "sort.h"
/**
 * bubble_sort - Sort array
 * @array: Array to sort
 * @size: Size
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int *vodka = NULL;
	int *ron = NULL;
	int flag = 0;
	int tmp;

	if (sizeof(array) == 0 || size <=1)
		return;

	for (i = 0 ; i < size - 1 ; i++)
	{
		flag = 0;
		for (j = 0 ; j < size - i - 1 ; j++)
		{
			vodka = &array[j];
			ron = &array[j + 1];
			if (*vodka > *ron)
			{
				tmp = *vodka;
				*vodka = *ron;
				*ron = tmp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}

}
