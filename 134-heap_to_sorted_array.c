#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	newnode = malloc(sizeof(binary_tree_t));

	if (!newnode)
		return (NULL);

	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = NULL;
	return (newnode);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a
 *				sorted array of integers.
 * @heap: pointer to root node
 * @size: address to store size of array
 * Return: pointer to array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	int extract, i = 0;
	size_t hpsize;

	if (!heap)
		return (NULL);
	hpsize = binary_tree_size(heap);
	*size = hpsize;
	array = malloc(hpsize * sizeof(int));
	if (!array)
		return (NULL);
	while (heap)
	{
		extract = heap_extract(&heap);
		array[i] = extract;
		i++;
	}
	return (array);
}
