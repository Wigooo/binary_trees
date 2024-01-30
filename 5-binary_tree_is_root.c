#include "binary_trees.h"

/**
 * binary_tree_is_root - check if root
 *
 * @node: pointer
 *
 * Return: int
*/

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
