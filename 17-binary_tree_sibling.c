#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: node to find it's siblings
 * Return: pointer to sibling node if exists, NULL otherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node->parent)
	{
		if (node->parent->left == node)
		{
			return (node->parent->right);
		}
		return (node->parent->left);
		if (node->parent->right == node)
		{
			return (node->parent->left);
		}
		return (node->parent->right);
	}
	return (NULL);
}
