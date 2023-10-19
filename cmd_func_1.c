#include "monty.h"

/**
 * push - Push an element onto the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	stack_t *new_node;

	arg = strtok(NULL, " \t\n\r");
	if (!arg || !is_number(arg))
		p_err(stack, 3, line_number);

	new_node = create_node(stack, atoi(arg));

	if (mode == QUEUE)
		add_node_queue(stack, new_node);
	else
		add_node_stack(stack, new_node);
}

/**
 * pall - Print all values on the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - Print the value at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
		p_more_err(stack, 5, line_number);

	printf("%d\n", (*stack)->n);
}
/**
 * pop - Remove the top element from the stack
 * @stack: A pointer to the stack.
 * @line_number: The line number of the opcode.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack))
		p_more_err(stack, 6, line_number);

	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}
/**
 * swap - Swap the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the opcode.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		p_more_err(stack, 7, line_number, "swap");

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}
