#include "monty.h"

/**
 * _pchar - Prints the Ascii value
 * @stack: Pointer to a pointer pointing to the top node of the stack
 * @line_number: Integer representing the line number of the opcode
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	int asc;

	if (stack == NULL || *stack == NULL)
		str_err(11, line_number);

	asc = (*stack)->n;
	if (asc < 0 || asc > 127)
		str_err(10, line_number);
	printf("%c\n", asc);
}

/**
 * _pstr - Prints a string
 * @stack: Pointer to a pointer pointing to the top node of the stack
 * @ln: Integer representing the line number of the opcode
 */

void _pstr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int asc;
	stack_t *t;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	t = *stack;
	while (t != NULL)
	{
		asc = t->n;
		if (asc <= 0 || asc > 127)
			break;
		printf("%c", asc);
		t = t->next;
	}
	printf("\n");
}

/**
 * _rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */

void _rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	t = *stack;
	while (t->next != NULL)
		t = t->next;

	t->next = *stack;
	(*stack)->prev = t;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * _rotr - Rotates the last node of the stack to the top
 * @stack: Pointer to a pointer pointing to the top node of the stack
 * @ln: Integer representing the line number of the opcode
 */

void _rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	t = *stack;

	while (t->next != NULL)
		t = t->next;

	t->next = *stack;
	t->prev->next = NULL;
	t->prev = NULL;
	(*stack)->prev = t;
	(*stack) = t;
}
