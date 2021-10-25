#include "sort.h"


int max_value(int *array, size_t size)
{
	size_t i = 0;
	int max_value = 0;

	while (i < size)
	{
		if (max_value < array[i])
			max_value = array[i];
		i++;
	}
	return (max_value);
}

void counting_sort(int *array, size_t size)
{
	int *count_array = NULL;
	int *new_array = NULL;
	int max = 0;
	int i = 0;
	if (size <= 1)
		return;
	max = max_value(array, size);
	count_array = malloc(sizeof(int) * (max + 1));
	if (!count_array)
		return;
	for (i = 0 ; i <= max ; i++)
		count_array[i] = 0;
	for (i = 0 ; i < (int)size ; i++)
		count_array[(array[i])] += 1;
	for (i = 0 ; i < max ; i++)
		count_array[i + 1] += count_array[i];
	print_array(count_array, max + 1);
	new_array = malloc(sizeof(int) * size);
	if (!new_array)
	{
		free(count_array);
		return;
	}
	for (i = 0 ; i < (int)size ; i++)
	{
		new_array[count_array[array[i]] - 1] += array[i];
		count_array[(array[i] - 1)] += 1;
	}
	for (i = 0 ; i < (int)size ; i++)
		array[i] = new_array[i];
	free(count_array);
	free(new_array);
}
