#ifndef __SORT_ALG__
#define __SORT_ALG__

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_int(int *a, int *b);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void recursive(int *array, int first, int last, size_t size);
int partition(int *array, int first, int last, int size);

void swap(int *array, int i, int j, int size);
void shell_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);
void _swap(listint_t *tmp, listint_t *tmp2, listint_t **list);
#endif /* __SORT_ALG__ */
