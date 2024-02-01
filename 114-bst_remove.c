#include "binary_trees.h"
/**
 * minofBST - finds minimum value in BST
 * @root: root node of tree pointer
 * Return: pointer to minimum value node
 */
bst_t *minofBST(bst_t *root)
{
	bst_t *minimum = root;

	while (minimum->left)
		minimum = minimum->left;
	return (minimum);
}
/**
 * bst_remove -  removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree,
 *			where you will remove a node
 * @value: value to remove in tree
 * Return: a pointer to the new root node of the tree after removing
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tempo = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			tempo = root->right;
			free(root);
			return (tempo);
		}
		else if (!root->right)
		{
			tempo = root->left;
			free(root);
			return (tempo);
		}
		tempo = minofBST(root->right);
		root->n = tempo->n;
		root->right = bst_remove(root->right, tempo->n);
	}
	return (root);
}
