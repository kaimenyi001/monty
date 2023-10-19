#include "monty.h"

/**
 * _err - Prints appropiate error messages determined by their error code.
 * @errors: The errors are as follows:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */

void _err(int errors, ...)
{
	va_list a;
	char *op;
	int i;

	va_start(a, errors);
	switch (errors)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(a, char *));
			break;
		case 3:
			i = va_arg(a, int);
			op = va_arg(a, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", i, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(a, int));
			break;
		default:
			break;
	}
	free_nd();
	exit(EXIT_FAILURE);
}

/**
 * _errs - handles errors.
 * @errors: The errors are as follows:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */

void _errs(int errors, ...)
{
	va_list a;
	int i;

	va_start(a, errors);
	switch (errors)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(a, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(a, int));
			break;
		case 8:
			i = va_arg(a, unsigned int);
			fprintf(stderr, "L%d: can't swap, stack too short\n", i);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(a, unsigned int));
			break;
		default:
			break;
	}
	free_nd();
	exit(EXIT_FAILURE);
}

/**
 * str_err - handles errors.
 * @errors: The errors are as follows:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */

void str_err(int errors, ...)
{
	va_list a;
	int i;

	va_start(a, errors);
	i = va_arg(a, int);
	switch (errors)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", i);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", i);
			break;
		default:
			break;
	}
	free_nd();
	exit(EXIT_FAILURE);
}
