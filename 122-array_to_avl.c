#include "binary_trees.h"

/**
 * array_to_avl - builds AVL from array
 * @array: pointer to array
 * @size: size of array
 * Return: pointer to root node of the created AVL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		avl_insert(&root, array[i]);
	}
	return (root);
}
