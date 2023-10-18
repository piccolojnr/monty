#include "monty.h"
/**
 * nop - does nothing
 * @stack: stack head
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * add_stack - adds the top two elements of the stack
 * @stack: stack head
 * @line_number: line number
 */
void add_stack(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_more_err(7, line_number, "add");

	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	pop_stack(stack, line_number);
}
/**
 * sub_stack - subtracts the top two elements of the stack
 * @stack: stack head
 * @line_number: line number
 */
void sub_stack(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_more_err(7, line_number, "sub");

	sub =  (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = sub;
	pop_stack(stack, line_number);
}
/**
 * mul_stack - multiplies  the top two elements of the stack
 * @stack: stack head
 * @line_number: line number
 */
void mul_stack(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_more_err(7, line_number, "mul");

	mul = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = mul;
	pop_stack(stack, line_number);
}
/**
 * div_stack - divides the top two elements of the stack
 * @stack: stack head
 * @line_number: line number
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_more_err(7, line_number, "div");

	if ((*stack)->n == 0)
		print_more_err(8, line_number);

	div = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = div;
	pop_stack(stack, line_number);
}
