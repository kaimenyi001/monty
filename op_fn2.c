#include "monty.h"

/**
 * _nop - Does something
 * @stack: Pointer to a pointer pointing to the top node of the stack
 * @line_number: Integer representing the line number of the opcode
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _swap - Swaps the top elements of the stack
 * @stack: Pointer to a pointer pointing to the top node of the stack
 * @line_number: Integer representing the line number of the opcode
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_errs(8, line_number, "swap");
	t = (*stack)->next;
	(*stack)->next = t->next;
	if (t->next != NULL)
		t->next->prev = *stack;
	t->next = *stack;
	(*stack)->prev = t;
	t->prev = NULL;
	*stack = t;
}

/**
 * _add - Adds the top two elements of the stack
 * @stack: Pointer to a pointer pointing to the top node of the stack
 * @line_number: Integer representing the line number of the opcode
 */

void _add(stack_t **stack, unsigned int line_number)
{
	int k;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_errs(8, line_number, "add");

	(*stack) = (*stack)->next;
	k = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = k;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _sub - subtraction
 * @stack: Pointer to a pointer pointing to the top node of the stack
 * @line_number: Integer representing the line number of the opcode
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	int k;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		_errs(8, line_number, "sub");

	(*stack) = (*stack)->next;
	k = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = k;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _div - division
 * @stack: Pointer to a pointer pointing to the top node of the stack
 * @line_number: Integer representing the line number of the opcode
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int k;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_errs(8, line_number, "div");

	if ((*stack)->n == 0)
		_errs(9, line_number);
	(*stack) = (*stack)->next;
	k = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = k;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
