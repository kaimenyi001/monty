#ifndef _MONTY_
#define _MONTY_

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void opens(char *file_nm);
void reads(FILE *);
int seps(char *buffer, int line_number, int format);
void find_fn(char *, char *, int, int);
void calls(op_func, char *, char *, int, int);
stack_t *creates(int n);
void _queue(stack_t **, unsigned int);
void _add(stack_t **, unsigned int);
void _sub(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void _mul(stack_t **, unsigned int);
void _mod(stack_t **, unsigned int);
void _push(stack_t **, unsigned int);
void _pint(stack_t **, unsigned int);
void _pall(stack_t **, unsigned int);
void _nop(stack_t **, unsigned int);
void _swap(stack_t **, unsigned int);
void _pchar(stack_t **, unsigned int);
void _rotl(stack_t **, unsigned int);
void _pstr(stack_t **, unsigned int);
void _rotr(stack_t **, unsigned int);
void _err(int errors, ...);
void free_nd(void);
void _errs(int errors, ...);
void str_err(int errors, ...);

#endif
