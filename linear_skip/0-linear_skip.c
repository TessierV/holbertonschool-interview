#include "search.h"

/* Constants for messages */
#define CHECKED_VALUE "Value checked at index [%lu] = [%d]\n"
#define FOUND_BETWEEN_INDEXES "Value found between indexes [%lu] and [%lu]\n"

/**
 * linear_skip - searches for a specific value in an express-powered linked list
 * @list: pointer to the head of the skip list
 * @value: value to search for
 *
 * Return: pointer to the node containing the value, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *start = NULL, *end = NULL;

    /* Check if the list is valid and the value is in the search range */
    if (!list || list->n > value)
        return NULL;

    /* Traverse the list until the value is exceeded */
    while (list->express && list->express->n < value)
    {
        printf(CHECKED_VALUE, list->express->index, list->express->n);
        list = list->express;
    }

    /* Store the start and end indices of the search */
    start = list;
    end = list->express ? list->express : list;

    /* Print the start and end indices of the search */
    printf(FOUND_BETWEEN_INDEXES, start->index, end->index);

    /* Linear search within the search range */
    while (list && list->n <= value)
    {
        printf(CHECKED_VALUE, list->index, list->n);
        if (list->n == value)
            return list;
        list = list->next;
    }

    return NULL;
}
