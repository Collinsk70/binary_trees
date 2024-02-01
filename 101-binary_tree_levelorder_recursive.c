#include "binary_trees.h"

/**
 * struct node_s - Structure representing a singly linked list node
 * @node: Pointer to a constant binary tree node
 * @next: Pointer to the next node in the linked list
 */

typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} ll;

ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to be applied to each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ll *children = NULL;

	func(tree->n);
	children = get_children(children, tree);
	levels_rec(children, func);

	free_list(children);
}

/**
 * process_nodes_at_levels - Invokes a function on all nodes at each level.
 * @head: Pointer to the head of a linked list containing nodes at one level.
 * @func: Pointer to a function to be called for each node.
 */

void levels_rec(ll *head, void (*func)(int))
{
	ll *children = NULL, *curr = NULL;

	if (!head)
		return;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
	}
	levels_rec(children, func);
	free_list(children);
}

/**
 * get_children - Adds children of a parent node to a linked list.
 * @head: Pointer to the head of the linked list where children will be appended.
 * @parent: Pointer to the node whose children are to be appended.
 * Return: Pointer to the head of the linked list of children.
 */

ll *get_children(ll *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - Adds a new node at the end of a linked list.
 * @head: Pointer to the head of the linked list.
 * @btnode: Pointer to the constant binary tree node to be appended.
 * Return: Pointer to the head of the linked list, or NULL on failure.
 */

ll *append(ll *head, const binary_tree_t *btnode)
{
	ll *new = NULL, *last = NULL;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->node = btnode;
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			last = head;
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	return (head);
}
/**
 * free_list - Releases memory for all nodes in a linked list.
 * @head: Pointer to the head of the list_t linked list.
 */

void free_list(ll *head)
{
	ll *ptr = NULL;

	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
