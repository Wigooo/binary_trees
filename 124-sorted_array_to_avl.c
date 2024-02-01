#include "binary_trees.h"

avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *toavltree(avl_t *parent, int *array, int first, int last);
/**
 * sorted_array_to_avl - Builds an AVL tree from an array.
 *
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array
 *
 * Return: A pointer to the root node of the created AVL tree, NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (toavltree(NULL, array, 0, ((int)(size)) - 1));
}

/**
 * toavltree - Create the tree using the half element of the array.
 *
 * @parent: Parent of the node to create.
 * @array: Sorted array.
 * @first: Position where the array starts.
 * @last: Position where the array ends.
 *
 * Return: Tree created.
 */
avl_t *toavltree(avl_t *parent, int *array, int first, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int middle = 0;

	if (first <= last)
	{
		middle = (first + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[middle]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = toavltree(root, array, first, middle - 1);
		root->right = toavltree(root, array, middle + 1, last);
		return (root);
	}
	return (NULL);
}
