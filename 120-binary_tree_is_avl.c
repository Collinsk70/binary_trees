#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Calculates the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height of.
 *
 * Return: Returns 0 if tree is NULL, otherwise returns the height.
 */

size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_avl_helper - Determines if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to examine.
 * @lo: The value of the smallest node visited so far.
 * @hi: The value of the largest node visited so far.
 *
 * Return: Returns 1 if the tree is a valid AVL tree; otherwise, returns 0.
 */

int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Determines if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to examine.
 *
 * Return: Returns 1 if tree is a valid AVL tree; otherwise, returns 0.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
