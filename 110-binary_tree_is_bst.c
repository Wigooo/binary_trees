#include "binary_trees.h"
/**
 * subfunc - checks if tree valid binary search tree
 * @tree: root node pointer
 * @minimum: smallest node value visited
 * @maximum: largest node value visited
 * Return: 1 if BST, 0 otherwise
 */
int subfunc(const binary_tree_t *tree, int minimum, int maximum)
{
	if (!tree)
		return (1);
	if (tree->n < minimum || tree->n > maximum)
		return (0);
	return (subfunc(tree->left, minimum, tree->n - 1) &&
			subfunc(tree->right, tree->n + 1, maximum));
}
/**
 * binary_tree_is_bst - checks if a binary tree is
 *				a valid Binary Search Tree
 * @tree: pointer to root node
 * Return: 1 if BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (subfunc(tree, INT_MIN, INT_MAX));
}
