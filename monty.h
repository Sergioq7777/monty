#ifndef MONTY_H
#define MONTY_H

#define STK "stack"
#define QUE "queue"
#define TOKDEL "\n \r\t"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

extern char *tok;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


int check_integer(stack_t **head, unsigned int lin, char *linef, FILE *f_);
void _tkn(char *lintok, unsigned int lin, stack_t **head, FILE *file, int *s);
void _pushstack(stack_t **head, int num);
void _pushqueue(stack_t **head, int num);
void slf(unsigned int lin, stack_t **head);
void _pall(stack_t **head, unsigned int lin);
void freee(stack_t **head);
void _pint(stack_t **head, unsigned int lin);
void _pop(stack_t **head, unsigned int lin);
void _swap(stack_t **head, unsigned int lin);
void _add(stack_t **head, unsigned int lin);
void _nop(stack_t **head, unsigned int lin);


#endif
