#include "monty.h"
/**
 * mod_stack - computes the remainder of the division of the top two
 * @stack: stack head
 * @line_number: line number
 */
void mod_stack(stack_t **stack, unsigned int line_number)
{
    int mod;

    (void)stack;

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
    (void)stack;

    if (stack == NULL || *stack == NULL)
        print_more_more_err(10, line_number);

    if ((*stack)->n < 0 || (*stack)->n > 127)
        print_more_more_err(9, line_number);

    printf("%c\n", (*stack)->n);
}