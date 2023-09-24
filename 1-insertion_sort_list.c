#include "sort.h"
/**
* insertion_sort_list - insertion sorting algorithm
* @list: linked list to sort
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *prev, *next;
	int swapped;

	if (!list || !(*list) || !(*list)->next)
		return;
	tmp = *list;
	while (tmp)
	{
		swapped = 0;
		while (tmp->next)
		{
			next = tmp->next;
			if (tmp->n > next->n)
			{
				prev = tmp->prev;
				tmp->next = next->next;
				tmp->prev = next;
				next->next = tmp;
				next->prev = prev;
				if (prev)
					prev->next = next;
				else
					*list = next;
				if (tmp->next)
					tmp->next->prev = tmp;
				print_list(*list);
				swapped = 1;
			}
			else
				tmp = tmp->next;
		}
		if (!swapped)
			break;
	}
}
