#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

/* func_1 */
void get_func(char *opcode, char *value, int line_num);
stack_t *create_node(int n);
int check_digit(char *value, int line_num);

/* stack_func_1 */
void add_to_stack(stack_t **stack, unsigned int line_num);
void print_stack(stack_t **stack, unsigned int line_num);
void print_top(stack_t **stack, unsigned int line_num);
void pop_stack(stack_t **stack, unsigned int line_num);
void swap_stack(stack_t **stack, unsigned int line_num);

/* stack_func_2 */
void nop(stack_t **stack, unsigned int line_number);
void add_stack(stack_t **stack, unsigned int line_number);
void sub_stack(stack_t **stack, unsigned int line_number);
void mul_stack(stack_t **stack, unsigned int line_number);
void div_stack(stack_t **stack, unsigned int line_number);

/* stack_func_3 */
void mod_stack(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);

/* getline */
ssize_t _getline(char **line, size_t *len, FILE *stream);

/* error */
void print_err(int code, ...);
void print_more_err(int code, ...);
void print_more_more_err(int code, ...);
void free_stack(void);

/* read_file */
void read_file(FILE *fd);
int parse_line(char *buf, int line_num, int format);

#endif /* MONTY_H */