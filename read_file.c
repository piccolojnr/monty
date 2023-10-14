#include "monty.h"
/**
 * read_file - reads a bytecode file and runs commands
 * @fd: file descriptor for monty bytecodes file
 */
void read_file(FILE *fd)
{
    int line_num, format = 0;
    char *buf = NULL;
    size_t len = 0;

    for (line_num = 1; _getline(&buf, &len, fd) != -1; line_num++)
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
 * Return:
 */
int parse_line(char *buf, int line_num, int format)
{
    char *opcode, *value;
    const char *delim = "\n ";
    size_t index;

    if (buf == NULL)
        print_err(2);

    opcode = strtok(buf, delim);

    index = strlen(opcode) - 1;

    if ('0' + opcode[index] == 61)
        opcode[index] = '\0';

    if (opcode == NULL || opcode[0] == '\0' || opcode[0] == '#')
    {
        return (format);
    }

    value = strtok(NULL, delim);

    if (value)
    {
        index = strlen(value) - 1;
        if ('0' + value[index] == 61)
            value[index] = '\0';
    }

    get_func(opcode, value, line_num);
    return (format);
}
