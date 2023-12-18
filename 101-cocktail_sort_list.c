#include "sort.h"

/**
 *swap - sort list using insertion algorithm
 *@list: list to be sorted
 *@top: current node
 *Return: pointer to the swapped position
 */

listint_t *swap(listint_t **list, listint_t *top)
{
	listint_t *next = top->next, *prev = top->prev;

	if (prev)
		prev->next = next;
	if (next)
	{
		next->prev = prev;
		top->next = next->next;
		if (next->next)
			next->next->prev = top;
		next->next = top;
		top->prev = next;
	}
	if (!next->prev)
		*list = next;
	(void) list;
	return (next);
}

/**
 *sort_back - sort list using insertion algorithm
 *@list: list to be sorted
 *@top: flag
 *@flag: flag
 *Return: state
 */

int sort_back(listint_t **list, listint_t *top, int *flag)
{
	/* printf("back\n"); */
	while (top)
	{
		if (top->prev)
		{
			if (top->n < top->prev->n)
			{
				*flag = 0;
				top = swap(list, top->prev)->next;
				print_list(*list);
			}
		}
		if (top)
			top = top->prev;
		else
			break;

	}
	return (*flag);
	(void) list;
}


/**
 *sort_fow - sort list using insertion algorithm
 *@list: list to be sorted
 *@flag: flag
 *Return: state
 */

int sort_fow(listint_t **list, int flag)
{
	listint_t *top = *list, *back;
	/* printf("fow\n"); */
	while (top)
	{
		if (top->next)
		{
			if (top->n > top->next->n)
			{
				flag = 0;
				top = swap(list, top);
				print_list(*list);
			}
		}
		else
		{
			back = top;
			break;
		}
		if (top)
			top = top->next;
		else
			break;
	}
	flag = sort_back(list, back, &flag);
	return (flag);
}


/**
 *cocktail_sort_list - sort list using insertion algorithm
 *@list: list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	int flag = 0;

	if (!list || !(*list) || !(*list)->next)
		return;
	while (flag == 0)
	{
		flag = 1;
		flag = sort_fow(list, flag);
	}
}
