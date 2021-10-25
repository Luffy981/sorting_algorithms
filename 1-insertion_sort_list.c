#include "sort.h"

/**
 * insertion_sort_list - Sort doubly linked list
 * @list: Doubly linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL;
	listint_t *back_head = NULL;
	listint_t *tmp = NULL;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;
	head = *list;
	head = head->next;
	while (head)
	{
		back_head = head->prev;
		if (back_head->n > head->n)
		{
			swap_nodes(&back_head, &head, list);
			print_list(*list);
			while (back_head->prev)
			{
				if ((back_head->n) < (back_head->prev->n))
				{
					tmp = back_head->prev;
					swap_nodes(&tmp, &back_head, list);
					print_list(*list);
				}
				back_head = back_head->prev;
			}
		}
		head = head->next;
	}
}

/**
 * swap_nodes - Swap nodes
 * @turtle: List 1
 * @rabbit: List 2
 * @list: List
 *
 * Return: Nothing
 */
void swap_nodes(listint_t **turtle, listint_t **rabbit, listint_t **list)
{
	listint_t *before;
	listint_t *after;

	if (!(*turtle) || !(*rabbit))
		return;
	before = (*turtle)->prev;
	after = (*rabbit)->next;

	if (before)
		before->next = (*rabbit);
	(*rabbit)->prev = before;
	(*rabbit)->next = (*turtle);
	(*turtle)->prev = (*rabbit);
	(*turtle)->next = after;

	if (after)
		after->prev = (*turtle);
	*turtle = *rabbit;
	*rabbit = (*turtle)->next;

	if (!before)
		*list = *turtle;
}
