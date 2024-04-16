#include "search.h"

/**
 * linear_skip - searches for a specific
 * value in an express-powered linked list
 * @head: address
 * @value: value
 * Return: Returns address to the node or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    if (!list || list->n > value)
        return (NULL);
    return (list->n == value) ? list :
           (!list->express || (list->n < value && value < list->express->n)) ?
           linear_skip(list->next, value) : linear_skip(list->express, value);
}
