#include "sort.h"
void merger(int *arr, int  *left, int *right, int s_left, int s_right)
{
	int *ptr3 = arr;
	int *ptr1 = left;
	int *ptr2 = right;
	int i = 0;
	int j = 0;
	while (i < s_left && j < s_right)
	{
		if (*ptr1 <= *ptr2)
		{
			*ptr3 = *ptr1;
			ptr1++;
			i++;
		}
		else
		{
			*ptr3 = *ptr2;
			ptr2++;
			j++;
		}
		ptr3++;
	}
	while (i < s_left)
	{
		*ptr3 = *ptr1;
		ptr1++;
		ptr3++;
		i++;
	}
	while (j < s_right)
	{
		*ptr3 = *ptr2;
		ptr2++;
		ptr3++;
		j++;
	}
}

void merge_sort(int *array, size_t size)
{
	int mid = size / 2;
	int *left = NULL;
	int *right = NULL;
	int i;

	if (size < 2)
		return;
	left = calloc(mid, sizeof(int));
	right = calloc(size - mid, sizeof(int));

	for (i = 0 ; i < mid ; i++)
	{
		left[i] = array[i];
	}
	for (i = mid ; i < (int)size ; i++)
	{
		right[i - mid] = array[i];
	}
	print_array(array, size);
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merger(array, left, right, mid, size - mid);
	free(left);
	free(right);
}
