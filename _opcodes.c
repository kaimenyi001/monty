#include "monty.h"

/**
 * opens - opens a file
 * @file_nm: the file namepath
 * Return: void
 */

void opens(char *file_nm)
{
	FILE *d = fopen(file_nm, "r");

	if (file_nm == NULL || d == NULL)
		_err(2, file_nm);

	reads(d);
	fclose(d);
}


/**
 * reads - reads a file
 * @d: pointer to file descriptor
 * Return: void
 */

void reads(FILE *d)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, d) != -1; line_number++)
	{
		format = seps(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * seps - Separates each line into tokens
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int seps(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		_err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_fn(opcode, value, line_number, format);
	return (format);
}

/**
 * find_fn - find the appropriate function
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format
 * @ln: line number
 * Return: void
 */

void find_fn(char *opcode, char *value, int ln, int format)
{
	int j;
	int c;

	instruction_t fn_list[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"nop", _nop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (c = 1, j = 0; fn_list[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, fn_list[j].opcode) == 0)
		{
			calls(fn_list[j].f, opcode, value, ln, format);
			c = 0;
		}
	}
	if (c == 1)
		_err(3, ln, opcode);
}


/**
 * calls - Calls the required function
 * @fn: Pointer to the function that is about to be called
 * @op: string representing the opcode
 * @val: string representing a numeric value
 * @ln: line number for the instruction
 * @format: Format specifier
 */

void calls(op_func fn, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int c;
	int j;

	c = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			c = -1;
		}
		if (val == NULL)
			_err(5, ln);
		for (i = 0; val[j] != '\0'; j++)
		{
			if (isdigit(val[j]) == 0)
				_err(5, ln);
		}
		node = creates(atoi(val) * c);
		if (format == 0)
			fn(&node, ln);
		if (format == 1)
			_queue(&node, ln);
	}
	else
		fn(&head, ln);
}
