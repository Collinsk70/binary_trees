#include "binary_trees.h"

/**
 * insert_left_child - Function to insert a node as the left-child of another
 *                     node in a binary tree.
 * @parent: Pointer to the node where the left-child is to be inserted.
 * @value: The value to be stored in the new left-child node.
 *
 * Returns: If parent is NULL or an error occurs, returns NULL.
 *          Otherwise, returns a pointer to the newly inserted node.
 *
 * Description: If the parent already has a left-child, the new node
 *              replaces it, and the old left-child becomes the left-child
 *              of the new node.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
