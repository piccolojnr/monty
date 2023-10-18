#include "monty.h"

/**
 * add_to_stack - adds a node to the stack
 * @stack: stack to add to
 * @line_num: line number of opcode
 */
void add_to_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void)line_num;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *stack;
		return;
	}
	tmp = head;
	head = *stack;
	head->next = tmp;
	tmp->prev = head;
}
/**
 * print_stack - prints the stack
 * @stack: stack to print
 * @line_num: line number of opcode
 */
void print_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void)line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);

	tmp = *stack;
	printf("+++++++++++++++++++++\n");
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	printf("+++++++++++++++++++++\n");
}
/**
 * print_top - prints the top of the stack
 * @stack: stack to print
 * @line_num: line number of opcode
 */
void print_top(stack_t **stack, unsigned int line_num)
{
	(void)line_num;
	if (stack == NULL || *stack == NULL)
		print_more_err(5);

	printf("%d\n", (*stack)->n);
}
/**
 * pop_stack - removes the top of the stack
 * @stack: stack to print
 * @line_num: line number of opcode
 */
void pop_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void)line_num;

	if (stack == NULL || *stack == NULL)
		print_more_err(6);

	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
/**
 * swap_stack - swaps the top two elements of the stack
 * @stack: stack to print
 * @line_num: line number of opcode
 */
void swap_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void)line_num;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_more_err(7, line_num, "swap");

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	tmp->next = (*stack)->next;
	tmp->prev = *stack;

	(*stack)->next = tmp;
}
