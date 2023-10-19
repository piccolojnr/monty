#include "monty.h"

/**
 * add - Add the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
		p_more_err(stack, 7, line_number, "add");

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
/**
 * nop - Do nothing.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub - Subtract the top element of the stack from the second top element.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
		p_more_err(stack, 7, line_number, "sub");

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
/**
 * mul_op - Multiply the second top element of the stack with the top element.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
		p_more_err(stack, 7, line_number, "mul");

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
/**
 * div_op - Divide the second top element of the stack by the top element.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
		p_more_err(stack, 7, line_number, "div");

	if ((*stack)->n == 0)
		p_more_err(stack, 8, line_number);

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}
