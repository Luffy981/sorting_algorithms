#include "sort.h"
/**
 * merger - Merger
 * @arr: Array
 * @left: Left
 * @right: Right
 * @s_left: Size of left
 * @s_right: Size of right
 *
 * Return: Nothing
 */
void merger(int *arr, int  *left, int *right, int s_left, int s_right)
{
	int *ptr3 = arr, *ptr1 = left, *ptr2 = right;
	int i = 0, j = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, s_left);
	printf("[right]: ");
	print_array(right, s_right);
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
	printf("[Done]: ");
	print_array(arr, s_left + s_right);
}

/**
 * merge_sort - Merge sort
 * @array: Array
 * @size: Size
 *
 * Return: Nothing
 */
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
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merger(array, left, right, mid, size - mid);
	free(left);
	free(right);
}
