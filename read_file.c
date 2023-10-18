#include "monty.h"
/**
 * read_file - reads a bytecode file and runs commands
 * @fd: file descriptor for monty bytecodes file
 */
void read_file(FILE *fd)
{
	int line_num, format = 1;
	char *buf = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buf, &len, fd) != -1; line_num++)
	{
		format = parse_line(buf, line_num, format);
	}

	free(buf);
}
/**
 * parse_line - parses a line for opcode and value
 * @buf: line to parse
 * @line_num: line number
 * @format: format specifier
 *
 * Return: format specifier
 */
int parse_line(char *buf, int line_num, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";
	size_t index;

	if (buf == NULL)
		print_err(2);
	if (strlen(buf) == 0)
		return (format);
	opcode = strtok(buf, delim);
	if (strcmp(opcode, "stack") == 0)
	{
		format = 1;
		return (format);
	}
	else if (strcmp(opcode, "queue") == 0)
	{
		format = 0;
		return (format);
	}
	index = strlen(opcode) - 1;

	if (opcode == NULL || opcode[0] == '\0' || opcode[0] == '#')
		return (format);
	value = strtok(NULL, delim);

	if (value)
	{
		index = strlen(value) - 1;
		if ('0' + value[index] == 61)
			value[index] = '\0';
	}
	get_func(opcode, value, line_num, format);
	return (format);
}
