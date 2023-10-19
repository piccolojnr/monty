#include "monty.h"
/**
 * create_node - creates a new node
 * @stack: stack
 * @n: value to add to node
 *
 * Return: node
 */
stack_t *create_node(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		p_err(stack, 2);

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
/**
 * free_stack - Frees a stack_t stack.
 * @head: pointer to head of stack
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
