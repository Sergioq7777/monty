#include "monty.h"


/**
 *_pop - removes node stack
 *@head: head
 *@line_number: number possible error
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *aux;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	aux = aux->next;
	free(*head);
	*head = aux;
}

/**
 *_swap - swap top stack
 *@head: head
 *@l_n: number possible error
 */
void _swap(stack_t **head, unsigned int l_n)
{
	stack_t *aux;
	int count = 0, to_a = 0, to_b = 0;

	aux = *head;
	while (aux)
	{
		aux = aux->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	aux = aux->next;
	to_b = (*head)->n;
	to_a = aux->n;
	aux->n = to_b;
	(*head)->n = to_a;
}

/**
 *_add - adds elements stack
 *@head: head
 *@l_n: number possible error
 */
void _add(stack_t **head, unsigned int l_n)
{
	stack_t *aux;
	int count = 0;

	aux = *head;
	while (aux)
	{
		aux = aux->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	aux = aux->next;
	aux->n += ((*head)->n);
	free(*head);
	*head = aux;
}

/**
 *_nop - the nop opcode
 *@head: head
 *@l_n: number possible error
 */
void _nop(stack_t **head, unsigned int l_n)
{
	(void) head;
	(void) l_n;
}
