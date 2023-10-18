#include "monty.h"
/**
 * add_node_begin - adds a new node at the begining of a stack_t list.
 * @stack: node
 */
void add_node_begin(stack_t **stack)
{

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *stack;
		return;
	}
	(*stack)->next = head;
	head->prev = *stack;
	head = *stack;
}
/**
 * add_node_end - adds a new node at the end of a stack_t list.
 * @stack: node
 */
void add_node_end(stack_t **stack)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *stack;
		return;
	}

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
}
