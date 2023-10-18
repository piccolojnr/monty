#include "monty.h"
/**
 * mod_stack - computes the remainder of the division of the top two
 * @stack: stack head
 * @line_number: line number
 */
void mod_stack(stack_t **stack, unsigned int line_number)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_more_err(7, line_number, "mod");

	if ((*stack)->n == 0)
		print_more_err(8, line_number);

	mod = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = mod;
	pop_stack(stack, line_number);
}
/**
 * print_char - prints the char at the top of the stack
 * @stack: stack head
 * @line_number: line number
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_more_more_err(10, line_number);

	if ((*stack)->n < 0 || (*stack)->n > 127)
		print_more_more_err(9, line_number);

	printf("%c\n", (*stack)->n);
}
/**
 * print_str - prints the string starting at the top of the stack
 * @stack: stack head
 * @line_number: line number
 */
void print_str(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int value;

	(void)line_number;
	for (; current; current = current->next)
	{
		value = current->n;
		if (value >= 1 && value <= 127)
			printf("%c", value);
		else
			break;
	}
	printf("\n");
}
/**
 * rotl_stack - rotates the stack to the top
 * @stack: stack head
 * @line_number: line number
 */
void rotl_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1 = *stack;
	stack_t *tmp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	(void)line_number;
	for (; tmp1->next; tmp1 = tmp1->next)
		;

	tmp2 = (*stack)->next;

	tmp1->next = *stack;
	tmp2->prev = NULL;
	(*stack)->next = NULL;
	(*stack)->prev = tmp1;
	*stack = tmp2;
}
/**
 * rotr_stack - rotates the stack to the top
 * @stack: stack head
 * @line_number: line number
 */
void rotr_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1 = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	(void)line_number;
	for (; tmp1->next; tmp1 = tmp1->next)
		;

	tmp1->prev->next = NULL;

	tmp1->next = *stack;
	tmp1->prev = NULL;

	*stack = tmp1;
}
