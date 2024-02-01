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
 * isavl - checks if avltree
 * @tree: root node pointer
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if avl, 0 if not
 */
int isavl(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	if (abs(binary_tree_balance(tree)) > 1)
		return (0);
	return (isavl(tree->left, min, tree->n - 1) &&
			isavl(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: root node pointer
 * Return: 1 if AVL tree, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (isavl(tree, INT_MIN, INT_MAX));
}
