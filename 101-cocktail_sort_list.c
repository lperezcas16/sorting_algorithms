#include "sort.h"
/**
 * _swap - Function to swap nodes
 * @tmp2: new temporal to swap
 * @tmp: temporal node
 * @list: doubly linked list
 *
 * Return - void
 */
void _swap(listint_t *tmp, listint_t *tmp2, listint_t **list)
{
	listint_t *left_node, *right_node;

	left_node = tmp->prev;
	right_node = tmp2->next;

	if (left_node != NULL)
		left_node->next = tmp2;
	else
		*list = tmp2;

	if (right_node != NULL)
		right_node->prev = tmp;

	tmp2->prev = left_node;
	tmp->next = right_node;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	print_list(*list);
}
/**
 * cocktail_sort_list - sorts a doubly linked list ascending order
 * @list: linked list
 *
 * Return - void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *aux;
	int swapp = 1;

	if (list == NULL || (*list)->next == NULL || *list == NULL)
		return;

	aux = *list;

	while (swapp)
	{
		swapp = 0;
		while (aux->next != NULL)
		{
			if (aux->n > aux->next->n)
			{
				_swap(aux, aux->next, list);
				++swapp;
				continue;
			}
			aux = aux->next;
		}
		aux = aux->prev;
		while (aux->prev != NULL)
		{
			if (aux->n < aux->prev->n)
			{
				_swap(aux->prev, aux, list);
				++swapp;
				continue;
			}
			aux = aux->prev;
		}
	}
}
