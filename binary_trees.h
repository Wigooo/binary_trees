#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
}binary_tree_t;

/**
 * struct levelorder_queue_s - Level order traversal queue.
 * @node: A node of a binary tree.
 * @next: The next node to traverse to in the binary tree.
 */

typedef struct levelorder_queue_s
{
	binary_tree_t *node;
	struct levelorder_queue_s *next;
} levelorder_queue_t;

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_print(const binary_tree_t *);


#endif /* BINARY_TREES_H */