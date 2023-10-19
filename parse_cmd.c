#include "monty.h"
/**
 * process_monty_commands - Process Monty bytecode commands
 * @file: A pointer to the input bytecode file.
 */
void process_monty_commands(FILE *file)
{
	char *line = NULL, *opcode = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	stack_t *head = NULL;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;

		opcode = strtok(line, " \t\n\r");

		if (opcode == NULL || *opcode == '#')
			continue; /* Ignore empty lines and comments */

		get_function(&head, opcode, line_number);
	}

	free(line);
	free_stack(head);
}

/**
 * get_function - Get the function that corresponds to an opcode
 * @stack: A pointer to the stack.
 * @opcode: The opcode to get the function for.
 * @line_number: The line number of the opcode.
 */
void get_function(stack_t **stack, char *opcode, unsigned int line_number)
{
	int i, found = 0;
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul_op},
		{"div", div_op},
		{"mod", mod_op},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue_op},
		{"stack", stack_op},
		{NULL, NULL}};

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
		{
			found = 1;
			op_funcs[i].f(stack, line_number);
		}
	}
	if (found == 0)
		p_err(stack, 4, line_number, opcode);
}
