#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: wanted node to know it's depth
 * Return: depth if success, 0 otherwise
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t nodesabove = 0;

	if (!tree)
		return (0);

	if (tree->parent)
	{
		nodesabove = 1 + binary_tree_depth(tree->parent);
	}
	return (nodesabove);
}

/**
 * helping_func - goes through tree
 * @tree: tree to traverse
 * @func: called function
 * @depth: depth of node
 */
void helping_func(const binary_tree_t *tree, void (*func)(int),
		size_t depth)
{
	if (depth == 0)
		func(tree->n);
	else
	{
		helping_func(tree->left, func, depth - 1);
		helping_func(tree->right, func, depth - 1);
	}
}

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
 * binary_tree_levelorder - goes through a binary tree,
 *				using level-order traversal.
 * @tree: root node pointer
 * @func: pointer to function called for each node
 * Return: nothin
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t depth, bottom;

	if (!tree || !func)
		return;
	depth = binary_tree_depth(tree);
	bottom = binary_tree_height(tree);
	for (depth = 0; depth <= bottom; depth++)
		helping_func(tree, func, depth);
}
