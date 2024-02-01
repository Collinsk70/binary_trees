#include "binary_trees.h"

/**
 * CalculateTreeHeight - Determines the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: If the tree is NULL, returns 0; otherwise, returns the height.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
	}
	return (0);
}
