#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    if (!root)
        return (NULL);

    /* Create a new node */
    heap_t *new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    /* If the tree is empty, make the new node the root */
    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    /* Insert the new node at the end of the tree */
    heap_t *parent = get_parent_node(*root);
    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;

    /* Restore Max Heap property */
    heapify_up(new_node);

    return (new_node);
}

/**
 * get_parent_node - Finds the parent node for the next insertion in the heap.
 * @root: A pointer to the root node of the Heap.
 *
 * Return: A pointer to the parent node.
 */
heap_t *get_parent_node(heap_t *root)
{
    if (!root)
        return (NULL);

    /* Initialize variables */
    int bin_size = get_size(root) + 1;
    int mask = 1 << (bin_size - 1);
    heap_t *parent = root;

    /* Traverse the binary tree to find the parent node */
    while (mask > 1)
    {
        mask >>= 1;
        parent = (bin_size & mask) ? parent->right : parent->left;
    }

    return (parent);
}

/**
 * get_size - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree.
 */
int get_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    int left_height = get_size(tree->left);
    int right_height = get_size(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * heapify_up - Maintains the Max Heap property after insertion.
 * @node: A pointer to the newly inserted node.
 */
void heapify_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        swap_values(node, node->parent);
        node = node->parent;
    }
}

/**
 * swap_values - Swaps the values of two binary tree nodes.
 * @a: A pointer to the first node.
 * @b: A pointer to the second node.
 */
void swap_values(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}