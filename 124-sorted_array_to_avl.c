#include "binary_trees.h"

/**
 * toavltree - helper that builds an AVL tree from an array
 * @root: double pointer to the root node of the subtree
 * @array: a pointer to the first element of the array to be converted
 * @lo: lower bound index
 * @hi: upper bound index
 */
void toavltree(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *new = NULL;
	size_t i;

	if (hi - lo > 1)
	{
		i = (hi - lo) / 2 + lo;
		new = binary_tree_node(*root, array[i]);
		if (array[i] > (*root)->n)
			(*root)->right = new;
		else if (array[i] < (*root)->n)
			(*root)->left = new;
		toavltree(&new, array, lo, i);
		toavltree(&new, array, i, hi);
	}
}

/**
 * sorted_array_to_avl -  builds an AVL tree from an array
 * @array: array pointer
 * @size: size of array
 * Return: pointer to the root node of the created AVL tree,
 *				or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	if (!array)
		return (NULL);
	i = (size - 1) / 2;
	root = binary_tree_node(NULL, array[i]);

	toavltree(&root, array, i, size);
	return (root);
}
