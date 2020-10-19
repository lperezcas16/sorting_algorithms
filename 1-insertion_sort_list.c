#include "sort.h"
/**
 * init - Head node of a linked list
 * @tmp: node in linked list
 *
 * Return: Head of linked list
 */
listint_t *init(listint_t *tmp)
{
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}
/**
 * insertion_sort_list - sorts an array of integers in ascending order
 * @list: list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux_node = NULL, *tmp, *aux;

	if (!list)
	{
		return;
	}
	aux_node = init(*list);

	for (aux_node = aux_node->next; aux_node;)
	{
		tmp = aux_node->next;
		while (aux_node->prev && aux_node->n < aux_node->prev->n)
		{
			aux = aux_node->prev;
			aux->next = aux_node->next;
			aux_node->prev = aux->prev;
			aux->prev = aux_node;
			aux_node->next = aux;
			if (aux->next)
				aux->next->prev = aux;
			if (aux_node->prev)
				aux_node->prev->next = aux_node;
			print_list(init(*list));
		}
		aux_node = tmp;
	}
	*list = init(*list);
}
