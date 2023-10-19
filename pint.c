#include "monty.h"

/**
 * print_top - prints the top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the monty file
 * Return: No return
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
