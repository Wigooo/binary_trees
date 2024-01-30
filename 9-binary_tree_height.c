#include "binary_trees.h"

/**
 * binary_tree_height -  measures the height of a binary tree
 * @tree: root of tree
 * Return: height if success, 0 otherwise
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftsubtree = 0;
	size_t rightsubtree = 0;

	if (!tree)
		return (0);

	if (tree->left)
		leftsubtree = 1 + binary_tree_height(tree->left);
	if (tree->right)
		rightsubtree = 1 + binary_tree_height(tree->right);
	if (leftsubtree > rightsubtree)
		return (leftsubtree);
	return (rightsubtree);
}
