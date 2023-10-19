#include "monty.h"

/**
 * _mul - multiplication
 * @stack: Pointer to a pointer pointing to the top node of the stack
 * @line_number: Integer representing the line number of the opcode
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	int k;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_errs(8, line_number, "mul");

	(*stack) = (*stack)->next;
	k = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = k;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _mod - modular
 * @stack: Pointer to a pointer pointing to the top node of the stack
 * @line_number: Integer representing the line number of the opcode.
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	int k;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		_errs(8, line_number, "mod");

	if ((*stack)->n == 0)
		_errs(9, line_number);
	(*stack) = (*stack)->next;
	k = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = k;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
