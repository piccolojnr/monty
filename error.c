#include "monty.h"
/**
 * print_err - prints error messages
 * @code: error code
 * (0) USAGE monty file
 * (1) CAN'T OPEN FILE
 * (2) MALLOC FAILED
 * (3) PUSH OPERATION USAGE
 * (4) UNKNOWN INSTRUCTION
 */
void print_err(int code, ...)
{
    va_list args;
    int l_num;
    char *op;

    va_start(args, code);

    switch (code)
    {
    case 0:
        fprintf(stderr, "USAGE: monty file\n");
        break;
    case 1:
        fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
        break;
    case 2:
        fprintf(stderr, "Error: malloc failed\n");
        break;
    case 3:
        fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
        break;
    case 4:
        l_num = va_arg(args, int);
        op = va_arg(args, char *);
        fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
        break;
    default:
        break;
    }

    va_end(args);
    free_stack();
    exit(EXIT_FAILURE);
}

/**
 * print_more_err - prints error messages
 * @code: error code
 * (5) CAN'T PINT, STACK EMPTY
 * (6) CAN'T POP AN EMPTY STACK
 * (7) PUSH OPERATION USAGE
 * (8) DIVISION BY ZERO
 */
void print_more_err(int code, ...)
{
    va_list args;
    int l_num;
    char *op;

    va_start(args, code);

    switch (code)
    {
    case 5:
        fprintf(stderr, "L%d: can't pint, stack empty\n",
                va_arg(args, int));
        break;
    case 6:
        fprintf(stderr, "L%d: can't pop an empty stack\n",
                va_arg(args, int));
        break;
    case 7:
        l_num = va_arg(args, unsigned int);
        op = va_arg(args, char *);
        fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
        break;
    case 8:
        fprintf(stderr, "L%d: division by zero\n",
                va_arg(args, unsigned int));
        break;
    default:
        break;
    }

    va_end(args);
    free_stack();
    exit(EXIT_FAILURE);
}
/**
 * print_more_err - prints error messages
 * @code: error code
 * (9) CAN'T PCHAR, VALUE OUT OF RANGE
 * (10) CAN'T PCHAR, STACK EMPTY
 */
void print_more_more_err(int code, ...)
{
    va_list args;
    int l_num;

    va_start(args, code);

    l_num = va_arg(args, int);
    switch (code)
    {
    case 9:
        fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
        break;
    case 10:
        fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
        break;
    default:
        break;
    }

    va_end(args);
    free_stack();
    exit(EXIT_FAILURE);
}
/**
 * free_stack - frees the stack
 */
void free_stack(void)
{
    stack_t *tmp;

    if (head == NULL)
        return;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}