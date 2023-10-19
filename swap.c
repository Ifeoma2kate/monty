#include "monty.h"

/**
 * swap_top_two - Swaps the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 * Return: No return
 */
void swap_top_two(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int stack_length = 0;
	int temp_value;

	current = *stack;

	while (current)
	{
		current = current->next;
		stack_length++;
	}

	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	temp_value = current->n;
	current->n = current->next->n;
	current->next->n = temp_value;
}
