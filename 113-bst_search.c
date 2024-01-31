#include "binary_trees.h"

/**
 * bst_search - search for value
 *
 * @tree: pointer
 * @value: the value
 *
 * Return: bst_t
*/

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
