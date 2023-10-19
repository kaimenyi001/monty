#include "monty.h"

stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opens(argv[1]);
	free_nd();
	return (0);
}

/**
 * creates - Creates a node
 * @n: Number to go inside the node
 * Return: a pointer to the node upon success, Otherwise NULL.
 */

stack_t *creates(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		_err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nd - Frees nodes in the stack
 * Return: void
 */

void free_nd(void)
{
	stack_t *t;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		t = head;
		head = head->next;
		free(t);
	}
}


/**
 * _queue - Adds a node to the queue
 * @new_node: Pointer to the new node
 * @ln: line number of the opcode
 */

void _queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (t->next != NULL)
		t = t->next;

	t->next = *new_node;
	(*new_node)->prev = t;

}
