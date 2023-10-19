#include "monty.h"


/**
 * _push - Adds a node to the stack
 * @new_node: Pointer to the new node
 * @ln: Interger representing the line number of the opcode
 */

void _push(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	t = head;
	head = *new_node;
	head->next = t;
	t->prev = head;
}


/**
 * _pall - Adds a node to the stack
 * @stack: Pointer to a pointer pointing to the top node of the stack
 * @line_number: line number of  the opcode
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	t = *stack;
	while (t != NULL)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}

/**
 * _pop - Adds a node to the stack
 * @stack: Pointer to a pointer pointing to the top node of the stack
 * @line_number: Interger representing the line number of the opcode
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	if (stack == NULL || *stack == NULL)
		_errs(7, line_number);

	t = *stack;
	*stack = t->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(t);
}

/**
 * _pint - Prints the top node of the stack
 * @stack: Pointer to a pointer pointing to top node of the stack
 * @line_number: Interger representing the line number of the opcode
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		_errs(6, line_number);
	printf("%d\n", (*stack)->n);
}
