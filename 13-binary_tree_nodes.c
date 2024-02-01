#include "binary_trees.h"

/**
 * binary_tree_nodes - Determines the number of nodes with at least one child in a binary tree.
 * @tree: Pointer to the root node of the tree to count the nodes.
 *
 * Return: Returns 0 if tree is NULL, otherwise returns the node count.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		nodes += (tree->left || tree->right) ? 1 : 0;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}
