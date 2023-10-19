#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
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
 * struct bus_s - variables -args, files, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> aueue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;
extern bus_t bus;
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
void addnode(stack_t **stack, int value);
void addqueue(stack_t **stack, int value);
void free_stack(stack_t *stack);
void f_pall(stack_t **head, unsigned int counter);
void push_to_stack(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void pop_top(stack_t **stack, unsigned int line_number);
void swap_top_two(stack_t **stack, unsigned int line_number);
void add_top_two(stack_t **stack, unsigned int line_number);
void nop_operation(stack_t **stack, unsigned int line_number);


#endif
