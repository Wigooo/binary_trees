#include "binary_trees.h"


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
