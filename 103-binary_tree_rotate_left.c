#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to root node
 * Return: pointer to new root node of tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tempo = NULL, *parent;

	if (!tree || !tree->right)
		return (NULL);
	tempo = tree;
	parent = tree->parent;
	tree = tree->right;
	tree->parent = NULL;

	if (tree->left)
	{
		tempo->right = tree->left;
		tree->left->parent = tempo;
	}
	else
		tempo->right = NULL;
	tempo->parent = tree;
	tree->left = tempo;
	if (parent)
		parent->right = tree;
	tree->parent = parent;
	return (tree);
}
