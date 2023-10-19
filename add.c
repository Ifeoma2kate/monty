#include "monty.h"

/**
 * add_top_two - Adds the top two elements of the stack and relaces them
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 * @Return: No return
 */
void add_top_two(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int stack_length = 0;
	int sum;

	current = *stack;

	while (current)
	{
		current = current->next;
		stack_length++;
	}

	if (stack_length < 2)
	{
		fprintf(stderr, "%d: can't add, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	*stack = current->next;
	free(current);
}
