#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 *						in a binary tree.
 * @tree: root node pointer
 * Return: number of nodes if success, 0 otherwise
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t numbers = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	numbers = 1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);

	return (numbers);
}
