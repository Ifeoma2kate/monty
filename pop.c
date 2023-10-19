#include "monty.h"

/**
 * pop_top - Removes and frees the top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 * Return: No return
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	top_node = *stack;
	*stack = top_node->next;
	free(top_node);
}
