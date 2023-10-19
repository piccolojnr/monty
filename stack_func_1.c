#include "monty.h"
/**
 * create_node - creates a new node
 * @n: value to add to node
 *
 * Return: node
 */
stack_t *create_node(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		p_err(2);

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
/**
 * free_stack - Frees a stack_t stack.
 */
void free_stack(void)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
