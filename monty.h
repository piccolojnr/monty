#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#define STACK 0
#define QUEUE 1

#define STACK 0
#define QUEUE 1

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

extern int mode;

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

/* parse commands */
void process_monty_commands(FILE *file);
void get_function(stack_t **stack, char *opcode, unsigned int line_number);

/* command functions 1 */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* command functions 2 */
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul_op(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);

/* command functions 3 */
void mod_op(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/* command functions 3 */
void add_node_queue(stack_t **stack, stack_t *new_node);
void add_node_stack(stack_t **stack, stack_t *new_node);
void stack_op(stack_t **stack, unsigned int line_number);
void queue_op(stack_t **stack, unsigned int line_number);
int get_mode(void);

/* stack functions */
stack_t *create_node(stack_t **stack, int n);
void free_stack(stack_t *head);

/* utilities */
int is_number(char *str);

/* error handling */
void p_err(stack_t **stack, int op_code, ...);
void p_more_err(stack_t **stack, int op_code, ...);
void p_more_more_err(stack_t **stack, int op_code, ...);

#endif /* MONTY_H */
