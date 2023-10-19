#include "monty.h"
#include <stdio.h>

/**
 * f_pall - prints the stack
 * @head: pointer to the stack head
 * @counter: unused parameter
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;
	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
