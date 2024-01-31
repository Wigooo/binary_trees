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

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: root node pointer
 * Return: balance factor if success, 0 otherwise
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t hleft = 0;
	size_t hright = 0;

	if (!tree)
		return (0);
	if (!tree->left)
		hleft = 0;
	if (!tree->right)
		hright = 0;
	if (tree->left)
		hleft = 1 + binary_tree_height(tree->left);
	if (tree->right)
		hright = 1 + binary_tree_height(tree->right);
	return (hleft - hright);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: root node pointer
 * Return: 1 if perfect, 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && tree->right &&
			binary_tree_balance(tree) == 0 &&
			binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right))
		return (1);
	return (0);
}
