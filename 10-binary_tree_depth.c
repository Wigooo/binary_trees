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
