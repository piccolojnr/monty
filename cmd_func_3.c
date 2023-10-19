#include "monty.h"

/**
 * mod_op - Calculate the remainder of the division of the second top
 * element by the top element of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
		p_more_err(stack, 7, line_number, "mod");

	if ((*stack)->n == 0)
		p_more_err(stack, 8, line_number);

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * pchar - Print the character at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
		p_more_more_err(stack, 10, line_number);

	if ((*stack)->n < 0 || (*stack)->n > 127)
		p_more_more_err(stack, 9, line_number);

	printf("%c\n", (*stack)->n);
}
/**
 * pstr - Print a string starting from the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}

/**
 * rotl - Rotate the stack to the left.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *current;

	(void)line_number;

	if (stack && *stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = NULL;
		temp->prev = NULL;
		(*stack)->prev = NULL;
		current = *stack;
		while (current->next)
		{
			current = current->next;
		}
		current->next = temp;
		temp->prev = current;
	}
}

/**
 * rotr - Rotate the stack to the right.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (stack && *stack && (*stack)->next)
	{
		temp = *stack;
		while (temp->next)
		{
			temp = temp->next;
		}

		if (temp->prev)
		{
			temp->prev->next = NULL;
			temp->prev = NULL;
			temp->next = *stack;
			(*stack)->prev = temp;
			*stack = temp;
		}
	}
}
