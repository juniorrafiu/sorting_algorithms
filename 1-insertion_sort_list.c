#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * insertion_sort_list - sorts a list in ascending order using insertion.
 * @list: the linked list in question.
 * Return: sorted list in ascending order.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;

		while (insert != NULL && iter->n < insert->n)
		{
			iter->next = insert;
			iter->prev = insert->prev;
			if (insert->prev)
				insert->prev->next = iter;
			else
				*list = iter;
			insert->prev = iter;
			insert->next = tmp;
			if (tmp)
				tmp->prev = insert;
			print_list((const listint_t *)*list);
			insert = iter->prev;
		}
	}
}
