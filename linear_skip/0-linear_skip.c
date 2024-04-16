#include "search.h"

/* Constants for messages */
#define CHECKED_VALUE "Value checked at index [%lu] = [%d]\n"
#define FOUND_BETWEEN_INDEXES "Value found between indexes [%lu] and [%lu]\n"

/**
 * search_express_list - Searches for a value in the express list.
 * @start: A pointer to the starting node of the express list.
 * @value: The value to search for.
 * @last: A pointer to the last node of the express list.
 *
 * Return: A pointer to the first node where value is located,
 * or NULL if value is not present.
 */
skiplist_t *search_express_list(skiplist_t *start, int value, skiplist_t *last)
{
	skiplist_t *node = start, *express = start->express;

	while (express && express->n < value)
	{
		printf(CHECKED_VALUE, express->index, express->n);
		node = express;
		express = express->express;
	}

	printf(FOUND_BETWEEN_INDEXES, node->index, (express ? express->index : last->index));
	return (node);
}

/**
 * linear_skip - Searches for a value in a sorted skip list.
 * @list: A pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Return: A pointer to the first newNode where value is located,
 * or NULL if value is not present or list is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	if (!list)
		return (NULL);
	skiplist_t *newNode = list, *last = newNode;

	while (last->next)
		last = last->next;
	search_express_list(list, value, last);
	while (newNode && newNode->n < value)
	{
		printf(CHECKED_VALUE, newNode->index, newNode->n);
		newNode = newNode->next;
	}
	if (newNode && newNode->n == value)
	{
		printf(CHECKED_VALUE, newNode->index, newNode->n);
		return (newNode);
	}
	return (NULL);
}
