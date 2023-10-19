#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * push_to_stack - Pushes a new node onto stack
 * @stack: pointer to the stack
 * @line_number: Line number in the monty file
 * Return: no return
 */
void push_to_stack(stack_t **stack, unsigned int line_number)
{
	int value, index = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			index++;

		while (bus.arg[index] != '\0')
		{
			if (bus.arg[index] > '9' || bus.arg[index] < '0')
				flag = 1;
			index++;
		}

		if (flag)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	value = atoi(bus.arg);

	if (bus.lifi == 0)
		addnode(stack, value);
	else
		addqueue(stack, value);
}
