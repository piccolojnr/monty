#include "monty.h"

/**
 * add_node_queue - Add a node to a queue.
 * @stack: A pointer to the stack.
 * @new_node: The node to add.
 */
void add_node_queue(stack_t **stack, stack_t *new_node)
{
	stack_t *current;

	/* In queue mode, insert at the end (LIFO behavior) */
	if (*stack)
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
	else
	{
		*stack = new_node;
	}
}
/**
 * add_node_stack - Add a node to a stack.
 * @stack: A pointer to the stack.
 * @new_node: The node to add.
 */
void add_node_stack(stack_t **stack, stack_t *new_node)
{
	/* In stack mode, insert at the beginning (FIFO behavior) */
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * stack_op - Set the format of data to a stack (LIFO).
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = STACK;
}

/**
 * queue_op - Set the format of data to a queue (FIFO).
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void queue_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = QUEUE;
}

/**
 * get_mode - Get the current mode (stack or queue).
 * Return: The current mode (STACK or QUEUE).
 */
int get_mode(void)
{
	return (mode);
}
