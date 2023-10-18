#include "monty.h"

stack_t *head;
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	char *file_name;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_name = argv[1];
	fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		print_err(1, file_name);

	read_file(fd);

	fclose(fd);

	printf("executed successfully\n");
	free_stack();
	return (0);
}
