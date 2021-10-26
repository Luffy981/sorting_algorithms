#include "sort.h"
int partition(int *A, int start, int end, size_t size)
{
	int *pivot = &A[end];
	int part_idx = start;
	int i;
	int tmp;
	int *ptr1 = NULL;
	int *ptr2 = NULL;

	for (i = start ; i < end ; i++)
	{
		ptr1 = &A[i];
		ptr2 = &A[part_idx];
		if (*ptr1 <= *pivot)
		{
			tmp = *ptr1;
			*ptr1 = *ptr2;
			*ptr2 = tmp;
			print_array(A, size);
			part_idx++;

		}
		ptr2 = &A[part_idx];
	}
	tmp = *ptr2;
	*ptr2  = *pivot;
	*pivot = tmp;
	print_array(A, size);
	return (part_idx);
}

void quick(int *array, int start, int end, size_t size)
{

	int part_idx;

	if (start < end)
	{
		part_idx = partition(array, start, end, size);
		quick(array, start, part_idx - 1, size);
		quick(array, part_idx + 1, end, size);
	}
}
void quick_sort(int *array, size_t size)
{
	quick(array, 0, size - 1, size);
}

