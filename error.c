#include "monty.h"
/**
 * p_err - prints error messages
 * @stack: stack
 * @op_code: opcode
 * (0) USAGE: monty file
 * (1) ERROR: Can't open file %s
 * (2) ERROR: malloc failed
 * (3) ERROR: L%d: usage: push integer
 * (4) ERROR: L%d: unknown instruction %s
 */
void p_err(stack_t **stack, int op_code, ...)
{
	va_list args;
	int l_num;
	char *op;

	va_start(args, op_code);

	switch (op_code)
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
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
/**
 * p_more_err - prints error messages
 * @stack: stack
 * @op_code: error op_code
 * (5) CAN'T PINT, STACK EMPTY
 * (6) CAN'T POP AN EMPTY STACK
 * (7) PUSH OPERATION USAGE
 * (8) DIVISION BY ZERO
 */
void p_more_err(stack_t **stack, int op_code, ...)
{
	va_list args;
	int l_num;
	char *op;

	va_start(args, op_code);

	switch (op_code)
	{
	case 5:
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
		break;
	case 6:
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
		break;
	case 7:
		l_num = va_arg(args, unsigned int);
		op = va_arg(args, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
		break;
	case 8:
		fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
		break;
	default:
		break;
	}

	va_end(args);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
/**
 * p_more_more_err - prints error messages
 * @stack: stack
 * @op_code: error op_code
 * (9) CAN'T PCHAR, VALUE OUT OF RANGE
 * (10) CAN'T PCHAR, STACK EMPTY
 */
void p_more_more_err(stack_t **stack, int op_code, ...)
{
	va_list args;
	int l_num;

	va_start(args, op_code);

	l_num = va_arg(args, int);
	switch (op_code)
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
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
