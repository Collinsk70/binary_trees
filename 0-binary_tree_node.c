#include "binary_trees.h"

/**
 * create_binary_tree_node - Function to create a binary tree node.
 * @parent: Pointer to the parent of the node being created.
 * @value: The value to be stored in the new node.
 *
 * Returns: If an error occurs, returns NULL.
 *          Otherwise, returns a pointer to the newly created node.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
