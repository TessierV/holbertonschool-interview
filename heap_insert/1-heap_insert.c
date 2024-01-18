#include "binary_trees.h"
#include <stdlib.h>

heap_t *heap_insert(heap_t **root, int value)
{
    binary_tree_t *new_node, *parent;
    if (!root)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root)
        return (*root = new_node, new_node);

    parent = *root;
    while (parent->left && parent->right)
        parent = (binary_tree_height(parent->left) <= binary_tree_height(parent->right)) ? parent->left : parent->right;

    new_node->parent = parent;
    if (parent->left)
        parent->right = new_node;
    else
        parent->left = new_node;

    heapify_up(new_node);

    return (new_node);
}

int binary_tree_height(const binary_tree_t *tree)
{
    int left_height, right_height;
    if (!tree)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

void heapify_up(binary_tree_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        int temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }
}
