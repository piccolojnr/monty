#include "monty.h"
/**
 * get_func - gets the function to execute
 * @opcode: opcode to execute
 * @value: value to pass to function
 * @line_num: line number of opcode
 * @format: format of opcode
 */
void get_func(char *opcode, char *value, int line_num, int format)
{
	int i, flag, new_digit;
	stack_t *new_node;

	instruction_t opcodes[] = {
		{"push", nop}, {"pall", print_stack},
		{"pint", print_top}, {"pop", pop_stack},
		{"swap", swap_stack}, {"add", add_stack},
		{"sub", sub_stack}, {"mul", mul_stack},
		{"div", div_stack}, {"mod", mod_stack},
		{"pchar", print_char}, {"pstr", print_str},
		{"rotl", rotl_stack}, {"rotr", rotr_stack},
		{"nop", nop}, {NULL, NULL}
	};
	for (flag = 1, i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0 && value != NULL)
			{
				new_digit = check_digit(value, line_num);
				new_node = create_node(new_digit);
				if (format == 1)
					add_node_begin(&new_node);
				else
					add_node_end(&new_node);
			}
			else
			{
				opcodes[i].f(&head, line_num);
			}
			flag = 0;
		}
	}

	if (flag == 1)
		print_err(4, line_num, opcode);
}

/**
 * check_digit - checks if a string is a digit
 * @value: string to check
 * @line_num: line number of string
 *
 * Return: digit
 */
int check_digit(char *value, int line_num)
{
	int i;
	int flag = 1;
	int new_digit;

	if (value == NULL)
		print_err(3, line_num);

	if (value[0] == '-')
	{
		value++;
		flag = -1;
	}

	for (i = 0; value[i] != '\0'; i++)
	{
		if (isdigit(value[i]) == 0)
			print_err(3, line_num);
	}

	new_digit = atoi(value) * flag;

	return (new_digit);
}
/**
 * create_node - creates a new node
 * @n: value to add to node
 *
 * Return: node
 */
stack_t *create_node(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		print_err(2);

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
