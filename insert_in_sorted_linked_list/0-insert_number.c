#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer of the list
 * @n: int to be inserted
 * Return: newNode, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int n)
{
    listint_t *newNode, *current, *prev;

    if (head == NULL)
        return (NULL);

    newNode = malloc(sizeof(listint_t));
    if (newNode == NULL)
        return (NULL);

    newNode->n = n;
    newNode->next = NULL;

    current = *head;
    prev = NULL;

    while (current != NULL && current->n < n)
    {
        prev = current;
        current = current->next;
    }

    if (prev == NULL)
    {
        newNode->next = *head;
        *head = newNode;
        return (newNode);
    }
    else
    {
        prev->next = newNode;
        newNode->next = current;
    }
    if (current == *head && prev == NULL)
    {
        free(newNode);
        return NULL;
    }

    return (newNode);
}
