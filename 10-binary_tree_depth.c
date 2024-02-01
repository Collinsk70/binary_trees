#include "binary_trees.h"

/**
 * measure_tree_depth - Function to determine the depth of a node in a binary tree.
 * @tree: Pointer to the node whose depth is to be measured.
 *
 * Returns: If tree is NULL, the function returns 0, otherwise, it returns the depth.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
