#include "sort.h"



void insertion_sort_list(listint_t **list)
{

	listint_t *node = *list;
	listint_t *hole = *list;
	listint_t *save1 = NULL;
	listint_t *save2 = NULL;
	int tmp;

	node = *list;
	for (node = node->next ; node ; )
	{
		save1 = hole;
		save2 = node;
		tmp = hole->n;
		while (hole && hole->n > node->n)
		{
			print_list(*list);
			tmp = hole->n;
			hole->n = node->n;
			node->n = tmp;
			if (hole->prev)
				hole = hole->prev;
			node = node->prev;
			tmp = node->n;
		}
		hole = save1;
		node = save2;
		hole = hole->next;
		node = node->next;
	}
}
