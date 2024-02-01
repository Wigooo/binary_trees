#include "binary_trees.h"

/**
 * binary_tree_size -  measure the size of a binary tree
 * @tree: root of tree
 * Return: size if success, 0 otherwise
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t nodesize = 0;
	/*size_t nodesize = sizeleft + sizeright;*/

	if (!tree)
		return (0);

	nodesize = 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);

	return (nodesize);
}
